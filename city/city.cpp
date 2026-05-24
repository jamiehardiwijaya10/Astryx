#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "../battle/dungeon.cpp"
using namespace std;

struct SumberDaya
{
  string nama;
  int kayu;
  int batu;
  int scrap;
  int token;
  int turn;
};

struct Bangunan
{
  string nama;
  bool pakai;
  int bKayu;
  int bBatu;
  int bScrap;
  int pKayu;
  int pBatu;
  int pScrap;
};

struct Lahan
{
  string nama;
  int bKayu;
  int bBatu;
  int bScrap;
  int pKayu;
  int pBatu;
  int pScrap;
};

struct Area
{
  string nama;
  bool unlock;
  int kapasitas;
  int totalK;
  int totalB;
  int totalS;
  Lahan bangunan[10];
};Area daerah[5];

bool notifStory = false;
//PEKTOR as Bucketk
vector <SumberDaya> players;
void vanguardBarracks(PlayerData &p);
void academyMenu(PlayerData &p);

void garis(int ukuran){
  int pilihan = 0;
  pilihan += ukuran;
  cout << string(int(pilihan),'=') << endl;
  pilihan = 0;
}

void setProduksi(Lahan &l){
    if (l.nama == "Lumberyard"){
        l.pKayu = 10;
    }
    else if (l.nama == "Stone Quarry"){
        l.pBatu = 8;
    }
    else if (l.nama == "Scrap Reclamation Center"){
        l.pScrap = 6;
    }
    else if(l.nama == "Empty Land"){
        l.pKayu = l.pBatu = l.pScrap = 0;
    }
}

void membaca(string username){
  players.clear();
  ifstream file("../databases/playerresources.txt");
  string line;
  getline(file, line);
  while (getline(file, line)) 
  {
      stringstream baca1(line);
      SumberDaya p;
      baca1 >> p.nama >> p.kayu >> p.batu >> p.scrap >> p.token >> p.turn;
      players.push_back(p);
  }
  file.close();

  ifstream file2("../databases/building.txt");
  int i = 0;
  getline(file2, line);
  while (getline(file2, line)) {
        stringstream baca2(line);
        string name;
        string areaName;
        string unlockStatus;
        string kapasitasLahan;
        string namaLahan;

        getline(baca2, name, ',');
        getline(baca2, areaName, ',');
        getline(baca2, unlockStatus, ',');
        getline(baca2, kapasitasLahan, ',');

        if (name == username && i < 5){

            daerah[i].nama = areaName;
            daerah[i].unlock = (unlockStatus == "1");
            daerah[i].kapasitas = stoi(kapasitasLahan);

            for(int j=0; j<daerah[i].kapasitas; j++){
                if(j<daerah[i].kapasitas-1){
                  getline(baca2, namaLahan, ',');
                }
                else{
                  getline(baca2, namaLahan);
                }
                daerah[i].bangunan[j].nama = namaLahan;
                setProduksi(daerah[i].bangunan[j]);
            }
            i++;
          }
        }

  file2.close();
}

void PerhitunganSumberDaya(string username){
  for (auto &p : players){
    if(username == p.nama ){
      if (p.token > 0){
        int totalK = 0;
        int totalB = 0;
        int totalS = 0;
        
        for (int i=0; i<4; i++){
            totalK += daerah[1].bangunan[i].pKayu;
            totalB += daerah[1].bangunan[i].pBatu;
            totalS += daerah[1].bangunan[i].pScrap;
        }
        p.kayu += totalK;
        p.batu += totalB;
        p.scrap += totalS;
        p.turn++;
        p.token--;
        
        cout << "Token tersisa: " << p.token  << endl;
        cin.ignore();
        waitEnter();
      }

      else if (p.token == 0){
        cout << "Token habis!" << endl;
        cin.ignore();
        waitEnter();
      }
    }
  }
}

void updatePlayer(){

  ofstream tulis1("../databases/playerresources.txt");

  if (!tulis1.is_open())
  {
    cout << "File not found" << endl;
  }

  tulis1<<"nama kayu batu scrap token turn"<<endl;

  for (auto &p : players)
  {
    tulis1 << p.nama << " " << p.kayu << " " << p.batu << " " << p.scrap << " " << p.token << " " << p.turn <<endl;
  }

  tulis1.close();

  }

