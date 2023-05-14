// Example code from
//   https://github.com/platformio/platform-espressif8266/tree/develop/examples/esp8266-rtos-sdk-blink
//
// Except...  This one actually functions...

#include "esp_common.h"
#include "freertos/task.h"
#include "gpio.h"


/******************************************************************************
 * NFC how this was SUPPOSED to work...
 * It didn't...
 * 
 * Went hunting around the Interwebs & found a random StackOverflow thread
 * where I found the `GPIO_OUTPUT_SET` call that I've inserted in place of the
 * `gpio16_output_set()` calls.  Now it works.
 * (BTW...  The documentation I've seen so far sucks.)
*******************************************************************************/
void task_blink(void* ignore)
{
    // gpio16_output_conf();
    while(true) {
//    	gpio16_output_set(0);
        GPIO_OUTPUT_SET (2, 0);
        vTaskDelay(100/portTICK_RATE_MS);
//    	gpio16_output_set(1);
        GPIO_OUTPUT_SET (2, 1);
        vTaskDelay(1000/portTICK_RATE_MS);
    }

    vTaskDelete(NULL);
}

/******************************************************************************
 * FunctionName : user_init
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void user_init(void)
{
    xTaskCreate(&task_blink, "startup", 2048, NULL, 1, NULL);
}
