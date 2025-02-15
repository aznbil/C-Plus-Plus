#include <iostream>
using namespace std;

struct Buku{
  int id;
  string judul;
  string penulis;
  int tahun_terbit;
};

struct Anggota{
  int id;
  char nama[50];
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