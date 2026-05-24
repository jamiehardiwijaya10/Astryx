#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../utils/player.cpp"
#include "../utils/helper.cpp"

using namespace std;

struct Character {
    string name;
    int maxhp; // ini max xp nya, jadi kalo heal ga bisa ngelebihin maxhp
    int hp; // ini buat current health
    int atk, def;

    bool canDefend;
    bool canDodge;

    int dodgechance;
    int defend = 0;
    int dodge = 0; 

    int buffAttack = 0;

    vector<Skill> skills;
    bool alive = true;
};

Character createCharacter(CharacterData &cd)
{
    Character c;
    c.name = cd.name;
    c.maxhp = getFinalHP(cd);
    c.hp = c.maxhp;
    c.atk = getFinalATK(cd);
    c.def = getFinalDEF(cd);
    c.canDefend = true;
    c.canDodge = false;
    c.dodgechance = 0;
    c.alive = true;

    return c;
}

// Update : Jadinya calc damage disatuin biar enak kedepannya
int applyDamage(Character &attacker, Character &target, int rawDamage) {
    if (target.dodge) {
        if (rand() % 100 < target.dodgechance) {
            cout << target.name << " successfully dodged the attack!\n";
            
            return 0;
        } else {
            cout << target.name << " tried to dodge but failed!\n";
        }
    }

    int damage = rawDamage - target.def;

    if (target.defend) {
        damage *= 0.5;
    }

    if (damage < 1) {
        damage = 1;
    }

    target.hp -= damage;

    if (target.hp <= 0) {
        target.hp = 0;
        target.alive = false;
    }

    return damage;
}

// Function buat action attack (damage calc etc)
void attack(Character &attacker, Character &target) {
    int raw = attacker.atk + attacker.buffAttack;
    int damage = applyDamage(attacker, target, raw);

    if (damage > 0) {
        cout << attacker.name << " deals " << damage << " damage to " << target.name << endl;
    }

    if (target.hp <= 0) {
        cout << target.name << " is defeated!\n";
    }
}

