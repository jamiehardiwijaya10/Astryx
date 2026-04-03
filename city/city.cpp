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

void AreaLock(){
  daerah[0].nama = "Ariolla Monument";
  daerah[0].unlock = true;
  
  daerah[1].nama = "Village of Purification";
  daerah[1].unlock = false;
  
  daerah[2].nama = "Masonwood";
  daerah[2].unlock = false;

  daerah[3].nama = "Rovenilla";
  daerah[3].unlock = false;

  daerah[4].nama = "Moncini Basin";
  daerah[4].unlock = false;
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
  file2 << nama  << ", Arriola Monument, "<< 1 <<", Kosong, Kosong, Kosong, Kosong "<< endl;
  file2 << nama  << ", Village Of Purification, "<< 1 <<", Kosong, Kosong, Kosong, Kosong "<< endl;
  file2 << nama  << ", Masonwood, "<<1<<", Kosong, Kosong, Kosong, Kosong "<< endl;
  file2 << nama  << ", Rovenilla, "<<1<<", Kosong, Kosong, Kosong, Kosong "<< endl;
  file2 << nama  << ", Moncini Basin, "<<1<<", Kosong, Kosong, Kosong, Kosong "<< endl;
  file2.close();


  return nama;
}

void membaca(string username){
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

void header(string username){
  for (auto &p : players)
  {
    if (p.nama == username)
    {
      //system("cls");
      cout << "[Token = " << p.token << "]                [" << "Turn ke-" << p.turn << "]"<< endl;
      garis(39);
      cout << "| Kayu: "<< p.kayu << "| Batu: "<< p.batu << "| Scrap: "<< p.scrap <<" |"<<endl;
    }
  }
}


void lahanKosong(){
    cout<< "Lahan 1"<<endl;
    cout<< "Lahan 2"<<endl;
    cout<< "Lahan 3"<<endl;
    cout<< "Lahan 4"<<endl;
    cout<< "Pilih lahan"<<endl;
}

void area(string username){
  AreaLock();
  int pArea;
  do{
    system("cls");
    //cout << "[Token = " << p.token << "]                [" << "Turn ke-" << p.turn << "]"<< endl;
    //garis(39);
    //cout << "| Kayu: "<< p.kayu << "| Batu: "<< p.batu << "| Scrap: "<< p.scrap <<" |"<<endl;
    header(username);
    garis(39);
    cout << "|           Act 1 - Arriola Port          |" << endl;
    garis (39);
    for(int i = 0; i<5; i++){
      cout<< i+1 <<". "; if (daerah[i].unlock){cout<< daerah[i].nama;}
      else cout<<"(Terkunci)";
        cout<<endl;
      }
      cout<< "0. Kembali"<<endl;
      garis (39);
      cout <<"Pilih Area:"; cin>>pArea;
      switch(pArea){
            case 1:
                system("cls");
                cout<<"Selamat datang di Ariolla Monument\n "<< endl;
                header(username);
                garis(39);
                cout << "|         Arriola Monument        |" << endl;
                garis (39);
                
                break;           
            case 2:
                header(username);
                cout<<"Selamat datang di Village of Purification"<< endl;
                break;           
            case 3:
                header(username);
                cout<<"Selamat datang di Rovenila"<< endl;
                break;           
            case 4:
                header(username);
                cout<<"Selamat datang di Moncini Basin"<< endl;
                break;
            case 5:
                header(username);
                cout<<"Selamat datang di Masonwood"<< endl;
                break;
            case 0:
                break;
            default: 
                cout<<"Silahkan pilih kota yang tersedia"<<endl;
              }
            } while(pArea<0 || pArea>5);
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
  

  sapa(username);
  area(username);
}

int main(){
  string nama = newGame();
  mainCity(nama);
}