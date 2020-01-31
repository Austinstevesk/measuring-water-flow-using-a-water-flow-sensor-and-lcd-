# measuring-water-flow-using-a-water-flow-sensor-and-lcd-
In this project, I used a water flow sensor model YF-S201 to get the value of water flowing in a pipe. 
The setup includes use of interrupt to make sure that the processor executes the code at the least time possible after a signal 
is detected. 
The unsigned character flowsensor should be set to digital pin 2,tried otherwise and it couldn't work.
The void flow function enables frequency to be incremented every time there is a signal change. 
You may assume a water flow sensor has an analog input right. 
However, I used a digital input as I are executing the loop after a change in value is detected and printing it out.
Checking on the delay and the lcd.print lines of code, they are at the top in the if statement. 
This will ensure that the delay won't affect the whole loop affecting the value. We were interested in the flow 
frequency and I captured the value after every 1 second. This is explained by the statement that checks whether the 
current time value is greater than the cloopTime value by 1000 milliseconds.
This thereby triggers the code execution.
DEC gives the value in decimal.
