#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
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
        cout << target.name << " is defeated";
    }
}

// Buat action skill
void useSkill(Character &user, vector<Character> &enemyTeam) {
    if (user.skills.empty()) {
        cout << "No skill available!\n";
        return;
    }

    cout << "\nChoose Skill : \n";
    for (int i = 0; i < user.skills.size(); i++) {
        cout << i + 1 << ". " << user.skills[i].name;
        
        if (user.skills[i].currentCD > 0) {
            cout << " (CD : " << user.skills[i].currentCD << ")";
        }
        cout << endl;
    }
    
    cout << "Choice : ";
    int SkillChoice; cin >> SkillChoice;
    SkillChoice -= 1;

    if (SkillChoice < 0 or SkillChoice >= user.skills.size()) {
        cout << "Invalid Skill!\n";
        return;
    }

    Skill &skill = user.skills[SkillChoice];

    if (skill.currentCD > 0) {
        cout << "Skill on cooldown!\n";
        return;
    }

    cout << user.name << " uses " << skill.name << endl;

    // Dmg Skill
    if (skill.type == "damage") {
        int targetIndex;

        cout << "Choose target : \n";

        for (int i = 0; i < enemyTeam.size(); i++) {
            if (enemyTeam[i].alive) {
                cout << i << enemyTeam[i].name << " HP : " << enemyTeam[i].hp << endl;
            }
        }
        cin >> targetIndex;

        attack(user, enemyTeam[targetIndex]);
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
        return false;
    }
}

// Buat action player
void playerTurn(vector<Character> &playerTeam, vector<Character> &enemyTeam) {
    for (auto &p : playerTeam) {
        if (!p.alive) {
            continue;
        }

        garis(29,'=');
        cout << "TURN : " << p.name << endl;
        cout << "HP : " << p. hp << "/" << p.maxhp << endl;
        garis(29,'-');

        cout << "Enemies : \n";
        for (int i = 0; i < enemyTeam.size(); i++) {
            if (enemyTeam[i].alive) {
                cout << i + 1 << ". " << enemyTeam[i].name << " (HP : " << enemyTeam[i].hp << ")\n";
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

        cout << "Choice : ";
        int choice; cin >> choice;

        if (choice == 1) {
            int targetIndex;

            cout << "Choose target : \n";

            for (int i = 0; i < enemyTeam.size(); i++) {
                if (enemyTeam[i].alive) {
                    cout << i + 1 << ". " << enemyTeam[i].name << " HP : " << enemyTeam[i].hp << endl;
                }
            }
            cin >> targetIndex;
            targetIndex -= 1;
            attack(p, enemyTeam[targetIndex]);
        }

        else if (choice == 2 and p.canDefend) {
            p.defend = 1;
            
            cout << p.name << " is defending!\n";
        }

        else if (choice == 3 and p.canDodge) {
            p.dodge = 1;

            cout << p.name << " prepared to dodge\n";
        }

        else if (choice == 4 and !p.skills.empty()) {
            useSkill(p, enemyTeam);
        }

        else {
            cout << "Invalid action!\n";
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
            cout << e.name << " is dodging!\n"; 
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
    // Nama - MaxHp - Hp - Atk - Def - CanDefend - CanDodge,

    srand(time(0));

    Character knight = {"Knight", 60, 60, 10, 6, true, false, 0};
    Character jawajawa = {"Jawa Man", 100, 100, 100, 100, true, true, 50};

    jawajawa.skills.push_back({"Jawa Blast", "aoe", 100, 2});
    jawajawa.skills.push_back({"Jawa Chants", "buff", 100, 2});

    vector<Character> playerTeam = {knight, jawajawa};

    Character lurker = {"Lurker", 60, 60, 10, 5, false, true, 30};
    Character Ligma = {"Ligma Monster", 60, 60, 5, false, true, 30};

    vector<Character> enemyTeam = {lurker, Ligma};

    while (teamAlive(playerTeam) and teamAlive(enemyTeam)) {
        playerTurn(playerTeam, enemyTeam);
        enemyTurn(enemyTeam, playerTeam);

        update(playerTeam);
        update(enemyTeam);
    }

    if (teamAlive(playerTeam)) {
        cout << "\nVictory!\n";
    } else {
        cout << "\nDefeat...\n";
    }

    return 0;
}