void updateBuilding(string username){
    vector<string>semuaData;
    string line;
    int i = 0;
    ifstream file2("../databases/building.txt");

    while (getline(file2, line))
    {
        stringstream baca2(line);
        string name;

        getline(baca2, name, ',');

        if (name != username && i < 5)
        {
          semuaData.push_back(line);
        }
    }
    file2.close();
    
    for (int i=0; i<5; i++){
        string baris;

        baris += username + ",";
        baris += daerah[i].nama + ",";
        baris += (daerah[i].unlock ? "1" : "0") + string(",");
        baris += to_string(daerah[i].kapasitas) + ",";

        for (int j=0; j<daerah[i].kapasitas; j++)
        {
            baris += daerah[i].bangunan[j].nama;
            if (j < daerah[i].kapasitas-1)
                baris += ",";
        }
        semuaData.push_back(baris);
    }
    ofstream tulis("../databases/building.txt");
    for (auto &data : semuaData){
        tulis << data << endl;
    }
  tulis.close();
}

void header(string username){
  for (auto &p : players)
  {
    if (p.nama == username)
    {
      cout << "[Token = " << p.token << "]                [" << "Turn ke-" << p.turn << "]"<< endl;
      garis(39);
      cout << "| Wood: "<< p.kayu << " | Stone: "<< p.batu << " | Scrap: "<< p.scrap <<" |"<<endl;
    }
  }
}

void statistikArea(int i){
    daerah[i].totalK = 0;
    daerah[i].totalB = 0;
    daerah[i].totalS = 0;
    for(int j = 0; j<daerah[i].kapasitas; j++){
        daerah[i].totalK += daerah[i].bangunan[j].pKayu;
        daerah[i].totalB += daerah[i].bangunan[j].pBatu;
        daerah[i].totalS += daerah[i].bangunan[j].pScrap;
        }
    
    cout<<"Statistik Area:"<<endl;
    cout<<"Wood  = "<< daerah[i].totalK <<"/Turn" <<endl;
    cout<<"Stone = "<< daerah[i].totalB <<"/Turn" <<endl;
    cout<<"Scrap = "<< daerah[i].totalS <<"/Turn" <<endl;
    garis (39);
}

void ariollaMonument(string username, int area,int nomorlahan){
  int pilih;
  garis(39);
  if(daerah[area].bangunan[nomorlahan].nama == "Ariolla Market")
  {
    while (true)
    {
          system("cls");
          header(username);
          cout << "|       "<< daerah[area].bangunan[nomorlahan].nama <<"      |" << endl;
          garis (39);
          cout<<"1. 50 Wood (2 token)"<<endl;
          cout<<"2. 40 Stone (2 token)"<<endl;
          cout<<"3. 30 Scrap (3 token)"<<endl;
          cout<<"0. Back"<<endl;
          garis (39);
          cout<<"What you want to buy: ";cin>>pilih;
          if (cin.fail())
          {
            cin.clear();
            cin.ignore();
            continue;
          }
          break;
        }
        
  
        for (auto &p : players){
          if (p.nama == username){
              if(pilih==1){
                cout<<"You have purchased wood"<<endl;
                p.token -= 2;
                p.kayu += 50;
              }
              else if(pilih==2){
                cout<<"You have purchased stone"<<endl;
                p.token -= 2;
                p.batu += 40;
              }
              else if(pilih==3){
                cout<<"You have purchased scrap"<<endl;
                p.token -= 3;
                p.scrap += 30;
              }
              else if(pilih==0){
                system("pause");
                return;
              }
              else
              {
                cout << "Invalid, Return to Ariolla Monument Lobby";
                system("pause");
                return;
              }
          }
        }
      }
      else if(daerah[area].bangunan[nomorlahan].nama == "Ariolla Clinic")
      {
        while (true)
        {
          cout << "|       "<< daerah[area].bangunan[nomorlahan].nama <<"      |" << endl;
          garis (39);
          cout<<"1. Medkit (5 token)"<<endl;
          cout<<"2. First aid (2 token)"<<endl;
          cout<<"3. Betadine (3 token)"<<endl;
          cout<<"0. Back"<<endl;
          garis (39);
          cout<<"What you want to buy: ";cin>>pilih;
          if (cin.fail())
          {
            cin.clear();
            cin.ignore();
            continue;
          }
          break;
        }
        
  
        for (auto &p : players){
          if (p.nama == username){
              if(pilih==1){
                cout<<"Kayu telah dibeli"<<endl;
                p.token -= 2;
                p.kayu += 50;
              }
              else if(pilih==2){
                cout<<"Batu telah dibeli"<<endl;
                p.token -= 2;
                p.batu += 40;
              }
              else if(pilih==3){
                cout<<"Scrap telah dibeli"<<endl;
                p.token -= 3;
                p.scrap += 30;
              }
              else if(pilih==0){
                system("pause");
                return;
              }
              else
              {
                cout << "Invalid, Return to Ariolla Monument Lobby";
                system("pause");
                return;
              }
          }
        }
      }
      else{return;}
    }

