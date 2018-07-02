int interval = 256;

int val = 0;

// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A0, INPUT);
}

// the loop function runs over and over again forever
void loop() {
  val = analogRead(A0);
  Serial.println(val);
  
  if(val < 20) {
    analogWrite(3,255);
    enableLeds(0);
  }
  else if(val < interval) {
    analogWrite(3,192);
    enableLeds(1);
  } else if (val < interval*2) {
    analogWrite(3,128);
    enableLeds(2);
  } else if (val < interval*3) {
    analogWrite(3,64);
   enableLeds(3);
  } else {
    analogWrite(3,0);
    enableLeds(4);
  }
}

void enableLeds(int value) {

  switch(value){
    case 0:
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, HIGH);
      break;
    case 1:
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, HIGH);
      digitalWrite(A4, LOW);
      break;
    case 2:
      digitalWrite(A1, HIGH);
      digitalWrite(A2, HIGH);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      break;
    case 3:
      digitalWrite(A1, HIGH);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      break;
    case 4:
      digitalWrite(A1, LOW);
      digitalWrite(A2, LOW);
      digitalWrite(A3, LOW);
      digitalWrite(A4, LOW);
      break;
  }
  
}

