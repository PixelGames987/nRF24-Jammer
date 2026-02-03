# nRF24 Jammer

## Wiring:

| ESP32 WROOM-32 Pin | nRF24L01+ Pin | Notes |
|---------------------|----------------------|-------|
| 3V3                | VCC                 | Power (3.3V) |
| GND                | GND                 | Ground |
| GPIO 12            | CE                  | Chip Enable |
| GPIO 5             | CSN                 | Chip Select / Slave Select |
| GPIO 18            | SCK                 | SPI Clock |
| GPIO 23            | MOSI                | SPI Master Out Slave In |
| GPIO 19            | MISO                | SPI Master In Slave Out |
| (Not connected)    | IRQ                 | Interrupt (optional) |
