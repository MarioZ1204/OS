//Developer:Mario Zambrano
/* Script description:
Turn led on with Arduino and c++
*/
const int pinVerde = 11;
const int pinRojo = 12;
const int pinAmarillo = 13;

// Variables de estado de las luces
bool verdeEncendido = false;
bool rojoEncendido = false;
bool amarilloEncendido = false;

void setup() {
  // Inicialización del puerto serial
  Serial.begin(9600);
  
  // Configuración de los pines de salida para controlar los LEDs
  pinMode(pinVerde, OUTPUT);
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAmarillo, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) {
    int opcion = Serial.parseInt(); // Lee el número ingresado por el usuario

    // Realiza acciones según la opción ingresada
    switch (opcion) {
      case 1:
        encenderVerde();
        break;
      case 2:
        apagarVerde();
        break;
      case 3:
        encenderRojo();
        break;
      case 4:
        apagarRojo();
        break;
      case 5:
        encenderAmarillo();
        break;
      case 6:
        apagarAmarillo();
        break;
      case 7:
        encenderTodas();
        break;
      case 8:
        apagarTodas();
        break;
      case 9:
        intermitente();
        break;
      default:
        Serial.println("Opción no válida.");
        break;
    }
  }
}

void encenderVerde() {
  digitalWrite(pinVerde, HIGH);
  verdeEncendido = true;
}

void apagarVerde() {
  digitalWrite(pinVerde, LOW);
  verdeEncendido = false;
}

void encenderRojo() {
  digitalWrite(pinRojo, HIGH);
  rojoEncendido = true;
}

void apagarRojo() {
  digitalWrite(pinRojo, LOW);
  rojoEncendido = false;
}

void encenderAmarillo() {
  digitalWrite(pinAmarillo, HIGH);
  amarilloEncendido = true;
}

void apagarAmarillo() {
  digitalWrite(pinAmarillo, LOW);
  amarilloEncendido = false;
}

void encenderTodas() {
  encenderVerde();
  encenderRojo();
  encenderAmarillo();
}

void apagarTodas() {
  apagarVerde();
  apagarRojo();
  apagarAmarillo();
}

void intermitente() {
  for (int i = 0; i < 5; i++) {
    encenderTodas();
    delay(500);
    apagarTodas();
    delay(500);
  }
}