void villageOfPurification(string username, int area,int nomorlahan){
  int pilih;

       cout << "1. Lumberyard\n";
       cout << "2. Stone Quarry\n";
       cout << "3. Scrap Reclamation Center\n";
       cout << "0. Batal\n";
       cout << "Pilih : "; cin >> pilih;

       for (auto &p : players){
        if (p.nama == username){

          if (pilih == 1){

            if (daerah[area].bangunan[nomorlahan].nama == "Lumberyard")
            {
              cout << "Can't build the same buildings" << endl;
              system("pause");
            }
            else if( p.batu >= 30 && p.scrap >= 5)
            {
              daerah[area].bangunan[nomorlahan].nama = "Lumberyard";
              p.batu -= 30;
              p.scrap -= 5;
            }
            else
            {
              cout << "Not enough resourcess" << endl;
              system("pause");
            }
          }

          else if (pilih == 2){
            if (daerah[area].bangunan[nomorlahan].nama == "Stone Quarry")
            {
              cout << "Can't build the same buildings" << endl;
              system("pause");
            }
            else if(p.kayu >=20 && p.scrap >= 5)
            {
            daerah[area].bangunan[nomorlahan].nama = "Stone Quarry";
            p.kayu -= 20;
            p.scrap -= 5;
            }
            else
            {
              cout << "Not enough resources" << endl;
              system("pause");
            }
          }

          else if (pilih == 3){
            if (daerah[area].bangunan[nomorlahan].nama == "Scrap Reclamation Center")
            {
              cout << "Can't build the same buildings" << endl;
              system("pause");
            }
            else if(p.kayu >= 30 && p.batu >= 30)
            {
            daerah[area].bangunan[nomorlahan].nama = "Scrap Reclamation Center";
            p.kayu -= 30;
            p.batu -= 30;
            }
            else
            {
              cout << "Not enough resourcess" << endl;
              system("pause");
            }

          }
          else return;

       setProduksi(daerah[area].bangunan[nomorlahan]);
       return;
        }
       }
}

void rovenilla(string username, int area,int nomorlahan){
  int pilih;
  system("cls");
      header(username);
      garis(39);
      if(daerah[area].bangunan[nomorlahan].nama == "Grand Roven Market")
      {
        cout << "|       "<< daerah[area].bangunan[nomorlahan].nama <<"      |" << endl;
        garis (39);
        cout<<"1. 80 Wood (2 token)"<<endl;
        cout<<"2. 60 Stone (2 token)"<<endl;
        cout<<"3. 50 Scrap (3 token)"<<endl;
        cout<<"0. Keluar"<<endl;
        garis (39);
        cout<<"What you want to buy: ";cin>>pilih;
  
        for (auto &p : players){
          if (p.nama == username){
              if(pilih==1){
                cout<<"You have purchased wood"<<endl;
                p.token -= 2;
                p.kayu += 50;
              }
              else if(pilih==2){
                cout<<"You have purchased stone"<<endl;
                p.token -= 2;
                p.batu += 40;
              }
              else if(pilih==3){
                cout<<"You have purchased scrap"<<endl;
                p.token -= 3;
                p.scrap += 30;
              }
              else if(pilih==0){
                system("pause");
                return;
              }
          }
        }
      }
      else if (daerah[area].bangunan[nomorlahan].nama == "Vanguard Barracks")
      {
          PlayerData p = loadPlayer(username);
          vanguardBarracks(p);
          savePlayer(p);
          savePlayerCharacters(p);
      }
      else if (daerah[area].bangunan[nomorlahan].nama == "Academy of Sciences") 
      {
          PlayerData p = loadPlayer(username);
          academyMenu(p);
          savePlayer(p);
          savePlayerCharacters(p);
      }
      else{return;}
}

