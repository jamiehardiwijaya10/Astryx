#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
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

    for (int i = 0; i < text.length(); i++) {

        cout << text[i] << flush;

        for (int t = 0; t < delay; t += 5) {

            if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
                cout << text.substr(i + 1);
                cout << endl;
                return;
            }

            Sleep(5);
        }
    }

    cout << endl;
}

void dialog(string nama, string text, int delay = 40){
    typing(nama + " :", delay);
    typing(text, delay);
    cout << endl;
}

void saveGame(string username,int chapter, int scene) {
    ifstream file1("databases/player.txt");
    vector <string> semuaBaris;
    string baris;
    string header;
    bool found = false;
    
    if (file1.is_open()){
        if (getline(file1, header)) {}

        while(getline(file1,baris)){
        stringstream baca(baris);
        string user;
        int ch, sc;
        baca >> user >> ch >> sc;

        if (user == username){
            ch = chapter;
            sc = scene;
            found = true;
            }
            semuaBaris.push_back(user + " " + to_string(ch) + " " + to_string(sc));
        }
        file1.close();
    }
    ofstream file2("databases/player.txt");
    if(file2.is_open()){
        if (!header.empty()) {
            file2 << header << endl;
        }

        for (string &b : semuaBaris){
            file2 << b << endl;
        }
        file2.close();
    }
}


void title(string text) {
    cout << "=====================================\n";
    cout << "          " << text << "\n";
    cout << "=====================================\n\n";
}

void title2(string text) {
    cout << "===========" << text << "============\n";
    
}

#include <algorithm>

bool waitOrSkip() {
    string input;
    cout << "\n(Enter = continue | Type 's' = skip): ";
    getline(cin, input);

    input.erase(remove_if(input.begin(), input.end(), ::isspace), input.end());

    if (input == "s" || input == "S") {
        cout << "[Scene skipped]\n";
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
    cout << "\n(Press enter to continue... )";
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