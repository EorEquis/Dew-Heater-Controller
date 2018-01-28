/******************************
* Simple dew heater controller.
* 
* Reads a DHT22 for humidity, and if humidity is
* over a certain level, turns the dew heater on.
* Otherwise, turns it off.
*******************************/

//Libraries
#include <DHT.h>;

//Constants
#define DHTPIN 7              // DHT Data pin           - Green
#define DHTTYPE DHT22         // DHT 22  (AM2302)
#define heaterPin 9           // Base pin on TIP120     - Yellow
DHT dht(DHTPIN, DHTTYPE);     // Initialize DHT


//Variables
float hum;                    // Stores humidity value
float humLimit = 80;          // Max humidity before heater is enabled.  Float for easier testing, could be int
long readDelay = 30000;         // Milliseconds between reads.  The heater could, conceivably, cycle every time DHT is read.  Set with caution.
void setup()
{
//  Serial.begin(9600);         // Needed for initial testing/troubleshooting
  dht.begin();
}

void loop()
{
    // Read humidity and store in hum
    hum = dht.readHumidity();

    //Print humidity and heater state for testing
    if (hum > humLimit)
      {
        analogWrite(heaterPin, 255);
//        Serial.print("Humidity: ");
//        Serial.print(hum);
//        Serial.println(" % - Heater is on.");
      }
    else
      {
        analogWrite(heaterPin, 0);
//        Serial.print("Humidity: ");
//        Serial.print(hum);
//        Serial.println(" % - Heater is off.");
      }

    // Delay before reading again
    delay(readDelay); 
}

    
