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
  char nama[50]; //struct dalam struct ada mahasiswa, dosen, pegawai jangan langsung nama. nanti dipanggil id nya 
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

// ini bagian untuk membuat data
void create_buku();
void create_anggota();
void create_peminjaman();

// ini bagian untuk membaca data
void read_buku();
void read_anggota();
void read_peminjaman();

// ini bagian untuk memperbarui data
void update_buku();
void update_anggota();
void update_peminjaman();

// ini bagian untuk menghapus data
void delete_buku();
void delete_anggota();
void delete_peminjaman();

int main(){
  menu();
  return 0;
}

void menu(){
  int choose;

  cout << "Welcome" << endl;
  cout << "1. Create " << endl;
  cout << "2. Read " << endl;
  cout << "3. Update " << endl;
  cout << "4. Delete " << endl;
  cout << "5. Exit " << endl;
  cout << "Pilih menu : ";
  cin >> choose;

  switch(choose){
    case 1:
      menu_Create();
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    default:
      cout << "Input tidak valid" << endl;
      break;
  }
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
  Buku buku[100];
  int n;
  
  cout << "Berapa data yang ingin di input? ";
  cin >> n;
  if(n > 100){
    cout << "Input melebihi batas" << endl;
    return;
  }
  if(n < 1){
    cout << "Input tidak valid" << endl;
    return;
  }
  
  system("cls");
  for (int i = 0; i < n; i++){
    cout << "Id buku\t\t: ";
    cin >> buku[i].id;
    cin.ignore();
    cout << "Judul buku\t: ";
    getline(cin, buku[i].judul);
    cout << "Penulis buku\t: ";
    getline(cin, buku[i].penulis);
    cout << "Tahun terbit\t: ";
    cin >> buku[i].tahun_terbit;

    cout << endl;
  }
}

void create_anggota(){
  Anggota anggota[100];
  int n;
  
  cout << "Berapa data yang ingin di input? ";
  cin >> n;
  if(n > 100){
    cout << "Input melebihi batas" << endl;
    return;
  }
  if(n < 1){
    cout << "Input tidak valid" << endl;
    return;
  }
  
  system("cls");
  for (int i = 0; i < n; i++){
  cout << "Id anggota : ";
  cin >> anggota[i].id;
  cin.ignore();
  cout << "Nama anggota : ";
  cin >> anggota[i].nama;
  cout << "Pekerjaan anggota : ";
  getline(cin, anggota[i].role.role);
  cout << "Alamat anggota : ";
  getline(cin, anggota[i].alamat);
  cout << "Telepon anggota : ";
  cin >> anggota[i].telepon;
}

}

void create_peminjaman(){
  Peminjaman pinjaman[100];
  int n;

  cout << "Berapa data yang ingin di input? ";
  cin >> n;
  if(n > 100){
    cout << "Input melebihi batas" << endl;
    return;
  }
  if(n < 1){
    cout << "Input tidak valid" << endl;
    return;
  }

  for (int i = 0; i < n; i++){  
  cout << "Id peminjam : ";
  cin >> pinjaman[i].idPeminjam;
  cin.ignore();
  cout << "Id buku : ";
  cin >> pinjaman[i].idBuku;
  cin.ignore();
  cout << "Id anggota : ";
  cin >> pinjaman[i].idAnggota;
  cin.ignore();
  cout << "Tanggal pinjam : ";
  getline(cin, pinjaman[i].tanggal_pinjam);
  cout << "Tanggal kembali : ";
  getline(cin, pinjaman[i].tanggal_kembali);
  }

}


