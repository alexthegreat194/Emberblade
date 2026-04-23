# Notes

## SFML (vendored)

We use **SFML 2.6.2** from the official download page:

https://www.sfml-dev.org/download/sfml/2.6.2/

On macOS, use the **Clang** archive that matches the machine (**64-bit** Intel vs **ARM64** Apple Silicon).

### What was copied into `vendor/sfml/` (Apr 2026)

The macOS SDK tree was merged into the repo under `vendor/sfml/` so `src/compile.sh` can use `-I../vendor/sfml/include` and `-L../vendor/sfml/lib` without Homebrew:

- **`include/`** — full SFML headers (`SFML/Config.hpp`, module headers, etc.).
- **`lib/`** — `libsfml-*.2.6.2.dylib`, version symlinks (e.g. `libsfml-graphics.dylib` → `…2.6.dylib`), and **`lib/cmake/`** (CMake config for optional CMake builds).
- **`Frameworks/`** — the six bundles from the SDK’s **`Frameworks/`** folder (`sfml-audio`, `sfml-graphics`, `sfml-network`, `sfml-system`, `sfml-window`, `SFML.framework`). These match the official layout next to `lib/`.

`examples/`, `doc/`, and `templates/` from the archive were not needed for compiling Emberblade and were not copied.

The SFML **`.dylib`** builds in `lib/` still reference helper frameworks (e.g. **FreeType**, **OpenAL**, **vorbis**, …) via paths under **`../Frameworks/`**. Those ship in the SDK’s **`extlibs/`** folder. If the game **fails at launch** with missing-framework / **dyld** errors for audio or text, copy everything under **`extlibs/*.framework`** into **`vendor/sfml/Frameworks/`** as well (same sibling-of-`lib` layout as in the unpacked SDK).

### “Vendor” in this repo

Third-party native deps we keep **inside the repo** under `vendor/` instead of relying on a system package manager. Here that means our own copy of the SFML SDK paths that the shell script points at.

## macOS vendored SFML — layout and gotchas

### Which SDK zip?

- **Apple Silicon (M1/M2/…):** SFML 2.6.2 **Clang — ARM64** from the [2.6.2 download page](https://www.sfml-dev.org/download/sfml/2.6.2/).
- **Intel Mac:** **Clang — 64-bit (macOS 10.15+)**.
- If `file vendor/sfml/lib/libsfml-system.dylib` shows **x86_64** but the Mac is **arm64**, the linker will ignore the dylibs and you get huge “undefined symbols” lists — wrong architecture.

### `vendor/sfml/` layout (what the **prebuilt dylibs** expect)

- **`include/`** — headers (`SFML/Config.hpp`, …).
- **`lib/`** — `libsfml-*.dylib` plus symlinks (what `compile.sh` links with `-L`).
- **`Frameworks/`** — **required at runtime** for the official macOS dylibs: they reference paths like `@rpath/../Frameworks/freetype.framework/...`, `@rpath/../Frameworks/OpenAL.framework/...`, vorbis/ogg/FLAC, etc.

The official zip also has an **`extlibs/`** folder with those same `*.framework` bundles. **dyld does not look in `extlibs/`** for those references — only **`Frameworks/`** (sibling of `lib/`). So: **copy or move `extlibs/*.framework` into `Frameworks/`**. After that, you **do not need** an `extlibs/` folder in the repo unless you want to keep a duplicate for your own reference.

### Quick sanity checks (shell)

- **`test -f path`** — exits 0 if `path` exists as a file (often used as `test -f … && echo OK`). Same idea as **`[ -f path ]`**.
- **`file vendor/sfml/lib/libsfml-system.dylib`** — confirm **arm64** vs **x86_64**.
- **`lipo -archs vendor/sfml/lib/libsfml-system.dylib`** — list slice(s) in a universal binary.

### `compile.sh` and “build config”

The game script sets **rpath** and links `-lsfml-*`. It does **not** change where SFML’s own dylibs look for FreeType/OpenAL — that is **baked into the SFML binaries**. Fixing paths without moving frameworks would mean **rebuilding SFML** or **`install_name_tool`**, which is unnecessary if **`Frameworks/`** is populated correctly.