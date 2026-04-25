#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "../battle/battle.cpp"
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

struct Lahan
{
  string nama;
  bool rusak = true;
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

void garis(int ukuran){
  int pilihan = 0;
  pilihan += ukuran;
  cout << string(int(pilihan),'=') << endl;
  pilihan = 0;
}

string newGame(){
  string nama;
  string cek;
  vector <string> check;

  //Validasi akun baru
  ifstream filecek("../databases/player.txt");
  getline(filecek,cek);
  while (getline(filecek,cek))
  {
    check.push_back(cek);
  }
  bool ada = true;

  while (ada)
  {
    system("cls");
    cout << "Masukkan Username: ";
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
      cout << "Nama sudah digunakan!\n";
      system("pause");
    }
    else
    {
      ada = false;
    }
  }
  
  //Tamvbah ke resources
  ofstream file("../databases/playerresources.txt", ios::app); //appendlibel
  if (!file.is_open())
  {
    cout << "File tidak ada" << endl;
  }
  file << nama << " " << "100 100 100 100 1" << endl;
  file.close();

  //Tamcbah ke buildings
  ofstream file2("../databases/building.txt", ios::app);
  if (!file2.is_open())
  {
    cout << "File gaada";
  }
  file2 << nama  << ",Ariolla Monument,1,5,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land"<< endl;
  file2 << nama  << ",Village Of Purification,1,4,Lumberyard,Stone Quarry,Scrap Reclamation Center,Empty Land"<< endl;
  file2 << nama  << ",Masonwood,0,0"<< endl;
  file2 << nama  << ",Rovenilla,1,10,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land,Empty Land"<< endl;
  file2 << nama  << ",Moncini Basin,1,3,Empty Land,Empty Land,Empty Land"<< endl;
  file2.close();

  ofstream file3("../databases/player.txt", ios::app);
  if (!file3.is_open())
  {
    cout << "File gaada";
  }
  file3 << nama << endl;
  file3.close();

  return nama;
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
      cout << "| Wood: "<< p.kayu << "| Stone: "<< p.batu << "| Scrap: "<< p.scrap <<" |"<<endl;
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
  string bangunan[]={"The Ariolla Statue",
    "The Ship Docks",
    "Ariolla Market",
    "Ariolla Clinic",
    "Ariolla Transit Station"};

  for(int i=0; i<daerah[area].kapasitas; i++){
    if(daerah[area].bangunan[i].rusak){
      cout<<i+1<<". "<< bangunan[i];
      if(i == 0){cout<<" (50 Wood)"<<endl;}
      else if(i == 1){cout<<" (30 Wood, 20 Stone)"<<endl;}
      else if(i == 2){cout<<" (Scrap 25)"<<endl;}
      else if(i == 3){cout<<" (Scrap 30, Stone 10)"<<endl;}
      else if(i == 4){cout<<" (20 Wood, 15 Stone, 10 Scrap)"<<endl;}
    }
  }
      cout << "0. Batal\n";
      cout << "Pilih: "; cin >> pilih;       

