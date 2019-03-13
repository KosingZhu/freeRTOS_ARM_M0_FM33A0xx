/**
  ******************************************************************************
  * @file    fm33a0xx_u7816.c
  * @author  FM33a0 Application Team
  * @version V2.0.1
  * @date    4-MAY-2017
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of....:
  *
*/
/* Includes ------------------------------------------------------------------*/

#include "FM33A0XX_u7816.h" 

//Code_Start
//2018-04-12-09-21-42
//FM33A0XX_Driver_Gen_V1.4

/* U7816ͨ������ʹ�ܿ��� ��غ��� */
void U7816x_U7816CTRL_TXEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816CTRL |= (U7816x_U7816CTRL_TXEN_Msk);
	}
	else
	{
		U7816x->U7816CTRL &= ~(U7816x_U7816CTRL_TXEN_Msk);
	}
}

FunState U7816x_U7816CTRL_TXEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816CTRL & (U7816x_U7816CTRL_TXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ������ʹ�ܿ��� ��غ��� */
void U7816x_U7816CTRL_RXEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816CTRL |= (U7816x_U7816CTRL_RXEN_Msk);
	}
	else
	{
		U7816x->U7816CTRL &= ~(U7816x_U7816CTRL_RXEN_Msk);
	}
}

FunState U7816x_U7816CTRL_RXEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816CTRL & (U7816x_U7816CTRL_RXEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ʱ��CLK���ʹ�ܿ��� ��غ��� */
void U7816x_U7816CTRL_CKOEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816CTRL |= (U7816x_U7816CTRL_CKOEN_Msk);
	}
	else
	{
		U7816x->U7816CTRL &= ~(U7816x_U7816CTRL_CKOEN_Msk);
	}
}

FunState U7816x_U7816CTRL_CKOEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816CTRL & (U7816x_U7816CTRL_CKOEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ�����ݷ���ǿ���������Զ���Ч���� ��غ��� */
void U7816x_U7816CTRL_HPUAT_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816CTRL |= (U7816x_U7816CTRL_HPUAT_Msk);
	}
	else
	{
		U7816x->U7816CTRL &= ~(U7816x_U7816CTRL_HPUAT_Msk);
	}
}

FunState U7816x_U7816CTRL_HPUAT_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816CTRL & (U7816x_U7816CTRL_HPUAT_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* U7816ͨ��ǿ����ʹ�ܿ��� ��غ��� */
void U7816x_U7816CTRL_HPUEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816CTRL |= (U7816x_U7816CTRL_HPUEN_Msk);
	}
	else
	{
		U7816x->U7816CTRL &= ~(U7816x_U7816CTRL_HPUEN_Msk);
	}
}

FunState U7816x_U7816CTRL_HPUEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816CTRL & (U7816x_U7816CTRL_HPUEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ERROR SIGNAL���ѡ�� ��غ��� */
void U7816x_U7816FRC_ERSW_Set(U7816x_Type* U7816x, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816x->U7816FRC;
	tmpreg &= ~(U7816x_U7816FRC_ERSW_Msk);
	tmpreg |= (SetValue & U7816x_U7816FRC_ERSW_Msk);
	U7816x->U7816FRC = tmpreg;
}

uint32_t U7816x_U7816FRC_ERSW_Get(U7816x_Type* U7816x)
{
	return (U7816x->U7816FRC & U7816x_U7816FRC_ERSW_Msk);
}

/* ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч�� ��غ��� */
void U7816x_U7816FRC_ERSGD_Set(U7816x_Type* U7816x, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816x->U7816FRC;
	tmpreg &= ~(U7816x_U7816FRC_ERSGD_Msk);
	tmpreg |= (SetValue & U7816x_U7816FRC_ERSGD_Msk);
	U7816x->U7816FRC = tmpreg;
}

uint32_t U7816x_U7816FRC_ERSGD_Get(U7816x_Type* U7816x)
{
	return (U7816x->U7816FRC & U7816x_U7816FRC_ERSGD_Msk);
}

/* BGT��block guard time������ ��غ��� */
void U7816x_U7816FRC_BGTEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816FRC |= (U7816x_U7816FRC_BGTEN_Msk);
	}
	else
	{
		U7816x->U7816FRC &= ~(U7816x_U7816FRC_BGTEN_Msk);
	}
}

