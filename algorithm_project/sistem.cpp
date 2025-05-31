#include <iostream>
#include <fstream>
using namespace std;
// unsigned = angka positif saja, tanpa negatif

struct Buku {
    unsigned int id;
    string judul;
    string penulis;
    int tahun_terbit;
    static unsigned int last_id_buku; // berbagi nilai antar semua objek

    // Constructor to initialize the id
    Buku() : id(++last_id_buku) {}
};
unsigned int Buku::last_id_buku = 110;

struct Pekerjaan {
    string role;
};

struct Anggota {
    unsigned int id;
    Pekerjaan role;
    string nama;
    string alamat;
    char telepon[15];
    static unsigned int last_id_anggota;

    // Constructor to initialize the id
    Anggota() : id(++last_id_anggota) {}
};
unsigned int Anggota::last_id_anggota = 120;


struct Peminjaman {
    unsigned int idPeminjam;
    string judul_buku;
    string nama_anggota;
    string tanggal_pinjam;
    string tanggal_kembali;
    static unsigned int last_id_peminjam;

    // Constructor to initialize the idPeminjam
    Peminjaman() : idPeminjam(++last_id_peminjam) {}
};
unsigned int Peminjaman::last_id_peminjam = 310;

struct Login{
  string 
    username,
    password,
    peran;
};


void menu_admin();
void menu_user();

void loginpage();
void login();
void admin();
void user();
void buat_akun();

// ini bagian untuk membuat data
void menu_Create();
void menu_create_user();
void create_buku();
void create_anggota();
void create_peminjaman();

// ini bagian untuk membaca data
void menu_Read();
void read_buku(int index);
void read_anggota(int index);
void read_peminjaman(int index);
void menu_read_user();

// ini bagian untuk memperbarui data
void menu_Update();
void update_buku();
void update_anggota();
void update_peminjaman();

// ini bagian untuk menghapus data
void menu_Delete();
void delete_buku();
void delete_anggota();
void delete_peminjaman();

void menu_sorting();
void sorting_buku_tahunTerbit_DESC();
void sorting_anggota();
void sorting_peminjaman();

void menu_search();
void search_buku();
void search_anggota();
void search_peminjaman();

void read_file();
void read_fileAkun();
void read_fileBuku();
void read_fileAnggota();
void read_filePeminjaman();

bool checkUsername(string username);

Login UsAd[100];// UsAd = user admin
Buku daftarBuku[100];
Anggota daftarAnggota[100];
Peminjaman daftarPeminjaman[100];
int jumlahBuku = 0, jumlahAnggota = 0, jumlahPeminjaman = 0, jumlahAkun = 0;
bool check; // check ID in func create peminjaman 
int main() {
    while (true) { // Keep the application running until the user exits
      read_file();  
      loginpage();
    }
    return 0;
}

void read_file(){
  read_fileAkun();
  read_fileBuku();
  read_fileAnggota();
  read_filePeminjaman();
}

void read_fileAkun(){
  ifstream myfile("jumlahakun");
  if(myfile.is_open()){
    myfile >> jumlahAkun;
    myfile.close();
  }

  ifstream file("akun.txt");
  if(file.is_open()){
    for(int i = 0; i < jumlahAkun; i++){
      file >> UsAd[i].username;
      file >> UsAd[i].password;
      file >> UsAd[i].peran;
    }
    file.close();
  }
}

void read_fileBuku(){
  ifstream myfile("jumlahbuku");
      if (myfile.is_open()) {
        myfile >> jumlahBuku;
        myfile.close();
    }

  ifstream file("dataBuku.txt");
  if(file.is_open()){
    for(int i = 0; i < jumlahBuku; i++){
      file >> daftarBuku[i].id;
      file.ignore();
      getline(file, daftarBuku[i].judul);
      getline(file, daftarBuku[i].penulis);
      file >> daftarBuku[i].tahun_terbit;
      file.ignore();
    }
    file.close();
  }
  
}

void read_fileAnggota(){
  ifstream myfile("jumlahAnggota");
      if (myfile.is_open()) {
        myfile >> jumlahAnggota;
        myfile.close();
    }

  ifstream file("dataAnggota.txt");
  if(file.is_open()){
      for(int i = 0; i < jumlahAnggota; i++){
      file >> daftarAnggota[i].id;
      file.ignore();
      getline(file, daftarAnggota[i].nama);
      getline(file, daftarAnggota[i].role.role);
      getline(file, daftarAnggota[i].alamat);
      file >> daftarAnggota[i].telepon;
      file.ignore();
    }
      file.close();
  }
}

void read_filePeminjaman(){
  ifstream myfile("jumlahPeminjaman");
      if (myfile.is_open()) {
        myfile >> jumlahPeminjaman;
        myfile.close();
    }

  ifstream file("dataPeminjaman.txt");
  if(file.is_open()){
    for(int i = 0; i < jumlahPeminjaman; i++){
      file >> daftarPeminjaman[i].idPeminjam;
      file.ignore();
      getline(file, daftarPeminjaman[i].judul_buku);
      getline(file, daftarPeminjaman[i].nama_anggota);
      getline(file, daftarPeminjaman[i].tanggal_pinjam);
      getline(file, daftarPeminjaman[i].tanggal_kembali);
    }
    file.close();
  }
}

