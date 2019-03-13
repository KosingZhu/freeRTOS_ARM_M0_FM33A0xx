/**
  ******************************************************************************
  * @file    fm33a0xx_btim.c
  * @author  FM33a0 Application Team
  * @version V2.0.1
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_btim.h"  


/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup BTIM 
  * @brief BTIM driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup BTIM_Private_Functions
  * @{
  */ 

//Code_Start
//2018-04-02-13-20-21
//FM33A0XX_Driver_Gen_V1.4

/* ��λ�������������� ��غ��� */
void BTIMx_BTCR1_CHEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR1 |= (BTIMx_BTCR1_CHEN_Msk);
	}
	else
	{
		BTIMx->BTCR1 &= ~(BTIMx_BTCR1_CHEN_Msk);
	}
}

FunState BTIMx_BTCR1_CHEN_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR1 & (BTIMx_BTCR1_CHEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��λ�������������� ��غ��� */
void BTIMx_BTCR1_CLEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR1 |= (BTIMx_BTCR1_CLEN_Msk);
	}
	else
	{
		BTIMx->BTCR1 &= ~(BTIMx_BTCR1_CLEN_Msk);
	}
}

FunState BTIMx_BTCR1_CLEN_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR1 & (BTIMx_BTCR1_CLEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ģʽѡ�� ��غ��� */
void BTIMx_BTCR1_MODE_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_MODE_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_MODE_Msk);
	BTIMx->BTCR1 = tmpreg;
}

uint32_t BTIMx_BTCR1_MODE_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_MODE_Msk);
}

/* �����ػ�׽��ѡ�� ��غ��� */
void BTIMx_BTCR1_EDGESEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_EDGESEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_EDGESEL_Msk);
	BTIMx->BTCR1 = tmpreg;
}

uint32_t BTIMx_BTCR1_EDGESEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_EDGESEL_Msk);
}

/* ��׽ģʽ���ƣ�����׽ģʽ����Ч�� ��غ��� */
void BTIMx_BTCR1_CAPMOD_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_CAPMOD_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_CAPMOD_Msk);
	BTIMx->BTCR1 = tmpreg;
}

uint32_t BTIMx_BTCR1_CAPMOD_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_CAPMOD_Msk);
}

/* �����㲶׽ģʽ���� ��غ��� */
void BTIMx_BTCR1_CAPCLR_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_CAPCLR_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_CAPCLR_Msk);
	BTIMx->BTCR1 = tmpreg;
}

uint32_t BTIMx_BTCR1_CAPCLR_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_CAPCLR_Msk);
}

/* ���β�׽���� ��غ��� */
void BTIMx_BTCR1_CAPONCE_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR1;
	tmpreg &= ~(BTIMx_BTCR1_CAPONCE_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR1_CAPONCE_Msk);
	BTIMx->BTCR1 = tmpreg;
}

uint32_t BTIMx_BTCR1_CAPONCE_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR1 & BTIMx_BTCR1_CAPONCE_Msk);
}

/* PWMģʽ��� ��غ��� */
void BTIMx_BTCR1_PWM_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR1 |= (BTIMx_BTCR1_PWM_Msk);
	}
	else
	{
		BTIMx->BTCR1 &= ~(BTIMx_BTCR1_PWM_Msk);
	}
}

FunState BTIMx_BTCR1_PWM_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR1 & (BTIMx_BTCR1_PWM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������ڲ�����Դ�ź�ѡ�� ��غ��� */
void BTIMx_BTCR2_SIG2SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_SIG2SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_SIG2SEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}

uint32_t BTIMx_BTCR2_SIG2SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_SIG2SEL_Msk);
}

/* �������ڲ���׽Դ�ź�ѡ�� ��غ��� */
void BTIMx_BTCR2_SIG1SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_SIG1SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_SIG1SEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}

uint32_t BTIMx_BTCR2_SIG1SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_SIG1SEL_Msk);
}

/* ��λ������Դѡ�� ��غ��� */
void BTIMx_BTCR2_CNTHSEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_CNTHSEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_CNTHSEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}

uint32_t BTIMx_BTCR2_CNTHSEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_CNTHSEL_Msk);
}

/* �ⲿ����DIR����ʹ�� ��غ��� */
void BTIMx_BTCR2_DIREN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR2 |= (BTIMx_BTCR2_DIREN_Msk);
	}
	else
	{
		BTIMx->BTCR2 &= ~(BTIMx_BTCR2_DIREN_Msk);
	}
}

