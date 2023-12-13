#include <kipr/wombat.h>

int main()
{
    // Proximity sensor 
    bool val = analog(0) < 1750; /*Object relatively close*/
    val = analog(0) < 2000; /*Object close*/
    val = analog(0) < 1750; /*Object really close*/

    //Light sensor
    val = digital(0) == 0 /*Returns 1 if light shined*/

    //Button
    val = digital(0) == 0 /*Returns 1 if button is pressed*/

    //Tophat (Yet to figure out)

    //Infrared (Yet to figure out
    val = analog(0) > 2500 /* See black*/
    val = analog(0) < 2500 /*See white*/
    val = analog(0) == 2500 /*See gray*/
}
