
task main()
{
	//Auto Straight
SensorValue[rightEnc] = 0;
SensorValue[leftEnc] = 0;

while(SensorValue[leftEnc] < 1260)
	{
		if (SensorValue[leftEnc] > SensorValue[rightEnc])
		{
			motor[rightMotor] = 63;
			motor[leftMotor] = 50;
		}
		if (SensorValue[leftEnc] < SensorValue[rightEnc])
		{
			motor[rightMotor] = 50;
			motor[leftMotor] = 63;
		}
		if (SensorValue[leftEnc] == SensorValue[rightEnc])
		{
			motor[rightMotor] = 63;
			motor[leftMotor] = 63;
		}
	}


}
