#include <iostream>
#include <windows.h>
#include "../utils/helper.cpp"
using namespace std;

int prologue() {
    system("cls");

    title("PROLOGUE");

    typing("Demirgus University, 22 September 1891", 40);
    Sleep(800);

     if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Di dalam kota yang ramai dan penuh kehidupan.", 35);
    typing("Seseorang sedang memperhatikan koral di pelabuhan.", 35);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Apakah ini sebuah fenomena baru? Kenapa koral ini berwarna merah?\"", 50);
    typing("Ucap seorang peneliti yang sedang memeriksa koral tersebut.", 40);
    Sleep(500);

    system("cls");
    typing("\"Koral yang sebelumnya berwarna putih kini berubah menjadi merah muda.\"", 40);
    typing("\"Mungkin fenomena The Red Tide merubah warnanya\"\n", 40);
    Sleep(500);
    typing("Note : The Red Tide adalah fenomena alam dimana alam merubah dirinya sendiri menjadi sesuatu yang lebih berbahaya dan merusak. The Red Tide bisa merubah segala sesuatu yang ada di alam, termasuk makhluk hidup, menjadi sesuatu yang lebih berbahaya dan merusak.", 40);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");
    typing("\"Hei Elias! Apakah koral disana juga berubah warna?\"", 40);
    typing("Seseorang berteriak ke peneliti tersebut dari kejauhan.\n", 40);
    Sleep(500);

    typing("Elias Vermont, seorang peneliti muda yang sedang bekerja di pelabuhan, mendengar teriakan tersebut dan segera berlari ke arah sumber suara.", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Kenapa kamu bertanya? Apakah ada yang salah dengan koral disini?\"", 40);
    typing("Elias bertanya dengan penuh kekhawatiran.\n", 40);
    Sleep(500);
    typing("\"Koral disana juga berubah warna menjadi merah.\"", 40);
    typing("Tambah Elias dengan tenang.\n", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Kenapa kau sangat tenang begitu? Apakah kamu sudah tahu apa yang terjadi?\"", 40);
    typing("Tanya rekan Elias dengan nada penasaran.\n", 40);
    Sleep(500);
    typing("\"Aku sudah melihat fenomena ini sebelumnya. Ini adalah tanda bahwa The Red Tide sedang menyebar.\"", 40);
    typing("Jawab Elias dengan serius.\n", 40);
    Sleep(500);
    typing("\"The Red Tide bisa sangat berbahaya bagi kehidupan laut dan manusia. Kita harus laporkan hasil ini ke Demirgus Laboratory\"", 40);
    typing("Saran Elias kepada rekannya.\n", 40);
    typing("\"Kau sepertinya sangat tenang menghadapi situasi ini. Sebaiknya kau jelaskan kepadaku nanti apa itu The Red Tide.\"", 40);
    typing("Rekan Elias berbicara dengan perasaan kesal sambil bergurau.\n", 40);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Di Demirgus Laboratory........", 40);
    Sleep(800);

     if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Akhirnya selesai juga, tapi The Red Tide masih menyimpan misteri yang membuatku penasaran.\"", 40);
    typing("Elias berbicara pada dirinya sendiri sambil memeriksa data yang telah dikumpulkan.\n", 40);
    Sleep(500);
    typing("\"Hei! Sebaiknya kau beritahu dulu padaku apa itu The Red Tide.\"", 40);
    typing("Permintaan rekan Elias yang masih kesal.\n", 40);
    Sleep(500);
    typing("\"Rumit tapi asik. Aku akan jelaskan nanti.\"", 40);
    typing("Elias menjawab dengan santai sambil tersenyum.\n", 40);
    Sleep(500);
    typing("\"Hei kau sudah berjanji yang tadi!\"", 40);
    typing("Rekan Elias kembali mengingatkan dengan nada kesal.\n", 40);
    Sleep(500);
    typing("\"Aku harus menelitinya lebih dalam dulu. Ini masih teoriku saja.\"", 40);
    typing("Elias menjawab dengan serius sambil menatap data yang ada di depannya.\n", 40);
    Sleep(500);
    typing("\"Baiklah, tapi jangan lupa jelaskan nanti ya!\"", 40);
    typing("Rekan Elias berbicara dengan nada kesal bergurau sambil meninggalkan Lab. \n", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Elias kembali fokus pada penelitiannya, mencoba mencari tahu lebih banyak tentang fenomena The Red Tide yang sedang menyebar dengan cepat.", 40);
    typing("Namun, waktu semakin berlalu dan Elias belum menemukan jawaban yang memuaskan. Dia mulai merasa frustasi dan putus asa.", 40);
    typing("Tanpa ia sadari, waktu semakin malam....", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Elias, ini sudah malam. Kamu harus istirahat.\"", 40);
    typing("Ucap seorang professor Demirgus yang tiba-tiba datang ke tempat Elias\n", 40);
    Sleep(500);
    typing("\"Ah Professor Lucia, aku hanya ingin menyelesaikan penelitianku ini. Aku yakin aku sudah dekat dengan jawabannya.\"", 40);
    typing("Elias menjawab dengan penuh semangat.\n", 40);
    Sleep(500);
    typing("\"Elias, aku tahu kamu sangat berdedikasi dengan penelitianmu, tapi kamu terlalu sering bekerja seperti ini selama 3 bulan. Kamu tidak akan bisa menyelesaikan penelitiannya jika kamu sakit.\"", 40);
    typing("Professor Lucia berbicara dengan nada khawatir.\n", 40);
    Sleep(500);
    typing("\"Aku sarankan kamu pulang dan ambil libur besok. Aku yakin kamu akan menemukan jawabannya dengan pikiran yang lebih segar.\"", 40);
    typing("Professor Lucia memberikan saran dengan nada lembut.\n", 40);
    Sleep(500);
    typing("\"Kamu juga sudah terlalu lama tidak keluar dari lab. Bahkan semenjak kamu berkuliah kesini kamu belum pulang ke kota asalmu.\"", 40);
    typing("Professor Lucia menambahkan dengan nada khawatir.\n", 40);
    Sleep(500);
    typing("\"Apakah professor menyaranku untuk pulang ke rumah?\"", 40);
    typing("Elias bertanya dengan nada satir.\n", 40);
    Sleep(500);
    typing("\"Ya, aku menyarankan kamu untuk pulang ke rumah. Aku yakin kamu akan menemukan jawabannya dengan pikiran yang lebih segar.\"", 40);
    typing("Professor Lucia memberikan saran dengan nada lembut.\n", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");
    typing("Pelabuhan Elpis, 23 September 1891", 40);
    Sleep(800);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("\"Aku tidak yakin pulang ke rumah dengan rasa penasaran dapat menjernihkan pikiranku. Lagipula, sudah tidak ada siapa siapa di sana.\"", 40);
    typing("\"Tapi apa boleh buat, aku harus mengikuti saran professor.\"", 40);
    typing("\"Mungkin The Red Tide sudah menyebar juga ke Morivelle. Jika iya, aku bisa meneliti dengan suasana lebih baru.\"", 40);
    typing("\"Bahkan bisa saja ada temuan baru disana.\"", 40);
    typing("Gumam Elias dengan nada optimis.\n", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Seorang nelayan berdiri di samping kapalnya, memperhatikan Elias dari jauh.", 40);
    typing("\"Kau mau ke mana?\" tanya seorang nelayan.\n", 40);
    Sleep(500);
    typing("\"Morivelle.\" jawab Elias dengan singkat.\n", 40);
    Sleep(500);
    typing("\"Morivelle? Apa kau penduduk dari sana?\" tanya nelayan dengan nada penasaran.\n", 40);
    Sleep(500);
    typing("\"Ya, aku berasal dari sana. Aku hanya ingin pulang untuk sementara waktu.\" jawab Elias dengan nada datar.\n", 40);
    Sleep(500);
    typing("\"Sudah berapa lama kau disini?\" tanya nelayan dengan nada penasaran.\n", 40);
    Sleep(500);
    typing("\"Sudah hampir 5 tahun.\" jawab Elias dengan nada datar.\n", 40);
    Sleep(500);
    typing("\"Oh, jadi kau sudah lama tidak pulang ke sana?\" tanya nelayan dengan nada penasaran.\n", 40);
    typing("\"Pantas saja kau mau kesana. Sepertinya kau tidak tahu.\"\n", 40);
    Sleep(500);
    typing("\"Maksudnya?\" tanya Elias dengan nada penasaran.\n", 40);
    typing("\"Morivelle sudah lama tidak bisa diakses. Sejak 5 tahun yang lalu, sudah tidak ada kapal yang berani ke sana karena banyaknya kabut tebal yang menyelimuti pulau itu.\"\n", 40);
    typing("\"Bahkan kabarnya kota itu sudah musnah karena kabut itu.\"\n", 40);
    Sleep(500);
    typing("\"Kau yakin?\" tanya Elias dengan nada penasaran.\n", 40);
    typing("\"Ya, aku yakin. Aku sudah mendengar banyak cerita tentang itu.\"\n", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Elias terdiam sejenak, mencoba mencerna informasi yang baru saja dia dapatkan. Dia merasa sedikit panik, tapi dia juga merasa penasaran dengan apa yang sebenarnya terjadi di Morivelle.", 40);
    typing("\"Apakah ini ada hubungannya dengan The Red Tide? Apakah kabut itu juga disebabkan oleh fenomena itu?\" Gumaman Elias dalam hati.", 40);
    Sleep(500);
    typing("\"Apakah kau bisa mengantarku kesana?\" tanya Elias dengan nada serius.\n", 40);
    typing("\"Aku tidak bisa. Aku sudah terlalu tua untuk berlayar ke sana.\"\n", 40);
    typing("\"Jika kau benar-benar ingin ke sana, kau bisa mengunakan kapalku yang disana tapi harganya sedikit mahal. Kau juga harus pergi sendiri karena aku tidak bisa mengantarmu.\"\n", 40);
    Sleep(500);
    typing("\"Baiklah, aku akan pergi sendiri. Tolong beritahu aku harganya.\"\n", 40);
    Sleep(500);
    typing("\"Harganya 100 token.\"\n", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("Tanpa pikir panjang, Elias membayar biaya untuk membeli kapal tersebut. Selain perasaan penasarannya yang sangat besar, dia juga mulai merindukan kota masa kecilnya.", 40);
    typing("Elias pun segera bersiap untuk berlayar ke Morivelle.", 40);
    Sleep(500);

    if (waitOrSkip()) {
        return 0;
    }

    system("cls");

    typing("To Be Continued...", 100);
    return 0;
}

int main() {
    prologue();
    return 0;
}