#include <iostream>

using namespace std;

int main(){

	int bil;
    cout<<" =========================================== "<<endl;
    cout<<"    Program Penentu Bil Ganjil atau Genap    "<<endl;
    cout<<" =========================================== "<<endl;
	cout<<" Masukan Bilangan \t\t: ";
	cin>>bil;
	
	if (bil%2==0){
		cout<<" "<<bil<<" adalah bilangan genap "<<endl;

	}else {
		cout<<" "<<bil<<" adalah bilangan ganjil "<<endl;	
	}
}