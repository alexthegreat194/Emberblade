#!/usr/bin/env bash
#
# macOS only — build with vendored SFML (see ../vendor/sfml/). SFML 2.x only — not SFML 3.
# https://www.sfml-dev.org/download.php
#
# Populate:
#   ../vendor/sfml/include/SFML/...
#   ../vendor/sfml/lib/libsfml-*.dylib
#

set -euo pipefail

if [[ "$(uname -s)" != "Darwin" ]]; then
	echo "error: this script only supports macOS (Darwin)." >&2
	exit 1
fi

cd "$(dirname "$0")"

# --- require SDK (paths are relative to this script in src/) ---
if [[ ! -f ../vendor/sfml/include/SFML/Config.hpp ]]; then
	echo "error: missing ../vendor/sfml/include/SFML/Config.hpp" >&2
	echo "       unpack SFML 2.x for macOS so include/ and lib/ sit under ../vendor/sfml/" >&2
	exit 1
fi

# --- compile ---
g++ -I../vendor/sfml/include -std=c++11 -c Animal.cpp
g++ -I../vendor/sfml/include -std=c++11 -c BodyBox.cpp
g++ -I../vendor/sfml/include -std=c++11 -c Globals.cpp
g++ -I../vendor/sfml/include -std=c++11 -c Inventory.cpp
g++ -I../vendor/sfml/include -std=c++11 -c Item.cpp
g++ -I../vendor/sfml/include -std=c++11 -c ItemStack.cpp
g++ -I../vendor/sfml/include -std=c++11 -c Notification.cpp
g++ -I../vendor/sfml/include -std=c++11 -c NotificationHandler.cpp
g++ -I../vendor/sfml/include -std=c++11 -c WeaponBox.cpp
g++ -I../vendor/sfml/include -std=c++11 -c Emberblade.cpp
g++ -I../vendor/sfml/include -std=c++11 -c main.cpp

# --- link ---
# Emberblade ends up in repo root; dylibs live in vendor/sfml/lib.
g++ -I../vendor/sfml/include -std=c++11 -L../vendor/sfml/lib -o ../Emberblade \
	main.o Animal.o BodyBox.o Globals.o Inventory.o Item.o ItemStack.o \
	Notification.o NotificationHandler.o WeaponBox.o Emberblade.o \
	-lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system \
	-Wl,-rpath,@executable_path/vendor/sfml/lib \
	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreFoundation -framework OpenAL

echo "Built ../Emberblade"
