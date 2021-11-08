//Included Headers
#include <WaspSensorEvent_v30.h>
#include <stdio.h>
#include<string.h>
#include <iostream.h>
unsigned int luxes = 0;
unsigned long milliseconds;

//File Name variable
const char data[] = "OP9.TXT";

void setup()
{

  USB.ON();
  SD.ON();
  Events.ON();
  //If file of name 'data' already exists, delete it, then create it
  SD.del(data);
  SD.create(data);
}

//Find amount of digits in values to create the proper buffer for SDcard
int digitAmt(int x){
  int digits = 0;
  while (x != 0) {
    x /= 10;
    digits++;
  }
  if(digits==0){
    digits = 1;
  }
 return digits;
}

void loop()
{
  //Call the getLuxes() method to read luxes from the TSL2561 Luminosity Sensor! Save this in luxes
  luxes = Events.getLuxes();
  int number = luxes;
  
  milliseconds = millis();
  //Find, and save the amount of digits in the luxes for storage purposes
  int digits_luxes = digitAmt(number);
  int digits_millis = digitAmt(milliseconds);
  //Set a buffer of 16 for SD CARD
  char buf[16];
  //Append datum to data
  //Use itoa(integer, buffer, base) to convert luxes to a string (base-10)
  SD.append(data, "TIME: ", 6);
  SD.append(data, ltoa(milliseconds,buf,10), 16);
  SD.append(data, "\n", 2);
  SD.append(data, "LUX: ", 5);
  SD.append(data, itoa(luxes,buf,10), digits_luxes);
  SD.append(data, "\n", 2);

}