# RECON-2024

This repository contains various examples for collecting coverage on iOS and Android. The Cartographer Ghidra extension by NCCGroup is also included as the current release is temporarily broken for Ghidra 11.1 - this version has the required patch.

## iOS Coverage

Example covers coverage collection for `libsystem_kernel.dylib` calls made by TrollInstallerX when executing the PhysPuppet privilege escalation.

## Android Native Coverage 

Example covers coverage collection for `libmsysinfra.so` packaged within Facebook Messenger & a toy example binary for non-root coverage collection called `fysa`.

## Android Native Coverage 

Example covers coverage collection for `MessagesNotificationManager` in Facebook Messenger as well as instructions for collecting coverage for the TrendMicro Keybox CTF.
