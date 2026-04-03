#include <iostream>
#include <windows.h>
using namespace std;

void typing(string text, int delay = 30) {
    for (char c : text) {
        cout << c << flush;
        Sleep(delay);
    }
    cout << endl;
}

void title(string text) {
    cout << "=====================================\n";
    cout << "        " << text << "\n";
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