#define BLYNK_TEMPLATE_ID "TMPL68l2xQTp7"
#define BLYNK_TEMPLATE_NAME "dud"
#define BLYNK_AUTH_TOKEN "H9BYVEC_jjUL0oPqGzMsWOfscFMb_i9N"
#define BLYNK_PRINT Serial 
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

//27 21 pwm
const int Motor1 = 12; //หลักขวา
const int Motor2 = 14;
const int Motor3 = 18; //หลักซ้าย
const int Motor4 = 19;
const int Motor5 = 0; //ปัดขวา
const int Motor6 = 2;
const int Motor7 = 4; //ปัดซ้าย
const int Motor8 = 16;
const int PWM1 = 27; //ขวา
const int PWM2 = 21; //ซ้าย
const int PWM3 = 2;
char auth[] = "H9BYVEC_jjUL0oPqGzMsWOfscFMb_i9N";
char ssid[] = "OPPO A60";
char pass[] = "12345678";

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  Blynk.begin(auth, ssid, pass);
  
  while (Blynk.connected() == false) {
    Serial.print(".");
    delay(1000);
  }
  
  Serial.println("\nConnected to Wi-Fi");

  pinMode(Motor1, OUTPUT);
  pinMode(Motor2, OUTPUT);
  pinMode(Motor3, OUTPUT);
  pinMode(Motor4, OUTPUT);
  pinMode(Motor5, OUTPUT);
  pinMode(Motor6, OUTPUT); 
  pinMode(Motor7, OUTPUT);
  pinMode(Motor8, OUTPUT);

  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
  pinMode(PWM3, OUTPUT);
}

void forward(){
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
  digitalWrite(Motor3, LOW);
  digitalWrite(Motor4, HIGH);
  analogWrite(PWM1, 50);
  analogWrite(PWM2, 50);
}

void backward(){
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, LOW);
  analogWrite(PWM1, 50);
  analogWrite(PWM2, 50);
}

void left(){
  digitalWrite(Motor1, HIGH);
  digitalWrite(Motor2, LOW);
  digitalWrite(Motor3, HIGH);
  digitalWrite(Motor4, LOW);
  analogWrite(PWM1, 50);
  analogWrite(PWM2, 50);
}

void right(){
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, HIGH);
  digitalWrite(Motor3, LOW);
  digitalWrite(Motor4, HIGH);
  analogWrite(PWM1, 50);
  analogWrite(PWM2, 50);
}

void stop(){
  digitalWrite(Motor1, LOW);
  digitalWrite(Motor2, LOW);
  digitalWrite(Motor3, LOW);
  digitalWrite(Motor4, LOW);
  analogWrite(PWM1, 50);
  analogWrite(PWM2, 50);
}


void cleaning1(){
  digitalWrite(Motor5, HIGH);
  digitalWrite(Motor6, LOW);
  digitalWrite(Motor7, LOW);
  digitalWrite(Motor8, HIGH);
  analogWrite(PWM3, 15);
}

BLYNK_WRITE(V0) {
  if (param[0]) {
    forward();
  } else {
    stop();
  }
}

BLYNK_WRITE(V1) {
  if (param[0]) {
    left();
  } else {
    stop();
  }
}

BLYNK_WRITE(V2) {
  if (param[0]) {
    right();
  } else {
    stop();
  }
}

BLYNK_WRITE(V3) {
  if (param[0]) {
    backward();
  } else {
    stop();
  }
}

void loop() {
  if (Blynk.connected()) {
    Blynk.run();
  } else {
    Serial.println("Disconnected from Blynk");
  }
cleaning1();
delay(1000);
}