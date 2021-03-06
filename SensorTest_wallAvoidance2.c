#pragma config(Sensor, in1,    PhotoSensor,    sensorReflection)
#pragma config(Sensor, dgtl2,  button1,        sensorTouch)
#pragma config(Sensor, dgtl3,  button2,        sensorTouch)
#pragma config(Sensor, dgtl4,  sonarLeftIn,    sensorSONAR_cm)
#pragma config(Sensor, dgtl6,  sonarRightIn,   sensorSONAR_cm)
#pragma config(Sensor, dgtl8,  sonarMiddleIn,  sensorSONAR_cm)
#pragma config(Sensor, dgtl12, LEDRed,         sensorLEDtoVCC)
#pragma config(Motor,  port1,           motorL,        tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port10,          motorR,        tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool button1_pushed;
bool button2_pushed;

void signal_wall() { //too close, short blinks
	int i = 0;
	while(i < 10){
		SensorValue[LEDRed] = 1;
		wait1Msec(90);
		SensorValue[LEDRed] = 0;
		wait1Msec(90);
		i = i + 1;
	}
}

void monitorInput() //monitors which button is being pushed
{
	if(SensorValue(button1) && !button1_pushed)
	{
		button1_pushed = true;
	}

	if(SensorValue(button2) && !button2_pushed)
	{
		button2_pushed = true;
	}
}

void motorStop(){
	motor[motorL] = 0;
	motor[motorR] = 0;
	signal_wall();
}

void wallDetected(){
	motor[motorL] = -50;
	motor[motorR] = -50;
	wait1Msec(1500);
}

task main(){

	button1_pushed = button2_pushed = false;

	enum T_state {															//Declare states
		STOP,
		MOVING
	};

	T_state state = STOP;

	while (true) {

		monitorInput();

		switch (state)	{

		case STOP:
			motor[motorL] = 0;
			motor[motorR] = 0;
			if(button1_pushed) {
				button1_pushed = false;
				state = MOVING;
			}
			break;

		case MOVING:
			wait1Msec(500);
			motor[motorL] = 45;
			motor[motorR] = 45;
			if(SensorValue[sonarLeftIn] < 25 || SensorValue [sonarRightIn] < 25){
				motorStop();
				wallDetected();
				state = STOP;
			}
			if(button2_pushed) {
				button2_pushed = false;
				state = STOP;
			}
			break;

			//default:
		}
	}
}
