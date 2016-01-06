import time, sys
import ps.drone

drone = ps.drone.Drone()
drone.startup()

drone.reset()
while (drone.getBattery()[0] ==-1): time.sleep(0.1)
print "Battery: "+str(drone.getBattery()[0])+"%"+str(drone.getBattery()[1])
if drone.getBattery()[1]=="empty": sys.exit()

drone.useDemoMode(True)
drone.getNDpackage(["demo"])
time.sleep(0.5)



drone.takeoff()
while drone.NavData["demo"][0][2]: time.sleep(0.1)

#right, forward, up, turn right)
move(0.5,0.1,0.1,0.5)
time.sleep(3)
drone.stop()
time.sleep(2)

#the doggie stuff
drone.doggyHop()
time.sleep(4)
drone.stop()
time.sleep(2)
drone.doggyNod()
time.sleep(4)
drone.stop()
time.sleep(2)
drone.doggyWag()
time.sleep(4)
drone.stop()
time.sleep(2)

drone.land()
