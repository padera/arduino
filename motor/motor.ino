const int OUT_DIR_LEFT  = 2;
const int OUT_DIR_RIGHT = 3;
const int OUT_MOTOR = 9;
const int IN_ON_OFF = 5;
const int IN_DIR = 4;
const int IN_SPEED = A0;

boolean isOn = false;
boolean isTurningLeft = true;

int motorSpeed = 0;

void setup() {
  pinMode(IN_ON_OFF, INPUT);
  pinMode(IN_DIR, INPUT);
  pinMode(OUT_MOTOR, OUTPUT);
  pinMode(OUT_DIR_LEFT, OUTPUT);
  pinMode(OUT_DIR_RIGHT, OUTPUT);
  digitalWrite(OUT_MOTOR, LOW);
}

void loop() {
  isOn = digitalRead(IN_ON_OFF) == HIGH ? !isOn : isOn;
  delay(1);
  isTurningLeft = digitalRead(IN_DIR) == HIGH ? !isTurningLeft : isTurningLeft;
  motorSpeed = analogRead(IN_SPEED) / 4;
  digitalWrite(OUT_DIR_LEFT, isTurningLeft ? HIGH : LOW);
  digitalWrite(OUT_DIR_RIGHT, isTurningLeft ? LOW : HIGH);
  analogWrite(OUT_MOTOR, isOn ? motorSpeed : 0);
}

