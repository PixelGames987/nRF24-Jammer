#include <SPI.h>
#include <RF24.h>
#define CE_PIN 12
#define CSN_PIN 5
#define LED_PIN 2
RF24 radio(CE_PIN, CSN_PIN);
// channels 37, 38, 39 for advertising + data channels 0-36 (mapped to RF channels 2-80)
byte ble_channels[] = {2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21,
                       22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41};
// BLE advertising priority channels
byte ble_adv_priority[] = {37, 38, 39, 1, 2, 3, 25, 26, 27, 79, 80, 81};
// Full Bluetooth Classic
byte bluetooth_channels[] = {2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13, 14, 15, 16, 17,
                             18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33,
                             34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
                             50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65,
                             66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80};
byte* current_channels = ble_adv_priority;
uint8_t channel_count = sizeof(ble_adv_priority);
volatile uint8_t current_channel_index = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(CSN_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(CSN_PIN, HIGH);
  SPI.begin();
  SPI.setFrequency(15000000); // Try 15MHz, fallback to 10MHz if unstable
  SPI.setDataMode(SPI_MODE0);
  SPI.setBitOrder(MSBFIRST);
  if (!radio.begin()) {
    Serial.println("ERROR: nRF24L01 module not found!");
    while(1) {
      digitalWrite(LED_PIN, HIGH);
      delay(100);
      digitalWrite(LED_PIN, LOW);
      delay(100);
    }
  }
  Serial.println("nRF24L01+PA+LNA initialized successfully");
  
  radio.setPALevel(RF24_PA_MAX);
  radio.setAddressWidth(3);
  radio.setPayloadSize(1);
  if (!radio.setDataRate(RF24_2MBPS)) {
    Serial.println("Warning: Could not set 2Mbps data rate");
  }
  radio.setAutoAck(false);
  radio.setRetries(0, 0);
  // Start constant carrier
  radio.startConstCarrier(RF24_PA_MAX, current_channels[0]);
  Serial.print("Channels: ");
  for(int i = 0; i < channel_count; i++) {
    Serial.print(current_channels[i]);
    Serial.print(" ");
  }
  Serial.println("Starting hopping...");
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  if (++current_channel_index >= channel_count) current_channel_index = 0;
  
  // Direct SPI write to RF_CH
  digitalWrite(CSN_PIN, LOW);
  SPI.transfer(0x25);
  SPI.transfer(current_channels[current_channel_index]);
  digitalWrite(CSN_PIN, HIGH);
}
