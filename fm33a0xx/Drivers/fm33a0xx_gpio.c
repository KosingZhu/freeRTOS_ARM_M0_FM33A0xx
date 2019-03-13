/**
  ******************************************************************************
  * @file    FM33a0xx_gpio.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_gpio.h" 
#include "fm33a0xx_conf.h"	
/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup GPIO 
  * @brief GPIO driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-21-16
//FM33A0XX_Driver_Gen_V1.4

/* PortX������ݼĴ��� ��غ��� */
void GPIOx_DO_Write(GPIOx_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DO = (SetValue & GPIOx_DO_DO_Msk);
}

uint32_t GPIOx_DO_Read(GPIOx_Type* GPIOx)
{
	return (GPIOx->DO & GPIOx_DO_DO_Msk);
}

/* PortX���������λ�Ĵ��� ��غ��� */
void GPIOx_DSET_Write(GPIOx_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DSET = (SetValue & GPIOx_DSET_DSET_Msk);
}

/* PortX������ݸ�λ�Ĵ��� ��غ��� */
void GPIOx_DRESET_Write(GPIOx_Type* GPIOx, uint32_t SetValue)
{
	GPIOx->DRESET = (SetValue & GPIOx_DRESET_DRESET_Msk);
}

/* PortX�������ݼĴ��� ��غ��� */
uint32_t GPIOx_DIN_Read(GPIOx_Type* GPIOx)
{
	return (GPIOx->DIN & GPIOx_DIN_DIN_Msk);
}

/* FOUT���Ƶ��ѡ���ź� ��غ��� */
void GPIO_FOUTSEL_FOUTSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->FOUTSEL;
	tmpreg &= ~(GPIO_FOUTSEL_FOUTSEL_Msk);
	tmpreg |= (SetValue & GPIO_FOUTSEL_FOUTSEL_Msk);
	GPIO->FOUTSEL = tmpreg;
}

uint32_t GPIO_FOUTSEL_FOUTSEL_Get(void)
{
	return (GPIO->FOUTSEL & GPIO_FOUTSEL_FOUTSEL_Msk);
}

/* PG6ǿ����ʹ�� ��غ��� */
void GPIO_HDSEL_PG6HDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO->HDSEL |= (GPIO_HDSEL_PG6HDEN_Msk);
	}
	else
	{
		GPIO->HDSEL &= ~(GPIO_HDSEL_PG6HDEN_Msk);
	}
}

FunState GPIO_HDSEL_PG6HDEN_Getable(void)
{
	if (GPIO->HDSEL & (GPIO_HDSEL_PG6HDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PE2ǿ����ʹ�� ��غ��� */
void GPIO_HDSEL_PE2HDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO->HDSEL |= (GPIO_HDSEL_PE2HDEN_Msk);
	}
	else
	{
		GPIO->HDSEL &= ~(GPIO_HDSEL_PE2HDEN_Msk);
	}
}

FunState GPIO_HDSEL_PE2HDEN_Getable(void)
{
	if (GPIO->HDSEL & (GPIO_HDSEL_PE2HDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PE4ģ�⹦��ѡ�� ��غ��� */
void GPIO_ANASEL_PE4ANS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->ANASEL;
	tmpreg &= ~(GPIO_ANASEL_PE4ANS_Msk);
	tmpreg |= (SetValue & GPIO_ANASEL_PE4ANS_Msk);
	GPIO->ANASEL = tmpreg;
}

uint32_t GPIO_ANASEL_PE4ANS_Get(void)
{
	return (GPIO->ANASEL & GPIO_ANASEL_PE4ANS_Msk);
}

/* PE3ģ�⹦��ѡ�� ��غ��� */
void GPIO_ANASEL_PE3ANS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->ANASEL;
	tmpreg &= ~(GPIO_ANASEL_PE3ANS_Msk);
	tmpreg |= (SetValue & GPIO_ANASEL_PE3ANS_Msk);
	GPIO->ANASEL = tmpreg;
}

uint32_t GPIO_ANASEL_PE3ANS_Get(void)
{
	return (GPIO->ANASEL & GPIO_ANASEL_PE3ANS_Msk);
}

/* PC15ģ�⹦��ѡ�� ��غ��� */
void GPIO_ANASEL_PC15ANS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->ANASEL;
	tmpreg &= ~(GPIO_ANASEL_PC15ANS_Msk);
	tmpreg |= (SetValue & GPIO_ANASEL_PC15ANS_Msk);
	GPIO->ANASEL = tmpreg;
}

uint32_t GPIO_ANASEL_PC15ANS_Get(void)
{
	return (GPIO->ANASEL & GPIO_ANASEL_PC15ANS_Msk);
}

/* PC14ģ�⹦��ѡ�� ��غ��� */
void GPIO_ANASEL_PC14ANS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->ANASEL;
	tmpreg &= ~(GPIO_ANASEL_PC14ANS_Msk);
	tmpreg |= (SetValue & GPIO_ANASEL_PC14ANS_Msk);
	GPIO->ANASEL = tmpreg;
}

