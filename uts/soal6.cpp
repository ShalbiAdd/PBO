#include <iostream>
using namespace std;

class clc{
    private :
        int a, b;

    public :
    void input(){
        cout<<" Masukkan Angka Pertama : ";
        cin>>a;
        cout<<" Masukkan Angka Kedua : ";
        cin>>b;
    }
    int jumlah (){
        return a + b;
    } 
    int kurang (){
        return a - b;
    }
    int kalian (){
        return a * b;
    }
    int bagian (){
        return a / b;
    }
};

int main(){

    clc c;
    int x;
    char menu; 

OPERASI : 
    cout<<"===================================================="<<endl;
	cout<<"               KALKULATOR SEDERHANA "<<endl;
	cout<<"===================================================="<<endl;
	cout<<" OPERASI ARITMATIKA : "<<endl;
	cout<<" 1. Penjumlahan "<<endl;
	cout<<" 2. Pengurangan "<<endl;
	cout<<" 3. Perkalian "<<endl;
	cout<<" 4. Pembagian "<<endl;
	cout<<" 5. Keluar "<<endl;
    cout<<" PILIH OPERASI : ";
    cin>>x;

    switch (x){

        case 1 :
            c.input();
            cout<<" Hasilnya : "<<c.jumlah()<<endl;
        break;

        case 2 :
            c.input();
            cout<<" Hasilnya : "<<c.kurang()<<endl;
        break;

        case 3 :
            c.input();
            cout<<" Hasilnya : "<<c.kalian()<<endl;
        break;

        case 4 :
            c.input();
            cout<<" Hasilnya : "<<c.bagian()<<endl;
        break;

        case 5 :
            goto KELUAR;
        break;
    }
    cout<<" Mau Coba Lagi (y/n) ?"<<endl;
    cin>>menu;

    if((menu=='y') || (menu=='Y')){
            goto OPERASI;
        }

    else if ((menu=='n') || (menu=='N')){
            goto KELUAR;
        }

    KELUAR :
        cout<<"===================================================="<<endl;
		cout<<"                  TERIMAKASIH "<<endl;
		cout<<"===================================================="<<endl;
        return 0;
}
    
