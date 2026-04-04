#include <iostream>
#include <windows.h>
#include "../utils/helper.cpp"
using namespace std;

int chap1(){
    system("cls");
    typing("CHAPTER 1 - RETURN TO MORIVELLE", 100);
    Sleep(800);
    
    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("ACT 1 - The Night Raiders", 100);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Ariolla Monument, Ariolla Port, Morivelle City.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("23 September 1891", 40);
    typing("10.51 PM", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Setelah melalui perjalanan selama 14 jam dari Pelabuhan Elpis, Elias tiba di Morivelle.", 40);
    typing("Tepatnya di Ariolla Port yang dulu menjadi pusat kedatangan turis ke Morivelle dan 1 dari 5 region besar di Morivelle", 40);
    typing("\"Apakah ini... A-Ariolla Port?\"", 40);
    typing("\"A-Apa yang terjadi disini?\"", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Ariolla Port yang dulu ramai dengan turis kini berubah menjadi kota mati yang sunyi. Bangunan-bangunan yang dulu megah kini hancur dan dipenuhi dengan tanaman liar.", 40);
    typing("Pelabuhan yang dulu penuh dengan kapal kini kosong dan dipenuhi dengan sampah-sampah yang berserakan.", 40);
    typing("Elias berjalan menyusuri pelabuhan dengan perasaan campur aduk antara sedih, marah, dan bingung.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Fenomena The Red Tide belum mampu memberikan dampak sebesar ini.", 40);
    typing("\"Apakah ini puncak kerusakan dari The Red Tide? Aku harus mencari tahu", 40);
    typing("Mengesampingkan emosinya, Elias pergi untuk mencari tahu apa yang terjadi dengan kota asalnya", 40);
    typing("Ia mulai mencari informasi dengan memeriksa bangunan-bangunan yang masih berdiri, mencari petunjuk tentang apa yang terjadi di Ariolla Monument.", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    return 0;
}

int main() {
    chap1();
    return 0;
}