void loginpage() {
    int pilih;
    cout << "Login sebagai:" << endl;
    cout << "1. Login" << endl;
    cout << "2. Buat akun" << endl;
    cout << "3. Exit" << endl;
    cout << "Jawab: ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            login(); // Proceed to login menu
            break;
        case 2:
            buat_akun(); // Proceed to create account menu
            break;
        case 3:
            cout << "Terima kasih telah menggunakan aplikasi ini." << endl;
            exit(0); // Exit the application
        default:
            cout << "Input tidak valid." << endl;
            break;
    }
}

void login(){
  string username, password;
  string veriPass, veriUsern, veriPeran;
  bool check = false;

    for(int i = 2 ; i >= 0 ; i--){
        ifstream login;
        login.open("akun.txt");
        cout<<"\nMasukan Username anda \t: ";
        cin>>username;
        cout<<"Masukan Password anda \t: ";
        cin>>password;
        while(!login.eof()){
            login >> veriUsern;
            login >> veriPass;
            login >> veriPeran;
            if((veriUsern == username) && (veriPass == password)){
                cout<<endl<<"anda berhasil login"<<endl<<endl;
                check = true;
                break;
            }
        }
        if((i == 0) && (!check)){
            cout<<"Kesempatan Login anda Habis, Silahkan Coba Kembali Lain Kali"<<endl;
            exit(0);
        }else if(!check){
            cout<<"Username atau Password anda salah"<<endl;
            cout<<"Anda Masih memiliki "<< i <<" kesempatan lagi"<<endl;
            cout<<"Silahkan mengisi kembali"<<endl;
            cout<<endl;
        }
         if (check){
            break;
        }
        login.close();
    }
    if(veriPeran == "user")menu_user();
    else if(veriPeran == "admin")menu_admin();
}

void buat_akun(){
  string peran, username;
  int siapa;
  cout << "Peran " << endl;
  cout << "1. user " << endl;
  cout << "2. admin " << endl;

  cout << "siapa anda? : ";
  cin>>siapa;
    if(siapa == 1){
      UsAd[jumlahAkun].peran = "user";
    }
    else {
      UsAd[jumlahAkun].peran = "admin";
    }
    //check username
    bool check = false;
    do{
    cout    <<"Masukan Username Anda : ";
    cin     >> username;
    if(checkUsername(username)){
      cout << "Username sudah ada!" << endl;
    }else{
      check = true;
      UsAd[jumlahAkun].username = username;
    }
    }while(!check);

    cout    <<"Masukan Password Anda : ";
    cin     >> UsAd[jumlahAkun].password;

    ofstream akun;
    akun.open("akun.txt", ios::app);
    akun    << UsAd[jumlahAkun].username;
    akun    << endl;
    akun    << UsAd[jumlahAkun].password;
    akun    << endl;
    akun    << UsAd[jumlahAkun].peran;
    akun    << endl;

    jumlahAkun ++;
    if(akun){
        cout<<"\nSelamat Akun anda sudah di buat"<<endl;
        cout<<"Silahkan Lanjut ke menu login"<<endl;
        loginpage();
    }else{
        cout<<"Terjadi kesalahan, silahkan coba lagi"<<endl;
    }
    akun.close();

    ofstream myfile("jumlahakun");
    if(myfile.is_open()){
      myfile << jumlahAkun;
      myfile.close();
    }
}

bool checkUsername(string username){
  for(int i = 0; i < jumlahAkun; i++){
    if(UsAd[i].username == username){
      return true;
    }
  }
  return false;
}

void menu_user() {
    int pilih;
    char jawab;

    do {
        cout << "\nWelcome" << endl;
        cout << "1. Create data diri" << endl;
        cout << "2. Lihat peminjaman" << endl;
        cout << "3. Logout" << endl; // Changed "Exit" to "Logout"
        cout << "Pilih menu: ";
        cin >> pilih;

        switch (pilih) {
            case 1:
                menu_create_user();
                break;
            case 2:
                if (jumlahPeminjaman == 0) {
                    cout << "Tidak ada data peminjaman." << endl;
                } else {
                    menu_read_user();
                }
                break;
            case 3:
                cout << "Anda telah logout." << endl;
                return; // Return to the login screen
            default:
                cout << "Input tidak valid" << endl;
                break;
        }
        cout << "Ingin lanjut (y/n): ";
        cin >> jawab;
    } while (jawab == 'y');
}

