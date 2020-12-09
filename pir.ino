int led = 13;                // the pin that the LED is attached to
//int relay1 = 4;
int relay2 = 7;
int sensor = 4;              // the pin that the sensor is attached to
int state =   LOW        ;   // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(led, OUTPUT);      // initalize LED as an output
//  pinMode(relay1,OUTPUT);
  pinMode(relay2,OUTPUT);
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
  //relay initialize
//  digitalWrite(relay1,HIGH);
  digitalWrite(relay2,HIGH);
}

void loop()
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {           // check if the sensor is HIGH
    digitalWrite(led, HIGH);   // turn LED ON
//    digitalWrite(relay1,LOW);
    digitalWrite(relay2,LOW);
    delay(15000);                // delay 15 seconds
   
    if (state == LOW) {
      Serial.println("Motion detected!");
      state = HIGH;       // update variable state to HIGH
    }
  }
  else {
      digitalWrite(led, LOW); // turn LED OFF
//      digitalWrite(relay1,HIGH);
      digitalWrite(relay2,HIGH);
      delay(200);             // delay 200 milliseconds
     
      if (state == HIGH){
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
