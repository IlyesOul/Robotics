from irobot_edu_sdk.backend.bluetooth import Bluetooth
from irobot_edu_sdk.robots import event, hand_over, Color, Robot, Root, Create3

robot = Create3(Bluetooth())

def threshold(sensors):
    return sensors[3]<70

@event(robot.when_play)
async def play(robot):
    while (await robot.get_position().x < 250) :
        distance_array = (await robot.get_ir_proximity()).sensors
        print(distance_array[3])
        while threshold(distance_array):
            await robot.set_wheel_speeds(100,100)

robot.play()
