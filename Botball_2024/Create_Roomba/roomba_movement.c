#include <kipr/wombat.h>
#include </home/kipr/Documents/KISS/Default User/arm_code/src/main.c>

int main()
{
    create3_connect();

    enable_servos();

    set_servo_position(0, 200);

    //while(digital(0)==0){
    //}
    
    // Erect the arm
    lift0(4500, 600);
    lift1(4600, 600);
    lift2(500, 600);

    //Folding the arm after moving it
    //msleep(20000);
    //lower0(4500, 600);
    //lower1(4500, 600);
    // lower2(500, 600);

    // PRIMARY FUNCTION: GET TO TOWER
    int black_counter = 0;

    // SUBSECTION: MOVE UNTIL DETECTED TWO LINES
    while(black_counter != 2)
    {

        create3_velocity_set_components(-.25, 0);

        int analog_val = analog(0);
        //If black is seen
        if(analog_val > 3700)
        {
            black_counter+=1;
            analog_val = analog(0);
        }
        //While black is seen move
        while(analog_val > 3700){

            if ((black_counter == 2))
                break;
            create3_velocity_set_components(-.25, 0);
            analog_val = analog(0);
        }

    }

    //SUBSECTION: Move forward past line to align with pole
    msleep(1000);
    while(analog(1) > 1300)
    {
        create3_velocity_set_components(-.05, 0);
    }


    //SUBSECTION: ROTATE TO TOWER
    create3_rotate_degrees(-100, 180);
    create3_wait();

    //SUBSECTION: Move towards tower
    create3_drive_straight(.255,0.5);
    create3_wait();

    //TODO - Pickup botguy
    msleep(2000);
    lower2(1750, 500);
    msleep(1000);
    set_servo_position(0, 1450);
    msleep(500);
    
    //Back up to pole
    create3_drive_straight(-.2, .25);
    
    //Rotate towards noodle corner
    create3_rotate_degrees(-80, 180);
    
    //move towards noodle
    create3_drive_straight(.50, .25);
    
    //Rotate towards rock heap
	create3_rotate_degrees(50, 180);
    
    //Move towards rock heap
    create3_drive_straight(.25, .50);
    create3_wait();
    
    //Drop cube in rock heap
    set_servo_position(0, 200);
    
    //Rotate to octagon
    create3_rotate_degrees(90, 180);
    
    //Move forward
    create3_drive_straight(.15,.25);
    
    //Rotate left
    create3_rotate_degrees(35, 180);
    
    //Move forward a bit more
    create3_drive_straight(.23, .25);
    
    //Increase height of motor2
    lift2(800,500);
    
    //Rotate right to smack cube
    create3_rotate_degrees(-78, 75);

    
    //Move Forward
    create3_drive_straight(.07, .25);
    
    //open claw
    set_servo_position(0,200);
    
    return 0;
}
