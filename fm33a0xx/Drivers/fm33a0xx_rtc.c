/**
  ******************************************************************************
  * @file    fm33a0xx_rtc.c
  * @author  FM33a0xx Application Team
  * @version V2.0.1
  * @date    15-1-2018
  * @brief   This file provides firmware functions to manage the following 
  *          functionalities of RTC peripheral:
  *
*/

/* Includes ------------------------------------------------------------------*/
#include "fm33A0xx_rtc.h"  

/** @addtogroup fm33a0xx_StdPeriph_Driver
  * @{
  */

/** @defgroup RTC 
  * @brief RCC driver modules
  * @{
  */ 

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
//Code_Start
//2018-04-02-13-22-12
//FM33A0XX_Driver_Gen_V1.4

/* RTCдʹ�ܼĴ��� ��غ��� */
void RTC_RTCWE_Write(uint32_t SetValue)
{
	RTC->RTCWE = (SetValue);
}

/* BCDʱ����Ĵ��� ��غ��� */
void RTC_BCDSEC_Write(uint32_t SetValue)
{
	RTC->BCDSEC = (SetValue & RTC_BCDSEC_BCDSEC_Msk);
}

uint32_t RTC_BCDSEC_Read(void)
{
	return (RTC->BCDSEC & RTC_BCDSEC_BCDSEC_Msk);
}

/* BCDʱ����ӼĴ��� ��غ��� */
void RTC_BCDMIN_Write(uint32_t SetValue)
{
	RTC->BCDMIN = (SetValue & RTC_BCDMIN_BCDMIN_Msk);
}

uint32_t RTC_BCDMIN_Read(void)
{
	return (RTC->BCDMIN & RTC_BCDMIN_BCDMIN_Msk);
}

/* BCDʱ��Сʱ�Ĵ��� ��غ��� */
void RTC_BCDHOUR_Write(uint32_t SetValue)
{
	RTC->BCDHOUR = (SetValue & RTC_BCDHOUR_BCDHOUR_Msk);
}

uint32_t RTC_BCDHOUR_Read(void)
{
	return (RTC->BCDHOUR & RTC_BCDHOUR_BCDHOUR_Msk);
}

/* BCDʱ����Ĵ��� ��غ��� */
void RTC_BCDDATE_Write(uint32_t SetValue)
{
	RTC->BCDDATE = (SetValue & RTC_BCDDATE_BCDDATE_Msk);
}

uint32_t RTC_BCDDATE_Read(void)
{
	return (RTC->BCDDATE & RTC_BCDDATE_BCDDATE_Msk);
}

/* BCDʱ�����ڼĴ��� ��غ��� */
void RTC_BCDWEEK_Write(uint32_t SetValue)
{
	RTC->BCDWEEK = (SetValue & RTC_BCDWEEK_BCDWEEK_Msk);
}

uint32_t RTC_BCDWEEK_Read(void)
{
	return (RTC->BCDWEEK & RTC_BCDWEEK_BCDWEEK_Msk);
}

/* BCDʱ���¼Ĵ��� ��غ��� */
void RTC_BCDMONTH_Write(uint32_t SetValue)
{
	RTC->BCDMONTH = (SetValue & RTC_BCDMONTH_BCDMONTH_Msk);
}

uint32_t RTC_BCDMONTH_Read(void)
{
	return (RTC->BCDMONTH & RTC_BCDMONTH_BCDMONTH_Msk);
}

/* BCDʱ����Ĵ��� ��غ��� */
void RTC_BCDYEAR_Write(uint32_t SetValue)
{
	RTC->BCDYEAR = (SetValue & RTC_BCDYEAR_BCDYEAR_Msk);
}

uint32_t RTC_BCDYEAR_Read(void)
{
	return (RTC->BCDYEAR & RTC_BCDYEAR_BCDYEAR_Msk);
}

/* ���ӵ�Сʱ��ֵ ��غ��� */
void RTC_ALARM_ALARMHOUR_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_ALARMHOUR_Msk);
	tmpreg |= (SetValue & RTC_ALARM_ALARMHOUR_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_ALARMHOUR_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_ALARMHOUR_Msk);
}