// Buat action skill
bool useSkill(Character &user, vector<Character> &playerTeam, vector<Character> &enemyTeam) {
    if (user.skills.empty()) {
        cout << "No skill available!\n";
        return false;
    }
    
    bool validSkill = false;

    while (!validSkill) {
        cout << "\nChoose Skill : \n";
        setColor(RED_COLOR);
        cout << "0. Back\n";
        setColor(DEFAULT_COLOR);
        for (int i = 0; i < user.skills.size(); i++) {
            cout << i + 1 << ". " << user.skills[i].name;
            
            if (user.skills[i].currentCD > 0) {
                cout << " [CD : " << user.skills[i].currentCD << "]";
            } else {
                cout << " [READY]";
            }
            cout << endl;
        }

        cout << "Choice : ";
        int SkillChoice; cin >> SkillChoice;
        
        SkillChoice -= 1;

        // Return to action menu
        
        if (SkillChoice == -1) {
            system("cls");

            return false;
        }

        if (SkillChoice < 0 or SkillChoice >= user.skills.size()) {
            system("cls");

            cout << "Invalid Skill!\n";
            continue;
        }

        Skill &skill = user.skills[SkillChoice];

        if (skill.currentCD > 0) {
            system("cls");
            
            cout << "Skill on cooldown!\n";
            continue;
        }

        validSkill = true;

        cout << user.name << " uses " << skill.name << endl;

        // Dmg Skill
        if (skill.type == "damage") {
            int targetIndex;

            for (int i = 0; i < enemyTeam.size(); i++) {
                if (enemyTeam[i].alive) {
                    cout << i + 1 << ". " << enemyTeam[i].name;
                    setColor(RED_COLOR);
                    cout << " [HP : " << enemyTeam[i].hp << "]\n";
                    setColor(DEFAULT_COLOR);
                }
            }
            cout << "Choose target : ";
            if (!(cin >> targetIndex)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    } 
            targetIndex -= 1;

            system("cls");

            if (targetIndex >= 0 and targetIndex < enemyTeam.size() and enemyTeam[targetIndex].alive) {
                Character &enemy = enemyTeam[targetIndex];

                int damage = applyDamage(user, enemy, skill.power);

                if (damage > 0) {
                    cout << user.name << " uses " << skill.name << " and deals " << damage << " damage to " << enemy.name << endl;
                }
            }
        }

        // Aoe Skill
        else if (skill.type == "aoe") {
            for (auto &enemy : enemyTeam) {
                if (enemy.alive) {
                    int damage = applyDamage(user, enemy, skill.power);

                    if (damage > 0) {
                        cout << enemy.name << " takes " << damage << " damage\n";
                    }

                    if (enemy.hp <= 0) {
                        cout << enemy.name << " is defeated!\n";
                    }
                }
            }
        }

        // HEAL
        else if (skill.type == "heal") {
            int targetIndex; bool validTarget = false;

            while (!validTarget) {
                system("cls");
                cout << "\nChoose target to heal : \n";

                for (int i = 0; i < playerTeam.size(); i++) {
                    if (playerTeam[i].alive) {
                        cout << i + 1 << ". "; setColor(GREEN_COLOR);
                        cout << playerTeam[i].name << " [HP : " <<  playerTeam[i].hp << "/" << playerTeam[i].maxhp << "]";
                        setColor(DEFAULT_COLOR);

                        if (&playerTeam[i] == &user) {
                            printColor(" (SELF)", YELLOW_COLOR);
                        }

                        cout << endl;
                    }
                }

                cout << "Choice : "; 
                if (!(cin >> targetIndex)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }
                targetIndex -= 1;

                if (targetIndex >= 0 and targetIndex < playerTeam.size() and playerTeam[targetIndex].alive) {
                    Character &ally = playerTeam[targetIndex];

                    ally.hp += skill.power;
                    if (ally.hp > ally.maxhp) {
                        ally.hp = ally.maxhp;
                    }

                    setColor(GREEN_COLOR);
                    cout << ally.name; printColor(" healed for ", DEFAULT_COLOR); cout << skill.power << " HP!\n";

                    validTarget = true;
                } else {
                    cout << "Invalid target!\n";
                }
            }
        }
    
        // Buff Skill
        else if (skill.type == "buff") {
            int targetIndex; bool validTarget = false;

            while (!validTarget) {
                system("cls");
                cout << "\nChoose target to buff : \n";

                for (int i = 0; i < playerTeam.size(); i++) {
                    if (playerTeam[i].alive) {
                        cout << i + 1 << ". "; printColor(playerTeam[i].name, GREEN_COLOR); setColor(RED_COLOR);
                        cout << " [ATK : " << playerTeam[i].atk << "]"; setColor(DEFAULT_COLOR);

                        if (&playerTeam[i] == &user) {
                            printColor(" (SELF)", YELLOW_COLOR);
                        }

                        cout << endl;
                    }
                }
                cout << "\nChoose target : ";
                if (!(cin >> targetIndex)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }
                targetIndex -= 1;

                if (targetIndex >= 0 and targetIndex < playerTeam.size() and playerTeam[targetIndex].alive) {
                    Character &ally = playerTeam[targetIndex];

                    ally.buffAttack += skill.power;

                    printColor(ally.name, GREEN_COLOR); cout << " gains "; setColor(RED_COLOR);
                    cout << skill.power << " ATK!\n"; setColor(DEFAULT_COLOR);

                    validTarget = true;
                } else {
                    cout << "Invalid target!\n";
                }
            }
        }

        skill.currentCD = skill.cooldown;
        return true;
    }
    return false;
}   

// Function buat nyari targert random
Character& RandomTarget(vector<Character> &team) {
    vector<int> aliveIdx;

    for (int i = 0; i < team.size(); i++) {
        if (team[i].alive) aliveIdx.push_back(i);
    }

    if (aliveIdx.empty()) {
        throw runtime_error("No alive target!");
    }
    int r = rand() % aliveIdx.size();
    return team[aliveIdx[r]];
}

// Function buat cek team
bool teamAlive(vector<Character> &team) {
    for (auto &c : team) {
        if (c.alive) {
            return true;
        }   
    }
    return false;
}

