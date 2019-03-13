/**
  ******************************************************************************
  * @file    fm33a0xx_pmu.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    27-12-2017
  * @brief   
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_pmu.h" 

/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup PMU 
  * @brief PMU driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup PMU_Private_Functions
  * @{
  */


//Code_Start
//2018-04-02-13-22-03
//FM33A0XX_Driver_Gen_V1.4

/* �ر�XTLF ��غ��� */
void PMU_LPMCFG_XTOFF_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->LPMCFG;
	tmpreg &= ~(PMU_LPMCFG_XTOFF_Msk);
	tmpreg |= (SetValue & PMU_LPMCFG_XTOFF_Msk);
	PMU->LPMCFG = tmpreg;
}

uint32_t PMU_LPMCFG_XTOFF_Get(void)
{
	return (PMU->LPMCFG & PMU_LPMCFG_XTOFF_Msk);
}

/* LDO15ʹ��״̬��ֻ�� ��غ��� */
FlagStatus PMU_LPMCFG_LDO15EN_Chk(void)
{
	if (PMU->LPMCFG & PMU_LPMCFG_LDO15EN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* DeepSleepģʽ��RAM���ݱ�������λ ��غ��� */
void PMU_LPMCFG_DSLPRAM_EXT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->LPMCFG;
	tmpreg &= ~(PMU_LPMCFG_DSLPRAM_EXT_Msk);
	tmpreg |= (SetValue & PMU_LPMCFG_DSLPRAM_EXT_Msk);
	PMU->LPMCFG = tmpreg;
}

uint32_t PMU_LPMCFG_DSLPRAM_EXT_Get(void)
{
	return (PMU->LPMCFG & PMU_LPMCFG_DSLPRAM_EXT_Msk);
}

/* DeepSleep���Ƽ� ��غ��� */
void PMU_LPMCFG_SLPDP_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->LPMCFG;
	tmpreg &= ~(PMU_LPMCFG_SLPDP_Msk);
	tmpreg |= (SetValue & PMU_LPMCFG_SLPDP_Msk);
	PMU->LPMCFG = tmpreg;
}

uint32_t PMU_LPMCFG_SLPDP_Get(void)
{
	return (PMU->LPMCFG & PMU_LPMCFG_SLPDP_Msk);
}

/* �͹���ģʽ�ں˵�ѹ���� ��غ��� */
void PMU_LPMCFG_CVS_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->LPMCFG |= (PMU_LPMCFG_CVS_Msk);
	}
	else
	{
		PMU->LPMCFG &= ~(PMU_LPMCFG_CVS_Msk);
	}
}

