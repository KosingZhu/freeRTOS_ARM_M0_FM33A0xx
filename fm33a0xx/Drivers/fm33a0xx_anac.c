/**
  ******************************************************************************
  * @file    fm33a0xx_anac.c
  * @author  FM33a0 Application Team
  * @version V2.0.1
  * @date    23-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_anac.h" 


/** @addtogroup fm33a0_StdPeriph_Driver
  * @{
  */

/** @defgroup ANAC 
  * @brief ANAC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-20-01
//FM33A0XX_Driver_Gen_V1.4

/* PDR�µ縴λ��ѹ���� ��غ��� */
void ANAC_PDRCON_PDRCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->PDRCON;
	tmpreg &= ~(ANAC_PDRCON_PDRCFG_Msk);
	tmpreg |= (SetValue & ANAC_PDRCON_PDRCFG_Msk);
	ANAC->PDRCON = tmpreg;
}

uint32_t ANAC_PDRCON_PDRCFG_Get(void)
{
	return (ANAC->PDRCON & ANAC_PDRCON_PDRCFG_Msk);
}

/* PDR�µ縴λʹ�� ��غ��� */
void ANAC_PDRCON_PDREN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->PDRCON |= (ANAC_PDRCON_PDREN_Msk);
	}
	else
	{
		ANAC->PDRCON &= ~(ANAC_PDRCON_PDREN_Msk);
	}
}

FunState ANAC_PDRCON_PDREN_Getable(void)
{
	if (ANAC->PDRCON & (ANAC_PDRCON_PDREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* BOR�µ縴λ��ѹ���� ��غ��� */
void ANAC_BORCON_BOR_PDRCFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->BORCON;
	tmpreg &= ~(ANAC_BORCON_BOR_PDRCFG_Msk);
	tmpreg |= (SetValue & ANAC_BORCON_BOR_PDRCFG_Msk);
	ANAC->BORCON = tmpreg;
}

uint32_t ANAC_BORCON_BOR_PDRCFG_Get(void)
{
	return (ANAC->BORCON & ANAC_BORCON_BOR_PDRCFG_Msk);
}

/* BOR�رտ��ƼĴ��� ��غ��� */
void ANAC_BORCON_OFF_BOR_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->BORCON |= (ANAC_BORCON_OFF_BOR_Msk);
	}
	else
	{
		ANAC->BORCON &= ~(ANAC_BORCON_OFF_BOR_Msk);
	}
}

