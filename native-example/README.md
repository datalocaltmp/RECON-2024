# Android Native Coverage Collection

Based on the [Visualizing Android Code Execution](https://s11research.com/posts/Visualizing-Android-Code-Execution-Pt.2/) write-up.

## Demo Exercise - Collecting coverage for Messengers libmsysinfra.so

1) Find the thread ID `frida-trace -U Messenger -i 'libmsysinfra.so!MCQOrcaTempMessageListFetchResultsWithChildren'`

2) Collect the coverage with `python3 ./frida-drcov.py -D emulator-5554 Messenger -w libmsysinfra.so -t <threadID>`

3) Load `libmsysinfra.so` into Ghidra - set Image base to 0x0 with Memory Map > Home Icon 

4) (Optional) Modify the coverage file to add recognizable characters to the module i.e. append a ton of `!` characters

5) Load the coverage file via `Tools > Code Coverage > Load Code Coverage Files`

6) Confirm you see coverage for `MCQOrcaTempMessageListFetchResultsWithChildren`

## Workshop Exercise

1) Move the following files to your `/data/local/tmp/` directory with `adb push`
    * `fvsa.<arch>`
    * `libfrida-gadget-arm64.config.so`
    * `libfrida-gadget-arm64.so`
    * `frida-drcov.js`

2) Rename `fvsa.<arch>` to `fvsa`

3) Run `./fvsa`

4) Run `LD_PRELOAD=libfrida-gadget-arm64.so ./fvsa`

5) Confirm you have `/data/local/tmp/rawcov.dat`

6) `adb pull /data/local/tmp/rawcov.dat`

7) Covert rawcov to drcov format with `./tooling/frida-drcov.py`

8) Load resulting `frida-cov.log` into Ghidra
