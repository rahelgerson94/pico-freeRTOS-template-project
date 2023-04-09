/*
 * FreeRTOS V202107.00
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#define TASK_PRIORITIZATION 
#define HEAP 
#define QUEUE 1
#include "general_utils.h"

/* rahel's includes */
#include "r_queue.h"
/* globals */
static void prvSetupHardware( void );
static void init_pin(unsigned int pin_number, unsigned int dir);

static const unsigned int gQ1_LENGTH = 3;
static const unsigned int gQ2_LENGTH = 3;
 
#define TASK_COUNT 2   

/*-----------------------------------------------------------*/
int main( void )
{
 
   
    /* Perform any hardware setup necessary. */
    
    prvSetupHardware();
    printf("enetered main()\n");
    /* The queue is created to hold a maximum of 5 values, each of which is
    large enough to hold a variable of type int32_t. */
    xQueue = xQueueCreate( 5, sizeof( int32_t ) );
    //q1 = xQueueCreate(5, sizeof(int32_t ));

    /* --- APPLICATION TASKS CAN BE CREATED HERE --- */
    /* Create the first task at TASK_COUNT (highest priority).  The task parameter is not used
    and set to NULL.  The task handle is also not used so is also set to NULL. */
    
    // #if TASK_PRIORITIZATION==1
    //     printf("got here\n");
    //     init_pin(LED1, OUT);
    //     init_pin(LED2, OUT);
    //     init_pin(ERR_LED, OUT);
    //     //xTaskCreate( vTask1, "Task 1", 1000, NULL, TASK_COUNT, NULL );
    //     // xTaskCreate( blink1, "Task 1", 1000, NULL, TASK_COUNT, NULL );
    //     xTaskCreate( blink, "blink ", 1000, NULL, TASK_COUNT-1, NULL );
    //     /* The task is created at priority 2 ______^. */
    //     /* Create the second task at TASK_COUNT -1, which is lower than the priority
    //     given to Task 1.  Again the task parameter is not used so is set to NULL -
    //     BUT this time the task handle is required (used by vTask1) so the address of xTask2Handle
    //     is passed in the last parameter. */
    
    //     //xTaskCreate( vTask2, "Task 2", 1000, NULL, TASK_COUNT-1, &xTask2Handle );
    //     xTaskCreate( vListenSerial, "serial listener", 1000, NULL, TASK_COUNT, NULL );
    // #elif HEAP==1
    //     printf("got here\n");
    //     xTaskCreate( vGetChar, "1", 1000, NULL, TASK_COUNT, NULL );
    // #elif QUEUE==1
        
        if (xQueue != NULL)
        {

            // //q2 = xQueueCreate(gQ2_LENGTH, sizeof(char));
            // printf("enter delay between blinks\n: ");
            // unsigned int rate;
            // scanf(" %u", &rate);
            // xQueueSendToBack(q1, rate, 0);

            xTaskCreate(
            vSenderTask, //pointer to defining function
            "Sender 1", //name
            1024, //stack depth
            (void*) 10, //no parameters passed
            1, //priority
            NULL //task handle
            ); 

            xTaskCreate(
            vSenderTask, //pointer to defining function
            "Sender 2", //name
            1024, //stack depth
            (void*) 20, //no parameters passed
            1, //priority
            NULL //task handle
            ); 

            xTaskCreate(
            vReceiverTask, //pointer to defining function
            "Receiver", //name
            1024, //stack depth
            NULL, //no parameters passed
            TASK_COUNT, //equal priority as task A
            NULL //task handle
            ); 

        }
        else
        {
            printf("couldn't create q1");
        }
        
   // #endif

    /* Start the scheduler so the tasks start executing. */
    vTaskStartScheduler();
    /* If all is well then main() will never reach here as the scheduler will
    now be running the tasks.  If main() does reach here then it is likely there
    was insufficient heap memory available for the idle task to be created.
    Chapter 2 provides more information on heap memory management. */
    
    for( ;; );
}

