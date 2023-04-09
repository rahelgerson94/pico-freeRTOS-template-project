## Directories:

+ The **FreeRTOS/Source** directory contains the FreeRTOS source code, and contains
  its own readme file.

+ The **Applications/build** folder  contains the executables  be uploaded + run on the pico. 

+ The **FreeRTOS/Applications/Source** contains the source code (.c and .h files) which generate the executables. main.uf2 contains the instructions to implement the full functionality on the pico, e.g  SPI I/O,  kalman filtering, writing to pins. That is why multiple files are shwon in the directory structure.  
These files should be included in the add_executable() fct in Applications/Source/CMakeLists.txt.

## Important files
in every "main" file, make sure to include general_utils.h. This file contains the pico sdk library files as well necessary FreeRTOS kernel files.

## Building

cd Applications #from ~/Documents/Pico/FreeRTOS
mkdir build  
cd build  
cmake ..  
make  

## Uploading
with the pico in bootloader mode, run the following command from Applications/build/:\
`
cp main.uf2 /Volumes/RPI-RP2
`

 