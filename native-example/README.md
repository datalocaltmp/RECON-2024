# Android Native Coverage Collection

Based on the [Visualizing Android Code Execution](https://s11research.com/posts/Visualizing-Android-Code-Execution-Pt.2/) write-up.

## Alternative method to frida-drcov.py

Frida Server Gadget Method

1) Rather than using frida-server, use frida gadget via `LD_PRELOAD=./libgadget.so`
2) Within `libgadget.config.so` reference the lighthouse modified javascript `frida-drcov.js`
3) `frida-drcov.js` stores raw coverage data in `/data/local/tmp/rawcov.dat`
4) Use modified `frida-drcov.py` to convert raw data to Cartographer
5) Import coverage map into Ghidra!