void vanguardBarracks(PlayerData &p) {
    if (p.ownedCharacters.empty()) {
        cout << "You don't have character yet!\n";
        system("pause");
        return;
    }

    while (true) {
        system("cls");
        garis (25); 
        cout << "|   VANGUARD BARRACKS   |\n";
        garis (25);
        cout << "Syringe: " << p.syringe << "\n\n";

        for (int i = 0; i < p.ownedCharacters.size(); i++) {
            auto &c = p.ownedCharacters[i];
            cout << i + 1 << ". " << c.name
                 << " (Lv " << c.level
                 << ", EXP " << c.exp << ")\n";
        }
        
        cout << "0. Back\n";
        garis (25);
        cout << "Choose karakter: ";

        int pilih;
        cin >> pilih;

        if (pilih == 0) return;

        if (pilih < 1 || pilih > p.ownedCharacters.size()) {
            cout << "Invalid choice!\n";
            system("pause");
            continue;
        }

        CharacterData &c = p.ownedCharacters[pilih - 1];

        cout << "\nUpgrade " << c.name << "?\n";
        cout << "Need 1 Syringe\n";
        cout << "1. Yes\n0. No\n";
        garis (25);
        cout << "Choose: ";

        int confirm;
        cin >> confirm;

        if (confirm == 1) {
            if (p.syringe <= 0) {
                cout << "You don't have enough syringe!\n";
            } else {
                p.syringe--;

                if (c.level >= 10) {
                  cout << "Level maksimal!\n";
                  return;
                }
                else {
                  c.level++;
                  cout << c.name << " has been upgrade to level " << c.level << "!\n";
                }
            }
            system("pause");
        }
    }
}

void academyMenu(PlayerData &p) {
    if (p.ownedCharacters.empty()) {
        cout << "You don't have character yet!\n";
        system("pause");
        return;
    }

    while (true) {
        system("cls");
        garis (27);
        cout << "|   ACADEMY OF SCIENCES   |\n";
        garis (27);
        cout << "Powder: " << p.powder << "\n\n";

        for (int i = 0; i < p.ownedCharacters.size(); i++) {
            cout << i + 1 << ". " << p.ownedCharacters[i].name << endl;
        }
        
        cout << "0. Back\n";
        garis (27);
        cout << "Choose character: ";

        int pilih;
        cin >> pilih;

        if (pilih == 0) return;

        if (pilih < 1 || pilih > p.ownedCharacters.size()) {
            cout << "Invalid choice!\n";
            system("pause");
            continue;
        }

        CharacterData &c = p.ownedCharacters[pilih - 1];

        if (c.skillsName.empty()) {
            cout << "The character has no skill!\n";
            system("pause");
            continue;
        }

        while (true) {
            system("cls");
            cout << "=== " << c.name << " ===\n";
            cout << "Powder: " << p.powder << "\n\n";

            for (int i = 0; i < c.skillsName.size(); i++) {
                cout << i + 1 << ". "
                     << c.skillsName[i]
                     << " (Lv " << c.skillLevels[i] << ")\n";
            }

            cout << "0. Back\n";
            garis (25);
            cout << "Choose skill: ";

            int s;
            cin >> s;

            if (s == 0) break;

            if (s < 1 || s > c.skillsName.size()) {
                cout << "Invalid choice!\n";
                system("pause");
                continue;
            }

            int idx = s - 1;

            cout << "\nUpgrade " << c.skillsName[idx] << "?\n";
            cout << "Need 1 Powder\n";
            cout << "1. Yes\n0. No\n";
            garis (25);
            cout<< "Choose: ";

            int confirm;
            cin >> confirm;

            if (confirm == 1) {
                if (p.powder <= 0) {
                    cout << "You don't have enough powder!\n";
                } else {
                    p.powder--;

                    // 🔥 upgrade skill
                    c.skillLevels[idx]++;
                    if (c.skillLevels[idx] >= 10) {
                        cout << "Level maksimal!\n";
                        return;
                    }
                    else {
                    cout << c.skillsName[idx]
                         << " has been upgrade to level "
                         << c.skillLevels[idx] << "!\n";
                    }
                }
                system("pause");
            }
        }
    }
}

