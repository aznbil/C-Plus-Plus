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

void create_buku();
void create_anggota();
void create_peminjaman();

int main(){
  while(true){
  create_buku();
  create_anggota();
  create_peminjaman();
  }
  return 0;
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


