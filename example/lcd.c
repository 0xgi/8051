#include "lcd.h"

sbit LCD_RS = P2^0;
sbit LCD_EN = P2^1;
#define LCD_DATA P3

void Delay_ms(unsigned int t) {
	unsigned int x, y;
	for (x = 0; x < t; x++) {
		for (y = 0; y < 123; y++);
	}
}

void LCD_cmd(unsigned char cmd) {
	LCD_RS = 0;
	LCD_DATA = cmd;
	LCD_EN = 0;
	LCD_EN = 1;
	Delay_ms(2);
}

void Send_char(char c) {
	LCD_RS = 1;
	LCD_DATA = c;
	LCD_EN = 0;
	LCD_EN = 1;
	Delay_ms(2);
}

void Send_str(char *str) {
	
	unsigned char i = 0;

	while(str[i] != 0) {
		Send_char(str[i]);
		i++;
	}
}

void main(){
	LCD_cmd(0x0C);
	LCD_cmd(0x38);
	Send_str("      0xgi");

	while(1) {

	}
}