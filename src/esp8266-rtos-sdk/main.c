// Example code from
//   https://github.com/platformio/platform-espressif8266/tree/develop/examples/esp8266-rtos-sdk-blink
//
// Except...  This one actually functions...

#include "esp_common.h"

void task_blink(void* ignore);

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
