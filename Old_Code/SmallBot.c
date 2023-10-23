#include <math.h>
//global variables
const int servo_right = 0;
const int servo_left = 1;
const int servo_claw = 2;
const int servo_claw_max = 1000;
const int servo_max = 1800; //right servo is down at 1800, left servo is down at 0, claw is open at 650
const int motor_right = 0;
const int motor_left = 1;
const int motor_right_power = 75;//percent
const int motor_left_power = 85;
const int infraredCutoffValue = 900;

//forward declarations
int golden_pom_collector(int);
//int deposit_poms(void);

//--------------------------------------------------------------------------

void driveStraight(int power, int time){
	motor(motor_right, power + ((power < 0) ? (13) : (-13)));
	motor(motor_left, power);
	wait_for_milliseconds(time);
	ao();
}
void freezeMotors(){
	freeze(motor_right);
	freeze(motor_left);
}
void turn(int motorPort, int power, int time){
		motor(motorPort, power);
	wait_for_milliseconds(time);
	ao();
}
//direction: -1 if right, 1 if left
void turnInPlace(int direction, int power, int time){
	motor(motor_right, power * direction);
	motor(motor_left, -power * direction);
	wait_for_milliseconds(time);
	ao();
}

void lowerArm(int currPos){//lowers the arm from the current pos to fully down
	while(currPos > 0){
		wait_for_milliseconds(250);
		currPos = currPos - 100;
		set_servo_position(servo_right, servo_max - currPos);
		set_servo_position(servo_left, currPos);
	}
}

void straight(){
	motor(motor_right, 60);
	motor(motor_left, 70);	
}
void moveRight(){
	motor(motor_left, 90);
	motor(motor_right, 50);
}
void moveLeft(){
	motor(motor_right, 80);
	motor(motor_left, 50);
}

void cam(){
	motor(motor_right, 20);
	motor(motor_left, 20);
	camera_open();
	int step = 0;
	do{
		camera_update();
		if (get_object_count(0) > 0|| get_object_count(1) > 0){
			if(get_object_confidence(0, 0) > .1 || get_object_confidence(1, 0) > .1){
				if(get_object_center(0, 0).y > 90 || get_object_center(1, 0).y > 90){
					if((get_object_center(0, 0).x > 90 || get_object_center(1, 0).x > 90)){
						moveRight();
					}
					if((get_object_center(0, 0).x < 70 || get_object_center(1, 0).x < 70)){
						moveLeft();
					}
					if((get_object_center(0, 0).x > 75 && get_object_center(0, 0).x < 85) || (get_object_center(1, 0).x > 75 && get_object_center(1, 0).x < 85)){
						straight();
					}
				}
			}
		}
	}while(step++ < 100);
	ao();
}

int main(void){
	enable_servos();
	//wait_for_light(14);
	//shut_down_in(110);
	set_servo_position(servo_right, 0);//servo port number, servo position
	set_servo_position(servo_left, 1800);
	set_servo_position(servo_claw, servo_claw_max);
	//driveStraight(-60, 500);
	turnInPlace(-1, 70, 950); //turn 90 degrees
	driveStraight(-70, 150);
	lowerArm(servo_max);
	disable_servos();
	driveStraight(80, 4000);
	turn(motor_left, 60, 600);
	cam();
	
	//driveStraight(60, 2000);
	//turn(motor_right, 60, 3000);
	
	
	
	/*
	driveAtPower(70);						//drive forward until it reaches 
	while(analog(0) < infraredCutoffValue){	//the black line in the middle
		printf("%d\n", analog(0));
		wait_for_milliseconds(1);
	}
	freezeMotors();
	*/
	return 0;
}

//-----------------=bullshit until the end of the file=-----------------------------------------
int claw_close(void){
	return 0;
}

/*----------------------------------------------------
golden_pom_collector function by Jasper 3/1/15
------------------------------------------------------
Function collects the golden poms in the center lane into the claw of the small bot. This function also prepares the bot to hyperextend the arm so that it can drop the golden poms into the caldera.

Takes takes a velocity argujment and returns 1 when complete.
----------------------------------------------------*/

int golden_pom_collector(int power){
	//digital(0) is connected to a bump sensor on the front of the arm
	//the bot wil continue to drive forward collecting poms while it hasn't hit the wall
	while(!digital(0)){
		//drive the bot towards the wall
		motor(motor_right, power);
		motor(motor_left, power);
	}
	msleep(500);	//back the bot up so the claw
	bk(motor_right);//
	bk(motor_left);	//
	msleep(100);	//doesn't break on the edge of the board
	freeze(motor_right);//stop the bot so
	freeze(motor_left); //the poms can be picked up
	msleep(100);
	claw_close();//picks up the poms
	fd(motor_right);
	fd(motor_left);							//move forward until the bot is sufficiently underneath the caldera
	while(analog(1) > infraredCutoffValue); //the sharpie black line is used to determine when the bot will stop
	freeze(motor_right);
	freeze(motor_left);
	//deposit_poms();//drop the
	return 0;
}



