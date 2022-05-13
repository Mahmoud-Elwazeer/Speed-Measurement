#include<LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5 , d6 = 6, d7 = 7;
LiquidCrystal lcd(rs , en , d4 , d5 ,d6 , d7);


#define echo A0    //Echo pin
#define trigger A1 //Trigger pin


int G_led = 8; // choose the pin for the Green Led
int R_led  =9; // choose the pin for the Red Led
int y_led = 10; // choose the pin for the yellow Led
int b_led = 11; // choose the pin for the blue Led


// defines variables
long duration;
int distance1=0;
int distance2=0;
double Speed=0;
int distance=0;



void setup(){


pinMode(echo, INPUT );// declare ultrasonic sensor Echo pin as input
pinMode(trigger, OUTPUT); // declare ultrasonic sensor Trigger pin as Output 



pinMode(G_led,OUTPUT); // declare Green LED as output
pinMode(R_led,OUTPUT); // declare Red LED as output
pinMode(y_led,OUTPUT); // declare Blue LED as output
pinMode(b_led,OUTPUT); // declare white LED as output


lcd.begin(16,2);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" Object  Speed ");
lcd.setCursor(0,1);
lcd.print("   Measurement  ");
delay(2000);
lcd.clear();
Serial.begin(9600); // Starts the serial communication
}


void loop(){

//calculating Speed
   distance1 = ultrasonicRead(); //calls ultrasoninicRead() function below
   
   delay(1000);//giving a time gap of 1 sec
   
   distance2 = ultrasonicRead(); //calls ultrasoninicRead() function below
   
   //formula change in distance divided by change in time
   Speed = (distance2 - distance1)/1.0; //as the time gap is 1 sec we divide it by 1.


   
//Displaying Speed
  Serial.print("Speed in cm/s  :"); 
  Serial.println(Speed);
lcd.setCursor(0,1); 
lcd.print("Speed  cm/s ");
lcd.print(Speed);    


// LED indicator
if (distance >0 && distance <25) 
{
    digitalWrite( G_led , HIGH);
    delay(50);                  // waits for a second
    digitalWrite( G_led , LOW);    // sets the LED off
    delay(50);                  // waits for a second
}

if (distance > 25 && distance <50 ) 
{
    digitalWrite( G_led , HIGH);
    delay(200);                  // waits for a second
    digitalWrite( G_led , LOW);    // sets the LED off
    delay(200);                  // waits for a second
}

if (distance >50  && distance < 75) 
{
    digitalWrite( R_led , HIGH);
    delay(50);                  // waits for a second
    digitalWrite( R_led , LOW);    // sets the LED off
    delay(50);                  // waits for a second
}
if (distance >75  && distance < 100) 
{
    digitalWrite( R_led , HIGH);
    delay(200);                  // waits for a second
    digitalWrite( R_led , LOW);    // sets the LED off
    delay(200);                  // waits for a second
}
if (distance >100  && distance < 125) 
{
    digitalWrite( y_led , HIGH);
    delay(50);                  // waits for a second
    digitalWrite( y_led , LOW);    // sets the LED off
    delay(50);                  // waits for a second
}
if (distance >125  && distance < 150) 
{
    digitalWrite( y_led , HIGH);
    delay(200);                  // waits for a second
    digitalWrite( y_led , LOW);    // sets the LED off
    delay(200);                  // waits for a second
}
if (distance >150  && distance < 175) 
{
    digitalWrite( b_led , HIGH);
    delay(50);                  // waits for a second
    digitalWrite( b_led , LOW);    // sets the LED off
    delay(50);                  // waits for a second
}
if (distance >175  && distance < 200) 
{
    digitalWrite( b_led , HIGH);
    delay(200);                  // waits for a second
    digitalWrite( b_led , LOW);    // sets the LED off
    delay(200);                  // waits for a second
}      


}

float ultrasonicRead ()
{
// Clears the trigPin
digitalWrite(trigger, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echo, HIGH);

//calculating distance
// Prints the distance on the Serial Monitor
Serial.print("Distance in cm : ");
Serial.println(distance);
lcd.setCursor(0,0);
lcd.print("Dist. in cm ");
lcd.print(distance);
lcd.print("   ");
distance= duration/28.5/2;
return distance;

}
