#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <windows.h>
#include "story/prologue.cpp"
using namespace std;

#define RESET   "\033[0m"
#define CYAN    "\033[36m"

struct SaveData {
  string username;
  int chapter;
  int scene;
};

string newGame(){
  string nama;
  string cek;
  vector <string> check;

  //Validasi akun baru
  ifstream filecek("databases/player.txt");
  if(filecek.is_open()){
    getline(filecek,cek);
    while (getline(filecek,cek)){
      stringstream baca(cek);
      string daftarUser;
      baca >> daftarUser;
      if(!daftarUser.empty()){
        check.push_back(daftarUser);
      }
    }
    filecek.close();
  }

  bool ada = true;
  while (ada)
  {
    system("cls");
    cout << "Enter Username: ";
    getline(cin, nama);
    cout << endl;

    if(nama.find(' ') != string::npos || nama.empty()){
      cout << "username cannot be empty or contain spaces!\n";
      system("pause");
      continue;
    }

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
  file << nama << " " << 100 << " " << 100 << " " << 100 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " "  << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 0 << " " << 10 << " " << 1

  << endl;
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
  file3 << nama << " 1 1" << endl;
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

void menusepsepan(){
  int logs;
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
      prologue();
      chap1(1, username);

      return;
    }

    else if (logs == 2)
    {
      while (true)
      {
        system("cls");
        garis(30);
        cout << "|          Load Game         |" <<endl;
        garis(30);

        ifstream  file1("databases/player.txt");
        vector<SaveData>daftarAkun;
        string baris;

        if (file1.is_open()) {
          getline(file1,baris);
          while(getline(file1,baris)){
            stringstream baca(baris);
            SaveData akun;
            if (baca >> akun.username >> akun.chapter >> akun.scene){
              daftarAkun.push_back(akun);
            }
          }
          file1.close();
        }

        if(daftarAkun.empty()){
          cout << "No data saved, please create new game"<<endl;
        }
        else{
          for (int i = 0; i < daftarAkun.size(); i++){
            cout << i+1 << ". " << daftarAkun[i].username 
                        << " (Chapter " << daftarAkun[i].chapter 
                        << " - Scene " << daftarAkun[i].scene << ")" <<endl;
          }
        }

        cout << "0. Back\n";
        garis(30);
        cout << "Choose account: ";

        int pilihanUser;
        cin >> pilihanUser;

        if (cin.fail()) {
          cin.clear();
          cin.ignore();
          continue;
        }

        if (pilihanUser == 0) break;

        if (pilihanUser >= 1 && pilihanUser <= daftarAkun.size())
        {
          SaveData akunDipilih = daftarAkun[pilihanUser-1];
          cin.ignore();

          cout << "\nLoading Game as " << akunDipilih.username <<"..."<<endl;
          Sleep(1000);

          chap1(akunDipilih.scene, akunDipilih.username);
          return;
          }
        else{
          cout << "Invalid choice" <<endl;
          system("pause");
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