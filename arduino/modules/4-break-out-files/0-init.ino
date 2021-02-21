// Configure
float time_delay_after_dose = 600; // seconds delay between executing a dose and performing another on this plant.
float high_threshhold = 550; // this value and below means the soil is too dry.
float moisture_level = 0;

typedef struct {
  uint8_t lang;
  char* plant_name;
  int* relay_pinout;
  int* analog_pinout;
  int* dose_time;
} plant_group;

// This is where we define our plants and how they're configured.
// 	* incrementing number for indexing
// 	* name of the plant/plant group
// 	* pin number on the relay board eg "IN2", "IN3", just specify the number.
// 	* the analog pin name on the arduino board
//  * the number of miliseconds to run the pump to denote a single "dose", a dose must deliver 30ml of water.
const plant_group myPlantgroupArr[] {
  {0, "Test plant one", 2, A0, 4000},
  {1, "Test plant two", 3, A1, 8000}
};

void setup() {
  Serial.begin(9600);

  delay(1000);
  Serial.println("lets begin...");

  for(uint8_t i = 0; i < sizeof(myPlantgroupArr)/sizeof(plant_group); ++i) {
    pinMode(myPlantgroupArr[i].relay_pinout, OUTPUT);
    pinMode(myPlantgroupArr[i].analog_pinout, INPUT);
    digitalWrite(myPlantgroupArr[i].relay_pinout, HIGH);
  }
}
