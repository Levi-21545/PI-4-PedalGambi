import serial
import pyaudio
import struct

# Configuração da porta Serial
serial_port = 'COM11' 
baud_rate = 115200
ser = serial.Serial(serial_port, baud_rate)

# Configuração do áudio
p = pyaudio.PyAudio()
sample_rate = 8000  # Taxa de amostragem para reprodução
channels = 1        # Mono
format = pyaudio.paInt16

stream = p.open(format=format, channels=channels, rate=sample_rate, output=True)

try:
    while True:
        if ser.in_waiting >= 2:  # Verifica se há pelo menos 2 bytes disponíveis
            # Lê dois bytes para formar uma amostra de 16 bits
            data_bytes = ser.read(2)
            sample = struct.unpack('<h', data_bytes)[0]  # Converte os bytes em um inteiro de 16 bits
            
            # Reproduzir o áudio captado
            stream.write(data_bytes)
except KeyboardInterrupt:
    pass
finally:
    stream.stop_stream()
    stream.close()
    p.terminate()
    ser.close()