// Buat action player
void playerTurn(vector<Character> &playerTeam, vector<Character> &enemyTeam) {
    for (auto &p : playerTeam) {
        if (!teamAlive(enemyTeam)) {
            cout << "\nAll enemies defeated!";

            Sleep(1000);
            system("cls");

            return;
        }
        
        if (!p.alive) {
            continue;
        }

        int choice; bool valid = false;

        while (!valid) {
            garis(29,'=');

            cout << "TURN : "; 
            
            setColor(YELLOW_COLOR);
            cout << p.name << endl;
            
            setColor(GREEN_COLOR);
            cout << "HP : "; setColor(10); 
            cout << p. hp << "/" << p.maxhp << endl;
            setColor(7);
            garis(29,'=');

            cout << "Enemies : \n";
            for (int i = 0; i < enemyTeam.size(); i++) {
                if (enemyTeam[i].alive) {
                    cout << i + 1 << ". ";
                    setColor(4);
                    cout << enemyTeam[i].name;
                    setColor(10);
                    cout << " [HP : " << enemyTeam[i].hp << "]\n";
                    setColor(7);
                }
            }
            garis(29,'-');
            
            cout << "Actions : \n";
            cout << "1. Attack\n";
            if (p.canDefend) {
                cout << "2. Defend\n";
            }
            if (p.canDodge) {
                cout << "3. Dodge\n";
            }
            if (!p.skills.empty()) {
                cout << "4. Skill\n";
            }

            garis(29, '-');

            cout << "Choose action : ";
            if (!(cin >> choice)) {
                cin.clear();
                cin.ignore(1000, '\n');
                continue;
            }

            if (choice == 1) {
                int targetIndex;
                
                for (int i = 0; i < enemyTeam.size(); i++) {
                    if (enemyTeam[i].alive) {
                        cout << i + 1 << ". ";
                        setColor(4);
                        cout << enemyTeam[i].name;
                        setColor(10);
                        cout << " [HP : " << enemyTeam[i].hp << "]\n";
                        setColor(7);
                    }
                }

                bool validTarget = false;
                while (!validTarget) {
                    cout << "Choose target : ";
                    if (!(cin >> targetIndex)) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        continue;
                    }
                    targetIndex -= 1;

                    if (targetIndex >= 0 and targetIndex < enemyTeam.size() and enemyTeam[targetIndex].alive) {
                        validTarget = true;
                    } else {
                        cout << "Invalid target. Try again!\n";
                    }
                }
                system("cls");
                
                attack(p, enemyTeam[targetIndex]);

                valid = true;
            }

            else if (choice == 2 and p.canDefend) {
                system("cls");
                p.defend = 1;
                
                cout << p.name << " is defending!\n";
                valid = true;
            }

            else if (choice == 3 and p.canDodge) {
                system("cls");
                p.dodge = 1;

                cout << p.name << " prepared to dodge\n";
                valid = true;
            }

            else if (choice == 4 and !p.skills.empty()) {
                system("cls");
                if (useSkill(p, playerTeam ,enemyTeam)) {
                    valid = true;
                }
            }

            else {
                cout << "Invalid action. Try again!\n";
            }
        }
    }
}

