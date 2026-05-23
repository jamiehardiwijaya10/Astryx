#include <iostream>
#include <string>
#include <windows.h>
#include "story/prologue.cpp"
using namespace std;

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

string newGame(){
  string nama;
  string cek;
  vector <string> check;

  //Validasi akun baru
  ifstream filecek("databases/player.txt");
  getline(filecek,cek);
  while (getline(filecek,cek))
  {
    check.push_back(cek);
  }
  bool ada = true;

  while (ada)
  {
    system("cls");
    cout << "Enter Username: ";
    getline(cin, nama);
    cout << endl;

    bool ditemukan = false;
    for (auto &anggota : check)
    {
      if (nama == anggota)
      {
        ditemukan = true;
        break;
      }
    }

    if (ditemukan)
    {
      cout << "Username has been used!\n";
      system("pause");
    }
    else
    {
      ada = false;
    }
  }
  
  //Tamvbah ke resources
  ofstream file("databases/playerresources.txt", ios::app); //appendlibel
  if (!file.is_open())
  {
    cout << "File not found" << endl;
  }
  file << nama << " " << "100 100 100 10 1" << endl;
  file.close();

  //Tamcbah ke buildings
  ofstream file2("databases/building.txt", ios::app);
  if (!file2.is_open())
  {
    cout << "File not found";
  }
  file2 << nama  << ",Ariolla Monument,1,5,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land"<< endl;
  file2 << nama  << ",Village Of Purification,1,4,Lumberyard,Stone Quarry,Scrap Reclamation Center,Empty Land"<< endl;
  file2 << nama  << ",Masonwood,0,0"<< endl;
  file2 << nama  << ",Rovenilla,0,10,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land"<< endl;
  file2 << nama  << ",Moncini Basin,0,3,Empty Land,Empty Land,Empty Land"<< endl;
  file2.close();

  ofstream file3("databases/player.txt", ios::app);
  if (!file3.is_open())
  {
    cout << "File not found";
  }
  file3 << nama << endl;
  file3.close();

  PlayerData p{};
  p.name = nama;
  p.syringe = 0;
  p.powder = 0;
  p.partyNames = vector<string>(3, "");

  vector<CharacterData> db = loadCharacterDB();

  for (auto &c : db) {
      if (c.name == "Elias") {
          CharacterData starter = c;
          starter.exp = 0;
          starter.skillLevels = vector<int>(starter.skillsName.size(), 1);

          p.ownedCharacters.push_back(starter);
          p.partyNames[0] = "Elias";
          break;
      }
  }

  savePlayer(p);
  savePlayerCharacters(p);

  return nama;
}

string menusepsepan(){
  vector<string> nama;
  ifstream file("databases/player.txt");
  string line;
  int logs;

  getline(file, line);
  while (getline(file, line)) {
    if (!line.empty())
      nama.push_back(line);
  }
  file.close();

  while (true)
  {
    system("cls");
    garis(30);
    cout << "          MORIVELLE           \n";
    garis(30);
    cout << "1. New Game\n2. Load\n0. Exit\n";
    garis(30);
    cout << "Choose: "; cin >> logs;

    if (cin.fail()) {
      cin.clear();
      cin.ignore();
      continue;
    }

    if (logs == 1)
    {
      cin.ignore();
      string username = newGame();

      // langsung mulai story
      saveGame(1,1);
      prologue();
      chap1(1, username);

      return username;
    }

    else if (logs == 2)
    {
      while (true)
      {
        system("cls");
        garis(30);
        cout << "|          Load Game         |" <<endl;
        garis(30);

        for (int i = 0; i < nama.size(); i++)
        {
          cout << i+1 << ". " << nama[i] << endl;
        }

        cout << "0. Back\n";
        cout << "\nChoose index: ";

        int pilihanUser;
        cin >> pilihanUser;

        if (cin.fail()) {
          cin.clear();
          cin.ignore();
          continue;
        }

        if (pilihanUser == 0) break;

        if (pilihanUser >= 1 && pilihanUser <= nama.size())
        {
          string username = nama[pilihanUser-1];

          loadGame();

          if (save.chapter == 1) {
            chap1(save.scene, username);
          }

          return username;
        }
      }
    }

    // EXIT
    else if (logs == 0)
    {
      exit(0);
    }
  }
}