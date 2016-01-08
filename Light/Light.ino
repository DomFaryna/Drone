#include <TimerOne.h>

/* Example: TSL235R
  Collaborative ideas from:
  retrofelty, robtillaart, Gumpy_Mike, and madepablo
 
  Sensor:
  http://www.sparkfun.com/datasheets/Sensors/Imaging/TSL235R-LF.pdf
  measurement area: 0.92mm2
 
  Wiring:
  TSL235R    Arduino pins
  GND        GND
  Vcc        +5V
  Out        Digital pin 2
  Wire a 0.1uF capacitator between Vcc and GND close to the sensor
*/

// Pin definitions
# define TSL235R 2                      // Out of TSL235R connected to Digital pin 2

// Constants
int period = 1000;                     // Miliseconds of each light frecuency measurement
int ScalingFactor = 1;                 // Scaling factor of this sensor
float area = 0.0092;                   // Sensing area of TSL235R device (cm2)
int done = 0;

// Variables
unsigned long counter = 0;             // Counter of measurements during the test
unsigned long currentTime = millis();  
unsigned long startTime = currentTime;
volatile long pulses = 0;              // Counter of measurements of the TSL235R
unsigned long frequency;               // Read the frequency from the digital pin (pulses/second)
float irradiance;                      // Calculated irradiance (uW/cm2)


void setup() {
 Timer1.initialize(2000000);
 Serial.begin(9600);                           // Start and configure the serial port
 attachInterrupt(0, PulseCount, RISING);
 pinMode(TSL235R, INPUT);
 Serial.write("1"); // Declare the pin such as an input of data
 Serial.println("Testing a TSL235R sensor:");  // Splash screen
 Serial.println("-------------------------");
 Serial.println();  
}

void loop(){
  
  
    
      if(done < 10){
        Timer1.attachInterrupt(getStuffDone);
         
         
      } else{
        Timer1.detachInterrupt();
        Serial.println("x");
        delay(1000);
      }
      
      if(Serial.available()){
        Serial.read();
        Serial.println(frequency);
    }
    
}


void getStuffDone(){
     counter++;                           // Increase the number of measurement
     //Serial.print(counter);               // Print the measurement number
     getfrequency();                      // Request to measure the frequency
     //Serial.print("  ");
     //Serial.println(frequency);             // print the frequency (pulses/second)
     //Serial.println("");
     //Serial.print(" pulses/second    ");
     getirradiance();                     // Request to calculate the irradiance (uW/cm2)
     //Serial.print("  ");
     //Serial.print(irradiance);             // print the frequency (pulses/second)
     //Serial.println(" uW/cm2");
     pulses = 0;                          // reset the pulses counter 
     done++;
}

void PulseCount()
{
pulses++;
}

unsigned long getfrequency () {
 noInterrupts();
 frequency = pulses /(period/1000);    // Calculate the frequency (pulses/second)
 interrupts();
 return (frequency);
}

float getirradiance () {
 irradiance = frequency / area;      // Calculate Irradiance (uW/cm2)
 return (irradiance);
}


