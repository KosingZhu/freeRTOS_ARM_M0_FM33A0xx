#include "FM33A0XX.h"
#include "define_all.h"


void softReset(void)
{
	RCC->SOFTRST = 0x5C5CAABB;
}


uint32 readHardFaultReg(void)
{
	return (SCU->HDFFLAG);
}


uint32 readRSTFLAG(void)
{
	return (RCC->RSTFLAG);
}

void clrRSFLAG(uint32 flag)
{
	RCC->RSTFLAG = flag;
}

void feedDog(void)
{
	IWDT_Clr();  
}


void HardFault_Handler(void)
{
	while(1)
    {
        softReset();
	}
}





