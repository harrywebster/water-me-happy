void loop() {

  for(uint8_t i = 0; i < sizeof(myPlantgroupArr)/sizeof(plant_group); ++i) {

      moisture_level = analogRead(myPlantgroupArr[i].analog_pinout);

			Serial.print(myPlantgroupArr[i].plant_name);
      Serial.println(moisture_level);

      if(moisture_level < high_threshhold) {
        if (myPlantgroupArr[i].dont_rewater == 0) {
        	//myPlantgroupArr[i].dont_rewater = time_delay_after_dose;

          Serial.println("\tPlant group is IN the water - pump ON");

          digitalWrite(myPlantgroupArr[i].relay_pinout, LOW);
          delay(myPlantgroupArr[i].dose_time);
          digitalWrite(myPlantgroupArr[i].relay_pinout, HIGH);
        }
        else{
         // if (myPlantgroupArr[i].dont_rewater > 0 ) myPlantgroupArr[i].dont_rewater--;
          Serial.println("\tPlant group would be rewatered, but still within delay");
         // Serial.println(myPlantgroupArr[i].dont_rewater);
        }
      }
      else{
        Serial.println("\tPlant group ONE is OUT of the water - pump OFF");
        digitalWrite(myPlantgroupArr[i].relay_pinout, HIGH);
      }
  }

  delay(4000);
}
