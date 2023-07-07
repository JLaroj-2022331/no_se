
#include <LedControl.h>
#include <Ticker.h>

int adc, cover;
int seg;

volatile static bool estado_mq2;
void isr_mq2(void); 

LedControl lc=LedControl(11,13,10,1);
Ticker isr_accion_mq2(isr_mq2, 2000);

void setup()
{
Serial.begin(9600);
lc.shutdown(0,false);
lc.setIntensity(0,4);
lc.clearDisplay(0);
isr_accion_mq2.start(); 
}
void loop()
{
isr_accion_mq2.update();
}

void copo_funcion()
{
byte copo[8]=
{
B00101000,
B10010010,
B01010100,
B10111010,
B00010000,
B10111010,
B01010100,
B10010010,
};

for(int i=0; i<8;i++)
{
lc.setRow(0,i,copo[i]);
}}
void llama_funcion()
{

byte llama[8]=
{
B00010000,
B00101000,
B01000100,
B10000010, 
B10000010,
B10000010,
B01000100,
B00111000,
};  

for(int i=0; i<8;i++)
{
lc.setRow(0,i,llama[i]);
}}
void isr_mq2(void)
{
adc=analogRead(A0);
cover = map(adc,0,1024,0,100);
Serial.print("adc:");
Serial.print(adc);
Serial.println("   porcentaje:");
Serial.println(cover);
Serial.println(adc);
if(adc>100)
{
if(seg==0)
{
parpadeo();}
if(seg==1)
{
llama_funcion();
}
}

else{
copo_funcion();
seg=0;
}
}

void parpadeo()
{
llama_funcion();
delay(1000);  
lc.clearDisplay(0);
delay(1000);
llama_funcion();
delay(1000);  
lc.clearDisplay(0);
delay(1000);
llama_funcion();
delay(1000);  
seg=1;
}
