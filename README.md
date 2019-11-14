make-wiring ported For Windows
===========
Porting Earlz code to windows with minor adjustments for functunality.
the full thought process is posted here.
https://www.reddit.com/r/AskProgramming/comments/a19cdv/can_someone_show_me_how_to_implement_this_github/

# Requirements
Winavr: https://sourceforge.net/projects/winavr/

# Usage
Load your libaries (.c and .h files) in folders within the ./src directory
Load your code (test.cpp) into the main directory
Change settings in bin/settings.ini to the specific application
# Command line interface
1. build -- This will build and compile a specified library. It will first copy all the header files from every library to `output/include`. It then compiles all the libraries and then outputs the library binaries to the `output/lib`. If your libraries are interdependent try running build all so that all the header files get included. If there is an error in one library the command window will print the errors in the console.
2. clean -- This will remove all the compiled .o files from the src directory. It will not remove files from the output directory
3. rebuild -- will clean and then build
4. compile -- compiles your .cpp file that is in the main directory. Errros will show in the command prompt.
5. upload -- will compile and convert the built binary files, stored in the output directory, into a .hex file and use avrdude to upload to the specified AVR.

Usage is simple, make sure you have winAVR.
List the command and then the library you wish to compile. List "all" if you want to compile all the libraries in ./src/

**build command compiles all the .c and .cpp library files into .o files and .a files** 

    ./build.exe build arduino
    ./build.exe build Wire
    ./build.exe build all
Afterwards, you'll have the relevant header files and compiled binaries in the `output/lib and output/include` directory
	
   **clean command deletes all .o files**

    ./build.exe clean arduino
	./build.exe clean all
	
   **rebuild command cleans then builds**
   
	./build.exe rebuild arduino
    	./build.exe rebuild all
Afterwards, you'll have the relevant header files and compiled binaries in the `output/lib and output/include` directory

  **compile command compiles your main code**
  
  	./build.exe compile
Afterwards, you'll have the compiled binary in the `output/codes` directory

  **upload command will compile your main code and upload its .hex file to the avr.**

	./build.exe upload 

and the avr should reset and run the uploaded code

# Retargetting
Change settings in bin/settings.ini
For example: 16MHz Atmega644pa using libraries Wire EEPROM and Arduino. Using avrgcc, compiling test.cpp and uploading it to the avr with an stk500 programmer on COM17.

    CODENAME=test ;without cpp
    LIBS= EEPROM Wire avr Arduino;
    PROGRAMMER = stk500 ;https://www.nongnu.org/avrdude/user-manual/avrdude_4.html
    COMPORT=COM17
    CPUFREQ="16000000UL"
    MCU="atmega644pa"
    PARTNO="m644p" ;https://www.nongnu.org/avrdude/user-manual/avrdude_4.html
    VARIANT='standard' ;where to get the `pins_arduino.h` file
    CFLAGS="-w -Os -Wl,--gc-sections -ffunction-sections -fdata-sections -std=c99"
    CPPFLAGS="-w -Os -Wl,--gc-sections -ffunction-sections -fdata-sections"
    ARFLAGS=""
    SOURCES="src"
    OUTPUTS="output"
    
You can also tweak other parameters like `CFLAGS` to your liking as well.


