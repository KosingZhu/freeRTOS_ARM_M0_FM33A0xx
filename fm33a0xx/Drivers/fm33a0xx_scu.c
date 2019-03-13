/**
  ******************************************************************************
  * @file    fm33a0xx_scu.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    7-12-2017
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of the system control unit (scu) peripheral:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_scu.h" 

/** @addtogroup fm385_StdPeriph_Driver
  * @{
  */

/** @defgroup SCU 
  * @brief SCU driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/


/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/** @defgroup SCU_Private_Functions
  * @{
  */
	

//Code_Start
//2018-04-02-13-22-16
//FM33A0XX_Driver_Gen_V1.4

/* Debug״̬��ET4ʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_ET4_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET4_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET4_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_ET4_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET4_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET3ʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_ET3_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET3_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET3_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_ET3_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET3_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET2ʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_ET2_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET2_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET2_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_ET2_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET2_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��ET1ʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_ET1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_ET1_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_ET1_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_ET1_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_ET1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��BT2ʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_BT2_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_BT2_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_BT2_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_BT2_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_BT2_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��BT1ʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_BT1_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_BT1_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_BT1_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_BT1_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_BT1_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��WWDTʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_WWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_WWDT_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_WWDT_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_WWDT_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_WWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Debug״̬��IWDTʹ�ܿ��� ��غ��� */
void SCU_MCUDBGCR_DBG_IWDT_STOP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		SCU->MCUDBGCR |= (SCU_MCUDBGCR_DBG_IWDT_STOP_Msk);
	}
	else
	{
		SCU->MCUDBGCR &= ~(SCU_MCUDBGCR_DBG_IWDT_STOP_Msk);
	}
}

FunState SCU_MCUDBGCR_DBG_IWDT_STOP_Getable(void)
{
	if (SCU->MCUDBGCR & (SCU_MCUDBGCR_DBG_IWDT_STOP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��ַ�Ƕ�����ʴ����־ ��غ��� */
void SCU_HDFFLAG_DABORT_ADDR_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_DABORT_ADDR_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_DABORT_ADDR_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_DABORT_ADDR_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƿ���ַ���ʴ����־ ��غ��� */
void SCU_HDFFLAG_DABORT_RESP_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_DABORT_RESP_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_DABORT_RESP_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_DABORT_RESP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVC instructionsδ�����־ ��غ��� */
void SCU_HDFFLAG_SVCUNDEF_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_SVCUNDEF_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_SVCUNDEF_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_SVCUNDEF_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ִ��BKPTָ���־ ��غ��� */
void SCU_HDFFLAG_BKPT_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_BKPT_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_BKPT_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_BKPT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Thumb-State��־ ��غ��� */
void SCU_HDFFLAG_TBIT_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_TBIT_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_TBIT_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_TBIT_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����ָ���־ ��غ��� */
void SCU_HDFFLAG_SPECIAL_OP_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_SPECIAL_OP_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_SPECIAL_OP_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_SPECIAL_OP_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* hardfault��־λ ��غ��� */
void SCU_HDFFLAG_HDF_REQUEST_FLAG_Clr(void)
{
	SCU->HDFFLAG = SCU_HDFFLAG_HDF_REQUEST_FLAG_Msk;
}

FlagStatus SCU_HDFFLAG_HDF_REQUEST_FLAG_Chk(void)
{
	if (SCU->HDFFLAG & SCU_HDFFLAG_HDF_REQUEST_FLAG_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void SCU_Deinit(void)
{
	SCU->MCUDBGCR = 0x00003F03;
	SCU->HDFFLAG = 0x00000000;
}
//Code_End


/******END OF FILE****/



