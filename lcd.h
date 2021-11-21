#ifndef LCD_H_
#define LCD_H_
#include "config.h"
#include "macros.h"
#include "hardware.h"

#define lcd_send_4bit(val) send_high_nibble_to_shift(lcd_data_PORT,lcd_data_digit,val)



#define rs_com() clearbit(lcd_com_PORT,RS_lcd_com_digit)

#define rs_data() setbit(lcd_com_PORT,RS_lcd_com_digit)

#define rw_write() clearbit(lcd_com_PORT,RW_lcd_com_digit)



#define lcdCommand(cmnd) lcdSend(1,cmnd);

#define lcdData(data) lcdSend(0,data);


  
void E_h2l();

void lcdSend(unsigned char choice,unsigned char msg);

void lcd_init();

void lcd_gotoxy(unsigned char x,unsigned char y);

void lcd_print(char *str);


// commands

#define clear_display_screen 0x01

#define return_home 0x02

#define shift_cursor_to_left 0x04

#define shift_cursor_to_right 0x06

#define shift_display_left 0x07

#define shift_display_right 0x05

// =======================================
/*
#define clear_display_screen

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1

#define clear_display_screen 1
*/
#endif /* LCD_H_ */