// Pinout
int IN1 = 2;
int IN2 = 3;
int Pin1 = A0;
int Pin2 = A1;

// Configure
float moisture1 = 0;
float moisture2 = 0;

float high_threshhold = 550;

// Init the app with all our initial states of switches.
void setup() {
  Serial.begin(9600);

  // Plant group one
  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);

  // Plant group two
  pinMode(IN2, OUTPUT);
  pinMode(Pin2, INPUT);
  digitalWrite(IN2, HIGH);

  delay(1000);
}

void loop() {

  moisture1 = analogRead(Pin1);
  moisture2 = analogRead(Pin2);

  formatPrint("Is the sensor IN or OUT our test glass of water? - PG1:", moisture1, " - PG2:", moisture2);
  Serial.println();

  if(moisture1 < high_threshhold) {
    Serial.println("\tPlant group ONE is IN the water - pump ON");
    digitalWrite(IN1, LOW);
  }
  else{
    Serial.println("\tPlant group ONE is OUT of the water - pump OFF");
    digitalWrite(IN1, HIGH);
  }

  if(moisture2 < high_threshhold) {
    Serial.println("\tPlant group TWO is IN the water - pump ON");
    digitalWrite(IN2, LOW);
  }
  else{
    Serial.println("\tPlant group TWO is OUT of the water - pump OFF");
    digitalWrite(IN2, HIGH);
  }

  Serial.println();
  delay(1000);
}

void formatPrint( char *leftStr, int MyVar1, char *sepStr, int MyVar2){
     Serial.print (leftStr);
     Serial.print (MyVar1);
     Serial.print (sepStr);
     Serial.print (MyVar2);
}
