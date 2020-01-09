make-wiring ported For Windows
===========
Porting Earlz code to windows with minor adjustments for functunality.
the full thought process is posted here.
https://www.reddit.com/r/AskProgramming/comments/a19cdv/can_someone_show_me_how_to_implement_this_github/

# Requirements
Winavr: https://sourceforge.net/projects/winavr/

# Usage
**PREQS**

Load your libaries (.c and .h files) in folders within the ./src directory.

Load your code (test.cpp) into the main directory.

Change settings in bin/settings.ini to the specific application.

**With this repo you can:**

Open command prompt window in the directory and run the below commands to compile code, compile libaries, and upload code to a generic AVR

Open monitor.exe and specify baud rate and com port to view a serial port. (you need to connect the TX RX pins to an FTDI)

# Settings
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
 CODENAME is your code's file name without the cpp. This code is located in the main directory
 
 LIBS is the external libraries in the ./src directory. NOTE: make sure Arduino is last if using native arduino libraries like Wire or EEPROM.
 
 PROGRAMMER defines the ICSP programemr being used
 
 CPUFREQ is the Clock frequency your avr is to be used at (i.e 16MHz).
 
 MCU is the name of the avr
 
 PARTNO is another identifier for the avr
 
 Variant is where the pins_arduino.h file is located. This will allow you to use the arduino macros. For example:
 it will allow you to refer to pin PB0 on the avr as digital pin '8'. Make sure this file is the correct variant if you want to use the arduino core.
 
 Cflags and Cpp flags can be changed if needed
 
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


At any time the user can delete the ouput folder. Rebuilding will make a new one.




