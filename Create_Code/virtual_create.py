
from irobot_edu_sdk.backend.bluetooth import Bluetooth
from irobot_edu_sdk.robots import event, hand_over, Color, Robot, Root, Create3

robot = Create3(Bluetooth())

@event (robot.when_bumped,[])
async def bumped(robot):
    await robot.move(-5)
    await robot.set_wheel_speeds(100,0)
    await robot.set_lights_rgb(65,65,65)

@event (robot.when_play)
async def play(robot):
    await robot.wait(2)
    await robot.move(45)
    await robot.turn_left(90)
    await robot.wait(1)
    await robot.move(15)
    await robot.wait(3)
    await robot.move(-15)
    await robot.turn_right(90)
    await robot.move(15)


   
robot.play()