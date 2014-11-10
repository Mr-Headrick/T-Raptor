#pragma config(Sensor, in1,    topRitePot,     sensorPotentiometer)
#pragma config(Sensor, in2,    topLeftPot,     sensorPotentiometer)
#pragma config(Sensor, in3,    lowRitePot,     sensorPotentiometer)
#pragma config(Sensor, in4,    lowLeftPot,     sensorPotentiometer)
#pragma config(Motor,  port2,           drvRiteMotr,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           drvLeftMotr,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           topRiteMotr,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           topLeftMotr,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           lowRiteMotr,   tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           lowLeftMotr,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           claw,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

  int buffer = 61;
  int fastSpd = 63;
  int spd = 52;
  int slowSpd = 42;
  int stopSpd = 8;

task main()
{
	clearLCDLine(0);                      // Clear line 1 (0) of the LCD
  clearLCDLine(1);                      // Clear line 2 (1) of the LCD
  bLCDBacklight = true;                 // Turn on LCD Backlight
	displayLCDCenteredString(0,"Hi! I'm Freddy!");
	wait1Msec(500);
  while(1 == 1)
  {
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    //Upper Lift Control

  if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 1){

}
    else if(vexRT[Btn6U] == 1 && vexRT[Btn6D] == 0)
    {
    	   motor[topRiteMotr] = spd;
         motor[topLeftMotr] = spd;
 /*     if(SensorValue(topRitePot)>SensorValue(topLeftPot)+buffer){
         motor[topRiteMotr] = slowSpd;
         motor[topLeftMotr] = fastSpd;}
      else if(SensorValue(topLeftPot)>SensorValue(topRitePot)+buffer){
         motor[topLeftMotr] = slowSpd;
         motor[topRiteMotr] = fastSpd;}
      else {
         motor[topRiteMotr] = spd;
         motor[topLeftMotr] = spd;} */
    }
    else if(vexRT[Btn6U] == 0 && vexRT[Btn6D] == 1)
    {
    	   motor[topRiteMotr] = -spd;
         motor[topLeftMotr] = -spd;
    }
    else
    {
         motor[topRiteMotr] = stopSpd;
         motor[topLeftMotr] = stopSpd;
    }


    //Lower Lift Control

    if(vexRT[Btn5U] == 1)
    {
    	   motor[lowRiteMotr] = spd;
         motor[lowLeftMotr] = spd;
         /*
      if(SensorValue(lowRitePot)>SensorValue(lowLeftPot)+buffer){
         motor[lowRiteMotr] = slowSpd;
         motor[lowLeftMotr] = fastSpd;}
      else if(SensorValue(lowLeftPot)>SensorValue(lowRitePot)+buffer){
         motor[lowLeftMotr] = slowSpd;
         motor[lowRiteMotr] = fastSpd;}
      else {
         motor[lowRiteMotr] = spd;
         motor[lowLeftMotr] = spd;}*/
    }
    else if(vexRT[Btn5D] == 1)
    {    motor[lowRiteMotr] = -spd;
         motor[lowLeftMotr] = -spd;
    }
    else
    {
         motor[lowRiteMotr] = stopSpd;
         motor[lowLeftMotr] = stopSpd;
    }
//+++++++++++++++++++++++++++++++++++++++++++++| DRIVE |+++++++++++++++++++++++++++++++++++++++++++++
    motor[drvLeftMotr]  = (vexRT[Ch2] + vexRT[Ch1])/2;  // (y + x)/2
    motor[drvRiteMotr] = (vexRT[Ch2] - vexRT[Ch1])/2;  // (y - x)/2
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

 if(vexRT[Btn7L]==1)      {
  motor[intake]= -63;}
  else if(vexRT[Btn7D]==1){
  motor[intake]= 63; }
  else{motor[intake]=0;}

  if(vexRT[Btn8U]==1)      {
  motor[lowRiteMotr]= spd;}
  else if(vexRT[Btn7U]==1){
  motor[lowLeftMotr]= spd; }


  if(vexRT[Btn8R]==1){
    	motor[claw]=42;}
  else if(vexRT[Btn8D]==1){
  	  motor[claw]=-42;}
  else
  	{motor[claw]=0;}



  clearLCDLine(0);                      // Clear line 1 (0) of the LCD
  clearLCDLine(1);                      // Clear line 2 (1) of the LCD
  bLCDBacklight = true;                 // Turn on LCD Backlight

  displayLCDString(0,0,"TL:"); displayLCDNumber(0,3,SensorValue(topLeftPot));
  displayLCDString(0,9,"TR:"); displayLCDNumber(0,12,SensorValue(topRitePot));
  displayLCDString(1,0,"LR:"); displayLCDNumber(1,3,SensorValue(lowLeftPot));
  displayLCDString(1,9,"LR:"); displayLCDNumber(1,12,SensorValue(lowRitePot));

  }
}