FunState ANAC_BORCON_OFF_BOR_Getable(void)
{
	if (ANAC->BORCON & (ANAC_BORCON_OFF_BOR_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD��Դ�����ж�ʹ�� ��غ��� */
void ANAC_SVDCFG_PFIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCFG |= (ANAC_SVDCFG_PFIE_Msk);
	}
	else
	{
		ANAC->SVDCFG &= ~(ANAC_SVDCFG_PFIE_Msk);
	}
}

FunState ANAC_SVDCFG_PFIE_Getable(void)
{
	if (ANAC->SVDCFG & (ANAC_SVDCFG_PFIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD��Դ�ָ��ж�ʹ�� ��غ��� */
void ANAC_SVDCFG_PRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCFG |= (ANAC_SVDCFG_PRIE_Msk);
	}
	else
	{
		ANAC->SVDCFG &= ~(ANAC_SVDCFG_PRIE_Msk);
	}
}

FunState ANAC_SVDCFG_PRIE_Getable(void)
{
	if (ANAC->SVDCFG & (ANAC_SVDCFG_PRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD������ֵ���� ��غ��� */
void ANAC_SVDCFG_SVDLVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->SVDCFG;
	tmpreg &= ~(ANAC_SVDCFG_SVDLVL_Msk);
	tmpreg |= (SetValue & ANAC_SVDCFG_SVDLVL_Msk);
	ANAC->SVDCFG = tmpreg;
}

uint32_t ANAC_SVDCFG_SVDLVL_Get(void)
{
	return (ANAC->SVDCFG & ANAC_SVDCFG_SVDLVL_Msk);
}

/* �����˲�ʹ�ܣ�SVDMODE=1ʱ������1�� ��غ��� */
void ANAC_SVDCFG_DFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCFG |= (ANAC_SVDCFG_DFEN_Msk);
	}
	else
	{
		ANAC->SVDCFG &= ~(ANAC_SVDCFG_DFEN_Msk);
	}
}

FunState ANAC_SVDCFG_DFEN_Getable(void)
{
	if (ANAC->SVDCFG & (ANAC_SVDCFG_DFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD����ģʽѡ�� ��غ��� */
void ANAC_SVDCFG_SVDMOD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->SVDCFG;
	tmpreg &= ~(ANAC_SVDCFG_SVDMOD_Msk);
	tmpreg |= (SetValue & ANAC_SVDCFG_SVDMOD_Msk);
	ANAC->SVDCFG = tmpreg;
}

uint32_t ANAC_SVDCFG_SVDMOD_Get(void)
{
	return (ANAC->SVDCFG & ANAC_SVDCFG_SVDMOD_Msk);
}

/* SVD��Ъʹ�ܼ�� ��غ��� */
void ANAC_SVDCFG_SVDITVL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->SVDCFG;
	tmpreg &= ~(ANAC_SVDCFG_SVDITVL_Msk);
	tmpreg |= (SetValue & ANAC_SVDCFG_SVDITVL_Msk);
	ANAC->SVDCFG = tmpreg;
}

uint32_t ANAC_SVDCFG_SVDITVL_Get(void)
{
	return (ANAC->SVDCFG & ANAC_SVDCFG_SVDITVL_Msk);
}

/* SVD����ʹ�ܣ�����Ϊ0 ��غ��� */
void ANAC_SVDCON_SVDTE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCON |= (ANAC_SVDCON_SVDTE_Msk);
	}
	else
	{
		ANAC->SVDCON &= ~(ANAC_SVDCON_SVDTE_Msk);
	}
}

FunState ANAC_SVDCON_SVDTE_Getable(void)
{
	if (ANAC->SVDCON & (ANAC_SVDCON_SVDTE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVDʹ�� ��غ��� */
void ANAC_SVDCON_SVDEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->SVDCON |= (ANAC_SVDCON_SVDEN_Msk);
	}
	else
	{
		ANAC->SVDCON &= ~(ANAC_SVDCON_SVDEN_Msk);
	}
}

FunState ANAC_SVDCON_SVDEN_Getable(void)
{
	if (ANAC->SVDCON & (ANAC_SVDCON_SVDEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* SVD��Դ������(ģ��ģ��ֱ��������ź�,����SVD������ʱ��ɲ�ѯ) ��غ��� */
FlagStatus ANAC_SVDSIF_SVDO_Chk(void)
{
	if (ANAC->SVDSIF & ANAC_SVDSIF_SVDO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Դ�����жϱ�־�Ĵ�������Դ��ѹ���䵽SVD��ֵ֮��ʱ��λ�����д1���� ��غ��� */
void ANAC_SVDSIF_PFF_Clr(void)
{
	ANAC->SVDSIF = ANAC_SVDSIF_PFF_Msk;
}

FlagStatus ANAC_SVDSIF_PFF_Chk(void)
{
	if (ANAC->SVDSIF & ANAC_SVDSIF_PFF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��Դ�ָ��жϱ�־�Ĵ�������Դ��ѹ������SVD��ֵ֮��ʱ��λ�����д1���� ��غ��� */
void ANAC_SVDSIF_PRF_Clr(void)
{
	ANAC->SVDSIF = ANAC_SVDSIF_PRF_Msk;
}

FlagStatus ANAC_SVDSIF_PRF_Chk(void)
{
	if (ANAC->SVDSIF & ANAC_SVDSIF_PRF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SVD�ڲ��˲���ĵ�ѹ����־������ʹ�������˲�ʱ�����壻�������д�˼Ĵ����� ��غ��� */
FlagStatus ANAC_SVDALM_SVDALM_B_Chk(void)
{
	if (ANAC->SVDALM & ANAC_SVDALM_SVDALM_B_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* XTLFͣ���ⱨ���ж�ʹ��,�ϵ�Ĭ�Ϲرգ�������ϵ�ʱ����δ���񴥷��ж�
 ��غ��� */
void ANAC_FDETIE_FDET_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->FDETIE |= (ANAC_FDETIE_FDET_IE_Msk);
	}
	else
	{
		ANAC->FDETIE &= ~(ANAC_FDETIE_FDET_IE_Msk);
	}
}

FunState ANAC_FDETIE_FDET_IE_Getable(void)
{
	if (ANAC->FDETIE & (ANAC_FDETIE_FDET_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ͣ����ģ����� ��غ��� */
FlagStatus ANAC_FDETIF_FDETO_Chk(void)
{
	if (ANAC->FDETIF & ANAC_FDETIF_FDETO_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ͣ�����жϱ�־�Ĵ�����XTLFͣ��ʱӲ���첽��λ�����д1���㣻ֻ����FDETO��Ϊ0������²��ܹ�����˼Ĵ��� ��غ��� */
void ANAC_FDETIF_FDETIF_Clr(void)
{
	ANAC->FDETIF = ANAC_FDETIF_FDETIF_Msk;
}

FlagStatus ANAC_FDETIF_FDETIF_Chk(void)
{
	if (ANAC->FDETIF & ANAC_FDETIF_FDETIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ADC�ж�ʹ�� ��غ��� */
void ANAC_ADCCON_ADC_IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCCON |= (ANAC_ADCCON_ADC_IE_Msk);
	}
	else
	{
		ANAC->ADCCON &= ~(ANAC_ADCCON_ADC_IE_Msk);
	}
}

FunState ANAC_ADCCON_ADC_IE_Getable(void)
{
	if (ANAC->ADCCON & (ANAC_ADCCON_ADC_IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADCͨ��ѡ�� ��غ��� */
void ANAC_ADCCON_ADC_VANA_EN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->ADCCON;
	tmpreg &= ~(ANAC_ADCCON_ADC_VANA_EN_Msk);
	tmpreg |= (SetValue & ANAC_ADCCON_ADC_VANA_EN_Msk);
	ANAC->ADCCON = tmpreg;
}

uint32_t ANAC_ADCCON_ADC_VANA_EN_Get(void)
{
	return (ANAC->ADCCON & ANAC_ADCCON_ADC_VANA_EN_Msk);
}

/* ADCʹ���ź� ��غ��� */
void ANAC_ADCCON_ADC_EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCCON |= (ANAC_ADCCON_ADC_EN_Msk);
	}
	else
	{
		ANAC->ADCCON &= ~(ANAC_ADCCON_ADC_EN_Msk);
	}
}

FunState ANAC_ADCCON_ADC_EN_Getable(void)
{
	if (ANAC->ADCCON & (ANAC_ADCCON_ADC_EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC TRIMֵ,�ӳ�����������ȡ ��غ��� */
void ANAC_ADCTRIM_Write(uint32_t SetValue)
{
	ANAC->ADCTRIM = (SetValue & ANAC_ADCTRIM_ADC_TRIM_Msk);
}

uint32_t ANAC_ADCTRIM_Read(void)
{
	return (ANAC->ADCTRIM & ANAC_ADCTRIM_ADC_TRIM_Msk);
}

/* ADC������ݼĴ��� ��غ��� */
uint32_t ANAC_ADCDATA_Read(void)
{
	return (ANAC->ADCDATA & ANAC_ADCDATA_ADC_DATA_Msk);
}

/* ADCת������жϱ�־��Ӳ����λ�����д1���㣬д0��Ч ��غ��� */
void ANAC_ADCIF_ADC_IF_Clr(void)
{
	ANAC->ADCIF = ANAC_ADCIF_ADC_IF_Msk;
}

FlagStatus ANAC_ADCIF_ADC_IF_Chk(void)
{
	if (ANAC->ADCIF & ANAC_ADCIF_ADC_IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ADC����ͨ��Bufferʹ�� ��غ��� */
void ANAC_ADCINSEL_BUFEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCINSEL |= (ANAC_ADCINSEL_BUFEN_Msk);
	}
	else
	{
		ANAC->ADCINSEL &= ~(ANAC_ADCINSEL_BUFEN_Msk);
	}
}

FunState ANAC_ADCINSEL_BUFEN_Getable(void)
{
	if (ANAC->ADCINSEL & (ANAC_ADCINSEL_BUFEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC����Buffer Bypass ��غ��� */
void ANAC_ADCINSEL_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->ADCINSEL |= (ANAC_ADCINSEL_BUFBYP_Msk);
	}
	else
	{
		ANAC->ADCINSEL &= ~(ANAC_ADCINSEL_BUFBYP_Msk);
	}
}

FunState ANAC_ADCINSEL_BUFBYP_Getable(void)
{
	if (ANAC->ADCINSEL & (ANAC_ADCINSEL_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ADC����ͨ��ѡ�� ��غ��� */
void ANAC_ADCINSEL_BUFSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->ADCINSEL;
	tmpreg &= ~(ANAC_ADCINSEL_BUFSEL_Msk);
	tmpreg |= (SetValue & ANAC_ADCINSEL_BUFSEL_Msk);
	ANAC->ADCINSEL = tmpreg;
}

uint32_t ANAC_ADCINSEL_BUFSEL_Get(void)
{
	return (ANAC->ADCINSEL & ANAC_ADCINSEL_BUFSEL_Msk);
}

/* TRNG���� ��غ��� */
void ANAC_TRNGCON_TRNGEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->TRNGCON |= (ANAC_TRNGCON_TRNGEN_Msk);
	}
	else
	{
		ANAC->TRNGCON &= ~(ANAC_TRNGCON_TRNGEN_Msk);
	}
}

FunState ANAC_TRNGCON_TRNGEN_Getable(void)
{
	if (ANAC->TRNGCON & (ANAC_TRNGCON_TRNGEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���1��������ֻ�� ��غ��� */
FlagStatus ANAC_COMP1CR_CMP1O_Chk(void)
{
	if (ANAC->COMP1CR & ANAC_COMP1CR_CMP1O_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���1��������ѡ�� ��غ��� */
void ANAC_COMP1CR_V1PSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP1CR;
	tmpreg &= ~(ANAC_COMP1CR_V1PSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP1CR_V1PSEL_Msk);
	ANAC->COMP1CR = tmpreg;
}

uint32_t ANAC_COMP1CR_V1PSEL_Get(void)
{
	return (ANAC->COMP1CR & ANAC_COMP1CR_V1PSEL_Msk);
}

/* �Ƚ���1��������ѡ�� ��غ��� */
void ANAC_COMP1CR_V1NSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP1CR;
	tmpreg &= ~(ANAC_COMP1CR_V1NSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP1CR_V1NSEL_Msk);
	ANAC->COMP1CR = tmpreg;
}

uint32_t ANAC_COMP1CR_V1NSEL_Get(void)
{
	return (ANAC->COMP1CR & ANAC_COMP1CR_V1NSEL_Msk);
}

/* �Ƚ���1ʹ��λ ��غ��� */
void ANAC_COMP1CR_CMP1EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMP1CR |= (ANAC_COMP1CR_CMP1EN_Msk);
	}
	else
	{
		ANAC->COMP1CR &= ~(ANAC_COMP1CR_CMP1EN_Msk);
	}
}

FunState ANAC_COMP1CR_CMP1EN_Getable(void)
{
	if (ANAC->COMP1CR & (ANAC_COMP1CR_CMP1EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���2��������ֻ�� ��غ��� */
FlagStatus ANAC_COMP2CR_CMP2O_Chk(void)
{
	if (ANAC->COMP2CR & ANAC_COMP2CR_CMP2O_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���2��������ѡ�� ��غ��� */
void ANAC_COMP2CR_V2PSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP2CR;
	tmpreg &= ~(ANAC_COMP2CR_V2PSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP2CR_V2PSEL_Msk);
	ANAC->COMP2CR = tmpreg;
}

uint32_t ANAC_COMP2CR_V2PSEL_Get(void)
{
	return (ANAC->COMP2CR & ANAC_COMP2CR_V2PSEL_Msk);
}

/* �Ƚ���2��������ѡ�� ��غ��� */
void ANAC_COMP2CR_V2NSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMP2CR;
	tmpreg &= ~(ANAC_COMP2CR_V2NSEL_Msk);
	tmpreg |= (SetValue & ANAC_COMP2CR_V2NSEL_Msk);
	ANAC->COMP2CR = tmpreg;
}

uint32_t ANAC_COMP2CR_V2NSEL_Get(void)
{
	return (ANAC->COMP2CR & ANAC_COMP2CR_V2NSEL_Msk);
}

/* �Ƚ���2ʹ��λ ��غ��� */
void ANAC_COMP2CR_CMP2EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMP2CR |= (ANAC_COMP2CR_CMP2EN_Msk);
	}
	else
	{
		ANAC->COMP2CR &= ~(ANAC_COMP2CR_CMP2EN_Msk);
	}
}

FunState ANAC_COMP2CR_CMP2EN_Getable(void)
{
	if (ANAC->COMP2CR & (ANAC_COMP2CR_CMP2EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���2�����˲�ʹ�� ��غ��� */
void ANAC_COMPICR_CMP2DF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP2DF_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP2DF_Msk);
	}
}

FunState ANAC_COMPICR_CMP2DF_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP2DF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���1�����˲�ʹ�� ��غ��� */
void ANAC_COMPICR_CMP1DF_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP1DF_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP1DF_Msk);
	}
}

FunState ANAC_COMPICR_CMP1DF_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP1DF_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���Buffer Bypass ��غ��� */
void ANAC_COMPICR_BUFBYP_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_BUFBYP_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_BUFBYP_Msk);
	}
}

FunState ANAC_COMPICR_BUFBYP_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_BUFBYP_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���Bufferʹ�� ��غ��� */
void ANAC_COMPICR_BUFENB_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_BUFENB_Msk);
	}
	else
	{
		ANAC->COMPICR |= (ANAC_COMPICR_BUFENB_Msk);
	}
}

FunState ANAC_COMPICR_BUFENB_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_BUFENB_Msk))
	{
		return DISABLE;
	}
	else
	{
		return ENABLE;
	}
}

/* �Ƚ���2�ж�Դѡ�� ��غ��� */
void ANAC_COMPICR_CMP2SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMPICR;
	tmpreg &= ~(ANAC_COMPICR_CMP2SEL_Msk);
	tmpreg |= (SetValue & ANAC_COMPICR_CMP2SEL_Msk);
	ANAC->COMPICR = tmpreg;
}

uint32_t ANAC_COMPICR_CMP2SEL_Get(void)
{
	return (ANAC->COMPICR & ANAC_COMPICR_CMP2SEL_Msk);
}

/* �Ƚ���1�ж�Դѡ�� ��غ��� */
void ANAC_COMPICR_CMP1SEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = ANAC->COMPICR;
	tmpreg &= ~(ANAC_COMPICR_CMP1SEL_Msk);
	tmpreg |= (SetValue & ANAC_COMPICR_CMP1SEL_Msk);
	ANAC->COMPICR = tmpreg;
}

uint32_t ANAC_COMPICR_CMP1SEL_Get(void)
{
	return (ANAC->COMPICR & ANAC_COMPICR_CMP1SEL_Msk);
}

/* �Ƚ���2�ж�ʹ�� ��غ��� */
void ANAC_COMPICR_CMP2IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP2IE_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP2IE_Msk);
	}
}

FunState ANAC_COMPICR_CMP2IE_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP2IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���1�ж�ʹ�� ��غ��� */
void ANAC_COMPICR_CMP1IE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		ANAC->COMPICR |= (ANAC_COMPICR_CMP1IE_Msk);
	}
	else
	{
		ANAC->COMPICR &= ~(ANAC_COMPICR_CMP1IE_Msk);
	}
}

FunState ANAC_COMPICR_CMP1IE_Getable(void)
{
	if (ANAC->COMPICR & (ANAC_COMPICR_CMP1IE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �Ƚ���2�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void ANAC_COMPIF_CMP2IF_Clr(void)
{
	ANAC->COMPIF = ANAC_COMPIF_CMP2IF_Msk;
}

FlagStatus ANAC_COMPIF_CMP2IF_Chk(void)
{
	if (ANAC->COMPIF & ANAC_COMPIF_CMP2IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* �Ƚ���1�жϱ�־��Ӳ����λ�����д1���� ��غ��� */
void ANAC_COMPIF_CMP1IF_Clr(void)
{
	ANAC->COMPIF = ANAC_COMPIF_CMP1IF_Msk;
}

FlagStatus ANAC_COMPIF_CMP1IF_Chk(void)
{
	if (ANAC->COMPIF & ANAC_COMPIF_CMP1IF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

void ANAC_Deinit(void)
{
	ANAC->PDRCON = 0x00000003;
	ANAC->BORCON = 0x00000002;
	ANAC->SVDCFG = 0x00000008;
	ANAC->SVDCON = 0x00000000;
	//ANAC->SVDSIF = ;
	//ANAC->SVDALM = ;
	ANAC->FDETIE = 0x00000000;
	//ANAC->FDETIF = ;
	ANAC->ADCCON = 0x00000000;
	ANAC->ADCTRIM = 0x00000000;
	//ANAC->ADCDATA = ;
	//ANAC->ADCIF = ;
	ANAC->ADCINSEL = 0x00000000;
	ANAC->TRNGCON = 0x00000000;
	ANAC->COMP1CR = 0x00000000;
	ANAC->COMP2CR = 0x00000000;
	ANAC->COMPICR = 0x00000040;
	//ANAC->COMPIF = ;
}
//Code_End



/*SVD ��ʼ�����ú���*/
void ANAC_SVD_Init(ANAC_SVD_InitTypeDef* para)
{
	ANAC_SVDCFG_SVDMOD_Set(para->SVDMOD);	//SVD����ģʽѡ��
	ANAC_SVDCFG_SVDITVL_Set(para->SVDITVL);	//SVD��Ъʹ�ܼ������
	ANAC_SVDCFG_SVDLVL_Set(para->SVDLVL);	//SVD������ֵ����
	ANAC_SVDCFG_DFEN_Setable(para->DFEN);	//SVD�����˲����ã�SVDMODE=1ʱ������1��
	ANAC_SVDCFG_PFIE_Setable(para->PFIE);	//SVD��Դ�����ж�����
	ANAC_SVDCFG_PRIE_Setable(para->PRIE);	//SVD��Դ�ָ��ж�����
	ANAC_SVDCON_SVDTE_Setable(DISABLE);	//�رղ��Թ���
	ANAC_SVDCON_SVDEN_Setable(para->SVDEN);	//SVDʹ������
}

/*ADC ��ʼ�����ú���*/
void ANAC_ADC_Init(ANAC_ADC_InitTypeDef* para)
{
	ANAC_ADCTRIM_Write(para->ADC_TRIM);				//<��Ч�ο���ѹ��У�Ĵ���
	ANAC_ADCCON_ADC_VANA_EN_Set(para->ADC_VANA_EN);	//<�ڲ�ͨ�����ⲿͨ��ѡ��
	ANAC_ADCINSEL_BUFSEL_Set(para->BUFSEL);			//<ADC����ͨ��ѡ��
	ANAC_ADCINSEL_BUFBYP_Setable(para->BUFBYP);		//<ADC����Buffer Bypass��ADC����Buffer Bypass��ʹ��ADC�����ⲿ�ź�����ʱ���ر�bypass�� ʹ��ADC�����ڲ��ź�ʱ�����뽫��λ��1��bypass��
	ANAC_ADCINSEL_BUFEN_Setable(para->BUFEN);		//<ADC����ͨ��Bufferʹ�ܣ���������
	ANAC_ADCCON_ADC_IE_Setable(para->ADC_IE);		//<ADC�ж�ʹ��
	ANAC_ADCCON_ADC_EN_Setable(para->ADC_EN);		//<ADCʹ��
}

/*ADC ����ͨ�����ú���������*/
void ANAC_ADC_Channel_SetEx(uint8_t ChSel_def)
{
	switch( ChSel_def )
	{
		case CH_PTAT://�¶ȴ�����ͨ��
			ANAC_ADCCON_ADC_VANA_EN_Set(ANAC_ADCCON_ADC_VANA_EN_PTAT);	//����	
			ANAC_ADCTRIM_Write(const_adc_TrimT);						//���òο���ѹ
			ANAC_ADCINSEL_BUFBYP_Setable(ENABLE);	//�ڲ��źŲ�����bypassbuffer
			ANAC_ADCINSEL_BUFEN_Setable(ENABLE);	//
			break;

		case CH_VDD://��ԴVDDͨ��
			ANAC_ADCCON_ADC_VANA_EN_Set(ANAC_ADCCON_ADC_VANA_EN_VOLTAGE);	//��VDD��ѹ��ע��ADC����Ϊ4.5V��2.2mV*0x7FF��,����4.5V�ĵ�ѹ����0x7FF
			ANAC_ADCTRIM_Write(const_adc_TrimV);							//���òο���ѹ
			ANAC_ADCINSEL_BUFBYP_Setable(ENABLE);		//�ڲ�����
			ANAC_ADCINSEL_BUFEN_Setable(ENABLE);		//��ѹ
			ANAC_ADCINSEL_BUFSEL_Set(ANAC_ADCINSEL_BUFSEL_VDD);//vdd
			break;
		
		case CH_IN1://�ⲿ����ͨ��
		case CH_IN2:
		case CH_IN3:
		case CH_IN4:
		case CH_IN5:
		case CH_IN6:
		case CH_IN7:
		case CH_IN8:
			ANAC_ADCCON_ADC_VANA_EN_Set(ANAC_ADCCON_ADC_VANA_EN_VOLTAGE);	//���ѹ�������ѹ���ɸ���оƬVDD��ע��ADC����Ϊ4.5V��2.2mV*0x7FF��,����4.5V�ĵ�ѹ����0x7FF
			ANAC_ADCTRIM_Write(const_adc_TrimV);							//���òο���ѹ
			ANAC_ADCINSEL_BUFBYP_Setable(DISABLE);	//�ⲿ�źŲ������ر�bypassbuffer
			ANAC_ADCINSEL_BUFEN_Setable(ENABLE);	//��bufferen
			ANAC_ADCINSEL_BUFSEL_Set((ANAC_ADCINSEL_BUFSEL_ADC_IN1 + (ChSel_def - CH_IN1)));//����ͨ��ѡ��
			break;
		
		default:
			break;
	}
}


/*ADC ��ѹ���㺯��
	���룺ADֵ	 float�ͣ����㴦��ƽ��ֵ��
	�������ѹ@mV float��
*/
//�����ѹ����100mV����Խ����̫׼ȷ
//�����ѹ����4.4V����Խ����̫׼ȷ
//�����ѹ���ɳ�����Դ��ѹ
//�����ѹ���ɳ���4.5V
float ANAC_ADC_VoltageCalc(float fADCData)
{
	float fVolt = 0;
		
	if( (const_adc_Slope > 2000) && (const_adc_Slope < 2400) )
	{
		//ʹ�óɲ�����	
		//ADCֵ����Ϊ��ѹֵ
//		fVolt = fADCData*((const_adc_Slope/1000.0))+(float)const_adc_Offset/100.0;	
		if(fADCData <= 30)
			fVolt = 0;
		else if(fADCData <= 50)
			fVolt = (fADCData-30)*5;
		else if(fADCData <= 150)
			fVolt = (fADCData*(const_adc_Slope/1000.0));
		else if(fADCData <= 500)
			fVolt = (fADCData*0.98*(const_adc_Slope/1000.0));
		else
			fVolt = (fADCData*(const_adc_Slope/1000.0))+const_adc_Offset/100.0;	
	}
	else
	{
		//������ʱʹ��
		fVolt = (fADCData - 10)*2.174;
	}
	
	return fVolt;
}

/*ADC �¶ȼ��㺯��
	���룺ADֵ	 float�ͣ����㴦��ƽ��ֵ��
	���룺��Դ��ѹ uint08�� ��֧��3/5V����������ѹ����
	������¶�@�� float��
*/
float ANAC_ADC_TemperatureCalc(float fADCData ,uint8_t Vdd)
{
	float fTestADC, fTestT, fFa;
	float fTemperature;
		
	if( const_temp_TestA == 0x1E )
	{
		//ʹ���¶ȶ�������
		fTestT = const_temp_TestA+(float)(const_temp_TestB/0x80)*0.5;
		if( Vdd == 3 )
		{
			fTestADC = const_adc_Test  - const_T_Offset3V*const_TmpsH;
		}
		else
		{			
			fTestADC = const_adc_Test  - const_T_Offset5V*const_TmpsH;
		}
	}
	else
	{
		//������ʱʹ��
		fTestT = 30;
		fTestADC = 1500;
	}
	
	if( fADCData > (fTestADC-25) )	//����
		fFa = const_TmpsH;
	else
		fFa = const_TmpsL;

	fTemperature = (fADCData - fTestADC)/fFa + fTestT;
	
	return fTemperature;
}


/*COMP ��ʼ�����ú���*/
void ANAC_COMPx_Init(ANAC_COMPx_InitTypeDef* para)
{
	if(para->COMPx == 1)//�Ƚ���1
	{
		ANAC_COMP1CR_V1PSEL_Set(para->VxPSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMP1CR_V1NSEL_Set(para->VxNSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMPICR_CMP1SEL_Set(para->CMPxSEL);	//�Ƚ���x�ж�Դѡ��
		ANAC_COMPICR_CMP1IE_Setable(para->CMPxIE);	//����x�ж�ʹ��
		ANAC_COMPICR_CMP1DF_Setable(para->CMPxDF);	//�Ƚ���x�����˲�ʹ��
		ANAC_COMP1CR_CMP1EN_Setable(para->CMPxEN);	//�Ƚ���xʹ��
	}
	else		//�Ƚ���2
	{
		ANAC_COMP2CR_V2PSEL_Set(para->VxPSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMP2CR_V2NSEL_Set(para->VxNSEL);		//�Ƚ���x��������ѡ��
		ANAC_COMPICR_CMP2SEL_Set(para->CMPxSEL);	//�Ƚ���x�ж�Դѡ��
		ANAC_COMPICR_CMP2IE_Setable(para->CMPxIE);	//����x�ж�ʹ��
		ANAC_COMPICR_CMP2DF_Setable(para->CMPxDF);	//�Ƚ���x�����˲�ʹ��
		ANAC_COMP2CR_CMP2EN_Setable(para->CMPxEN);	//�Ƚ���xʹ��	
	}
}


/******END OF FILE****/



