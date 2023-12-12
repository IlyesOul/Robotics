from irobot_edu_sdk.backend.bluetooth import Bluetooth
from irobot_edu_sdk.robots import event, hand_over, Color, Robot, Root, Create3
from irobot_edu_sdk.music import Note

robot = Root(Bluetooth())


@event(robot.when_played)
async def play(robot):
    await robot.set_wheel_speeds(-100, 100)
    # C D E E E A A C C B G
    await robot.play_note(4, 1)
    await robot.wait(1)
    await robot.play_note(6, 1)
    await robot.play_note(8, 1)
    await robot.wait(.05)
    await robot.play_note(8, 1)
    await robot.wait(.05)
    await robot.play_note(8, 1)
    await robot.wait(1)
    await robot.play_note(1, 1)
    await robot.wait(.05)
    await robot.play_note(1, 1)
    await robot.wait(1)
    await robot.play_note(16, 1)
    await robot.wait(.05)
    await robot.play_note(16, 1)
    await robot.wait(1)
    await robot.play_note(2, 1)
    await robot.play_note(11, 1)