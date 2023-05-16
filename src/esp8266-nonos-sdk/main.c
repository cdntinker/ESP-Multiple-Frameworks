// Example code from
//   https://github.com/platformio/platform-espressif8266/blob/master/examples/esp8266-nonos-sdk-Blink/platformio.ini

#include "osapi.h"
#include "user_interface.h"

void blinky(void *arg);

static os_timer_t ptimer;

void ICACHE_FLASH_ATTR user_init(void)
{
    gpio_init();

    uart_init(74880, 74880);
    os_printf("3\n");
    os_printf("2\n");
    os_printf("1\n");
    os_printf("0\n");
    os_printf("SDK version:%s\n", system_get_sdk_version());
    os_printf("This is \"esp8266-nonos-sdk\"\n");

    // Disable WiFi
    	wifi_set_opmode(NULL_MODE);

    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO2_U, FUNC_GPIO2);

    os_timer_disarm(&ptimer);
    os_timer_setfn(&ptimer, (os_timer_func_t *)blinky, NULL);
    os_timer_arm(&ptimer, 100, 1);
}