/* ���ӵķ���ֵ ��غ��� */
void RTC_ALARM_ALARMMIN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_ALARMMIN_Msk);
	tmpreg |= (SetValue & RTC_ALARM_ALARMMIN_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_ALARMMIN_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_ALARMMIN_Msk);
}

/* ���ӵ�����ֵ ��غ��� */
void RTC_ALARM_ALARMSEC_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ALARM;
	tmpreg &= ~(RTC_ALARM_ALARMSEC_Msk);
	tmpreg |= (SetValue & RTC_ALARM_ALARMSEC_Msk);
	RTC->ALARM = tmpreg;
}

uint32_t RTC_ALARM_ALARMSEC_Get(void)
{
	return (RTC->ALARM & RTC_ALARM_ALARMSEC_Msk);
}

/* Ƶ�����ѡ���ź� ��غ��� */
void RTC_FSEL_FSEL_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->FSEL;
	tmpreg &= ~(RTC_FSEL_FSEL_Msk);
	tmpreg |= (SetValue & RTC_FSEL_FSEL_Msk);
	RTC->FSEL = tmpreg;
}

uint32_t RTC_FSEL_FSEL_Get(void)
{
	return (RTC->FSEL & RTC_FSEL_FSEL_Msk);
}

/* LTBC����������ֵ ��غ��� */
void RTC_ADJUST_Write(uint32_t SetValue)
{
	RTC->ADJUST = (SetValue & RTC_ADJUST_ADJUST_Msk);
}

uint32_t RTC_ADJUST_Read(void)
{
	return (RTC->ADJUST & RTC_ADJUST_ADJUST_Msk);
}

/* LTBC�������� ��غ��� */
void RTC_ADSIGN_ADSIGN_Set(uint32_t SetValue)
{
	uint32_t tmpreg;
	tmpreg = RTC->ADSIGN;
	tmpreg &= ~(RTC_ADSIGN_ADSIGN_Msk);
	tmpreg |= (SetValue & RTC_ADSIGN_ADSIGN_Msk);
	RTC->ADSIGN = tmpreg;
}

uint32_t RTC_ADSIGN_ADSIGN_Get(void)
{
	return (RTC->ADSIGN & RTC_ADSIGN_ADSIGN_Msk);
}

/* �����Уʹ���ź� ��غ��� */
void RTC_PR1SEN_PR1SEN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->PR1SEN |= (RTC_PR1SEN_PR1SEN_Msk);
	}
	else
	{
		RTC->PR1SEN &= ~(RTC_PR1SEN_PR1SEN_Msk);
	}
}

