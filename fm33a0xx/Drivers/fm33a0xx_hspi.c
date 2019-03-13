/**
  ******************************************************************************
  * @file    fm33a0xx_spi.c
  * @author  
  * @version V2.0.1
  * @date    
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of SPI:           
  *           
  ******************************************************************************  
  */ 

/* Includes ------------------------------------------------------------------*/ 

#include "fm33A0xx_hspi.h"  



/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

//Code_Start
//2018-04-02-13-22-40
//FM33A0XX_Driver_Gen_V1.4

/* Masterģʽ�£����ڵ������ղ�����λ��Slaveģʽ�£����ڵ���������λ ��غ��� */
void HSPI_SPICR1_DELAY_CFG_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_DELAY_CFG_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_DELAY_CFG_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_DELAY_CFG_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_DELAY_CFG_Msk);
}

/* MASTER/SLAVEģʽѡ�� ��غ��� */
void HSPI_SPICR1_MM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_MM_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_MM_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_MM_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_MM_Msk);
}

void HSPI_SPICR1_WAIT_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_WAIT_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_WAIT_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_WAIT_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_WAIT_Msk);
}

/* MASTERģʽ���������� ��غ��� */
void HSPI_SPICR1_BAUD_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_BAUD_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_BAUD_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_BAUD_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_BAUD_Msk);
}

/* ֡��ʽ ��غ��� */
void HSPI_SPICR1_LSBF_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_LSBF_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_LSBF_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_LSBF_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_LSBF_Msk);
}

/* ʱ�Ӽ���ѡ�� ��غ��� */
void HSPI_SPICR1_CPHOL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_CPHOL_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_CPHOL_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_CPHOL_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_CPHOL_Msk);
}

/* ʱ����λѡ�� ��غ��� */
void HSPI_SPICR1_CPHA_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR1;
	tmpreg &= ~(HSPI_SPICR1_CPHA_Msk);
	tmpreg |= (SetValue & HSPI_SPICR1_CPHA_Msk);
	HSPI->SPICR1 = tmpreg;
}

uint32_t HSPI_SPICR1_CPHA_Get(void)
{
	return (HSPI->SPICR1 & HSPI_SPICR1_CPHA_Msk);
}

/* Slave����ܽ��˲�ʹ�ܣ�SSN/SCK/MOSI�� ��غ��� */
void HSPI_SPICR2_FLTEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPICR2 |= (HSPI_SPICR2_FLTEN_Msk);
	}
	else
	{
		HSPI->SPICR2 &= ~(HSPI_SPICR2_FLTEN_Msk);
	}
}

FunState HSPI_SPICR2_FLTEN_Getable(void)
{
	if (HSPI->SPICR2 & (HSPI_SPICR2_FLTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Masterģʽ��SSN����ģʽѡ�� ��غ��� */
void HSPI_SPICR2_SSNM_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_SSNM_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_SSNM_Msk);
	HSPI->SPICR2 = tmpreg;
}

uint32_t HSPI_SPICR2_SSNM_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_SSNM_Msk);
}

/* TXONLYӲ���Զ���յ�ʹ�� ��غ��� */
void HSPI_SPICR2_TXO_AC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_TXO_AC_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_TXO_AC_Msk);
	HSPI->SPICR2 = tmpreg;
}

uint32_t HSPI_SPICR2_TXO_AC_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_TXO_AC_Msk);
}

/* TXONLY����λ ��غ��� */
void HSPI_SPICR2_TXO_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPICR2 |= (HSPI_SPICR2_TXO_Msk);
	}
	else
	{
		HSPI->SPICR2 &= ~(HSPI_SPICR2_TXO_Msk);
	}
}

FunState HSPI_SPICR2_TXO_Getable(void)
{
	if (HSPI->SPICR2 & (HSPI_SPICR2_TXO_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Masterģʽ�£��������ͨ����λ����SSN�����ƽ ��غ��� */
void HSPI_SPICR2_SSN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_SSN_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_SSN_Msk);
	HSPI->SPICR2 = tmpreg;
}

uint32_t HSPI_SPICR2_SSN_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_SSN_Msk);
}

/* Masterģʽ�£�SSN�Ŀ��Ʒ�ʽ ��غ��� */
void HSPI_SPICR2_SSNSEN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = HSPI->SPICR2;
	tmpreg &= ~(HSPI_SPICR2_SSNSEN_Msk);
	tmpreg |= (SetValue & HSPI_SPICR2_SSNSEN_Msk);
	HSPI->SPICR2 = tmpreg;
}

uint32_t HSPI_SPICR2_SSNSEN_Get(void)
{
	return (HSPI->SPICR2 & HSPI_SPICR2_SSNSEN_Msk);
}

