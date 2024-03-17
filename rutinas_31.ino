//Developer:Mario Zambrano
/* Script description:
Turn led on with Arduino and c++
*/
const int pinLedRojo = 13; 
const int sensorTemperatura = A0;
const int pinVentilador = 12; 

float temperatura = 0; 

#include <LiquidCrystal.h>

int seconds = 0;

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int tmpSensorPin = A0;
const int ledPin = 6;
const int motorPin = 7;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Temperatura:"); 
  lcd.setCursor(0, 1);
  lcd.print("Inicializando...");
  delay(2000); 
  lcd.clear(); 
}


void loop() {
  
  temperatura = obtenerTemperatura();
  
  Serial.print("Temperatura oC: ");
  Serial.println(temperatura);
  
  if (temperatura < 5) {
    
    intermitenciaLed();
    apagarVentilador(); 
  } else if (temperatura >= 6 && temperatura <= 25) {
    
    apagarLed();
    apagarVentilador();
  } else {
   
    encenderLed();
    encenderVentilador();
  }
  
  delay(1000); 
}

float obtenerTemperatura() {
  
  int lectura = analogRead(sensorTemperatura);
  
  
  float voltaje = lectura * (5.0 / 1023.0); 
  float temperaturaCelsius = (voltaje - 0.5) * 100.0;
  
  return temperaturaCelsius;
}

void intermitenciaLed() {
  digitalWrite(pinLedRojo, HIGH);
  delay(500);
  digitalWrite(pinLedRojo, LOW);
  delay(500);
}

void encenderLed() {
  digitalWrite(pinLedRojo, HIGH);
}

void apagarLed() {
  digitalWrite(pinLedRojo, LOW);
}

void encenderVentilador() {
  digitalWrite(pinVentilador, HIGH); 
}

void apagarVentilador() {
  digitalWrite(pinVentilador, LOW); 
}