uint32_t GPIO_ANASEL_PC14ANS_Get(void)
{
	return (GPIO->ANASEL & GPIO_ANASEL_PC14ANS_Msk);
}

/* PC13ģ�⹦��ѡ�� ��غ��� */
void GPIO_ANASEL_PC13ANS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->ANASEL;
	tmpreg &= ~(GPIO_ANASEL_PC13ANS_Msk);
	tmpreg |= (SetValue & GPIO_ANASEL_PC13ANS_Msk);
	GPIO->ANASEL = tmpreg;
}

uint32_t GPIO_ANASEL_PC13ANS_Get(void)
{
	return (GPIO->ANASEL & GPIO_ANASEL_PC13ANS_Msk);
}

/* PC12ģ�⹦��ѡ�� ��غ��� */
void GPIO_ANASEL_PC12ANS_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = GPIO->ANASEL;
	tmpreg &= ~(GPIO_ANASEL_PC12ANS_Msk);
	tmpreg |= (SetValue & GPIO_ANASEL_PC12ANS_Msk);
	GPIO->ANASEL = tmpreg;
}

uint32_t GPIO_ANASEL_PC12ANS_Get(void)
{
	return (GPIO->ANASEL & GPIO_ANASEL_PC12ANS_Msk);
}


void GPIOx_Deinit(GPIOx_Type* GPIOx)
{
	GPIOx->INEN = 0x00000000;
	GPIOx->PUEN = 0x00000000;
	GPIOx->ODEN = 0x00000000;
	GPIOx->FCR = 0x00000000;
	GPIOx->DO = 0x00000000;
	//GPIOx->DSET = ;
	//GPIOx->DRESET = ;
	//GPIOx->DIN = ;
}

void GPIO_Deinit(void)
{
	GPIO->EXTI0_SEL = 0xFFFF0000;
	GPIO->EXTI1_SEL = 0xFFFF0000;
	GPIO->EXTI2_SEL = 0xFFFF0000;
	//GPIO->EXTI0IF = ;
	//GPIO->EXTI1IF = ;
	//GPIO->EXTI2IF = ;
	GPIO->FOUTSEL = 0x00000000;
	GPIO->HDSEL = 0x00000000;
	GPIO->ANASEL = 0x00000000;
	GPIO->IODF = 0x00000000;
	GPIO->PINWKEN = 0x00000000;
}
//Code_End


void GPIO_ALL_Deinit(void)
{
	GPIO_Deinit();
	GPIOx_Deinit(GPIOA);
	GPIOx_Deinit(GPIOB);
	GPIOx_Deinit(GPIOC);
	GPIOx_Deinit(GPIOD);
	GPIOx_Deinit(GPIOE);
	GPIOx_Deinit(GPIOF);
	GPIOx_Deinit(GPIOG);
}

/* GPIO ��ʼ������ */
void GPIO_Init(GPIOx_Type* GPIOx, GPIO_InitTypeDef* para)
{
    uint32_t pinpos = 0x00,pinbit = 0x00,currentpin =0x00;
	uint32_t tmpreg; 

    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
    for (pinpos = 0; pinpos < 16; pinpos++)
    {
        pinbit = ((uint32_t)0x01) <<pinpos;
        currentpin = (para->Pin) & pinbit;
			
        if (currentpin == pinbit)
        {
			tmpreg = GPIOx->INEN;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxINEN)<<pinpos;	
			GPIOx->INEN = tmpreg;
			
			tmpreg = GPIOx->PUEN;
			tmpreg &= ~pinbit;
            tmpreg |= (para->PxPUEN)<<pinpos;
			GPIOx->PUEN = tmpreg;
			
			tmpreg = GPIOx->ODEN;
			tmpreg &= ~pinbit;
            tmpreg |= (para->PxODEN)<<pinpos;
			GPIOx->ODEN = tmpreg;

			pinbit = (((uint32_t)0x00000003)) <<(pinpos*2);
			tmpreg = GPIOx->FCR;
            tmpreg &= ~pinbit;
            tmpreg |= (para->PxFCR)<<(pinpos*2);
			GPIOx->FCR = tmpreg;
        }
    }
}

