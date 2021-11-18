#include "config.h"
//#include "lcd.h"
//#include "lcd.c"
#include "macros.h"
#include "hardware.h"

#define LCD_DPRT lcd_data_PORT

#define LCD_DDDR lcd_data_dir

#define LCD_CPRT lcd_com_PORT

#define LCD_CDDR lcd_com_dir

#define LCD_RS RS_lcd_com_digit

#define LCD_RW RW_lcd_com_digit

#define LCD_E E_lcd_com_digit


#define lcd_send_4bit(val) send_high_nibble_to_shift(lcd_data_PORT,lcd_data_digit,val)



#define rs_com() clearbit(lcd_com_PORT,RS_lcd_com_digit)

#define rs_data() setbit(lcd_com_PORT,RS_lcd_com_digit)

#define rw_write() clearbit(lcd_com_PORT,RW_lcd_com_digit)

  
void E_h2l()
{
  setbit(lcd_com_PORT,E_lcd_com_digit);
  _delay_us(1);
  clearbit(lcd_com_PORT,E_lcd_com_digit);
  _delay_us(100);
}

void lcdCommand(unsigned char cmnd)
{
  //lcd_data_PORT =(cmnd&0xf0)>>(4-lcd_data_digit);
  clear4bit(lcd_data_PORT,lcd_data_digit);
  lcd_send_4bit(cmnd);
  //clearbit(lcd_com_PORT,RS_lcd_com_digit);
  rs_com();
  //clearbit(lcd_com_PORT,RW_lcd_com_digit);
  rw_write();
  
  E_h2l();
  
  //lcd_data_PORT =((cmnd<<4)&0xf0)>>(4-lcd_data_digit);
  clear4bit(lcd_data_PORT,lcd_data_digit);
  lcd_send_4bit((cmnd<<4));

  E_h2l();
}


void lcdData(unsigned char data)
{
  clear4bit(lcd_data_PORT,lcd_data_digit);
  lcd_send_4bit(data);
  //clearbit(lcd_com_PORT,RS_lcd_com_digit);
  rs_data();
  //clearbit(lcd_com_PORT,RW_lcd_com_digit);
  rw_write();
  
  E_h2l();
  
  //lcd_data_PORT =((cmnd<<4)&0xf0)>>(4-lcd_data_digit);
  clear4bit(lcd_data_PORT,lcd_data_digit);
  lcd_send_4bit((data<<4));

  E_h2l();
}

void lcd_init()
{
  send_high_nibble_to_shift(lcd_data_dir,lcd_data_digit,0xff);
  
  setbit(lcd_com_dir,RS_lcd_com_digit);
  setbit(lcd_com_dir,RW_lcd_com_digit);
  setbit(lcd_com_dir,E_lcd_com_digit);
  
  clearbit(lcd_com_PORT,E_lcd_com_digit);

  lcdCommand(0x33);
  lcdCommand(0x32);
  lcdCommand(0x28);
  lcdCommand(0x0e);
  lcdCommand(0x01);

  _delay_us(2000);
  
  lcdCommand(0x06);
}

void lcd_gotoxy(unsigned char x,unsigned char y)
{
  unsigned char pos[] = {0x80,0xc0};
  
  lcdCommand(pos[y-1]+(x-1));;

  _delay_us(100);
}

void lcd_print(char *str)
{
  unsigned char i = 0;
  while(str[i] != 0)
  {
    lcdData(str[i]);
    i++;
  }
}


int main() {
  lcd_init();
  lcd_gotoxy(1,1);
  lcd_print("the world is but");
  lcd_gotoxy(1,1);
  lcd_print("one country");
	while(1)
  {
	}
  return 0;
}
