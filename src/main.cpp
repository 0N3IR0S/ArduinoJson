#include <Arduino.h>
/*
Description:  Small example for the ArduinoJson library.
License:      This project is licensed under the terms of the MIT license.
Github:       https://github.com/0N3IR0S/ArduinoJson

Author:   Benjamin Buerge
Created:  20.10.2020
*/
#include <ArduinoJson.h>

// FUNCTIONS
void sendJson()
{
    static unsigned long lastMillis;
    if (millis() - lastMillis >= 1000)
    {
        char buffer[64];                // buffer to store json
        StaticJsonDocument<78> doc;     // reserves memory in stack, for bigger files than 1kb, use DynamicJsonDocument
        doc["temperature"] = 23.4;
        doc["humidity"] = 41.1;
        doc["pressure"] = 95.52;
        serializeJson(doc, buffer);
        Serial.println(buffer);

        lastMillis = millis();
    }
}

// SETUP
void setup()
{
    Serial.begin(115200);
    Serial.println(F("Serial Monitor started!"));
}

// MAIN LOOP
void loop()
{
    sendJson();
}