void bangunLahan(string username, int area, int nomorlahan){
    if (daerah[area].nama == "Ariolla Monument"){
    int pilih;
    int pBuilding;
    int pBuild;
      Bangunan AM[]={
      {"The Ariolla Statue",false, 20, 15, 10, 0, 0, 0},
      {"The Ship Docks",false, 10, 25, 30, 0, 0, 0},
      {"Ariolla Market",true, 15, 30, 40, 0, 0, 0},
      {"Ariolla Clinic",true, 40, 20, 25, 0, 0, 0},
      {"Ariolla Transit Station",false, 25, 20, 35, 0, 0, 0},
      };
  if(daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
    cout <<"1. Make a building"<<endl;}
  else if(daerah[area].bangunan[nomorlahan].nama != "Empty Land"){
    cout <<"2. Destroy building"<<endl;
  }
  if(daerah[area].bangunan[nomorlahan].nama == "Ariolla Market" ||
      daerah[area].bangunan[nomorlahan].nama == "Ariolla Clinic"){
            cout <<"3. Enter the building"<<endl;}
    cout <<"0. Back"<<endl;
    garis (39);     
    cout <<"Choose: ";cin>>pilih;

    if(pilih==1 && daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
      system("cls");
      header(username);
      garis(39);
      cout << "|              Buildings              |" << endl;
      garis (39);
      for(int i=0; i<5;i++){
        cout<<i+1<< ". "<<AM[i].nama<<endl;
      }
      garis (39);
      cout <<"Choose buildings: ";cin>>pBuilding;
      if (cin.fail())
      {
        cin.clear();
        cin.ignore();
      }
      if (pBuilding == 0)
      {
        return;
      }
      
      if (pBuilding > 5 || pBuilding < 0)
      {
        return;
      }
      
      
      cout<<"\nUse "<<AM[pBuilding-1].bKayu<<" Wood, "
        <<AM[pBuilding-1].bBatu<<" Stone and "
        <<AM[pBuilding-1].bScrap<<" Scrap\nto build "
        <<AM[pBuilding-1].nama<<"\n"<<endl;
      cout <<"1. Yes, build it now"<<endl;      
      cout <<"0. Build it later"<<endl;
      garis (39);
      cout <<"Choose: ";cin>>pBuild;

      for (auto &p : players){
        if (p.nama == username){
            if (pBuild == 1 && p.kayu >= AM[pBuilding-1].bKayu && 
                p.batu >= AM[pBuilding-1].bBatu && 
                p.scrap >= AM[pBuilding-1].bScrap){
                
                p.kayu  -= AM[pBuilding-1].bKayu; 
                p.batu  -= AM[pBuilding-1].bBatu; 
                p.scrap -= AM[pBuilding-1].bScrap; 
                daerah[area].bangunan[nomorlahan].nama = AM[pBuilding-1].nama;
              }
              else if (pBuild == 0){
              return;}

              else{
                   cout << "Resource not enough!\n";
                   system("pause");
                   return;
               }}}}

    else if (pilih == 2){
      if (daerah[area].bangunan[nomorlahan].nama == "Empty Land")
      {
        return;
      }else{

        
        daerah[area].bangunan[nomorlahan].nama = "Empty Land";
        system("cls");
        cout<<"Building has been destroyed"<<endl;
        system("pause");
        return;
      }
    }
    
    else if (pilih == 3){
      ariollaMonument(username,area,nomorlahan);}  
    else if (pilih == 0){
      return;}
    }

    

  else if (daerah[area].nama == "Village Of Purification"){
    villageOfPurification(username,area,nomorlahan);
    return;
    }

  else if (daerah[area].nama == "Rovenilla"){
    int pilih;
    int pBuilding;
    int pBuild;
    Bangunan RN[] = {
       {"Grand Roven Market", true, 200, 150, 100, 0, 0, 0},
       {"Water Purification Plant",false, 100, 250, 300, 0, 0, 0},
       {"Iron-Bound Warehouse",false, 150, 300, 400, 0, 0, 0},
       {"Academy of Sciences",true, 400, 200, 250, 0, 0, 0},
       {"RovenIlla Memorial Hospital",false, 250, 200, 350, 0, 0, 0},
       {"Orphanage of Hope",false, 300, 100, 50, 0, 0, 0},
       {"Signal Transmission Tower",false, 100, 150, 500, 0, 0, 0},
       {"The Aegis Wall",false, 50, 600, 300, 0, 0, 0},
       {"Vanguard Barracks",true, 250, 400, 200, 0, 0, 0},
       {"Governor Manor",false, 500, 500, 500, 0, 0, 0}
      };

  if(daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
    cout <<"1. Make a building"<<endl;}
  else if(daerah[area].bangunan[nomorlahan].nama != "Empty Land"){
    cout <<"2. Destroy building"<<endl;
  }
  if(daerah[area].bangunan[nomorlahan].nama == "Grand Roven Market" ||
      daerah[area].bangunan[nomorlahan].nama == "Academy of Sciences" ||
      daerah[area].bangunan[nomorlahan].nama == "Vanguard Barracks" ){
            cout <<"3. Enter the building"<<endl;}
    cout <<"0. Back"<<endl;
    garis (39);     
    cout <<"Choose: ";cin>>pilih;

    if(pilih==1 && daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
      while (true)
      {
        system("cls");
        header(username);
        garis(39);
        cout << "|              Buildings              |" << endl;
        garis (39);
        for(int i=0; i<10;i++){
          cout<<i+1<< ". "<<RN[i].nama<<endl;
        }
        cout << "0. Back" << endl;
        garis (39);
        cout <<"Pilih bangunan: ";cin>>pBuilding;
        if (cin.fail())
        {
          cin.clear();
          cin.ignore();
        }
        if (pBuilding > 10 || pBuilding < 0)
        {
          return;
        }
        if (pBuilding == 0)
        {
          return;
      }
      break;
      }
        
      
      cout<<"\nUse "<<RN[pBuilding-1].bKayu<<" Wood, "
        <<RN[pBuilding-1].bBatu<<" Stone and "
        <<RN[pBuilding-1].bScrap<<" Scrap\nto build "
        <<RN[pBuilding-1].nama<<"\n"<<endl;
      cout <<"1. Yes, build it now"<<endl;      
      cout <<"0. build it later"<<endl;
      garis (39);
      cout <<"Choose: ";cin>>pBuild;

      for (auto &p : players)
      {
        if (p.nama == username)
        {

            if (pBuild == 1)
            {
              if(p.kayu >= RN[pBuilding-1].bKayu && 
                  p.batu >= RN[pBuilding-1].bBatu && 
                  p.scrap >= RN[pBuilding-1].bScrap){
                
                  p.kayu  -= RN[pBuilding-1].bKayu; 
                  p.batu  -= RN[pBuilding-1].bBatu; 
                  p.scrap -= RN[pBuilding-1].bScrap; 
                  daerah[area].bangunan[nomorlahan].nama = RN[pBuilding-1].nama;
              } 
              else
              {
                  cout << "Resources not enough!\n";
                  system("pause");
                  return;
              }
            }

            else if (pBuild == 0){
            return;}

            else
            {
                   cout << "Invalid\n";
                   system("pause");
                   return;
            }
          }
        }
      }

    else if (pilih == 2){
      if (daerah[area].bangunan[nomorlahan].nama == "Empty Land")
      {
        return;
      }else{

        daerah[area].bangunan[nomorlahan].nama = "Empty Land";
        system("cls");
        cout<<"Building has been destroyed"<<endl;
        system("pause");
        return;
      }
    }
    
    else if (pilih == 3){
      rovenilla(username,area,nomorlahan);}  
    else if (pilih == 0){
      return;}
    }

   
   else if (daerah[area].nama == "Moncini Basin"){
    int pilih;
    int pBuilding;
    int pBuild;
      Bangunan MB[] = {
        {"Purification Rail-Cannon", false, 20, 50, 10, 0, 0, 0},
        {"Aegis Resonance Pylon", false, 30, 30, 10, 0, 0, 0},
        {"Kinetic Harpoon Launcher", false, 20, 40, 15, 0, 0, 0}
      };

  if(daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
    cout <<"1. Make a building"<<endl;}
  else if(daerah[area].bangunan[nomorlahan].nama != "Empty Land"){
    cout <<"2. Destroy building"<<endl;
  }
    cout <<"0. Back"<<endl;
    garis (39);     
    cout <<"Choose: ";cin>>pilih;

    if(pilih==1 && daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
      system("cls");
      header(username);
      garis(39);
      cout << "|              Buildings              |" << endl;
      garis (39);
      for(int i=0; i<3;i++){
        cout<<i+1<< ". "<<MB[i].nama<<endl;
      }
      garis (39);
      cout <<"Choose building: ";cin>>pBuilding;
      
      cout<<"\nUse "<<MB[pBuilding-1].bKayu<<" Wood, "
        <<MB[pBuilding-1].bBatu<<" Stone dan "
        <<MB[pBuilding-1].bScrap<<" Scrap\nto build "
        <<MB[pBuilding-1].nama<<"\n"<<endl;
      cout <<"1. Yes, build it now"<<endl;      
      cout <<"0. Build it later"<<endl;
      garis (39);
      cout <<"Choose: ";cin>>pBuild;

      for (auto &p : players){
        if (p.nama == username){
            if (pBuild == 1 && p.kayu >= MB[pBuilding-1].bKayu && 
                p.batu >= MB[pBuilding-1].bBatu && 
                p.scrap >= MB[pBuilding-1].bScrap){
                
                p.kayu  -= MB[pBuilding-1].bKayu; 
                p.batu  -= MB[pBuilding-1].bBatu; 
                p.scrap -= MB[pBuilding-1].bScrap; 
                daerah[area].bangunan[nomorlahan].nama = MB[pBuilding-1].nama;
              }
              else if (pBuild == 0){
              return;}

              else{
                   cout << "Resource not enough!\n";
                   system("pause");
                   return;
               }}}}

    else if (pilih == 2){
      if (daerah[area].bangunan[nomorlahan].nama == "Empty Land")
      {
        return;
      }else{

        daerah[area].bangunan[nomorlahan].nama = "Empty Land";
        system("cls");
        cout<<"Building has been destroyed"<<endl;
        system("pause");
        return;
      }
      }

    else if (pilih == 0){
      return;}
    }
}


