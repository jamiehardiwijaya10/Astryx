#include <iostream>
#include <cstdlib>
using namespace std;

char papan[3][3];
void init() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            papan[i][j] = ' ';
        }
    }
}

void tampil() {
   cout << " --------- \n";
   
   for (int i = 0; i < 3; i++) {
      cout << " | ";
      for (int j = 0; j < 3; j++) {
         cout << papan[i][j];
         if (j < 2) cout << " | ";
      }
      cout << endl;
      if (i < 2){
         cout << " --------- \n";
      }
   }

}

bool menang(char p) {
    for (int i = 0; i < 3; i++) {
        if (papan[i][0] == p && papan[i][1] == p && papan[i][2] == p)
            return true;
        if (papan[0][i] == p && papan[1][i] == p && papan[2][i] == p)
            return true;
    }

    if (papan[0][0] == p && papan[1][1] == p && papan[2][2] == p)
        return true;

    if (papan[0][2] == p && papan[1][1] == p && papan[2][0] == p)
        return true;

    return false;
}

// ================= CEK FULL =================
bool penuh() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] != 'X' && papan[i][j] != 'O')
                return false;
        }
    }
    return true;
}

// ================= CEK MOVE MENANG =================
bool cobaMenang(int &r, int &c, char p) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (papan[i][j] != 'X' && papan[i][j] != 'O') {
                char temp = papan[i][j];
                papan[i][j] = p;

                if (menang(p)) {
                    r = i;
                    c = j;
                    papan[i][j] = temp;
                    return true;
                }

                papan[i][j] = temp;
            }
        }
    }
    return false;
}

// ================= AI =================
void aiMove() {
    int r, c;

    // 1. AI menang
    if (cobaMenang(r, c, 'O')) {
        papan[r][c] = 'O';
        return;
    }

    // 2. Blok player
    if (cobaMenang(r, c, 'X')) {
        papan[r][c] = 'O';
        return;
    }

    // 3. Tengah
    if (papan[1][1] != 'X' && papan[1][1] != 'O') {
        papan[1][1] = 'O';
        return;
    }

    // 4. Random
    while (true) {
        int i = rand() % 3;
        int j = rand() % 3;

        if (papan[i][j] != 'X' && papan[i][j] != 'O') {
            papan[i][j] = 'O';
            return;
        }
    }
}

// ================= MAIN =================
int main() {
    init();

    int pilihan;

    while (true) {
        tampil();

        // PLAYER
        cout << "Giliran kamu (X)\n";
        cout << "Pilih (1-9): ";
        cin >> pilihan;

        int r = (pilihan - 1) / 3;
        int c = (pilihan - 1) % 3;

        if (papan[r][c] == 'X' || papan[r][c] == 'O') {
            cout << "Sudah diisi!\n";
            continue;
        }

        papan[r][c] = 'X';

        if (menang('X')) {
            tampil();
            cout << "🎉 Kamu menang!\n";
            break;
        }

        if (penuh()) {
            tampil();
            cout << "😐 Seri!\n";
            break;
        }
        aiMove();

        if (menang('O')) {
            tampil();
            cout << "💀 AI menang!\n";
            break;
        }

        if (penuh()) {
            tampil();
            cout << "😐 Seri!\n";
            break;
        }
    }

    return 0;
}