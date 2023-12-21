const int relay_Pin = 2;
const int boton_Pin = 3;
const int led_partida_Pin = 9;  // PWM
const int sensor_Pin = 0; // sensor de partida

unsigned long previousMillis = 0;

int relay_state = LOW;
int boton = LOW;
int intervalo = 1000;
int sensor = 1023;
int wait = HIGH;
int luz = 0;
int fade = 1;


void setup() {
  
pinMode(relay_Pin, OUTPUT);
pinMode(boton_Pin, INPUT);
pinMode(led_partida_Pin, OUTPUT);
pinMode(LED_BUILTIN, OUTPUT);

analogWrite(led_partida_Pin,0);
}

void loop() {

sensor = analogRead(sensor_Pin);
wait = (sensor>500);

if (!wait) {
  luz = 255;
  fade = -1;
  boton = digitalRead(boton_Pin);
  if (boton) {
  analogWrite(led_partida_Pin, 0);
  luz = 0;
  fade = 1;
  digitalWrite(relay_Pin, HIGH);
  delay(5000);
  digitalWrite(relay_Pin, LOW);
}
  
}

else{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 5) {
    previousMillis = currentMillis;
    
  luz = luz + fade;
  if (luz <= 0 || luz >= 255) {
    fade = -fade;
  }
  }
}

analogWrite(led_partida_Pin, luz);
/*sensor = analogRead(sensor_Pin);

if (sensor<500) {
  analogWrite(led_partida_Pin, 255);
}
else {
  analogWrite(led_partida_Pin, 0);
}

boton = digitalRead(boton_Pin);

if (boton) {
  digitalWrite(relay_Pin, HIGH);
  delay(5000);
  digitalWrite(relay_Pin, LOW);
}

delay (10);*/

}
