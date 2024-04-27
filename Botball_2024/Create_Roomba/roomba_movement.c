#include <kipr/wombat.h>
#include </home/kipr/Documents/KISS/Default User/arm_code/src/main.c>

int main()
{
    create3_connect();

    enable_servos();

    while(digital(0)==0){}
    
    msleep(10000);

    set_servo_position(0, 250);

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
    
    //Over the hump
    //create3_drive_straight(.07,0.75);
    
    //SUBSECTION: ROTATE TO TOWER
    //create3_rotate_degrees(-100, 180);
    //Phillip idea
    create3_rotate_degrees(-90, 270);
    create3_wait();

    //SUBSECTION: Move towards tower
    create3_drive_straight(.26,0.5);
    create3_wait();

    //TODO - Pickup cube
    msleep(2000);
    lower2(1600, 500);
    msleep(1000);
    //Phillip idea
    set_servo_position(0, 1500);
    //set_servo_position(0, 1500);
    msleep(500);

    //Back up to pole
    create3_drive_straight(-.2, .25);
    create3_wait();

    //Rotate towards noodle corner
    create3_rotate_degrees(-90, 180);
    create3_wait();
    
    //Delay for other bots
    create3_drive_straight(-.3, .25);
    create3_wait();
    
    msleep(25000);
    
    //move towards noodle
    create3_drive_straight(.8, .25);
    create3_wait();
    
    //Rotate towards rock heap
    create3_rotate_degrees(60, 180);
    create3_wait();

    //Move towards rock heap
    create3_drive_straight(.35, .50);
    create3_wait();

    //Drop cube in rock heap
    set_servo_position(0, 250);

    //Rotate to octagon
    create3_rotate_degrees(91, 180);
    create3_wait();

    //Move forward
    create3_drive_straight(.15,.25);
    create3_wait();

    //Rotate left
    create3_rotate_degrees(35, 180);
    create3_wait();
	
    //Move forward a bit more
    create3_drive_straight(.26, .25);
    create3_wait();
	
    //Increase height of motor2
    lift2(800,500);

    //Rotate right to smack cube
    create3_rotate_degrees(-80, 50);
    create3_wait();
	
    //Move Forward
    create3_drive_straight(.07, .25);
    create3_wait();
	
    //Move Backwards
    //create3_drive_straight(-.07, .25);

    //Rotate right to smack cube
    //create3_rotate_degrees(-18, 75);

    //open claw
    set_servo_position(0,250);
    
    //lift claw
    lift2(2000,500);
    
    //move backwards
    create3_drive_straight(-.1, .25);
    create3_wait();
	
    //rotate next to middle cubes
    create3_rotate_degrees(18, 75);
    create3_wait();
    
    //lower 2nd arm to level with cubes
    lower2(1500,500);
    
    //push cubes off to zone
    create3_drive_straight(.1, .25);
    create3_wait();
    
    //lift 2nd arm
    lift2(1000,500);
    
    //move back
    create3_drive_straight(-.15, .25);
    create3_wait();
    
    //Rotate left to smack left cube
    create3_rotate_degrees(-115, 270);
    create3_wait();
    
    //Lower arm 
    lower2(1800, 500);
    
    //Rotate left to hit other cube
    create3_rotate_degrees(270, 180);
    create3_wait();

    //360 noscope
    create3_rotate_degrees(360, 95);
    create3_wait();
    
    
    return 0;
}
