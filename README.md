SimCity Population Growth Sim README
------------------------------------
Authors: Akeel Hanchard, Tejdeep Reddy, Kevin Licitis, Zayden Owens, Corbyn Ledbetter, Oscar Trujillo

Required files for compile
--------------------------
1. main.cpp
2. commercial.cpp
3. commercial.h 
4. residential.cpp
5. residential.h 
6. industrial.cpp
7. industrial.h 
8. zone.cpp
9. zone.h

Instructions for compile
------------------------
1. Gather the list of required files(above) for compile into one directory.
2. Using a Linux terminal or Windows command prompt, navigate to the MinGW folder using the command "cd C:\MinGW\bin"
3. Copy the directory path that stores the required files above
4. Using g++, enter the command "g++ " followed by "(directory)\*.cpp (directory)\*.h"
5. The above compiler will create a file "a" in the location of the compiler "C:\MinGW\bin"

Required files for runtime
--------------------------
1. a(a.exe if compiled in Windows, a.out if compiled in Linux)
2. .txt file containing region information(ex. region.txt)
3. .csv file containing the layout for the region

Instructions for runtime
------------------------
1. load a.exe/a.out. To launch this file in Linux, type "./a.out". To launch in Windows, type "a.exe"
2. The program will prompt user to enter a region file 
*NOTE: You must include .txt at the end of your file or the program will exit*
3. The program will run the simulation given the following parameters listed in the region.txt file
4. Results will be displayed and program will exit
