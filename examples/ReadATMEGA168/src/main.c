#include <avr/io.h>
#include <avr/power.h>
#include "usart.h"

int main(void) {
  clock_prescale_set(clock_div_1);

  usart_init();
  usart_print("USART Read Demo\r\n\n");
  while (1) {

    // Prompt for input
    usart_print("Enter text: ");
    
    // Wait for data in usart_last_command
    usart_waitForCommand();

    // Echo back input
    usart_print("\r\nYou entered: ");
    usart_print(usart_last_command);  
    usart_print("\r\n");

    // Parse input numbers
    usart_print("\r\nEnter numbers: ");
    usart_waitForCommand();
    
    float nums[1];
    usart_get_numbers(usart_last_command, USART_BUFFER_SIZE, nums);
    
    usart_print("You entered:");
    usart_print_num(nums[0]);

    usart_print("\r\n");
    usart_print("END\r\n");

    break;
  }

}