void lahanKosong(string username,int i){
  int pLahan;
  while (true)
  {
    system("cls");
    cout<<"Welcome to" << daerah[i].nama <<"\n" << endl;
    header(username);
    garis(39);
    cout << "|           "<< daerah[i].nama <<"          |" << endl;
    garis (39);
    for(int j=0; j<daerah[i].kapasitas; j++){
      cout<< j+1 <<". " << daerah[i].bangunan[j].nama <<endl;
    }
    cout<< "0. Back "<<endl;
    garis (39);
    if (i==1)
        {statistikArea(i);}
    cout<< "Choose land: ";cin>>pLahan;

    if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        cout << "Enter numbers";
        continue;
       }

    if (pLahan >= 1 && pLahan <= daerah[i].kapasitas){
      bangunLahan(username,i,pLahan-1);
      continue;
    }
 
    else if (pLahan == 0)
    {
        return;
    }

    else
    {
      continue;
    }
  }
}

bool ariollaSelesai(){
  bool TAS = false,TSD = false,AM = false,AC = false,ATS = false;
    for(int i = 0; i < daerah[0].kapasitas; i++){
        if(daerah[0].bangunan[i].nama == "The Ariolla Statue"){
            TAS = true;
        }
    }
    for(int i = 0; i < daerah[0].kapasitas; i++){
        if(daerah[0].bangunan[i].nama == "The Ship Docks"){
            TSD = true;
        }
    }
    for(int i = 0; i < daerah[0].kapasitas; i++){
        if(daerah[0].bangunan[i].nama == "Ariolla Market"){
            AM = true;
        }
    }
    for(int i = 0; i < daerah[0].kapasitas; i++){
        if(daerah[0].bangunan[i].nama == "Ariolla Clinic"){
            AC = true;
        }
    }
    for(int i = 0; i < daerah[0].kapasitas; i++){
        if(daerah[0].bangunan[i].nama == "Ariolla Transit Station"){
            ATS = true;
        }
    }
    if (TAS == true && TSD == true && AM == true && AC == true && ATS == true)
    {
      return true;
    }
    else{
      return false;
    }
    ;
}