void menu_admin() {
    int choose;
    char jawab;

    do {
        cout << "\nWelcome" << endl;
        cout << "1. Create" << endl;
        cout << "2. Read" << endl;
        cout << "3. Sorting" << endl;
        cout << "4. Delete" << endl;
        cout << "5. Update" << endl;
        cout << "6. Search" << endl;
        cout << "7. Logout" << endl; // Changed "Exit" to "Logout"
        cout << "Pilih menu: ";
        cin >> choose;

        switch (choose) {
            case 1:
                menu_Create();
                break;
            case 2:
                menu_Read();
                break;
            case 3:
                menu_sorting();
                break;
            case 4:
                menu_Delete();
                break;
            case 5:
                int updateChoice;
                cout << "\nMenu Update" << endl;
                cout << "1. Update Buku" << endl;
                cout << "2. Update Anggota" << endl;
                cout << "3. Update Peminjaman" << endl;
                cout << "Pilih menu: ";
                cin >> updateChoice;
                switch (updateChoice) {
                    case 1:
                        update_buku();
                        break;
                    case 2:
                        update_anggota();
                        break;
                    case 3:
                        update_peminjaman();
                        break;
                    default:
                        cout << "Input tidak valid" << endl;
                        break;
                }
                break;
            case 6:
                menu_search();
                break;
            case 7:
                cout << "Anda telah logout." << endl;
                return; // Return to the login screen
            default:
                cout << "Input tidak valid" << endl;
                break;
        }
        cout << "Ingin lanjut (y/n): ";
        cin >> jawab;
    } while (jawab == 'y');
}

void menu_create_user(){
  create_anggota();
}

void menu_Create(){
  int choose;
  cout << "\nMenu Create" << endl;
  cout << "1. Buku " << endl;
  cout << "2. Peminjaman " << endl;
  cout << "Pilih menu : ";
  cin >> choose;

  switch (choose){
    case 1:
      create_buku();
      break;
    case 2:
      create_peminjaman();
      break;
    default:
      cout << "Input tidak valid" << endl;
      break;
  }
}

void create_buku(){
  int dataygdiinput;

  cout << "Berapa data yang ingin di input? ";
  cin >> dataygdiinput;
  if(dataygdiinput < 1){
    cout << "Input tidak valid" << endl;
    return;
  }
  if(dataygdiinput + jumlahBuku > 100){
    cout << "Input melebihi batas" << endl;
    return;
  }

  ofstream file("dataBuku.txt", ios::app);
  if(!file){
      cout << "Gagal membuka file!" << endl;
      return;
    }

  for (int i = jumlahBuku ; i < dataygdiinput + jumlahBuku; i++){
    cout << "Buku ke-" << i + 1 << endl;
    cout << "Id buku\t\t: " << daftarBuku[i].id << endl;
    cin.ignore();
    cout << "Judul buku\t: ";
    getline(cin, daftarBuku[i].judul);
    cout << "Penulis buku\t: ";
    getline(cin, daftarBuku[i].penulis);
    cout << "Tahun terbit\t: ";
    cin >> daftarBuku[i].tahun_terbit;
    cout << endl;

    file << daftarBuku[i].id << endl;
    file << daftarBuku[i].judul << endl;
    file << daftarBuku[i].penulis << endl;
    file << daftarBuku[i].tahun_terbit << endl;
  }
  file.close();

  jumlahBuku += dataygdiinput;
  ofstream jumlah("jumlahbuku", ios::trunc);
  if(jumlah.is_open()){
    jumlah << jumlahBuku;
    jumlah.close();
  }else{
    cout << "Gagal menyimpan jumlah buku" << endl;
  }
}

void create_anggota(){
  if(jumlahAnggota >= 100){
    cout << "Data Penuh" << endl;
    return;
  }

  ofstream Anggota("dataAnggota.txt", ios::app);
  if(!Anggota){
    cout << "Gagal membuka file!" << endl;
    return; 
  }

  daftarAnggota[jumlahAnggota].id;
  cin.ignore();
  cout << "Nama\t\t: ";
  getline(cin, daftarAnggota[jumlahAnggota].nama);
  cout << "Pekerjaan\t: ";
  getline(cin, daftarAnggota[jumlahAnggota].role.role);
  cout << "Alamat\t\t: ";
  getline(cin, daftarAnggota[jumlahAnggota].alamat);
  cout << "Telepon\t\t: ";
  cin >> daftarAnggota[jumlahAnggota].telepon;
  cout << endl;

  Anggota << daftarAnggota[jumlahAnggota].id << endl;
  Anggota << daftarAnggota[jumlahAnggota].nama << endl;
  Anggota << daftarAnggota[jumlahAnggota].role.role << endl;
  Anggota << daftarAnggota[jumlahAnggota].alamat << endl;
  Anggota << daftarAnggota[jumlahAnggota].telepon << endl;

  Anggota.close();

  jumlahAnggota ++;
  ofstream myfile("jumlahAnggota", ios::trunc);
  if (myfile.is_open()) {
        myfile << jumlahAnggota;
        myfile.close();
    } else {
        cout << "Gagal menyimpan jumlah data!" << endl;
    }
}

