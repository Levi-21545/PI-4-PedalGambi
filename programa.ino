#include <SPI.h>

const int csPin = 5; // Pino CS do MCP3008 conectado ao pino GPIO 5
const int adcChannel = 1; // Canal do MCP3008 usado para captar o sinal

void setup() {
  Serial.begin(115200);
  SPI.begin(18, 19, 23, csPin); // Clock: 18, MISO: 19, MOSI: 23, CS: 5
  pinMode(csPin, OUTPUT);
  digitalWrite(csPin, HIGH);
}

int readADC(int channel) {
  digitalWrite(csPin, LOW);
  
  byte command = 0b00011000 | (channel & 0x07);
  SPI.transfer(command); 
  int adcValue = (SPI.transfer(0x00) & 0x03) << 8;
  adcValue |= SPI.transfer(0x00);
  
  digitalWrite(csPin, HIGH);
  return adcValue;
}

void loop() {
  int sample = readADC(adcChannel); 
  byte highByte = (sample >> 8) & 0xFF; // Byte mais significativo
  byte lowByte = sample & 0xFF;         // Byte menos significativo
  
  // Envia ambos os bytes pela Serial
  Serial.write(highByte);
  Serial.write(lowByte);
  delayMicroseconds(125); // Ajuste do intervalo de amostragem (~8kHz)
}
