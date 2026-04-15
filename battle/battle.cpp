#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "../utils/helper.cpp"

using namespace std;

struct Skill {
    string name;
    string type; // For now baru : damage, aoe, heal, buff (might add more idk)
    int power;
    int duration;
    int cooldown;

    int currentCD = 0;
};

struct Character {
    string name;
    int maxhp; // ini max xp nya, jadi kalo heal ga bisa ngelebihin maxhp
    int hp; // ini buat current health
    int atk, def;

    bool canDefend;
    bool canDodge;

    int defend = 0;
    int dodge = 0; 
    int dodgechance;

    int buffAttack = 0;

    vector<Skill> skills;
    bool alive = true;
};

// Function buat action attack (damage calc etc)
void attack(Character &attacker, Character &target) {
    if (target.dodge) {
        int roll = rand() % 100;
        if (roll < target.dodgechance) {
            cout << target.name << " successfully dodged the attack!\n";
            return;
        } else {
            cout << target.name << " tried to dodge but failed!\n";
        }
    }

    // Buat damage calculationz
    int totalAttack = attacker.atk + attacker.buffAttack;

    int damage = totalAttack - target.def;

    if (target.defend) {
        damage /= 2;
    }

    if (damage < 1) {
        damage = 1;
    }

    target.hp -= damage;
    cout << attacker.name << " deals " << damage << " damage to " << target.name << endl;

    if (target.hp <= 0) {
        target.hp = 0;
        target.alive = false;
        cout << target.name << " is defeated\n";
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
                    setColor(10);
                    cout << " [HP : " << enemyTeam[i].hp << "]\n";
                    setColor(7);
                }
            }
            cout << "Choose target : ";
            cin >> targetIndex; targetIndex -= 1;

            system("cls");

            if (targetIndex >= 0 and targetIndex < enemyTeam.size() and enemyTeam[targetIndex].alive) {
                Character &enemy = enemyTeam[targetIndex];

                int damage = skill.power - enemy.def;
                
                if (enemy.dodge) {
                    if (rand() % 100 < enemy.dodgechance) {
                        cout << enemy.name << " dodged the skill!\n";
                        return true;
                    }
                }

                if (enemy.defend) {
                    damage /= 2;
                }

                if (damage < 1) {
                    damage = 1;
                }

                enemy.hp -= damage;

                cout << user.name << " uses " << skill.name << " and deals " << damage << " damage to " << enemy.name << endl;

                if (enemy.hp <= 0) {
                    enemy.hp = 0;
                    enemy.alive = false;
                    cout << enemy.name << " is defeated!\n";
                }
            }
        }

        // Aoe Skill
        else if (skill.type == "aoe") {
            for (auto &enemy : enemyTeam) {
                if (enemy.alive) {
                    enemy.hp -= skill.power;

                    cout << enemy.name << " takes " << skill.power << " damage\n";

                    if (enemy.hp <= 0) {
                        enemy.hp = 0;
                        enemy.alive = false;

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

                cout << "Choice : "; cin >> targetIndex;
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
                cout << "\nChoose target : "; cin >> targetIndex;
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
}   

// Function buat nyari targert random
Character& RandomTarget(vector<Character> &team) {
    while (true) {
        int i = rand() % team.size();
        if (team[i].alive) {
            return team[i];
        }
    }
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

            cout << "Choose action : "; cin >> choice;

            if (choice == 1) {
                int targetIndex; bool validTarget = false;
                
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

                while (!validTarget) {
                    cout << "Choose target : ";
                    cin >> targetIndex;
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
                        printColor(e.name, RED_COLOR); cout << "uses " << skill.name << "!\n";

                        for (auto &p : playerTeam) {
                            if (!p.alive) {
                                continue;
                            }

                            p.hp -= skill.power;

                            printColor(p.name, GREEN_COLOR); cout << " takes "; setColor(RED_COLOR);
                            cout << skill.power << " damage!\n"; setColor(DEFAULT_COLOR);

                            if (p.hp <= 0) {
                                p.hp = 0;
                                p.alive = false;
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

                        int damage = skill.power - playerTeam[target].def;
                        if (damage < 1) {
                            damage = 1;
                        }

                        playerTeam[target].hp -= damage;

                        printColor(playerTeam[target].name, GREEN_COLOR); cout << " takes "; setColor(RED_COLOR);
                        cout << damage << " damage!\n"; setColor(DEFAULT_COLOR);

                        if (playerTeam[target].hp <= 0) {
                            playerTeam[target].hp = 0;
                            playerTeam[target].alive = false;
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

int main() {
    system("cls");
    // Nama - MaxHp - Hp - Atk - Def - CanDefend - CanDodge - DodgeChance
    // Nama - Type - Power - Duration - CD

    srand(time(0));

    Character Elias = {"Elias Viremont", 50, 50, 10, 5, true, false, 0};

    Elias.skills.push_back({"Ballscracker", "damage", 20, 2, 2});

    vector<Character> playerTeam = {Elias};

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
        cout << "Victory!\n";
    } else {
        setColor(RED_COLOR);
        cout << "Defeat...\n";
    }
    setColor(DEFAULT_COLOR);

    return 0;
}