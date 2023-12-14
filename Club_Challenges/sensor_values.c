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

    //Tophat
    val = analog(0) > 3200 /*See black */
    val = analog(0) < 400 /*See red*/

    //Infared 
    val = analog(0) > 3600 /* See black*/
    val = analog(0) <= 300 /*See red*/
}
