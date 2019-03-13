/**
  ******************************************************************************
  * @file    fm33a0xx_flash.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    3-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_flash.h" 

/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup FLASH 
  * @brief FLASH driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup FLASH_Private_Functions
  * @{
  */ 
	
//Code_Start
//2018-04-02-13-21-07
//FM33A0XX_Driver_Gen_V1.4

/* Flash���ȴ���������(CPUʱ�ӳ���24M���迪wait1) ��غ��� */
void FLASH_FLSRDCON_WAIT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->FLSRDCON;
	tmpreg &= ~(FLASH_FLSRDCON_WAIT_Msk);
	tmpreg |= (SetValue & FLASH_FLSRDCON_WAIT_Msk);
	FLASH->FLSRDCON = tmpreg;
}

uint32_t FLASH_FLSRDCON_WAIT_Get(void)
{
	return (FLASH->FLSRDCON & FLASH_FLSRDCON_WAIT_Msk);
}

/* �û������ּĴ��� ��غ��� */
FlagStatus FLASH_OPTBR_DBGCFGEN_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_DBGCFGEN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

FlagStatus FLASH_OPTBR_RAMBOOT_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_RAMBOOT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

FlagStatus FLASH_OPTBR_ACLOCKEN_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_ACLOCKEN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

FlagStatus FLASH_OPTBR_DBRDPEN_Chk(void)
{
	if (FLASH->OPTBR & FLASH_OPTBR_DBRDPEN_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ACLOCK���üĴ�����32bit���ֱ����ڿ���Block31~Block0��Ӧ�ô����д������1����ȡ�Ͳ�дȨ������0����ȡ�Ͳ�дȨ�޷ſ�,���ֻ��д1���������㡣 ��غ��� */
void FLASH_ACLOCK1_Write(uint32_t SetValue)
{
	FLASH->ACLOCK1 = (SetValue);
}

uint32_t FLASH_ACLOCK1_Read(void)
{
	return (FLASH->ACLOCK1);
}

/* ACLOCK���üĴ�����32bit���ֱ����ڿ���Block63~Block32��Ӧ�ô����д������1����ȡ�Ͳ�дȨ������0����ȡ�Ͳ�дȨ�޷ſ�,���ֻ��д1���������㡣 ��غ��� */
void FLASH_ACLOCK2_Write(uint32_t SetValue)
{
	FLASH->ACLOCK2 = (SetValue);
}

uint32_t FLASH_ACLOCK2_Read(void)
{
	return (FLASH->ACLOCK2);
}

/* ������ ��غ��� */
void FLASH_EPCON_ERTYPE_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->EPCON;
	tmpreg &= ~(FLASH_EPCON_ERTYPE_Msk);
	tmpreg |= (SetValue & FLASH_EPCON_ERTYPE_Msk);
	FLASH->EPCON = tmpreg;
}

uint32_t FLASH_EPCON_ERTYPE_Get(void)
{
	return (FLASH->EPCON & FLASH_EPCON_ERTYPE_Msk);
}

void FLASH_EPCON_PREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->EPCON;
	tmpreg &= ~(FLASH_EPCON_PREQ_Msk);
	tmpreg |= (SetValue & FLASH_EPCON_PREQ_Msk);
	FLASH->EPCON = tmpreg;
}

uint32_t FLASH_EPCON_PREQ_Get(void)
{
	return (FLASH->EPCON & FLASH_EPCON_PREQ_Msk);
}

void FLASH_EPCON_EREQ_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = FLASH->EPCON;
	tmpreg &= ~(FLASH_EPCON_EREQ_Msk);
	tmpreg |= (SetValue & FLASH_EPCON_EREQ_Msk);
	FLASH->EPCON = tmpreg;
}

uint32_t FLASH_EPCON_EREQ_Get(void)
{
	return (FLASH->EPCON & FLASH_EPCON_EREQ_Msk);
}

/* Flash��дKey����Ĵ������������SWD��������дǰ������ȷ����˵�ַд��Ϸ�KEY���С��յ�ַ���������޼Ĵ���ʵ�֡� ��غ��� */
void FLASH_FLSKEY_Write(uint32_t SetValue)
{
	FLASH->FLSKEY = (SetValue);
}

/* Flash�ж�ʹ�� ��غ��� */
void FLASH_FLSIE_AUTHIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_AUTHIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_AUTHIE_Msk);
	}
}

FunState FLASH_FLSIE_AUTHIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_AUTHIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void FLASH_FLSIE_KEYIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_KEYIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_KEYIE_Msk);
	}
}

FunState FLASH_FLSIE_KEYIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_KEYIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void FLASH_FLSIE_CKIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_CKIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_CKIE_Msk);
	}
}

