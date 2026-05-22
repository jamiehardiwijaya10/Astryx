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
  while (getline(file, line)) {
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
    cout << "File tidak ada" << endl;
  }
  tulis1<<"nama kayu batu scrap token turn"<<endl;
  for (auto &p : players){

    tulis1 << p.nama << " " << p.kayu << " " << p.batu << " " << p.scrap << " " << p.token << " " << p.turn <<endl;
    
  }
  tulis1.close();
  
  }

void updateBuilding(string username){
    vector<string>semuaData;
    string line;
    int i = 0;
    ifstream file2("../databases/building.txt");
    while (getline(file2, line)){
        stringstream baca2(line);
        string name;

        getline(baca2, name, ',');

        if (name != username && i < 5){
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

        for (int j=0; j<daerah[i].kapasitas; j++){
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
  system("cls");
      header(username);
      garis(39);
      if(daerah[area].bangunan[nomorlahan].nama == "Ariolla Market")
      {
        cout << "|       "<< daerah[area].bangunan[nomorlahan].nama <<"      |" << endl;
        garis (39);
        cout<<"1. 50 Kayu (2 token)"<<endl;
        cout<<"2. 40 Batu (2 token)"<<endl;
        cout<<"3. 30 Scrap (3 token)"<<endl;
        cout<<"0. Keluar"<<endl;
        garis (39);
        cout<<"pilih yang ingin dibeli: ";cin>>pilih;
  
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
          }
        }
      }
      else if(daerah[area].bangunan[nomorlahan].nama == "Ariolla Clinic")
      {
        cout << "|       "<< daerah[area].bangunan[nomorlahan].nama <<"      |" << endl;
        garis (39);
        cout<<"1. Medkit (5 token)"<<endl;
        cout<<"2. first aid (2 token)"<<endl;
        cout<<"3. betadine (3 token)"<<endl;
        cout<<"0. Keluar"<<endl;
        garis (39);
        cout<<"pilih yang ingin dibeli: ";cin>>pilih;
  
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
              cout << "Tidak bisa membangun bangunan yang sama" << endl;
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
              cout << "Maaf, Sumberdaya yang anda miliki tidak cukup" << endl;
              system("pause");
            }
          }

          else if (pilih == 2){
            if (daerah[area].bangunan[nomorlahan].nama == "Stone Quarry")
            {
              cout << "Tidak bisa membangun bangunan yang sama" << endl;
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
              cout << "Maaf, Sumberdaya yang anda miliki tidak cukup" << endl;
              system("pause");
            }
          }

          else if (pilih == 3){
            if (daerah[area].bangunan[nomorlahan].nama == "Scrap Reclamation Center")
            {
              cout << "Tidak bisa membangun bangunan yang sama" << endl;
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
              cout << "Maaf, Sumberdaya yang anda miliki tidak cukup" << endl;
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
        cout<<"1. 80 Kayu (2 token)"<<endl;
        cout<<"2. 60 Batu (2 token)"<<endl;
        cout<<"3. 50 Scrap (3 token)"<<endl;
        cout<<"0. Keluar"<<endl;
        garis (39);
        cout<<"pilih yang ingin dibeli: ";cin>>pilih;
  
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
        cout << "Kamu belum punya karakter!\n";
        system("pause");
        return;
    }

    while (true) {
        system("cls");
        cout << "=== VANGUARD BARRACKS ===\n";
        cout << "Syringe: " << p.syringe << "\n\n";

        for (int i = 0; i < p.ownedCharacters.size(); i++) {
            auto &c = p.ownedCharacters[i];
            cout << i + 1 << ". " << c.name
                 << " (Lv " << c.level
                 << ", EXP " << c.exp << ")\n";
        }

        cout << "0. Kembali\n";
        cout << "Pilih karakter: ";

        int pilih;
        cin >> pilih;

        if (pilih == 0) return;

        if (pilih < 1 || pilih > p.ownedCharacters.size()) {
            cout << "Pilihan tidak valid!\n";
            system("pause");
            continue;
        }

        CharacterData &c = p.ownedCharacters[pilih - 1];

        cout << "\nUpgrade " << c.name << "?\n";
        cout << "Butuh 1 Syringe\n";
        cout << "1. Ya\n0. Tidak\nPilih: ";

        int confirm;
        cin >> confirm;

        if (confirm == 1) {
            if (p.syringe <= 0) {
                cout << "Syringe tidak cukup!\n";
            } else {
                p.syringe--;

                if (c.level >= 10) {
                  cout << "Level maksimal!\n";
                  return;
                }
                else {
                  c.level++;
                  cout << c.name << " naik ke level " << c.level << "!\n";
                }
            }
            system("pause");
        }
    }
}

void academyMenu(PlayerData &p) {
    if (p.ownedCharacters.empty()) {
        cout << "Kamu belum punya karakter!\n";
        system("pause");
        return;
    }

    while (true) {
        system("cls");
        cout << "=== ACADEMY OF SCIENCES ===\n";
        cout << "Powder: " << p.powder << "\n\n";

        for (int i = 0; i < p.ownedCharacters.size(); i++) {
            cout << i + 1 << ". " << p.ownedCharacters[i].name << endl;
        }

        cout << "0. Kembali\n";
        cout << "Pilih karakter: ";

        int pilih;
        cin >> pilih;

        if (pilih == 0) return;

        if (pilih < 1 || pilih > p.ownedCharacters.size()) {
            cout << "Pilihan tidak valid!\n";
            system("pause");
            continue;
        }

        CharacterData &c = p.ownedCharacters[pilih - 1];

        if (c.skillsName.empty()) {
            cout << "Karakter tidak punya skill!\n";
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

            cout << "0. Kembali\n";
            cout << "Pilih skill: ";

            int s;
            cin >> s;

            if (s == 0) break;

            if (s < 1 || s > c.skillsName.size()) {
                cout << "Pilihan tidak valid!\n";
                system("pause");
                continue;
            }

            int idx = s - 1;

            cout << "\nUpgrade " << c.skillsName[idx] << "?\n";
            cout << "Butuh 1 Powder\n";
            cout << "1. Ya\n0. Tidak\nPilih: ";

            int confirm;
            cin >> confirm;

            if (confirm == 1) {
                if (p.powder <= 0) {
                    cout << "Powder tidak cukup!\n";
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
                         << " naik ke level "
                         << c.skillLevels[idx] << "!\n";
                    }
                }
                system("pause");
            }
        }
    }
}

