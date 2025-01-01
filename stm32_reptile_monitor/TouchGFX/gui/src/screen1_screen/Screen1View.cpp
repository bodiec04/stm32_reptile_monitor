#include <gui/screen1_screen/Screen1View.hpp>
#include <iostream>
#include "main.h"
#include <touchgfx/Unicode.hpp>
using namespace std;

Screen1View::Screen1View()
{
}
void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}

void Screen1View::setupRTC(){
	printf("Enter current year in 24-hour format\n");
	int current_hour = 0;
	scanf("%d", &current_hour);

	printf("Enter minutes:\n");
	int current_minutes = 0;
	scanf("%d", &current_minutes);

	printf("Entered time %d : %d\n", current_hour, current_minutes);

	RTC_TimeTypeDef rtc_config;
	// add an extra hour cuz idk
	rtc_config.Hours = current_hour +1;
	rtc_config.Minutes = current_minutes;

	if(HAL_RTC_SetTime(&hrtc, &rtc_config, RTC_FORMAT_BIN) == HAL_OK){
		printf("Time set successfully\n");
	};
}

void Screen1View::refreshTime(){
	printf("Update time\n");

	RTC_TimeTypeDef current_time;

	if(HAL_RTC_GetTime(&hrtc, &current_time, RTC_FORMAT_BIN) == HAL_OK){
		printf("%d : %d\n", current_time.Hours, current_time.Minutes);
	}

	touchgfx::Unicode::snprintf(currentTimeAreaBuffer1, 10, "%d", current_time.Hours);
	touchgfx::Unicode::snprintf(currentTimeAreaBuffer2, 10, "%d", current_time.Minutes);
	currentTimeArea.invalidate();

}

void Screen1View::setAlarm(){
	int alarm_hour;
	int alarm_minute;

	printf("Enter alarm hour");
	scanf("%d", &alarm_hour);
	printf("Enter alarm minute");
	scanf("%d", &alarm_minute);
//
//	RTC_AlarmTypeDef set_alarm;
//
//	set_alarm.Hours = alarm_hour+1;
//	set_alarm.Minutes = alarm_minute;
//
//	HAL_StatusTypeDef status = HAL_RTC_SetAlarm_IT(&hrtc, &set_alarm, RTC_FORMAT_BIN);
//	if(status == HAL_OK){
//		printf("Alarm set properly\n");
//	} else {
//		printf("Could not set alarm\n");
//	}
}
