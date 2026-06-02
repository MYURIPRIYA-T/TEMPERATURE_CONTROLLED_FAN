#include "DHT.h"           // Incluimos librería DHT
 
#define DHTPIN 2           // Definimos el pin digital donde se conecta el sensor
#define DHTTYPE DHT11      // Definimos el tipo de sensor en mi caso DHT11
#define fanPWM 3           // fanPWM speed control signal pin

int setTemp = 25;      // Temperatura setpoint grados Celsius
int minTemp = 20;      // Temperatura MIN grados Celsius
int maxTemp = 42;      // Temperatura MAX grados Celsius

DHT dht(DHTPIN, DHTTYPE);      // Inicializamos el sensor DHT11 (16mhz Arduino)
 
void setup() {
  Serial.begin(9600);           // Inicializamos comunicacion serie
  pinMode(fanPWM, OUTPUT);      // Habilitamos fanPWM signal output
  dht.begin();                  // Comenzar la biblioteca del sensor dht
  
////////////////////Fan Speed 25KHz Clock Speed Setup////////////////////
  
   TCCR2A = 0x23;  // set time clock multiplier
   TCCR2B = 0x09;  // select clock
   OCR2A = 79;     // timing for 25kHz
   OCR2B = 30;     // set the PWM duty cycle
}
 
void loop() { 
 
  ////////////////////Lectura de Sensores Temp/Hum////////////////////

   delay(2000);     // Esperamos 2 segundos entre medidas

   float h = dht.readHumidity();           // Leemos la humedad relativa
   float t = dht.readTemperature();        // Leemos la temperatura en grados centígrados (por defecto)
   float f = dht.readTemperature(true);    // Leemos la temperatura en grados Fahreheit 

    if (isnan(h) || isnan(t)) {             // Comprobamos si ha habido algún error en la lectura
    Serial.println("Error obteniendo los datos del sensor DHT11"); // Mostrar por consola el error
    return;
    }// ¡Leer la temperatura o la humedad toma alrededor de 250 milisegundos!
    
    Serial.print("Fan Speed: ");        // Mostrar por consola fanSpeed leido en el serial
    Serial.print(OCR2B);
    Serial.print(" %");
    Serial.print("\t Temperatura: ");   // Mostrar por consola temperatura leido en el serial
    Serial.print(t);
    Serial.print(" *C ");
    Serial.print("\t Humedad: ");       // Mostrar por consola humedad leido en el serial
    Serial.print(h);
    Serial.print("\n"); 
   
     if(t < minTemp) {                  // Si la temperatura está por debajo de minTemp (20°) apague los ventiladores
        analogWrite(fanPWM, LOW);
        OCR2B = 0;                      // Velocidad del fan en 0   
     }
     else{                              // Si está por arriba de minTemp (20°) mantener el flujo de aire mínimo
        analogWrite(fanPWM, HIGH);

  ////////////////////Logica del Fan////////////////////
  
     if(t >= minTemp)             // speed level 1    mayor o igual a 20°
       OCR2B = 20;                // fan = minimo
     if(t >= setTemp)             // speed level 2    mayor o igual a 25°
        OCR2B = 30;               // fan + 10
     if(t >= setTemp + 5)         // speed level 3    mayor o igual a 30°
        OCR2B = 40;               // fan + 20
     if(t >= setTemp + 10)        // speed level 4    mayor o igual a 35°
        OCR2B = 50;               // fan + 30
     if(t >= setTemp + 15)        // speed level 5    mayor o igual a 40°
        OCR2B = 60;               // fan + 40
     if(t >= maxTemp)             // maximo nivel de velocidad a mas de 42°
        OCR2B = 79;               // fan = maximo
        }
}