       for (auto &p : players){
           if (p.nama == username){

               if (pilih == 1 ){
                  if(daerah[area].bangunan[nomorlahan].rusak && p.kayu >= 50)
                    if(
                  daerah[area].bangunan[0].nama == bangunan[0] ||
                  daerah[area].bangunan[1].nama == bangunan[0] ||
                  daerah[area].bangunan[2].nama == bangunan[0] ||
                  daerah[area].bangunan[3].nama == bangunan[0] ||
                  daerah[area].bangunan[4].nama == bangunan[0]          
                ){cout<< "Maaf, tidak ada pilihan"<< endl;
                  system("pause");
                  return;}
                else{
                   p.kayu -= 50;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[0];
                   daerah[area].bangunan[0].rusak = false;
                }
               }
               else if (pilih == 2 && p.kayu >= 30 && p.batu >= 20){
                if(
                  daerah[area].bangunan[0].nama == bangunan[1] ||
                  daerah[area].bangunan[1].nama == bangunan[1] ||
                  daerah[area].bangunan[2].nama == bangunan[1] ||
                  daerah[area].bangunan[3].nama == bangunan[1] ||
                  daerah[area].bangunan[4].nama == bangunan[1]          
                ){cout<< "Maaf, tidak ada pilihan"<< endl;
                  system("pause"); 
                  return;}
                else{
                   p.kayu -= 30; p.batu -= 20;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[1];
                   daerah[area].bangunan[1].rusak = false;
                }
               }
               else if (pilih == 3 && p.scrap >= 25){
                 if(
                  daerah[area].bangunan[0].nama == bangunan[2] ||
                  daerah[area].bangunan[1].nama == bangunan[2] ||
                  daerah[area].bangunan[2].nama == bangunan[2] ||
                  daerah[area].bangunan[3].nama == bangunan[2] ||
                  daerah[area].bangunan[4].nama == bangunan[2]          
                ){cout<< "Maaf, tidak ada pilihan"<< endl;
                  system("pause");
                  return;}
                else{
                   p.scrap -= 25;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[2];
                   daerah[area].bangunan[2].rusak = false;
                }
               }
               else if (pilih == 4 && p.scrap >= 30 && p.batu >= 10){
                if(
                  daerah[area].bangunan[0].nama == bangunan[3] ||
                  daerah[area].bangunan[1].nama == bangunan[3] ||
                  daerah[area].bangunan[2].nama == bangunan[3] ||
                  daerah[area].bangunan[3].nama == bangunan[3] ||
                  daerah[area].bangunan[4].nama == bangunan[3]          
                ){cout<< "Maaf, tidak ada pilihan"<< endl;
                  system("pause");
                  return;}
                else{
                   p.scrap -= 30; p.batu -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[3];
                   daerah[area].bangunan[3].rusak = false;
                }
               }
               else if (pilih == 5 && p.kayu >= 20 && p.batu >= 15 && p.scrap >= 10){
                if(
                  daerah[area].bangunan[0].nama == bangunan[4] ||
                  daerah[area].bangunan[1].nama == bangunan[4] ||
                  daerah[area].bangunan[2].nama == bangunan[4] ||
                  daerah[area].bangunan[3].nama == bangunan[4] ||
                  daerah[area].bangunan[4].nama == bangunan[4]          
                ){cout<< "Maaf, tidak ada pilihan"<< endl;
                  system("pause");
                  return;}
                else{
                   p.kayu -= 20; p.batu -= 15; p.scrap -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[4];
                   daerah[area].bangunan[4].rusak = false;
                }
               }
               else if (pilih == 0){
                   return;
               }
               else{
                   cout << "Resource tidak cukup!\n";
                   system("pause");
                   return;
               }
           }
       }
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
  string bangunan[]={ "The Grand Roven Market",
  "Central Water Purification Plant",
  "Iron-Bound Warehouse",
  "The Academy of Sciences",
  "RovenIlla Memorial Hospital",
  "The Orphanage of Hope",
  "Signal Transmission Tower",
  "The Aegis Wall",
  "Vanguard Barracks",
  "The Governor's Manor"};

  for(int i=0; i<daerah[area].kapasitas; i++){
    if(daerah[area].bangunan[i].rusak){
      cout<<i+1<<". "<< bangunan[i];
      if(i == 0){cout<<" (50 kayu)"<<endl;}
      else if(i == 1){cout<<" (30 kayu, 20 Batu)"<<endl;}
      else if(i == 2){cout<<" (Scrap 25)"<<endl;}
      else if(i == 3){cout<<" (Scrap 30, Batu 10)"<<endl;}
      else if(i == 4){cout<<" (20 kayu, 15 Batu, 10 Scrap)"<<endl;}
      else if(i == 5){cout<<" (30 kayu, 20 Batu)"<<endl;}
      else if(i == 6){cout<<" (Scrap 25)"<<endl;}
      else if(i == 7){cout<<" (Scrap 30, Batu 10)"<<endl;}
      else if(i == 8){cout<<" (20 kayu, 15 Batu, 10 Scrap)"<<endl;}
      else if(i == 9){cout<<" (20 kayu, 15 Batu, 10 Scrap)"<<endl;}
    }
  }
      cout << "0. Batal\n";
      cout << "Pilih: "; cin >> pilih;       

       for (auto &p : players){
           if (p.nama == username){

               if (pilih == 1 ){
                  if(daerah[area].bangunan[nomorlahan].rusak && p.kayu >= 50)
                   p.kayu -= 50;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[0];
                   daerah[area].bangunan[nomorlahan].rusak = false;
                   
               }
               else if (pilih == 2 && p.kayu >= 30 && p.batu >= 20){
                   p.kayu -= 30; p.batu -= 20;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[1];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 3 && p.scrap >= 25){
                   p.scrap -= 25;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[2];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 4 && p.scrap >= 30 && p.batu >= 10){
                   p.scrap -= 30; p.batu -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[3];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 5 && p.kayu >= 20 && p.batu >= 15 && p.scrap >= 10){
                   p.kayu -= 20; p.batu -= 15; p.scrap -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[4];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 6 && p.kayu >= 30 && p.batu >= 20){
                   p.kayu -= 30; p.batu -= 20;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[5];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 7 && p.scrap >= 25){
                   p.scrap -= 25;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[6];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 8 && p.scrap >= 30 && p.batu >= 10){
                   p.scrap -= 30; p.batu -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[7];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 9 && p.kayu >= 20 && p.batu >= 15 && p.scrap >= 10){
                   p.kayu -= 20; p.batu -= 15; p.scrap -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[8];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 10 && p.kayu >= 20 && p.batu >= 15 && p.scrap >= 10){
                   p.kayu -= 20; p.batu -= 15; p.scrap -= 10;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[9];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 0){
                   return;
               }
               else{
                   cout << "Resource tidak cukup!\n";
                   system("pause");
                   return;
               }
           }
       }
}

