#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

char papan[3][3];
void init() {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         papan[i][j] = ' ';
      }
   }
}

void tampilan() {
   cout << "=== TIC TAC TOE ===\n\n";
   for (int i = 0; i < 3; i++) {
      cout << " ";
      for (int j = 0; j < 3; j++) {
         cout << papan[i][j];
         if (j < 2) cout << " | ";
      }
      cout << endl;
      if (i < 2) cout << "---+---+---\n";
   }
   cout << endl;
}

bool menang(char p) {
   for (int i = 0; i < 3; i++) {
      if (papan[i][0] == p && papan[i][1] == p && papan[i][2] == p) return true;
      if (papan[0][i] == p && papan[1][i] == p && papan[2][i] == p) return true;
   }
   if (papan[0][0] == p && papan[1][1] == p && papan[2][2] == p) return true;
   if (papan[0][2] == p && papan[1][1] == p && papan[2][0] == p) return true;

   return false;
}

bool penuh() {
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (papan[i][j] != 'X' && papan[i][j] != 'O')
            return false;

   return true;
}

bool cobaMenang(int &b, int &k, char p) {
   for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
         if (papan[i][j] != 'X' && papan[i][j] != 'O') {
            char lama = papan[i][j];
            papan[i][j] = p;
            if (menang(p)) {
               b = i;
               k = j;
               papan[i][j] = lama;
                return true;
            }
            papan[i][j] = lama;
         }
      }
   }
   return false;
}

void acak() {
   int r, c;
   if(cobaMenang(r, c, 'O')) {
      papan[r][c] = 'O';
      return;
   }
   if(cobaMenang(r, c, 'X')) {
      papan[r][c] = 'O';
      return;
   }
   if(papan[1][1] != 'X' && papan[1][1] != 'O') {
      papan[1][1] = 'O';
      return;
   }
   while(true) {
      int i = rand() % 3;
      int j = rand() % 3;

      if(papan[i][j] != 'X' && papan[i][j] != 'O') {
         papan[i][j] = 'O';
         return;
      }
   }
}

int main() {
   srand(time(0));
   char ulang;

   do {
      init();
      while (true) {
         system("CLS");
         tampilan();
         int pilihan;
         cout << "Giliran kamu (X)\n";
            
         do {
            cout << "Pilih (1-9): ";
            cin >> pilihan;

            if (pilihan < 1 || pilihan > 9) {
               cout << "Input tidak valid!\n";
            }
         } while (pilihan < 1 || pilihan > 9);

         int r = (pilihan - 1) / 3;
         int c = (pilihan - 1) % 3;
         if (papan[r][c] == 'X' || papan[r][c] == 'O') {
            cout << "Sudah diisi!\n";
            Sleep(1000);
            continue;
         }

            papan[r][c] = 'X';
            if (menang('X')) {
            system("CLS");
            tampilan();
            cout << "GACORRRR MENANG!\n";
            break;
         }

         if(penuh()) {
            system("CLS");
            tampilan();
            cout << "Seri!\n";
            break;
         }

         cout << "Lawan Sedang Berpikir: ";
         for (int i = 0; i < 3; i++) {
            cout << ".";
            Sleep(500);
         }
         acak();

         if(menang('O')) {
            system("CLS");
            tampilan();
            cout << "AWOKWOWK KALAH LAWAN BOT\n";
            break;
         }
         if(penuh()) {
            system("CLS");
            tampilan();
            cout << "Seri!\n";
            break;
         }
      }

      do {
         cout << "\nMain lagi? (y/n): ";
         cin >> ulang;

         if (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N') {
                cout << "Input tidak valid!\n";
         }
      } while (ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');

   } while (ulang == 'y' || ulang == 'Y');

   cout << "\n=== Matur Suwun ===\n";
   return 0;
}