#include <kipr/wombat.h>

int main()
{
    create3_connect();
    
    int black_counter = 0;
    
    while(black_counter != 2)
    {
        create3_velocity_set_components(-.25, 0);
        if(analog(0) > 3000)
        {
            black_counter+=1;
        }
        while(analog(0) > 3000){create3_velocity_set_components(-.25, 0);}
        
    }
    
    create3_drive_straight(1, -0.25);
    
    return 0;
}
