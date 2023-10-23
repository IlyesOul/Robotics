int claw_motor = 2;
int helicopter_servo = 3;
void turnHelicopterFront(void)
	{
	set_servo_position(helicopter_servo, 1627);
	printf("turning in");
	}
           	
void turnHelicopterOut(void)
	{
	set_servo_position(helicopter_servo, 737);
	printf("turning out");
	}
int main(){
	enable_servo(3);
	turnHelicopterOut();
	msleep(1000);
	turnHelicopterFront();
	msleep(1000);
	
	/*
	motor(claw_motor, 6);
	msleep(2200);
	freeze(claw_motor);
	msleep(1000);
	motor(claw_motor, -6);
	msleep(2200);
	freeze(claw_motor);
	*/
	/*int initial_motor_position = get_motor_position_counter(claw_motor);
	
	mtp(claw_motor, -200, (initial_motor_position + 600));
	msleep(500);
	
	
	mtp(claw_motor, 200, (initial_motor_position - 600));
	msleep(500);*/
	return 0;
	
}
