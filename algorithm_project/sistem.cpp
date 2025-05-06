#include <iostream>
using namespace std;

struct Buku{
  int id;
  string judul;
  string penulis;
  int tahun_terbit;
};

struct Pekerjaan {
  string role;
};

struct Anggota{
  int id; 
  Pekerjaan role;
  string nama; //struct dalam struct ada mahasiswa, dosen, pegawai jangan langsung nama. nanti dipanggil id nya 
  string alamat;
  char telepon[15];
  };


struct Peminjaman{
  int idPeminjam;
  int idBuku;
  int idAnggota;
  string tanggal_pinjam;
  string tanggal_kembali;
};

// ini bagian untuk menu
void menu();
void menu_Create();
void menu_Read();
void menu_Update();
void menu_Delete();
void menu_sorting();

// ini bagian untuk membuat data
void create_buku();
void create_anggota();
void create_peminjaman();

// ini bagian untuk membaca data
void read_buku(int index);
void read_anggota(int index);
void read_peminjaman(int index);

// ini bagian untuk memperbarui data
void update_buku();
void update_anggota();
void update_peminjaman();

// ini bagian untuk menghapus data
void delete_buku();
void delete_anggota();
void delete_peminjaman();

void sorting_buku_tahunTerbit_DESC();
void sorting_anggota();
void sorting_peminjaman();

void search_buku();
void search_anggota();
void search_peminjaman();
void menu_search();

Buku daftarBuku[100];
Anggota daftarAnggota[100];
Peminjaman daftarPeminjaman[100];
int jumlahBuku = 0, jumlahAnggota = 0, jumlahPeminjaman = 0;

int main(){
  menu();
  return 0;
}

void menu(){
  int choose;
  char jawab;
  do{
    cout << "Welcome" << endl;
    cout << "1. Create " << endl;
    cout << "2. Read " << endl;
    cout << "3. Sorting " << endl;
    cout << "4. Delete " << endl;
    cout << "5. Update " << endl;
    cout << "6. Search" << endl;
    cout << "7. Exit" << endl;
    cout << "Pilih menu : ";
    cin >> choose;

    switch(choose){
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
        break;
      case 5:
        break;
      case 6:
         menu_search();
        break;
      case 7:
         exit(0);
        break;
      default:
        cout << "Input tidak valid" << endl;
        break;
    }
    cout << "Ingin lanjut (y/n): ";
    cin >> jawab;
  }while(jawab == 'y');
}

void menu_Create(){
  int choose;
  cout << "\nMenu Create" << endl;
  cout << "1. Buku " << endl;
  cout << "2. Anggota " << endl;
  cout << "3. Peminjaman " << endl;
  cout << "Pilih menu : ";
  cin >> choose;

  switch (choose){
    case 1:
      create_buku();
      break;
    case 2:
      create_anggota();
      break;
    case 3:
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

  for (int i = jumlahBuku ; i < dataygdiinput + jumlahBuku; i++){
    cout << "Buku ke-" << i + 1 << endl;
    cout << "Id buku\t\t: ";
    cin >> daftarBuku[i].id;
    cin.ignore();
    cout << "Judul buku\t: ";
    getline(cin, daftarBuku[i].judul);
    cout << "Penulis buku\t: ";
    getline(cin, daftarBuku[i].penulis);
    cout << "Tahun terbit\t: ";
    cin >> daftarBuku[i].tahun_terbit;
    cout << endl;
  }
  jumlahBuku += dataygdiinput;
}

void create_anggota(){
  int dataygdiinput;
  cout << "Berapa data yang ingin di input? ";
  cin >> dataygdiinput;
  if(dataygdiinput + jumlahAnggota > 100){
    cout << "Input melebihi batas" << endl;
    return;
  }
  if(dataygdiinput < 1){
    cout << "Input tidak valid" << endl;
    return;
  }

  for (int i = jumlahAnggota; i < dataygdiinput + jumlahAnggota; i++){
  cout << "Anggota ke-" << i + 1 << endl;
  cout << "Id anggota : ";
  cin >> daftarAnggota[i].id;
  cin.ignore();
  cout << "Nama anggota : ";
  getline(cin, daftarAnggota[i].nama);
  cout << "Pekerjaan : ";
  getline(cin, daftarAnggota[i].role.role);
  cout << "Alamat : ";
  getline(cin, daftarAnggota[i].alamat);
  cout << "Telepon : ";
  cin >> daftarAnggota[i].telepon;
  cout << endl;
}
  jumlahAnggota += dataygdiinput;
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

  for (int i = jumlahPeminjaman; i < dataygdiinput + jumlahPeminjaman; i++){  
  cout << "Id peminjam : ";
  cin >> daftarPeminjaman[i].idPeminjam;
  cin.ignore();
  cout << "Id buku : ";
  cin >> daftarPeminjaman[i].idBuku;
  cin.ignore();
  cout << "Id anggota : ";
  cin >> daftarPeminjaman[i].idAnggota;
  cin.ignore();
  cout << "Tanggal pinjam : ";
  getline(cin, daftarPeminjaman[i].tanggal_pinjam);
  cout << "Tanggal kembali : ";
  getline(cin, daftarPeminjaman[i].tanggal_kembali);
  cout << endl;
  }
  jumlahPeminjaman += dataygdiinput;
}

void read_buku(int index = 0){
  if (index == 0){
    cout << "\nDaftar Buku" << endl;
  }
  if(index >= jumlahBuku) return;
  cout << "Id Buku: " << daftarBuku[index].id << endl;
  cout << "Judul: " << daftarBuku[index].judul << endl;
  cout << "Penulis: " << daftarBuku[index].penulis << endl;
  cout << "Tahun Terbit: " << daftarBuku[index].tahun_terbit << endl;
  cout << "----------------------\n";
  read_buku(index + 1);
}

void read_anggota(int index = 0){
  if (index == 0){
    cout << "\nDaftar Anggota" << endl;
  }
  if(index >= jumlahAnggota) return;
  cout << "Id Anggota: " << daftarAnggota[index].id << endl;
  cout << "Nama: " << daftarAnggota[index].nama << endl;
  cout << "Pekerjaan: " << daftarAnggota[index].role.role << endl;
  cout << "Alamat: " << daftarAnggota[index].alamat << endl;
  cout << "Telepon: " << daftarAnggota[index].telepon << endl;
  cout << "----------------------\n";
  read_anggota(index + 1);
}

void read_peminjaman(int index = 0){
  if (index == 0){
    cout << "\nDaftar Peminjaman" << endl;
  }
  if(index >= jumlahPeminjaman) return;
  cout << "Id Peminjam: " << daftarPeminjaman[index].idPeminjam << endl;
  cout << "Id Buku: " << daftarPeminjaman[index].idBuku << endl;
  cout << "Id Anggota: " << daftarPeminjaman[index].idAnggota << endl;
  cout << "Tanggal Pinjam: " << daftarPeminjaman[index].tanggal_pinjam << endl;
  cout << "Tanggal Kembali: " << daftarPeminjaman[index].tanggal_kembali << endl;
  cout << "----------------------\n";
  read_peminjaman(index + 1);
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
  for(int i = 0; i < jumlahBuku; i++){
    for (int j = 0; j < jumlahBuku - i - 1; j++){
      if (daftarBuku[j].tahun_terbit < daftarBuku[j + 1].tahun_terbit){
        swap(daftarBuku[j], daftarBuku[j + 1]);
      }
    }
  }
  read_buku();
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
      cout << "Id Buku: " << daftarPeminjaman[i].idBuku << endl;
      cout << "Id Anggota: " << daftarPeminjaman[i].idAnggota << endl;
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


