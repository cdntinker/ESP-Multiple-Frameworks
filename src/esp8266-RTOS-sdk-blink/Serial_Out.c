#include "esp_common.h"

#include "MACROS.h"
#include "Functions.h"

// Printf Hello world every two seconds
void Hello(void *pvParameters)
{
    while (1)
    {
        TellMe0("Hello multi-threading world!");
        vTaskDelay(2000 / portTICK_RATE_MS);
    }
    vTaskDelete(NULL);
}

void DescribeMe()
{
    printf("\n\n");
    printf("===============================\n");
    printf("This is: %s\n", STR(Device_Name));
    printf("SDK version: %s\n", system_get_sdk_version());
    printf("===============================\n");
}

void TellMe0(char *Message)
{
#ifdef DEBUG
    printf("%s\n", Message);
#endif
}

void TellMe1(char *Message, char *string)
{
#ifdef DEBUG
    printf(Message, string);
#endif
}
