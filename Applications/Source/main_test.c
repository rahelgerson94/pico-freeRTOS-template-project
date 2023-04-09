#include "file.h"
/* test to see if I can call a function from another function that 
gets created into a task*/

int main(void){
    prvSetupHardware();
    printf("entered main\n");
    /* create kernel objects here */
    vTaskStartScheduler();
    for (;;){}
}