void monciniBasin(string username, int area, int nomorlahan){
  int pilih;
  cout<<"selamat kamu bisa\n"<<endl;
  return;
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
    cout <<"1. Buat Bangunan"<<endl;}
  else if(daerah[area].bangunan[nomorlahan].nama != "Empty Land"){
    cout <<"2. Hancurkan Bangunan"<<endl;
  }
  if(daerah[area].bangunan[nomorlahan].nama == "Ariolla Market" ||
      daerah[area].bangunan[nomorlahan].nama == "Ariolla Clinic"){
            cout <<"3. Masuk Bangunan"<<endl;}
    cout <<"0. Kembali"<<endl;
    garis (39);     
    cout <<"Pilih: ";cin>>pilih;

    if(pilih==1 && daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
      system("cls");
      header(username);
      garis(39);
      cout << "|              buildings              |" << endl;
      garis (39);
      for(int i=0; i<5;i++){
        cout<<i+1<< ". "<<AM[i].nama<<endl;
      }
      garis (39);
      cout <<"Pilih bangunan: ";cin>>pBuilding;
      
      cout<<"\nGunakan "<<AM[pBuilding-1].bKayu<<" Kayu, "
        <<AM[pBuilding-1].bBatu<<" Batu dan "
        <<AM[pBuilding-1].bScrap<<" Scrap\nuntuk membangun "
        <<AM[pBuilding-1].nama<<"\n"<<endl;
      cout <<"1. Ya, Bangun sekarang"<<endl;      
      cout <<"0. Bangun Nanti"<<endl;
      garis (39);
      cout <<"Pilih: ";cin>>pBuild;

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
                   cout << "Resource tidak cukup!\n";
                   system("pause");
                   return;
               }}}}

    else if (pilih == 2){
      daerah[area].bangunan[nomorlahan].nama = "Empty Land";
      system("cls");
      cout<<"Bangunan telah dihancurkan"<<endl;
      system("pause");
      return;
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
    cout <<"1. Buat Bangunan"<<endl;}
  else if(daerah[area].bangunan[nomorlahan].nama != "Empty Land"){
    cout <<"2. Hancurkan Bangunan"<<endl;
  }
  if(daerah[area].bangunan[nomorlahan].nama == "Grand Roven Market" ||
      daerah[area].bangunan[nomorlahan].nama == "Academy of Sciences" ||
      daerah[area].bangunan[nomorlahan].nama == "Vanguard Barracks" ){
            cout <<"3. Masuk Bangunan"<<endl;}
    cout <<"0. Kembali"<<endl;
    garis (39);     
    cout <<"Pilih: ";cin>>pilih;

    if(pilih==1 && daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
      system("cls");
      header(username);
      garis(39);
      cout << "|              buildings              |" << endl;
      garis (39);
      for(int i=0; i<10;i++){
        cout<<i+1<< ". "<<RN[i].nama<<endl;
      }
      garis (39);
      cout <<"Pilih bangunan: ";cin>>pBuilding;
      
      cout<<"\nGunakan "<<RN[pBuilding-1].bKayu<<" Kayu, "
        <<RN[pBuilding-1].bBatu<<" Batu dan "
        <<RN[pBuilding-1].bScrap<<" Scrap\nuntuk membangun "
        <<RN[pBuilding-1].nama<<"\n"<<endl;
      cout <<"1. Ya, Bangun sekarang"<<endl;      
      cout <<"0. Bangun Nanti"<<endl;
      garis (39);
      cout <<"Pilih: ";cin>>pBuild;

      for (auto &p : players){
        if (p.nama == username){
            if (pBuild == 1 && p.kayu >= RN[pBuilding-1].bKayu && 
                p.batu >= RN[pBuilding-1].bBatu && 
                p.scrap >= RN[pBuilding-1].bScrap){
                
                p.kayu  -= RN[pBuilding-1].bKayu; 
                p.batu  -= RN[pBuilding-1].bBatu; 
                p.scrap -= RN[pBuilding-1].bScrap; 
                daerah[area].bangunan[nomorlahan].nama = RN[pBuilding-1].nama;
              }
              else if (pBuild == 0){
              return;}

              else{
                   cout << "Resource tidak cukup!\n";
                   system("pause");
                   return;
               }}}}

    else if (pilih == 2){
      daerah[area].bangunan[nomorlahan].nama = "Empty Land";
      system("cls");
      cout<<"Bangunan telah dihancurkan"<<endl;
      system("pause");
      return;
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
    cout <<"1. Buat Bangunan"<<endl;}
  else if(daerah[area].bangunan[nomorlahan].nama != "Empty Land"){
    cout <<"2. Hancurkan Bangunan"<<endl;
  }
    cout <<"0. Kembali"<<endl;
    garis (39);     
    cout <<"Pilih: ";cin>>pilih;

    if(pilih==1 && daerah[area].bangunan[nomorlahan].nama == "Empty Land"){
      system("cls");
      header(username);
      garis(39);
      cout << "|              buildings              |" << endl;
      garis (39);
      for(int i=0; i<3;i++){
        cout<<i+1<< ". "<<MB[i].nama<<endl;
      }
      garis (39);
      cout <<"Pilih bangunan: ";cin>>pBuilding;
      
      cout<<"\nGunakan "<<MB[pBuilding-1].bKayu<<" Kayu, "
        <<MB[pBuilding-1].bBatu<<" Batu dan "
        <<MB[pBuilding-1].bScrap<<" Scrap\nuntuk membangun "
        <<MB[pBuilding-1].nama<<"\n"<<endl;
      cout <<"1. Ya, Bangun sekarang"<<endl;      
      cout <<"0. Bangun Nanti"<<endl;
      garis (39);
      cout <<"Pilih: ";cin>>pBuild;

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
                   cout << "Resource tidak cukup!\n";
                   system("pause");
                   return;
               }}}}

    else if (pilih == 2){
      daerah[area].bangunan[nomorlahan].nama = "Empty Land";
      system("cls");
      cout<<"Bangunan telah dihancurkan"<<endl;
      system("pause");
      return;
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
    cout<<"Selamat datang di" << daerah[i].nama <<"\n" << endl;
    header(username);
    garis(39);
    cout << "|           "<< daerah[i].nama <<"          |" << endl;
    garis (39);
    for(int j=0; j<daerah[i].kapasitas; j++){
      cout<< j+1 <<". " << daerah[i].bangunan[j].nama <<endl;
    }
    cout<< "0. Kembali "<<endl;
    garis (39);
    if (i==1)
        {statistikArea(i);}
    cout<< "Pilih lahan: ";cin>>pLahan;

    if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        cout << "Masukkan angka";
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
  while (true)
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
    cout<< "0. Kembali"<<endl;
    garis (39);
    cout <<"Pilih Area: "; cin>>pArea;
    
    if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        cout << "Masukkan angka";
        continue;
       }

    if (pArea == 1){
      if (daerah[0].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
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
            else cout<<"Maaf, Area ini masih terkunci";
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
            else cout<<"Maaf, Area ini masih terkunci";
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
            else cout<<"Maaf, Area ini masih terkunci";
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
            else cout<<"Maaf, Area ini masih terkunci";
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
        cout << "Ingin lanjut ke story? (y/n): ";
        cin >> pilih;
        if (pilih == 'y' || pilih == 'Y'){
          cin.ignore();
          waitEnter();
          return; 
        }
      }
      else{
        cout << "Story belum tersedia!\n";
        cin.ignore();
        waitEnter();
      }
    }

    else if (pArea == 0)
    {
      break;
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
  cout << "Ketik enter untuk melanjutkan...."; getline(cin, baca1);
}


void mainCity(string username){
  string baca1;
  garis(25);
  cout << "Welcome to Ariolla Port" << endl;
  garis(25);
  cout << "\nketik enter atau apa saja untuk melanjutkan..."; getline(cin,baca1) ; cout<<endl ;

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