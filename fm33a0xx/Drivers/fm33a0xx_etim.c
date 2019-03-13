/**
  ******************************************************************************
  * @file    fm33a0xx_etim.c
  * @author  FM33a0 Application Team
  * @version V2.0.1
  * @date    26-2-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_etim.h"  


/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup ETIM 
  * @brief ETIM driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-21-03
//FM33A0XX_Driver_Gen_V1.4

/* �������������˲�ʹ�� ��غ��� */
void ETIMx_ETxCR_EXFLT_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_EXFLT_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_EXFLT_Msk);
	}
}

FunState ETIMx_ETxCR_EXFLT_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_EXFLT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PWM������� ��غ��� */
void ETIMx_ETxCR_PWM_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_PWM_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_PWM_Msk);
	}
}

FunState ETIMx_ETxCR_PWM_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_PWM_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �������� ��غ��� */
void ETIMx_ETxCR_CEN_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CEN_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CEN_Msk);
	}
}

FunState ETIMx_ETxCR_CEN_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ģʽѡ�� ��غ��� */
void ETIMx_ETxCR_MOD_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_MOD_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_MOD_Msk);
	ETIMx->ETxCR = tmpreg;
}

uint32_t ETIMx_ETxCR_MOD_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_MOD_Msk);
}

/* ��չ��ʱ������ʹ�� ��غ��� */
void ETIMx_ETxCR_CASEN_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CASEN_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CASEN_Msk);
	}
}

FunState ETIMx_ETxCR_CASEN_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CASEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ģʽ���ط�ʽѡ�񣨼���ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ����� ��غ��� */
void ETIMx_ETxCR_EDGESEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_EDGESEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_EDGESEL_Msk);
	ETIMx->ETxCR = tmpreg;
}

uint32_t ETIMx_ETxCR_EDGESEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_EDGESEL_Msk);
}

/* ��׽ģʽ���� ��غ��� */
void ETIMx_ETxCR_CAPMOD_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_CAPMOD_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_CAPMOD_Msk);
	ETIMx->ETxCR = tmpreg;
}

uint32_t ETIMx_ETxCR_CAPMOD_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_CAPMOD_Msk);
}

/* �����㲶׽ģʽ���� ��غ��� */
void ETIMx_ETxCR_CAPCLR_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CAPCLR_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CAPCLR_Msk);
	}
}

FunState ETIMx_ETxCR_CAPCLR_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CAPCLR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���β�׽���� ��غ��� */
void ETIMx_ETxCR_CAPONCE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxCR |= (ETIMx_ETxCR_CAPONCE_Msk);
	}
	else
	{
		ETIMx->ETxCR &= ~(ETIMx_ETxCR_CAPONCE_Msk);
	}
}

FunState ETIMx_ETxCR_CAPONCE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxCR & (ETIMx_ETxCR_CAPONCE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��׽��ѡ�� ��غ��� */
void ETIMx_ETxCR_CAPEDGE_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxCR;
	tmpreg &= ~(ETIMx_ETxCR_CAPEDGE_Msk);
	tmpreg |= (SetValue & ETIMx_ETxCR_CAPEDGE_Msk);
	ETIMx->ETxCR = tmpreg;
}

uint32_t ETIMx_ETxCR_CAPEDGE_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCR & ETIMx_ETxCR_CAPEDGE_Msk);
}

/* �ڲ��ź�2Դѡ��(��׽Դ) ��غ��� */
void ETIMx_ETxINSEL_SIG2SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_SIG2SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_SIG2SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}

uint32_t ETIMx_ETxINSEL_SIG2SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_SIG2SEL_Msk);
}

/* �ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ�� ��غ��� */
void ETIMx_ETxINSEL_SIG1SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_SIG1SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_SIG1SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}

uint32_t ETIMx_ETxINSEL_SIG1SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_SIG1SEL_Msk);
}

/* GROUP2 �ź�ѡ����� ��غ��� */
void ETIMx_ETxINSEL_GRP2SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_GRP2SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_GRP2SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}

uint32_t ETIMx_ETxINSEL_GRP2SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_GRP2SEL_Msk);
}

/* GROUP1 �ź�ѡ����� ��غ��� */
void ETIMx_ETxINSEL_GRP1SEL_Set(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ETIMx->ETxINSEL;
	tmpreg &= ~(ETIMx_ETxINSEL_GRP1SEL_Msk);
	tmpreg |= (SetValue & ETIMx_ETxINSEL_GRP1SEL_Msk);
	ETIMx->ETxINSEL = tmpreg;
}

