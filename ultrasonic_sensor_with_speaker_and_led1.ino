int inch = 0;
int cm = 0;

long readDistance(int signal) //UltraSonicDistance
{
  	pinMode(signal, OUTPUT);  // Clear the signal pin
  	digitalWrite(signal, LOW);
  	delay(3);
 	digitalWrite(signal, HIGH);
  	delay(10);   // Set signal pin to HIGH for 10 microsecond
  	digitalWrite(signal, LOW);
  	pinMode(signal, INPUT); //Read the signal pin
  	return pulseIn(signal, HIGH); //Return the sound travel time in mu
}
void setup()
{
  	pinMode(9, OUTPUT); // sets the digital pin 9 as output
  	pinMode(9, OUTPUT);
  	Serial.begin(9600); //This starts the serial communication 
}
void loop()
{
 	cm = 0.01723 * readDistance(7); //ping time in cm
  	inch = (cm / 2.54); // 1 inch = 2.54cm
  	Serial.print(inch); 
  	Serial.print("inches, ");
  	Serial.print(cm);
  	Serial.println("cm");
  	if( inch <80)  //It will buzz the sound and lights the LED if the object is is within 80 inches.
  	{
    	digitalWrite(9, HIGH); // sets the digital pin 9 on
  		digitalWrite(9, HIGH);
 	}
  	else
  	{
    	digitalWrite(9, LOW); // sets the digital pin 9 off
  		digitalWrite(9, LOW);
  	}
  delay(60); // Wait for 60 microsecond
}
