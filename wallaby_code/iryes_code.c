#include <kipr/wombat.h>

int count = 0;

int main()
{
    	//Hardcoded
    	//move_at_velocity(0,-1325);
    	//move_at_velocity(1,1300); 
    	//msleep(5000);
    	//ao();
        while (analog(5) < 1700)
        {
            move_at_velocity(0,-1325);
    		move_at_velocity(1,1300); 
        }
        msleep(2000);
        
    
    ao();
    msleep(2500);
    motor(0, -50);
    msleep(1000);
    move_at_velocity(2, 1000);
	msleep(5000);
    


    return 0;
}
