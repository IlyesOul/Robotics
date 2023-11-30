from irobot_edu_sdk.backend.bluetooth import Bluetooth
from irobot_edu_sdk.robots import event, hand_over, Color, Robot, Root, Create3

robot = Create3(Bluetooth())

global obstacle_position_array
obstacle_position_array = []

async def try_again (x, y):
    global obstacle_position_array
    obstacle_position_array.append([x,y])
    await robot.turn_left(45)

@event(robot.when_play)
async def play(robot):
    while True:
        distance_array = (await robot.get_ir_proximity()).sensors
        while distance_array[3] < 25:
            print(f"Distance [3] = {distance_array[3]}")
            await robot.set_wheel_speeds(10,10)
            distance_array = (await robot.get_ir_proximity()).sensors
        await try_again((await robot.get_position()).x, (await robot.get_position()).y)
        global obstacle_position_array
        while [(await robot.get_position()).x, (await robot.get_position()).y] not in obstacle_position_array and distance_array[3] < 25:
            await robot.set_wheel_speeds(10,10)
        await robot.move(-15)

@event(robot.when_touched, [])
async def when_touched(robot):
    robot.set_wheel_speeds(0,0)
    robot.set_lights_rgb(65,65,65)


robot.play()
