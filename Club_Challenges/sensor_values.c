#include <kipr/wombat.h>

int main()
{
    // Proximity sensor 
    bool val = analog(0) < 1650; /*Object relatively close*/
    val = analog(0) < 1750; /*Object close*/
    val = analog(0) < 2200; /*Object really close*/

    //Light sensor
    val = digital(0) == 0 /*Returns 1 if light shined*/

    //Button
    val = digital(0) == 0 /*Returns 1 if button is pressed*/

    //Tophat (Yet to figure out)

    //Infared (Yet to figure out
    val = analog(0) > 2500 /* See black*/
    val = analog(0) < 1500 /*See white*/
    val = analog(0) < 2500 && analog(0) > 1500 /*See gray*/
}
