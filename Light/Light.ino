/* Example: TSL235R
  Collaborative ideas from:
  retrofelty, robtillaart, Gumpy_Mike, and madepablo
 
  Wiring:
  TSL235R    Arduino pins
  GND        GND
  Vcc        +5V
  Out        Digital pin 2
  Wire a 0.1uF capacitator between Vcc and GND
*/

// Pin definitions
# define Sensor 2

// Variables
volatile long count = 0;   // Counter of measurements of the TSL235R
long threshold = 100;      // Minimum of measurements
long counter = 0;          // Counter of measurements during the test
int frequency;             // Read the frequency from the digital pin

void setup()
{
 Serial.begin(9600);                           // Start and configure the serial port
 pinMode(frequency, INPUT);                    // Declare the pin such as an input of data
 attachInterrupt(0, MyIRQ, CHANGE);
 Serial.println("Testing a TSL235R sensor:");  // Splash screen
 Serial.println("-------------------------");
 Serial.println();  
}

void loop()
{
counter = counter + 1;       // Increase the number of measurement
noInterrupts();
if (count > threshold)
{
  frequency=digitalRead(Sensor);  // Read the sensor
  Serial.print(counter);     // Print the measurement number
  Serial.print("  ");
  Serial.println(frequency); // print the signal
  count = 0;                 // reset the counter
  interrupts();  
}
delay (1000);               // wait 1 seconds until the next measurement
}

void MyIRQ()
{
count++;
}
