#include <csl.h>
#include <csl_pll.h>
#include <csl_emif.h>
#include <csl_chip.h>
#include <stdio.h>


//ʵ��ٿأ�
//ѡ��TESTCOMMAND:1Ϊ�Զ�����,2Ϊҹ��ģʽ,3Ϊ��ͨ�ƶ���ͨ,
//                 4Ϊ��ͨ���ϱ�ͨ,5Ϊ���С�
unsigned int TESTCOMMAND =0	;
//#define TESTCOMMAND   1       //��ͨ�Ʋ�������ѡ��

unsigned int TestCommand =0;//�޲���

#define TRAFFICAUTO	    0xAA14//�Զ�����ģʽ
#define TRAFFICNIGHT	0xAA16//ҹ��ģʽ
#define	TRAFFICEAST	    0xAA1A//����ͨ��	
#define TRAFFICSOUTH	0xAA1B//�ϱ�ͨ��
#define TRAFFICFORBID	0xAA1C//����

#define  EASTEWEST     0x88c	//��ͨ�ƶ���ͨ���ϱ����У�
#define  SOUTHNORTH    0x311	//��ͨ���ϱ�ͨ���������У�  
#define  IOCHANGE      0x462	//��ͨ�Ƹ�����Ƶ���
#define  ALLFORBIN     0x914	//��ͨ�Ƹ����������
void delay(int period);


volatile unsigned char* DEL = (volatile unsigned char *)0x600000;//��ͨ�ƣ��Դ˵�ַ��������Դ�Ż�
volatile unsigned char* DECCTL = (volatile unsigned char *)0x280001;//���ƼĴ���
main()
{
    /*��ʼ��CSL��*/	
    CSL_init();
    
    /*����ϵͳ�������ٶ�Ϊ300MHz*/
    PLL_setFreq(1, 0xF, 0, 1, 3, 3, 0);
    
   	/*��ʼ��DSP�ⲿEMIF*/
    Emif_Config(); 
    *DECCTL=0x40;//�����ֵ����
    
   /* #if TESTCOMMAND==1
		TestCommand =TRAFFICAUTO;//�Զ�����
	#endif
	#if TESTCOMMAND==2
		TestCommand =TRAFFICNIGHT;//ҹ��ģʽ
	#endif
	#if TESTCOMMAND==3
		TestCommand =TRAFFICEAST;//��ͨ�ƶ���ͨ
	#endif
	#if TESTCOMMAND==4
		TestCommand =TRAFFICSOUTH;//��ͨ���ϱ�ͨ
	#endif
	#if TESTCOMMAND==5
		TestCommand =TRAFFICFORBID;//����
	#endif	   */
	for(;;)
	{	
		switch(TESTCOMMAND)
		{	
			/*�Զ�����ģʽ*/
			case 1:
				/*����ģʽ*/
				
				/*�Ӷ������ϱ�*/
				*DEL=EASTEWEST;
				delay(2000);
				*DEL=IOCHANGE;
				delay(1000);
				*DEL=SOUTHNORTH;
				delay(8000);
				
				/*���ϱ�������*/
				*DEL=SOUTHNORTH;
				delay(2000);
				*DEL=IOCHANGE;
				delay(1000);
				*DEL=EASTEWEST;
				delay(8000);
				break;			
			
			/*ҹ��ģʽ*/	
			case 2:
				*DEL=IOCHANGE;
     			delay(6000);
				*DEL=0;
				delay(6000);
				break;
			
			/*��ͨ�ƶ���ͨ*/
			case 3:
                *DEL=IOCHANGE;
				delay(1000);
				*DEL=EASTEWEST;		
			    delay(2000);
			  
				break;

			/*��ͨ���ϱ�ͨ*/	
			case 4:
                *DEL=IOCHANGE;
				delay(1000);
				*DEL=SOUTHNORTH;
				delay(2000);
			
				break;

			/*����*/	
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
