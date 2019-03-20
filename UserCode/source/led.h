#ifndef _led_H
#define _led_H


#define ALARM_PULSE_PORT 		GPIOG			//DEBUG引脚复用
#define ALARM_PULSE_PIN 		GPIO_Pin_9

#define BACKLIGHT_PORT			GPIOE
#define BACKLIGHT_PIN			GPIO_Pin_2


#define KEY_LED_PORT			GPIOG
#define KEY_LED_PIN             GPIO_Pin_6



#define ALARM_R_PORT			GPIOD	//	4
#define ALARM_R_PIN				GPIO_Pin_0


#define ALARM_G_PORT			GPIOB	//6
#define ALARM_G_PIN				GPIO_Pin_1

//#define ALARM_R_REG_DATA        PEDATA
//#define ALARM_G_REG_DATA  		PGDATA




//backlight led
#define BACKLIGHT_ON          GPIO_ResetBits(BACKLIGHT_PORT, BACKLIGHT_PIN)
#define BACKLIGHT_OFF         GPIO_SetBits(BACKLIGHT_PORT, BACKLIGHT_PIN)
#define BACKLIGHT_BLINK       GPIO_ToggleBits(BACKLIGHT_PORT, BACKLIGHT_PIN)


#ifndef DEBUG
// pulse LED
#define ALARM_PULSE_ON          GPIO_ResetBits(ALARM_PULSE_PORT, ALARM_PULSE_PIN)
#define ALARM_PULSE_OFF         GPIO_SetBits(ALARM_PULSE_PORT, ALARM_PULSE_PIN)
#define ALARM_PULSE_BLINK       GPIO_ToggleBits(ALARM_PULSE_PORT, ALARM_PULSE_PIN)
// alarm LED R
#define ALARM_R_ON      		GPIO_ResetBits(ALARM_R_PORT, ALARM_R_PIN)
#define ALARM_R_OFF     		GPIO_SetBits(ALARM_R_PORT, ALARM_R_PIN)
#define ALARM_R_BLINK           GPIO_ToggleBits(ALARM_R_PORT, ALARM_R_PIN)
#else
// pulse LED
#define ALARM_PULSE_ON 
#define ALARM_PULSE_OFF 
#define ALARM_PULSE_BLINK


// alarm LED R
#define ALARM_R_ON
#define ALARM_R_OFF
#define ALARM_R_BLINK

#endif


// alarm LED G
#define ALARM_G_ON      	    GPIO_ResetBits(ALARM_G_PORT, ALARM_G_PIN)
#define ALARM_G_OFF     		GPIO_SetBits(ALARM_G_PORT, ALARM_G_PIN)
#define ALARM_G_BLINK     		GPIO_ToggleBits(ALARM_G_PORT, ALARM_G_PIN)
#define getAlarm_G_Sta()		(!GPIO_ReadOutputDataBit(ALARM_G_PORT, ALARM_G_PIN))


//key board led
#define KEY_LED_ON      		GPIO_SetBits(KEY_LED_PORT, KEY_LED_PIN)
#define KEY_LED_OFF   			GPIO_ResetBits(KEY_LED_PORT, KEY_LED_PIN)
#define KEY_LED_BLINK			GPIO_ToggleBits(KEY_LED_PORT, KEY_LED_PIN)


/*功能IO宏定义*/
#define LED				GPIOG
#define LED_PIN			GPIO_Pin_6


/*操作宏定义*/
#define LED_ON			GPIO_ResetBits(LED, LED_PIN)
#define LED_OFF			GPIO_SetBits(LED, LED_PIN)
#define LED_TOG			GPIO_ToggleBits(LED, LED_PIN)


#define LED_Flash(Times, LED)				\
do{											\
	for(uint08 i = 0; i < Times; i++)		\
	{										\
		LED##BLINK;							\
		TicksDelayMs(50, NULL);				\
	}										\
	LED##OFF;								\
}while(0)



#endif