/* ��ȡһ��IO�ڵ����ò����ṹ�� 
	ע��һ��ֻ�ܶ�ȡһ��IO������
*/

void GPIO_Get_InitPara(GPIOx_Type* GPIOx, uint32_t GPIO_Pin, GPIO_InitTypeDef* para)
{
    uint32_t pinbit = 0x00;
    uint32_t i,temp;

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));	
	
	for (i = 0; i < 16; i++)
	{
		pinbit = GPIO_Pin & (1<<i);
		if(pinbit > 0) break;
	}
	
	if(i < 16)
	{
		pinbit = i;
		para->Pin = GPIO_Pin;
		
		temp = (GPIOx->INEN&GPIO_Pin)>>pinbit;
		if(temp == (uint32_t)GPIO_IN_En)
		{                                         
			para->PxINEN = GPIO_IN_En;
		}
		else
		{
			para->PxINEN = GPIO_IN_Dis;
		}   
		
		temp = (GPIOx->PUEN&GPIO_Pin)>>pinbit;                                    
		if(temp == (uint32_t)GPIO_PU_En)
		{                                         
			para->PxPUEN = GPIO_PU_En;
		}
		else
		{
			para->PxPUEN = GPIO_PU_Dis;
		}   
		
		temp = (GPIOx->ODEN&GPIO_Pin)>>pinbit;                                   
		if(temp == (uint32_t)GPIO_OD_En)
		{                                         
			para->PxODEN = GPIO_OD_En;
		}
		else
		{
			para->PxODEN = GPIO_OD_Dis;
		}  
		
		temp = (GPIOx->FCR>>(pinbit*2))&0x00000003;                                    
		if(temp == (uint32_t)GPIO_FCR_IN)
		{                                         
			para->PxFCR = GPIO_FCR_IN;
		}
		else if(temp == (uint32_t)GPIO_FCR_OUT)
		{
			para->PxFCR = GPIO_FCR_OUT;
		}
		else if(temp == (uint32_t)GPIO_FCR_DIG)
		{                                         
			para->PxFCR = GPIO_FCR_DIG;
		}
		else
		{
			para->PxFCR = GPIO_FCR_ANA;
		}
	}  
}

/* ��ȡGPIOx�������ݼĴ��� */
uint32_t GPIO_ReadInputData(GPIOx_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
//	return(GPIOx_DIN_Read(GPIOx));
	return (GPIOx->DIN);
}

/* ��ȡGPIOx�������ݼĴ���bit */
uint8_t GPIO_ReadInputDataBit(GPIOx_Type* GPIOx, uint32_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;

	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	assert_param(IS_GET_GPIO_PIN(GPIO_Pin));

    if ((GPIOx->DIN & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/* GPIOx���������1 */
void GPIO_SetBits(GPIOx_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));

//	GPIOx_DSET_Write(GPIOx, Pin);
    GPIOx->DSET = GPIO_Pin;
}

/* GPIOx���������0 */
void GPIO_ResetBits(GPIOx_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
//	GPIOx_DRESET_Write(GPIOx, Pin);
    GPIOx->DRESET = GPIO_Pin;
}

/* GPIOx��������÷�ת */
void GPIO_ToggleBits(GPIOx_Type* GPIOx, uint32_t GPIO_Pin)
{
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GPIO_PIN(GPIO_Pin));
	
	if(GPIO_Pin&GPIOx->DO)
	{
		//GPIO_ResetBits(GPIOx, GPIO_Pin);
		GPIOx->DRESET = GPIO_Pin;	
	}
	else
	{
		//GPIO_SetBits(GPIOx, GPIO_Pin);	
		GPIOx->DSET = GPIO_Pin;
	}
}

