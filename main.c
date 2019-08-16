#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"
#include "key.h"
 
 int main(void)
 {	
	u8 key=0;
	u16 a,b,i,j;
	a=6000;
	 b=5000;
	delay_init();	    
	LED_Init();
	KEY_Init();
	while(1)
	{
		key=KEY_Scan(0);
		if(key)
		{						   
			switch(key)
			{				 
				case KEY1_PRES:	
        for(i=0;i<1000;i++)
				{				
					LED1=0;
					delay_ms(200);
		      LED1=1;
		      LED0=0;
					delay_ms(200);
		      LED0=1;
					delay_ms(10);
					if(KEY1==0)
						break;
				}	
					break;
				case KEY0_PRES:
					delay_ms(10);
					for(j=0;j<1000;j++)
				   {
						for(i=0;i<=a;i++)
						{
							LED0=0;
							delay(i);
							LED0=1;
							delay(a-i);
						 if(KEY0==0)
					   break;
						}
						for(i=0;i<b;i++)
						{
							LED0=0;
							delay(b-i);
							LED0=1;
							delay(i);
						if(KEY0==0)
					   break;
						}
			}
		}
		}else delay_ms(10); 		
  }
}


