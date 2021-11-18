#include "config.h"
#include "led.h"
#include "led.c"
#include "macros.h"
#include "hardware.h"




int main() {	
	led_init();
	while(1)
  {
    led_toggle();
	}
  return 0;
}
