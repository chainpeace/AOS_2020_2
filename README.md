# AOS_2020_2

Page-level Memory Tracing Tool

branch for testing to make intentional page fault

Usage

1)apply patch
$cd linux-v5.4.49-vanilla
$patch -p1 < ../page_fault.patch

2)compile enable program
$cd ../
$gcc -o enable_plmt enable_plmt.c

3)enable tracing : ./enable_plmt [command]
$./enable_plmt ls

4)do tracing
$ls
$dmesg

5)disable tracing
$./enable_plmt


