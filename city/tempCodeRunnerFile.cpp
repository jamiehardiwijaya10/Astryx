
// void updateData(string username){
//   ifstream file("../databases/playerresources.txt");
//   string line;
//   getline(file, line);
//   while (getline(file, line)) {
//       stringstream baca1(line);
//       SumberDaya p;
//       baca1 >> p.nama >> p.kayu >> p.batu >> p.scrap >> p.token >> p.turn;
//       players.push_back(p);
//     }
//   file.close();

//   offstream tulis1("../databases/playerresources.txt");
  


//   ifstream file2("../databases/building.txt");
//   int i = 0;
//   while (getline(file2, line)) {
//         stringstream baca2(line);
//         string name;
//         string areaName;
//         string unlockStatus;
//         string l1,l2,l3,l4;

//         getline(baca2, name, ',');
//         getline(baca2, areaName, ',');
//         getline(baca2, unlockStatus, ',');
//         getline(baca2, l1, ',');
//         getline(baca2, l2, ',');
//         getline(baca2, l3, ',');
//         getline(baca2, l4);

//         if (name == username && i < 5){

//             daerah[i].nama = areaName;

//             daerah[i].unlock = (unlockStatus == "1");

//             daerah[i].bangunan[0].nama = l1;
//             daerah[i].bangunan[1].nama = l2;
//             daerah[i].bangunan[2].nama = l3;
//             daerah[i].bangunan[3].nama = l4;

//             i++;
//           }
//         }
//   file2.close();
//   if(username == p.nama){
//     ofstream tulis2("../databases/playerresources.txt");
//     tulis2<< p.nama <<" " 
//           << p.kayu+ daerah[0].bangunan[0] <<" " 
//           << p.batu <<" "
//           << p.scrap<<" "
//           << p.token<<" "
//           << p.turn <<endl;
//   }
// }