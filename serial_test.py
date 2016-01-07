import serial

check = 0
connected = False
print "Not connected"

ser = serial.Serial("/dev/ttyACM1", 9600)

while not connected:
	serin = ser.read()
	connected = True
print "Connected"

ser.write("1")

while check == 0:
	ser.readline()
	print ser.readline()
	if ser.read() == '0':
		check = 1

ser.close()
