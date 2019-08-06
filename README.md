# Chip-8 Emulator in C

## Building
To build all three components (compiler, decompiler, and emulator), run

`./build.sh`

Otherwise, `cd` into the appropriate directory and run

`make`

## About
This project was built entirely with the C Standard Library, so no external
dependencies are needed, other than make/GCC/Clang to build.

## Compiling
After writing your program in the Chip-8 assembly language, you can compile it
to a Chip-8 compatible binary using either the built compiler program, found in

`compiler/bin/compile`

Alternatively, you can use the script

`cc.sh`

to compile your program. In both instances, the command looks like this:

`./[executable] [source file] [output file]`

## Running
To run a .ch8 program, launch the emulator with the following command:

`./bin/chip-8 [binary file] -e=x`

where `x` is the endianess of the program binary, either `l` for little or `b`
for big. There's no easy way to tell which a pre-built binary complies with,
but this compiler builds binaries in big-endian format.

The program will start automatically after the splash displays.

## Decompiling
The decompiler is not entirely reliable, as is the case with most decompilers.
The possibility exists that a Chip-8 binary may include a jump or call to an
odd-numbered address, in which case the everything after that address will be
offset by a nibble, making for garbage output. It also can sometimes stumble on
sprites or other data interlaced among the code. The best option is to stick to
even-addressed jumps, and leave all sprites/data at the end of the program
(although I understand that the decompiler will not be very useful for your own
programs. It was mostly built as a verification that the compiler and
interpreter were looking at commands the same way, and to provide easier reading
of hexdumps from pre-built binaries).

Similarly to compiling, decompiling can be done either directly with the
executable, found at

`decompiler/bin/decompile`

or the script

`dc.sh`

The command will look like this:

`./[executable] [binary file] -e=x`

where `x` is the endianess (see above under Running). You can redirect the
output to a file for easier perusal.

## Instruction Set
A fairly detailed listing of the instruction set can be found here:

http://devernay.free.fr/hacks/chip8/C8TECH10.HTM#3.0

A few notes:
* The `SYS` instruction does nothing in this implementation.
* The keyboard is currently non-functional, so `SKP` and `SKNP` do nothing.
	However, `LD Vx, K` does seem to work to some extent. 
