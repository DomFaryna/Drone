import serial
import ps_drone

check = 0

connected = False
print "Not connected"

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

if pas == 1:
	while not connected:
		serin = ser.read()
		connected = True
	print "Connected"

	ser.write("1")

	while check == 0:
		ser.write("1")
#		ser.open()
		word = ser.readline()
		print word
		try:
			x = int(word[:-1])
			if x > 100000:
				print "Pretty big number"
			else:
				print "Pretty small number"
		except:
			crap = 0
		if 'x' in word:
			check = 1
	
	ser.close()
