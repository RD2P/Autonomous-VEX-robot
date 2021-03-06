#pragma config(Sensor, dgtl2,  button,         sensorTouch)
#pragma config(Motor,  port8,           motorL,        tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           motorR,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          motorArm,      tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

bool button_pushed; //flag to store button1 input

void monitorInput() //monitors which button is being pushed
{
	if(SensorValue(button) && !button_pushed)
	{
		button_pushed = true;
	}
}

void openArm() {
	motor [motorArm] = 10;
	wait1Msec(500);
	motor [motorArm]	= 0;
wait1Msec(3000);
	motor [motorL]	= -40;
	motor [motorR]	= -40;
	wait1Msec(1500);
	motor [motorL]	= 0;
	motor [motorR]	= 0;
}

task main () {

	monitorInput ();

	while (true) {
		if ( SensorValue[button] == 1 ){
			openArm();
		}
	}

} //end task main
