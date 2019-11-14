make-wiring ported For Windows
===========
Porting Earlz code to windows with minor adjustments for functunality.
the full thought process is posted here.
https://www.reddit.com/r/AskProgramming/comments/a19cdv/can_someone_show_me_how_to_implement_this_github/

# Requirements
Winavr: https://sourceforge.net/projects/winavr/

# Usage
Load your libaries (.c and .h files) in folders within the ./src directory
commandline interface:
1. build -- This will build the library. It will copy all the header files first to `output/include`. It outputs the library to the `output/lib`if your libraries are interdependent try running build all so that all the header files get included
2. clean -- This will remove all the compiled files from the src directory. It will not remove files from the output directory
3. rebuild -- will clean and then build

Usage is simple, make sure you have winAVR.
list the command and then the library you wish to compile. List "all" if you want to compile all the libraries in ./src/

build command builds the .c and .cpp files into .o files and then compiles into a .a file:

    ./build.exe build arduino
    ./build.exe build Wire
    ./build.exe build all
	
   clean command deletes all .o files:
   
    ./build.rb clean arduino
	./build.rb clean all
	or
    ./build.exe clean arduino
	./build.exe clean all
	
   rebuild command cleans then builds:
   
    ./build.rb rebuild arduino
    ./build.rb rebuild all
	or
	./build.exe rebuild arduino
    ./build.exe rebuild all


and afterwards, you'll have the relevant header files and compiled libraries in the `output/lib and output/include` directory

There are three possible options for every library



# Retargetting
Change settings in bin/settings.ini
For example: 16MHz Atmega328p

    VARIANT='standard' #where to get the `pins_arduino.h` file
    CPUFREQ="16000000UL"
    MCU="atmega328p"
You can also tweak other parameters like `CFLAGS` to your liking as well.