void monciniBasin(string username, int area, int nomorlahan){
  int pilih;
  string bangunan[]={ "The Purification Rail-Cannon",
  "Aegis Resonance Pylon",
  "Kinetic Harpoon Launcher"};

  for(int i=0; i<daerah[area].kapasitas; i++){
    if(daerah[area].bangunan[i].rusak){
      cout<<i+1<<". "<< bangunan[i];
      if(i == 0){cout<<" (50 kayu)"<<endl;}
      else if(i == 1){cout<<" (30 kayu, 20 Batu)"<<endl;}
      else if(i == 2){cout<<" (Scrap 25)"<<endl;}
    }
  }
      cout << "0. Batal\n";
      cout << "Pilih: "; cin >> pilih;       

       for (auto &p : players){
           if (p.nama == username){

               if (pilih == 1 ){
                  if(daerah[area].bangunan[nomorlahan].rusak && p.kayu >= 50)
                   p.kayu -= 50;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[0];
                   daerah[area].bangunan[nomorlahan].rusak = false;
                   
               }
               else if (pilih == 2 && p.kayu >= 30 && p.batu >= 20){
                   p.kayu -= 30; p.batu -= 20;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[1];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 3 && p.scrap >= 25){
                   p.scrap -= 25;
                   daerah[area].bangunan[nomorlahan].nama = bangunan[2];
                   daerah[area].bangunan[nomorlahan].rusak = false;
               }
               else if (pilih == 0){
                   return;
               }
               else{
                   cout << "Resource tidak cukup!\n";
                   system("pause");
                   return;
               }
           }
       }
}

void bangunLahan(string username, int area, int nomorlahan){

   if (daerah[area].nama == "Village Of Purification"){
       villageOfPurification(username,area,nomorlahan);
       return;
      }

   else if (daerah[area].nama == "Ariolla Monument"){
       ariollaMonument(username,area,nomorlahan);
       return;
   }
  //  else if (daerah[area].nama == "Ariolla Monument"){
  //      ariollaMonument(username,area,nomorlahan);
  //      return;
  //  }
   else if (daerah[area].nama == "Rovenilla"){
       rovenilla(username,area,nomorlahan);
       return;
   }
   else if (daerah[area].nama == "Moncini Basin"){
       monciniBasin(username,area,nomorlahan);
       return;
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
    for(int i = 0; i < daerah[0].kapasitas; i++){
        if(daerah[0].bangunan[i].nama == "Empty Land"){
            return false;
        }
    }
    return true;
}

void area(string username){
  int pArea;
  while (true)
  {

    system("cls");
    header(username);
    garis(39);
    cout << "|              Ariolla Port             |" << endl;
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
                lahanKosong(username,pArea-1);
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

string menusepsepan(){
  vector <string> nama;
  ifstream file("../databases/player.txt");
  string line;
  int logs;
  
  getline(file, line);
  while (getline(file, line)) {
    if (!line.empty())
    nama.push_back(line);
  }
  file.close();
  
  //konsidi
  if (nama.empty() == true)
  {
    return newGame();
  }
  
  else if (nama.empty() == false)
  {
    while (true)
    { 
      system("cls");
      garis(30);
      cout << "          MORIVELLE           \n";
      garis(30);
      cout << "1. New Game\n2. Load" << endl;
      garis(30);
      cout << "Pilih: "; cin >> logs;
      if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        cout << "Masukkan angka\n";
        continue;
       }
      if (logs == 1)
      {
        string bucket;
        getline(cin,bucket); //bug yang belum di ajarin
        return newGame();
      }

      else if (logs == 2)
      {
        while (true)
        {
          garis(30);
          for (int i = 0; i < (int)nama.size(); i++)
          {
            cout << i+1 << ". " << nama[i] << endl;
          }
          cout << "0. Kembali\n";
          int pilihanUser;
          cout << "\nPilih index: "; cin >> pilihanUser;
          if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        system("cls");
        garis(30);
        cout << "Masukkan angka\n";
        continue;
       }

          if (pilihanUser < 1 || pilihanUser > (int)nama.size())
          {
            if (pilihanUser == 0)
            {
              break;
            }
            
            garis(30);
            cout << "Harap masukkan angka yang valid\n";
            continue;
          }
          
          return nama[pilihanUser-1];
        }
        
        }
    }
  }
  return 0;
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

int main(){
  mainCity(menusepsepan());
}