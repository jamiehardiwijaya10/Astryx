#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

int nilaiKartu(string kartu, int jumlahSaatIni, bool pemain = true) {
    if (kartu == "J") return 11;
    if (kartu == "Q") return 12;
    if (kartu == "K") return 13;
    if (kartu == "A") return 14;

    return stoi(kartu);
}

int total(string megang[], int berapaKartu, bool pemain = true) {
    if (berapaKartu == 2 && megang[0] == "A" && megang[1] == "A") {
        return 15;
    }

    int total = 0;
    int jumlahAs = 0;
    for (int i = 0; i < berapaKartu; i++) {
        if (megang[i] == "A") {
            total += 14;
            jumlahAs++;
        } else {
            total += nilaiKartu(megang[i], total, pemain);
        }
    }

    while (total > 21 && jumlahAs > 0) {
        total -= 13;
        jumlahAs--;
    }

    return total;
}

void acak(string kartu[]) {
    srand(time(0));
    for (int i = 0; i < 52; i++) {
        int r = rand() % 52;
        swap(kartu[i], kartu[r]);
    }
}

void tampilkan(string megang[], int berapaKartu, bool sembunyi = false) {
    for (int i = 0; i < berapaKartu; i++) {
        if (sembunyi)
            cout << "* ";
        else
            cout << megang[i] << " ";
    }
}

int main() {
    char ulang;

    do {
        system("CLS");
        string kartuDasar[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        string kartu[52];
        int index = 0;
    
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 13; j++)
                kartu[index++] = kartuDasar[j];
    
        acak(kartu);
        string pemain[10], lawan[10];
        int p = 0, l = 0, top = 0;
    
        pemain[p++] = "A";
        lawan[l++] = kartu[top++];
        pemain[p++] = "A";
        lawan[l++] = kartu[top++];
    
        char pilih;
        while(true) {
            cout << "Membagikan Kartu ";
            for(int i = 0; i < 3; i++){
                cout << ".";
            }
            Sleep(1000);
            system("CLS");

            cout << "========== BLACKJACK ==========\n";
            cout << "J = 11, Q = 12, K = 13, A = 14\n";
            cout << "===============================\n";
            cout << "Player: ";
            tampilkan(pemain, p);
            cout << " (Total: " << total(pemain, p) << ")\n";
    
            cout << "Dealer: ";
            tampilkan(lawan, l, true);
            cout << endl;
    
            if (total(pemain, p) > 21) {
                cout << "Player bust!\n";
                break;
            }

            do {
                cout << "Hit / Stand (h/s): "; cin >> pilih;
                pilih = tolower(pilih);
                if (pilih != 'h' && pilih != 's') {
                    cout << "Input tidak valid! Masukkan hanya 'h' atau 's'.\n";
                }
            } while (pilih != 'h' && pilih != 's');

        if (pilih == 'h')
            pemain[p++] = kartu[top++];
        else if (pilih == 's')
            break;
                }
    
        cout << "\nGiliran Lawan ";
        for(int i = 0; i < 3; i++){
            cout << ".";
            Sleep(1000);
        }
    
        while (total(lawan, l, false) < 17) {
            lawan[l++] = kartu[top++];
        }
    
        system("CLS");
        cout << "========== HASIL ==========\n";
        cout << "Player: "; tampilkan(pemain, p);
        cout << " (" << total(pemain, p) << ")\n";
    
        cout << "Dealer: ";
        tampilkan(lawan, l);
        cout << " (" << total(lawan, l) << ")\n";
    
        bool seri = false;
        int totalPlayer = total(pemain, p);
        int totalDealer = total(lawan, l);
        if (totalPlayer <= 21 && (totalDealer > 21 || totalPlayer > totalDealer)) {
            cout << "\nMenang! Langsung keluar game.\n";
            break;
        }
        if (totalPlayer > 21 || (totalDealer <= 21 && totalDealer > totalPlayer)) {
            cout << "\nKalah! Ulang otomatis...\n";
            Sleep(1500);
            ulang = 'y';
        } 
        else {
            do {
                cout << "\nSeri! Mau ulang (y/n): "; cin >> ulang;
                if(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
                    cout << "Input tidak valid! Masukkan hanya y atau n.\n";
                }
            } while(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');
        }
    } while(ulang == 'y' || ulang == 'Y');

    return 0;
}