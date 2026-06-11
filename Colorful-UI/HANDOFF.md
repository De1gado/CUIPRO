# Loneliness UI — журнал работы и план

Документ для продолжения работы над переоформлением Colorful-UI в направление
**Cold Zone / Loneliness**. Визуальный эталон — [APPROVED_UI_DIRECTION.md](APPROVED_UI_DIRECTION.md).
Этот файл — что сделано, на чём остановились, как продолжать.

---

## 1. Концепт (коротко)

Тёмный, холодный, изношенный пост-апокалиптический UI в духе S.T.A.L.K.E.R.
Палитра: чёрно-синие поверхности `#020507…#0D1721`, грязно-белый активный текст
`#E4E0D0`, холодный сине-серый вторичный `#8FA8B8`, ржаво-красный для danger `#7F2F2F`.
Полная палитра и токены — в `Scripts/3_Game/Config/Color.c` (класс `UIColor`,
префикс `Zone*`) и `Scheme.c` (класс `colorScheme`).

### Правило цвета кнопок (договорённость, держать по всем экранам)
- **Неактивный пункт** → `colorScheme.SecondaryText()` (холодный сине-серый), без заливки.
- **Hover** → `colorScheme.ButtonHover()` (грязно-белый).
- **Первичное действие** (Play) → solid: грязно-белая полоса + тёмный текст, через
  `cuiElmnt.proSolidBtnDC(...)` / `proSolidBtn(...)` (см. `buttons.c`).
- **Danger** → `colorScheme.BtnDangerBG()` / `ZoneDanger()`.

---

## 2. Важные факты и грабли (НЕ переоткрывать)

1. **Шрифт `GUI/fonts/Stalker/Arimo-Stalker.fnt` рендерит кириллицу в игре.**
   Статический байт-скан FNT5 показывает «нет кириллицы» — это ЛОЖНО. Шрифт рабочий,
   не трогать, русские лейблы в нём отображаются.
2. **Локализация:** vanilla loc-ключи (`#main_menu_exit`, `#menu_cancel`,
   `#main_menu_respawn` и т.п.) на RU-клиенте сами дают русский. Предпочитать их
   хардкоду русских строк. Хардкод оставлен только там, где у vanilla нет ключа.
3. **Цвета-алиасы:** старый код зовёт `UIColor.White()`, `cuiTeal()`, `Dossier*` и
   т.п. — все переопределены на Zone-палитру в `Color.c`, поэтому многие экраны
   перекрашиваются «бесплатно» через токены. Но где `.layout` хардкодит `color …` —
   токен не применяется, нужна ручная правка файла.
4. **CleanupForOwner / CallLater(0):** обработчики кнопок (`CUIButtonHandler`)
   защищены от use-after-free. При добавлении кнопок использовать существующие
   `cuiElmnt.proBtn*` обёртки, не изобретать свои.

---

## 3. Сделано

### База (Codex)
- `Color.c` — палитра переписана на Cold Zone + слой алиасов для обратной совместимости.
- `Scheme.c` — токены на Zone-палитру, добавлены `BtnDanger*`, `Dialog*`, `MenuTint`,
  `BackgroundTone`, `TabPanelBackground`.
- `buttons.c` — добавлен `proSolidBtnDC` (solid-кнопка + direct connect).
- `MainMenu.c` + `cui.mainMenu.layout` — полный ретему: `ZoneTint`, `ZoneLogo`,
  `PlayBtn` solid, кнопки перемаплены под RU-сервер (ВОЙТИ/ДИСКОРД/МАГАЗИН/ПРАВИЛА/
  НАСТРОЙКИ/ВЫЙТИ). Ассеты: `Loneliness_MainMenu.paa`, `Loneliness_Logo.paa`,
  `Loneliness_Button_Primary.paa`, шрифт `Arimo-Stalker`.

### Правки поверх (эта сессия)
- **Лого единый:** `Settings.c` `Branding.Logo()` → `Loneliness_Logo.paa`; 7 layout-ов
  переправлены с отсутствующего `CuiPro_Logo.edds` на `Loneliness_Logo.paa`
  (loading, loggingIn, priorityQueue, mainMenu, ingame, logout, respawn).
