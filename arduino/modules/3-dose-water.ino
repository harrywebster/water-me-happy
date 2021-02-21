// Pinout
int IN1 = 2;
int IN2 = 3;
int Pin1 = A0;
int Pin2 = A1;
float moisture1 = 0;
float moisture2 = 0;
float dont_rewater1 = 0;
float dont_rewater2 = 0;

// Configure
float time_delay_after_dose = 600; // seconds delay between executing a dose and performing another on this plant.
float high_threshhold = 550; // this value and below means the soil is too dry.

// Number of miliseconds to pump water to achieve a single "dose" aka 30ml.
float dose1 = 4000;
float dose2 = 8000; // this would suggest the water in pump two has further to travel, fight gravity or the pump is not as powerful.

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
    if (dont_rewater1 == 0) {
      dont_rewater1 = time_delay_after_dose;
      Serial.println("\tPlant group ONE is IN the water - pump ON");

      digitalWrite(IN1, LOW);
      delay(dose1);
      digitalWrite(IN1, HIGH);
    }
    else{
      if (dont_rewater1 > 0 ) dont_rewater1--;
      Serial.println("\tPlant group ONE would be rewatered, but still within delay");
      Serial.println(dont_rewater1);
    }
  }
  else{
    Serial.println("\tPlant group ONE is OUT of the water - pump OFF");
    digitalWrite(IN1, HIGH);
  }

  if(moisture2 < high_threshhold) {
    if (dont_rewater2 == 0) {
      dont_rewater2 = time_delay_after_dose;
      Serial.println("\tPlant group TWO is IN the water - pump ON");

      digitalWrite(IN2, LOW);
      delay(dose2);
      digitalWrite(IN2, HIGH);
    }
    else{
      if (dont_rewater2 > 0 ) dont_rewater2--;
      Serial.println("\tPlant group TWO would be rewatered, but still within delay");
      Serial.println(dont_rewater2);
    }
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