// Buat action musuh
void enemyTurn(vector<Character> &enemyTeam, vector<Character> &playerTeam) {
    for (auto &e : enemyTeam) {
        if (!e.alive) {
            continue;
        }

        cout << "\nEnemy "; printColor(e.name, RED_COLOR); cout << "'s turn\n";

        bool actionDone = false;

        // Enemy will atk lowest HP
        int target = -1;
        for (int i = 0; i < playerTeam.size(); i++) {
            if (playerTeam[i].alive) {
                if (target == -1 or playerTeam[i].hp < playerTeam[target].hp) {
                    target = i;
                }
            }
        }

        if (target == -1) continue;
        
        // Enemy will do defensive shi if low hp
        if (!actionDone and e.hp < e.maxhp * 0.3 ) {
            for (auto &skill : e.skills) {
                if (skill.type == "heal" and skill.currentCD == 0) {
                    printColor(e.name, RED_COLOR); cout << " uses " << skill.name << "!\n";

                    e.hp += skill.power;
                    if (e.hp > e.maxhp) {
                        e.hp = e.maxhp;
                    }

                    skill.currentCD = skill.cooldown;
                    actionDone = true;
                    break;
                }
            }

            if (!actionDone and e.canDefend) {
                e.defend = 1;
                printColor(e.name, RED_COLOR); cout << " is defending!\n";
                actionDone = true;
            }

            if (!actionDone and e.canDodge) {
                e.dodge = 1;
                printColor(e.name, RED_COLOR); cout << " prepares to dodge!\n";
                actionDone = true;
            }
        }

        // AOE Skill if many player
        if (!actionDone) {
            int aliveCount = 0;
            
            for (auto &p :playerTeam) {
                if (p.alive) {
                    aliveCount++;
                }
            }

            if (aliveCount >= 2) {
                for (auto &skill : e.skills) {
                    if (skill.type == "aoe" and skill.currentCD == 0) {
                        printColor(e.name, RED_COLOR); cout << " uses " << skill.name << "!\n";
                        
                        for (auto &p : playerTeam) {
                            if (!p.alive) {
                                continue;
                            }
                            
                            int damage = applyDamage(e, p, skill.power);

                            if (damage > 0) {
                                printColor(p.name, GREEN_COLOR); cout << " takes "; setColor(RED_COLOR);
                                cout << damage << " damage!\n"; setColor(DEFAULT_COLOR);
                            }

                            if (p.hp <= 0) {
                                cout << p.name << " is defeated!\n";
                            }
                        }
                        skill.currentCD = skill.cooldown;
                        actionDone = true;
                        break;
                    }
                    
                }
            }
        }

        // Damage Skill 
        if (!actionDone) {
            for (auto &skill : e.skills) {
                if (skill.type == "damage" and skill.currentCD == 0) {
                    if (rand() % 100 < 70) {
                        printColor(e.name, RED_COLOR); cout << " uses " << skill.name << "!\n";
                        
                        int damage = applyDamage(e, playerTeam[target], skill.power);

                        if (damage > 0) {
                            printColor(playerTeam[target].name, GREEN_COLOR); cout << " takes "; setColor(RED_COLOR);
                            cout << damage << " damage!\n"; setColor(DEFAULT_COLOR);
                        }

                        if (playerTeam[target].hp <= 0) {
                            cout << playerTeam[target].name << " is defeated!\n";
                        }

                        skill.currentCD = skill.cooldown;
                        actionDone = true;
                        break;
                    }
                }
            }
        }

        // Default action
        if (!actionDone and target != -1) {
            attack(e, playerTeam[target]);
        }
    }
}

void showTeam(vector<Character> &team, string label) {
    cout << "\n[" << label << "]\n";

    for (int i = 0; i < team.size(); i++) {
        cout << i + 1 << team[i].name << " | HP : " << team[i].hp << "/" << team[i].maxhp;
        
        if (!team[i].alive) {
            cout << "[DEAD]";
        } else {
            if (team[i].dodge) {
                cout << " [DODGE]";
            } else if (team[i].defend) {
                cout << " [DEF]";
            }
        }
        cout << endl;
    }
}

// Buat reset action per turn
void update(vector<Character> &team) {
    for (auto &c : team) {
        c.defend = 0;
        c.dodge = 0;
        c.buffAttack = 0;

        for (auto &s : c.skills) {
            if (s.currentCD > 0) {
                s.currentCD--;
            }
        }
    }
}

void actionselect() {
    cout << "Choose action:\n";
    return;
}

vector<Character> buildPlayerTeam(PlayerData &player) {
    vector<Character> team;

    for (string name : player.partyNames) {
        if (name == "") continue;

        for (auto &cd : player.ownedCharacters) {
            if (cd.name == name) {
                Character c = createCharacter(cd);

                c.skills = getCharacterSkills(cd);
                team.push_back(c);
                break;
            }
        }
    }

    return team;
}

