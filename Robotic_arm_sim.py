import sys
from coppeliasim_zmqremoteapi_client import RemoteAPIClient
import time
from math import*
import numpy as np
import keyboard

if __name__ == '__main__':
    try:
        client = RemoteAPIClient()
        sim = client.require('sim')
        sim.setStepping(True)
        sim.startSimulation()
        print("Started simulation")

        body = sim.getObject("/base_link_respondable")
        Servo_1_joint = sim.getObject(
            "base_link_respondable\Assembly_URDF\meshes\Servo1")
        Servo_2_joint = sim.getObject(
            "Robotic_Arm\Assembly_URDF\meshes\Servo_2")
        Servo_3_joint = sim.getObject(
            "Robotic_Arm\Assembly_URDF\meshes\Servo_3")
        Servo_4_joint = sim.getObject(
            "Robotic_Arm\Assembly_URDF\meshes\Servo_4")



        joints = [Servo_1_joint, Servo_2_joint, Servo_3_joint, Servo_4_joint]


    except KeyboardInterrupt:
        sim.stopSimulation()
        time.sleep(0.5)
        if sim.getSimulationState() == sim.simulation_stopped:
            print('\nSimulation interrupted by user in CoppeliaSim.')
        else:
            print('\nSimulation could not be interrupted. Stop the simulation manually.')

    finally:
        sys.exit()