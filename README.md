# Learn about debugging
Inspired by Low Level Learning 
[video](https://www.youtube.com/watch?v=3T3ZDquDDVg&list=PLx9cFXs5R8k_TbMWYuBtjHoqyFIFDkfbd&index=39).

## Build
Build with debug information adding `-g` option: `gcc main.c -o inventory -g`

## Core dump
Let the program crash to produce the core dump file and inspect it.

### Setup
Allow the kernel to dump any amount of core dump: `ulimit -c unlimited`
Set the location of the core dump files to the executable local dir: `echo "./core" > /proc/sys/kernel/core_pattern`
The previous command must be preceded by `sudo su` because the simply `sudo` does not elevate the redirection of output.
Check the location of the core dump files: `cat /proc/sys/kernel/core_pattern`

### Inspect crash informations
Inspect content of core dump file using `gdb` command: `gdb ./inventory core`

Inside the gdb console:
* examine instruction at pc `x\i $pc`
* `info registers`