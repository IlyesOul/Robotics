int main_motor = 1;
int support_motor = 3;

int main(){
	//enable_servo(3);
	//set_servo_position(3,350);
	
	///1. lift the arm up vertically.
	mav(main_motor,1500);
	motor(support_motor,-100);
	msleep(5000);
	
	//2. bring the arm back down vertically.
	
	mrp(main_motor, -700, -600);
	msleep(300);
	motor(support_motor,100);
	
	mrp(main_motor, -700, -300);
	msleep(300);
	motor(support_motor,100);
	
	mrp(main_motor, -700, 000);
	msleep(300);
	motor(support_motor,100);
	
	msleep(600);
	
	/*mav(main_motor, -700);
	msleep(400);
	motor(support_motor,100);
	msleep(600);*/
	return 0;
}
