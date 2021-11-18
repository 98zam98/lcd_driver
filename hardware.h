
#ifndef HARDWARE_H_
#define HARDWARE_H_

/*lcd data ports*/
#define lcd_data_digit	0
#define lcd_data_dir 	DDRC
#define lcd_data_PORT  	PORTC
//--------------------------------------	



/*lcd com ports*/
#define lcd_com_digit	2
#define RS_lcd_com_digit	2
#define RW_lcd_com_digit	3
#define E_lcd_com_digit	4
#define lcd_com_dir 	DDRD
#define lcd_com_PORT  	PORTD
//--------------------------------------	


#endif