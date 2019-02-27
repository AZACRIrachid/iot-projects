

// utlrasonic pinout
#define ULTRASONIC_TRIG_PIN     5   // pin TRIG 
#define ULTRASONIC_ECHO_PIN     4 // pin ECHO 

// measure distance 
  long duration, distance;

int count=0;
int freeSlot =0;

void setup() {
 Serial.begin (9600); // initiate serial communication to raspberry pi
 // ultraonic setup 
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);
 
}



void loop(){
  
  
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
  duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);
  //  distance = (high level timevelocity of sound (340M/S) / 2, 
 //  in centimeter = uS/58
  distance = duration/58.2;
  //distance = (duration/2) / 29.1;
  Serial.print("********** Ultrasonic Distance: ");
  Serial.print(distance);
  Serial.println(" cm");



  
 if(distance<10){
   distance = 1;
   Serial.print("slot is token");
 }
 else { distance = 0;
 Serial.print("slot is free");
 }


// add the result from all sensor to count total car
 count = distance ;

 // free slot = total slot - total car
 freeSlot = 4 - count;
 // number of total slot is 
 Serial.println(freeSlot);
 // the status is updated every 30 seconds.
 delay(30000);
 freeSlot = 0;
 distance = 0;
 

 }
