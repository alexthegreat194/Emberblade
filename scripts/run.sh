#!/usr/bin/env bash
#
# Build, then run Emberblade with the working directory at the repository root
# (so relative paths to assets/ resolve as expected).
#
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_ROOT="$(cd "$SCRIPT_DIR/.." && pwd)"
"$SCRIPT_DIR/compile.sh"
cd "$REPO_ROOT"
exec "$REPO_ROOT/Emberblade" "$@"
