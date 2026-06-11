# Loneliness Approved UI Direction

## Project Name

Loneliness

## Name

Cold Zone / post-apocalyptic monochrome UI.

This is the approved visual direction for further Loneliness UI development.
Do not use the earlier amber/orange HUD direction as the base style.

## Core Mood

Dark, cold, worn, utilitarian interface inspired by S.T.A.L.K.E.R.-like post-Soviet survival UI.
The UI should feel like an old field terminal, dossier, inventory board, or damaged military menu over a night scene.

## Palette

- Background black: `#020507`
- Deep blue-black: `#071018`
- Cold dark blue: `#0D1721`
- Graphite steel: `#1C2730`
- Primary dirty white: `#E4E0D0`
- Secondary UI blue-gray: `#8FA8B8`
- Aged beige-gray: `#9A9688` only for scratches, worn borders, and paper dirt. It must not become the general UI tone.
- Danger rust red: `#7F2F2F`
- Cold blue-gray accent: `#8FA8B8`

## Typography

- Display font: tall, narrow, worn Cyrillic-compatible type for logo, big headings, section numbers, and major labels.
- UI font: narrow readable Cyrillic-compatible type for buttons, tabs, fields, captions, and values.
- Text should look printed, faded, and field-used rather than clean modern SaaS/game UI.

## Panels And Windows

- Rectangular panels, no rounded corners.
- Dark transparent surfaces based on `#020507`, `#071018`, and `#0D1721`.
- Thin dirty beige-gray borders.
- Worn/grunge edges and scratched masks where possible.
- Primary active item: dirty white torn strip with dark text.
- Inactive items: cold blue-gray text without fill.
- Danger actions: rust-red worn fill.
- Progress bars: dirty white fill, dark track, thin border.
- Inventory: thin framed grid, active tab as dirty white strip, inactive tabs dark.
- Dialogs and notifications: dark boxed panel, thin border, warning icon in rust red, primary action as dirty white button.

## UI Elements

- Buttons: rectangular, thin border, distressed active/hover texture.
- Tabs: framed segmented tabs; active tab uses dirty white fill.
- Checkboxes/toggles: minimal outlined controls with dirty white active mark.
- Icons: simple, pale dirty white or cold blue-gray; red only for danger/warning.
- Cursor/reticle: simple pale linework, no bright neon.

## Development Rule

Every screen must be developed through the full chain:

1. Script controller
2. Layout file
3. Image/font assets

Changing only `Color.c` or `Scheme.c` is not enough, because many screens hardcode colors, fonts, textures, and widget structure directly in `.layout` files.
