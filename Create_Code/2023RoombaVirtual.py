
from irobot_edu_sdk.backend.bluetooth import Bluetooth
from irobot_edu_sdk.robots import event, hand_over, Color, Robot, Root, Create3
from random import random, randrange

robot = Create3(Bluetooth())

@event (robot.when_play)
async def play(robot):
    await robot.wait(3)
    await robot.turn_right(10)
    await robot.move(4)
    await robot.turn_right(16.5)
    await robot.move(6)
    await robot.turn_right(18)
    await robot.move(5.5)
    await robot.turn_right(5)
    await robot.move(1)
    await robot.wait(2.5)
    await robot.move(35)
    await robot.turn_left(80)
    await robot.wait(2)
    await robot.move(15)
    await robot.wait(1)
    await robot.move(-14)
    await robot.turn_right(80)
    await robot.move(30)
    await robot.turn_left(110)
    await robot.move(10)
    #await robot.wait(1)
    await robot.move(-5)
    await robot.turn_right(55)
    await robot.move(-10)
    await robot.turn_right(54)
    await robot.move(30)
    await robot.turn_left(110)
    await robot.move(10)
    await robot.turn_left(10)
    await robot.move(10)
    await robot.wait(1)
    await robot.move(-10)
    await robot.turn_right(10)
    await robot.move(-10)
    await robot.turn_right(110)
    await robot.move(27)
    await robot.turn_left(60)
    await robot.move(30)

    # Ramming at full speed ahead

    #await robot.turn_right(135)
    #await robot.wait(2)
    #await robot.move(40)
    #await robot.turn_right(80)
    
    # Allahuakbar
    await robot.move(-25)
    await robot.turn_right(90)
    await robot.move(15)
    while True:
        degree_to_rotate = randrange(0,360)
        await robot.turn_left(degree_to_rotate)
        await robot.set_wheel_speeds(1000,1000)
        await robot.wait(3)

   
robot.play()