FunState U7816x_U7816FRC_BGTEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816FRC & (U7816x_U7816FRC_BGTEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ƽ���������żУ�����ʱ�Զ��ط����� ��غ��� */
void U7816x_U7816FRC_REP_T_Set(U7816x_Type* U7816x, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816x->U7816FRC;
	tmpreg &= ~(U7816x_U7816FRC_REP_T_Msk);
	tmpreg |= (SetValue & U7816x_U7816FRC_REP_T_Msk);
	U7816x->U7816FRC = tmpreg;
}

uint32_t U7816x_U7816FRC_REP_T_Get(U7816x_Type* U7816x)
{
	return (U7816x->U7816FRC & U7816x_U7816FRC_REP_T_Msk);
}

/* ��żУ������ѡ�� ��غ��� */
void U7816x_U7816FRC_PAR_Set(U7816x_Type* U7816x, uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = U7816x->U7816FRC;
	tmpreg &= ~(U7816x_U7816FRC_PAR_Msk);
	tmpreg |= (SetValue & U7816x_U7816FRC_PAR_Msk);
	U7816x->U7816FRC = tmpreg;
}

uint32_t U7816x_U7816FRC_PAR_Get(U7816x_Type* U7816x)
{
	return (U7816x->U7816FRC & U7816x_U7816FRC_PAR_Msk);
}

/* Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu�� ��غ��� */
void U7816x_U7816FRC_FREN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816FRC |= (U7816x_U7816FRC_FREN_Msk);
	}
	else
	{
		U7816x->U7816FRC &= ~(U7816x_U7816FRC_FREN_Msk);
	}
}

FunState U7816x_U7816FRC_FREN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816FRC & (U7816x_U7816FRC_FREN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������������żУ���Ĵ���ʽѡ�� ��غ��� */
void U7816x_U7816FRC_TREPEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816FRC |= (U7816x_U7816FRC_TREPEN_Msk);
	}
	else
	{
		U7816x->U7816FRC &= ~(U7816x_U7816FRC_TREPEN_Msk);
	}
}

FunState U7816x_U7816FRC_TREPEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816FRC & (U7816x_U7816FRC_TREPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����������żУ���Ĵ���ʽѡ�� ��غ��� */
void U7816x_U7816FRC_RREPEN_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816FRC |= (U7816x_U7816FRC_RREPEN_Msk);
	}
	else
	{
		U7816x->U7816FRC &= ~(U7816x_U7816FRC_RREPEN_Msk);
	}
}

FunState U7816x_U7816FRC_RREPEN_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816FRC & (U7816x_U7816FRC_RREPEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ������������ʹ�� ��غ��� */
void U7816x_U7816FRC_DICONV_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816FRC |= (U7816x_U7816FRC_DICONV_Msk);
	}
	else
	{
		U7816x->U7816FRC &= ~(U7816x_U7816FRC_DICONV_Msk);
	}
}

FunState U7816x_U7816FRC_DICONV_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816FRC & (U7816x_U7816FRC_DICONV_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ����ʱ�����EGTʱ�䣨��ETUΪ��λ�� ��غ��� */
void U7816x_U7816EGT_Write(U7816x_Type* U7816x, uint32_t SetValue)
{
	U7816x->U7816EGT = (SetValue & U7816x_U7816EGT_TXEGT_Msk);
}

uint32_t U7816x_U7816EGT_Read(U7816x_Type* U7816x)
{
	return (U7816x->U7816EGT & U7816x_U7816EGT_TXEGT_Msk);
}

/* U7816ʱ�������Ƶ���ƼĴ��� ��غ��� */
void U7816x_U7816CLKDIV_Write(U7816x_Type* U7816x, uint32_t SetValue)
{
	U7816x->U7816CLKDIV = (SetValue & U7816x_U7816CLKDIV_CLKDIV_Msk);
}

uint32_t U7816x_U7816CLKDIV_Read(U7816x_Type* U7816x)
{
	return (U7816x->U7816CLKDIV & U7816x_U7816CLKDIV_CLKDIV_Msk);
}

/* U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ� ��غ��� */
void U7816x_U7816PDIV_Write(U7816x_Type* U7816x, uint32_t SetValue)
{
	U7816x->U7816PDIV = (SetValue & U7816x_U7816PDIV_PDIV_Msk);
}

uint32_t U7816x_U7816PDIV_Read(U7816x_Type* U7816x)
{
	return (U7816x->U7816PDIV & U7816x_U7816PDIV_PDIV_Msk);
}

/* U7816���ݽ��ջ���Ĵ��� ��غ��� */
uint32_t U7816x_U7816RXBUF_Read(U7816x_Type* U7816x)
{
	return (U7816x->U7816RXBUF & U7816x_U7816RXBUF_RXBUF_Msk);
}

/* U7816���ݷ��ͻ���Ĵ��� ��غ��� */
void U7816x_U7816TXBUF_Write(U7816x_Type* U7816x, uint32_t SetValue)
{
	U7816x->U7816TXBUF = (SetValue & U7816x_U7816TXBUF_TXBUF_Msk);
}

/* ���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ ��غ��� */
void U7816x_U7816IE_RXIE_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816IE |= (U7816x_U7816IE_RXIE_Msk);
	}
	else
	{
		U7816x->U7816IE &= ~(U7816x_U7816IE_RXIE_Msk);
	}
}

