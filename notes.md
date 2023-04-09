
3/12: streamlined FreeRTOS directory contents so I could have an base template  for my own projects
the direcotry structure is:
|- Source //unchanged 
|- Applications //used to be Demo. 
|   |- build/
|   |- OnEitherCore/
|   |- pico_sdk_import.cmake
|   |- Source/
|   |   |- pico_sdk_import.cmake
|   |   |- FreeRTOSConfig.h
|   |   |- main.c
|   |   |- FreeRTOS_Kernel_import.cmake
|   |   |- main.h
|   |   |- RegTest.s
|   |   |- CMakeLists.txt
|   |   |- <file1.c  // to be included in main.c
|   |   |- <file1.h  // to be included in main.c
|   |   |- <file2.c  // to be included in main.c
|   |   |- <file2.h  // to be included in main.c
|   |   |-          :
|   |   |-          :
|   |   |- <fileN.c  // to be included in main.c
|   |   |- <fileN.h  // to be included in main.c



definiations: 
- executables (.uf2 files)

INTENT
Source: contains the files necessary to FreeRTOS.

Applications/build folder  contains the executables  be uploaded + run on the pico. 

Applications/Source folder contains the source code (.c and .h files) which generate the executables. main.uf2 contains the instructions to implement the full functionality on the pico, e.g  SPI I/O,  kalman filtering, writing to pins. That is why multiple files are shwon in the directory structure.  
These files should be included in the add_executable() fct in Applications/Source/CMakeLists.txt. 