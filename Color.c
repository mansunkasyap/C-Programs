#include <windows.h>
#include <stdio.h>

// Function to set console text color
void setConsoleColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}

int main() {
    // Set text color to green
    setConsoleColor(2);
    printf("This text is green\n");

    // Set text color to red
    setConsoleColor(4);
    printf("This text is red\n");

    // Reset to default color
    setConsoleColor(7);
    printf("This text is default color\n");
s
    return 0;
}
