#include <Arduino.h>

double RL = 10.0; //The value of resistor RL
double analog_value = 0;
double VRL;
double Rs;
double Ro, k;
int analogPin = 34;

void setup() //Runs only once
{
  Serial.begin(9600); //Initialise serial COM for displaying the value
  k = 1;
}

void loop()
{
  for (int test_cycle = 1; test_cycle <= 200; test_cycle++)
  //Read the analog output of the sensor for 200 times

  {
    analog_value = analog_value + analogRead(analogPin); //add the values for 200
  }

  analog_value = analog_value / 200.0;
  Serial.print("Analog value at fresh air = ");
  Serial.println(analog_value);

  //Convert analog value to voltage
  VRL = analog_value * (5.0 / 1023.0);

  //RS = ((Vc/VRL)-1)*RL is the formulae we obtained from datasheet
  Rs = ((5.0 / VRL) - 1) * RL;
  Serial.print("Rs at fresh air = ");
  Serial.println(Rs);

  //Rs/Ro is k as we obtained from graph of datasheet
  Ro = Rs / k;
  Serial.print("Ro at fresh air = ");
  Serial.println(Ro); //Display calculated Ro
  delay(2500);
}