FunState BTIMx_BTCR2_DIREN_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR2 & (BTIMx_BTCR2_DIREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �ڲ�DIR�����ź�ʹ�� ��غ��� */
void BTIMx_BTCR2_STDIR_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTCR2 |= (BTIMx_BTCR2_STDIR_Msk);
	}
	else
	{
		BTIMx->BTCR2 &= ~(BTIMx_BTCR2_STDIR_Msk);
	}
}

FunState BTIMx_BTCR2_STDIR_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTCR2 & (BTIMx_BTCR2_STDIR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��λ������ʹ�ܿ���ѡ���ź� ��غ��� */
void BTIMx_BTCR2_SRCSEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_SRCSEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_SRCSEL_Msk);
	BTIMx->BTCR2 = tmpreg;
}

uint32_t BTIMx_BTCR2_SRCSEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_SRCSEL_Msk);
}

/* �����ź�2����ѡ�� ��غ��� */
void BTIMx_BTCR2_DIRPO_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCR2;
	tmpreg &= ~(BTIMx_BTCR2_DIRPO_Msk);
	tmpreg |= (SetValue & BTIMx_BTCR2_DIRPO_Msk);
	BTIMx->BTCR2 = tmpreg;
}

uint32_t BTIMx_BTCR2_DIRPO_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCR2 & BTIMx_BTCR2_DIRPO_Msk);
}

/* RTCOUT2�źſ���2 ��غ��� */
void BTIMx_BTCFG1_RTCSEL2_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_RTCSEL2_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_RTCSEL2_Msk);
	BTIMx->BTCFG1 = tmpreg;
}

uint32_t BTIMx_BTCFG1_RTCSEL2_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_RTCSEL2_Msk);
}

/* RTCOUT1�źſ���1 ��غ��� */
void BTIMx_BTCFG1_RTCSEL1_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_RTCSEL1_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_RTCSEL1_Msk);
	BTIMx->BTCFG1 = tmpreg;
}

uint32_t BTIMx_BTCFG1_RTCSEL1_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_RTCSEL1_Msk);
}

/* Group2�ź�ѡ����� ��غ��� */
void BTIMx_BTCFG1_GRP2SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_GRP2SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_GRP2SEL_Msk);
	BTIMx->BTCFG1 = tmpreg;
}

uint32_t BTIMx_BTCFG1_GRP2SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_GRP2SEL_Msk);
}

void BTIMx_BTCFG1_GRP1SEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG1;
	tmpreg &= ~(BTIMx_BTCFG1_GRP1SEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG1_GRP1SEL_Msk);
	BTIMx->BTCFG1 = tmpreg;
}

uint32_t BTIMx_BTCFG1_GRP1SEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG1 & BTIMx_BTCFG1_GRP1SEL_Msk);
}

/* �ⲿ�����ź�ѡ�����2 ��غ��� */
void BTIMx_BTCFG2_EXSEL2_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_EXSEL2_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_EXSEL2_Msk);
	BTIMx->BTCFG2 = tmpreg;
}

uint32_t BTIMx_BTCFG2_EXSEL2_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_EXSEL2_Msk);
}

/* �ⲿ�����ź�ѡ�����1 ��غ��� */
void BTIMx_BTCFG2_EXSEL1_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_EXSEL1_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_EXSEL1_Msk);
	BTIMx->BTCFG2 = tmpreg;
}

uint32_t BTIMx_BTCFG2_EXSEL1_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_EXSEL1_Msk);
}

/* �ڲ������ź�ѡ�����2 ��غ��� */
void BTIMx_BTCFG2_INSEL2_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_INSEL2_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_INSEL2_Msk);
	BTIMx->BTCFG2 = tmpreg;
}

uint32_t BTIMx_BTCFG2_INSEL2_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_INSEL2_Msk);
}

void BTIMx_BTCFG2_INSEL1_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTCFG2;
	tmpreg &= ~(BTIMx_BTCFG2_INSEL1_Msk);
	tmpreg |= (SetValue & BTIMx_BTCFG2_INSEL1_Msk);
	BTIMx->BTCFG2 = tmpreg;
}

uint32_t BTIMx_BTCFG2_INSEL1_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCFG2 & BTIMx_BTCFG2_INSEL1_Msk);
}

/* ����Group1��Ԥ��Ƶ�Ĵ��� ��غ��� */
void BTIMx_BTPRES_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTPRES = (SetValue & BTIMx_BTPRES_PRESCALE_Msk);
}

uint32_t BTIMx_BTPRES_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTPRES & BTIMx_BTPRES_PRESCALE_Msk);
}

