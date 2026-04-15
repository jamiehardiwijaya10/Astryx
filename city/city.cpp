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
  file2 << nama  << ",Ariolla Monument,1,5,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong"<< endl;
  file2 << nama  << ",Village Of Purification,1,4,Penebangan Kayu,Penambangan Batu,Pengumpulan Scrap,Lahan Kosong"<< endl;
  file2 << nama  << ",Masonwood,0,0"<< endl;
  file2 << nama  << ",Rovenilla,0,10,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong,Lahan Kosong"<< endl;
  file2 << nama  << ",Moncini Basin,0,3,Lahan Kosong,Lahan Kosong,Lahan Kosong"<< endl;
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
    if (l.nama == "Penebangan Kayu"){
        l.pKayu = 10;
        l.pBatu = 0;
        l.pScrap = 0;
    }
    else if (l.nama == "Penambangan Batu"){
        l.pKayu = 0;
        l.pBatu = 8;
        l.pScrap = 0;
    }
    else if (l.nama == "Pengumpulan Scrap"){
        l.pKayu = 0;
        l.pBatu = 0;
        l.pScrap = 6;
    }
    else if(l.nama == "Lahan Kosong"){
        l.pKayu = 0;
        l.pBatu = 0;
        l.pScrap = 0;
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
      cout << "| Kayu: "<< p.kayu << "| Batu: "<< p.batu << "| Scrap: "<< p.scrap <<" |"<<endl;
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
    cout<<"Kayu = "<< daerah[i].totalK <<"/Turn" <<endl;
    cout<<"Batu = "<< daerah[i].totalB <<"/Turn" <<endl;
    cout<<"Scrap= "<< daerah[i].totalS <<"/Turn" <<endl;
    garis (39);
}

void bangunLahan(int area, int nomorlahan, string username){

   if (daerah[area].nama == "Village Of Purification"){
       int pilih;

       cout << "1. Penebangan Kayu\n";
       cout << "2. Penambangan Batu\n";
       cout << "3. Pengumpulan Scrap\n";
       cout << "0. Batal\n";
       cout << "Pilih: "; cin >> pilih;

       for (auto &p : players){
        if (p.nama == username){

          if (pilih == 1 && p.batu >= 30 && p.scrap >= 5){

            if (daerah[area].bangunan[nomorlahan].nama == "Penebangan Kayu")
            {
              cout << "Tidak bisa membangun bangunan yang sama" << endl;
              system("pause");
            }
            else
            {
            daerah[area].bangunan[nomorlahan].nama = "Penebangan Kayu";
            p.batu -= 30;
            p.scrap -= 5;
            }
          }

          else if (pilih == 2 && p.kayu >=20 && p.scrap >= 5){
            if (daerah[area].bangunan[nomorlahan].nama == "Penambangan Batu")
            {
              cout << "Tidak bisa membangun bangunan yang sama" << endl;
              system("pause");
            }
            else
            {
            daerah[area].bangunan[nomorlahan].nama = "Penambangan Batu";
            p.kayu -= 20;
            p.scrap -= 5;
            }
          }

          else if (pilih == 3 && p.kayu >= 30 && p.batu >= 30){
            if (daerah[area].bangunan[nomorlahan].nama == "Pengumpulan Scrap")
            {
              cout << "Tidak bisa membangun bangunan yang sama" << endl;
              system("pause");
            }
            else{
            daerah[area].bangunan[nomorlahan].nama = "Pengumpulan Scrap";
            p.kayu -= 30;
            p.batu -= 30;
            }

          }
          else return;

       setProduksi(daerah[area].bangunan[nomorlahan]);
       return;
        }
       }
      }

   if (daerah[area].nama == "Ariolla Monument"){
       int pilih;

       cout << "1. Patung Ariolla (Kayu 50)\n";
       cout << "2. Dermaga Kapal (Kayu 30, Batu 20)\n";
       cout << "3. Pusat Makanan (Scrap 25)\n";
       cout << "4. Pusat Obat (Scrap 30, Batu 10)\n";
       cout << "0. Batal\n";
       cout << "Pilih: "; cin >> pilih;

       for (auto &p : players){
           if (p.nama == username){

               if (pilih == 1 && p.kayu >= 50){
                   p.kayu -= 50;
                   daerah[area].bangunan[nomorlahan].nama = "Patung Ariolla";
               }
               else if (pilih == 2 && p.kayu >= 30 && p.batu >= 20){
                   p.kayu -= 30; p.batu -= 20;
                   daerah[area].bangunan[nomorlahan].nama = "Dermaga Kapal";
               }
               else if (pilih == 3 && p.scrap >= 25){
                   p.scrap -= 25;
                   daerah[area].bangunan[nomorlahan].nama = "Pusat Makanan";
               }
               else if (pilih == 4 && p.scrap >= 30 && p.batu >= 10){
                   p.scrap -= 30; p.batu -= 10;
                   daerah[area].bangunan[nomorlahan].nama = "Pusat Obat";
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

    if (pLahan == 1)
    {
        bangunLahan(i,0,username);
        continue;
    }

    else if (pLahan == 2)
    {
        bangunLahan(i,1,username);
        continue;
    }

    else if (pLahan == 3)
    {
        bangunLahan(i,2,username);
        continue;
    }

    else if (pLahan == 4)
    {
        bangunLahan(i,3,username);
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
    for(int i = 0; i < 4; i++){
        if(daerah[0].bangunan[i].nama == "Lahan Kosong"){
            return false;
        }
    }
    return true;
}

void area(string username){
  int pArea;
  while (true)
  {
    if(ariollaSelesai() && !notifStory){
      cout << "\n[!] Ariolla Monument selesai!\n";
      cout << "[!] Story baru tersedia!\n";
      notifStory = true;
      waitEnter();
    }

    system("cls");
    header(username);
    garis(39);
    cout << "|              Ariolla Port             |" << endl;
    garis (39);
    for(int i = 0; i<5; i++){
      cout<< i+1 <<". "; if (daerah[i].unlock){cout<< daerah[i].nama;}
      else cout<<"(Terkunci)";
      cout<<endl;
    }
    cout<< "6. Next Turn"<<endl;
    cout<< "7. Lanjut Story"<<endl;
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