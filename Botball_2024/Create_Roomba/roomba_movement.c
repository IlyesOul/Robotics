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
        if(analog_val > 3300)
        {
            black_counter+=1;
            analog_val = analog(0);
        }
        //While black is seen move
        while(analog_val > 3300){
  			
         	if ((black_counter == 2))
                break;
            create3_velocity_set_components(-.25, 0);
            analog_val = analog(0);
        }
        
    }
    
    //SUBSECTION: ROTATE TO TOWER
    create3_rotate_degrees(-90, 180);
    create3_wait();
    
    //SUBSECTION: Move towards tower
    
    while(analog(1)<1475){
        create3_velocity_set_components(.25, 0);
    }
    /*
     while(analog(1)<2800){
        create3_velocity_set_components(.25, 0);
    }
    while(analog(1)>1200){
        create3_velocity_set_components(-.25, 0);
    }
    */
    //TODO - Pickup botguy
    
    // PRIMARY FUNCTION: FLICKS TIPS
    
 
    //SUBSECTION: Move until far enough
    printf(analog(1));
    
    while(analog(1) > 2300)
    {
        printf(analog(1));
        create3_velocity_set_components(-.25, 0);
    }
    
    //SUBSECTION: Lower arm
    
    //SUBSECTION: Rotate left-to-right
    
   
    
    
    
    return 0;
}
