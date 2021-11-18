#include "config.h"
//#include "lcd.h"
//#include "lcd.c"
#include "macros.h"
#include "hardware.h"

#define lcd_send_4bit(val) send_high_nibble_to_shift(lcd_data_PORT,lcd_data_digit,val)



#define rs_com() clearbit(lcd_com_PORT,RS_lcd_com_digit)

#define rs_data() setbit(lcd_com_PORT,RS_lcd_com_digit)

#define rw_write() clearbit(lcd_com_PORT,RW_lcd_com_digit)



#define lcdCommand(cmnd) lcdSend(1,cmnd);

#define lcdData(data) lcdSend(0,data);


  
void E_h2l()
{
  setbit(lcd_com_PORT,E_lcd_com_digit);
  _delay_us(1);
  clearbit(lcd_com_PORT,E_lcd_com_digit);
  _delay_us(100);
}

void lcdSend(unsigned char choice,unsigned char msg)
{
  clear4bit(lcd_data_PORT,lcd_data_digit);
  lcd_send_4bit(msg);
  if(choice)
    rs_com(); //command
  else
    rs_data();
  
  rw_write();
  E_h2l();
  clear4bit(lcd_data_PORT,lcd_data_digit);
  lcd_send_4bit((msg<<4));

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
  lcd_print(" Zyad Ahmed Said");
  lcd_gotoxy(1,2);
  lcd_print("Mackawy aka ZAM");
	while(1)
  {
	}
  return 0;
}
