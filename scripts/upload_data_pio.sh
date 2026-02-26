#!/usr/bin/env bash
# Helper: upload data/ folder to ESP32 filesystem using PlatformIO
set -e
if ! command -v platformio >/dev/null 2>&1 && ! command -v pio >/dev/null 2>&1; then
  echo "PlatformIO CLI (platformio or pio) not found in PATH." >&2
  exit 1
fi

if command -v platformio >/dev/null 2>&1; then
  PIO=platformio
else
  PIO=pio
fi

echo "Uploading data/ to device filesystem (uploadfs)..."
$PIO run --target uploadfs
echo "Done."
