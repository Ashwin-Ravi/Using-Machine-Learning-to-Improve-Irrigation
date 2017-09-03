// Import libraries for integration with sensor. 
#include <VirtualWire.h> 
#include <OneWire.h> 
#include <DallasTemperature.h> 
 
 
// Data wire is plugged into pin 3 on the Arduino 
#define ONE_WIRE_BUS 3 
 
// Setup a oneWire instance to communicate with any OneWire devices 
OneWireoneWire(ONE_WIRE_BUS); 
 
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperaturesensors(&oneWire); 
 
// Initialize all variables needed for transmission and to store sensor 
data 
constintled_pin = 13; 
constinttransmit_pin = 12; 
constintreceive_pin = 2; 
constinttransmit_en_pin = 4; 
constint Sensor1Pin = A0; 
constint Sensor1Pin2 = A1; 
int Sensor1Data; // Moisture sensor data 
int Sensor1Data2;// Soil Temperature data 
char Sensor1CharMsg[4]; 
char Sensor1CharMsg2[4]; 
 
//Store address of the temperature sensor in a variable 
DeviceAddressinsideThermometer = { 0x28, 0xFF, 0x4A, 0xA3, 0x55, 0x14, 
0x03, 0x46 }; 
 
void setup() 
{ 
 // start serial port 
Serial.begin(9600); 
 // Start up the library 
sensors.begin(); 
 // set the resolution to 10 bit (good enough?) 
sensors.setResolution(insideThermometer, 10); 
 // Initialise the IO and ISR for transmission 
vw_set_tx_pin(transmit_pin); 
vw_set_rx_pin(receive_pin); 
vw_set_ptt_pin(transmit_en_pin); 
vw_set_ptt_inverted(true); // Required for DR3100 
vw_setup(2000); // Bits per sec 
pinMode(Sensor1Pin,INPUT); 
} 
 
byte count = 1; 
inttempC; 
 
//Function to get Temperature values from the sensor 
voidprintTemperature(DeviceAddressdeviceAddress) 
{ 
tempC = sensors.getTempC(deviceAddress); 
if (tempC == -127.00) { 
Serial.print("Error getting temperature"); 
 } 
 
 
void loop() 
{ 
delay(500); 
sensors.requestTemperatures(); // Get sensor values 
printTemperature(insideThermometer); 
 Sensor1Data = analogRead(Sensor1Pin); // Get moisture values 
itoa(Sensor1Data,Sensor1CharMsg,10); 
itoa(tempC,Sensor1CharMsg2,10); 
digitalWrite(led_pin, HIGH); // Flash a light to show transmitting 
 
//Start Transmission of data from both sensors 
vw_send((uint8_t *)Sensor1CharMsg, strlen(Sensor1CharMsg)); 
vw_wait_tx(); // Wait until the whole message is gone 
digitalWrite(led_pin, LOW); 
Serial.println(Sensor1CharMsg); 
delay(1000); 
digitalWrite(led_pin, HIGH); // Flash a light to show transmitting 
vw_send((uint8_t *)Sensor1CharMsg2, strlen(Sensor1CharMsg2)); 
vw_wait_tx(); // Wait until the whole message is gone 
digitalWrite(led_pin, LOW); 
Serial.println(Sensor1CharMsg2); 
delay(1000); 
}