FunState U7816x_U7816IE_RXIE_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816IE & (U7816x_U7816IE_RXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ ��غ��� */
void U7816x_U7816IE_TXIE_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816IE |= (U7816x_U7816IE_TXIE_Msk);
	}
	else
	{
		U7816x->U7816IE &= ~(U7816x_U7816IE_TXIE_Msk);
	}
}

FunState U7816x_U7816IE_TXIE_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816IE & (U7816x_U7816IE_TXIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ ��غ��� */
void U7816x_U7816IE_LSIE_Setable(U7816x_Type* U7816x, FunState NewState)
{
	if (NewState == ENABLE)
	{
		U7816x->U7816IE |= (U7816x_U7816IE_LSIE_Msk);
	}
	else
	{
		U7816x->U7816IE &= ~(U7816x_U7816IE_LSIE_Msk);
	}
}

FunState U7816x_U7816IE_LSIE_Getable(U7816x_Type* U7816x)
{
	if (U7816x->U7816IE & (U7816x_U7816IE_LSIE_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* �����־���Ĵ������ó����������г���Ӳ����λ����U7816ERR����Ӧ�����־���� ��غ��� */
FlagStatus U7816x_U7816IF_ERRIF_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816IF & U7816x_U7816IF_ERRIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ���ͻ������ձ�־ ��غ��� */
void U7816x_U7816IF_TXIF_Clr(U7816x_Type* U7816x)
{
	U7816x->U7816IF = U7816x_U7816IF_TXIF_Msk;
}

FlagStatus U7816x_U7816IF_TXIF_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816IF & U7816x_U7816IF_TXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������ɱ�־ ��غ��� */
void U7816x_U7816IF_RXIF_Clr(U7816x_Type* U7816x)
{
	U7816x->U7816IF = U7816x_U7816IF_RXIF_Msk;
}

FlagStatus U7816x_U7816IF_RXIF_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816IF & U7816x_U7816IF_RXIF_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������żУ������־λ ��غ��� */
void U7816x_U7816ERR_TPARERR_Clr(U7816x_Type* U7816x)
{
	U7816x->U7816ERR = U7816x_U7816ERR_TPARERR_Msk;
}

FlagStatus U7816x_U7816ERR_TPARERR_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816ERR & U7816x_U7816ERR_TPARERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����������żУ������־λ ��غ��� */
void U7816x_U7816ERR_RPARERR_Clr(U7816x_Type* U7816x)
{
	U7816x->U7816ERR = U7816x_U7816ERR_RPARERR_Msk;
}

FlagStatus U7816x_U7816ERR_RPARERR_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816ERR & U7816x_U7816ERR_RPARERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ����֡��ʽ�����־λ ��غ��� */
void U7816x_U7816ERR_FRERR_Clr(U7816x_Type* U7816x)
{
	U7816x->U7816ERR = U7816x_U7816ERR_FRERR_Msk;
}

FlagStatus U7816x_U7816ERR_FRERR_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816ERR & U7816x_U7816ERR_FRERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ������������־λ ��غ��� */
void U7816x_U7816ERR_OVERR_Clr(U7816x_Type* U7816x)
{
	U7816x->U7816ERR = U7816x_U7816ERR_OVERR_Msk;
}

FlagStatus U7816x_U7816ERR_OVERR_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816ERR & U7816x_U7816ERR_OVERR_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* U7816�ӿڷ����˴����źţ����ڵȴ��Է��ط�����.״̬�����뷢�ʹ����ź�״̬ʱ��λ���յ�������ʼλ���߽��뷢��״̬ʱӲ������;
 ��غ��� */
FlagStatus U7816x_U7816STA_WAIT_RPT_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816STA & U7816x_U7816STA_WAIT_RPT_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������æ��־ ��غ��� */
FlagStatus U7816x_U7816STA_TXBUSY_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816STA & U7816x_U7816STA_TXBUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* ��������æ��־ ��غ��� */
FlagStatus U7816x_U7816STA_RXBUSY_Chk(U7816x_Type* U7816x)
{
	if (U7816x->U7816STA & U7816x_U7816STA_RXBUSY_Msk)
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}


void U7816x_Deinit(U7816x_Type* U7816x)
{
	U7816x->U7816CTRL = 0x00000000;
	U7816x->U7816FRC = 0x00000006;
	U7816x->U7816EGT = 0x00000000;
	U7816x->U7816CLKDIV = 0x00000003;
	U7816x->U7816PDIV = 0x00000173;
	//U7816x->U7816RXBUF = ;
	//U7816x->U7816TXBUF = ;
	U7816x->U7816IE = 0x00000000;
	//U7816x->U7816IF = 0x00000002;
	//U7816x->U7816ERR = 0x00000000;
	//U7816x->U7816STA = 0x00000000;
}
//Code_End


/* U7816����������ʼ������ */
void U7816_Init(U7816x_Type* U7816x, U7816_InitTypeDef* para)
{
	U7816x_U7816CTRL_TXEN_Setable(U7816x, para->TXEN);		//����ʹ��
	U7816x_U7816CTRL_RXEN_Setable(U7816x, para->RXEN);		//����ʹ��
	U7816x_U7816CTRL_CKOEN_Setable(U7816x, para->CKOEN);		//U7816ʱ��CLK���ʹ�ܿ���
	U7816x_U7816CTRL_HPUAT_Setable(U7816x, para->HPUAT);		//U7816ͨ�����ݷ���ǿ���������Զ���Ч����
	U7816x_U7816CTRL_HPUEN_Setable(U7816x, para->HPUEN);		//U7816ͨ��ǿ����ʹ�ܿ���
	
	U7816x_U7816FRC_ERSW_Set(U7816x, para->ERSW);		//ERROR SIGNAL���ѡ��
	U7816x_U7816FRC_ERSGD_Set(U7816x, para->ERSGD);		//ERROR SIGNAL��GUARDTIME���ѡ�񣨽��ڷ���ʱ��Ч��
	U7816x_U7816FRC_BGTEN_Setable(U7816x, para->BGTEN);		//BGT��block guard time������
	U7816x_U7816FRC_REP_T_Set(U7816x, para->REP_T);		//���ƽ���������żУ�����ʱ�Զ��ط�����
	U7816x_U7816FRC_PAR_Set(U7816x, para->PAR);		//��żУ������ѡ��
	U7816x_U7816FRC_FREN_Setable(U7816x, para->FREN);		//Guard Time���ȿ���λ������ʱ�ϸ���Э��2etu��
	U7816x_U7816FRC_TREPEN_Setable(U7816x, para->TREPEN);		//������������żУ���Ĵ���ʽѡ��
	U7816x_U7816FRC_RREPEN_Setable(U7816x, para->RREPEN);		//����������żУ���Ĵ���ʽѡ��
	U7816x_U7816FRC_DICONV_Setable(U7816x, para->DICONV);		//������������ʹ��
	
	U7816x_U7816EGT_Write(U7816x, para->TXEGT);		//����ʱ�����EGTʱ�䣨��ETUΪ��λ��
	U7816x_U7816CLKDIV_Write(U7816x, para->CLKDIV);		//U7816ʱ�������Ƶ���ƼĴ���
	U7816x_U7816PDIV_Write(U7816x, para->PDIV);		//U7816Ԥ��Ƶ���ƼĴ���������7816ͨ�ŷ�Ƶ�ȣ������ʣ�
	
	U7816x_U7816IE_RXIE_Setable(U7816x, para->RXIE);		//���ݽ����ж�ʹ��λ����ӦRX_FLAG�жϱ�־λ
	U7816x_U7816IE_TXIE_Setable(U7816x, para->TXIE);		//���ݷ����ж�ʹ��λ����ӦTX_FLAG�жϱ�־λ
	U7816x_U7816IE_LSIE_Setable(U7816x, para->LSIE);		//��·״̬�ж�ʹ��λ����ӦERROR_FLAG�жϱ�־λ
}

/******END OF FILE****/
