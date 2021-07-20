#include <csl.h>
#include <csl_pll.h>
#include <csl_emif.h>
#include <csl_chip.h>
#include <stdio.h>


//实验操控：
//选择TESTCOMMAND:1为自动运行,2为夜间模式,3为交通灯东西通,
//                 4为交通灯南北通,5为禁行。
unsigned int TESTCOMMAND =0	;
//#define TESTCOMMAND   1       //交通灯操作命令选择

unsigned int TestCommand =0;//无操作

#define TRAFFICAUTO	    0xAA14//自动运行模式
#define TRAFFICNIGHT	0xAA16//夜间模式
#define	TRAFFICEAST	    0xAA1A//东西通行	
#define TRAFFICSOUTH	0xAA1B//南北通行
#define TRAFFICFORBID	0xAA1C//禁行

#define  EASTEWEST     0x88c	//交通灯东西通（南北禁行）
#define  SOUTHNORTH    0x311	//交通灯南北通（东西禁行）  
#define  IOCHANGE      0x462	//交通灯各方向黄灯亮
#define  ALLFORBIN     0x914	//交通灯各方向均禁行
void delay(int period);


volatile unsigned char* DEL = (volatile unsigned char *)0x600000;//交通灯；对此地址不进行资源优化
volatile unsigned char* DECCTL = (volatile unsigned char *)0x280001;//控制寄存器
main()
{
    /*初始化CSL库*/	
    CSL_init();
    
    /*设置系统的运行速度为300MHz*/
    PLL_setFreq(1, 0xF, 0, 1, 3, 3, 0);
    
   	/*初始化DSP外部EMIF*/
    Emif_Config(); 
    *DECCTL=0x40;//将这个值赋给
    
   /* #if TESTCOMMAND==1
		TestCommand =TRAFFICAUTO;//自动运行
	#endif
	#if TESTCOMMAND==2
		TestCommand =TRAFFICNIGHT;//夜间模式
	#endif
	#if TESTCOMMAND==3
		TestCommand =TRAFFICEAST;//交通灯东西通
	#endif
	#if TESTCOMMAND==4
		TestCommand =TRAFFICSOUTH;//交通灯南北通
	#endif
	#if TESTCOMMAND==5
		TestCommand =TRAFFICFORBID;//禁行
	#endif	   */
	for(;;)
	{	
		switch(TESTCOMMAND)
		{	
			/*自动运行模式*/
			case 1:
				/*白天模式*/
				
				/*从东西到南北*/
				*DEL=EASTEWEST;
				delay(2000);
				*DEL=IOCHANGE;
				delay(1000);
				*DEL=SOUTHNORTH;
				delay(8000);
				
				/*从南北到东西*/
				*DEL=SOUTHNORTH;
				delay(2000);
				*DEL=IOCHANGE;
				delay(1000);
				*DEL=EASTEWEST;
				delay(8000);
				break;			
			
			/*夜间模式*/	
			case 2:
				*DEL=IOCHANGE;
     			delay(6000);
				*DEL=0;
				delay(6000);
				break;
			
			/*交通灯东西通*/
			case 3:
                *DEL=IOCHANGE;
				delay(1000);
				*DEL=EASTEWEST;		
			    delay(2000);
			  
				break;

			/*交通灯南北通*/	
			case 4:
                *DEL=IOCHANGE;
				delay(1000);
				*DEL=SOUTHNORTH;
				delay(2000);
			
				break;

			/*禁行*/	
			case 5:
				*DEL=IOCHANGE;	
				delay(1000);
				*DEL=ALLFORBIN;		
				delay(2000);
			
				break;							
			
			default:
				break;
		} 		
	}			
}

void delay(int period)
{
    int i, j;
    
    for(i=0; i<period; i++)
    {
        for(j=0; j<0x1000; j++);
    }
}

/******************************************************************************\
* End of 5502_FALSH.c
\******************************************************************************/