int battle1(string username) {
    prepareBattle(username);

    system("cls");
    // Nama - MaxHp - Hp - Atk - Def - CanDefend - CanDodge - DodgeChance
    // Nama - Type - Power - Duration - CD

    srand(time(0));
    
    PlayerData player = loadPlayer(username);
    vector<Character> playerTeam;
    bool hasValid = false;
    for (auto &n : player.partyNames) {
        if (n != "") {
            hasValid = true;
            break;
        }
    }
    
    if (!hasValid) {
        cout << "Party kosong! Pilih karakter dulu.\n";
        return 0;
    }
    
    playerTeam = buildPlayerTeam(player);

    Character sickman = {"Sickman", 20, 20, 10, 5, false, false, 0};

    vector<Character> enemyTeam = {sickman, sickman};

    while (teamAlive(playerTeam) and teamAlive(enemyTeam)) {
        playerTurn(playerTeam, enemyTeam);
        enemyTurn(enemyTeam, playerTeam);

        update(playerTeam);
        update(enemyTeam);
    }

    if (teamAlive(playerTeam)) {
        setColor(YELLOW_COLOR);
        for (auto &name : player.partyNames) {
            for (auto &cd : player.ownedCharacters) {
                if (cd.name == name) {
                    addCharacterExp(cd, 50);
                    break;
                }
            }
        }
        savePlayer(player);
        cout << "Victory!\n";
    } else {
        setColor(RED_COLOR);
        cout << "Defeat...\n";
    }
    setColor(DEFAULT_COLOR);

    saveGame(1, 7);
    return 0;
}

int boss(string username) {
    prepareBattle(username);

    system("cls");

    srand(time(0));
    
    PlayerData player = loadPlayer(username);
    vector<Character> playerTeam;
    bool hasValid = false;
    for (auto &n : player.partyNames) {
        if (n != "") {
            hasValid = true;
            break;
        }
    }
    
    if (!hasValid) {
        cout << "Party kosong! Pilih karakter dulu.\n";
        return 0;
    }

    playerTeam = buildPlayerTeam(player);


    // Character Knight = {"Knight", 60, 60, 10, 5, false, true, 60};

//    Knight.skills.push_back({"Essence of Harmony", "heal", 25, 0, 3});


    Character Vessel = {"Vessel of The Deep", 140, 140, 15, 5, true, false, 0};

    Vessel.skills.push_back({"Tide of Rebirth", "heal", 25, 0, 3});
    Vessel.skills.push_back({"Crushing Depths", "damage", 20, 0, 4});
    Vessel.skills.push_back({"Drowning Cataclysm", "aoe", 30, 0, 6});


    vector<Character> enemyTeam = {Vessel};

    while (teamAlive(playerTeam) and teamAlive(enemyTeam)) {
        playerTurn(playerTeam, enemyTeam);
        enemyTurn(enemyTeam, playerTeam);

        update(playerTeam);
        update(enemyTeam);
    }

    if (teamAlive(playerTeam)) {
        setColor(YELLOW_COLOR);
        for (auto &name : player.partyNames) {
            for (auto &cd : player.ownedCharacters) {
                if (cd.name == name) {
                    addCharacterExp(cd, 50);
                    break;
                }
            }
        }
        savePlayer(player);
        cout << "Victory!\n";
    } else {
        setColor(RED_COLOR);
        cout << "Defeat...\n";
    }
    setColor(DEFAULT_COLOR);

    return 0;
}

