#include <gui/screen1_screen/Screen1View.hpp>
#include <iostream>
#include "main.h"
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
	cout << "setup RTC Triggered";
}
