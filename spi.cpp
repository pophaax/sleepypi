/*
 * 
 *
 *
 *					RASPBERRY PI CODE
 *
 *
 *			PIN HIGH = Sleepy Pi checks every 10 seconds
 *          PIN LOW = Sleepy Pi checks every 300 seconds
 *
 *
 * 			Set pin to high when starting the program and low before shutting down the raspberry pi
 *
*/

#include <unistd.h>
#include <stdio.h>
#include <cstdlib>
#include <wiringPi.h>


int main() {

	int sleepyPi_pin = 6;

	wiringPiSetup();
	pinMode(sleepyPi_pin,OUTPUT);

	//while(1){
	//	digitalWrite(sleepyPi_pin, 1);
	//	printf("The pin is HIGH\n");
	//	usleep(15000000); // 15 seconds
	//	digitalWrite(sleepyPi_pin, 0);
	//	printf("The pin is LOW\n");
	//	usleep(15000000);
	//}

	printf("I've just woken up!! :D\n");
	digitalWrite(sleepyPi_pin, 1);
	usleep(60000000); // 60 seconds - 1 min
	//usleep(120000000); // 120 seconds - 2 min
	//digitalWrite(sleepyPi_pin, 0);
	printf("I'm going to sleep now!\n");
	system("sudo poweroff");
}

/*
 *
 *
 *
 *					ARDUINO SLEEPY PI CODE
 *
 *
 *
 *
 * 
//
// Simple example showing how to set the RTC alarm pin to wake up the Arduino
// and then power up the Raspberry Pi
//

#include "SleepyPi.h"
#include <Time.h>
#include <LowPower.h>
#include <DS1374RTC.h>
#include <Wire.h>

const int LED_PIN = 13;


const int LONG_TIME = 256;
const int SHORT_TIME = 2;

boolean recentLongSleep;

void alarm_isr()
{
	// Just a handler for the alarm interrupt.
	// You could do something here
	
	}
	
	void setup()
	{
		
		// Configure "Standard" LED pin
		pinMode(LED_PIN, OUTPUT);
		digitalWrite(LED_PIN,LOW);		// Switch off LED
		
		SleepyPi.enablePiPower(false);
		
		// initialize serial communication: In Arduino IDE use "Serial Monitor"
		Serial.begin(9600);
		recentLongSleep = false;
		
	}
	
	void loop()
	{
		// Allow wake up alarm to trigger interrupt on falling edge.
		attachInterrupt(0, alarm_isr, FALLING);		// Alarm pin
		
		SleepyPi.enableWakeupAlarm();
		if(SleepyPi.checkPiStatus(false)) {
			SleepyPi.setAlarm(SHORT_TIME);              // in seconds
			recentLongSleep = false;
		} else {
			if(recentLongSleep) {
				SleepyPi.setAlarm(SHORT_TIME);
		} else {
			SleepyPi.setAlarm(LONG_TIME);
			recentLongSleep = true;
		}
		}
		// Enter power down state with ADC and BOD module disabled.
		// Wake up when wake up pin is low.
		SleepyPi.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
		
		// Disable external pin interrupt on wake up pin.
		detachInterrupt(0);
		
		// Do something here
		// Example: Read sensor, data logging, data transmission.
		SleepyPi.enablePiPower(true);
		
		Serial.println("I've Just woken up");
		digitalWrite(LED_PIN,HIGH);		// Switch on LED
		delay(250);
		digitalWrite(LED_PIN,LOW);		// Switch off LED
		
		}
*/
