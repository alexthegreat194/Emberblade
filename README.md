# Emberblade

Emberblade is a top-down 2D game built as a summer project. You explore a large open world, gather plants, manage gear, and fight wildlife with different weapons, all wrapped in a simple inventory and crafting-style UI.

![Emberblade Screenshot](docs/screenshot.png)

## About the game

The world is a wide tile-based area with the camera following the player. You move through grassland-style terrain, interact with harvestable plants that regrow on a timer, and encounter animals such as pigs and boars. Combat uses a sword or spear, with hitboxes for the player, weapons, and creatures, plus floating damage feedback. A hotbar and separate inventory and crafting views let you switch between playing, managing items, and crafting without leaving a single client executable.

## Implemented Features

- Plant harvesting
- Inventory system
- Combat system with different weapons
- Multiple NPCs

## Architecture

- **Stack:** C++11, **SFML 2.x** (graphics, window, audio). Built with `g++` via `scripts/compile.sh`; the binary is linked against the **vendored** SFML in `vendor/sfml/`.
- **Entry point and loop:** The main game loop, rendering, and much of the gameplay live in `src/main.cpp` (player, plants, damage numbers, hotbar, input, and the render/update cycle). Smaller subsystems are split into translation units for clarity and compile times.
- **Subsystems in `src/`:** `Inventory` / `Item` / `ItemStack` for items; `Notification` and `NotificationHandler` for on-screen messages; `WeaponBox` and `BodyBox` for attack and body collision; `Animal` for creatures. Shared UI helpers and mode enum live in `Emberblade.hpp` / `Emberblade.cpp`; `Globals.hpp` / `Globals.cpp` hold application-wide state (world position, zoom, textures, fonts, the player inventory, and notifications).
- **Assets:** Sprites, sheets, and fonts are under `assets/`. The game expects to be run with the **working directory at the repository root** so those paths resolve (as noted in the install section).
- **Build output:** Object files go to `build/`; the executable is `Emberblade` at the repository root after a successful `compile.sh` run.

## Installation

**macOS only.** SFML is **not** installed via Homebrew. Add the official **SFML 2.x** macOS SDK into the repo so this layout exists (merge the SDK’s `include` and `lib` folders):

- `vendor/sfml/include/SFML/...`
- `vendor/sfml/lib/libsfml-*.dylib`

Download: [SFML downloads](https://www.sfml-dev.org/download.php). Match **SFML 2** to this codebase (it uses the SFML 2 API). The `src/SFML/*-3.dll` files are SFML 3 Windows runtimes only; they are not used by this build script.

Then build and run from the repository root (so `assets/` resolves correctly):

```bash
git clone https://github.com/alexthegreat194/Emberblade.git
cd Emberblade
chmod +x scripts/compile.sh scripts/run.sh
./scripts/compile.sh   # build only → ./Emberblade
./scripts/run.sh       # build, then run (cwd = repo root)
./Emberblade          # run last build
```
