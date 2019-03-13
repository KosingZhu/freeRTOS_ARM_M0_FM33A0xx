/**
  ******************************************************************************
  * @file    fm33a0xx_trng.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    30-11-2017
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33a0xx_trng.h" 


/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup TRNG 
  * @brief TRNG driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-22-21
//FM33A0XX_Driver_Gen_V1.4

/* RNGʹ�ܼĴ��������д1ʹ�� ��غ��� */
//void TRNG_TRNGCON_RNGEN_Setable(FunState NewState)
//{
//	if (NewState == ENABLE)
//	{
//		TRNG->TRNGCON |= (TRNG_TRNGCON_RNGEN_Msk);
//	}
//	else
//	{
//		TRNG->TRNGCON &= ~(TRNG_TRNGCON_RNGEN_Msk);
//	}
//}

//FunState TRNG_TRNGCON_RNGEN_Getable(void)
//{
//	if (TRNG->TRNGCON & (TRNG_TRNGCON_RNGEN_Msk))
//	{
//		return ENABLE;
//	}
//	else
//	{
//		return DISABLE;
//	}
//}

/* ��������ɽ����CRC�������Ĵ��� ��غ��� */
uint32_t TRNG_RNGOUT_Read(void)
{
	return (TRNG->RNGOUT);
}

/* ���������ʧ���ж�ʹ�ܼĴ���
 ��غ��� */
void TRNG_RNGIE_RNGIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		TRNG->RNGIE |= (TRNG_RNGIE_RNGIE_Msk);
	}
	else
	{
		TRNG->RNGIE &= ~(TRNG_RNGIE_RNGIE_Msk);
	}
}

FunState TRNG_RNGIE_RNGIE_Getable(void)
{
	if (TRNG->RNGIE & (TRNG_RNGIE_RNGIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* LFSRʹ�ܱ�־,���Ĵ�����������ģ���жϣ�������ѯ ��غ��� */
FlagStatus TRNG_RNGIF_LFSREN_Chk(void)
{
	if (TRNG->RNGIF & TRNG_RNGIF_LFSREN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���������ʧ�ܱ�־�����д1��0 ��غ��� */
void TRNG_RNGIF_RNF_Clr(void)
{
	TRNG->RNGIF = TRNG_RNGIF_RNF_Msk;
}

FlagStatus TRNG_RNGIF_RNF_Chk(void)
{
	if (TRNG->RNGIF & TRNG_RNGIF_RNF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CRC���ƼĴ��� ��غ��� */
void TRNG_CRCCON_CRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		TRNG->CRCCON |= (TRNG_CRCCON_CRCEN_Msk);
	}
	else
	{
		TRNG->CRCCON &= ~(TRNG_CRCCON_CRCEN_Msk);
	}
}

FunState TRNG_CRCCON_CRCEN_Getable(void)
{
	if (TRNG->CRCCON & (TRNG_CRCCON_CRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC������������Ĵ��� ��غ��� */
void TRNG_CRCIN_Write(uint32_t SetValue)
{
	TRNG->CRCIN = (SetValue);
}

uint32_t TRNG_CRCIN_Read(void)
{
	return (TRNG->CRCIN);
}

/* CRC������ɱ�־�����д0���� ��غ��� */
void TRNG_CRCFLAG_CRCD_Clr(void)
{
	TRNG->CRCFLAG &= ~(TRNG_CRCFLAG_CRCD_Msk);
}

FlagStatus TRNG_CRCFLAG_CRCD_Chk(void)
{
	if (TRNG->CRCFLAG & TRNG_CRCFLAG_CRCD_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void TRNG_Deinit(void)
{
	ANAC->TRNGCON = 0x00000000;//TRNG->TRNGCON = 0x00000000;
	//TRNG->RNGOUT = ;
	TRNG->RNGIE = 0x00000000;
	//TRNG->RNGIF = ;
	TRNG->CRCCON = 0x00000000;
	TRNG->CRCIN = 0x00000000;
	TRNG->CRCFLAG = 0x00000000;
}
//Code_End



/******END OF FILE****/



