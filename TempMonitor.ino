#include "DHT.h"
#include "WiFiEsp.h" //Fixed Library
#include <ThingSpeak.h> // Include library for ThingSpeak (or similar for Blynk/ThingsBoard)
#include "SoftwareSerial.h"

SoftwareSerial softSerial(4,5);

//Define DHT settings
#define DHTPIN 2  // Pin connected to the DHT11
#define DHTTYPE DHT11  // DHT 11 sensor
DHT dht(DHTPIN, DHTTYPE);

// Wi-Fi credentials
const char* ssid = "";  // Wi-Fi SSID
const char* password = "";  // Wi-Fi password

// ThingSpeak settings
unsigned long myChannelNumber = ;  // ThingSpeak Channel Number
const char* myWriteAPIKey = "";  // ThingSpeak Write API Key

// Initialize WiFi client
WiFiEspClient client;

void setup() {
  Serial.begin(9600);  // Initialize serial communication
  dht.begin(); //Start reading the DHT sensor 

  // Connect to Wi-Fi
  softSerial.begin(115200);
  softSerial.write("AT+CIOBAUD=9600r\r\n");
  softSerial.write("AT+RST\r\n");
  softSerial.begin(9600);
  WiFi.init(&softSerial);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
}

void loop() {
  // Read temperature and humidity
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  //check if reading failed
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Print temperature to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Send data to ThingSpeak
  ThingSpeak.setField(1, temperature);
  ThingSpeak.setField(2, humidity);
  int response = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);

  delay(20000);  // Wait 20 seconds before sending new data
}
