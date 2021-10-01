#include <iostream>
using namespace std;

int main(){
	int x,y,z,hasil,a;
	
	
	
	kalkulator :
	cout<<"===================================================="<<endl;
	cout<<"               KALKULATOR SEDERHANA "<<endl;
	cout<<"===================================================="<<endl;
	cout<<" OPERASI ARITMATIKA : "<<endl;
	cout<<"(1) Penjumlahan "<<endl;
	cout<<"(2) Pengurangan "<<endl;
	cout<<"(3) Perkalian "<<endl;
	cout<<"(4) Pembagian "<<endl;
	cout<<" Masukkan Angka = "<<endl;
	cin>>x;
	cout<<" Masukkan Angka = "<<endl;
	cin>>y;
	cout<<" PILIH OPERASI : ";
	cin>>z;
	
	
	if(z==1){
		hasil=x+y;
		cout<<" Hasil Penjumlahan = "<<hasil<<endl;
	}
	else if(z==2){
		hasil=x-y;
		cout<<" Hasil Pengurangan = "<<hasil<<endl;
	}
	else if(z==3){
		hasil=x*y;
		cout<<" Hasil Perkalian = "<<hasil<<endl;
	}
	else if(z==4){
		hasil=x/y;
		cout<<" Hasil Pembagian = "<<hasil<<endl;
	}
	
	cout<<"===================================================="<<endl;
	cout<<" Keluar    (1) "<<endl;
	cout<<" Coba Lagi (2)"<<endl;
	cout<<"===================================================="<<endl;
	cout<<" Pilih : "<<endl;
	cin>>a;
	
	if (a==2){
		goto kalkulator;
	}
	else if (a==1){
		cout<<"===================================================="<<endl;
		cout<<"                  TERIMAKASIH "<<endl;
		cout<<"===================================================="<<endl;
	}
	
	
}