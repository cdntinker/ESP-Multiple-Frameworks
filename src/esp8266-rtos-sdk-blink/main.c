// Example code from
//   https://calangorobo.blogspot.com/2018/03/a-guide-to-esp8266-rtos-sdk.html

#include "esp_common.h"
#include <stdio.h>
#include "uart.h"
#include "gpio.h"

#include "Functions.h"


// "Main" function
void user_init(void)
{
    // Change the default value of the baudrate to 115200 (printf uses UART0)
    // UART_SetBaudrate(UART0, BIT_RATE_115200);
    UART_SetBaudrate(UART0, BIT_RATE_74880);

    DescribeMe();

    // GPIO2 set as IO
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

// Hello and Blink tasks
    xTaskCreate(Hello, "Hello", 256, NULL, 2, NULL);

    xTaskCreate(Blink, "Blink", 256, NULL, 2, NULL);
}