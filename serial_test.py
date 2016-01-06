import serial

connected = False
print "Not connected"

ser = serial.Serial("COM2", 9600)

while not connected:
	serin = ser.read()
	connected = True
print "Connected"

ser.Write("1")

while ser.read() == '1':
	ser.read()

ser.close()
