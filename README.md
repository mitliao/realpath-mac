# realpath for macOS

This is a *very much* simpler implementation of `realpath` from GNU `coreutils`, inspired by [harto/realpath-osx](https://github.com/harto/realpath-osx).

This version supports multiple path arguments just like the GNU one,  and a very useful option `--relative-to`.

To build, just run `make`. After that, you can run `make install` which will install `realpath` to `/usr/local/bin/`.


