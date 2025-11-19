const mqtt = require('mqtt');

// MQTT Broker settings
const mqttServer = 'mqtt://localhost:1883'; // Change to your broker IP if needed
const mqttOptions = {
  clientId: 'NodeJS_Publisher',
  username: '', // Leave empty if no authentication
  password: '', // Leave empty if no authentication
};

// MQTT Topics
const temperatureTopic = 'esp32/temperature';
const humidityTopic = 'esp32/humidity';

// Publish interval (ms)
const interval = 5000;

// Sensor simulation variables
let temperature = 22.0;
let humidity = 55.0;

// Connect to MQTT broker
const client = mqtt.connect(mqttServer, mqttOptions);

client.on('connect', () => {
  console.log('MQTT connected!');
  console.log(`Client ID: ${mqttOptions.clientId}`);
  console.log('==============================================');

  // Start publishing at regular intervals
  setInterval(publishSensorData, interval);
});

client.on('error', (err) => {
  console.error('MQTT connection error:', err.message);
});

client.on('reconnect', () => {
  console.log('Attempting MQTT connection...');
});

function publishSensorData() {
  // Simulate sensor readings
  temperature = simulateTemperature();
  humidity = simulateHumidity();

  // Convert to strings with 2 decimal places
  const tempString = temperature.toFixed(2);
  const humString = humidity.toFixed(2);

  // Publish temperature
  console.log(`Publishing temperature: ${tempString}°C to topic: ${temperatureTopic}`);
  client.publish(temperatureTopic, tempString);

  // Publish humidity
  console.log(`Publishing humidity: ${humString}% to topic: ${humidityTopic}`);
  client.publish(humidityTopic, humString);

  console.log('---');
}

// Simulate realistic temperature readings (18°C to 28°C with smooth variations)
function simulateTemperature() {
  const variation = (Math.random() * 2 - 1); // Random variation ±1°C
  temperature += variation * 0.1; // Smooth changes

  // Keep within realistic bounds
  if (temperature < 18.0) temperature = 18.0;
  if (temperature > 28.0) temperature = 28.0;

  return temperature;
}

// Simulate realistic humidity readings (40% to 70% with smooth variations)
function simulateHumidity() {
  const variation = (Math.random() * 2 - 1); // Random variation ±1%
  humidity += variation * 0.2; // Smooth changes

  // Keep within realistic bounds
  if (humidity < 40.0) humidity = 40.0;
  if (humidity > 70.0) humidity = 70.0;

  return humidity;
}

// Handle graceful shutdown
process.on('SIGINT', () => {
  console.log('\nDisconnecting from MQTT broker...');
  client.end();
  process.exit();
});
