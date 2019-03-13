/**
  ******************************************************************************
  * @file    fm33a0xx_crc.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    8-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_crc.h" 


/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup CRC
  * @brief CRC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-20-31
//FM33A0XX_Driver_Gen_V1.4

/* CRC���ݼĴ��� ��غ��� */
void CRC_CRCDR_Write(uint32_t SetValue)
{
	CRC->CRCDR = (SetValue & CRC_CRCDR_CRCDR_Msk);
}

uint32_t CRC_CRCDR_Read(void)
{
	return (CRC->CRCDR & CRC_CRCDR_CRCDR_Msk);
}

/* CRC���뷴ת���� ��غ��� */
void CRC_CRCCR_RFLTIN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCCR |= (CRC_CRCCR_RFLTIN_Msk);
	}
	else
	{
		CRC->CRCCR &= ~(CRC_CRCCR_RFLTIN_Msk);
	}
}

FunState CRC_CRCCR_RFLTIN_Getable(void)
{
	if (CRC->CRCCR & (CRC_CRCCR_RFLTIN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC�����ת���� ��غ��� */
void CRC_CRCCR_RFLTO_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCCR |= (CRC_CRCCR_RFLTO_Msk);
	}
	else
	{
		CRC->CRCCR &= ~(CRC_CRCCR_RFLTO_Msk);
	}
}

FunState CRC_CRCCR_RFLTO_Getable(void)
{
	if (CRC->CRCCR & (CRC_CRCCR_RFLTO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRC�����־λ��ֻ�� ��غ��� */
FlagStatus CRC_CRCCR_RES_Chk(void)
{
	if (CRC->CRCCR & CRC_CRCCR_RES_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* CRC�����־λ��ֻ�� ��غ��� */
FlagStatus CRC_CRCCR_BUSY_Chk(void)
{
	if (CRC->CRCCR & CRC_CRCCR_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ʹ�� ��غ��� */
void CRC_CRCCR_XOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCCR |= (CRC_CRCCR_XOR_Msk);
	}
	else
	{
		CRC->CRCCR &= ~(CRC_CRCCR_XOR_Msk);
	}
}

FunState CRC_CRCCR_XOR_Getable(void)
{
	if (CRC->CRCCR & (CRC_CRCCR_XOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* CRCУ�����ʽѡ�� ��غ��� */
void CRC_CRCCR_CRCSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = CRC->CRCCR;
	tmpreg &= ~(CRC_CRCCR_CRCSEL_Msk);
	tmpreg |= (SetValue & CRC_CRCCR_CRCSEL_Msk);
	CRC->CRCCR = tmpreg;
}

uint32_t CRC_CRCCR_CRCSEL_Get(void)
{
	return (CRC->CRCCR & CRC_CRCCR_CRCSEL_Msk);
}

/* CRC����Ĵ��� ��غ��� */
void CRC_CRCLFSR_Write(uint32_t SetValue)
{
	CRC->CRCLFSR = (SetValue & CRC_CRCLFSR_LFSR_Msk);
}

uint32_t CRC_CRCLFSR_Read(void)
{
	return (CRC->CRCLFSR & CRC_CRCLFSR_LFSR_Msk);
}

/* CRC������Ĵ��� ��غ��� */
void CRC_CRCXOR_Write(uint32_t SetValue)
{
	CRC->CRCXOR = (SetValue & CRC_CRCXOR_CRC_XOR_Msk);
}

uint32_t CRC_CRCXOR_Read(void)
{
	return (CRC->CRCXOR & CRC_CRCXOR_CRC_XOR_Msk);
}

/* Flash����CRCУ��ʹ�� ��غ��� */
void CRC_CRCFLSEN_FLSCRCEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		CRC->CRCFLSEN |= (CRC_CRCFLSEN_FLSCRCEN_Msk);
	}
	else
	{
		CRC->CRCFLSEN &= ~(CRC_CRCFLSEN_FLSCRCEN_Msk);
	}
}

FunState CRC_CRCFLSEN_FLSCRCEN_Getable(void)
{
	if (CRC->CRCFLSEN & (CRC_CRCFLSEN_FLSCRCEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* FlashУ����ʼ��ַ��Word��ַ�� ��غ��� */
void CRC_CRCFLSAD_Write(uint32_t SetValue)
{
	CRC->CRCFLSAD = (SetValue & CRC_CRCFLSAD_FLSAD_Msk);
}

uint32_t CRC_CRCFLSAD_Read(void)
{
	return (CRC->CRCFLSAD & CRC_CRCFLSAD_FLSAD_Msk);
}

/* CRC FlashУ�����ݳ��ȣ�Word���ȣ� ��غ��� */
void CRC_CRCFLSSIZE_Write(uint32_t SetValue)
{
	CRC->CRCFLSSIZE = (SetValue & CRC_CRCFLSSIZE_FLSS_Msk);
}

uint32_t CRC_CRCFLSSIZE_Read(void)
{
	return (CRC->CRCFLSSIZE & CRC_CRCFLSSIZE_FLSS_Msk);
}


void CRC_Deinit(void)
{
	//CRC->CRCDR = ;
	CRC->CRCCR = 0x00000000;
	CRC->CRCLFSR = 0x0000FFFF;
	CRC->CRCXOR = 0x00000000;
	CRC->CRCFLSEN = 0x00000000;
	CRC->CRCFLSAD = 0x00000000;
	CRC->CRCFLSSIZE = 0x00000000;
}
//Code_End

/* CRC��ʼ�����ú���*/
void CRC_Init(CRC_InitTypeDef* para)
{
	CRC_CRCCR_CRCSEL_Set(para->CRCSEL);			/*!<CRCУ�����ʽѡ��*/
	CRC_CRCCR_RFLTIN_Setable(para->RFLTIN);		/*!<CRC���뷴ת����*/
	CRC_CRCCR_RFLTO_Setable(para->RFLTO);		/*!<CRC�����ת����*/
	CRC_CRCCR_XOR_Setable(para->XOR);			/*!<������ʹ��*/
	CRC_CRCXOR_Write(para->CRC_XOR);			/*!<���������Ĵ���*/
}

/******END OF FILE****/