/* ��ȡGPIOx������ݼĴ��� */
uint32_t GPIO_ReadOutputData(GPIOx_Type* GPIOx)
{
	assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
	
//	return(GPIOx_DO_Read(GPIOx));
	return (GPIOx->DO);
}

/* ��ȡGPIOx������ݼĴ���bit */
uint8_t GPIO_ReadOutputDataBit(GPIOx_Type* GPIOx, uint32_t GPIO_Pin)
{
    uint8_t bitstatus = 0x00;
	
    assert_param(IS_GPIO_ALL_PERIPH(GPIOx));
    assert_param(IS_GET_GPIO_PIN(GPIO_Pin));
	
    if (((GPIOx->DO) & GPIO_Pin) != (uint32_t)Bit_RESET)
    {
        bitstatus = (uint8_t)Bit_SET;
    }
    else
    {
        bitstatus = (uint8_t)Bit_RESET;
    }
    return bitstatus;
}

/* GPIO���������˲����� */
void GPIO_IODF_SetableEx(uint32_t DFPinDef, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO->IODF |= ((uint32_t)0x01) << DFPinDef;
	}
	else
	{
		GPIO->IODF &= ~(((uint32_t)0x01) << DFPinDef);
	}
}

/* WKUP����ʹ�� */
void GPIO_PINWKEN_SetableEx(uint32_t NWKPinDef, FunState NewState)
{
	if (NewState == ENABLE)
	{
		GPIO->PINWKEN |= NWKPinDef;
	}
	else
	{
		GPIO->PINWKEN &= ~ NWKPinDef;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Pin
 ����˵����GPIO EXTI �ⲿ����ѡ��
 ���������GPIOx �˿� GPIO_Pinpin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Select_Pin(GPIOx_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;
	
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}
	}

	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
			pin_shift = (pin_num%8)*2;
			tmpreg = GPIO->EXTI0_SEL;
			tmpreg &= (~(0x00000003 << pin_shift));
			if(GPIOx == GPIOA)
			{
				tmpreg |= ((pin_num/8) << pin_shift);
			}
			else
			{
				tmpreg |= (((pin_num/8)+ 2) << pin_shift);
			}
			GPIO->EXTI0_SEL = tmpreg;
			break;

		case (uint32_t)GPIOC:
			pin_shift = (pin_num%8)*2;
			tmpreg = GPIO->EXTI1_SEL;
			tmpreg &= (~(0x00000003 << pin_shift));
			tmpreg |= ((pin_num/8) << pin_shift);
			GPIO->EXTI1_SEL = tmpreg;
			break;

		case (uint32_t)GPIOD://0~10
			if(pin_num <= 10)
			{
				pin_shift = (pin_num%8)*2;
				tmpreg = GPIO->EXTI1_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (((pin_num/8)+ 2) << pin_shift);
				GPIO->EXTI1_SEL = tmpreg;
			}
			break;

		case (uint32_t)GPIOE://2~9(-2)
			if((pin_num >= 2)&&(pin_num <= 5))//1bit
			{
				pin_shift = pin_num - 2;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000001 << pin_shift));
				GPIO->EXTI2_SEL = tmpreg;
			}
			else if((pin_num >= 6)&&(pin_num <= 9))//2bit
			{
				pin_shift = 4 + (pin_num - 6)*2;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				GPIO->EXTI2_SEL = tmpreg;
			}
			break;

		case (uint32_t)GPIOF://1~7   8~11(-4)
			if((pin_num >= 1)&&(pin_num <= 3))//1bit
			{
				pin_shift = pin_num;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000001 << pin_shift));
				tmpreg |= (0x00000001 << pin_shift);
				GPIO->EXTI2_SEL = tmpreg;
			}
			else if((pin_num >= 4)&&(pin_num <= 7))//2bit-a
			{
				pin_shift = 4 + (pin_num - 4)*2;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (0x00000001 << pin_shift);
				GPIO->EXTI2_SEL = tmpreg;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))//2bit-b
			{
				pin_shift = 4 + (pin_num - 8)*2;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (0x00000002 << pin_shift);
				GPIO->EXTI2_SEL = tmpreg;
			}
			break;

		case (uint32_t)GPIOG://2(+1) 5~8(-1)
			if(pin_num == 2)
			{
				pin_shift = 6;
				tmpreg = GPIO->EXTI1_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (0x00000003 << pin_shift);
				GPIO->EXTI1_SEL = tmpreg;
			}
			else if((pin_num >= 5)&&(pin_num <= 8))
			{
				pin_shift = (pin_num - 1)*2;
				tmpreg = GPIO->EXTI1_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= (0x00000003 << pin_shift);
				GPIO->EXTI1_SEL = tmpreg;
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Select_Edge
 ����˵����GPIO EXTI_Select_Edge �ⲿ�жϱ���ѡ��
 ���������GPIOx �˿� ��GPIO_Pin �˿������� ,edge_select ������
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Select_Edge(GPIOx_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select)
{
	uint32_t pin_num = 0,i;	
	uint32_t pin_shift;
	uint32_t tmpreg;

	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}	
	
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
			pin_shift = (pin_num%8)*2 + 16;
			tmpreg = GPIO->EXTI0_SEL;
			tmpreg &= (~(0x00000003 << pin_shift));			  
			tmpreg |= edge_select << pin_shift;
			GPIO->EXTI0_SEL = tmpreg;
			break;

		case (uint32_t)GPIOC:
			pin_shift = (pin_num%8)*2 + 16;
			tmpreg = GPIO->EXTI1_SEL;
			tmpreg &= (~(0x00000003 << pin_shift));			  
			tmpreg |= edge_select << pin_shift;
			GPIO->EXTI1_SEL = tmpreg;
			break;

		case (uint32_t)GPIOD://0~10
			if(pin_num <= 10)
			{
				pin_shift = (pin_num%8)*2 + 16;
				tmpreg = GPIO->EXTI1_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));			  
				tmpreg |= edge_select << pin_shift;
				GPIO->EXTI1_SEL = tmpreg;
			}
			break;

		case (uint32_t)GPIOE://2~9(-2)
			if((pin_num >= 2)&&(pin_num <= 9))
			{
				pin_shift = (pin_num - 2)*2 + 16;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= edge_select << pin_shift;
				GPIO->EXTI2_SEL = tmpreg;
			}
			break;

		case (uint32_t)GPIOF://1~7   8~11(-4)
			if((pin_num >= 1)&&(pin_num <= 7))
			{
				pin_shift = pin_num*2 + 16;
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= edge_select << pin_shift;
				GPIO->EXTI2_SEL = tmpreg;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				pin_shift = ((pin_num - 8)+4)*2 + 16;	
				tmpreg = GPIO->EXTI2_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= edge_select << pin_shift;
				GPIO->EXTI2_SEL = tmpreg;
			}
			break;

		case (uint32_t)GPIOG://2(+1) 5~8(-1)
			if(pin_num == 2)
			{
				pin_shift = (pin_num + 1)*2 + 16;
				tmpreg = GPIO->EXTI1_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));			  
				tmpreg |= edge_select << pin_shift;
				GPIO->EXTI1_SEL = tmpreg;
			}
			else if((pin_num >= 5)&&(pin_num <= 8))
			{
				pin_shift = (pin_num - 1)*2 + 16;
				tmpreg = GPIO->EXTI1_SEL;
				tmpreg &= (~(0x00000003 << pin_shift));
				tmpreg |= edge_select << pin_shift;
				GPIO->EXTI1_SEL = tmpreg;
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_EXTIxIF_ClrEx
 ����˵����GPIO_EXTI_EXTIxIF_ClrEx ����жϱ�־
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_EXTIxIF_ClrEx(GPIOx_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}

	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
			GPIO->EXTI0IF = (0x00000001 << (pin_num&0x07));
			break;

		case (uint32_t)GPIOC:
			GPIO->EXTI1IF = (0x00000001 << (pin_num&0x07));
			break;

		case (uint32_t)GPIOD://0~10
			if(pin_num <= 10)
			{
				GPIO->EXTI1IF = (0x00000001 << (pin_num&0x07));
			}
			break;

		case (uint32_t)GPIOE://2~9(-2)
			if((pin_num >= 2)&&(pin_num <= 9))
			{
				GPIO->EXTI2IF = (0x00000001 << (pin_num - 2));
			}
			break;

		case (uint32_t)GPIOF://1~7   8~11(-4)
			if((pin_num >= 1)&&(pin_num <= 7))
			{
				GPIO->EXTI2IF = (0x00000001 << (pin_num&0x07));
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				GPIO->EXTI2IF = (0x00000001 << (pin_num - 4));
			}
			break;

		case (uint32_t)GPIOG://2(+1) 5~8(-1)
			if(pin_num == 2)
			{
				GPIO->EXTI1IF = (0x00000001 << (pin_num + 1));
			}
			else if((pin_num >= 5)&&(pin_num <= 8))
			{
				GPIO->EXTI1IF = (0x00000001 << (pin_num - 1));
			}
			break;
		
		default:
			break;
	}
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_EXTIxIF_ChkEx
 ����˵����GPIO_EXTI_EXTIxIF_ChkEx ��ȡ�жϱ�־״̬
 ���������GPIOx �˿� ��GPIO_Pin �˿������� 
 �����������
 ���ز����wFlagStatus �жϱ�־״̬
 *************************************************************************/
