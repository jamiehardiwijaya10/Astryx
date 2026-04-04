#include <iostream>
#include <windows.h>
using namespace std;

const int kapasitasTabung = 5;
const int kapasitasBola = 4;

struct stack {
    char data[kapasitasBola];
    int top;
} tabung[kapasitasTabung];
int langkah = 0;

void createStack(stack &s) {
    s.top = -1;
}

bool kosong(int i) {
    return tabung[i].top == -1;
}

bool penuh(int i) {
    return tabung[i].top == kapasitasBola - 1;
}

void push(int i, char x) {
    if (!penuh(i)) {
        tabung[i].data[++tabung[i].top] = x;
    }
}

char pop(int i) {
    if (!kosong(i)) {
        return tabung[i].data[tabung[i].top--];
    }
    return '\0';
}

char peek(int i) {
    if (!kosong(i)) {
        return tabung[i].data[tabung[i].top];
    }
    return '\0';
}

void createGame() {
    for (int i = 0; i < kapasitasTabung; i++) {
        createStack(tabung[i]);
    }
    push(0, 'R'); push(1, 'B'); push(2, 'G'); push(3, 'G');
    push(0, 'R'); push(1, 'R'); push(2, 'R'); push(3, 'B');
    push(0, 'B'); push(1, 'G'); push(2, 'Y'); push(3, 'Y');
    push(0, 'Y'); push(1, 'G'); push(2, 'B'); push(3, 'Y');
    langkah = 0;
}

void tampilkan() {
    cout << "\n=========== BALL SORT PUZZLE ===========\n";
    cout << "Langkah: " << langkah << "\n\n";

    
    for (int level = kapasitasBola - 1; level >= 0; level--) {
        for (int i = 0; i < kapasitasTabung; i++) {
            cout << "  ";
            if (tabung[i].top >= level) {
                cout << "[" << tabung[i].data[level] << "]";
            } else {
                cout << "[ ]";
            }
            cout << "  ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < kapasitasTabung; i++) {
        cout << "  [" << i+1 << "]  ";
    }
    cout << endl;
    cout << "===============================\n";
}

bool moveBall(int from, int to) {
    if (from == to) {
        cout << "Tidak bisa ke tabung yang sama!\n";
        return false;
    }

    if (from < 0 || from >= kapasitasTabung || to < 0 || to >= kapasitasTabung) {
        cout << "Input tidak valid!\n";
        return false;
    }

    if (kosong(from)) {
        cout << "Tabung asal kosong!\n";
        return false;
    }

    if (penuh(to)) {
        cout << "Tabung tujuan penuh!\n";
        return false;
    }

    char bola = pop(from);
    push(to, bola);
    langkah++;

    return true;
}

bool menang() {
    for (int i = 0; i < kapasitasTabung; i++) {
        if (kosong(i)) continue;

        if (tabung[i].top != kapasitasBola - 1) {
            return false;
        }

        char warna = tabung[i].data[0];
        for (int j = 1; j <= tabung[i].top; j++) {
            if (tabung[i].data[j] != warna) {
                return false;
            }
        }
    }
    return true;
}

void resetGame() {
    cout << "\nGame direset!\n";
    createGame();
}

int bsp() {
    createGame();
    int from, to;
    const int kapasitasLangkah = 15;

    while (true) {
        // cout<< "\nLoading";
        // for(int i = 0; i < 3; i++){
        //     cout << ".";
        //     Sleep(100);
        // }
        // system("CLS");
        tampilkan();
        cout << "Langkah: " << langkah << "/" <<kapasitasLangkah << endl;

        if (menang()) {
            return 0;
        }

        if (langkah >= kapasitasLangkah) {
            cout << "\nSilahkan Coba Lagi!\n";
            resetGame();
            continue;
        }

        cout << "Dari tabung: "; cin >> from;
        if (cin.fail()) {
            cin.clear(); cin.ignore();
            cout << "Input harus angka!\n";
            continue;
        }

        cout << "Ke tabung: "; cin >> to;
        if (cin.fail()) {
            cin.clear(); cin.ignore();
            cout << "Input harus angka!\n";
            continue;
        }

        from--; 
        to--;

        moveBall(from, to);
    }

    return 0;
}