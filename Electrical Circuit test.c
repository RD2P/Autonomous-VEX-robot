#pragma config(Sensor, in1,    rightSensor,    sensorReflection)
#pragma config(Sensor, in5,    leftSensor,     sensorReflection)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// LED light control values.
//const   int OFF = 0;
//const   int ON  = 1;

/*void light_status()
{
  // Turn of the red LED
  SensorValue(RedLED)= ON;
  wait1Msec(1000);
  SensorValue(RedLED)= OFF;
  wait1Msec(1000);
  SensorValue(RedLED)= ON;
}*/

task main()
{
	getSensorValue();

}
