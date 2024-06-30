# iOS Coverage Collection

Based on the [Visualizing iOS Code Execution](https://s11research.com/posts/Visualizing-iOS-Code-Execution/) write-up.

1) Load `libsystem_kernel.dylib` into Ghidra

2) Set the Image base to `0x0` with `currentProgram.setImageBase(currentProgram.getImageBase().getNewAddress(0x0), True)`

3) Open TrollInstallerX on your Jailbroken iPhone w/ Frida server installed

4) Collect coverage with `python3 ./frida-drcov.py -D <iPhone_device_id> -N libsystem_kernel.dylib -n mach_memory_object_memory_entry_64 TrollInstallerX`
    * the device ID can be collected with `frida-ls-devices`  

5) (Optional) Add some recognizable characters to the `libsystem_kernel.dylib` module in `frida-cov.log`

6) Load `frida-cov.log` into Ghidra and observe coverage in `mach_memory_object_memory_entry_64`

## Modifications to Lighthouse frida-drcov.py

The changes introduce to the Lighthouse tool introduce the ability to begin stalking threads once a trigger function is called - it stops stalking once the trigger function returns.

With large Application processes on Android and iOS it is not possible to trace everything without the process crashing - this functionality introduces the ability to tightly narrow the scope of tracing so as to avoid crashing the process.
