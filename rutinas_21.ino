//Developer:Mario Zambrano
/* Script description:
Turn led on with Arduino and c++
*/
const int pinLedRojo = 13;
const int sensorTemperatura = A0; 
const int pinVentilador = 12; 


float temperatura = 0; 

void setup() {
  
  Serial.begin(9600);
  
  
  pinMode(pinLedRojo, OUTPUT);
  pinMode(pinVentilador, OUTPUT);
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
