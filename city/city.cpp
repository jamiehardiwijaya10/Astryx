#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

struct sumberDaya
{
  string nama;
  int kayu;
  int batu;
  int scrap;
  int token;
  int turn;
};

struct lahan
{
  string nama;
  int bkp;
  int bbp;
  int bbs;
  int pk;
  int pb;
  int ps;
};

struct elkota
{
  string nama;
  lahan lahans[4];
};



//PEKTOR as Bucketk
vector <elkota> city; 
vector <sumberDaya> players;

void garis(int ukuran){
  int pilihan = 0;
  pilihan += ukuran;
  cout << string(int(pilihan),'=') << endl;
  pilihan = 0;
}

string newGame(){
  string nama;


  //Tamvbah ke resources
  ofstream file("../../databases/playerresources.txt", ios::app); //appendlibel
  if (!file.is_open())
  {
    cout << "File tidak ada" << endl;
  }
  cout << "Masukkan Username: "; getline(cin,nama); cout << endl;
       
  file << nama << " " << "1000 1000 1000 10 1" << endl;
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
      sumberDaya p;
      hmm >> p.nama >> p.kayu >> p.batu >> p.scrap >> p.token >> p.turn;
      players.push_back(p);
    }
    

    file.close();
}

void area(string username){
  membaca();
  for (auto &p : players)
  {
    if (p.nama == username)
    {
      system("cls");
      cout << "[Token = " << p.token << "] [" << "Turn ke-" << p.turn << "]"<< endl;
      garis(24);
      cout << "  Act 1 - Arriola Port  " << endl;
      garis (24);

    } 
  }
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