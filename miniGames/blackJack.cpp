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
    int total = 0;
    for (int i = 0; i < berapaKartu; i++) {
        total += nilaiKartu(megang[i], total, pemain);
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
    int saldo = 250;
    char ulang;

    do {
        system("CLS");
        cout << "Gold Anda: " << saldo << " g\n";
        int depo;
        do {
            cout << "Masukkan taruhan untuk ronde ini: "; cin >> depo;
            if (depo <= 0 || depo > saldo)
                cout << "Taruhan tidak valid! Masukkan angka antara 1 sampai saldo Anda.\n";
        } while (depo <= 0 || depo > saldo);

        string kartuDasar[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
        string kartu[52];
        int index = 0;
    
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 13; j++)
                kartu[index++] = kartuDasar[j];
    
        acak(kartu);
        string pemain[10], lawan[10];
        int p = 0, l = 0, top = 0;
    
        pemain[p++] = kartu[top++];
        lawan[l++] = kartu[top++];
        pemain[p++] = kartu[top++];
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
                cout << "AWOKWOWO bust!\n";
                break;
            }
    
            cout << "Hit / Stand (h/s): "; cin >> pilih;
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

        cout << "Saldo sekarang: " << saldo << "\n";

        if (saldo <= 0) {
            cout << "Saldo habis! Permainan selesai.\n";
            break;
        }

        do {
            cout << "\nApakah mau ulang (y/n): "; cin >> ulang;
            if(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
                cout << "Input tidak valid! Masukkan hanya y atau n.\n";
            }
        } while(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');

    } while(ulang == 'y' || ulang == 'Y');

    system("CLS");
    cout << "Nah thenks for playing.\nSaldo akhir: " << saldo << " g";

    return 0;
}