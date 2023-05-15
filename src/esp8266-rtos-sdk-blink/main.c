// Example code from
//   https://calangorobo.blogspot.com/2018/03/a-guide-to-esp8266-rtos-sdk.html

#include "esp_common.h"
#include <stdio.h>
#include "uart.h"
#include "gpio.h"

void hello(void *pvParameters);
void blink(void *pvParameters);
void howdee(char *Message);

// "Main" function
void user_init(void)
{
    // Change the default value of the baudrate to 115200 (printf uses UART0)
    // UART_SetBaudrate(UART0, BIT_RATE_115200);
    UART_SetBaudrate(UART0, BIT_RATE_74880);
    howdee("6");
    howdee("5");
    howdee("4");
    howdee("3");
    howdee("2");
    howdee("1");
    howdee("0");
    howdee("Whoop Dee Doo!!!");

    // GPIO2 set as IO
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);
    // Hello and Blink tasks
    // xTaskCreate(hello, "hello", 256, NULL, 2, NULL);
    xTaskCreate(blink, "blink", 256, NULL, 2, NULL);
}