uint32_t ETIMx_ETxINSEL_GRP1SEL_Get(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxINSEL & ETIMx_ETxINSEL_GRP1SEL_Msk);
}

/* ETxԤ��Ƶ�Ĵ���1 ��غ��� */
void ETIMx_ETxPESCALE1_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxPESCALE1 = (SetValue & ETIMx_ETxPESCALE1_PRESCALE1_Msk);
}

uint32_t ETIMx_ETxPESCALE1_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxPESCALE1 & ETIMx_ETxPESCALE1_PRESCALE1_Msk);
}

/* ETxԤ��Ƶ�Ĵ���2 ��غ��� */
void ETIMx_ETxPESCALE2_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxPESCALE2 = (SetValue & ETIMx_ETxPESCALE2_PRESCALE2_Msk);
}

uint32_t ETIMx_ETxPESCALE2_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxPESCALE2 & ETIMx_ETxPESCALE2_PRESCALE2_Msk);
}

/* ETx��ֵ�Ĵ��� ��غ��� */
void ETIMx_ETxIVR_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxIVR = (SetValue & ETIMx_ETxIVR_INITVALUE_Msk);
}

uint32_t ETIMx_ETxIVR_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxIVR & ETIMx_ETxIVR_INITVALUE_Msk);
}

/* ETx�ȽϼĴ��� ��غ��� */
void ETIMx_ETxCMP_Write(ETIMx_Type* ETIMx, uint32_t SetValue)
{
	ETIMx->ETxCMP = (SetValue & ETIMx_ETxCMP_CMP_Msk);
}

uint32_t ETIMx_ETxCMP_Read(ETIMx_Type* ETIMx)
{
	return (ETIMx->ETxCMP & ETIMx_ETxCMP_CMP_Msk);
}

/* ��չ��ʱ���Ƚ��ж�ʹ�� ��غ��� */
void ETIMx_ETxIE_CMPIE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxIE |= (ETIMx_ETxIE_CMPIE_Msk);
	}
	else
	{
		ETIMx->ETxIE &= ~(ETIMx_ETxIE_CMPIE_Msk);
	}
}

FunState ETIMx_ETxIE_CMPIE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIE & (ETIMx_ETxIE_CMPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��չ��ʱ����׽�ж�ʹ�� ��غ��� */
void ETIMx_ETxIE_CAPIE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxIE |= (ETIMx_ETxIE_CAPIE_Msk);
	}
	else
	{
		ETIMx->ETxIE &= ~(ETIMx_ETxIE_CAPIE_Msk);
	}
}

