#Written by Yousef Shaykholeslam
#18/3/2024
from Maix import GPIO
from fpioa_manager import fm
from machine import UART
import time

# Register the UART pins
fm.register(34, fm.fpioa.UART2_TX, force=True)
fm.register(35, fm.fpioa.UART2_RX, force=True)

# Initialize the UART
uart = UART(UART.UART2, 115200, timeout=1000, read_buf_len=4096)

# Send "Hello UART" to the Arduino
uart.write("Hello UART\n")

# Main loop
while True:
    if uart.any():
        data = uart.read()
        print("Received from Arduino: ", data)

    time.sleep(0.01)