FunState PMU_LPMCFG_CVS_Getable(void)
{
	if (PMU->LPMCFG & (PMU_LPMCFG_CVS_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �͹���ģʽ���üĴ��� ��غ��� */
void PMU_LPMCFG_PMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->LPMCFG;
	tmpreg &= ~(PMU_LPMCFG_PMOD_Msk);
	tmpreg |= (SetValue & PMU_LPMCFG_PMOD_Msk);
	PMU->LPMCFG = tmpreg;
}

uint32_t PMU_LPMCFG_PMOD_Get(void)
{
	return (PMU->LPMCFG & PMU_LPMCFG_PMOD_Msk);
}

/* ����ʱ����ƼĴ��� ��غ��� */
void PMU_WKDLYCON_TRHR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = PMU->WKDLYCON;
	tmpreg &= ~(PMU_WKDLYCON_TRHR_Msk);
	tmpreg |= (SetValue & PMU_WKDLYCON_TRHR_Msk);
	PMU->WKDLYCON = tmpreg;
}

uint32_t PMU_WKDLYCON_TRHR_Get(void)
{
	return (PMU->WKDLYCON & PMU_WKDLYCON_TRHR_Msk);
}

/* CPU Debugger���ѱ�־ ��غ��� */
void PMU_WKPFLAG_DBGWKF_Clr(void)
{
	PMU->WKPFLAG = PMU_WKPFLAG_DBGWKF_Msk;
}

FlagStatus PMU_WKPFLAG_DBGWKF_Chk(void)
{
	if (PMU->WKPFLAG & PMU_WKPFLAG_DBGWKF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SLEEP�����ж�ʹ�� ��غ��� */
void PMU_LPREIE_SLPEIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->LPREIE |= (PMU_LPREIE_SLPEIE_Msk);
	}
	else
	{
		PMU->LPREIE &= ~(PMU_LPREIE_SLPEIE_Msk);
	}
}

FunState PMU_LPREIE_SLPEIE_Getable(void)
{
	if (PMU->LPREIE & (PMU_LPREIE_SLPEIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LPRUN�����ж�ʹ�� ��غ��� */
void PMU_LPREIE_LPREIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		PMU->LPREIE |= (PMU_LPREIE_LPREIE_Msk);
	}
	else
	{
		PMU->LPREIE &= ~(PMU_LPREIE_LPREIE_Msk);
	}
}

FunState PMU_LPREIE_LPREIE_Getable(void)
{
	if (PMU->LPREIE & (PMU_LPREIE_LPREIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SLEEP�����жϱ�־��Ӳ����λ�����д1����,��PMOD=2��h2��CPUִ��WFI/WFEָ��ǰ��λ��SLEEPDEEP�Ĵ���ʱ��λ ��غ��� */
void PMU_LPREIF_SLPEIF_Clr(void)
{
	PMU->LPREIF = PMU_LPREIF_SLPEIF_Msk;
}

FlagStatus PMU_LPREIF_SLPEIF_Chk(void)
{
	if (PMU->LPREIF & PMU_LPREIF_SLPEIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* LPRUN�����жϱ�־��Ӳ����λ�����д1���㣻�������LPRUNģʽʱ���������LPREIF����оƬ�Խ�ͣ����ACTIVEģʽ,LPRUN Condition Error��������LPRUNʱ�������������
1�� HSCLKѡ����LSCLK��RCLP����
2�� RCHF��PLL��ADCʹ��δ�ر�
 ��غ��� */
void PMU_LPREIF_LPREIF_Clr(void)
{
	PMU->LPREIF = PMU_LPREIF_LPREIF_Msk;
}

FlagStatus PMU_LPREIF_LPREIF_Chk(void)
{
	if (PMU->LPREIF & PMU_LPREIF_LPREIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void PMU_Deinit(void)
{
	PMU->LPMCFG = 0x00060000;
	PMU->WKDLYCON = 0x00000001;
	//PMU->WKPFLAG = 0x00000000;
	PMU->LPREIE = 0x00000000;
	//PMU->LPREIF = 0x00000000;
}
//Code_End		

///* WKUP����ʹ��PIN�궨�� */
//��GPIO.h��
//#define		PINWKEN_PD6		BIT7
//#define		PINWKEN_PE9		BIT6
//#define		PINWKEN_PE2		BIT5
//#define		PINWKEN_PA13	BIT4
//#define		PINWKEN_PG7		BIT3
//#define		PINWKEN_PC13	BIT2
//#define		PINWKEN_PB0		BIT1
//#define		PINWKEN_PF5		BIT0
/* CPU WKPxF���ѱ�־ ��غ��� */
void PMU_WKPFLAG_WKPxF_ClrEx(uint32_t NWKPinDef)
{
	PMU->WKPFLAG = NWKPinDef;
}

FlagStatus PMU_WKPFLAG_WKPxF_ChkEx(uint32_t NWKPinDef)
{
	if (PMU->WKPFLAG & NWKPinDef)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void PMU_SleepCfg_Init(PMU_SleepCfg_InitTypeDef* SleepCfg_InitStruct)
{
	PMU_LPMCFG_SLPDP_Set(SleepCfg_InitStruct->SLPDP);				/*!<DeepSleep���ƼĴ���  */
	PMU_LPMCFG_DSLPRAM_EXT_Set(SleepCfg_InitStruct->DSLPRAM_EXT);	/*!<DeepSleepģʽ��RAM���ݱ�������  */	
	PMU_LPMCFG_CVS_Setable(SleepCfg_InitStruct->CVS);				/*!<�ں˵�ѹ����ʹ�ܿ���  */	
	PMU_LPMCFG_XTOFF_Set(SleepCfg_InitStruct->XTOFF);				/*!<�ر�XTLF������SLEEP/DEEPSLEEP��������  */
	SCB->SCR = SleepCfg_InitStruct->SCR;							/*!<M0ϵͳ���ƼĴ�����һ������Ϊ0����  */
	PMU_LPMCFG_PMOD_Set(SleepCfg_InitStruct->PMOD);					/*!<�͹���ģʽ����  */	
}