void create_peminjaman(){
  int dataygdiinput;
  cout << "Berapa data yang ingin di input? ";
  cin >> dataygdiinput;
  if(dataygdiinput + jumlahPeminjaman > 100){
    cout << "Input melebihi batas" << endl;
    return;
  }
  if(dataygdiinput < 1){
    cout << "Input tidak valid" << endl;
    return;
  }
  
  ofstream borrow("dataPeminjaman.txt", ios::app);
  if(!borrow){
      cout << "Gagal buka file\n";
      return;
    }

  for (int i = jumlahPeminjaman; i < dataygdiinput + jumlahPeminjaman; i++){  
  cout << "Id peminjam\t: " << daftarPeminjaman[i].idPeminjam << endl;
  cin.ignore();
  
  do{
  check = false;
  cout << "Judul buku\t: ";
  cin >> daftarPeminjaman[i].judul_buku;
  cin.ignore();
  for(int j = 0; j < jumlahBuku; j++){
    if(daftarPeminjaman[i].judul_buku == daftarBuku[j].judul){
      check = true;
      break;
    }
  }
  if(!check){
    cout << "Buku tidak ditemukan." << endl;
  }
  }while(!check);

  do{
  check = false;
  cout << "Nama anggota\t: ";
  cin >> daftarPeminjaman[i].nama_anggota;
  cin.ignore();
  for(int j = 0; j < jumlahAnggota; j++){
    if(daftarPeminjaman[i].nama_anggota == daftarAnggota[j].nama){
      check = true;
      break;
    }
  }
  if(!check){
    cout << "Anggota tidak ditemukan." << endl;
  }
  }while(!check);

  cout << "Tanggal pinjam\t: ";
  getline(cin, daftarPeminjaman[i].tanggal_pinjam);
  cout << "Tanggal kembali\t: ";
  getline(cin, daftarPeminjaman[i].tanggal_kembali);
  cout << endl;

  borrow << daftarPeminjaman[i].idPeminjam << endl;
  borrow << daftarPeminjaman[i].judul_buku << endl;
  borrow << daftarPeminjaman[i].nama_anggota << endl;
  borrow << daftarPeminjaman[i].tanggal_pinjam << endl;
  borrow << daftarPeminjaman[i].tanggal_kembali << endl;
  }
  borrow.close();

  jumlahPeminjaman += dataygdiinput;
  ofstream myfile("jumlahPeminjaman", ios::trunc);
  if (myfile.is_open()) {
        myfile << jumlahPeminjaman;
        myfile.close();
    } else {
        cout << "Gagal menyimpan jumlah data!" << endl;
    }
}

void read_buku(int index = 0){
  if (index == 0){
    cout << "\nDaftar Buku" << endl;
  }
  if(index >= jumlahBuku) return;
  cout << "Id Buku\t\t: " << daftarBuku[index].id << endl;
  cout << "Judul\t\t: " << daftarBuku[index].judul << endl;
  cout << "Penulis\t\t: " << daftarBuku[index].penulis << endl;
  cout << "Tahun Terbit\t: " << daftarBuku[index].tahun_terbit << endl;
  cout << "----------------------\n";
  read_buku(index + 1);
}

void read_anggota(int index = 0){
  if (index == 0){
    cout << "\nDaftar Anggota" << endl;
  }
  if(index >= jumlahAnggota) return;
  cout << "Id Anggota\t: " << daftarAnggota[index].id << endl;
  cout << "Nama\t\t: " << daftarAnggota[index].nama << endl;
  cout << "Pekerjaan\t: " << daftarAnggota[index].role.role << endl;
  cout << "Alamat\t\t: " << daftarAnggota[index].alamat << endl;
  cout << "Telepon\t\t: " << daftarAnggota[index].telepon << endl;
  cout << "----------------------\n";
  read_anggota(index + 1);
}

void read_peminjaman(int index = 0){
  if (index == 0){
    cout << "\nDaftar Peminjaman" << endl;
  }
  if(index >= jumlahPeminjaman) return;
  cout << "Id Peminjam\t: " << daftarPeminjaman[index].idPeminjam << endl;
  cout << "Judul Buku\t: " << daftarPeminjaman[index].judul_buku << endl;
  cout << "Nama Anggota\t: " << daftarPeminjaman[index].nama_anggota << endl;
  cout << "Tanggal Pinjam\t: " << daftarPeminjaman[index].tanggal_pinjam << endl;
  cout << "Tanggal Kembali\t: " << daftarPeminjaman[index].tanggal_kembali << endl;
  cout << "----------------------\n";
  read_peminjaman(index + 1);
}

void menu_read_user(){
  string nama;
  cin.ignore();
  cout << "Masukkan nama anda : " ; 
  cin >> nama;

  //salinan peminjaman
  Peminjaman salinan_peminjam[100];
  bool found = false;
  for(int i = 0; i < jumlahPeminjaman; i++){
    salinan_peminjam[i] = daftarPeminjaman[i];
    if(daftarPeminjaman[i].nama_anggota.find(nama) != string::npos){
    cout << "Id Peminjam\t: " << salinan_peminjam[i].idPeminjam << endl;
    cout << "Judul Buku\t: " << salinan_peminjam[i].judul_buku << endl;
    cout << "Nama Anggota\t: " << salinan_peminjam[i].nama_anggota << endl;
    cout << "Tanggal Pinjam\t: " << salinan_peminjam[i].tanggal_pinjam << endl;
    cout << "Tanggal Kembali\t: " << salinan_peminjam[i].tanggal_kembali << endl;
    cout << "----------------------\n";
    found = true;
    }
  }
  if (!found) {
    cout << "Data peminjaman tidak ditemukan." << endl;
  }
}

