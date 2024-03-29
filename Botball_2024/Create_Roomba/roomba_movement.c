#include <kipr/wombat.h>

int main()
{
    create3_connect();
    
    msleep(3000);
    
    //Arm base motor: motor(0);
    //Second arm: motor(1);
    //Third arm: motor(2);
    
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
    while(analog(2) > 1300)
    {
        create3_velocity_set_components(-.05, 0);
    }
    
    //SUBSECTION: ROTATE TO TOWER
    create3_rotate_degrees(-90, 180);
    create3_wait();
    
    //SUBSECTION: Move towards tower
    
    while(analog(1)<1250){
        create3_velocity_set_components(.25, 0);
    }
    
    msleep(1000);
    
    //TODO - Pickup botguy
    
    
    //Subsection: move back
    while(analog(1) > 2500)
    {
        
        create3_velocity_set_components(-.25, 0);
    }
    
    //Subsection: rotate left 90 degrees
    
    	create3_rotate_degrees(-90, 180);
    
    	//TODO: Drop Botguy
    
    //Subsection: rotate right 90 degrees
    	msleep(3000);
    	create3_rotate_degrees(90, 180);
    
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
    	while(analog(1)<1750){
            create3_velocity_set_components(.25, 0);
            //msleep(2000);
    		//create3_velocity_set_components(-.25, 0);
            //msleep(4000);
        }
    return 0;
}
