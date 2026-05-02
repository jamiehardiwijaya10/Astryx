#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
using namespace std;

enum tipeDungeon {
    TOKEN,
    RESOURCE,
    LEVEL,
    SKILL
};

struct Dungeon {
    tipeDungeon jenis;
    int floor;
    int maxFloors;
}; 

struct BattleResult {
    int totalToken = 0;
    int totalKayu = 0;
    int totalBatu = 0;
    int totalBesi = 0;
    int totalLevelMat = 0;
    int totalSkillMat = 0;
};

int battleDungeon(int floor);
int unlockedFloor = 1;
void setColor(int color);
void garis(int panjang, char karakter);

void animasiNomor(string jenis, int nilai, int color = 7) {
    cout << jenis;
    int current = 0;
    int step = max(1, nilai / 20);

    while (current < nilai) {
        current += step;
        if (current > nilai) current = nilai;

        cout << "\r" << nilai;
        setColor(color);
        cout << current;
        setColor(7);
        Sleep(20);
    }
    cout << endl;
}

void hadiah(BattleResult hasil, bool menang) {
    system("cls");
    setColor(6);
    cout << "\n==============================\n";
    cout << "       DUNGEON RESULT\n";
    cout << "==============================\n";
    setColor(7);
    Sleep(500);

    if(menang){
        setColor(10);
        cout << "\n        VICTORY!\n\n";
    } else {
        setColor(4);
        cout << "\n        DEFEAT...\n\n";
    }
    setColor(7);
    Sleep(700);

    cout << "Menghitung hasil...\n";
    Sleep(800);
    cout << "\n--- REWARD ---\n\n";

    if (hasil.totalToken > 0) animasiNomor("Token        : ", hasil.totalToken, 14);
    if (hasil.totalKayu > 0) animasiNomor("Kayu         : ", hasil.totalKayu, 2);
    if (hasil.totalBatu > 0) animasiNomor("Batu         : ", hasil.totalBatu, 7);
    if (hasil.totalBesi > 0) animasiNomor("Besi         : ", hasil.totalBesi, 8);
    if (hasil.totalLevelMat > 0) animasiNomor("Level Mat    : ", hasil.totalLevelMat, 11);
    if (hasil.totalSkillMat > 0) animasiNomor("Skill Mat    : ", hasil.totalSkillMat, 13);
    Sleep(500);

    setColor(6);
    cout << "\n==============================\n";
    cout << "        SELESAI\n";
    cout << "==============================\n";
    setColor(7);
    Sleep(1000);
}

void reward(Dungeon dungeon, BattleResult &hasil) {
    int lantai = dungeon.floor;
    bool isBoss = (lantai % 5 == 0);

    if (dungeon.jenis == TOKEN) {
        int token = 1 + rand() % 3 + (lantai / 5);
        if (isBoss) {
            token += 3;
        }
        hasil.totalToken += token;
        cout << "Kamu mendapatkan " << token << " token!\n";
    }  else if (dungeon.jenis == RESOURCE) {
        int kayu = (70 + rand() % 51) + (lantai * 3);
        int batu = (70 + rand() % 51) + (lantai * 3);
        int besi = (70 + rand() % 51) + (lantai * 3);

        if (isBoss) {
            kayu *= 2;
            batu *= 2;
            besi *= 2;
        }
        hasil.totalKayu += kayu;
        hasil.totalBatu += batu;
        hasil.totalBesi += besi;

        cout << "Mendapatkan resource:\n";
        cout << "KAYU " << kayu << endl;
        cout << "BATU " << batu << endl;
        cout << "SCRAP " << besi << endl;
    } else if (dungeon.jenis == LEVEL) {
        int exp = 10 + rand() % 11 + (lantai * 5);

        if (isBoss) {
            exp *= 2;
        }
        hasil.totalLevelMat += exp;
        cout << "Kamu mendapatkan " << exp << " Level Material!\n";
    } else if (dungeon.jenis == SKILL) {
        int base = 5 + rand() % 6;
        int total = base + (lantai * 2);

        if (isBoss) {
            total *= 2;
        }
        hasil.totalSkillMat += total;
        cout << "Mendapatkan Material Skill " << total << "\n";
    }
}

void mulaiDungeon(Dungeon dungeon) {
    if (dungeon.floor > unlockedFloor) {
        cout << "Checkpoint belum terbuka!\n";
        return;
    }

    BattleResult result;

    while (dungeon.floor <= dungeon.maxFloors) {
        cout << "\n==============================\n";
        cout << "           FLOOR " << dungeon.floor << endl;
        cout << "==============================\n";

        int hasil = battleDungeon(dungeon.floor);

        if (hasil == 0) {
            cout << "Kamu kalah di lantai " << dungeon.floor << endl;
            cout << "Dungeon gagal...\n";
            hadiah(result, false);
            return;
        }

        cout << "\nLantai " << dungeon.floor << " selesai!\n";
        reward(dungeon, result);

        if (dungeon.floor % 5 == 0) {
            if (unlockedFloor < dungeon.floor + 1) {
                unlockedFloor = dungeon.floor + 1;
            }
            cout << "Checkpoint terbuka! Bisa mulai dari Floor " << unlockedFloor << endl;
        }
        if (dungeon.floor == dungeon.maxFloors) {
            cout << "\nBoss dikalahkan! Dungeon selesai!\n";
            break;
        }

        cout << "\nMenuju floor berikutnya\n";
        cout << "[";
        for (int i = 0; i < 20; i++) {
            cout << "#";
            Sleep(100);
        }
        cout << "]\n";
        Sleep(300);
        system("CLS");

        dungeon.floor++;
    }

    cout << "\nDungeon selesai 30 lantai!\n";
    hadiah(result, true);
}

void menuDungeon() {
    cout << "\n===== PILIH DUNGEON =====\n";
    cout << "1. Dungeon Token\n";
    cout << "2. Dungeon Resource\n";
    cout << "3. Dungeon Level\n";
    cout << "4. Dungeon Skill\n";
    cout << "Pilihan: ";

    int pilihan;
    cin >> pilihan;
    Dungeon d;

    if (pilihan == 1) {
        d.jenis = TOKEN;
    } else if (pilihan == 2) {
        d.jenis = RESOURCE;
    } else if (pilihan == 3) {
        d.jenis = LEVEL;
    } else if (pilihan == 4) {
        d.jenis = SKILL;
    } else {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    d.maxFloors = 30;

    cout << "\nFloor terbuka sampai Floor " << unlockedFloor << endl;
    cout << "Pilih Floor:\n";
    vector<int> checkpoints;

    for (int i = 1; i <= unlockedFloor; i += 5) {
        checkpoints.push_back(i);
    }

    for (int i = 0; i < checkpoints.size(); i++) {
        cout << i + 1 << ". Floor " << checkpoints[i] << endl;
    }

    cout << "Pilihan: ";
    int pilihStart; cin >> pilihStart;
    system("CLS");

    if (pilihStart < 1 || pilihStart > checkpoints.size()) {
        cout << "Pilihan tidak valid!\n";
        return;
    }

    d.floor = checkpoints[pilihStart - 1];
    mulaiDungeon(d);
}

int dungeon() {
    srand(time(0));
    menuDungeon();
    return 0;
}