FunState RTC_PR1SEN_PR1SEN_Getable(void)
{
	if (RTC->PR1SEN & (RTC_PR1SEN_PR1SEN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ���������ֵ����256HzΪ���ڼ���������3.9ms ��غ��� */
void RTC_MSECCNT_Write(uint32_t SetValue)
{
	RTC->MSECCNT = (SetValue & RTC_MSECCNT_MSCNT_Msk);
}

uint32_t RTC_MSECCNT_Read(void)
{
	return (RTC->MSECCNT & RTC_MSECCNT_MSCNT_Msk);
}

/* PB5������ʱ�������ʹ��λ���޸�λֵ����������ϵ����г�ʼ�� ��غ��� */
void RTC_STAMPEN_STAMP1EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->STAMPEN |= (RTC_STAMPEN_STAMP1EN_Msk);
	}
	else
	{
		RTC->STAMPEN &= ~(RTC_STAMPEN_STAMP1EN_Msk);
	}
}

FunState RTC_STAMPEN_STAMP1EN_Getable(void)
{
	if (RTC->STAMPEN & (RTC_STAMPEN_STAMP1EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* PB4������ʱ�������ʹ��λ���޸�λֵ����������ϵ����г�ʼ�� ��غ��� */
void RTC_STAMPEN_STAMP0EN_Setable(FunState NewState)
{
	if (NewState == ENABLE)
	{
		RTC->STAMPEN |= (RTC_STAMPEN_STAMP0EN_Msk);
	}
	else
	{
		RTC->STAMPEN &= ~(RTC_STAMPEN_STAMP0EN_Msk);
	}
}

FunState RTC_STAMPEN_STAMP0EN_Getable(void)
{
	if (RTC->STAMPEN & (RTC_STAMPEN_STAMP0EN_Msk))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* ��⵽PB4������ʱ���ʱ�������� ��غ��� */
uint32_t RTC_CLKSTAMP0R_Read(void)
{
	return (RTC->CLKSTAMP0R);
}

/* ��⵽PB4������ʱ��������������� ��غ��� */
uint32_t RTC_CALSTAMP0R_Read(void)
{
	return (RTC->CALSTAMP0R);
}

/* ��⵽PB4�½���ʱ���ʱ�������� ��غ��� */
uint32_t RTC_CLKSTAMP0F_Read(void)
{
	return (RTC->CLKSTAMP0F);
}

/* ��⵽PB4�½���ʱ��������������� ��غ��� */
uint32_t RTC_CALSTAMP0F_Read(void)
{
	return (RTC->CALSTAMP0F);
}

/* ��⵽PB5������ʱ���ʱ�������� ��غ��� */
uint32_t RTC_CLKSTAMP1R_Read(void)
{
	return (RTC->CLKSTAMP1R);
}

/* ��⵽PB5������ʱ��������������� ��غ��� */
uint32_t RTC_CALSTAMP1R_Read(void)
{
	return (RTC->CALSTAMP1R);
}

/* ��⵽PB5�½���ʱ���ʱ�������� ��غ��� */
uint32_t RTC_CLKSTAMP1F_Read(void)
{
	return (RTC->CLKSTAMP1F);
}

/* ��⵽PB5�½���ʱ��������������� ��غ��� */
uint32_t RTC_CALSTAMP1F_Read(void)
{
	return (RTC->CALSTAMP1F);
}


void RTC_Deinit(void)
{
	RTC->RTCWE = 0x00000000;
	RTC->RTCIE = 0x00000000;
	//RTC->RTCIF = ;
	//RTC->BCDSEC = ;
	//RTC->BCDMIN = ;
	//RTC->BCDHOUR = ;
	//RTC->BCDDATE = ;
	//RTC->BCDWEEK = ;
	//RTC->BCDMONTH = ;
	//RTC->BCDYEAR = ;
	RTC->ALARM = 0x00000000;
	RTC->FSEL = 0x00000000;
	//RTC->ADJUST = ;
	//RTC->ADSIGN = ;
	RTC->PR1SEN = 0x00000000;
	//RTC->MSECCNT = ;
	RTC->STAMPEN = 0x00000000;
	RTC->CLKSTAMP0R = 0x00000000;
	RTC->CALSTAMP0R = 0x00000000;
	RTC->CLKSTAMP0F = 0x00000000;
	RTC->CALSTAMP0F = 0x00000000;
	RTC->CLKSTAMP1R = 0x00000000;
	RTC->CALSTAMP1R = 0x00000000;
	RTC->CLKSTAMP1F = 0x00000000;
	RTC->CALSTAMP1F = 0x00000000;
}
//Code_End

/* RTC�ж�ʹ�ܼĴ��� ��غ��� */
void RTC_RTCIE_SetableEx(FunState NewState, uint32_t ie_def)
{
	if (NewState == ENABLE)
	{
		RTC->RTCIE |= (ie_def);
	}
	else
	{
		RTC->RTCIE &= ~(ie_def);
	}
}

FunState RTC_RTCIE_GetableEx(uint32_t ie_def)
{
	if (RTC->RTCIE & (ie_def))
	{
		return ENABLE;
	}
	else
	{
		return DISABLE;
	}
}

/* RTC�жϱ�־ ��غ��� */
void RTC_RTCIF_ClrEx(uint32_t if_def)
{
	RTC->RTCIF = (if_def);
}

FlagStatus RTC_RTCIF_ChkEx(uint32_t if_def)
{
	if (RTC->RTCIF & (if_def))
	{
		return SET;
	}
	else
	{
		return RESET;
	}
}

/* RTC����ʱ�� *///ע��Ҫ�ȴ�д������������ʱ��
void RTC_TimeDate_SetEx(RTC_TimeDateTypeDef* para)
{
	RTC_BCDSEC_Write((uint32_t)para->Second);
	RTC_BCDMIN_Write((uint32_t)para->Minute);
	RTC_BCDHOUR_Write((uint32_t)para->Hour);
	RTC_BCDDATE_Write((uint32_t)para->Date);
	RTC_BCDMONTH_Write((uint32_t)para->Month);
	RTC_BCDYEAR_Write((uint32_t)para->Year);
	RTC_BCDWEEK_Write((uint32_t)para->Week);	
}

/* RTC��ȡʱ�� */
void RTC_TimeDate_GetEx(RTC_TimeDateTypeDef* para)
{
	para->Second = RTC_BCDSEC_Read();
	para->Minute = RTC_BCDMIN_Read();
	para->Hour = RTC_BCDHOUR_Read();
	para->Date = RTC_BCDDATE_Read();
	para->Month = RTC_BCDMONTH_Read();
	para->Year = RTC_BCDYEAR_Read();
	para->Week = RTC_BCDWEEK_Read();	
}

/* ����ʱ������ */
void RTC_AlarmTime_SetEx(RTC_AlarmTmieTypeDef* para)
{
	RTC_ALARM_ALARMSEC_Set(((uint32_t)para->Second<<RTC_ALARM_ALARMSEC_Pos));
	RTC_ALARM_ALARMMIN_Set(((uint32_t)para->Minute<<RTC_ALARM_ALARMMIN_Pos));
	RTC_ALARM_ALARMHOUR_Set(((uint32_t)para->Hour<<RTC_ALARM_ALARMHOUR_Pos));
}

/* ����ʱ���ȡ */
void RTC_AlarmTime_GetEx(RTC_AlarmTmieTypeDef* para)
{
	para->Second = (RTC_ALARM_ALARMSEC_Get())>>RTC_ALARM_ALARMSEC_Pos;
	para->Minute = (RTC_ALARM_ALARMMIN_Get())>>RTC_ALARM_ALARMMIN_Pos;
	para->Hour = (RTC_ALARM_ALARMHOUR_Get())>>RTC_ALARM_ALARMHOUR_Pos;
}	
	
/* ʱ������ݶ�ȡ */
void RTC_CLKSTAMPxx_GetEx(uint8_t StampType_def, RTC_StampTmieTypeDef* para)
{
	uint8_t i;
	__IO uint32_t *p_reg = 0;
	p_reg = &(RTC->CLKSTAMP0R);
	
	if(StampType_def <= 3)
	{
		for(i=0; i<StampType_def*2; i++)
		{
			p_reg++;
		}
		para->Second = 0xFF&(p_reg[0]>>0);
		para->Minute = 0xFF&(p_reg[0]>>8);
		para->Hour = 0xFF&(p_reg[0]>>16);
		para->Date = 0xFF&(p_reg[1]>>0);
		para->Month = 0xFF&(p_reg[1]>>16);
		para->Year = 0xFF&(p_reg[1]>>24);
		para->Week = 0xFF&(p_reg[1]>>8);
	}
}

/* RTC ʱ�Ӿ��Ȳ������� */
/*
	���� float�Ͳ����ppm
*/
void RTC_Trim_Proc(float err_ppm)
{
	float Rtcadj;
	Rtcadj = err_ppm*4.194304;//ת��Ϊ��Уֵ
		
	if( Rtcadj >= 0 ) 
	{
		RTC_ADJUST_Write((uint32_t)(Rtcadj+0.5));
		RTC_ADSIGN_ADSIGN_Set(RTC_ADSIGN_ADSIGN_PLUS);
	}			
	else              
	{
		RTC_ADJUST_Write((uint32_t)((Rtcadj-0.5)*-1.0));
		RTC_ADSIGN_ADSIGN_Set(RTC_ADSIGN_ADSIGN_MINUS);
	}    
}

/******END OF FILE****/




