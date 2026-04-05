#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
using namespace std;

struct kartu{
    kartu *next;
    int nilai;
    bool terbuka;
    bool hilang;
};

kartu *buatKartu() {
    kartu *first = NULL;
    kartu *last = NULL;
    int nilaiKartu[] = {1, 1, 2, 2, 3, 3, 4, 4};
    
    for (int i = 0; i < 8; i++) {
        int acak = rand() % 8;
        int temp = nilaiKartu[i];
        nilaiKartu[i] = nilaiKartu[acak];
        nilaiKartu[acak] = temp;
    }

    for (int i = 0; i < 8; i++) {
        kartu *baru = new kartu();
        baru->nilai = nilaiKartu[i];
        baru->terbuka = false;
        baru->hilang = false;
        baru->next = NULL;
        
        if (first == NULL) {
            first = baru;
            last = baru;
        } else {
            last->next = baru;
            last = baru;
        }
    }
    return first;
}

void tampilkan(kartu *first) {
    cout << "======== Memory Card ========\n\n";
    kartu *current = first;

    for (int i = 1; i <= 4; i++) {
        if (current->hilang || current->terbuka)
            cout << " [ " << current->nilai << " ] ";
        else
            cout << " [ ? ] ";
        current = current->next;
    }

    cout << "\n";
    for (int i = 1; i <= 4; i++) cout << "   " << i << "   ";
    cout << "\n\n";

    for (int i = 5; i <= 8; i++) {
        if (current->hilang || current->terbuka)
            cout << " [ " << current->nilai << " ] ";
        else
            cout << " [ ? ] ";
        current = current->next;
    }

    cout << "\n";
    for (int i = 5; i <= 8; i++) cout << "   " << i << "   ";
    cout << "\n=============================\n";
}

kartu *ambilKartu(kartu *first, int posisi) {
    kartu* current = first;
    for (int i = 1; i < posisi; i++) {
        if (current == NULL) return NULL;
        current = current->next;
    }
    return current;
}

bool cekMenang(kartu *first) {
    kartu *current = first;
    while (current != NULL) {
        if (!current->hilang) return false;
        current = current->next;
    }
    return true;
}

void tutupSemuaKartu(kartu *first) {
    kartu *current = first;
    while (current != NULL) {
        if (current->terbuka && !current->hilang) {
            current->terbuka = false;
        }
        current = current->next;
    }
}

int mc() { 
    srand(time(0));

    while (true) {
        kartu *first = buatKartu();
        int pilihan1 = 0, pilihan2 = 0;
        int skor = 0;
        int percobaan = 0;
        
        while(!cekMenang(first) && percobaan < 7) {
            system("cls");
            tampilkan(first);
            cout << "\nSkor: " << skor << " | Percobaan: " << percobaan << "/7\n";

            do {
                cout << "\nPilih kartu pertama (1-8): ";
                if (!(cin >> pilihan1)) {
                    cout << "Pilihan tidak valid!\n";
                    cin.clear(); cin.ignore();
                    pilihan1 = 0;
                    continue;
                }
                kartu *kartu1 = ambilKartu(first, pilihan1);
                if (pilihan1 < 1 || pilihan1 > 8 || kartu1 == NULL || kartu1->hilang || kartu1->terbuka) {
                    cout << "Pilihan tidak valid!\n";
                    pilihan1 = 0;
                }
            } while (pilihan1 == 0);

            kartu *kartu1 = ambilKartu(first, pilihan1);
            kartu1->terbuka = true;
            system("cls");
            tampilkan(first);

            do {
                cout << "\nPilih kartu kedua (1-8): ";
                if (!(cin >> pilihan2)) {
                    cout << "Pilihan tidak valid!\n";
                    cin.clear(); cin.ignore();
                    pilihan2 = 0;
                    continue;
                }
                kartu *kartu2 = ambilKartu(first, pilihan2);
                if (pilihan2 < 1 || pilihan2 > 8 || pilihan2 == pilihan1 || kartu2 == NULL || kartu2->hilang || kartu2->terbuka) {
                    cout << "Pilihan tidak valid!\n";
                    pilihan2 = 0;
                }
            } while (pilihan2 == 0);

            kartu *kartu2 = ambilKartu(first, pilihan2);
            kartu2->terbuka = true;
            system("cls");
            tampilkan(first);
            percobaan++;
            
            if (kartu1->nilai == kartu2->nilai) {
                cout << "\nCocok!\n";
                kartu1->hilang = true;
                kartu2->hilang = true;
                skor++;
            } else {
                cout << "\nTidak cocok!\n";
                cout << "Kartu " << pilihan1 << " = " << kartu1->nilai
                     << " | Kartu " << pilihan2 << " = " << kartu2->nilai << endl;
                cout << "Tunggu Sebentar";
                for(int i = 0; i < 3; i++){
                    cout << "."; Sleep(500);
                }
                tutupSemuaKartu(first);
                continue;
            }

            // cout << "\nTekan Enter...";
            // cin.ignore(); cin.get();
        }
        system("cls");

        if (cekMenang(first)) {
            cout << "Percobaan: " << percobaan << endl;
            cout << "Skor: " << skor << "/4\n";
            
            kartu *current = first;
            while (current != NULL) {
                kartu *temp = current;
                current = current->next;
                delete temp;
            }
            break;
        } else {
            cout << "ANDA KALAH!\nMengulang game...\n";
            for(int i = 0; i < 3; i++){
                cout << "."; Sleep(500);
            }
            
            kartu *current = first;
            while (current != NULL) {
                kartu *temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    return 0;
}