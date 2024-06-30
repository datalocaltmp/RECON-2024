`-rdynamic` flag ensures that the coverageTime function is exported to allow for hooking as if it were a native library.

```console
NDK/toolchains/llvm/prebuilt/darwin-x86_64/bin/aarch64-linux-android32-clang -rdynamic example.c
```