void menu_Read(){
  int choose;
  cout << "\nMenu Read" << endl;
  cout << "1. Buku" << endl;
  cout << "2. Anggota" << endl;
  cout << "3. Peminjaman" << endl;
  cout << "Pilih menu: ";
  cin >> choose;

  switch (choose){
      case 1:
          if (jumlahBuku == 0) {
              cout << "Tidak ada data buku." << endl;
          } else {
              read_buku();
          }
          break;
      case 2:
          if (jumlahAnggota == 0) {
              cout << "Tidak ada data anggota." << endl;
          } else {
              read_anggota();
          }
          break;
      case 3:
          if (jumlahPeminjaman == 0) {
              cout << "Tidak ada data peminjaman." << endl;
          } else {
              read_peminjaman();
          }
          break;
      default:
          cout << "Input tidak valid" << endl;
          break;
  }
}

void sorting_buku_tahunTerbit_DESC(){
  // buat salinan array, agar setelah di sorting tidak mempengaruhi di func menu read
  Buku salinan_buku[100];
  for(int i = 0; i < jumlahBuku; i++){
    salinan_buku[i] = daftarBuku[i];
  }

  for(int i = 0; i < jumlahBuku; i++){
    for (int j = 0; j < jumlahBuku - i - 1; j++){
      if (salinan_buku[j].tahun_terbit < salinan_buku[j + 1].tahun_terbit){
        swap(salinan_buku[j], salinan_buku[j + 1]);
      }
    }
  }
  for(int i = 0; i < jumlahBuku; i++){
    cout << "Id Buku\t\t: " << salinan_buku[i].id << endl;
    cout << "Judul\t\t: " << salinan_buku[i].judul << endl;
    cout << "Penulis\t\t: " << salinan_buku[i].penulis << endl;
    cout << "Tahun Terbit\t: " << salinan_buku[i].tahun_terbit << endl;
    cout << "----------------------\n";
  }
}

void sorting_anggota(){// acending
  for(int i = 0; i < jumlahAnggota; i++){
    for (int j = 0; j < jumlahAnggota - i - 1; j++){
      if (daftarAnggota[j].nama > daftarAnggota[j + 1].nama){
        swap(daftarAnggota[j], daftarAnggota[j + 1]);
      }
    }
  }
  read_anggota();
}

void sorting_peminjaman(){ // acending
  for(int i = 0; i < jumlahPeminjaman; i++){
    for (int j = 0; j < jumlahPeminjaman - i - 1; j++){
      if (daftarPeminjaman[j].tanggal_pinjam > daftarPeminjaman[j + 1].tanggal_pinjam){
        swap(daftarPeminjaman[j], daftarPeminjaman[j + 1]);
      }
    }
  }
  read_peminjaman();
}

void menu_sorting(){
  int choose;
  cout << "\nMenu Sorting" << endl;
  cout << "1. Tahun Terbit Buku(DESC)" << endl;
  cout << "2. Nama Anggota(ASCD)" << endl;
  cout << "3. Tanggal Pinjam Peminjaman(ASCD)" << endl;
  cout << "Pilih menu: ";
  cin >> choose;
  switch (choose){
  case 1:
    if (jumlahBuku == 0) {
      cout << "Tidak ada data buku." << endl;
  } else {
      sorting_buku_tahunTerbit_DESC();
  }
  break;
  case 2:
    if (jumlahAnggota == 0) {
      cout << "Tidak ada data buku." << endl;
  } else {
    sorting_anggota();
  }
  break;
  case 3:
    if (jumlahPeminjaman == 0) {
      cout << "Tidak ada data buku." << endl;
  } else {
    sorting_peminjaman();
  }
    break;
  default:
    cout << "Input tidak valid" << endl;
    break;
  }
}

void menu_search() {
  int choose;
  cout << "\nMenu Search" << endl;
  cout << "1. Cari Buku" << endl;
  cout << "2. Cari Anggota" << endl;
  cout << "3. Cari Peminjaman" << endl;
  cout << "Pilih menu: ";
  cin >> choose;

  switch (choose){
    case 1:
      search_buku();
      break;
    case 2:
      search_anggota();
      break;
    case 3:
      search_peminjaman();
      break;
    default:
      cout << "Input tidak valid" << endl;
      break;
  }
}

void search_buku() {
  string keyword;
  cin.ignore();
  cout << "Masukkan judul buku yang dicari: ";
  getline(cin, keyword);

  bool found = false;
  for (int i = 0; i < jumlahBuku; i++) {
    if (daftarBuku[i].judul.find(keyword) != string::npos) {
      cout << "Id: " << daftarBuku[i].id << endl;
      cout << "Judul: " << daftarBuku[i].judul << endl;
      cout << "Penulis: " << daftarBuku[i].penulis << endl;
      cout << "Tahun Terbit: " << daftarBuku[i].tahun_terbit << endl;
      cout << "----------------------" << endl;
      found = true;
    }
  }
  if (!found) {
    cout << "Buku tidak ditemukan." << endl;
  }
}

