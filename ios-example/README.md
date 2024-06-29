# iOS Coverage Collection

Based on the [Visualizing iOS Code Execution](https://s11research.com/posts/Visualizing-iOS-Code-Execution/) write-up.

## Modifications to Lighthouse frida-drcov.py

The changes introduce to the Lighthouse tool introduce the ability to begin stalking threads once a trigger function is called - it stops stalking once the trigger function returns.

With large Application processes on Android and iOS it is not possible to trace everything without the process crashing - this functionality introduces the ability to tightly narrow the scope of tracing so as to avoid crashing the process.
