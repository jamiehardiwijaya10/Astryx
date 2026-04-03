#include <iostream>
#include <string>
#include <windows.h>
#include "utils/helper.cpp"
using namespace std;

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

void titleMorivelle() {
    cout << CYAN;
    cout << "███╗   ███╗ ██████╗ ██████╗ ██╗██╗   ██╗███████╗██╗     ██╗     ███████╗\n";
    cout << "████╗ ████║██╔═══██╗██╔══██╗██║██║   ██║██╔════╝██║     ██║     ██╔════╝\n";
    cout << "██╔████╔██║██║   ██║██████╔╝██║██║   ██║█████╗  ██║     ██║     █████╗  \n";
    cout << "██║╚██╔╝██║██║   ██║██╔══██╗██║╚██╗ ██╔╝██╔══╝  ██║     ██║     ██╔══╝  \n";
    cout << "██║ ╚═╝ ██║╚██████╔╝██║  ██║██║ ╚████╔╝ ███████╗███████╗███████╗███████╗\n";
    cout << "╚═╝     ╚═╝ ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝  ╚══════╝╚══════╝╚══════╝╚══════╝\n";
    cout << RESET;
}

void menu() {
    cout << CYAN << "\n=== MAIN MENU ===\n" << RESET;
    cout << CYAN << "1. New Game\n";
    cout << CYAN  << "2. Continue\n";
    cout << CYAN   << "3. Exit\n" << RESET;
}

void newGame() {
    system("cls");
    cout << "Resident Evil.....\n";
    waitEnter();
}

void continueGame() {
    system("cls");
    cout << "Devil May Cry.....\n";
    waitEnter();
}

void mainMenu() {
    string input;

    while (true) {
        system("chcp 65001");
        system("cls");

        titleMorivelle();
        menu();

        cout << "\nPilih: ";
        getline(cin, input);

        if (input == "1") {
            newGame();
        }
        else if(input == "2") {
            continueGame();
        }
        else if(input == "3") {
            cout << "Keluar dari game...\n";
            Sleep(800);
            break;
        }
        else {
            cout << "Pilihan tidak valid!\n";
            waitEnter();
        }
    }
}

int main() {
    mainMenu();
    return 0;
}