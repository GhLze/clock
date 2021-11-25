#include <stc15.h>
#include <intrins.h>

unsigned char i;
unsigned char h=23;
unsigned char m=59;
unsigned char s=55;
unsigned char b[8]={0,0,10,0,0,10,0,0};
unsigned char code A[11]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0xbf};



void smg()
	{
	 b[0]=h/10;
	 b[1]=h%10;
	 b[3]=m/10;
	 b[4]=m%10;
	 b[6]=s/10;
	 b[7]=s%10;
 }
void shu()	
 {

	 P2 = (P2&0X1F) | 0XE0;
	 P0 =0xff;
	 P2 &=0X1F;
	
		P2 = (P2&0X1F) | 0XC0;
	  P0 = 0x01<<i;
	  P2 &=0X1F;
	
		
		  P2 = (P2&0X1F) | 0XE0;
	   P0 =A[b[i]];
		 P2 &=0X1F ;
	   i=(i+1)%8;
}

void BUZZER(bit temp)
{
	P2 = (P2&0X1F) | 0XA0;//打开Y5
	P06 = temp;//蜂鸣器
	P04 = temp;//继电器
	P2 &=0X1F;//关闭
}


void Timer0Init(void)		//1??@11.0592MHz
{
	AUXR |= 0x80;		//?????1T??
	TMOD &= 0xF0;		//???????
	TL0 = 0xCD;		//??????
	TH0 = 0xD4;		//??????
	TF0 = 0;		//??TF0??2
	TR0 = 1;		//???0????
}


void main (void)
{  Timer0Init();
	 ET0=1;
   EA=1;
	 BUZZER(0);
   while(1)
	{ 
		
		
	 }
} 
void Time0() interrupt 1
{
 static int count = 0;
	count++;
	smg();
	shu();
	if(count%1000==0)
	{
		s++;}
		if(s<60);
	else
	{
		s=0;
		m++;
		if(m<60);
		else
			{
				m=0;
				h++;
				if(h<24);
				else
					{
						h=0;
					}
				}
		}
	}

	
