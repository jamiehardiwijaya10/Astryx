#include <iostream>
#include <windows.h>

using namespace std;

#define DEFAULT_COLOR 7

#define RED_COLOR 12
#define GREEN_COLOR 10
#define YELLOW_COLOR 14
#define BLUE_COLOR 9
#define CYAN_COLOR 11
#define PURPLE_COLOR 13
#define WHITE_COLOR 15
#define GRAY_COLOR 8

void typing(string text, int delay = 30) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delay);
    }
    cout << endl;
}

void title(string text) {
    cout << "=====================================\n";
    cout << "          " << text << "\n";
    cout << "=====================================\n\n";
}

void title2(string text) {
    cout << "===========" << text << "============\n";
    
}

bool waitOrSkip() {
    string input;
    cout << "\n(Enter = lanjut | ketik 's' = skip): ";
    getline(cin, input);

    if (input == "s" || input == "S") {
        cout << "[Scene dilewati]\n";
        return true;
    }

    return false;
}

void garis(int ukuran,char hurup){
  int pilihan = 0;
  pilihan += ukuran;
  cout << string(int(pilihan),hurup) << endl;
  pilihan = 0;
}

void waitEnter() {
    string input;
    cout << "\n(Tekan Enter untuk lanjut)";
    getline(cin, input);
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void printColor(string text, int color) {
    setColor(color);
    cout << text;
    setColor(DEFAULT_COLOR);
}