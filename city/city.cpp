#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
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
  bool rusak;
  int bKayu;
  int bBatu;
  int bBesi;
  int pKayu;
  int pBatu;
  int pScrap;
};

struct Area
{
  string nama;
  bool unlock;
  int totalK;
  int totalB;
  int totalS;
  Lahan bangunan[4];
};Area daerah[5];



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

  //Tamvbah ke resources
  ofstream file("../databases/playerresources.txt", ios::app); //appendlibel
  if (!file.is_open())
  {
    cout << "File tidak ada" << endl;
  }
  cout << "Masukkan Username: "; getline(cin,nama); cout << endl;
       
  file << nama << " " << "100 100 100 10 1" << endl;
  file.close();

  //Tamcbah ke buildings
  ofstream file2("../databases/building.txt", ios::app);
  if (!file2.is_open())
  {
    cout << "File gaada";
  }
  file2 << nama  << ",Arriola Monument,1,Kosong,Kosong,Kosong,Kosong"<< endl;
  file2 << nama  << ",Village Of Purification,0,Kosong,Kosong,Kosong,Kosong"<< endl;
  file2 << nama  << ",Masonwood,0,Kosong,Kosong,Kosong,Kosong"<< endl;
  file2 << nama  << ",Rovenilla,0,Kosong,Kosong,Kosong,Kosong"<< endl;
  file2 << nama  << ",Moncini Basin,0,Kosong,Kosong,Kosong,Kosong"<< endl;
  file2.close();


  return nama;
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
  while (getline(file2, line)) {
        stringstream baca2(line);
        string name;
        string areaName;
        string unlockStatus;
        string l1,l2,l3,l4;

        getline(baca2, name, ',');
        getline(baca2, areaName, ',');
        getline(baca2, unlockStatus, ',');
        getline(baca2, l1, ',');
        getline(baca2, l2, ',');
        getline(baca2, l3, ',');
        getline(baca2, l4);

        if (name == username && i < 5){

            daerah[i].nama = areaName;

            daerah[i].unlock = (unlockStatus == "1");

            daerah[i].bangunan[0].nama = l1;
            daerah[i].bangunan[1].nama = l2;
            daerah[i].bangunan[2].nama = l3;
            daerah[i].bangunan[3].nama = l4;

            i++;
          }
        }
  file2.close();
}
void PerhitunganSumberDaya(string username){
  for (auto &p : players){
    if(username == p.nama ){
      int totalK = 0;
      int totalB = 0;
      int totalS = 0;
      
      for (int i=0; i<5; i++){
        for(int j = 0; j<4; j++){
            totalK += daerah[i].bangunan[j].pKayu;
            totalB += daerah[i].bangunan[j].pBatu;
            totalS += daerah[i].bangunan[j].pScrap;
           }
        }
      p.kayu += totalK;
      p.batu += totalB;
      p.scrap += totalS;
    }
    p.turn++;
    p.token--;

  }
}

void updatePlayer(string username){

  ofstream tulis1("../databases/playerresources.txt");
  if (!tulis1.is_open())
  {
    cout << "File tidak ada" << endl;
  }
  tulis1<<"nama kayu batu scrap token turn"<<endl;
  for (auto &p : players)
  { if(username == p.nama){
    players.clear();
    tulis1 << p.nama << " " << p.kayu << " " << p.batu << " " << p.scrap << " " << p.token << " " << p.turn <<endl;
      players.push_back(p);
    }
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

        for (int j=0; j<4; j++){
            baris += daerah[i].bangunan[j].nama;
            if (j < 3)
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
    for(int j = 0; j<4; j++){
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
   int pBangun;
   while (true){
       system("cls");
       header(username);
       garis(39);
       cout << "|          Pengelolaan Lahan          |" << endl;
       garis (39);
       cout << "1. Penebangan Kayu"<<endl;
       cout << "2. Penambangan Batu"<<endl;
       cout << "3. Pengumpulan Scrap"<<endl;
       cout << "0. Batal"<<endl;
       garis(39);
       cout <<"Pilih Pengelolaan pada lahan: "; cin >> pBangun;

       if (cin.fail())
       {
        cin.clear();
        cin.ignore();
        cout << "Masukkan angka";
        continue;
       }
       
  
         if (pBangun==1){
             daerah[area].bangunan[nomorlahan].nama = "Penebangan Kayu";
             daerah[area].bangunan[nomorlahan].pKayu = 10;
             daerah[area].bangunan[nomorlahan].pBatu = 0;
             daerah[area].bangunan[nomorlahan].pScrap = 0;
             break;
         }
         else if (pBangun == 2){
             daerah[area].bangunan[nomorlahan].nama = "Penambangan Batu";
             daerah[area].bangunan[nomorlahan].pKayu = 0;
             daerah[area].bangunan[nomorlahan].pBatu = 8;
             daerah[area].bangunan[nomorlahan].pScrap = 0;
             break;
         }
         else if(pBangun == 3){
             daerah[area].bangunan[nomorlahan].nama = "Pengumpulan Scrap";
             daerah[area].bangunan[nomorlahan].pKayu = 0;
             daerah[area].bangunan[nomorlahan].pBatu = 0;
             daerah[area].bangunan[nomorlahan].pScrap = 6;
             break;
         }
         else if (pBangun == 0){
          return;
         }
         
         else{
             cout << "Pilih yang ada\n";
         }
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
    cout << "|          "<< daerah[i].nama <<"          |" << endl;
    garis (39);
    for(int j=0; j<4; j++){
      cout<< j+1 <<". Lahan "<< daerah[i].bangunan[j].nama <<endl;
    }
    cout<< "0. Kembali "<<endl;
    garis (39);
    statistikArea(i);
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


void area(string username){
  int pArea;
  while (true)
  {
    system("cls");
    header(username);
    garis(39);
    cout << "|           Act 1 - Arriola Port          |" << endl;
    garis (39);
    for(int i = 0; i<5; i++){
      cout<< i+1 <<". "; if (daerah[i].unlock){cout<< daerah[i].nama;}
      else cout<<"(Terkunci)";
      cout<<endl;
    }
    cout<< "6. Next Turn"<<endl;
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
                continue;
    }

    else if (pArea == 2)
    {
      if (daerah[1].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                continue;
    }

    else if (pArea == 3)
    {
      if (daerah[2].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                continue;
    }

    else if (pArea == 4)
    {
      if (daerah[3].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                continue;
    }

    else if (pArea == 5)
    {
      if (daerah[4].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                continue;
    }

    else if (pArea == 6)
    { 
      PerhitunganSumberDaya(username);
      updateBuilding(username);
      updatePlayer(username);
      system("cls");
      continue;
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
  cout << "Welcome to Arriola Port" << endl;
  garis(25);
  cout << "\nketik enter atau apa saja untuk melanjutkan..."; getline(cin,baca1) ; cout<<endl ;
  
  for (auto &p : players)
  {
    if (p.nama.empty() == true)
    {
      cout << "Karena ini pertama kalinya,";
    }
  }
  membaca(username);
  sapa(username);
  area(username);
}

void turn(){

}

int main(){
  string nama = newGame();
  mainCity(nama);
}