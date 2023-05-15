#include "esp_common.h"

// Printf hello world every two seconds
void hello(void *pvParameters)
{
    while (1)
    {
        printf("Hello multi-threading world!\r\n");
        vTaskDelay(2000 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}

void howdee(char *Message)
{
    printf("%s\n", Message);
}