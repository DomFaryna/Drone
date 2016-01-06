print "Starting code"
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

print "Drone flight pattern commencing"

drone.moveForward()
time.sleep(1)
drone.moveUp()
time.sleep(1)
drone.moveLeft()
time.sleep(1)
drone.moveBackward()
time.sleep(1)
drone.moveDown()
time.sleep(1)
drone.moveRight()
time.sleep(1)
drone.stop()
time.sleep(2)

drone.land() #Lands drone

print "Drone flight pattern finished"
