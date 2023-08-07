#include <avr/io.h>
#include <avr/power.h>
#include "usart.h"

int main(void) {
  clock_prescale_set(clock_div_1);
  uint16_t counter = 0;
  
  usart_init();

  // Print formatted strings
  usart_print("USART Write Demo\r\n\n");
  usart_print("Printing formatted data:\r\n");

  // Print integers
  int16_t int1 = -12345;
  usart_print("Integer: ");
  usart_print_num(int1);
  usart_print("\r\n");

  // Print floats
  float float1 = 123.4567; 
  usart_print("Float: ");
  usart_print_float(float1, 2);
  usart_print("\r\n");

  // Print char
  char c = 'X';
  usart_print("Char: ");
  usart_print_char(c);
  usart_print("\r\n");

  // Print string
  char *str = "Hello World!";
  usart_print("String: ");
  usart_print(str);
  usart_print("\r\n");

  // Continuously print counter
  usart_print("Continuous counter: \n\r");
  while(1) {
    usart_print_num(counter++);
    usart_print("\r");
  }

}