<div align="center">
  
# nRF24 Jammer
<img src="/image.jpg" alt="Jammer image" width="350">
<br><br>
Many nRF24 modules will work better for jamming when selecting only a few channels in a non-sequential order rather than selecting all of them. This is why this code only jams 12 channels out of 79.
<br><br>
This jammer is also effective against WiFi networks on channels 1-13.
<br><br>
The jammer uses around 1W while active. With a small 150 mAh battery expect around 30min of use: 150mAh / 1W ≈ 30min
<br><br>
This is a relatively low-power device. Do not expect good jamming performance at distances greater than 10 meters.
<br><br>
<img src="/spectrum.jpg" alt="Jammer spectrum analysis" width="600">
<br><br>

## Parts List:
<table align="center">
<thead>
<tr>
<th>Item</th>
<th>Quantity</th>
</tr>
</thead>
<tbody>
<tr>
<td>ESP32 WROOM-32 Dev Board</td>
<td>1</td>
</tr>
<tr>
<td>nRF24L01+ PA+LNA Module</td>
<td>1</td>
</tr>
<tr>
<td>Jumper Cables</td>
<td>7</td>
</tr>
</tbody>
</table>
<br><br>

## Wiring:
<table align="center">
<thead>
<tr>
<th>ESP32 WROOM-32 Pin</th>
<th>nRF24L01+ Pin</th>
<th>Notes</th>
</tr>
</thead>
<tbody>
<tr>
<td>3V3</td>
<td>VCC</td>
<td>Power (3.3V)</td>
</tr>
<tr>
<td>GND</td>
<td>GND</td>
<td>Ground</td>
</tr>
<tr>
<td>GPIO 12</td>
<td>CE</td>
<td>Chip Enable</td>
</tr>
<tr>
<td>GPIO 5</td>
<td>CSN</td>
<td>Chip Select / Slave Select</td>
</tr>
<tr>
<td>GPIO 18</td>
<td>SCK</td>
<td>SPI Clock</td>
</tr>
<tr>
<td>GPIO 23</td>
<td>MOSI</td>
<td>SPI Master Out Slave In</td>
</tr>
<tr>
<td>GPIO 19</td>
<td>MISO</td>
<td>SPI Master In Slave Out</td>
</tr>
<tr>
<td>(Not connected)</td>
<td>IRQ</td>
<td>Interrupt (optional)</td>
</tr>
</tbody>
</table>

## Flashing Tutorial
### 1. Install Arduino IDE
Follow the instructions on the [Arduino Website](https://www.arduino.cc/en/software)
<br>
### 2. Add ESP32 Board Support and libraries
Go into the Boards Manager in the left side panel, search for "esp32" (the one by Espressif systems, not Arduino) and click install

Go into the Library Manager in same panel, search for "RF24" and click install
<br>
### 3. Compile and flash
Paste the code from the [nrf_jammer.ino](/nrf_jammer.ino) file into the Arduino IDE project

Hold down the "BOOT" button on the esp32 and plug it into the pc

(If you are on linux you need to run `sudo chmod 777 /dev/ttyUSB0`)

On the top board selection press "Select other board and port...", search for "ESP32 Dev Module", select the available port and press OK

Press the "Upload" button to start flashing
<br>

</div>