void area(string username){
  int pArea;
  bool ulang = true;

  
  while (ulang)
  {

    system("cls");
    header(username);
    garis(39);
    cout << "|             Ariolla Port             |" << endl;
    garis (39);
    for(int i = 0; i<5; i++){
      cout<< i+1 <<". "; if (daerah[i].unlock){cout<< daerah[i].nama;}
      else cout<<"(Locked)";
      cout<<endl;
    }
    cout<< "6. Next Turn and Save"<<endl;
    cout<< "7. Next Story"<<endl;
    cout<< "0. Quit"<<endl;
    garis (39);
    cout <<"Choose Area: "; cin>>pArea;
    
    if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        cout << "Enter numbers";
        continue;
       }

    if (pArea == 1){
      if (daerah[0].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Sorry, this area is locked";
            cin.ignore();
            waitEnter();
                continue;
    }

    else if (pArea == 2)
    {
      if (daerah[1].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Sorry, this area is locked";
            cin.ignore();
            waitEnter();
                continue;
    }

    else if (pArea == 3)
    {
      if (daerah[2].unlock)
              {
                dungeon(username);
              }
            else cout<<"Sorry, this area is locked";
            cin.ignore();
            waitEnter();
                continue;
    }

    else if (pArea == 4)
    {
      if (daerah[3].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Sorry, this area is locked";
            cin.ignore();
            waitEnter();
                continue;
    }

    else if (pArea == 5)
    {
      if (daerah[4].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Sorry, this area is locked";
            cin.ignore();
            waitEnter();
                continue;
    }

    else if (pArea == 6)
    { 
      PerhitunganSumberDaya(username);
      updateBuilding(username);
      updatePlayer();
      system("cls");
      continue;
    }

    else if (pArea == 7){
      if (ariollaSelesai()){
        char pilih;
        cout << "Do you want to continue the story? (y/n): ";
        cin >> pilih;
        if (pilih == 'y' || pilih == 'Y'){
          cin.ignore();
          waitEnter();
          updateBuilding(username);
          updatePlayer();
          ulang = false;
        }
      }
      else{
        cout << "Story not yet available!\n";
        cin.ignore();
        waitEnter();
      }
    }

    else if (pArea == 0)
    {
      ulang = false;
    }

    else
    {
      continue;
    }
  }
}


void sapa(string username){
  string baca1;
  system("cls");
  garis(20);
  cout << "   CITY BUILDING\n   Welcome " << username << "!" << endl;
  garis (20);
  cout << "Press enter to continue...."; getline(cin, baca1);
}


void mainCity(string username){
  string baca1;
  system("cls");
  garis(25);
  cout << "Welcome to Ariolla Port" << endl;
  garis(25);
  cout << "\nPress enter to continue..."; getline(cin,baca1) ; cout<<endl ;

  membaca(username);
  sapa(username);
  area(username);
}


// void main(){
//   mainCity(menusepsepan());
// }
// int main(string username){
//   PlayerData* p = getPlayerData(username);
//   if (p != nullptr) {
//     cout << "LEVEL: " << p-> << endl;
//     cout << "SYRINGE: " << p->syringe << endl;
//     cout << "POWDER: " << p->powder << endl;
//     system("pause");
// }
// }