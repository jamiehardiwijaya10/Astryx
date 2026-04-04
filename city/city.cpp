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

// void updateData(string username){
//   if(username == p.nama){
//     ofstream tulis1("../databases/playerresources.txt");
//     tulis1<< p.nama <<" " 
//           << p.kayu+ daerah[0].bangunan[0] <<" " 
//           << p.batu <<" "
//           << p.scrap<<" "
//           << p.token<<" "
//           << p.turn <<ENDL;
//   }
// }


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

// void bangunLahan(){
//   int pBangun;
//   do{  
//     cout << "Pilih bangunan:";
//     cout << "1. Penebangan Kayu"<<endl;
//     cout << "2. Penambangan Batu"<<endl;
//     cout << "3. Pengumpulan Scrap"<<endl;
//     cout << "0. Batal"<<endl;
//     cout <<"Pilih Pembangunan pada lahan: ";cin<<pBangun;
//     switch(pBangun)
//     {
//         case 1:
//             daerah[i].bangunan[lahanIndex].nama = "Kayu";
//             daerah[areaIndex].bangunan[lahanIndex].pKayu = 10;
//             daerah[areaIndex].bangunan[lahanIndex].pBatu = 0;
//             daerah[areaIndex].bangunan[lahanIndex].pScrap = 0;
//             break;

//         case 2:
//             daerah[areaIndex].bangunan[lahanIndex].nama = "Batu";
//             daerah[areaIndex].bangunan[lahanIndex].pKayu = 0;
//             daerah[areaIndex].bangunan[lahanIndex].pBatu = 8;
//             daerah[areaIndex].bangunan[lahanIndex].pScrap = 0;
//             break;

//         case 3:
//             daerah[areaIndex].bangunan[lahanIndex].nama = "Scrap";
//             daerah[areaIndex].bangunan[lahanIndex].pKayu = 0;
//             daerah[areaIndex].bangunan[lahanIndex].pBatu = 0;
//             daerah[areaIndex].bangunan[lahanIndex].pScrap = 6;
//             break;

//         case 0:
//             break;

//         default:
//             cout << "Pilihan salah\n";
//     }
//   }
// }

void lahanKosong(string username,int i){
  int pLahan;
  do{
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
    cout<<"Statistik Area:"<<endl;
    cout<<"Kayu = "<<"/Turn" <<endl;
    cout<<"Batu = "<<"/Turn" <<endl;
    cout<<"Scrap= "<<"/Turn" <<endl;
    garis (39);
    cout<< "Pilih lahan: ";cin>>pLahan;
    switch(pLahan){
      case 1:
        cout<< "1. Kembali "<<endl;
        break;
      case 2:
        cout<< "2. Kembali "<<endl;
        break;
      case 3:
        cout<< "3. Kembali "<<endl;
        break;
      case 4:
        cout<< "4. Kembali "<<endl;
        break;
      case 0:
        break;
      default:
        cout<<"Silahkan pilih lahan yang tersedia"<<endl;
    }
  } while(pLahan<1 || pLahan>4);
}

void area(string username){
  int pArea;
  do{
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
      cout<< "0. Kembali"<<endl;
      garis (39);
      cout <<"Pilih Area: "; cin>>pArea;
      switch(pArea){
            case 1:
            if (daerah[0].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                break;           
            case 2:
            if (daerah[1].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                break;           
            case 3:
            if (daerah[2].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                break;           
            case 4:
            if (daerah[3].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                break;
            case 5:
            if (daerah[4].unlock)
              {
                lahanKosong(username,pArea-1);
              }
            else cout<<"Maaf, Area ini masih terkunci";
                break;
            case 0:
                break;
            default: 
                cout<<"Silahkan pilih kota yang tersedia"<<endl;
    }
  } while(pArea<1 || pArea>5);
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

int main(){
  string nama = newGame();
  mainCity(nama);
}