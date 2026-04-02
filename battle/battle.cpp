#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

enum ActionChoice {
    ATTACK = 1,
    DEFEND,
    DODGE,
    SKILL
};

struct Character {
    string name;
    int maxhp; // ini max xp nya, jadi kalo heal ga bisa ngelebihin maxhp
    int hp; // ini buat current health
    int atk, def;

    bool canDefend;
    bool canDodge;

    int dodge;
    int defend; 
    int dodgechance;

    vector<Skill> skills;
    int cdRemains = 0;

    bool alive = true;
};

struct Skill {
    string name;
    string type;
    int power;
    int duration;
    int cooldown;
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
    int damage = attacker.atk - target.def;

    if (target.defend) {
        damage /= 2;
    }

    if (damage < 1) {
        damage = 1;
    }

    target.hp -= damage;
    cout << attacker.name << " deals " << damage << " to " << target.name << endl;

    if (target.hp <= 0) {
        target.hp = 0;
        target.alive = false;
        cout << target.name << " is defeated";
    }
}

// Function buat nyari targer random
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
        return false;
    }
}

// Buat action player
void playerTurn(vector<Character> &playerTeam, vector<Character> &enemyTeam) {
    for (auto &p : playerTeam) {
        if (!p.alive) {
            continue;
        }

        cout << "\n" << p.name << " HP : " << p.hp << endl;

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

        int choice; cin >> choice;

        switch (choice) {
            case ATTACK: {
                int targetIndex;
                cout << "Choose target : \n";

                for (int i = 0; i < enemyTeam.size(); i++) {
                    if (enemyTeam[i].alive) {
                        cout << i << enemyTeam[i].name << " HP : " << enemyTeam[i].hp << endl;
                    }
                }
                cin >> targetIndex;
                attack(p, enemyTeam[targetIndex]);
                break;
            }

            case DEFEND: {
                if (p.canDefend) {
                    p.defend = 1;
                    cout << p.name << " is defending!\n";
                }
                break;
            }

            case DODGE: {
                if (p.canDodge) {
                    p.dodge = 1;
                    cout << p.name << " prepared to dodge\n";
                }
                break;
            }

            case SKILL: {
                
            }
        }
    }
}

void actionselect() {
    cout << "Choose action:\n";
    return;
}