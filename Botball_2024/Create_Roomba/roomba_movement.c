#include <kipr/wombat.h>

int main()
{
    create3_connect();
    
    int black_counter = 0;
    
    while(black_counter != 2)
    {
        create3_velocity_set_components(-.25, 0);
        
        int analog_val = analog(0);
        //If black is seen
        if(analog_val > 3300)
        {
            black_counter+=1;
            printf("nig1 detected");
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
    
    //Rotate
        create3_rotate_degrees(-90, 180);
    	create3_wait();
    
    while(analog(1)<2800){
        create3_velocity_set_components(.25, 0);
        printf(analog(1));
    }
    create3_velocity_set_components(0, 0);
    
    return 0;
}