// Definir los pines de los LEDs
#define Ledja 2
#define BUZZER 6
int tiempo =1000;
int c=261; 
int d=294;
int e=329;
int f=349;
int g=391;
int gS=415;
int a=440;
int aS=455;
int b=466;
int cH=523;
int cSH=554;
int dH=587;
int dSH=622;
int eH=659;
int fH=698;
int fSH=740;
int gH=783;
int gSH=830;
int aH=880;

const int numDepartamentos = 22;
const int ledPins[numDepartamentos] = { 3, 4, 5, 6};

// Definir las preguntas y respuestas
const char* preguntas[numDepartamentos] = {
  "¿Cuál es la cabecera de Izabal?",   "¿Cuál es la cabecera de Peten?",  "¿Cuál es la cabecera de Quiche?", 
  "¿Cuál es la cabecera de Zacapa?",   "¿Cuál es la cabecera de Chimlatenango?",  "¿Cuál es la cabecera de Escuintla?", 
  "¿Cuál es la cabecera de Solola?",   "¿Cuál es la cabecera de Jalapa?",   "¿Cuál es la cabecera de Jutiapa?", 
  "¿Cuál es la cabecera de Totonicapan?",   "¿Cuál es la cabecera de Sacatepequez?",  "¿Cuál es la cabecera de Guatemala?", 
  "¿Cuál es la cabecera de San Marcos?",   "¿Cuál es la cabecera de Quiche?",   "¿Cuál es la cabecera de Alta verapaz?", 
  "¿Cuál es la cabecera de Baja Verapaz?",   "¿Cuál es la cabecera de Suchitepequez?",   "¿Cuál es la cabecera de Huehuetenango?", 
  "¿Cuál es la cabecera de El progreso?",   "¿Cuál es la cabecera de Chiquimula?",   "¿Cuál es la cabecera de Santa Rosa?", 
   "¿Cuál es la cabecera de Retalhuleu?"
};

const char* respuestasCorrectas[numDepartamentos] = {
  "Puerto Barrios", "Floress", "Santa Cruz del Quiche", "Zacapa", "Chimaltenango", "Escuintla",
  "Solola", "Jalapa", "Jutiapa", "Totonicapan", "Antigua Guatemala", "Ciudad de Guatemala",
 "San Marcos", "Quiche","Coban", "Salama", "Mazatenango", "Huehuetenango", "Guastatoya", 
 "Chiquimula", "Cuilapa", "Puerto Barrios"
};

void setup() {
  // Inicializar los LEDs como salidas
  for (int i = 0; i < numDepartamentos; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(Ledja, OUTPUT);
    pinMode(BUZZER,OUTPUT);

  }

  // Iniciar comunicación serial
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < numDepartamentos; i++) {
    // Mostrar la pregunta en el monitor serial
    Serial.println(preguntas[i]);

    // Esperar hasta que se reciba una respuesta por serial
    while (!Serial.available()) {}

    // Leer la respuesta ingresada
    String respuesta = Serial.readStringUntil('\n');

    // Verificar la respuesta
    if (respuesta.equalsIgnoreCase(respuestasCorrectas[i])) {
      // Encender el LED correspondiente si la respuesta es correcta
      digitalWrite(Ledja, HIGH);
      digitalWrite(ledPins[i], HIGH);
     
      delay(1000);
      digitalWrite(ledPins[i], LOW);
      digitalWrite(Ledja, LOW);

    }
    else
    {
    Serial.println("respuesta incorrecta");
    Serial.println("Buzzer Activo");
    tone(BUZZER, a, 500);
    delay(500+50);
    tone(BUZZER, a, 500);
    delay(500+50);     
    tone(BUZZER, a, 500); 
    delay(500+50);
    tone(BUZZER, b, 350);  
    delay(350+50);
    tone(BUZZER, g, 150);
    delay(150+50); 
    }

    // Limpiar el buffer del serial
    Serial.flush();
  }
}
