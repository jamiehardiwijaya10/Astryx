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
vector <Area> city; 
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

void lahanKosong(){
  
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
  ofstream file2("../../databases/building.txt", ios::app);
  if (!file2.is_open())
  {
    cout << "File gaada";
  }
  file2 << "ArriolaPort ArriolaMonument Kosong Kosong Kosong Kosong " << nama << endl;
  file2.close();


  return nama;
}

void membaca(){

  ifstream file("../../databases/playerresources.txt");
  string line;
  getline(file, line);
  while (getline(file, line)) {
      stringstream hmm(line);
      SumberDaya p;
      hmm >> p.nama >> p.kayu >> p.batu >> p.scrap >> p.token >> p.turn;
      players.push_back(p);
    }
    

    file.close();
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
      garis(39);
      cout << "|         Act 1 - Arriola Port        |" << endl;
      garis (39);
    }
  }
}

void area(string username){
  AreaLock();
  int pArea;
  do{
    //system("cls");
    //cout << "[Token = " << p.token << "]                [" << "Turn ke-" << p.turn << "]"<< endl;
    //garis(39);
    //cout << "| Kayu: "<< p.kayu << "| Batu: "<< p.batu << "| Scrap: "<< p.scrap <<" |"<<endl;
    //garis(39);
    //cout << "|         Act 1 - Arriola Port        |" << endl;
    //garis (39);
    header(username);
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
                //header(username);
                cout<<"Selamat datang di Ariolla Monument "<< endl;
                garis(39);
                
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
  string hmm;
  system("cls");
  garis(20);
  cout << "   CITY BUILDING\n   Welcome " << username << "!" << endl;
  garis (20);
  cout << "Ketik enter untuk melanjutkan...."; getline(cin, hmm);
}

void mainCity(string username){
    string hmm;
    garis(25);
    cout << "Welcome to Arriola Port" << endl;
    garis(25);
    cout << "\nketik enter atau apa saja untuk melanjutkan..."; getline(cin,hmm) ; cout<<endl ;

  membaca();
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