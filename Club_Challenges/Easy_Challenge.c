#include <kipr/wombat.h>

int main
{
    //Start with light - 1 POINT
    while(digital(0) == 0)
    {
        msleep(50);
    }

    //Move until detecting wall - 2 POINTS
    while(analog(0) < 2500)
    {
        motor(0, -100);
        motor(1, 100);
    }

    //Back upon upon detecting wall - .5 POINTS
    bk(1);
    bk(2);
    msleep(1500);

    //Rotate and move to can - 2 POINTS
    motor(1, 100);
    fd(0);
    fd(1);
    msleep(2000);

    //Give 'im a proper shmacking - 1.5 POINTS
    enable_servos();
    set_servo_position(0, /*However much it is*/ 500);

    return 0;
}