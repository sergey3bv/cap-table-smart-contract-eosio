# Cap table contract

## Build

Generate build system:

```sh
cmake . -B ./build
```

Compile the contract:

```sh
cmake --build ./build
```

Built project (wasm and abi files) will be held in `./build/cap_table`.

## Contribution

Additions to CMake should be done to the CMakeLists.txt in the `./src`
directory and **not in the top level CMakeLists.txt**.
