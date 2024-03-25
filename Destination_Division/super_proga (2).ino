int ch1 = 0;
int ch2 = 0;
int ch3 = 0;
int ch4 = 0;
int ch5 = 0;
int ch6 = 0;
int speedL = 0;
int speedR = 0;
int pin4 = 4;
int pin5 = 5;
int pin6 = 6;
int pin7 = 7;
int enA = 8;
int in1 = 10;
int in2 = 9;
int pulls = 0;
int pulls2 = 0;
int pulls3 = 0;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(pin6, OUTPUT);
  pinMode(pin7, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
  pinMode(A10, INPUT);
  Serial.begin(9600);
  analogWrite(enA, 0);
}

void loop() {
  pulls = pulseIn(A1, 100000);
  pulls2 = pulseIn(A2, 100000);
  pulls3 = pulseIn(A10, 100000);
  if (pulseIn(A1, 100000) <= 970){
  pulls = 970;  
  }
  if (pulseIn(A1, 100000) >= 2025){
  pulls = 2025;  
  }
  if (pulseIn(A2, 100000) <= 970){
  pulls2 = 970;  
  }
  if (pulseIn(A2, 100000) >= 2025){
  pulls2 = 2025;  
  }
  if (pulseIn(A10, 100000) <= 970){
  pulls3 = 970;  
  }
  if (pulseIn(A10, 100000) >= 2025){
  pulls3 = 2025;  
  }
  ch1 = map(pulls, 970, 2025, -255, 255);
  ch2 = map(pulls2, 970, 2025, -255, 255);
  ch6 = map(pulls3, 970, 2025, 0, 255);
  
  analogWrite(enA, 0);

  speedR = ch2 + ch1;
  speedL = ch2 - ch1;
  analogWrite(pin5, abs(speedL));
  analogWrite(pin6, abs(speedR));
  
  if (speedR < 15) {
    digitalWrite(pin7, 1);
  }
  else { 
    digitalWrite(pin7, 0);
}

  if (speedL < 15 ) {
    digitalWrite(pin4, 1);
  }
  else { 
    digitalWrite(pin4, 0);
  }
  
  Serial.println(ch6);
  if (ch6 < 30){
  analogWrite(enA, 200);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  }

  if (ch6 > 150){
  analogWrite(enA, 200);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}
}
