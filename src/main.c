#include <X11/X.h>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>
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


void grabKey(char *key, unsigned int mod) {
  KeySym sym = XStringToKeysym(key);
  KeyCode code = XKeysymToKeycode(dpy, sym);
  XGrabKey(dpy, code, mod, root, false, GrabModeAsync, GrabModeAsync);
  XSync(dpy, false);

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

 // Create and define the cursor.
  // > a. Create a cursor using the standard `X11/cursorfont.h`.
  Cursor cursor = XCreateFontCursor(dpy, XC_left_ptr);
  // > b. Define the cursor for the root window.
  XDefineCursor(dpy, root, cursor);
  // > c. Synchronize the changes.
  XSync(dpy, False);

  XEvent e;
  for (;;) {
    XNextEvent(dpy, &e);
    switch (e.type) {
    // [...]
    case ButtonPress:
      puts("LittleWM: Button pressed!");
      break;
    // [...]
  }


  // Tells X to send `ButtonPress` events on the root.
  XGrabButton(dpy, Button1, 0, root, 0, ButtonPressMask, GrabModeSync,
              GrabModeAsync, NULL, NULL);
              
  XEvent e;
  for (;;) {
    XNextEvent(dpy, &e);
    switch (e.type) {
    // [...]
    case ButtonPress:
      // Unfreeze X to allow more mouse events for the root and all children.
      XAllowEvents(dpy, ReplayPointer, CurrentTime);
      XSync(dpy, 0);
      puts("LittleWM: Button pressed!");
      break;
    // [...]
    }
  }

  // [...]
}

  // [...]
}

 // Grab keys to receive events
  // > a. Get a keysymbol of a string.
  KeySym aKeySym = XStringToKeysym("a");
  // > b. Get the keycode of this keysym.
  KeyCode aKeyCode = XKeysymToKeycode(dpy, aKeySym);
  // > c. Grab the key on the root window.
  XGrabKey(dpy, aKeyCode, ShiftMask, root, false, GrabModeAsync, GrabModeAsync);
  // > d. Synchronize the changes.
  XSync(dpy, false);

  XEvent e;
  for (;;) {
    XNextEvent(dpy, &e);
    switch (e.type) {
    // [...]
    case KeyPress:
      puts("LittleWM: Key pressed!");
      break;
    // [...]
    }
  }

  // [...]
}

 // Receive a `KeyPress` event when pressing "a" + "Shift".
  grabKey("a", ShiftMask);
  // Add more keybindings...


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
