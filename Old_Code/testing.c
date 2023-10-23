int main_motor = 1;
int support_motor = 3;
int claw_motor  = 2;
int helicopter_servo = 3;
void liftElbowArm(void)
{
	set_servo_position(3,350);
	
	mav(main_motor,1500);
	motor(support_motor,-100);
	msleep(4000);
	}
void lowerElbowArm(void)
{
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
}
void holdElbowArm(void)
	{
		mav(main_motor,1500);
	}
void armSlightUp(void)
	{
		motor(0,-50);
		msleep(500);
	}
void armSlightDown(void)
	{
	motor(claw_motor,-80);
	motor(0,50);
	msleep(500);
	}
void turnHelicopterFront(void)
	{
	set_servo_position(helicopter_servo, 1625);
	}
           	
void turnHelicopterOut(void)
	{
	set_servo_position(helicopter_servo, 737);
	}
           	
void turn_left()
	{
	create_spin_CCW(200);
	msleep(1000);
	create_stop();
	printf("turn left\n");
	}
           	
void turn_right()
{
	create_spin_CW(180);
	msleep(1000);
	create_stop();
	printf("turn right\n");
	}
           	
void openClaw(void)
	{
		motor(claw_motor, 6);
		msleep(2200);
		freeze(claw_motor);
	}
void closeClaw(void)
	{
		motor(claw_motor, -6);
		msleep(2200);
		freeze(claw_motor);
	}
           	
           	
int main()
{
	printf("program is starting\n");
	create_connect();
	//msleep(2000);
	printf("starting bot\n");
	printf("connected big bot\n");
	
	
	//1.raise the claw up fully & open claw
	liftElbowArm();
	enable_servo(helicopter_servo);
    turnHelicopterFront();
	
	//2.rotate 90 degrees to the right in place
	turn_right();
                          	
	//3.drive forward and push the blocks towards the mesTa (needs measurement testing)
	create_drive_direct(-300,-300);
	printf("drive straight");
	msleep(1000);
	create_stop();
	msleep(1000);
                          	
	//4.back up until the big bot hits the back wall 
	printf("drive back");
	create_drive_straight(500);
	msleep(1000);
	/*while(get_create_lbump == 0 && get_create_rbump == 0)
			{
				msleep(100);
			}
	*/
	create_stop();
                          	
	//5.lower the claw fully
	lowerElbowArm();
	turnHelicopterFront();
	openClaw();
                          	
	//6.drive forward until the cubes are in the open claw
	create_drive_direct(-350,-350);
	msleep(1250);
	create_stop();
			
	//7.close the claw
	closeClaw();
	printf("\nProgram end");
			
	//pause here today 3/21		
 /*                         	
	//8.turn 90 degrees to the left
	turn_left();
                          	
	//9.drive forward until the big bot is centered with the bot guy
	create_drive_direct(-200,-200);
	msleep(1000);
	create_stop();
                          	
	//10.turn 90 degrees right
	turn_right();
                          	
	//11.fully raise the claw
	//liftElbowArm();
	//holdElbowArm();
                          	
	//12.drive forward quickly enough to knock bot guy off of the mesa
	create_drive_direct( -500, -500 );
	msleep(300); // check these numbers
	create_stop();
                          	
	//13. back up slightly
	create_drive_direct( -90, -90 );
	msleep(100);
	create_stop(); // check these numbers
                          	
	//14. release the cubes onto the mesa
	//openClaw();
                          	
	
	//beginning of stuff that probably needs a lot of testing
	
                          	
	//15.back up so the claw is out of the way of the poms and cubes
	create_drive_straight(200);
	msleep(150);
	create_stop();
                          	
	// turn left
	turn_left();
                          	
	// drive until hit the side of the board
	create_drive_direct(300,300);
	while(get_create_lbump == 0 && get_create_rbump == 0);
	create_stop();
                          	
	// turn right
	turn_right();
	
	//move until back infront of the board
	create_drive_straight(200);
	msleep(150);
	create_drive_direct( 90 , 90);
	msleep(100);
	
	//turn right
	turn_right();
                          	
	// drive until the end of the board
	while (get_create_distance() != 670);
	{
	create_drive_straight(-400);
	msleep(100);
	}
	*/
	
	return 0;
	}
               

