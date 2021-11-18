#ifndef __MACROS_H__
#define __MACROS_H__

// macros start

#define setbit(reg,shift) reg|=(1<<shift)
#define clearbit(reg,shift) reg&=~(1<<shift)
#define togglebit(reg,shift) reg^=(1<<(shift))
#define checkbit(reg,shift) ((reg) & (1<<(shift)))
#define checkbit0(reg,shift) (((reg) & (1<<(shift)))>>shift)
#define assignbit(reg,shift,val) reg|=(val<<shift)

#define send_high_nibble(reg,val) reg =(val&0xf0)

#define clear4bit(reg,shift) reg&=~(0x0f<<shift)

#define send_high_nibble_to_shift(reg,shift,val) reg |=(val&0xf0)>>(4-shift)
// macros end

#endif