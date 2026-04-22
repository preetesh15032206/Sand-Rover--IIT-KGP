// Sand Rover Arduino Code
// Bluetooth Controlled 4WD Rover using HC-05 and L298N

#include <SoftwareSerial.h>

SoftwareSerial BT(2, 3); // RX, TX

// LEFT motors (Driver 1)
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
int ENA = 9;
int ENB = 10;

// RIGHT motors (Driver 2)
int IN5 = 8;
int IN6 = 11;
int IN7 = 12;
int IN8 = 13;

int speedVal = 150;

void setup() {
  BT.begin(9600);

  pinMode(IN1, OUTPUT); pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT); pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT); pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT); pinMode(IN8, OUTPUT);

  pinMode(ENA, OUTPUT); pinMode(ENB, OUTPUT);
}

void loop() {
  if (BT.available()) {
    char cmd = BT.read();
    handleCommand(cmd);
  }
}

void setSpeed() {
  analogWrite(ENA, speedVal);
  analogWrite(ENB, speedVal);
}

void stopAll() {
  digitalWrite(IN1, LOW); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW); digitalWrite(IN8, LOW);
}

void forward() {
  setSpeed();
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}

void back() {
  setSpeed();
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}

void left() {
  setSpeed();
  digitalWrite(IN1, LOW); digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW); digitalWrite(IN4, HIGH);
  digitalWrite(IN5, HIGH); digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH); digitalWrite(IN8, LOW);
}

void right() {
  setSpeed();
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW); digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW); digitalWrite(IN8, HIGH);
}

void handleCommand(char cmd) {
  switch(cmd) {
    case 'F': forward(); break;
    case 'B': back(); break;
    case 'L': left(); break;
    case 'R': right(); break;

    case 'G': forward(); delay(100); left(); break;
    case 'I': forward(); delay(100); right(); break;
    case 'H': back(); delay(100); left(); break;
    case 'J': back(); delay(100); right(); break;

    case 'S': stopAll(); break;
    case 'D': stopAll(); break;

    // Speed control
    case '0': speedVal = 0; break;
    case '1': speedVal = 100; break;
    case '2': speedVal = 120; break;
    case '3': speedVal = 140; break;
    case '4': speedVal = 160; break;
    case '5': speedVal = 180; break;
    case '6': speedVal = 200; break;
    case '7': speedVal = 220; break;
    case '8': speedVal = 240; break;
    case '9': speedVal = 255; break;
    case 'q': speedVal = 255; break;
  }
}
