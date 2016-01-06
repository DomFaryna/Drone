#Imports time and premade drone commands
import time, sys
import ps_drone

#Sets the drone up, reseting it so it won't make any stupid mistakes
drone = ps_drone.Drone()
drone.startup()

drone.reset()
while (drone.getBattery()[0] == -1): time.sleep(0.1)
print "Battery: "+str(drone.getBattery()[0])+"% "+str(drone.getBattery()[1])
if drone.getBattery()[1] == "empty": sys.exit()

drone.useDemoMode(True)
drone.getNDpackage(["demo"])
time.sleep(0.5)

drone.trim()
drone.getSelfRotation(5)
print "Auto-alteration:  "+str(drone.selfRotation)+"deg/sec"

#The main program starts now
drone.takeoff() #Starts drone
while drone.NavData["demo"][0][2]: time.sleep(0.1)

distance = 0
time = distance/0
angle = 180

drone.moveUp()
time.sleep(2)
drone.stop()

stop = False
while not stop:
	key = drone.getKey()
        if key == " ":
		if drone.NavData["demo"][0][2] and not drone.NavData["demo"][0][3]:     drone.takeoff()
                else: drone.land()
                elif key != "":         stop = True
		

drone.land()
