// Constants.c v3.0.0
static bool StartMainMenu      = true;  // Если true, при запуске принудительно показывается главное меню.
static bool NoHints			   = false;  // Если true, подсказки не показываются на экранах загрузки.
static bool UseImagesets       = false;   // Если true, записи hints.json с m_ImageSet/m_ImageName загружаются из зарегистрированного imageset backgrounds; иначе используется m_ImagePath.
static bool LoadVideo          = false;  // Если true, на экранах загрузки показывается видео вместе с подсказками.
static bool ShowGameOverOverlay = false;  // Внутренний флаг времени выполнения: переключается DayZPlayerImplement.ShowDeadScreen() для оверлея game over в InGameMenu/Respawn. Не пользовательская настройка (сбрасывается при каждой смерти).

// Параметры ниже сейчас часто ломаются. Исправление планируется в обновлении 4.0.0.
static bool EnableMenuVideo    = false;  // Фоновое видео в главном меню (через CuiBackgroundVideo от корня workspace).
static bool EnableOptionsVideo = false;  // Фоновое видео в меню настроек (при открытии из главного меню).
static bool VideoDeathScreens  = false;  // Если true, при смерти игрока показывается случайный экран game over.
// static bool RandomDeathScreens = false;  // Если true, при смерти игрока показывается случайное видео game over.

// Информация о сервере
// (В кнопках CUI возможны баги. На живых серверах ещё не тестировалось)
static const string SERVER_IP = "127.0.0.1";
static const int SERVER_PORT = 2302;

// Настройки видео (меняйте по своему усмотрению)
static const string m_LoadingVideo     = "CUI_Video.mov";  // Имя файла видео для экрана загрузки.
static const string m_MainMenuVideo    = "CUI_Video.mov";  // Имя файла видео для главного меню.
static const string m_OptionsMenuVideo = "CUI_Video.mov";  // Имя файла видео для меню настроек.

// Фон главного меню — выбор между спрайтом imageset и сырым .edds
// в зависимости от UseImagesets. Меняйте нужную ветку для смены пути.
string GetMainMenuBackground()
{
    if (UseImagesets)
        return "set:backgrounds image:mainmenu";
    return "Colorful-UI/GUI/textures/LoadScreens/Loneliness_MainMenu.paa";
}
// Один экран game over (экран смерти)
class GameOverScreen
{
    static string GameOverScreenImage() { return "Colorful-UI/GUI/textures/DeathScreens/DeathScreen.edds"; };
};

// Логотип сервера
// ПРИМЕЧАНИЕ: настройки ширины и высоты здесь пока не реализованы.
//        Рекомендуемый размер — 512×512; пока размер задаётся вручную в layout-файле.
class Branding
{
    static string Logo()
    {
        if (UseImagesets)
            return "set:branding image:logo";
        return "Colorful-UI/GUI/textures/Shared/Loneliness_Logo.paa";
    }
    static void ApplyLogo(ImageWidget widget)
    {
        if (!widget) return;
        widget.LoadImageFile(0, Logo());
        widget.SetFlags(WidgetFlags.STRETCH);
    }
};

// URL ссылок (добавьте свои ссылки здесь)
// ПРИМЕЧАНИЕ: если кнопка не нужна, укажите URL «#» или «».
//        Если не задать — кнопки не появятся в layout после компиляции.
//        Так отображаются только нужные кнопки.

class CustomURL {
	static string Website    = "#"; 
	static string PriorityQ  = "#";
	static string Custom     = "#";
}

class SocialURL {
	static string Discord    = "#";
	static string Facebook   = "#";
	static string Twitter    = "#";
	static string Reddit     = "#";
	static string Youtube    = "#";
}

