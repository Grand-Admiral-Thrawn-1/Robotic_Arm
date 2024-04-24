import sys
from coppeliasim_zmqremoteapi_client import RemoteAPIClient
import time
import math

if __name__ == '__main__':
    try:
        client = RemoteAPIClient()
        sim = client.require('sim')
        sim.setStepping(True)
        sim.startSimulation()
        print("Started simulation")

        global joint1
        global joint2
        global joint3
        global joint4

        joint1 = sim.getObject("/Servo_1_joint")
        joint2 = sim.getObject("/Servo2_joint")
        joint3 = sim.getObject("/Servo_3_joint")
        joint4 = sim.getObject("/Servo_4_joint")

        def sysCall_actuation():
            # put your actuation code here
            sim.setJointTargetPosition(joint1, math.pi/4)
            sim.setJointTargetPosition(joint2, math.pi/2)
            sim.setJointTargetPosition(joint3, math.pi)
            sim.setJointTargetPosition(joint4, math.pi/4)

        while True:
            sysCall_actuation()
            sim.switchThread()

    except KeyboardInterrupt:
        sim.stopSimulation()
        time.sleep(0.5)
        if sim.getSimulationState() == sim.simulation_stopped:
            print('\nSimulation interrupted by user in CoppeliaSim.')
        else:
            print('\nSimulation could not be interrupted. Stop the simulation manually.')

    finally:
        sys.exit()
