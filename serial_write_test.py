import serial
import time

connected = False
print "Not connected"
timer = 0

for i in xrange(0, 10):
	try:
		port = "/dev/ttyACM" + str(i)
		ser = serial.Serial(port, 9600)
		pas = 1
		print "connected to " + port
		ser.write("test")
		break
	
	except:
		print"didn't work"
		pas = 0


while timer < 5:
	ser.write("3")
	time.sleep(1)
	timer = timer + 1

while True:
	word = ser.readline()
	print word	