void BTIMx_BTLOADCR_LHEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTLOADCR |= (BTIMx_BTLOADCR_LHEN_Msk);
	}
	else
	{
		BTIMx->BTLOADCR &= ~(BTIMx_BTLOADCR_LHEN_Msk);
	}
}

void BTIMx_BTLOADCR_LLEN_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTLOADCR |= (BTIMx_BTLOADCR_LLEN_Msk);
	}
	else
	{
		BTIMx->BTLOADCR &= ~(BTIMx_BTLOADCR_LLEN_Msk);
	}
}

/* ��������λ����ֵ�Ĵ��� ��غ��� */
uint32_t BTIMx_BTCNTL_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCNTL & BTIMx_BTCNTL_CNTL_Msk);
}

/* ��������λ����ֵ�Ĵ��� ��غ��� */
uint32_t BTIMx_BTCNTH_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCNTH & BTIMx_BTCNTH_CNTH_Msk);
}

/* ��������λԤ�����Ĵ��� ��غ��� */
void BTIMx_BTPRESET_PRESETH_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTPRESET;
	tmpreg &= ~(BTIMx_BTPRESET_PRESETH_Msk);
	tmpreg |= (SetValue & BTIMx_BTPRESET_PRESETH_Msk);
	BTIMx->BTPRESET = tmpreg;
}

uint32_t BTIMx_BTPRESET_PRESETH_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTPRESET & BTIMx_BTPRESET_PRESETH_Msk);
}

/* ��������λԤ�����Ĵ��� ��غ��� */
void BTIMx_BTPRESET_PRESETL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTPRESET;
	tmpreg &= ~(BTIMx_BTPRESET_PRESETL_Msk);
	tmpreg |= (SetValue & BTIMx_BTPRESET_PRESETL_Msk);
	BTIMx->BTPRESET = tmpreg;
}

uint32_t BTIMx_BTPRESET_PRESETL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTPRESET & BTIMx_BTPRESET_PRESETL_Msk);
}

/* ��������λ���ؼĴ��� ��غ��� */
void BTIMx_BTLOADL_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTLOADL = (SetValue & BTIMx_BTLOADL_LOADL_Msk);
}

uint32_t BTIMx_BTLOADL_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTLOADL & BTIMx_BTLOADL_LOADL_Msk);
}

/* ��������λ���ؼĴ��� ��غ��� */
void BTIMx_BTLOADH_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTLOADH = (SetValue & BTIMx_BTLOADH_LOADH_Msk);
}

uint32_t BTIMx_BTLOADH_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTLOADH & BTIMx_BTLOADH_LOADH_Msk);
}

/* ��������λ�ȽϼĴ��� ��غ��� */
void BTIMx_BTCMPL_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTCMPL = (SetValue & BTIMx_BTCMPL_CMPL_Msk);
}

uint32_t BTIMx_BTCMPL_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCMPL & BTIMx_BTCMPL_CMPL_Msk);
}

/* ��������λ�ȽϼĴ��� ��غ��� */
void BTIMx_BTCMPH_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTCMPH = (SetValue & BTIMx_BTCMPH_CMPH_Msk);
}

uint32_t BTIMx_BTCMPH_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTCMPH & BTIMx_BTCMPH_CMPH_Msk);
}

/* ��������������ȼ����� ��غ��� */
void BTIMx_BTOUTCNT_Write(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	BTIMx->BTOUTCNT = (SetValue & BTIMx_BTOUTCNT_OUTCNT_Msk);
}

uint32_t BTIMx_BTOUTCNT_Read(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOUTCNT & BTIMx_BTOUTCNT_OUTCNT_Msk);
}

/* ������� ��غ��� */
void BTIMx_BTOCR_OUTCLR_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTCLR_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTCLR_Msk);
	BTIMx->BTOCR = tmpreg;
}

uint32_t BTIMx_BTOCR_OUTCLR_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTCLR_Msk);
}

/* �����ƽ����ѡ�� ��غ��� */
void BTIMx_BTOCR_OUTINV_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTINV_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTINV_Msk);
	BTIMx->BTOCR = tmpreg;
}

uint32_t BTIMx_BTOCR_OUTINV_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTINV_Msk);
}

/* ���ģʽѡ�� ��غ��� */
void BTIMx_BTOCR_OUTMOD_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTMOD_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTMOD_Msk);
	BTIMx->BTOCR = tmpreg;
}

uint32_t BTIMx_BTOCR_OUTMOD_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTMOD_Msk);
}

