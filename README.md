# QMC 解码

腾讯音乐 QMC 格式解码

## Release Build (`Makefile`)

Windows:

    make

Linux:

    # Build without .exe extension
    EXT= make

### Static Build

    env 'CFLAGS=-Wall -std=c11 -static' make

Adjust `CFLAGS` for your need.

## Development

Open `qmc-decode.cbp` with code::blocks for quick IDE setup.

Or just use any editor you prefer.
