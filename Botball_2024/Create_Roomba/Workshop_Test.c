#include <kipr/wombat.h>

int main()
{
   	create3_connect();
    
    // Testing bump
    /*while(create3_sensor_bump(2)!=1)
    {
        create3_velocity_set_components(1.0, 0.0);
    }*/
    
    
    //Testing Distance
    /*while(create3_sensor_ir(3) < 50)
    {
        create3_velocity_set_components(.25, 0.0);
    }*/
    
    /*
    //Testing Cliff Stuff
    while(1==1)
    {
        if(create3_sensor_cliff(2) < 50)
        {
            printf("cliff");
        }else
        {
            printf("No cliff");
        }
        
    } 
    */
    
    while(create3_sensor_ir(3)<40)
    {
        create3_velocity_set_components(50, 0.0);
    }
    
    create3_rotate_degrees(135, 60);
    create3_drive_straight(2, 2.5);
    create3_rotate_degrees(110, 60);
    create3_drive_straight(2, 2.5);
    

    return 0;
}