FunState FLASH_FLSIE_CKIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_CKIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void FLASH_FLSIE_PRDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_PRDIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_PRDIE_Msk);
	}
}

FunState FLASH_FLSIE_PRDIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_PRDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void FLASH_FLSIE_ERDIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		FLASH->FLSIE |= (FLASH_FLSIE_ERDIE_Msk);
	}
	else
	{
		FLASH->FLSIE &= ~(FLASH_FLSIE_ERDIE_Msk);
	}
}

FunState FLASH_FLSIE_ERDIE_Getable(void)
{
	if (FLASH->FLSIE & (FLASH_FLSIE_ERDIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Flash�жϱ�־ ��غ��� */
void FLASH_FLSIF_AUTHIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_AUTHIF_Msk;
}

FlagStatus FLASH_FLSIF_AUTHIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_AUTHIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLASH_FLSIF_KEYIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_KEYIF_Msk;
}

FlagStatus FLASH_FLSIF_KEYIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_KEYIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLASH_FLSIF_CKIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_CKIF_Msk;
}

FlagStatus FLASH_FLSIF_CKIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_CKIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLASH_FLSIF_PRDIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_PRDIF_Msk;
}

FlagStatus FLASH_FLSIF_PRDIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_PRDIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLASH_FLSIF_ERDIF_Clr(void)
{
	FLASH->FLSIF = FLASH_FLSIF_ERDIF_Msk;
}

FlagStatus FLASH_FLSIF_ERDIF_Chk(void)
{
	if (FLASH->FLSIF & FLASH_FLSIF_ERDIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void FLASH_Deinit(void)
{
	FLASH->FLSRDCON = 0x00000000;
	FLASH->PRFTCON = 0x00000000;
	//FLASH->OPTBR = 0x00000005;
	//FLASH->ACLOCK1 = ;
	//FLASH->ACLOCK2 = ;
	FLASH->EPCON = 0x00000000;
	FLASH->FLSKEY = 0x00000000;
	FLASH->FLSIE = 0x00000000;
	//FLASH->FLSIF = 0x00000000;
}
//Code_End



void FLASH_Erase_Sector(uint32_t erase_addr)
{
    //set to sector erase
    FLASH_EPCON_ERTYPE_Set(FLASH_EPCON_ERTYPE_SECTOR);
	
    //SET EREQ
    FLASH_EPCON_EREQ_Set(FLASH_EPCON_EREQ_ERASE);
	
    //write flash key
    FLASH_FLSKEY_Write(flash_sector_erase_key0);
    FLASH_FLSKEY_Write(flash_sector_erase_key1);
	
    //����Ҫ�����������������ַд��������0x1234_ABCD
    *(uint32_t*)erase_addr = flash_erase_data;
	
	//wait for finish
	while(SET != FLASH_FLSIF_ERDIF_Chk()){__NOP();}
	FLASH_FLSIF_ERDIF_Clr();
	
    FLASH_FLSKEY_Write(0x00000000);
}


void FLASH_Prog_SingleByte(uint32_t prog_addr,uint8_t prog_data)
{
	//set PREQ
    FLASH_EPCON_PREQ_Set(FLASH_EPCON_PREQ_PROG);
	
	//write flash key
    FLASH_FLSKEY_Write(flash_PROG_key0);
    FLASH_FLSKEY_Write(flash_PROG_key1);
	
    *(uint8_t*)prog_addr = prog_data;	

    while(RESET == FLASH_FLSIF_PRDIF_Chk()){__NOP();}
	FLASH_FLSIF_PRDIF_Clr();
	
    FLASH_FLSKEY_Write(0x00000000);
}

void FLASH_Prog_ByteString(uint32_t prog_addr,uint8_t* prog_data, uint16_t Len)
{
	uint16_t i;
	//set PREQ
	FLASH_EPCON_PREQ_Set(FLASH_EPCON_PREQ_PROG);
	
	//write flash key
	FLASH_FLSKEY_Write(flash_PROG_key0);
	FLASH_FLSKEY_Write(flash_PROG_key1);
	
	for(i=0; i<Len; i++)
	{
		FLASH_EPCON_PREQ_Set(FLASH_EPCON_PREQ_PROG);	//set PREQ
		*(uint8_t*)prog_addr = prog_data[i];						//дһ���ֽ�
		prog_addr++;
		while(RESET == FLASH_FLSIF_PRDIF_Chk()){__NOP();}//�ȴ�д�������
		FLASH_FLSIF_PRDIF_Clr();						//���д����жϱ�־
	//	delay_50(1);
	}
	
    FLASH_FLSKEY_Write(0x00000000);
}

/******END OF FILE****/






