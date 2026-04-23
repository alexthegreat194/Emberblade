#!/usr/bin/env bash
#
# macOS only — build with vendored SFML (see ../vendor/sfml/). SFML 2.x only — not SFML 3.
# https://www.sfml-dev.org/download.php
#
# Populate (repo root):
#   vendor/sfml/include/SFML/...
#   vendor/sfml/lib/libsfml-*.dylib
#
# Object files are written to build/ (create with mkdir below).
# Run from anywhere; paths are relative to the repository root.
#

set -euo pipefail

if [[ "$(uname -s)" != "Darwin" ]]; then
	echo "error: this script only supports macOS (Darwin)." >&2
	exit 1
fi

REPO_ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$REPO_ROOT"
mkdir -p build

# --- require SDK (paths are relative to repo root) ---
if [[ ! -f vendor/sfml/include/SFML/Config.hpp ]]; then
	echo "error: missing vendor/sfml/include/SFML/Config.hpp" >&2
	echo "       unpack SFML 2.x for macOS so include/ and lib/ sit under vendor/sfml/" >&2
	exit 1
fi

# --- compile (sources in src/, objects in build/) ---
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/Animal.cpp     -o build/Animal.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/BodyBox.cpp     -o build/BodyBox.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/Globals.cpp     -o build/Globals.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/Inventory.cpp   -o build/Inventory.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/Item.cpp        -o build/Item.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/ItemStack.cpp   -o build/ItemStack.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/Notification.cpp         -o build/Notification.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/NotificationHandler.cpp  -o build/NotificationHandler.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/WeaponBox.cpp     -o build/WeaponBox.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/Emberblade.cpp   -o build/Emberblade.o
g++ -Ivendor/sfml/include -Isrc -std=c++11 -c src/main.cpp         -o build/main.o

# --- link ---
# Emberblade in repo root; dylibs live in vendor/sfml/lib.
g++ -Ivendor/sfml/include -std=c++11 -Lvendor/sfml/lib -o Emberblade \
	build/main.o build/Animal.o build/BodyBox.o build/Globals.o build/Inventory.o \
	build/Item.o build/ItemStack.o build/Notification.o build/NotificationHandler.o \
	build/WeaponBox.o build/Emberblade.o \
	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system \
	-Wl,-rpath,@executable_path/vendor/sfml/lib \
	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreFoundation -framework OpenAL

echo "Built ./Emberblade (objects in build/)"
