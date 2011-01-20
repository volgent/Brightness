#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <X11/Xlib.h>
#include <X11/extensions/xf86vmode.h>

#define STEP 0.2

int main()
{
    Display * display;
    XF86VidModeGamma gamma;

    display = XOpenDisplay (NULL);
    if ((display) && (gamma.red > STEP))
    //if ((display) && (gamma.red < 1))
    {
        XF86VidModeGetGamma (display, 0, &gamma);
        gamma.red -= STEP;
        gamma.blue -= STEP;
        gamma.green  -= STEP;
        XF86VidModeSetGamma (display, 0, &gamma);
        XCloseDisplay (display);
    }
    return EXIT_SUCCESS;
}
