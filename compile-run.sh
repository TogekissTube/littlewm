#!/bin/sh

set -e

make build

install -v littlewm /usr/bin/

XEPHYR=$(command -v Xephyr) # Absolute path of Xephyr's bin
xinit ./xinitrc -- \
    "$XEPHYR" \
        :100 \
        -ac \
        -screen 1380x720\
        -host-cursor
