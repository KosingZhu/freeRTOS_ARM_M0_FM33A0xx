#ifndef _timer0_H
#define _timer0_H



#define ETIMx_ETxINSEL_GRP1SEL_ET1234_APBCLK	ETIMx_ETxINSEL_GRP1SEL_ET1_APBCLK



#define	mSecond		(80) 


#define doStopTimerBuzzer(timer, sta)	                \
do{				                                        \
			clrHMIStatus1(sta);							\
			timer = 0;									\
}while(0)


#define setTimer(Timer, time)		(Timer=time)
#define clrTimer(Timer)				(Timer=0)
#define getTimer(Timer)				(Timer)
#define decTimer(Timer)				(--Timer)
#define incTimer(Timer)				(Timer++)


#define perCircle		(8)
#define IntOneSecond	(244)

#define	perSecond		(50)
#define oneP5Second		(75)
#define fifteenSecond	(perSecond*15)
#define HalfSecond		(perSecond/2)
#define ms100			(5)
#define ms20			(5)
#define buzzerExTime	(7)
#define KeyModeWaitTime	(29)//按键模式退出等待时间
#define StandbyWaitTime	(10)//待机界面退出等待时间
#define KeyBackLightTime (10)//按键背光保持时间
#define SleepWaitTime	(28)//进入睡眠模式等待时间(SleepWaitTime-StandbyWaitTime)才是待机到休眠的间隔时间
#define EnterLowPowerTime	(5)
#define magic			(8)


#define _5Second	(5)
#define _3Second	(3)
#define _2Second	(2)
#define _10Second	(10)
#define _15Second	(15)
#define _20Second	(20)
#define _25Second	(25)
#define _30Second	(30)
#define _34Second	(34)
#define _60Second	(60)
#define _120Second	(120)
#define nSecond(n)	(_##n##Second)


extern  volatile  uint08 second;
extern  volatile  uint08 minute;
extern  volatile  uint08 hour;
extern  volatile  uint16 day;
extern  volatile  uint16 year;
extern  volatile  uint32 Timer0Tick;


void TimerInit(ETIMx_Type* ETIMx, uint16 howlong);
void setTime(ETIMx_Type* ETIMx, uint16 howlong);
void timerHandle(void);



int testTimer (void);



#endif