vector<Character> generateEnemy(int floor, string area) {
    vector<Character> enemies;
    bool isBoss = (floor % 5 == 0);
    int jumlahMusuh;

    if (isBoss) {
        jumlahMusuh = 1;
    } else if (floor <= 5) {
        jumlahMusuh = 2;
    } else if (floor <= 15) {
        jumlahMusuh = 3;
    } else {
        jumlahMusuh = 4;
    }

    for (int i = 0; i < jumlahMusuh; i++) {
        Character musuh;
        int baseHP = 30 + (floor * 12);
        int baseATK = 6 + (floor * 7);
        int baseDEF = 3 + floor;
        musuh.canDefend = (floor >= 3);
        musuh.canDodge = (floor >= 6);

        if (area == "Masonwood") {
            musuh.name = "Konyian Soldiers " + to_string(i + 1);
        } else if (area == "Tetsumori Forest") {
            musuh.name = "Forest Oni " + to_string(i + 1);
            baseHP += 25;
            baseDEF += 5;
        } else if (area == "Collosseum") {
            musuh.name = "Arena Beastmaster " + to_string(i + 1);
            baseATK += 10;
        } else if (area == "Sacrificial Pit") {
            musuh.name = "Bone Prisoner " + to_string(i + 1);
            baseHP += 40;
            musuh.canDodge = true;
        } else if (area == "Gryphon Aviary"){
            musuh.name = "Feathered Raider " + to_string(i + 1);
            baseHP += 25;
            baseDEF += 5;
            baseATK += 10;
            musuh.canDodge;
        } else {
            musuh.name = "Unknown Enemy";
        }

        musuh.maxhp = baseHP;
        musuh.hp = musuh.maxhp;
        musuh.atk = baseATK;
        musuh.def = baseDEF;
        musuh.dodgechance = 10 + (floor * 2);

        if (musuh.dodgechance > 45) {
            musuh.dodgechance = 45;
        }
        musuh.alive = true;

        if (area == "Masonwood") {
            if (floor >= 6) {
                musuh.name = "Seaborn Luker " + to_string(i + 1);
                musuh.skills.push_back({"Brine Burst", "aoe", musuh.atk + floor * 2, 0, 2});
            }
            if (floor >= 10) {
                musuh.skills.push_back({"Hunter Rage", "aoe", 8 + floor, 0, 3});
            }
        } else if (area == "Tetsumori Forest") {
            if (floor >= 6) {
                musuh.name = "Crimson Geisha " + to_string(i + 1);
                musuh.skills.push_back({"Crimson Veil ", "buff", musuh.atk * 2 + floor, 1, 2});
            } else if (floor >= 11) {
                musuh.name = "Night Parade Monk " + to_string(i + 1);
                musuh.skills.push_back({"Soul Catcher", "buff", musuh.atk + floor * 2, 2, 3});
            } else if (floor >= 21){
                musuh.name = "Celestial Samurai " + to_string(i + 1);
                musuh.skills.push_back({"One Cursed Slash", "damage", musuh.atk * 2 + floor * 2, 0, 3});
            }
        } else if (area == "Collosseum") {
            if (floor >= 6) {
                musuh.name = "Aurelis Centurion " + to_string(i + 1);
                musuh.skills.push_back({"Golden Phalank", "buff", musuh.atk + floor, 2, 4});
            } else if (floor >= 11) {
                musuh.name = "Gargantuan Idol " + to_string(i + 1);
                musuh.skills.push_back({"Titan Crush", "aoe", musuh.atk * 2 + floor, 0, 2});
            } else if (floor >= 21){
                musuh.name = "Soulbound Senator " + to_string(i + 1);
                musuh.skills.push_back({"Echoes of Verdict", "damage", musuh.atk * 3 + floor, 0, 2});
            } else if (floor >= 26){
                musuh.name = "Bloodfang Gladiator " + to_string(i + 1);
                musuh.skills.push_back({"Execution Rush", "damage", musuh.atk * 2 + floor * 2, 0, 3});
            }
        } else if (area == "Sacrificial Pit") {
            if (floor >= 6) {
                musuh.name = "Bloodveil Necromancer " + to_string(i + 1);
                musuh.skills.push_back({"Soul Extraction", "heal", musuh.hp + floor * 2, 0, 2});
            } else if (floor >= 11) {
                musuh.name = "Abyssal Torturer " + to_string(i + 1);
                musuh.skills.push_back({"Chain of Agony", "aoe", musuh.atk * 2 + floor, 0, 3});
            } else if (floor >= 21){
                musuh.name = "Frostborn Warden " + to_string(i + 1);
                musuh.skills.push_back({"Frozen Bastion", "buff", musuh.atk + floor * 2, 2, 3});
            } else if (floor >= 26){
                musuh.name = "Damned High Priest " + to_string(i + 1);
                musuh.skills.push_back({"Ritual of Ruin", "aoe", musuh.atk * 2 + floor * 2, 0, 3});
            }
        } else if (area == "Gryphon Aviary"){
            if (floor >= 6) {
                musuh.name = "High Sanctifier " + to_string(i + 1);
                musuh.skills.push_back({"Holy Decree", "buff", musuh.atk * 2 + floor, 2, 4});
            } else if (floor >= 11) {
                musuh.name = "Royal Executioner " + to_string(i + 1);
                musuh.skills.push_back({"Kingbreaker Axe", "damage", musuh.atk * 3 + floor * 2, 0, 3});
            } else if (floor >= 21){
                musuh.name = "Arcane Falcon Master " + to_string(i + 1);
                musuh.skills.push_back({"Sky Dominion", "aoe", musuh.atk + floor * 2, 0, 2});
            } else if (floor >= 26){
                musuh.name = "Grand Sentinel " + to_string(i + 1);
                musuh.skills.push_back({"Iron Bastion", "buff", musuh.atk * 2 + floor * 2, 2, 2});
            }
        }

        if (isBoss && i == 0) {
            if (area == "Masonwood") {
                musuh.name = "VESSEL OF THE DEEP";
                musuh.skills.push_back({"Abyssal Life", "heal", 35 + floor, 0, 2});
                musuh.skills.push_back({"Abyssal Attack", "damage", musuh.atk + floor * 2, 0, 3});
                musuh.skills.push_back({"Abyssal Cataclysm", "damage", (musuh.atk + floor) * 3, 0, 4});
            } else if (area == "Tetsumori Forest") {
                if(floor % 2 == 0){
                    musuh.name = "FALLEN AVATAR OF AMATERASU";
                    musuh.skills.push_back({"Solar Judgement", "damage", (musuh.atk + floor) * 2, 0, 2});
                    musuh.skills.push_back({"Eclipse Blessing", "heal", musuh.hp + floor * 4, 0, 3});
                    musuh.skills.push_back({"Divine Eclipse", "aoe", (musuh.atk + floor) * 2, 0, 4});
                } else {
                    musuh.name = "SHOGUN OF HOLLOW LANTERNS";
                    musuh.skills.push_back({"Lantern Slash", "damage", musuh.atk * 2 + floor, 0, 2});
                    musuh.skills.push_back({"Parade of the Lost", "buff", musuh.atk + floor, 0, 3});
                    musuh.skills.push_back({"Hollow Lantern Catastrophe", "aoe", musuh.atk + floor * 2, 0, 4});
                }
            } else if (area == "Collosseum") {
                if(floor % 2 == 0){
                    musuh.name = "EMPEROR OF ETERNAL MARBLE";
                    musuh.skills.push_back({"Imperial Ruptune", "damage", (musuh.atk + floor) * 2, 0, 2});
                    musuh.skills.push_back({"Decree Of Olympus", "buff", musuh.atk + floor, 0, 3});
                    musuh.skills.push_back({"Thronebreaker Cataclysm", "aoe", musuh.atk + floor * 2, 0, 4});
                } else {
                    musuh.name = "THE GARGOYLE PRIMARCH";
                    musuh.skills.push_back({"Petrifying Claw", "damage", musuh.atk + floor * 2, 0, 2});
                    musuh.skills.push_back({"Stoneheart Regeneration", "heal", (musuh.hp + floor) * 2, 0, 3});
                    musuh.skills.push_back({"Wings of Ruin", "aoe", (musuh.atk + floor) * 2, 0, 4});
                }
            } else if (area == "Sacrificial Pit") {
                musuh.name = "THE LICH KING";
                musuh.skills.push_back({"Frostmourne Cleave", "damage", (musuh.atk + floor) * 3, 0, 2});
                musuh.skills.push_back({"Army of the Damned", "buff", musuh.atk + floor * 2, 0, 3});
                musuh.skills.push_back({"Eternal Winter Apocalypse", "aoe", (musuh.atk + floor) * 3, 0, 4});
            } else if (area == "Gryphon Aviary"){
                if(floor % 4 == 0){
                    musuh.name = "CROWNED GRYPHON EMPEROR";
                    musuh.skills.push_back({"Talon of Dominion", "damage", (musuh.atk + floor) * 2, 0, 2});
                    musuh.skills.push_back({"Imperial Roar", "buff", musuh.atk * 2 + floor, 0, 3});
                    musuh.skills.push_back({"Skyfall Coronation", "aoe", musuh.atk + floor * 2, 0, 4});
                } else if(floor % 4 == 1) {
                    musuh.name = "SAINTESS OF THE ETERNAL SANCTUM";
                    musuh.skills.push_back({"Sacred Chain", "damage", musuh.atk + floor, 0, 2});
                    musuh.skills.push_back({"Blessing of Eternity", "heal", (musuh.hp + floor) * 6, 0, 3});
                    musuh.skills.push_back({"Heavenly Revelation", "aoe", musuh.atk * 2 + floor, 0, 4});
                } else if(floor % 4 == 2) {
                    musuh.name = "KING OF THE CRIMSON THRONE";
                    musuh.skills.push_back({"Crimson Edge", "damage", (musuh.atk + floor) * 2, 0, 2});
                    musuh.skills.push_back({"Tyrant's Command", "buff", musuh.atk + floor * 2, 0, 3});
                    musuh.skills.push_back({"Thronebreaker Cataclysm", "aoe", (musuh.atk + floor) * 2, 0, 4});
                } else if(floor == 30){
                    musuh.name = "SOVEREIGN OF THE SCOURGE";
                }
            }

            musuh.maxhp *= 2;
            musuh.hp = musuh.maxhp;
            musuh.atk += 15;
            musuh.def += 8;
            musuh.dodgechance += 15;

            if (musuh.dodgechance > 60) {
                musuh.dodgechance = 60;
            }
        }
        enemies.push_back(musuh);
    }
    return enemies;
}

