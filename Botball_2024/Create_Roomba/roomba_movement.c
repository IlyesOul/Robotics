#include <kipr/wombat.h>

int main()
{
    create3_connect();
    
    //Arm base motor: motor(0);
    //Second arm: motor(1);
    //Third arm: motor(2);
    
    //Line up with tower
    
    int black_counter = 0;
    
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
    
    create3_velocity_set_components(0, 0);
    create3_drive_straight(-.20, 20);
    
    //Rotate
    create3_rotate_degrees(-90, 180);
    create3_wait();
    
    while(analog(1)<1525){
        create3_velocity_set_components(.25, 0);
    }
    
    //TODO - Pickup botguy
    
    //Move back and flick the tip
    create3_drive_straight(-.50, 20);
    //(Continued task TODO - Lower arm)
    
    
    
    
    return 0;
}
