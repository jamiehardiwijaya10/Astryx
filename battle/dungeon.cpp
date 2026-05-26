#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "battle.cpp"
using namespace std;

enum tipeDungeon {
    TOKEN,
    RESOURCE,
    LEVEL,
    SKILL
};

struct Dungeon {
    tipeDungeon jenis;
    string area;
    int floor;
    int maxFloors;
};

struct BattleResult {
    int totalToken = 0;
    int totalResource1 = 0;
    int totalResource2 = 0;
    int totalResource3 = 0;
    int totalLevelMat = 0;
    int totalSkillMat = 0;

    string resource1;
    string resource2;
    string resource3;
    string levelMat;
    string skillMat;
};

void membaca(string username);

void addResourceToPlayer(string username, BattleResult &r) {
    ifstream file("databases/playerresources.txt");
    if (!file.is_open()) {
        cout << "Gagal membuka database resource!\n";
        return;
    }

    vector<string> lines;
    string nama;
    int kayu;
    int batu;
    int scrap;

    int bamboo;
    int clay;
    int alloy;

    int hardwood;
    int limestone;
    int copper;

    int petrifiedWood;
    int marble;
    int circuitScrap;

    int ironwood;
    int obsidian;
    int titanium;

    int token;
    int turn;
    string dummy;
    getline(file, dummy);
    bool found = false;
    while (file >> nama >> kayu >> batu >> scrap >> bamboo >> clay >> alloy >> hardwood >> limestone >> copper >> petrifiedWood >> marble >> circuitScrap >> ironwood >> obsidian >> titanium >> token >> turn) {
        if (nama == username) {
            found = true;

            if (r.resource1 == "Wood")
                kayu += r.totalResource1;
            else if (r.resource1 == "Bamboo")
                bamboo += r.totalResource1;
            else if (r.resource1 == "Hardwood")
                hardwood += r.totalResource1;
            else if (r.resource1 == "Petrified Wood")
                petrifiedWood += r.totalResource1;
            else if (r.resource1 == "Ironwood")
                ironwood += r.totalResource1;

            if (r.resource2 == "Stone")
                batu += r.totalResource2;
            else if (r.resource2 == "Clay")
                clay += r.totalResource2;
            else if (r.resource2 == "Limestone")
                limestone += r.totalResource2;
            else if (r.resource2 == "Marble")
                marble += r.totalResource2;
            else if (r.resource2 == "Obsidian")
                obsidian += r.totalResource2;

            if (r.resource3 == "Scrap")
                scrap += r.totalResource3;
            else if (r.resource3 == "Alloy")
                alloy += r.totalResource3;
            else if (r.resource3 == "Copper Ore")
                copper += r.totalResource3;
            else if (r.resource3 == "Circuit Scrap")
                circuitScrap += r.totalResource3;
            else if (r.resource3 == "Titanium Alloy")
                titanium += r.totalResource3;

            token += r.totalToken;
        }
        lines.push_back(
            nama + " " +

            to_string(kayu) + " " +
            to_string(batu) + " " +
            to_string(scrap) + " " +

            to_string(bamboo) + " " +
            to_string(clay) + " " +
            to_string(alloy) + " " +

            to_string(hardwood) + " " +
            to_string(limestone) + " " +
            to_string(copper) + " " +

            to_string(petrifiedWood) + " " +
            to_string(marble) + " " +
            to_string(circuitScrap) + " " +

            to_string(ironwood) + " " +
            to_string(obsidian) + " " +
            to_string(titanium) + " " +

            to_string(token) + " " +
            to_string(turn)
        );
    }
    file.close();

    if (!found) {
        cout << "Username tidak ditemukan di resource database!\n";
        return;
    }
    ofstream out("databases/playerresources.txt");
    out << "nama kayu batu scrap bamboo clay alloy hardwood limestone copper petrifiedWood marble circuitScrap ironwood obsidian titanium token turn\n";

    for (auto &l : lines) {
        out << l << endl;
    }
    out.close();
    cout << "Reward berhasil disimpan!\n";
}

