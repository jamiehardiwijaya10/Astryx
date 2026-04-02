#include<iostream>
#include<cstdlib>
#include<ctime>
#include<windows.h>
using namespace std;

void bkg(char pilihan, char musuh){
    cout << "-----------------------------\n";
    cout << "Hasil: ";

    if(pilihan == 'b' || pilihan == 'B'){
        if(musuh == 'b'){
            cout << "Seri";
        } else if(musuh == 'k') {
            cout << "Kalah";
        } else if(musuh == 'g'){
            cout << "Menang";
        }
    }
    if(pilihan == 'k' || pilihan == 'K'){
        if(musuh == 'b'){
            cout << "Menang";
        } else if(musuh == 'k') {
            cout << "Seri";
        } else if(musuh == 'g'){
            cout << "Kalah";
        }
    }
    if(pilihan == 'g' || pilihan == 'G'){
        if(musuh == 'b'){
            cout << "Kalah";
        } else if(musuh == 'k') {
            cout << "Menang";
        } else if(musuh == 'g'){
            cout << "Seri";
        }
    }
    cout << "\n-----------------------------\n";
}

string namaPilihan(char x){
    if(x == 'b' || x == 'B') return "Batu";
    if(x == 'k' || x == 'K') return "Kertas";
    if(x == 'g' || x == 'G') return "Gunting";
    return "";
}

int main(){
    srand(time(0));
    char ulang;

    do{
        int skorPlayer = 0;
        int skorMusuh = 0;
        while(skorPlayer < 2 && skorMusuh < 2){
            system("CLS");
            char musuh;
            int r = rand() % 3;
            
            if(r == 0) musuh = 'b';
            else if(r == 1) musuh = 'k';
            else musuh = 'g';
            char pilihan;
            cout << "======== BATU KERTAS GUNTING ========\n";
            cout << "   Skor Anda: " << skorPlayer << "     Skor Musuh: " << skorMusuh << endl;
            cout << "====================================\n";
            cout << "b = Batu | k = Kertas | g = Gunting\n";
            cout << "====================================\n";

            do {
                cout << "Pilih: "; cin >> pilihan;
                if(pilihan != 'b' && pilihan != 'B' && pilihan != 'k' && pilihan != 'K' && pilihan != 'g' && pilihan != 'G'){
                    cout << "Input tidak valid! Hanya boleh b, k, atau g.\n";
                }
            } while(pilihan != 'b' && pilihan != 'B' && pilihan != 'k' && pilihan != 'K' && pilihan != 'g' && pilihan != 'G');
            
            cout << "Musuh Memilih: ";
            for (int i = 0; i < 3; i++){
                cout << ".";
                Sleep(500);
            }
            system("CLS");

            if((pilihan == 'b' && musuh == 'g') || (pilihan == 'k' && musuh == 'b') || (pilihan == 'g' && musuh == 'k')){
                skorPlayer++;
            } else if((pilihan == 'b' && musuh == 'k') || (pilihan == 'k' && musuh == 'g') || (pilihan == 'g' && musuh == 'b')){
                skorMusuh++;
            }

            cout << "======== BATU KERTAS GUNTING ========\n";
            cout << "\nPilihan Player: " << namaPilihan(pilihan) << endl;
            cout << "Pilihan Musuh: " << namaPilihan(musuh) << endl;
            bkg(pilihan, musuh);
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore(); cin.get();
        }

        if(skorPlayer == 2){
            cout << "Weh gelo kroco bisa menang boleh juga tuh hoki";
        } else {
            cout << "AWOWKOWKWO bot !!!";
        }

        do {
            cout << "\nApakah mau ulang (y/n): "; cin >> ulang;

            if(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N'){
                cout << "Input tidak valid! Masukkan hanya y atau n.\n";
            }
        } while(ulang != 'y' && ulang != 'Y' && ulang != 'n' && ulang != 'N');
    } while(ulang == 'y' || ulang == 'Y');

    cout << "\n======== Matur Suwun ========\n";
}