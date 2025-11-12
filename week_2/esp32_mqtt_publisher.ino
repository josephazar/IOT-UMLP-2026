#include <WiFi.h>
#include <PubSubClient.h>

// WiFi credentials
const char* ssid = "OnePlus 8T";           // Replace with your WiFi SSID
const char* password = "cilios123";   // Replace with your WiFi password

// MQTT Broker settings
const char* mqtt_server = "10.185.170.189";     // Replace with your Raspberry Pi or PC IP address
const int mqtt_port = 1883;
const char* mqtt_user = "";                     // Leave empty if no authentication
const char* mqtt_password = "";                 // Leave empty if no authentication

// MQTT Topics
const char* temperature_topic = "esp32/temperature";
const char* humidity_topic = "esp32/humidity";

// Client ID
const char* client_id = "ESP32_Publisher";

// Create WiFi and MQTT client objects
WiFiClient espClient;
PubSubClient client(espClient);

// Variables for sensor simulation
float temperature = 20.0;
float humidity = 50.0;
unsigned long lastMsg = 0;
const long interval = 5000;  // Publish every 5 seconds

// Function prototypes
void setup_wifi();
void reconnect();
float simulateTemperature();
float simulateHumidity();

void setup() {
  // put your setup code here, to run once:
  // put your main code here, to run repeatedly:
  Serial.begin(115200);
  delay(10);
  
  Serial.println();
  Serial.println("ESP32 MQTT Publisher - Temperature & Humidity");
  Serial.println("==============================================");
  
  // Connect to WiFi
  setup_wifi();
  
  // Configure MQTT
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
   // Ensure MQTT connection
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Publish sensor data at regular intervals
  unsigned long now = millis();
  if (now - lastMsg > interval) {
    lastMsg = now;
    
    // Simulate sensor readings
    temperature = simulateTemperature();
    humidity = simulateHumidity();
    
    // Convert to strings
    char tempString[8];
    char humString[8];
    dtostrf(temperature, 1, 2, tempString);
    dtostrf(humidity, 1, 2, humString);
    
    // Publish temperature
    Serial.print("Publishing temperature: ");
    Serial.print(tempString);
    Serial.print("°C to topic: ");
    Serial.println(temperature_topic);
    client.publish(temperature_topic, tempString);
    
    // Publish humidity
    Serial.print("Publishing humidity: ");
    Serial.print(humString);
    Serial.print("% to topic: ");
    Serial.println(humidity_topic);
    client.publish(humidity_topic, humString);
    
    Serial.println("---");
  }
}

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println();
  Serial.println("WiFi connected!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  Serial.print("Signal strength (RSSI): ");
  Serial.print(WiFi.RSSI());
  Serial.println(" dBm");
}


void reconnect() {
  // Loop until reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    
    // Attempt to connect
    if (client.connect(client_id, mqtt_user, mqtt_password)) {
      Serial.println("connected!");
      Serial.print("Client ID: ");
      Serial.println(client_id);
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" - retrying in 5 seconds");
      delay(5000);
    }
  }
}
// Simulate realistic temperature readings (18°C to 28°C with smooth variations)
float simulateTemperature() {
  static float temp = 22.0;
  float variation = (random(-100, 100)) / 100.0;  // Random variation ±1°C
  temp += variation * 0.1;  // Smooth changes
  
  // Keep within realistic bounds
  if (temp < 18.0) temp = 18.0;
  if (temp > 28.0) temp = 28.0;
  
  return temp;
}

// Simulate realistic humidity readings (40% to 70% with smooth variations)
float simulateHumidity() {
  static float hum = 55.0;
  float variation = (random(-100, 100)) / 100.0;  // Random variation ±1%
  hum += variation * 0.2;  // Smooth changes
  
  // Keep within realistic bounds
  if (hum < 40.0) hum = 40.0;
  if (hum > 70.0) hum = 70.0;
  
  return hum;
}
