#include <X11/Xlib.h>
#include <X11/X.h>
#include <stdio.h>
#include <stdlib.h>

// Panic

void panic(char *msg) {
  puts(msg);
  exit(EXIT_FAILURE)
}

// X11 connection

Display *dpy;

// Display's root 
Window root;

int main(void) {

 // Open a display
  dpy = XOpenDisplay(NULL);
  if (dpy == NULL) {
    panic("LittleWM: Unable to open a X display.");
  }

  // Retrieves a root window of the display.
  root = DefaultRootWindow(dpy);

  // Close the display
  XCloseDisplay(dpy);


  // Request the X server to send events related to `SubstructureRedirectMask`,
  // `ResizeRedirectMask` and `SubstructureNotifyMask`.
  // > a. Select the event mask for the root.
  XSelectInput(dpy, root, SubstructureRedirectMask | SubstructureNotifyMask);
  // > b. Synchronize the changes.
  XSync(dpy, 0);

  XEvent e;
  for (;;) {
    XNextEvent(dpy, &e);
    switch (e.type) {
    default:
      puts("LittleWM: Unexpected event.");
      break;
    }
    // Ensures that X will proccess the event.
    XSync(dpy, 0);
  }

  
}