int battleDungeon(int floor, string username, string area) {
    system("cls");
    cout << "\n=== " << area << " FLOOR " << floor << " ===\n";
    PlayerData player = loadPlayer(username);
    vector<Character> playerTeam;
    bool hasValid = false;
    for (auto &n : player.partyNames) {
        if (n != "") {
            hasValid = true;
            break;
        }
    }
    if (!hasValid) {
        cout << "Party kosong! Pilih karakter dulu.\n";
        return 0;
    }
    
    playerTeam = buildPlayerTeam(player);
    vector<Character> enemyTeam = generateEnemy(floor, area);
    bool isBoss = (floor % 5 == 0);

    if (isBoss) {
        if(area == "Masonwood"){
            string title = "ARITHA\n";
            string nama = " VESSEL OF THE DEEP HAS AWOKEN!";
    
            setColor(YELLOW_COLOR);
            for (char c : title) {
                cout << c << flush;
                Sleep(100);
            }
            setColor(RED_COLOR);
            for (char c : nama) {
                cout << c << flush;
                Sleep(100);
            }
            setColor(DEFAULT_COLOR);
    
            cout << endl;
        }
    }

    while (teamAlive(playerTeam) && teamAlive(enemyTeam)) {
        playerTurn(playerTeam, enemyTeam);

        if (!teamAlive(enemyTeam)) {
            break;
        }
        enemyTurn(enemyTeam, playerTeam);
        update(playerTeam);
        update(enemyTeam);
    }

    if (teamAlive(playerTeam)) {
        setColor(YELLOW_COLOR);
        for (auto &name : player.partyNames) {
            for (auto &cd : player.ownedCharacters) {
                if (cd.name == name) {
                    addCharacterExp(cd, 50);
                    break;
                }
            }
        }
        savePlayer(player);
        cout << "\nVictory!\n";
        if (isBoss) {
            cout << "\nCHECKPOINT TERBUKA!\n";
        }
        setColor(DEFAULT_COLOR);

        return 1;
    } else {
        setColor(RED_COLOR);
        cout << "\nDefeat...\n";
        setColor(DEFAULT_COLOR);
        return 0;
    }
}