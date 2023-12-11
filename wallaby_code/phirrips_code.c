void rotatefull();

int main()
{
    enable_servos();
    set_servo_position(0,500);
    while (digital(0)==0)
    {
        msleep(100); //Waiting for light to connect
    }
    printf("ran");
    motor(2, -97);
    motor(3,95);
    while (analog(1)<1700)
    {
        msleep(1);
    }
    ao();
    msleep(100);
    rotatefull();
    motor(2, -97);
    motor(3,95);
    msleep(5000);
    return 0;
}


void rotatefull()
{
    motor(2,-900);
   	msleep(3500);
    ao();
}