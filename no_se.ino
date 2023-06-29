#include <SoftwareSerial.h>
#define led 2
SoftwareSerial ok(10, 11);
char jaja;


void setup() 
{
ok.begin(9600);
pinMode(led, OUTPUT);
}

void loop() 
{
if(ok.available())
{
jaja = ok.read();
switch(jaja)
{
case '1':
digitalWrite(led, HIGH);
break;

case '2':
digitalWrite(led, LOW);
break;
}

}
}