void search_anggota() {
  string keyword;
  cin.ignore();
  cout << "Masukkan nama anggota yang dicari: ";
  getline(cin, keyword);

  bool found = false;
  for (int i = 0; i < jumlahAnggota; i++) {
    if (daftarAnggota[i].nama.find(keyword) != string::npos) {
      cout << "Id: " << daftarAnggota[i].id << endl;
      cout << "Nama: " << daftarAnggota[i].nama << endl;
      cout << "Pekerjaan: " << daftarAnggota[i].role.role << endl;
      cout << "Alamat: " << daftarAnggota[i].alamat << endl;
      cout << "Telepon: " << daftarAnggota[i].telepon << endl;
      cout << "----------------------" << endl;
      found = true;
    }
  }
  if (!found) {
    cout << "Anggota tidak ditemukan." << endl;
  }
}

void search_peminjaman() {
  int id;
  cout << "Masukkan ID peminjam: ";
  cin >> id;

  bool found = false;
  for (int i = 0; i < jumlahPeminjaman; i++) {
    if (daftarPeminjaman[i].idPeminjam == id) {
      cout << "Id Peminjam: " << daftarPeminjaman[i].idPeminjam << endl;
      cout << "Id Buku: " << daftarPeminjaman[i].judul_buku << endl;
      cout << "Id Anggota: " << daftarPeminjaman[i].nama_anggota << endl;
      cout << "Tanggal Pinjam: " << daftarPeminjaman[i].tanggal_pinjam << endl;
      cout << "Tanggal Kembali: " << daftarPeminjaman[i].tanggal_kembali << endl;
      cout << "----------------------" << endl;
      found = true;
    }
  }
  if (!found) {
    cout << "Data peminjaman tidak ditemukan." << endl;
  }
}

void menu_Delete(){
  int pilih;
  cout << "\nMenu Delete" << endl;
  cout << "1. Delete Buku" << endl;
  cout << "2. Delete Anggota" << endl;
  cout << "3. Delete Peminjaman" << endl;
  cout << "Pilih menu: ";
  cin >> pilih;
  switch (pilih) {
      case 1:
          delete_buku();
          break;
      case 2:
          delete_anggota();
          break;
      case 3:
          delete_peminjaman();
          break;
      default:
          cout << "Input tidak valid" << endl;
          break;
  }
}

void delete_buku(){
  char jawab;
  string kill_judul;
  cin.ignore();
  cout << "\nDelete Book" << endl;
  cout << "Masukkan judul buku : "; 
  getline(cin, kill_judul);

  bool found = false;
  for (int i = 0; i <=jumlahBuku; i++) {
    if (daftarBuku[i].judul.find(kill_judul) != string::npos) {
        cout << "Id Buku\t\t: " << daftarBuku[i].id << endl;
        cout << "Judul\t\t: " << daftarBuku[i].judul << endl;
        cout << "Penulis\t\t: " << daftarBuku[i].penulis << endl;
        cout << "Tahun Terbit\t: " << daftarBuku[i].tahun_terbit << endl;
        cout << "----------------------\n";
        cout << "Yakin ingin menghapus? (y/n) : ";
        cin >> jawab;
        if(jawab == 'y'){
          daftarBuku[i].id = daftarBuku[i+1].id;
          daftarBuku[i].judul = daftarBuku[i+1].judul;
          daftarBuku[i].penulis = daftarBuku[i+1].penulis;
          daftarBuku[i].tahun_terbit = daftarBuku[i+1].tahun_terbit;
          cout << "Buku berhasil dihapus." << endl;
          found = true;
          jumlahBuku--;

          ofstream book("dataBuku.txt", ios::trunc);
          if(book.is_open()){
            for(int i = 0; i < jumlahBuku; i++){
              book << daftarBuku[i].id << endl;
              book << daftarBuku[i].judul << endl;
              book << daftarBuku[i].penulis << endl;
              book << daftarBuku[i].tahun_terbit << endl;
            }
            book.close();
          }
        }
        else{
          return menu_admin();
        }
    }
  }
  if (!found) {
    cout << "Buku tidak ditemukan." << endl;
  }
}

