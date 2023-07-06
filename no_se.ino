
#include <Wire.h>   
#include <PCF8574.h>  

#define PCF8574_HIGH LOW 
#define PCF8574_LOW HIGH 
#define LED0 0    
#define LED1 1   
#define LED2 2    
#define LED3 3    
#define INPUT0 4   
#define INPUT1 5    
#define INPUT2 6    
#define INPUT3 7 
#define SerialBaudRate 9600 


String inf_recibida; 
PCF8574 expansor_PCF(0x27);  
int numDepartamentos=22;
bool state_input0;
bool state_input1;
bool state_input2;
bool state_input3;

void setup()
{
  Serial.begin(SerialBaudRate); 
  Serial.println("cabecera de Guatemala");
  Serial.println("Comunicacion Serial - recepcion de un String"); 
  Wire.begin();  
  expansor_PCF.begin(); 
}

void loop()
{
  while (Serial.available() > 0)
  {
  inf_recibida = Serial.readStringUntil('\r\n'); 
  }

  state_input0 = expansor_PCF.read(INPUT0);
  state_input1 = expansor_PCF.read(INPUT1);
  state_input2 = expansor_PCF.read(INPUT2);
  state_input3 = expansor_PCF.read(INPUT3);

  for(i=0; i<numDepartamentos; i++)
  {
    Serial.println(preguntas[i]);
  }
  if(inf_recibida == String("on"))
  {
  Serial.println("cabecera de Guatemala");
  expansor_PCF.write(LED0,PCF8574_LOW);  //enciendo el puerto 0
  }
  else if(inf_recibida == String("Ciudad de Guatemala"))
  {
  expansor_PCF.write(LED0,PCF8574_HIGH);  //enciendo el puerto 0    
  }
  
}
