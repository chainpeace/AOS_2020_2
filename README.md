# AOS_2020_2

Page-level Memory Tracing Tool


branch for testing to make intentional page fault

Usage

1)apply patch and compile kernel

$cd linux-v5.4.49-vanilla

$patch -p1 < ../plmt_dmesg.patch ( or pltm_kwrite)

-- kernel compile and reboot --

2)compile enable program

$gcc -o enable_plmt enable_plmt.c

3)enable tracing : ./enable_plmt [command]

$./enable_plmt ls

4)do tracing

$ls

$dmesg

( or when you apply kwrite patch file, check /output.txt file)

5)disable tracing

$./enable_plmt