int unlockedFloor = 1;
void setColor(int color);
void garis(int panjang, char karakter);

void animasiNomor(string jenis, int nilai, int color = 7) {
    cout << jenis;
    int current = 0;
    int step = max(1, nilai / 20);
    while (current < nilai) {
        current += step;
        if (current > nilai) {
            current = nilai;
        }

        cout << "\r" << jenis;
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

    if (menang) {
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

    if (hasil.totalToken > 0) {
        animasiNomor("Token          : ", hasil.totalToken, 14);
    }
    if (hasil.totalResource1 > 0) {
        animasiNomor(hasil.resource1 + " : ", hasil.totalResource1, 2);
    }
    if (hasil.totalResource2 > 0) {
        animasiNomor(hasil.resource2 + " : ", hasil.totalResource2, 7);
    }
    if (hasil.totalResource3 > 0) {
        animasiNomor(hasil.resource3 + " : ", hasil.totalResource3, 8);
    }
    if (hasil.totalLevelMat > 0) {
        animasiNomor(hasil.levelMat + " : ", hasil.totalLevelMat, 11);
    }
    if (hasil.totalSkillMat > 0) {
        animasiNomor(hasil.skillMat + " : ", hasil.totalSkillMat, 13);
    }

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

    if (dungeon.area == "Masonwood") {
        hasil.resource1 = "Wood";
        hasil.resource2 = "Stone";
        hasil.resource3 = "Scrap";
        hasil.levelMat = "Lunar Syringe";
        hasil.skillMat = "Powder";
    } else if (dungeon.area == "Tetsumori Forest") {
        hasil.resource1 = "Bamboo";
        hasil.resource2 = "Clay";
        hasil.resource3 = "Alloy";
        hasil.levelMat = "Kobushi Flower";
        hasil.skillMat = "Blessed Water";
    } else if (dungeon.area == "Collosseum") {
        hasil.resource1 = "Hardwood";
        hasil.resource2 = "Limestone";
        hasil.resource3 = "Copper Ore";
        hasil.levelMat = "Warrior Scroll";
        hasil.skillMat = "Broken Hero Sword";
    } else if (dungeon.area == "Sacrificial Pit"){
        hasil.resource1 = "Petrified Wood";
        hasil.resource2 = "Marble";
        hasil.resource3 = "Circuit Scrap";
        hasil.levelMat = "Cursed Soul";
        hasil.skillMat = "Abyss Core";
    } else if (dungeon.area == "Gryphon Aviary"){
        hasil.resource1 = "Ironwood";
        hasil.resource2 = "Obsidian";
        hasil.resource3 = "Titanium Alloy";
        hasil.levelMat = "Enchanted Fragment";
        hasil.skillMat = "Gryphon Crystal";
    }

    if (dungeon.jenis == TOKEN) {
        int token = 1 + rand() % 3 + (lantai / 5);
        if (isBoss) {
            token += 3;
        }
        hasil.totalToken += token;
    } else if (dungeon.jenis == RESOURCE) {
        int r1 = (70 + rand() % 51) + (lantai * 3);
        int r2 = (70 + rand() % 51) + (lantai * 3);
        int r3 = (70 + rand() % 51) + (lantai * 3);

        if (isBoss) {
            r1 *= 2;
            r2 *= 2;
            r3 *= 2;
        }

        hasil.totalResource1 += r1;
        hasil.totalResource2 += r2;
        hasil.totalResource3 += r3;
    } else if (dungeon.jenis == LEVEL) {
        int exp = 10 + rand() % 11 + (lantai * 5);

        if (isBoss) {
            exp *= 2;
        }
        hasil.totalLevelMat += exp;
    } else if (dungeon.jenis == SKILL) {
        int base = 5 + rand() % 6;
        int total = base + (lantai * 2);

        if (isBoss) {
            total *= 2;
        }
        hasil.totalSkillMat += total;
    }
}

string getJenisDungeon(tipeDungeon jenis) {
    if (jenis == TOKEN) {
        return "TOKEN";
    } else if (jenis == RESOURCE) {
        return "RESOURCE";
    } else if (jenis == LEVEL) {
        return "LEVEL";
    } else{
        return "SKILL";
    }
}

void saveCheckpoint(string username, string area, string jenis, int checkpoint) {
    ifstream file("databases/dungeon.txt");
    vector<string> lines;
    string u, a, j;
    int cp;
    string header;
    getline(file, header);
    bool found = false;
    while (file >> u >> a >> j >> cp) {

        if (u == username && a == area && j == jenis) {
            cp = checkpoint;
            found = true;
        }
        lines.push_back(
            u + " " +
            a + " " +
            j + " " +
            to_string(cp)
        );
    }
    file.close();

    if (!found) {
        lines.push_back(
            username + " " +
            area + " " +
            jenis + " " +
            to_string(checkpoint)
        );
    }
    ofstream out("databases/dungeon.txt");
    out << header << endl;

    for (string l : lines) {
        out << l << endl;
    }
    out.close();
}

int loadCheckpoint(string username, string area, string jenis) {
    ifstream file("databases/dungeon.txt");
    if (!file.is_open()) {
        return 1;
    }

    string u, a, j;
    int cp;
    string header;
    getline(file, header);
    while (file >> u >> a >> j >> cp) {
        if (u == username && a == area && j == jenis) {
            return cp;
        }
    }

    return 1;
}

void mulaiDungeon(Dungeon dungeon, string username) {
    if (dungeon.floor > unlockedFloor) {
        cout << "Checkpoint belum terbuka!\n";
        return;
    }

    BattleResult result;
    BattleResult floorReward;
    prepareBattle(username);

    while (dungeon.floor <= dungeon.maxFloors) {
        cout << "\n==============================\n";
        cout << "      " << dungeon.area << endl;
        cout << "         FLOOR " << dungeon.floor << endl;
        cout << "==============================\n";
        int hasil = battleDungeon(dungeon.floor, username, dungeon.area);

        if (hasil == 0) {
            cout << "Kamu kalah di lantai " << dungeon.floor << endl;
            cout << "Dungeon gagal...\n";
            hadiah(result, false);
            return;
        }

        cout << "\nLantai " << dungeon.floor << " selesai!\n";
        floorReward = BattleResult();
        
        reward(dungeon, floorReward);
        result.totalToken += floorReward.totalToken;
        result.totalResource1 += floorReward.totalResource1;
        result.totalResource2 += floorReward.totalResource2;
        result.totalResource3 += floorReward.totalResource3;
        result.totalLevelMat += floorReward.totalLevelMat;
        result.totalSkillMat += floorReward.totalSkillMat;
        result.resource1 = floorReward.resource1;
        result.resource2 = floorReward.resource2;
        result.resource3 = floorReward.resource3;
        result.levelMat = floorReward.levelMat;
        result.skillMat = floorReward.skillMat;

        addResourceToPlayer(username, floorReward);
        membaca(username);

        if (dungeon.floor % 5 == 0) {
            if (dungeon.floor + 1 <= dungeon.maxFloors) {
                if (unlockedFloor < dungeon.floor + 1) {
                    unlockedFloor = dungeon.floor + 1;
                    string jenisDungeon = getJenisDungeon(dungeon.jenis);
                    saveCheckpoint(
                        username,
                        dungeon.area,
                        jenisDungeon,
                        unlockedFloor
                    );
            }
            }
            cout << "\nCheckpoint terbuka!\n";
            cout << "Bisa mulai dari Floor " << unlockedFloor << endl;
        } else if (dungeon.floor == dungeon.maxFloors) {
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
    hadiah(result, true);
}

void menuDungeon(string username, string area) {
    Dungeon d;
    d.area = area;

    system("cls");
    setColor(CYAN_COLOR);
    garis(60, '=');
    cout << "                         DUNGEON\n";
    garis(60, '=');
    setColor(DEFAULT_COLOR);

    cout << "\n";
    cout << "AREA : ";
    setColor(YELLOW_COLOR);
    cout << area << "\n\n";
    setColor(DEFAULT_COLOR);

    cout << "Select a dungeon type to enter.\n";
    cout << "Each dungeon grants different rewards.\n\n";

    garis(60, '-');
    cout << "\n";

    setColor(YELLOW_COLOR);
    cout << "[1] TOKEN DUNGEON\n";
    setColor(DEFAULT_COLOR);
    cout << " Reward     : Token\n";
    cout << " Floors     : 1 - 30\n";
    if (area == "Masonwood"){
        cout << " Enemy      : "; 
        setColor(YELLOW_COLOR);
        cout << "Konyian Soldiers, Seaborn Luker\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Enemy      : "; 
        setColor(YELLOW_COLOR);
        cout << "Forest Oni, Crimson Geisha, Night Parade Monk, Calestial Samurai\n";
    } else if (area == "Collosseum") {
        cout << " Enemy      : "; 
        setColor(YELLOW_COLOR);
        cout << "Arena Beastmaster, Arena Beastmaster, Gargantuan Idol, Soulbound Senator, Bloodfang Gladiator\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Enemy      : "; 
        setColor(YELLOW_COLOR);
        cout << "Bone Prisoner, Bloodveil Necromancer, Abyssal Torturer, Frostborn Warden, Damned High Priest\n";
    } else if (area == "Gryphon Aviary") {
        cout << " Enemy      : "; 
        setColor(YELLOW_COLOR);
        cout << "Feathered Raider, High Sanctifier, Royal Executioner, Arcane Falcon Master, Grand Sentinel\n";
    }
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood"){
        cout << " Boss       : "; 
        setColor(YELLOW_COLOR);
        cout << "VESSEL OF THE DEEP\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Boss       : "; 
        setColor(YELLOW_COLOR);
        cout << "FALLEN AVATAR OF AMATERASU, SHOGUN OF HOLLOW LANTERNS\n";
    } else if (area == "Collosseum") {
        cout << " Boss       : "; 
        setColor(YELLOW_COLOR);
        cout << "EMPEROR OF ETERNAL MARBLE, THE GARGOYLE PRIMARCH\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Boss       : "; 
        setColor(YELLOW_COLOR);
        cout << "THE LICH KING";
    } else if (area == "Gryphon Aviary") {
        cout << " Boss       : "; 
        setColor(YELLOW_COLOR);
        cout << "CROWNED GRYPHON EMPEROR, SAINTESS OF THE ETERNAL SANCTUM, KING OF THE CRIMSON THRONE, SOVEREIGN OF THE SCOURGE\n";
    }
    cout << "\n";
    setColor(DEFAULT_COLOR);
    
    setColor(GREEN_COLOR);
    cout << "[2] RESOURCE DUNGEON\n";
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood") {
        cout << " Reward     : Wood, Stone, Scrap\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Reward     : Bamboo, Clay, Alloy\n";
    } else if (area == "Collosseum") {
        cout << " Reward     : Hardwood, Limestone, Copper Ore\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Reward     : Petrified Wood, Marble, Circuit Scrap\n";
    } else if (area == "Gryphon Aviary") {
        cout << " Reward     : Ironwood, Obsidian, Titanium Alloy\n";
    }
    cout << " Floors     : 1 - 30\n";
    if (area == "Masonwood"){
        cout << " Enemy      : "; 
        setColor(GREEN_COLOR);
        cout << "Konyian Soldiers, Seaborn Luker\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Enemy      : "; 
        setColor(GREEN_COLOR);
        cout << "Forest Oni, Crimson Geisha, Night Parade Monk, Calestial Samurai\n";
    } else if (area == "Collosseum") {
        cout << " Enemy      : "; 
        setColor(GREEN_COLOR);
        cout << "Arena Beastmaster, Arena Beastmaster, Gargantuan Idol, Soulbound Senator, Bloodfang Gladiator\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Enemy      : "; 
        setColor(GREEN_COLOR);
        cout << "Bone Prisoner, Bloodveil Necromancer, Abyssal Torturer, Frostborn Warden, Damned High Priest\n";
    } else if (area == "Gryphon Aviary") {
        cout << " Enemy      : "; 
        setColor(GREEN_COLOR);
        cout << "Feathered Raider, High Sanctifier, Royal Executioner, Arcane Falcon Master, Grand Sentinel\n";
    }
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood"){
        cout << " Boss       : "; 
        setColor(GREEN_COLOR);
        cout << "VESSEL OF THE DEEP\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Boss       : "; 
        setColor(GREEN_COLOR);
        cout << "FALLEN AVATAR OF AMATERASU, SHOGUN OF HOLLOW LANTERNS\n";
    } else if (area == "Collosseum") {
        cout << " Boss       : "; 
        setColor(GREEN_COLOR);
        cout << "EMPEROR OF ETERNAL MARBLE, THE GARGOYLE PRIMARCH\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Boss       : "; 
        setColor(GREEN_COLOR);
        cout << "THE LICH KING";
    } else if (area == "Gryphon Aviary") {
        cout << " Boss       : "; 
        setColor(GREEN_COLOR);
        cout << "CROWNED GRYPHON EMPEROR, SAINTESS OF THE ETERNAL SANCTUM, KING OF THE CRIMSON THRONE, SOVEREIGN OF THE SCOURGE";
    }
    cout << "\n\n";
    setColor(DEFAULT_COLOR);

    setColor(CYAN_COLOR);
    cout << "[3] LEVEL DUNGEON\n";
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood") {
        cout << " Reward     : Lunar Syringe\n";
    }
    else if (area == "Tetsumori Forest") {
        cout << " Reward     : Kobushi Flower\n";
    }
    else if (area == "Collosseum") {
        cout << " Reward     : Warrior Scroll\n";
    }
    else if (area == "Sacrificial Pit") {
        cout << " Reward     : Cursed Soul\n";
    }
    else if (area == "Gryphon Aviary") {
        cout << " Reward     : Enchanted Fragment\n";
    }
    cout << " Floors     : 1 - 30\n";
    if (area == "Masonwood"){
        cout << " Enemy      : "; 
        setColor(CYAN_COLOR);
        cout << "Konyian Soldiers, Seaborn Luker\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Enemy      : "; 
        setColor(CYAN_COLOR);
        cout << "Forest Oni, Crimson Geisha, Night Parade Monk, Calestial Samurai\n";
    } else if (area == "Collosseum") {
        cout << " Enemy      : "; 
        setColor(CYAN_COLOR);
        cout << "Arena Beastmaster, Arena Beastmaster, Gargantuan Idol, Soulbound Senator, Bloodfang Gladiator\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Enemy      : "; 
        setColor(CYAN_COLOR);
        cout << "Bone Prisoner, Bloodveil Necromancer, Abyssal Torturer, Frostborn Warden, Damned High Priest\n";
    } else if (area == "Gryphon Aviary") {
        cout << " Enemy      : "; 
        setColor(CYAN_COLOR);
        cout << "Feathered Raider, High Sanctifier, Royal Executioner, Arcane Falcon Master, Grand Sentinel\n";
    }
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood"){
        cout << " Boss       : "; 
        setColor(CYAN_COLOR);
        cout << "VESSEL OF THE DEEP\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Boss       : "; 
        setColor(CYAN_COLOR);
        cout << "FALLEN AVATAR OF AMATERASU, SHOGUN OF HOLLOW LANTERNS\n";
    } else if (area == "Collosseum") {
        cout << " Boss       : "; 
        setColor(CYAN_COLOR);
        cout << "EMPEROR OF ETERNAL MARBLE, THE GARGOYLE PRIMARCH\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Boss       : "; 
        setColor(CYAN_COLOR);
        cout << "THE LICH KING";
    } else if (area == "Gryphon Aviary") {
        cout << " Boss       : "; 
        setColor(CYAN_COLOR);
        cout << "CROWNED GRYPHON EMPEROR, SAINTESS OF THE ETERNAL SANCTUM, KING OF THE CRIMSON THRONE, SOVEREIGN OF THE SCOURGE";
    }
    cout << "\n\n";
    setColor(DEFAULT_COLOR);

    setColor(PURPLE_COLOR);
    cout << "[4] SKILL DUNGEON\n";
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood") {
        cout << " Reward     : Powder\n";
    }
    else if (area == "Tetsumori Forest") {
        cout << " Reward     : Blessed Water\n";
    }
    else if (area == "Collosseum") {
        cout << " Reward     : Broken Hero Sword\n";
    }
    else if (area == "Sacrificial Pit") {
        cout << " Reward     : Abyss Core\n";
    }
    else if (area == "Gryphon Aviary") {
        cout << " Reward     : Gryphon Crystal\n";
    }
    cout << " Floors     : 1 - 30\n";
    if (area == "Masonwood"){
        cout << " Enemy      : "; 
        setColor(PURPLE_COLOR);
        cout << "Konyian Soldiers, Seaborn Luker\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Enemy      : "; 
        setColor(PURPLE_COLOR);
        cout << "Forest Oni, Crimson Geisha, Night Parade Monk, Calestial Samurai\n";
    } else if (area == "Collosseum") {
        cout << " Enemy      : "; 
        setColor(PURPLE_COLOR);
        cout << "Arena Beastmaster, Arena Beastmaster, Gargantuan Idol, Soulbound Senator, Bloodfang Gladiator\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Enemy      : "; 
        setColor(PURPLE_COLOR);
        cout << "Bone Prisoner, Bloodveil Necromancer, Abyssal Torturer, Frostborn Warden, Damned High Priest\n";
    } else if (area == "Gryphon Aviary") {
        cout << " Enemy      : "; 
        setColor(PURPLE_COLOR);
        cout << "Feathered Raider, High Sanctifier, Royal Executioner, Arcane Falcon Master, Grand Sentinel\n";
    }
    setColor(DEFAULT_COLOR);
    if (area == "Masonwood"){
        cout << " Boss       : "; 
        setColor(PURPLE_COLOR);
        cout << "VESSEL OF THE DEEP\n";
    } else if (area == "Tetsumori Forest") {
        cout << " Boss       : "; 
        setColor(PURPLE_COLOR);
        cout << "FALLEN AVATAR OF AMATERASU, SHOGUN OF HOLLOW LANTERNS\n";
    } else if (area == "Collosseum") {
        cout << " Boss       : "; 
        setColor(PURPLE_COLOR);
        cout << "EMPEROR OF ETERNAL MARBLE, THE GARGOYLE PRIMARCH\n";
    } else if (area == "Sacrificial Pit") {
        cout << " Boss       : "; 
        setColor(PURPLE_COLOR);
        cout << "THE LICH KING";
    } else if (area == "Gryphon Aviary") {
        cout << " Boss       : "; 
        setColor(PURPLE_COLOR);
        cout << "CROWNED GRYPHON EMPEROR, SAINTESS OF THE ETERNAL SANCTUM, KING OF THE CRIMSON THRONE, SOVEREIGN OF THE SCOURGE";
    }
    cout << "\n\n";
    setColor(DEFAULT_COLOR);

    setColor(RED_COLOR);
    cout << "[0] EXIT\n";
    setColor(DEFAULT_COLOR);
    garis(60, '=');
    cout << "\n";
    cout << "Choose Dungeon : ";
    int pilihan; cin >> pilihan;
    cin.clear(); cin.ignore();
    system("cls");

    if (pilihan == 0) {
        return;
    }
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
    

    string jenisDungeon = getJenisDungeon(d.jenis);
    unlockedFloor = loadCheckpoint(username, area, jenisDungeon);
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

    cout << "0. Kembali\n";
    cout << "Pilihan: ";
    int pilihStart; cin >> pilihStart;
    system("CLS");

    if (pilihStart == 0) {
        menuDungeon(username, area);
        return;
    }
    if (pilihStart < 1 || pilihStart > checkpoints.size()) {
        cout << "Pilihan tidak valid!\n";
        return;
    }
    d.floor = checkpoints[pilihStart - 1];

    mulaiDungeon(d, username);
}

int dungeon(string username, string area) {
    menuDungeon(username, area);

    return 0;
}