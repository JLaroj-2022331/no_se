#include <Wire.h> 
#include <Servo.h> 
#define Servo_pin 6
#define photoPin A0

int led_rojo = 3;
int led_verde = 4;
int led_azul = 5;
int lectura;
int raw;
int tol = 8;
int resultado_rojo, resultado_verde,resultado_azul;
int sensor_infra =2;
int servo_motor;
Servo myServo;


void setup()
{
  myServo.attach(Servo_pin);
  attachInterrupt(digitalPinToInterrupt(2), sensor_interrupcion, FALLING);
  Serial.begin(9600);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(sensor_infra, OUTPUT);
  for(int i=8; i<=11; i++)
  {
  pinMode(i,OUTPUT);
  }
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  }
void loop()
  {
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
 bool estado = digitalRead(sensor_infra);
 
 digitalWrite(8,HIGH);
 digitalWrite(9,HIGH);
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
 delay(2);

 digitalWrite(8,LOW);
 digitalWrite(9,HIGH);
 digitalWrite(10,HIGH);
 digitalWrite(11,LOW);
 delay(2);

 digitalWrite(8,LOW);
 digitalWrite(9,LOW);
 digitalWrite(10,HIGH);
 digitalWrite(11,HIGH);
 delay(2);

 digitalWrite(8,HIGH);
 digitalWrite(9,LOW);
 digitalWrite(10,LOW);
 digitalWrite(11,HIGH);
 delay(2);
  
  if(servo_motor==1)
  {
     myServo.write(90);
     delay(1000);
     myServo.write(0);
     delay(1000);
     servo_motor=0;
  }
  }

void sensor_interrupcion()
{
 digitalWrite(8,LOW); 
 digitalWrite(9,LOW);
 digitalWrite(10,LOW);
 digitalWrite(11,LOW);
  analogWrite(led_rojo,150);
 delay(50000);
 raw=analogRead(photoPin);
 resultado_rojo=map(raw,0,1023,0,1023);
 digitalWrite(led_rojo,LOW);
 Serial.print("Resultado rojo:");
 Serial.println(resultado_rojo);
 delay(20000);

 digitalWrite(led_verde,HIGH);
 delay(50000);
 raw=analogRead(photoPin);
 resultado_verde=map(raw,0,1023,0,1023);
 digitalWrite(led_verde,LOW);
 Serial.print("Resultado verde: ");
 Serial.println(resultado_verde);
 delay(20000);
  
 analogWrite(led_azul,180);
 delay(50000);
 raw=analogRead(photoPin);
 resultado_azul=map(raw,0,1023,0,1023);
 digitalWrite(led_azul,LOW);
 Serial.print("Resultado_Azul: ");
 Serial.println(resultado_azul);
 delay(20000);

 if(( resultado_verde>resultado_rojo)&&(resultado_verde>resultado_azul))
  {
 servo_motor=1;
  }
  else{
   
 servo_motor=0;
  }
  
   
  
  
  
 
 
 
   }
