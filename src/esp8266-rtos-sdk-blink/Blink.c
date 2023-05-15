#include "esp_common.h"
#include "gpio.h"

// Blink the led @1Hz
void blink(void *pvParameters) 
{ 
    while (1) 
    {
        printf("[LED] On\r\n");
        GPIO_OUTPUT_SET(2, 1);
        vTaskDelay(500/portTICK_RATE_MS);

        printf("[LED] Off\r\n");
        GPIO_OUTPUT_SET(2, 0);
        vTaskDelay(500/portTICK_RATE_MS);
    } 
    vTaskDelete(NULL); 
}
