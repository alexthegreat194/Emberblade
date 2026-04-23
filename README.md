
# Emberblade

This is a game that I worked on over the summer. Explore, harvest and hunt!

## Implemented Features

- Plant harvesting
- Inventory system
- Combat system with different weapons
- Multiple NPCs


## Installation

**macOS only.** SFML is **not** installed via Homebrew. Add the official **SFML 2.x** macOS SDK into the repo so this layout exists (merge the SDK’s `include` and `lib` folders):

- `vendor/sfml/include/SFML/...`
- `vendor/sfml/lib/libsfml-*.dylib`

Download: [SFML downloads](https://www.sfml-dev.org/download.php). Match **SFML 2** to this codebase (it uses the SFML 2 API). The `src/SFML/*-3.dll` files are SFML 3 Windows runtimes only; they are not used by this build script.

Then build and run from the repository root (so `assets/` resolves correctly):

```bash
git clone https://github.com/alexthegreat194/Emberblade.git
cd Emberblade
chmod +x src/compile.sh
./src/compile.sh
./Emberblade
```
    