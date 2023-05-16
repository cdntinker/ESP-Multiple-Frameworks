#include "esp_common.h"
#include "gpio.h"

#include "Functions.h"

// Blink the led @1Hz
void Blink(void *pvParameters)
{
    while (1)
    {
        TellMe0("[LED] On");
        GPIO_OUTPUT_SET(2, 1);
        vTaskDelay(500 / portTICK_RATE_MS);

        TellMe0("[LED] Off");
        GPIO_OUTPUT_SET(2, 0);
        vTaskDelay(500 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}
