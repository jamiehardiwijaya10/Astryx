#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Skill {
    string name;
    string type;
    int power;
    int duration;
    int cooldown;
    int currentCD = 0;
    int level = 1;
};

struct CharacterData {
    string name;
    int level;
    int exp;
    int baseHP;
    int baseATK;
    int baseDEF;

    int skill1;
    int skill2;
    int skill3;

    bool unlocked;
    vector<string> skillsName;
    vector<int> skillLevels;
};

struct PlayerData {
    string name;
    int syringe;
    int powder;

    vector<CharacterData> ownedCharacters;
    vector<string> partyNames;
};

vector<CharacterData> loadCharacterDB();
void assignStarterCharacter(PlayerData &p);
void savePlayer(PlayerData &p);

vector<CharacterData> loadPlayerCharacters(string username) {
    vector<CharacterData> list;
    ifstream file("../databases/playerchara.txt");
    if (!file.is_open()) return list;

    string name;
    while (file >> name) {
        int count;
        file >> count;
        if (count < 0 || count > 50) {
            cout << "Corrupted data!\n";
            break;
        }

        vector<CharacterData> temp;

        for (int i = 0; i < count; i++) {
            CharacterData c;
            int skillCount;
            file >> c.name >> c.level >> c.exp >> skillCount;

            if (skillCount < 0 || skillCount > 10) {
                cout << "Corrupted skill data!\n";
                return {};
            }

            c.skillsName.clear();
            c.skillLevels.clear();

            for (int j = 0; j < skillCount; j++) {
                string s;
                int lvl;
                file >> s >> lvl;

                c.skillsName.push_back(s);
                c.skillLevels.push_back(lvl);
            }
            temp.push_back(c);
        }

        if (name == username) {
            list = temp;
            break;
        }
    }
    vector<CharacterData> db = loadCharacterDB();

    for (auto &c : list) {
        bool found = false;
        for (auto &d : db) {
            if (c.name == d.name) {
                c.baseHP = d.baseHP;
                c.baseATK = d.baseATK;
                c.baseDEF = d.baseDEF;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Warning: Character " << c.name << " tidak ditemukan di database!\n";
        }
    }
    return list;
}

void savePlayerCharacters(PlayerData &p) {
    vector<string> all;
    vector<CharacterData> list;
    ifstream file("../databases/playerchara.txt");
    if (!file.is_open()) {
        cout << "Failed to open player characters file! Making new one...\n";
    }

    string line;
    string name;

    while (file >> name) {
        int count;
        file >> count;
        if (count < 0 || count > 50) {
            cout << "Corrupted data!\n";
            break;
        }

        vector<string> block;
        
        block.push_back(name + " " + to_string(count));

        for (int i = 0; i < count; i++) {
            string line;
            getline(file >> ws, line);

            block.push_back(line);
        }

        if (name != p.name) {
            for (auto &l : block)
                all.push_back(l);
        }
    }
    file.close();

    ofstream out("../databases/playerchara.txt", ios::trunc);

    for (auto &l : all) {
        out << l << endl;
    }

    out << p.name << " " << p.ownedCharacters.size() << endl;
    if (p.ownedCharacters.empty()) {
        cout << "Warning: no characters to save\n";
    }

    for (auto &c : p.ownedCharacters) {
        out << c.name << " " << c.level << " " << c.exp << " " << c.skillsName.size();

        for (int i = 0; i < c.skillsName.size() && i < c.skillLevels.size(); i++) {
            out << " " << c.skillsName[i] << " " << c.skillLevels[i];
        }

        out << endl;
    }

    out.close();
}

int getRequiredExp(int level) {
    return 50 * level;
}

void addCharacterExp(CharacterData &c, int amount) {
    c.exp += amount;

    while (c.exp >= getRequiredExp(c.level)) {
        c.exp -= getRequiredExp(c.level);
        c.level++;

        cout << "\n" << c.name << " LEVEL UP! Sekarang level " << c.level << endl;
    }
}

int getFinalHP(const CharacterData &c) {
    return c.baseHP + (c.level - 1) * 10;
}

int getFinalATK(const CharacterData &c) {
    return c.baseATK + (c.level - 1) * 2;
}

int getFinalDEF(const CharacterData &c) {
    return c.baseDEF + (c.level - 1) * 2;
}

vector<Skill> getCharacterSkills(CharacterData &cd) {
    vector<Skill> skills;

    for (int i = 0; i < cd.skillsName.size() && i < cd.skillLevels.size(); i++) {
        string skillName = cd.skillsName[i];
        int skillLvl = cd.skillLevels[i];

        Skill s;

        if (skillName == "IronVerdict")
            s = {"Iron Verdict", "damage", 20 + (skillLvl * 5), 0, 2};
        else if (skillName == "ShieldThrust")
            s = {"Shield Thrust", "damage", 15 + (skillLvl * 4), 0, 1};
        else if (skillName == "ButterflyBlessings")
            s = {"Butterfly Blessings", "heal", 25 + (skillLvl * 6), 0, 3};
        else if (skillName == "BambooSlash")
            s = {"Bamboo Slash", "damage", 18 + (skillLvl * 5), 0, 2};
        else if (skillName == "DivineDivergence")
            s = {"Divine Divergence", "aoe", 22 + (skillLvl * 5), 0, 4};
        else {
            continue; 
        }
        skills.push_back(s);
    }

    return skills;
}

PlayerData loadPlayer(string username) {
    ifstream file("../databases/playerdata.txt");
    PlayerData p{};
    bool found = false;
    p.partyNames.resize(3, "");
    p.ownedCharacters = loadPlayerCharacters(username);

    string line;
    getline(file, line);

    while (getline(file, line)) {
        stringstream ss(line);
        string name;
        ss >> name;
        
        if (name == username) {
            found = true;
            
            p.name = name;
            
            ss >> p.syringe >> p.powder;
            
            string a, b, c;
            
            if (ss >> a) p.partyNames[0] = a;
            if (ss >> b) p.partyNames[1] = b;
            if (ss >> c) p.partyNames[2] = c;
            break;
        }
    }
    if (!found) {
        cout << "Player tidak ditemukan!\n";
    }
    if (!found || p.ownedCharacters.empty()) {
        cout << "\n[!] Kamu belum memiliki karakter!\n";
        cout << "Silakan pilih minimal 1 karakter.\n";
        
        system("pause");
        system("cls");
        
        while (p.ownedCharacters.empty()) {
            cout << "\n[!] Kamu wajib memiliki minimal 1 karakter!\n";
            assignStarterCharacter(p);
        }
        savePlayer(p);
        savePlayerCharacters(p);
    }
    return p;
}

void showParty(PlayerData &p) {
    if (p.partyNames.size() < 3) {
        p.partyNames.resize(3, "");
    }
    cout << "\n=== PARTY ===\n";
    for (int i = 0; i < 3; i++) {
        cout << i + 1 << ". ";
        if (p.partyNames[i] == "")
            cout << "[Empty]";
        else
            cout << p.partyNames[i];
        cout << endl;
    }
}

int chooseCharacter(PlayerData &p) {
    cout << "\n=== PILIH KARAKTER ===\n";

    for (int i = 0; i < p.ownedCharacters.size(); i++) {
        cout << i + 1 << ". " << p.ownedCharacters[i].name << endl;
    }

    cout << "0. Batal\n";
    cout << "Pilih: ";

    int pilih;
    cin >> pilih;

    if (pilih <= 0 || pilih > p.ownedCharacters.size())
        return -1;

    return pilih - 1;
}

void setParty(PlayerData &p) {
    while (true) {
        system("cls");
        showParty(p);

        cout << "\n1. Set Slot\n2. Remove Slot\n0. Kembali\nPilih: ";

        int pilih;
        cin >> pilih;

        if (pilih == 0) return;

        if (pilih == 1) {
            int slot;
            cout << "Pilih slot (1-3): ";
            cin >> slot;

            if (slot < 1 || slot > 3) continue;

            int idx = chooseCharacter(p);
            if (idx == -1) continue;

            p.partyNames[slot - 1] = p.ownedCharacters[idx].name;

            cout << "Party diupdate!\n";
            system("pause");
        }

        else if (pilih == 2) {
            int slot;
            cout << "Slot mana (1-3): ";
            cin >> slot;

            if (slot < 1 || slot > 3) continue;

            p.partyNames[slot - 1] = "";

            cout << "Slot dikosongkan!\n";
            system("pause");
        }
    }
}

bool isPartyValid(PlayerData &p) {
    for (auto &n : p.partyNames) {
        if (n != "") return true;
    }
    return false;
}

vector<CharacterData> getPartyCharacters(PlayerData &p) {
    vector<CharacterData> party;

    for (auto &name : p.partyNames) {
        if (name == "") continue;

        for (auto &c : p.ownedCharacters) {
            if (c.name == name) {
                party.push_back(c);
                break;
            }
        }
    }

    return party;
}

void prepareBattle(string username) {
    PlayerData p = loadPlayer(username);

    while (true) {
        system("cls");

        cout << "=== PREPARE PARTY ===\n";
        showParty(p);

        cout << "\n1. Atur Party\n";
        cout << "0. Selesai\n";
        cout << "Pilih: ";

        int pilih;
        cin >> pilih;

        if (pilih == 0) {
            savePlayer(p);
            return;
        }

        if (pilih == 1) {
            setParty(p);
        }
    }
}

vector<CharacterData> loadCharacterDB() {
    vector<CharacterData> list;
    ifstream file("../databases/characters.txt");
    if (!file.is_open()) return list;

    string header;
    getline(file, header);

    CharacterData c;

    int skillCount;
    while (file >> c.name >> c.level >> c.baseHP >> c.baseATK >> c.baseDEF >> skillCount) {
        c.skillsName.clear();

        for (int i = 0; i < skillCount; i++) {
            string s;
            file >> s;
            c.skillsName.push_back(s);
        }

        file >> c.unlocked;

        list.push_back(c);
    }

    return list;
}

void assignStarterCharacter(PlayerData &p) {
    // vector<CharacterData> db = loadPlayerCharacters(p.name);
    vector<CharacterData> db = loadCharacterDB();
    if (db.empty()) {
        cout << "Database karakter kosong!\n";
        return;
    }

    cout << "=== PILIH KARAKTER ===\n";

    for (int i = 0; i < db.size(); i++) {
        cout << i + 1 << ". " << db[i].name;
        if (!db[i].unlocked) {
            cout << " [LOCKED]\n";
        } else {
            cout << " (HP:" << db[i].baseHP
            << " ATK:" << db[i].baseATK
            << " DEF:" << db[i].baseDEF << ")\n";
        }
    }

    cout << "Pilihan: ";
    int pilih;
    cin >> pilih;

    pilih--;

    if (pilih >= 0 && pilih < db.size()) {
        if (!db[pilih].unlocked) {
            cout << "Karakter masih terkunci!\n";
        } else {
            for (auto &c : p.ownedCharacters) {
                if (c.name == db[pilih].name) {
                    cout << "Sudah dimiliki!\n";
                    return;
                }
            }

            CharacterData newChar = db[pilih];
            newChar.skillLevels = vector<int>(newChar.skillsName.size(), 1);
            newChar.exp = 0;
            p.ownedCharacters.push_back(newChar);
            
            bool alreadyInParty = false;
            for (auto &name : p.partyNames) {
                if (name == db[pilih].name) {
                    alreadyInParty = true;
                    break;
                }
            }

            if (!alreadyInParty) {
                for (int i = 0; i < 3; i++) {
                    if (p.partyNames[i] == "") {
                        p.partyNames[i] = db[pilih].name;
                        break;
                    }
                }
            }
            cout << "Karakter berhasil dipilih!\n";}
        } 
    else {
        cout << "Pilihan tidak valid!\n";
    }

    system("pause");
    system("cls");
}

void unlockCharacter(string charName) {
    vector<CharacterData> db = loadCharacterDB();
    if (db.empty()) {
        cout << "Database karakter kosong!\n";
        return;
    }

    for (auto &c : db) {
        if (c.name == charName) {
            c.unlocked = true;
        }
    }

    ofstream out("../databases/characters.txt");
    out << "name level HP ATK DEF skillCount skill1 skill2 unlocked\n";

    for (auto &c : db) {
        out << c.name << " "
            << c.level << " "
            << c.baseHP << " "
            << c.baseATK << " "
            << c.baseDEF << " "
            << c.skillsName.size();

        for (auto &s : c.skillsName) {
            out << " " << s;
        }

        out << " " << c.unlocked << endl;
    }
    out.close();
}

void savePlayer(PlayerData &p) {
    vector<string> all;
    ifstream file("../databases/playerdata.txt");
    string line;

    getline(file, line);
    all.push_back("name syringe powder party1 party2 party3");

    while (getline(file, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        string name;
        ss >> name;

        if (name != p.name) {
            all.push_back(line);
        }
    }
    file.close();

    ofstream out("../databases/playerdata.txt");

    for (auto &l : all) {
        out << l << endl;
    }

    out << p.name << " "
        << p.syringe << " "
        << p.powder << " ";

    vector<string> party = p.partyNames;
    party.resize(3, "");

    out << party[0] << " "
        << party[1] << " "
        << party[2];

    out << endl;

    out.close();
}