FlagStatus GPIO_EXTI_EXTIxIF_ChkEx(GPIOx_Type* GPIOx,uint32_t GPIO_Pin)
{
	uint32_t pin_num = 0,i;	
	FlagStatus Result = RESET;
	
	for(i= 0;i<16;i++)
	{
		if(GPIO_Pin&(1<<i))
		{
			pin_num = i;
			break;
		}							
	}

	Result = RESET;
	switch((uint32_t)GPIOx)
	{
		case (uint32_t)GPIOA:
		case (uint32_t)GPIOB:
			if(GPIO->EXTI0IF & (0x00000001 << (pin_num&0x07))) Result = SET;
			break;

		case (uint32_t)GPIOC:
			if(GPIO->EXTI1IF & (0x00000001 << (pin_num&0x07))) Result = SET;
			break;

		case (uint32_t)GPIOD://0~10
			if(pin_num <= 10)
			{
				if(GPIO->EXTI1IF & (0x00000001 << (pin_num&0x07))) Result = SET;
			}
			break;

		case (uint32_t)GPIOE://2~9(-2)
			if((pin_num >= 2)&&(pin_num <= 9))
			{
				if(GPIO->EXTI2IF & (0x00000001 << (pin_num - 2))) Result = SET;
			}
			break;

		case (uint32_t)GPIOF://1~7   8~11(-4)
			if((pin_num >= 1)&&(pin_num <= 7))
			{
				if(GPIO->EXTI2IF & (0x00000001 << (pin_num&0x07))) Result = SET;
			}
			else if((pin_num >= 8)&&(pin_num <= 11))
			{
				if(GPIO->EXTI2IF & (0x00000001 << (pin_num - 4))) Result = SET;
			}
			break;

		case (uint32_t)GPIOG://2(+1) 5~8(-1)
			if(pin_num == 2)
			{
				if(GPIO->EXTI1IF & (0x00000001 << (pin_num + 1))) Result = SET;
			}
			else if((pin_num >= 5)&&(pin_num <= 8))
			{
				if(GPIO->EXTI1IF & (0x00000001 << (pin_num - 1))) Result = SET;
			}
			break;
		
		default:
			break;
	}
	
	return Result;
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Init
 ����˵����GPIO_EXTI_Init �ⲿ�жϳ�ʼ��
 ���������port �˿� ��pin �˿������� ,edge ������
 �����������
 ���ز����w��
 *************************************************************************/
//FM33A0XX��7��GPIO��A~G�������Բ���24���ⲿ�����жϣ�����IO����ͬʱ�����жϹ���
void GPIO_EXTI_Init(GPIOx_Type* GPIOx,uint32_t GPIO_Pin,GPIOExtiEdge edge_select)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTI_DISABLE);	//�رձ��ش���
	GPIO_EXTI_Select_Pin(GPIOx, GPIO_Pin);					//�ⲿ����ѡ��
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, edge_select);	//�޸ı���ѡ��
	GPIO_EXTI_EXTIxIF_ClrEx(GPIOx, GPIO_Pin);				//����жϱ�־
}

/*************************************************************************
 �������ƣ�GPIO_EXTI_Close
 ����˵����GPIO_EXTI_Close �ⲿ�жϹر�
 ���������port �˿� ��pin �˿������� 
 �����������
 ���ز����w��
 *************************************************************************/
void GPIO_EXTI_Close(GPIOx_Type* GPIOx,uint32_t GPIO_Pin)
{
	GPIO_EXTI_Select_Edge(GPIOx, GPIO_Pin, EXTI_DISABLE);//�رձ��ش���
}

/******END OF FILE****/




