
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>
#include <stdlib.h>
using namespace std;

const int kapasitas = 6;
struct player {
    string nama;
    int hp = 3;

    int heal = 0;
    int doubledmg = 0;
    int check = 0;

    bool buff = false;
};

player pemain;
player musuh;

vector<int> revolver;
void garis(int x) {
    for(int i=0;i<x;i++) {
        cout << "=";
    }
    cout << endl;
}

void reloadRevolver() {
    revolver.clear();
    int live = rand() % 4 + 2;
    int blank = kapasitas - live;

    for (int i = 0; i < live; i++) {
        revolver.push_back(1);
    }
    for (int i = 0; i < blank; i++) {
        revolver.push_back(0);
    }

    random_shuffle(revolver.begin(),revolver.end());
}

void randomItem(player &p) {
    for (int i = 0; i < 3; i++) {
        int x = rand()%3;

        if(x == 0) {
            p.heal++;
        } else if(x == 1) {
            p.doubledmg++;
        } else {
            p.check++;
        }
    }
}

void status() {
    system("cls");
    garis(35);
    cout << "      RUSSIAN ROULETTE\n";
    garis(35);

    cout << "Player HP : " << pemain.hp << endl;
    cout << "Enemy  HP : " << musuh.hp << endl;
    cout << "Bullets Left : " << revolver.size() << endl;
    garis(35);
}

void statusInventory() {
    system("CLS");
    garis(35);
    cout << "Inventory\n";
    cout << "Black Cigarette  : " << pemain.heal << endl;
    cout << "Shadow Knife     : " << pemain.doubledmg << endl;
    cout << "Eye of Chuthulu  : " << pemain.check << endl;
    garis(35);
}

void useItem() {
    int pilih;
    cout << "1. Black Cigarette\n";
    cout << "2. Shadow Knife\n";
    cout << "3. Eye of Chuthulu\n";
    cout << "0. Back\n";
    cout << "Choose : ";
    cin >> pilih;

    if(pilih == 0){
        return;
    }
    if(pilih == 1) {
        if(pemain.heal <= 0) {
            cout << "No item\n";
        } else {
            pemain.heal--;
            if(pemain.hp < 3) {
                pemain.hp++;
            }
            cout << "You healed 1 HP\n";
        }
    } else if(pilih == 2) {
        if(pemain.doubledmg <= 0) {
            cout << "No item\n";
        } else {
            pemain.doubledmg--;
            pemain.buff = true;
            cout << "Double Damage Activated\n";
        }
    } else if(pilih == 3) {
        if(pemain.check <= 0) {
            cout << "No item\n";
        } else {
            pemain.check--;
            if(revolver[0] == 1)
            {
                cout << "Next Bullet : LIVE\n";
            }
            else {
                cout << "Next Bullet : BLANK\n";
            }
        }
    }
    system("pause");
}

void damagePlayer() {
    int dmg = 1;
    if(musuh.buff == true)
    {
        dmg = 2;
        musuh.buff = false;
    }

    pemain.hp -= dmg;
}

void damageEnemy()
{
    int dmg = 1;
    if(pemain.buff == true)
    {
        dmg = 2;
        pemain.buff = false;
    }
    musuh.hp -= dmg;
}

void playerTurn() {
    while(true) {
        status();
        cout << "1. Shoot Yourself\n";
        cout << "2. Shoot Enemy\n";
        cout << "3. Use Item\n";
        cout << "Choose : ";
        int pilih; cin >> pilih;

        if(pilih == 3) {
            statusInventory();
            useItem();
            continue;
        }
        int bullet = revolver.front();
        revolver.erase(revolver.begin());

        if(pilih == 1) {
            if(bullet == 1) {
                cout << "\nBANG!!\n";
                damagePlayer();
                system("pause");
                cout << endl;
                break;
            } else {
                cout << "\nCLICK!! Blank Bullet\n";
                system("pause");
                if(revolver.empty())
                {
                    reloadRevolver();
                }
                continue;
            }
        }

        if(pilih == 2) {
            if(bullet == 1) {
                cout << "\nBANG!! Enemy got hit\n";
                damageEnemy();
            } else {
                cout << "\nCLICK!! Blank Bullet\n";
            }
            system("pause");
            cout << endl;
            break;
        }
    }
}

void enemyTurn() {
    if(musuh.hp <= 1 && musuh.heal > 0) {
        musuh.heal--;
        musuh.hp++;
        if(musuh.hp > 3) {
            musuh.hp = 3;
        }
        cout << "Enemy used Heal\n";
        system("pause");
        return;
    }
    int target = rand()%2;
    int bullet = revolver.front();
    revolver.erase(revolver.begin());

    if(target == 0) {
        cout << "Enemy shoots you\n";
        if(bullet == 1)
        {
            cout << "BANG!!\n";
            damagePlayer();
        }
        else
        {
            cout << "CLICK!!\n";
        }
    } else {
        cout << "Enemy shoots itself\n";
        if(bullet == 1) {
            cout << "BANG!!\n";
            damageEnemy();
        } else {
            cout << "CLICK!!\n";
        }
    }
    system("pause");
}

int rr() {
    srand(time(0));
    pemain.nama = "Elias";
    musuh.nama = "Toten'Arak";
    randomItem(pemain);
    randomItem(musuh);
    reloadRevolver();

    int round = 1;
    while(true) {
        if(revolver.empty()) {
            reloadRevolver();
        }
        if(round % 5 == 0) {
            randomItem(pemain);
            randomItem(musuh);
            cout << "Supply Drop!\n";
            cout << "Both players got 3 random items\n";
            system("pause");
        }
        playerTurn();
        if(musuh.hp <= 0) {
            system("cls");
            cout << "YOU WIN\n";
            break;
        }
        if(revolver.empty())
        {
            reloadRevolver();
        }
        enemyTurn();
        if(pemain.hp <= 0) {
            system("cls");
            cout << "YOU LOSE\n";
            break;
        }
        round++;
    }

    return 0;
}