/* HSPIʹ�� ��غ��� */
void HSPI_SPICR2_HSPIEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPICR2 |= (HSPI_SPICR2_HSPIEN_Msk);
	}
	else
	{
		HSPI->SPICR2 &= ~(HSPI_SPICR2_HSPIEN_Msk);
	}
}

FunState HSPI_SPICR2_HSPIEN_Getable(void)
{
	if (HSPI->SPICR2 & (HSPI_SPICR2_HSPIEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void HSPI_SPICR3_TXBFC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_TXBFC_Msk;
}

void HSPI_SPICR3_RXBFC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_RXBFC_Msk;
}

void HSPI_SPICR3_MERRC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_MERRC_Msk;
}

void HSPI_SPICR3_SERRC_Clr(void)
{
	HSPI->SPICR3 = HSPI_SPICR3_SERRC_Msk;
}

void HSPI_SPIIE_ERRIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPIIE |= (HSPI_SPIIE_ERRIE_Msk);
	}
	else
	{
		HSPI->SPIIE &= ~(HSPI_SPIIE_ERRIE_Msk);
	}
}

FunState HSPI_SPIIE_ERRIE_Getable(void)
{
	if (HSPI->SPIIE & (HSPI_SPIIE_ERRIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void HSPI_SPIIE_TXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPIIE |= (HSPI_SPIIE_TXIE_Msk);
	}
	else
	{
		HSPI->SPIIE &= ~(HSPI_SPIIE_TXIE_Msk);
	}
}

FunState HSPI_SPIIE_TXIE_Getable(void)
{
	if (HSPI->SPIIE & (HSPI_SPIIE_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

void HSPI_SPIIE_RXIE_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		HSPI->SPIIE |= (HSPI_SPIIE_RXIE_Msk);
	}
	else
	{
		HSPI->SPIIE &= ~(HSPI_SPIIE_RXIE_Msk);
	}
}

FunState HSPI_SPIIE_RXIE_Getable(void)
{
	if (HSPI->SPIIE & (HSPI_SPIIE_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* Master Error��־ ��غ��� */
FlagStatus HSPI_SPIIF_MERR_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_MERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* Slave Error��־ ��غ��� */
FlagStatus HSPI_SPIIF_SERR_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_SERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ջ�����������д1���� ��غ��� */
void HSPI_SPIIF_RXCOL_Clr(void)
{
	HSPI->SPIIF = HSPI_SPIIF_RXCOL_Msk;
}

FlagStatus HSPI_SPIIF_RXCOL_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_RXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ�����������д1���� ��غ��� */
void HSPI_SPIIF_TXCOL_Clr(void)
{
	HSPI->SPIIF = HSPI_SPIIF_TXCOL_Msk;
}

FlagStatus HSPI_SPIIF_TXCOL_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_TXCOL_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* HSPI���б�־��ֻ�� ��غ��� */
FlagStatus HSPI_SPIIF_BUSY_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_BUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* TX Buffer Empty��־λ ��غ��� */
FlagStatus HSPI_SPIIF_TXBE_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_TXBE_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RX Buffer Full��־λ ��غ��� */
FlagStatus HSPI_SPIIF_RXBF_Chk(void)
{
	if (HSPI->SPIIF & HSPI_SPIIF_RXBF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* SPI���ͻ��� ��غ��� */
void HSPI_SPITXBUF_Write(uint32_t SetValue)
{
	HSPI->SPITXBUF = (SetValue & HSPI_SPITXBUF_TXBUF_Msk);
}

uint32_t HSPI_SPITXBUF_Read(void)
{
	return (HSPI->SPITXBUF & HSPI_SPITXBUF_TXBUF_Msk);
}

/* SPI���ջ��� ��غ��� */
void HSPI_SPIRXBUF_Write(uint32_t SetValue)
{
	HSPI->SPIRXBUF = (SetValue & HSPI_SPIRXBUF_RXBUF_Msk);
}

uint32_t HSPI_SPIRXBUF_Read(void)
{
	return (HSPI->SPIRXBUF & HSPI_SPIRXBUF_RXBUF_Msk);
}


void HSPI_Deinit(void)
{
	HSPI->SPICR1 = 0x00000108;
	HSPI->SPICR2 = 0x00000054;
	HSPI->SPICR3 = 0x00000000;
	HSPI->SPIIE = 0x00000000;
	//HSPI->SPIIF = 0x00000002;
	//HSPI->SPITXBUF = 0x00000000;
	//HSPI->SPIRXBUF = 0x00000000;
}
//Code_End

//Code_Start_HandBy
void HSPI_Master_Init(HSPI_Master_SInitTypeDef* para)
{
	HSPI_Master_InitTypeDef init_para;
	HSPI_Deinit();

	init_para.DELAY_CFG = HSPI_SPICR1_DELAY_CFG_MASTER_NO_DELAY;
	init_para.WAIT = HSPI_SPICR1_WAIT_WAIT_1;
	init_para.BAUD_RATE = para->BAUD_RATE;
	init_para.LSBF = para->LSBF;
	init_para.CPHOL = para->CPHOL;
	init_para.CPHA = para->CPHA;
	init_para.SSNM = para->SSNM;
	init_para.TXO = DISABLE;
	init_para.TXO_AC = HSPI_SPICR2_TXO_AC_CLR_AT_CLOSE;
	init_para.SSNSEN = para->SSNSEN;

	init_para.HSPIEN = DISABLE;
	init_para.ERRIE = DISABLE;
	init_para.TXIE = DISABLE;
	init_para.RXIE = DISABLE;

	HSPI_SPICR1_DELAY_CFG_Set(init_para.DELAY_CFG);
	HSPI_SPICR1_WAIT_Set(init_para.WAIT);
	HSPI_SPICR1_BAUD_Set(init_para.BAUD_RATE);
	HSPI_SPICR1_LSBF_Set(init_para.LSBF);
	HSPI_SPICR1_CPHOL_Set(init_para.CPHOL);
	HSPI_SPICR1_CPHA_Set(init_para.CPHA);
	HSPI_SPICR2_SSNM_Set(init_para.SSNM);
	HSPI_SPICR2_TXO_Setable(init_para.TXO);
	HSPI_SPICR2_TXO_AC_Set(init_para.TXO_AC);
	HSPI_SPICR2_SSNSEN_Set(init_para.SSNSEN);

	HSPI_SPICR1_MM_Set(HSPI_SPICR1_MM_MASTER);//���ó���ģʽ
}


void HSPI_Slave_Init(HSPI_Slave_SInitTypeDef* para)
{
	HSPI_Slave_InitTypeDef init_para;
	HSPI_Deinit();

	init_para.DELAY_CFG = HSPI_SPICR1_DELAY_CFG_SLAVE_NORMAL;
	init_para.FLTEN = ENABLE;
	init_para.LSBF = para->LSBF;
	init_para.CPHOL = para->CPHOL;
	init_para.CPHA = para->CPHA;
	init_para.TXO = DISABLE;
	init_para.TXO_AC = HSPI_SPICR2_TXO_AC_CLR_AT_CLOSE;

	init_para.HSPIEN = DISABLE;
	init_para.ERRIE = DISABLE;
	init_para.TXIE = DISABLE;
	init_para.RXIE = DISABLE;

	HSPI_SPICR1_DELAY_CFG_Set(init_para.DELAY_CFG);
	HSPI_SPICR2_FLTEN_Setable(init_para.FLTEN);
	HSPI_SPICR1_LSBF_Set(init_para.LSBF);
	HSPI_SPICR1_CPHOL_Set(init_para.CPHOL);
	HSPI_SPICR1_CPHA_Set(init_para.CPHA);
	HSPI_SPICR2_TXO_Setable(init_para.TXO);
	HSPI_SPICR2_TXO_AC_Set(init_para.TXO_AC);
	
	HSPI_SPICR1_MM_Set(HSPI_SPICR1_MM_SLAVE);//���óɴ�ģʽ
}

void HSPI_SSN_Set_Low(void)//������
{
	HSPI_SPICR2_SSN_Set(HSPI_SPICR2_SSN_LOW);//����SSN�ź�
}

void HSPI_SSN_Set_High(void)//������
{
	HSPI_SPICR2_SSN_Set(HSPI_SPICR2_SSN_HIGH);//����SSN�ź�
}

unsigned char HSPI_Recv_Byte(void)//HSPI����һ�ֽ�
{
	return HSPI_SPIRXBUF_Read();
}
void HSPI_Send_Byte(unsigned char data)//HSPI����һ�ֽ�
{
	HSPI_SPITXBUF_Write(data);
}

unsigned char HSPI_RW_Byte(unsigned char data)//SPI���Ͳ�����һ�ֽ�
{
    unsigned char rx_data;

    while(1)
    {
    	if (HSPI_SPIIF_TXBE_Chk() == SET)
		{
			break;
		}		
    }
    HSPI_Send_Byte(data);

    while(1)
    {
    	if (HSPI_SPIIF_RXBF_Chk() == SET)
        {
            break;
        }
    }
    rx_data = HSPI_Recv_Byte();
    return rx_data;
}



/******END OF FILE****/

