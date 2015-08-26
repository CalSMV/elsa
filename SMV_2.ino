#include <Encoder.h>
#include <digitalWriteFast.h>
#include <Servo.h>

Servo myservo;

int val; 
int tempPosFlip = 0;
long encoder0Pos = 0;
int limit = 700;
int tick = 0;
int offset = 0;

Encoder quadEncoder(2,3);

int button1Pin = A3;
int button2Pin = A4;
int button1State = 0;
int button2State = 0;
int buttonHold = 0;
int button2Hold = 0;

int holdTime = 100;
int hold2Time = 50;

int thermistorPin = A5;

int led0 = 4;
int led1 = 5;
int led2 = 6;
int led3 = 7;
int led4 = 8;
int led5 = 9;
int led6 = 10;
int led7 = 11;
int led8 = 12;
int led9 = 13;


void setup() { 
  pinMode (button1Pin, INPUT);
  pinMode (button2Pin, INPUT);

  pinMode(led0,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  pinMode(led6,OUTPUT);
  pinMode(led7,OUTPUT);
  pinMode(led8,OUTPUT);
  pinMode(led9,OUTPUT);

  myservo.attach(A2);

  Serial.begin (9600);
} 

void loop() { 
  ++tick;
  button1State = digitalReadFast2(button1Pin);
  if (button1State == HIGH){
    if(buttonHold > holdTime)
    {
      quadEncoder.write(0); 
      buttonHold = 0;
    }
    else{
      ++buttonHold;
    }
  }
  else{
    buttonHold = 0; 
  }

  encoder0Pos = quadEncoder.read();
  //Serial.println(encoder0Pos);
  val = -encoder0Pos;
  val = map(val,-limit,limit,30,149);
  myservo.write(val+offset);



  button2State = digitalReadFast2(button2Pin);
  if (button2State == HIGH){
    if(button2Hold > holdTime)
    {
      tempPosFlip = tempPosFlip == 0 ? 1 : 0;
      button2Hold = 0;
    }
    else{
      ++button2Hold;
    }
  }
  else{
    button2Hold = 0; 
  }

  if(tempPosFlip == 1)
  {
    double temp;
    int adc = analogRead(thermistorPin);
    temp = log(((10240000/adc)-10000));
    temp = 1/(0.001129148 + (0.000234125 * temp) + (0.0000000876741 * temp * temp * temp));
    temp = temp-273.15;
    temp = (temp * (9/5))+32;
    Serial.print("Temp ");
    Serial.print(temp);
    Serial.print(" *F");
    Serial.println();

    temp = map(temp,13,22,0,9);

    digitalWriteFast2(led0,LOW);
    digitalWriteFast2(led1,LOW);
    digitalWriteFast2(led2,LOW);
    digitalWriteFast2(led3,LOW);
    digitalWriteFast2(led4,LOW);
    digitalWriteFast2(led5,LOW);
    digitalWriteFast2(led6,LOW);
    digitalWriteFast2(led7,LOW);
    digitalWriteFast2(led8,LOW);
    digitalWriteFast2(led9,LOW);

    if(temp < 130) {
      digitalWriteFast2(led0,HIGH);
    }
    if(temp < 140) {
      digitalWriteFast2(led1,HIGH);
    }
    if(temp < 150) {
      digitalWriteFast2(led2,HIGH);
    }
    if(temp < 160) {
      digitalWriteFast2(led3,HIGH);
    }
    if(temp < 170) {
      digitalWriteFast2(led4,HIGH);
    }
    if(temp < 180) {
      digitalWriteFast2(led5,HIGH);
    }
    if(temp < 190) {
      digitalWriteFast2(led6,HIGH);
    }
    if(temp < 200) {
      digitalWriteFast2(led7,HIGH);
    }
    if(temp < 210) {
      digitalWriteFast2(led8,HIGH);
    }
    if(temp < 220) {
      digitalWriteFast2(led9,HIGH);
    }


  }
  else
  {
    val = -encoder0Pos;
    val = map(val,-limit,limit,0,19);

    digitalWriteFast2(led0,LOW);
    digitalWriteFast2(led1,LOW);
    digitalWriteFast2(led2,LOW);
    digitalWriteFast2(led3,LOW);
    digitalWriteFast2(led4,LOW);
    digitalWriteFast2(led5,LOW);
    digitalWriteFast2(led6,LOW);
    digitalWriteFast2(led7,LOW);
    digitalWriteFast2(led8,LOW);
    digitalWriteFast2(led9,LOW);
    Serial.println(val);

    switch(val){
    case 19:
      digitalWriteFast2(led0,HIGH);
      break;
    case 18:
      digitalWriteFast2(led0,HIGH);
      break;
    case 17:
      digitalWriteFast2(led0,HIGH);
      digitalWriteFast2(led1,HIGH);
      break;
    case 16:
      digitalWriteFast2(led1,HIGH);
      break;
    case 15:
      digitalWriteFast2(led1,HIGH);
      digitalWriteFast2(led2,HIGH);
      break;
    case 14:
      digitalWriteFast2(led2,HIGH);
      break;
    case 13:
      digitalWriteFast2(led2,HIGH);
      digitalWriteFast2(led3,HIGH);
      break;
    case 12:
      digitalWriteFast2(led3,HIGH);
      break;
    case 11:
      digitalWriteFast2(led3,HIGH);
      digitalWriteFast2(led4,HIGH);
      break;
    case 10:
      digitalWriteFast2(led4,HIGH);
      break;
    case 9:
      digitalWriteFast2(led4,HIGH);
      digitalWriteFast2(led5,HIGH);
      break;
    case 8:
      digitalWriteFast2(led5,HIGH);
      break;
    case 7:
      digitalWriteFast2(led5,HIGH);
      digitalWriteFast2(led6,HIGH);
      break;
    case 6:
      digitalWriteFast2(led6,HIGH);
      break;
    case 5:
      digitalWriteFast2(led6,HIGH);
      digitalWriteFast2(led7,HIGH);
      break;
    case 4:
      digitalWriteFast2(led7,HIGH);
      break;
    case 3: 
      digitalWriteFast2(led7,HIGH);
      digitalWriteFast2(led8,HIGH);
      break;
    case 2:
      digitalWriteFast2(led8,HIGH);
      break;
    case 1:
      digitalWriteFast2(led8,HIGH);
      digitalWriteFast2(led9,HIGH);
      break;
    case 0:
      digitalWriteFast2(led9,HIGH);
      break;
    }
    if(val > 19){
      digitalWriteFast2(led0,HIGH);
    }
    if(val < 0){
      digitalWriteFast2(led9,HIGH);
    }
  }
}

