- **inGame-кластер выровнен под Cold Zone:** `InGameMenu.c` (5 nav-кнопок),
  `Respawn.c` (3), `LogoutMenu.c` (2 + `Cancel`→`#menu_cancel`) — idle на
  `SecondaryText`, hover `ButtonHover`.

Запушено: коммит `3bbb9c7`, ветка `main`, `github.com/De1gado/CUIPRO`.

---

## 4. На чём остановились

Поставлено на паузу пользователем после inGame-кластера. inGame layout-ы хардкода
цветов не имеют (чистая скрипт-тема). Дальше начинаются экраны с хардкодом цветов в
`.layout` — там поwidget-ная ручная работа.

---

## 5. Осталось (по приоритету)

| Экран | Файлы | Объём | Заметки |
|-------|-------|-------|---------|
| **Dialogs** | `GUI/layouts/dialogs/cui.dialogs.layout`, `Scripts/5_Mission/GUI/CUI/dialogs/` | малый | Часто на виду (exit-confirm). `Dialog*`-токены в `Scheme` уже есть. Иконка warning — `ZoneDanger()`. |
| **Options** | `GUI/layouts/options/cui.options_menu.layout`, `tabs/*`, `cui.tutorials.layout`; `Scripts/5_Mission/GUI/CUI/options/` | средний | Хардкод ярких цветов в layout. Слайдеры/инпуты/каретки → `Option*`-токены. |
| **Inventory** | `GUI/layouts/inventory/{medium,narrow,wide}/*`, headers, cargo | большой | Виден чаще всего. Активный таб = грязно-белая полоса, неактивные тёмные. Тонкая сетка-рамка. |

Прочее, что стоит проверить при сборке: loading-экраны (`cui.loading`,
`cui.loggingIn`, `cui.priorityQueue`), hints.

---

## 6. Рецепт «Cold Zone проход по экрану» (делать единообразно)

> Кандидат в скилл `cui-coldzone-pass`. Пока — чек-лист.

1. **Контроллер** (`Scripts/5_Mission/GUI/CUI/...`): прочитать, найти все `SetColor`,
   `proBtn*`, хардкод `ARGB(...)`. Заменить на `colorScheme.*`-токены. nav-кнопки →
   `SecondaryText` idle / `ButtonHover` hover. Первичное действие → solid.
2. **Layout** (`GUI/layouts/...`): `grep "color [0-9]"` — найти хардкод не-нейтральных
   цветов. Тёмные поверхности `#020507/#071018/#0D1721`, тонкие сине-серые рамки,
   прямые углы. Тексты обычно красятся из скрипта — layout-цвет оставить нейтральным.
3. **Ассеты**: если экран тянет старую текстуру/иконку не в стиле — заменить на
   Loneliness/Stalker или перекрасить через `SetColor`.
4. **Проверка**: все `FindAnyWidget("Name")` в скрипте обязаны иметь виджет с этим
   именем в layout. Сверить перед сборкой.
5. **Текст**: vanilla loc-ключ предпочесть хардкоду. Русский хардкод — только если
   ключа нет.

Полезные команды поиска хардкода:
```
grep -rn "color 0\.[5-9]"  GUI/layouts/<screen>     # яркие цвета в layout
grep -rn "ARGB("           Scripts/.../<Controller>.c # хардкод цвета в скрипте
grep -rn "PrimaryText()"   Scripts/.../<Controller>.c # кандидаты на SecondaryText
```

---

## 7. Сборка и тест

```
/dayz-preflight            # P:\ смонтирован, окружение готово
/dayz-build-pbo            # workspace → P:\Mods\@Colorful-UI\Addons\*.pbo
/dayz-launch-test          # diag server + client, глазами проверить экраны
/dayz-stop-test            # убить сессию
```

Перед заходом в Options/Inventory — рекомендуется собрать и **визуально подтвердить**
MainMenu + inGame-кластер (особенно рендер русского текста), чтобы не тащить
возможный косяк дальше.
