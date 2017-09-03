//import libraries needed to communicate with sensors and serial port of 
PC 
#include <VirtualWire.h> 
#include <dht.h> 
#define dht_dpin A0 
dht DHT; 
//initializing variables for controlling motor, serial communication and 
transmission 
intledPin=13; 
intmatlabData; 
constintled_pin = 6; 
constinttransmit_pin = 12; 
constintreceive_pin = 11; 
constinttransmit_en_pin = 3; 
int Sensor1Data; 
int stopper; 
// RF Transmission container 
char Sensor1CharMsg[4]; 
//Setup Arduino for serial communication and reception 
void setup() 
{ 
delay(1000); 
pinMode(ledPin,OUTPUT); 
Serial.begin(9600); // Debugging only 
 //Serial.println("setup"); 
 // Initialise the IO and ISR 
vw_set_tx_pin(transmit_pin); 
vw_set_rx_pin(receive_pin); 
vw_set_ptt_pin(transmit_en_pin); 
vw_set_ptt_inverted(true); // Required for DR3100 
vw_setup(2000); // Bits per second 
vw_rx_start(); // Start the receiver PLL running 
} 
 
void loop() 
{ 
if(Serial.available()>0) // if there is data to read 
 { 
matlabData=Serial.read(); // read data 
if(matlabData==1) 
digitalWrite(ledPin,HIGH); // turn on motor 
else if(matlabData==2) 
digitalWrite(ledPin,LOW); // turn off motor 
 } 
 //Read temperature and humidity and print on serial port 
DHT.read11(dht_dpin); 
delay(500); 
Serial.print(DHT.humidity); 
Serial.print("\n\r"); 
delay(300); 
Serial.print(DHT.temperature); 
Serial.print("\n\r"); 
stopper=1; 
 
 
while(stopper) 
{ 
uint8_tbuf[VW_MAX_MESSAGE_LEN]; 
uint8_tbuflen = VW_MAX_MESSAGE_LEN; 
if (vw_get_message(buf, &buflen)) // If Non-blocking message 
 { 
 inti; 
 
digitalWrite(led_pin, HIGH); // Flash a light to show received good 
message 
 // Message with a good checksum received, print it after 
converting to a number. 
 
 for (i = 0; i<buflen; i++) 
 { 
Sensor1CharMsg[i] = char(buf[i]); 
 } 
Sensor1CharMsg[buflen] = '\0'; 
digitalWrite(led_pin, LOW); 
 Sensor1Data = atoi(Sensor1CharMsg); 
 
if(stopper == 2 && Sensor1Data < 100) 
 { 
stopper=0; 
Serial.println(Sensor1Data); 
 } 
else if(stopper == 1 && Sensor1Data > 100 ) 

 { 
stopper=2; 
Serial.println(Sensor1Data); 
 } 
 } 
} 
} 