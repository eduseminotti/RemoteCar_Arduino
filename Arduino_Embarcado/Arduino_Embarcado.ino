#include <Servo.h>


#define SERVO 9

Servo servo;

int centralWheel = 45;
int RightWheel = 75;
int leftWheel = 15;
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;

void back() {
  //Gira o Motor A no sentido horario
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  //Gira o Motor B no sentido horario
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void brake() {
  //Para o motor A
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  //Para o motor B
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
}

void front() {
  //Gira o Motor A no sentido anti-horario
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  //Gira o Motor B no sentido anti-horario
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}


void turnRight() {
  servo.write(RightWheel);
}

void centralizedWheel() {
  servo.write(centralWheel);
}

void turnLeft() {
  servo.write(leftWheel);
}


void setup() {

  servo.attach(SERVO);
  servo.write(centralWheel);

  //Define os pinos como saida
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

}

void loop() {

  front();
  delay(3000);
  brake();
  delay(500);
  back();
  delay(3000);
  brake();
  delay(500);
  turnRight();
  delay(3000);
  turnLeft();
  delay(3000);
  centralizedWheel();

}