/* ����ź�Դѡ�� ��غ��� */
void BTIMx_BTOCR_OUTSEL_Set(BTIMx_Type* BTIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = BTIMx->BTOCR;
	tmpreg &= ~(BTIMx_BTOCR_OUTSEL_Msk);
	tmpreg |= (SetValue & BTIMx_BTOCR_OUTSEL_Msk);
	BTIMx->BTOCR = tmpreg;
}

uint32_t BTIMx_BTOCR_OUTSEL_Get(BTIMx_Type* BTIMx)
{
	return (BTIMx->BTOCR & BTIMx_BTOCR_OUTSEL_Msk);
}

/* ��ʱ����λ�ȽϷ����ź� ��غ��� */
void BTIMx_BTIE_CMPHIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_CMPHIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_CMPHIE_Msk);
	}
}

FunState BTIMx_BTIE_CMPHIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_CMPHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����λ�ȽϷ����ź� ��غ��� */
void BTIMx_BTIE_CMPLIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_CMPLIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_CMPLIE_Msk);
	}
}

FunState BTIMx_BTIE_CMPLIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_CMPLIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����λ����ź� ��غ��� */
void BTIMx_BTIE_OVHIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_OVHIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_OVHIE_Msk);
	}
}

FunState BTIMx_BTIE_OVHIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_OVHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����λ����ź� ��غ��� */
void BTIMx_BTIE_OVLIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_OVLIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_OVLIE_Msk);
	}
}

FunState BTIMx_BTIE_OVLIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_OVLIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ʱ����׽�����ź� ��غ��� */
void BTIMx_BTIE_CAPIE_Setable(BTIMx_Type* BTIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		BTIMx->BTIE |= (BTIMx_BTIE_CAPIE_Msk);
	}
	else
	{
		BTIMx->BTIE &= ~(BTIMx_BTIE_CAPIE_Msk);
	}
}

FunState BTIMx_BTIE_CAPIE_Getable(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIE & (BTIMx_BTIE_CAPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽��״̬ ��غ��� */
void BTIMx_BTIF_EDGESTA_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_EDGESTA_Msk;
}

FlagStatus BTIMx_BTIF_EDGESTA_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_EDGESTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��λ�ȽϷ����ź� ��غ��� */
void BTIMx_BTIF_CMPHIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_CMPHIF_Msk;
}

FlagStatus BTIMx_BTIF_CMPHIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_CMPHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��λ�ȽϷ����ź� ��غ��� */
void BTIMx_BTIF_CMPLIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_CMPLIF_Msk;
}

FlagStatus BTIMx_BTIF_CMPLIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_CMPLIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����λ����ź� ��غ��� */
void BTIMx_BTIF_OVHIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_OVHIF_Msk;
}

FlagStatus BTIMx_BTIF_OVHIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_OVHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����λ����ź� ��غ��� */
void BTIMx_BTIF_OVLIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_OVLIF_Msk;
}

FlagStatus BTIMx_BTIF_OVLIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_OVLIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��ʱ����׽�����ź� ��غ��� */
void BTIMx_BTIF_CAPIF_Clr(BTIMx_Type* BTIMx)
{
	BTIMx->BTIF = BTIMx_BTIF_CAPIF_Msk;
}

