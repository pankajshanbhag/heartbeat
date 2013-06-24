#include<at89x52.h>//reg51.h 
sbit lcd_d7 = P2^3;//LCD interface in 4 bit mode


sbit lcd_d6 = P2^2; 
sbit lcd_d5 = P2^1; 
sbit lcd_d4 = P2^0; 
sbit lcd_en = P2^4; 
sbit lcd_rs = P2^5; 
unsigned char bt,sec,sec100,min,r,t1,t2; 
void initializelcd(); 
void delay(n); 
void lcd_send_byte(unsigned char godata,bit w); 
void gotoxy(unsigned char x, unsigned char y); 
void printlcd(unsigned char *ch); 
void send(void); 
void extrint (void) interrupt 0 
{ 
bt++; 

} 
void timer0 (void) interrupt 1 using 1 
{ 
TH0 = 0xdc; 
sec100++; 
if(sec100>=10) 
{ 
sec++; 
sec100=0; 
if(sec>=6) 
{ 
min++; 
sec=0; 
} 
} 
} 

main() 
{ EA = 1; 
TMOD = 0x21; 
IT0 = 1; 
EX0 = 1; 
ET0 = 1; 
TR0 = 1; 

delay(1000); 
initializelcd(); 
delay(1000); 
gotoxy(0,0); 
delay(1500); 
printlcd("Welcome to H.R.M. "); 
delay(500); 
t1=0;t2=0; 
//delay(15000); 

while(1) 
{ 

if(min>=1) 
{ 
gotoxy(0,1); 
delay(500); 
bt=t1; 
lcd_send_byte((bt/100)+48,1); 
r=bt%100; 
lcd_send_byte((r/10)+48,1); 
lcd_send_byte((r%10)+48,1); 
delay(500); 
min=0; 
} 
} 
} 
void initializelcd(void) 
{ 
delay(16000); 
lcd_en = 1; 
lcd_send_byte(0x30,0); 
delay(1000); 
lcd_en = 0; 
delay(1000); 
lcd_en = 1; 
lcd_send_byte(0x30,0); 
delay(1000); 
lcd_en = 0; 
delay(1000); 
lcd_en = 1; 
lcd_send_byte(0x30,0); 
delay(1000); 
lcd_en = 0; 
delay(1000); 
lcd_en = 1; 
lcd_send_byte(0x20,0); 
delay(1000); 
lcd_en = 0; 
delay(1000); 
lcd_en = 1; 
lcd_send_byte(0x28,0); 
delay(500); 
lcd_send_byte(0x10,0); 
delay(500); 
lcd_send_byte(0x01,0); 
delay(500); 
lcd_send_byte(0x06,0); 
delay(500); 
lcd_send_byte(0x0c,0); 
delay(500); 
lcd_send_byte(0x1c,0); 
delay(500); 
lcd_send_byte(0x01,0); 
delay(500); 
} 

void delay(ndelay) 
int ndelay; 
{ 
int idelay; 

for (idelay=0;idelay <=ndelay;idelay++){;}
}


