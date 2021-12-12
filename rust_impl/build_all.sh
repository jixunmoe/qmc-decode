#!/usr/bin/env bash

set -ex

pushd "$(dirname "$0")"

rm -rf bin
mkdir -p bin

build_target() {
    rustup target add "$1"
    cargo build --target "$1" --release

    if [ -f "target/$1/release/rust_impl" ]; then
        cp "target/$1/release/rust_impl" "bin/qmc-decode.$2"
    else
        cp "target/$1/release/rust_impl.exe" "bin/qmc-decode.$2"
    fi
}

# debian/ubuntu deps
# sudo apt install gcc-mingw-w64-x86-64 gcc
build_target x86_64-pc-windows-gnu "x86_64.exe"

# sudo apt install gcc-x86-64-linux-gnux32
build_target x86_64-unknown-linux-gnu "x86_64.linux"

# sudo apt install gcc-aarch64-linux-gnu
build_target aarch64-unknown-linux-gnu "aarch64.linux"

# sudo apt install gcc-arm-linux-gnueabihf
build_target arm-unknown-linux-gnueabihf "armhf.linux"

popd