FlagStatus BTIMx_BTIF_CAPIF_Chk(BTIMx_Type* BTIMx)
{
	if (BTIMx->BTIF & BTIMx_BTIF_CAPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void BTIMx_Deinit(BTIMx_Type* BTIMx)
{
	BTIMx->BTCR1 = 0x00000000;
	BTIMx->BTCR2 = 0x00000000;
	BTIMx->BTCFG1 = 0x00000000;
	BTIMx->BTCFG2 = 0x00000000;
	BTIMx->BTPRES = 0x00000000;
	BTIMx->BTLOADCR = 0x00000000;
	//BTIMx->BTCNTL = ;
	//BTIMx->BTCNTH = ;
	BTIMx->BTPRESET = 0x00000000;
	BTIMx->BTLOADL = 0x00000000;
	BTIMx->BTLOADH = 0x00000000;
	//BTIMx->BTCMPL = ;
	//BTIMx->BTCMPH = ;
	BTIMx->BTOUTCNT = 0x00000000;
	BTIMx->BTOCR = 0x00000000;
	BTIMx->BTIE = 0x00000000;
	//BTIMx->BTIF = ;
}
//Code_End



void BTIMx_Init(BTIMx_Type* BTIMx, BTIM_InitTypeDef* para)
{
	BTIMx_Deinit(BTIMx);

	//��׽����ѡ��
	BTIMx_BTCR1_CAPMOD_Set(BTIMx, para->cap_para.CAPMOD);//��׽ģʽ���ƣ������Ȼ���������
	BTIMx_BTCR1_CAPCLR_Set(BTIMx, para->cap_para.CAPCLR);//��׽�Ƿ���Ҫ���������
	BTIMx_BTCR1_CAPONCE_Set(BTIMx, para->cap_para.CAPONCE);//��׽�Ƿ񵥴β�׽

	//�ź�ѡ����
	BTIMx_BTCFG1_RTCSEL1_Set(BTIMx, para->sig_src_para.RTCSEL1);//ѡ��RTCOUT1�ź�ѡ��
	BTIMx_BTCFG1_RTCSEL2_Set(BTIMx, para->sig_src_para.RTCSEL2);//ѡ��RTCOUT2�ź�ѡ��
	BTIMx_BTCFG2_INSEL1_Set(BTIMx, para->sig_src_para.INSEL1);//ѡ���ڲ������ź�1
	BTIMx_BTCFG2_INSEL2_Set(BTIMx, para->sig_src_para.INSEL2);//ѡ���ڲ������ź�2
    BTIMx_BTCFG2_EXSEL1_Set(BTIMx, para->sig_src_para.EXSEL1);//ѡ���ⲿ�����ź�1
    BTIMx_BTCFG2_EXSEL2_Set(BTIMx, para->sig_src_para.EXSEL2);//ѡ���ⲿ�����ź�2
	
	
	BTIMx_BTCFG1_GRP1SEL_Set(BTIMx, para->sig_src_para.GRP1SEL);//ѡ��GROUP1�ź�ѡ��
	BTIMx_BTCFG1_GRP2SEL_Set(BTIMx, para->sig_src_para.GRP2SEL);//ѡ��GROUP2�ź�ѡ��
	
	BTIMx_BTCR2_SIG2SEL_Set(BTIMx, para->sig_src_para.CNTSRC);//ѡ���ڲ�����Դ�ź�
	BTIMx_BTCR2_SIG1SEL_Set(BTIMx, para->sig_src_para.CAPSRC);//ѡ���ڲ���׽Դ�ź�

	BTIMx_BTCR2_CNTHSEL_Set(BTIMx, para->sig_src_para.CNTHSEL);//��λ����������Դѡ��
	BTIMx_BTCR2_SRCSEL_Set(BTIMx, para->sig_src_para.SRCSEL);//ѡ���λ�������Ƿ�ʹ��

	//DIR������
	BTIMx_BTCR2_DIREN_Setable(BTIMx, para->dir_para.DIREN);//�ⲿdir���ƻ�ʹ��
	//BTIMx_BTCR2_STDIR_Setable(BTIMx, para->dir_para.STDIR);//�ڲ�dir�����źţ����Ӧ�ò���Ҫ
	BTIMx_BTCR2_DIRPO_Set(BTIMx, para->dir_para.DIRPO);//�ⲿ����dir�źż���ѡ��


	//���������
	BTIMx_BTCR1_MODE_Set(BTIMx, para->ctrl_para.MODE);//����ģʽ��16λ��׽����8λ��ʱ����
	BTIMx_BTCR1_EDGESEL_Set(BTIMx, para->ctrl_para.EDGESEL);//��ѡ�������ػ����½���
	BTIMx_BTPRES_Write(BTIMx, para->ctrl_para.PRESCALE);//ѡ���Ƶϵ��

	BTIMx_BTPRESET_PRESETH_Set(BTIMx, para->ctrl_para.PRESETH);//��λԤ����ֵ
	BTIMx_BTPRESET_PRESETL_Set(BTIMx, para->ctrl_para.PRESETL);//��λԤ����ֵ

	BTIMx_BTLOADH_Write(BTIMx, para->ctrl_para.LOADH);//��λ����ֵ
	BTIMx_BTLOADL_Write(BTIMx, para->ctrl_para.LOADL);//��λ����ֵ
	
	//��������
	BTIMx_BTOCR_OUTMOD_Set(BTIMx, para->out_para.OUTMOD);//���ģʽѡ��
	BTIMx_BTOCR_OUTSEL_Set(BTIMx, para->out_para.OUTSEL);//����ź�ѡ��
	BTIMx_BTOUTCNT_Write(BTIMx, para->out_para.OUTCNT);//�������������
	BTIMx_BTOCR_OUTINV_Set(BTIMx, para->out_para.OUTINV);//�����ƽ����ѡ��
	
}