void delete_anggota(){
  char jawab;
  string kill_name;
  cin.ignore();
  cout << "\nKill Anggota" << endl;
  cout << "Masukkan nama anggota : "; 
  getline(cin, kill_name);

  bool found = false;
  for (int i = 0; i <=jumlahBuku; i++) {
    if (daftarAnggota[i].nama.find(kill_name) != string::npos) {
        cout << "Id Anggota\t: " << daftarAnggota[i].id << endl;
        cout << "Nama\t\t: " << daftarAnggota[i].nama << endl;
        cout << "Pekerjaan\t: " << daftarAnggota[i].role.role << endl;
        cout << "Alamat\t\t: " << daftarAnggota[i].alamat << endl;
        cout << "Telepon\t\t: " << daftarAnggota[i].telepon << endl;
        cout << "----------------------\n";
        cout << "Yakin ingin menghapus? (y/n) : ";
        cin >> jawab;
        if(jawab == 'y'){
          daftarAnggota[i].id = daftarAnggota[i+1].id;
          daftarAnggota[i].nama = daftarAnggota[i+1].nama;
          daftarAnggota[i].role.role = daftarAnggota[i+1].role.role;
          daftarAnggota[i].alamat = daftarAnggota[i+1].alamat;
          daftarAnggota[i].telepon == daftarAnggota[i+1].telepon;
          cout << "Buku berhasil dihapus." << endl;
          found = true;
          jumlahAnggota--;

          ofstream anggota("dataAnggota.txt", ios::trunc);
          if(anggota.is_open()){
            for(int i = 0; i < jumlahAnggota; i++){
              anggota << daftarAnggota[i].id << endl;
              anggota << daftarAnggota[i].nama << endl;
              anggota << daftarAnggota[i].role.role << endl;
              anggota << daftarAnggota[i].alamat << endl;
              anggota << daftarAnggota[i].telepon << endl;
            }
            anggota.close();
          }
        }
        else{
          return menu_admin();
        }
    }
  }
  if (!found) {
    cout << "Anggota tidak ditemukan." << endl;
  }
}

void delete_peminjaman(){
  int id;
  char jawab;
  cout << "Masukkan ID peminjam: ";
  cin >> id;

  bool found = false;
  for (int i = 0; i < jumlahPeminjaman; i++) {
    if (daftarPeminjaman[i].idPeminjam == id) {
      cout << "Id Peminjam\t: " << daftarPeminjaman[i].idPeminjam << endl;
      cout << "Judul Buku\t: " << daftarPeminjaman[i].judul_buku << endl;
      cout << "Nama Anggota\t: " << daftarPeminjaman[i].nama_anggota << endl;
      cout << "Tanggal Pinjam\t: " << daftarPeminjaman[i].tanggal_pinjam << endl;
      cout << "Tanggal Kembali\t: " << daftarPeminjaman[i].tanggal_kembali << endl;
      cout << "----------------------" << endl;
      cout << "Yakin ingin menghapus? (y/n) : ";
        cin >> jawab;
        if(jawab == 'y'){
          daftarPeminjaman[i].idPeminjam = daftarPeminjaman[i+1].idPeminjam;
          daftarPeminjaman[i].judul_buku = daftarPeminjaman[i+1].judul_buku;
          daftarPeminjaman[i].nama_anggota = daftarPeminjaman[i+1].nama_anggota;
          daftarPeminjaman[i].tanggal_pinjam = daftarPeminjaman[i+1].tanggal_pinjam;
          daftarPeminjaman[i].tanggal_kembali = daftarPeminjaman[i+1].tanggal_kembali;
          cout << "Buku berhasil dihapus." << endl;
          found = true;
          jumlahPeminjaman--;

          ofstream borrow("dataPeminjaman.txt", ios::trunc);
          if(borrow.is_open()){
            for(int i = 0; i < jumlahBuku; i++){
              borrow << daftarPeminjaman[i].idPeminjam << endl;
              borrow << daftarPeminjaman[i].judul_buku << endl;
              borrow << daftarPeminjaman[i].nama_anggota << endl;
              borrow << daftarPeminjaman[i].tanggal_pinjam << endl;
              borrow << daftarPeminjaman[i].tanggal_kembali << endl;
            }
            borrow.close();
          }
        }
        else{
          return menu_admin();
        }
      found = true;
    }
  }
  if (!found) {
    cout << "Data peminjaman tidak ditemukan." << endl;
  }
}

void update_buku() {
    string keyword;
    cout << "\nUpdate Buku" << endl;
    cout << "Masukkan judul buku yang ingin diupdate: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (int i = 0; i < jumlahBuku; i++) {
        if (daftarBuku[i].judul.find(keyword) != string::npos) {
            found = true;
            cout << "Id Buku\t\t: " << daftarBuku[i].id << endl;
            cout << "Judul\t\t: " << daftarBuku[i].judul << endl;
            cout << "Penulis\t\t: " << daftarBuku[i].penulis << endl;
            cout << "Tahun Terbit\t: " << daftarBuku[i].tahun_terbit << endl;
            cout << "----------------------\n";

            char jawab;
            cout << "Yakin ingin mengupdate buku ini? (y/n): ";
            cin >> jawab;
            if (jawab == 'y') {
                cin.ignore();
                cout << "Masukkan judul baru: ";
                getline(cin, daftarBuku[i].judul);
                cout << "Masukkan penulis baru: ";
                getline(cin, daftarBuku[i].penulis);
                cout << "Masukkan tahun terbit baru: ";
                cin >> daftarBuku[i].tahun_terbit;
                cout << "Buku berhasil diupdate." << endl;

                ofstream book("dataBuku.txt", ios::trunc);
                if(book.is_open()){
                  book << daftarBuku[i].id << endl;
                  book << daftarBuku[i].judul << endl;
                  book << daftarBuku[i].penulis << endl;
                  book << daftarBuku[i].tahun_terbit << endl;
                  book.close();
                }
                return;
            } else {
                cout << "Update dibatalkan." << endl;
                return;
            }
        }
    }
    if (!found) {
        cout << "Buku dengan judul \"" << keyword << "\" tidak ditemukan." << endl;
    }
}

