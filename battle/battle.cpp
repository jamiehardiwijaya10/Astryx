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
bool useSkill(Character &user, vector<Character> &enemyTeam) {
    if (user.skills.empty()) {
        cout << "No skill available!\n";
        return false;
    }
    
    bool validSkill = false;

    while (!validSkill) {
        cout << "\nChoose Skill : \n";
        setColor(4);
        cout << "0. Back\n";
        setColor(7);
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
            user.hp += skill.power;
            if (user.hp > user.maxhp) {
                user.hp = user.maxhp;
            }

            cout << user.name << " heals " << skill.power << " HP\n";
        }

        // Buff Skill
        else if (skill.type == "buff") {
            user.buffAttack += skill.power;

            cout << user.name << " gains +" << skill.power << " attack this turn!\n";
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
        if (!p.alive) {
            continue;
        }

        int choice; bool valid = false;

        while (!valid) {
            garis(29,'=');

            cout << "TURN : "; 
            setColor(6); 
            cout << p.name << endl;
            setColor(7);
            
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
                if (useSkill(p, enemyTeam)) {
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

        cout << "\nEnemy " << e.name << "'s turn\n";

        int r = rand() % 100;

        if (!e.skills.empty() and r > 80) {
            useSkill(e, playerTeam);
        }

        else if (e.canDodge and r > 50) {
            e.dodge = 1;
            cout << e.name << " prepared to dodge!\n"; 
        }

        else if (e.canDefend and r > 30) {
            e.defend = 1;
            cout << e.name << " is defending!\n";
        }

        else {
            Character &target = RandomTarget(playerTeam);
            attack(e, target);
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

int battle1() {
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
        setColor(6);
        cout << "\nVictory!\n";
    } else {
        setColor(4);
        cout << "\nDefeat...\n";
    }
    setColor(7);

    return 0;
}