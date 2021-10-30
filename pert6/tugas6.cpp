#include<iostream>

using namespace std;

// Kelas Abstrak, karena didalamnya hanya ada deklarsi dari fungtion dan method yang masih mentah
class Pukul{
    public:
        Pukul(int jam = 0, int menit = 0, int detik = 0);
        void setwaktu( int jammasuk, int menitmasuk, int detikmasuk);
        int getJam();
        int getMenit();
        int getDetik();
// Bagian ini adalah salah satu part dari enkapsulasi karena menyembunyikan variable di bagian private supaya tidak bisa 
// diakses sembarangan.
    private:
        int jam;
        int menit;
        int detik;
};

Pukul::Pukul(int jam, int menit, int detik){
    setwaktu(jam, menit, detik);
};

//Melakukan override fungsi dari class abstrak utama dan membuat fungtion baru yang berisi kondisi yang harus dipenuhi
void Pukul::setwaktu(int jammasuk, int menitmasuk, int detikmasuk){
    if ((jammasuk >= 0 && jammasuk<24) && (menitmasuk >= 0 && menitmasuk <= 59) && (detikmasuk >= 0 && detikmasuk <= 59)){
        jam = jammasuk;
        menit = menitmasuk;
        detik = detikmasuk;
    } else {
        cout<<"Format Waktu Salah"<<endl;
    }
}

// Metode getter 
int Pukul::getJam(){
    return jam;
}

int Pukul::getMenit(){
    return menit;
}

int Pukul::getDetik(){
    return detik;
}


int main(){    
//instansiasi
    Pukul t;

//Bagian ini adalah bagian untuk user mengisi inputan dari jam yang diinginkan
    int  jammasuk, menitmasuk, detikmasuk;
    cout<<"Masukkan Format Jam : "<<endl;
    cout<<" Jam   : ";
    cin>>jammasuk;
    cout<<" Menit : ";
    cin>>menitmasuk;
    cout<<" Detik : ";
    cin>>detikmasuk;

// Memasukan objek kedalam class yang telah dibuat
    t.setwaktu(jammasuk, menitmasuk, detikmasuk);
    cout<<"Waktu Menunjukan Pukul "<< t.getJam() << " : " << t.getMenit() << " : " << t.getDetik() << endl;

}