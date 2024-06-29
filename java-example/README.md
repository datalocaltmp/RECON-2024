# Android Java Coverage Collection

Based on the [Visualizing Android Code Execution Pt.3](https://s11research.com/posts/Visualizing-Android-Code-Execution-Pt.3/) write-up.

1. Download Trend Micro 2020 CTF Apk [here](https://github.com/Hong5489/TrendMicroCTF2020/blob/main/mobile2/Keybox.apk)

2. Trigger KEY1HintActivity with:

```console
$ adb shell am start-activity -a com.trendmicro.keybox.UNLOCK_HINT -n com.trendmicro.keybox/.KEY1HintActivity -e hintkey1 TrendMicro
```

3. Confirm you're seeing functionality run within the app on the activity

```console
$ frida-trace -U Keybox -j 'com.trendmicro.keybox.HippoLoader!*'
```

4. Generate all the .dot files for the `KEY1HintActivity` class

```console
//Only generates the .dot files for classes/methods associated with the specified class
jadx --raw-cfg --single-class com.trendmicro.keybox.KEY1HintActivity Keybox.apk

//Generates .dot files for all classes/methods in Keybox.apk
jadx --raw-cfg Keybox.apk
```

5. Load the .dot file associated with `onCreate` into [FlowFinder](https://s11research.com/assets/flowfinder/flowfinder.html)

6. Generate the Frida script with the verbose option

7. In another terminal, trigger the functionality again - with a wrong password first

```console
$ adb shell am start-activity -a com.trendmicro.keybox.UNLOCK_HINT -n com.trendmicro.keybox/.KEY1HintActivity -e hintkey1 Trend
```

8. After execution is observed; CTRL+C to send SIGINT and open the resulting `flow-cov.dot` file into FlowFinder

9. (Optional) Repeat the previous two steps but use the proper password - TrendMicro - to confirm a difference in execution.