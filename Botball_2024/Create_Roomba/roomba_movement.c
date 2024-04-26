#include <kipr/wombat.h>
#include </home/kipr/Documents/KISS/Default User/arm_code/src/main.c>

int main()
{
    create3_connect();

    enable_servos();

    set_servo_position(0, 300);
    
	//while(digital(0)==0){
    //}
    //Arm base motor: motor(0);
    //Second arm: motor(1);
    //Third arm: motor(2);

    //decrease motor0
    //increase motor1
    //lower motor2
    
    // Erect the arm
    lift0(4500, 500);
    lift1(2500, 500);
    lift2(700, 500);

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

    //SUBSECTION: Move forward past line
    msleep(1000);
    while(analog(1) > 1300)
    {
        create3_velocity_set_components(-.05, 0);
    }
	
    //create3_drive_straight(-.05,0.25);
    //create3_wait();
    
    //SUBSECTION: ROTATE TO TOWER
    create3_rotate_degrees(-102, 180);
    create3_wait();
    
    /*lift1(2800,500);
    
    lift2(300,500);
    
    lift0(2000,500);*/
    
    
    
    //SUBSECTION: Move towards tower
    create3_drive_straight(.29,0.5);
    create3_wait();
	
    set_servo_position(0, 1350);
    //TODO - Pickup botguy
    
    //lower2(2300,500);
    //msleep(2250);
    
    /*set_servo_position(0, 1350);
	msleep(2250);
   
    lift1(4500,500);
    msleep(2250);
    
    lift2(2000,500);
    msleep(2250);
    
    //Subsection: move back
    while(analog(2) > 2300)
    {
        create3_velocity_set_components(-.25, 0);
    }

    //Subsection: rotate left 90 degrees
    create3_rotate_degrees(-90, 180);
    create3_wait();

    //TODO: Drop Botguy
    //set_servo_position(0, 300);

    //Subsection: rotate right 90 degrees

    // PRIMARY FUNCTION: FLICKS CUBES


    //SUBSECTION: Move until far enough

    while(analog(1) > 2300)
    {
        printf(analog(1));
        create3_velocity_set_components(-.25, 0);
    }

    //SUBSECTION: Lower arm

    //SUBSECTION: Rotate left-to-right
    create3_rotate_degrees(-90, 180);
    create3_wait();
    create3_rotate_degrees(90, 180);
    create3_wait();
    create3_rotate_degrees(-90, 180);
    create3_wait();
    create3_rotate_degrees(90, 180);
    create3_wait();

    //SUBSECTION: Rotate backwards
    create3_rotate_degrees(180, 180);

    //PRIMARY FUNCTION: FLICKING SWITCH

    //TODO: MOVE UNTIL DETECTING POLE WITH POOL NOODLES

    //create3_velocity_set_components(.25, 0);
    msleep(2000);
    //create3_rotate_degrees(90, 180);
    //create3_wait();
    //while(analog(1)<1750){
        //create3_velocity_set_components(.25, 0);
        //msleep(2000);
        //create3_velocity_set_components(-.25, 0);
        //msleep(4000);
    //}*/
    return 0;
}
