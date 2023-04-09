cmake_minimum_required(VERSION 3.13)

# Pull in SDK (must be before project)
include(pico_sdk_import.cmake)

# Pull in FreeRTOS
include(FreeRTOS_Kernel_import.cmake)

project(example C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

set(target_name main)
pico_sdk_init()
add_executable(
        ${target_name}
        #main_r_timers.c
        main_test.c
        RegTest.s 
        )
#rahel insert
pico_enable_stdio_usb(${target_name} 1)
#end rahel insert

target_include_directories(${target_name} PRIVATE
        ${CMAKE_CURRENT_LIST_DIR} # Applications/Source
        # ${CMAKE_CURRENT_LIST_DIR}/../Common/include
)

target_compile_definitions(${target_name} PRIVATE
        PICO_STDIO_STACK_BUFFER_SIZE=64 # use a small printf on stack buffer
)
target_link_libraries(${target_name} 
                        pico_stdio
                        pico_stdlib 
                        pico_printf
                        
                        FreeRTOS-Kernel 
                        FreeRTOS-Kernel-Heap4)

pico_add_extra_outputs(${target_name})
