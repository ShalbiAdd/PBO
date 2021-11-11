#include <iostream>
#include <string.h>
using namespace std;

class nama{
    public :
        string firstn;
        string midn;
        string lastn;
};

int main(){

    int menu ;
    char z;

    PILIHAN :
        cout<<"                      Menu  "<<endl;
        cout<<"===================================================="<<endl;
        cout<<"1. INPUT "<<endl;
        cout <<"2. KELUAR "<<endl;
        cout<<"Pilihan : ";
        cin>>menu;
        nama name;

    switch (menu){
        case 1 :

        cout<<" Masukan Nama Depan : ";
        cin>>name.firstn;
        cout<<" Masukan Nama Tengah : ";
        cin>>name.midn;
        cout<<" Masukan Nama Belakang : ";
        cin>>name.lastn;
        cout<<" Nama lengkap : "<<name.firstn<<" "<<name.midn<<" "<<name.lastn<<endl;
        break;

        case 2 :
        goto KELUAR;
        break;
    }
        cout<<"===================================================="<<endl;
        cout<<" Apakah ingin mencoba lagi (y/n) ? "<<endl;
        cout<<"===================================================="<<endl; 
        cin>>z;

        if((z=='y') || (z=='Y')){
            goto PILIHAN;
        }

        else if ((z=='n') || (z=='N')){
            goto KELUAR;
        }

     KELUAR :
        cout<<"===================================================="<<endl;
		cout<<"                  TERIMAKASIH "<<endl;
		cout<<"===================================================="<<endl;
        return 0;

}