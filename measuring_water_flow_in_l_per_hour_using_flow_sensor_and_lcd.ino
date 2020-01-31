#include <LiquidCrystal.h>
volatile int flow_frequency; //This is used to measure water sensor pulses
unsigned int l_hour; //Litres per hour
unsigned char flowsensor = 2; //Sensor input pin
unsigned long currentTime;
unsigned long cloopTime;
void flow() //Interrupt function
{
  flow_frequency++;
}

LiquidCrystal lcd(3, 4, 5, 6, 7, 8); //RS, E, D4,D5,D6,D7
void setup() {
    // put your setup code here, to run once:
  pinMode(flowsensor, INPUT);
  digitalWrite(flowsensor, HIGH); //This is an optional pull-up
  Serial.begin(9600);
  attachInterrupt(0, flow, RISING); //Setup interrupt
  sei(); //Enables interrupts
  currentTime = millis();
  cloopTime = currentTime;

}

void loop() {


  // put your main code here, to run repeatedly:
  currentTime = millis();
  //Calculate and print litres/hour each second
  if(currentTime >= (cloopTime + 1000)){
    lcd.clear();
    lcd.print(l_hour); //Displays the flow rate in litres/hour
    cloopTime = currentTime; //Updates cloopTime

    //The pulse frequency (Hz) = 7.5Q, Q is the low rate in L/min
    l_hour = (flow_frequency * 60 / 7.5); // (Pulse frequency x 60 min) / 7.5Q = flowrate in L/hour
    flow_frequency = 0; //Reset the counter
    Serial.print(l_hour, DEC); //This prints litres/hour
    Serial.println(" L/hour");

 
  }

}
