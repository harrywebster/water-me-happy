// Pinout
int IN1 = 2;
int Pin1 = A0;

// Configure
float moisture0 = 0;
float high_threshhold = 550;

// Init the app with all our initial states of switches.
void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(Pin1, INPUT);
  digitalWrite(IN1, HIGH);

  delay(1000);
}

void loop() {
  Serial.print("Is the sensor IN or OUT our test glass of water? - ");

  moisture0 = analogRead(Pin1);
  Serial.println(moisture0);

  if(moisture0 < high_threshhold) {
    Serial.println("\tIN the water - pump ON");
    digitalWrite(IN1, LOW);
  }
  else{
    Serial.println("\tOUT of water - pump OFF");
    digitalWrite(IN1, HIGH);
  }

  Serial.println();
  delay(1000);
}
