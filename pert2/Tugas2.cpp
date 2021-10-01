#include <iostream>
// menggunakan library standar untuk menjalankan program sederhana yaitu iostream.

using namespace std;
// menggunakan header ini supaya bisa membaca perintah langsung seperti cout dan cin.

int main (){
// menggunakan int main karna didalam fungsinya nanti terdapat tipedata dan nilai kembalian.

int thl,ths,umr;
// Diatas merupakan variable variable yang akan digunakan pada program dibawah ini 

cout<<" ================================================== \n";
cout<<" Masukkan Tahun Lahir Anda \t\t :";
cin>>thl;
//variable thl diatas adalah hasil masukan yang akan digunakan pada rumus nanti

cout<<" Masukkan Tahun Saat Ini   \t\t :";
cin>>ths; 
// bagian ini sama seperti diatas tapi hanya berbeda masukannya saja

cout<<" ================================================== \n";
umr = ths - thl;
// Pada bagian ini adalah rumus utama yang digunakan untuk menjalankan program ini.
// Berdasarkan hasil output yang diminta secara logika rumus ini adalah rumus paling mudah.

cout<<" Berarti Usia Anda adalah "<<umr<<" Tahun .\n";
// bagian ini hanya berisi output biasa yang ditambahkan perintah untuk mengeluarkan variable umur

cout<<" Terima Kasih \n";
cout<<" ================================================== \n";

return 0;
}