void update_anggota() {
    string keyword;
    cout << "\nUpdate Anggota" << endl;
    cout << "Masukkan nama anggota yang ingin diupdate: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;
    for (int i = 0; i < jumlahAnggota; i++) {
        if (daftarAnggota[i].nama.find(keyword) != string::npos) {
            found = true;
            cout << "Id Anggota\t: " << daftarAnggota[i].id << endl;
            cout << "Nama\t\t: " << daftarAnggota[i].nama << endl;
            cout << "Pekerjaan\t: " << daftarAnggota[i].role.role << endl;
            cout << "Alamat\t\t: " << daftarAnggota[i].alamat << endl;
            cout << "Telepon\t\t: " << daftarAnggota[i].telepon << endl;
            cout << "----------------------\n";

            char jawab;
            cout << "Yakin ingin mengupdate anggota ini? (y/n): ";
            cin >> jawab;
            if (jawab == 'y') {
                cin.ignore();
                cout << "Masukkan nama baru: ";
                getline(cin, daftarAnggota[i].nama);
                cout << "Masukkan pekerjaan baru: ";
                getline(cin, daftarAnggota[i].role.role);
                cout << "Masukkan alamat baru: ";
                getline(cin, daftarAnggota[i].alamat);
                cout << "Masukkan telepon baru: ";
                cin >> daftarAnggota[i].telepon;
                cout << "Anggota berhasil diupdate." << endl;

                ofstream anggota("dataAnggota.txt", ios::trunc);
                if(anggota.is_open()){
                  anggota << daftarAnggota[i].id << endl;
                  anggota << daftarAnggota[i].nama << endl;
                  anggota << daftarAnggota[i].role.role << endl;
                  anggota << daftarAnggota[i].alamat << endl;
                  anggota << daftarAnggota[i].telepon << endl;
                  anggota.close();
                }
                return;
            } else {
                cout << "Update dibatalkan." << endl;
                return;
            }
        }
    }
    if (!found) {
        cout << "Anggota dengan nama \"" << keyword << "\" tidak ditemukan." << endl;
    }
}

void update_peminjaman() {
    int id;
    cout << "\nUpdate Peminjaman" << endl;
    cout << "Masukkan ID peminjaman yang ingin diupdate: ";
    cin >> id;

    bool found = false;
    for (int i = 0; i < jumlahPeminjaman; i++) {
        if (daftarPeminjaman[i].idPeminjam == id) {
            found = true;
            cout << "Id Peminjam\t: " << daftarPeminjaman[i].idPeminjam << endl;
            cout << "Judul Buku\t: " << daftarPeminjaman[i].judul_buku << endl;
            cout << "Nama Anggota\t: " << daftarPeminjaman[i].nama_anggota << endl;
            cout << "Tanggal Pinjam\t: " << daftarPeminjaman[i].tanggal_pinjam << endl;
            cout << "Tanggal Kembali\t: " << daftarPeminjaman[i].tanggal_kembali << endl;
            cout << "----------------------\n";

            char jawab;
            cout << "Yakin ingin mengupdate peminjaman ini? (y/n): ";
            cin >> jawab;
            if (jawab == 'y') {
                cin.ignore();
                cout << "Masukkan judul buku baru: ";
                getline(cin, daftarPeminjaman[i].judul_buku);
                cout << "Masukkan nama anggota baru: ";
                getline(cin, daftarPeminjaman[i].nama_anggota);
                cout << "Masukkan tanggal pinjam baru: ";
                getline(cin, daftarPeminjaman[i].tanggal_pinjam);
                cout << "Masukkan tanggal kembali baru: ";
                getline(cin, daftarPeminjaman[i].tanggal_kembali);
                cout << "Peminjaman berhasil diupdate." << endl;

                ofstream borrow("dataPeminjaman.txt", ios::trunc);
                if(borrow.is_open()){
                  borrow << daftarPeminjaman[i].idPeminjam << endl;
                  borrow << daftarPeminjaman[i].judul_buku << endl;
                  borrow << daftarPeminjaman[i].nama_anggota << endl;
                  borrow << daftarPeminjaman[i].tanggal_pinjam << endl;
                  borrow << daftarPeminjaman[i].tanggal_kembali << endl;
                  borrow.close();
                }
                return;
            } else {
                cout << "Update dibatalkan." << endl;
                return;
            }
        }
    }
    if (!found) {
        cout << "Peminjaman dengan ID \"" << id << "\" tidak ditemukan." << endl;
    }
}