FunState ETIMx_ETxIE_CAPIE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIE & (ETIMx_ETxIE_CAPIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��չ��ʱ������ж�ʹ�� ��غ��� */
void ETIMx_ETxIE_OVIE_Setable(ETIMx_Type* ETIMx, FunState NewState)
{
	if (NewState == ENABLE)
	{
		ETIMx->ETxIE |= (ETIMx_ETxIE_OVIE_Msk);
	}
	else
	{
		ETIMx->ETxIE &= ~(ETIMx_ETxIE_OVIE_Msk);
	}
}

FunState ETIMx_ETxIE_OVIE_Getable(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIE & (ETIMx_ETxIE_OVIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ�״̬�жϱ�־ ��غ��� */
void ETIMx_ETxIF_CMPIF_Clr(ETIMx_Type* ETIMx)
{
	ETIMx->ETxIF = ETIMx_ETxIF_CMPIF_Msk;
}

FlagStatus ETIMx_ETxIF_CMPIF_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_CMPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��׽��״̬��־ ��غ��� */
FlagStatus ETIMx_ETxIF_EDGESTA_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_EDGESTA_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��չ��ʱ����׽�����жϱ�־ ��غ��� */
void ETIMx_ETxIF_CAPIF_Clr(ETIMx_Type* ETIMx)
{
	ETIMx->ETxIF = ETIMx_ETxIF_CAPIF_Msk;
}

FlagStatus ETIMx_ETxIF_CAPIF_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_CAPIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��չ��ʱ������жϱ�־ ��غ��� */
void ETIMx_ETxIF_OVIF_Clr(ETIMx_Type* ETIMx)
{
	ETIMx->ETxIF = ETIMx_ETxIF_OVIF_Msk;
}

FlagStatus ETIMx_ETxIF_OVIF_Chk(ETIMx_Type* ETIMx)
{
	if (ETIMx->ETxIF & ETIMx_ETxIF_OVIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void ETIMx_Deinit(ETIMx_Type* ETIMx)
{
	ETIMx->ETxCR = 0x00000000;
	ETIMx->ETxINSEL = 0x00000000;
	ETIMx->ETxPESCALE1 = 0x00000000;
	ETIMx->ETxPESCALE2 = 0x00000000;
	ETIMx->ETxIVR = 0x00000000;
	ETIMx->ETxCMP = 0x00000000;
	ETIMx->ETxIE = 0x00000000;
	//ETIMx->ETxIF = 0x00000000;
}
//Code_End


/*ETIMx ��ʼ�����ú���*/
void ETIMx_Init(ETIMx_Type* ETIMx, ETIM_InitTypeDef* para)
{
	//�ź�Դ����
	ETIMx_ETxINSEL_SIG1SEL_Set(ETIMx, para->sig_src_para.SIG1SEL);		/* �ڲ��ź�1Դѡ���ڼ���ģʽ�¼���Դ���ɴ�ѡ�񣬲�׽ģʽ�¼���Դ�� */
	ETIMx_ETxINSEL_SIG2SEL_Set(ETIMx, para->sig_src_para.SIG2SEL);		/* �ڲ��ź�2Դѡ��(��׽Դ) */
	ETIMx_ETxINSEL_GRP1SEL_Set(ETIMx, para->sig_src_para.GRP1SEL);		/* GROUP1 �ź�ѡ����� */
	ETIMx_ETxINSEL_GRP2SEL_Set(ETIMx, para->sig_src_para.GRP2SEL);		/* GROUP2 �ź�ѡ����� */
	ETIMx_ETxPESCALE1_Write(ETIMx, para->sig_src_para.PRESCALE1);		/* ETxԤ��Ƶ�Ĵ���1 */
	ETIMx_ETxPESCALE2_Write(ETIMx, para->sig_src_para.PRESCALE2);		/* ETxԤ��Ƶ�Ĵ���2 */
	
	//���������
	ETIMx_ETxCR_EXFLT_Setable(ETIMx, para->ctrl_para.EXFLT);		/* �������������˲�ʹ�� */
	ETIMx_ETxCR_MOD_Set(ETIMx, para->ctrl_para.MOD);				/* ����ģʽѡ�� */
	ETIMx_ETxCR_CASEN_Setable(ETIMx, para->ctrl_para.CASEN);		/* ��չ��ʱ������ʹ�� */
	ETIMx_ETxCR_EDGESEL_Set(ETIMx, para->ctrl_para.EDGESEL);		/* ����ģʽ���ط�ʽѡ�񣨼���ʱ��ѡ��mcu_clkʱ��λ��Ч�����ǲ���mcu_clkʱ�������ؼ����� */

	ETIMx_ETxCR_PWM_Setable(ETIMx, para->ctrl_para.PWM);		/* PWM������� */

	ETIMx_ETxCR_CAPMOD_Set(ETIMx, para->ctrl_para.CAPMOD);			/* ��׽ģʽ���� */
	ETIMx_ETxCR_CAPCLR_Setable(ETIMx, para->ctrl_para.CAPCLR);		/* �����㲶׽ģʽ���� */
	ETIMx_ETxCR_CAPONCE_Setable(ETIMx, para->ctrl_para.CAPONCE);	/* ���β�׽���� */
	ETIMx_ETxCR_CAPEDGE_Set(ETIMx, para->ctrl_para.CAPEDGE);		/* ��׽��ѡ�� */

	ETIMx_ETxIVR_Write(ETIMx, para->ctrl_para.INITVALUE);	/* ETx��ֵ�Ĵ��� */
	ETIMx_ETxCMP_Write(ETIMx, para->ctrl_para.CMP);			/* ETx�ȽϼĴ��� */

	ETIMx_ETxIE_CMPIE_Setable(ETIMx, para->ctrl_para.CMPIE);		/* ��չ��ʱ���Ƚ��ж�ʹ�� */
	ETIMx_ETxIE_CAPIE_Setable(ETIMx, para->ctrl_para.CAPIE);		/* ��չ��ʱ����׽�ж�ʹ�� */
	ETIMx_ETxIE_OVIE_Setable(ETIMx, para->ctrl_para.OVIE);			/* ��չ��ʱ������ж�ʹ�� */

	ETIMx_ETxCR_CEN_Setable(ETIMx, para->ctrl_para.CEN);		/* �������� */
}


/******END OF FILE****/

