#include <iostream>

using namespace std;

class age{
    private:
    int ts, tl;

    public:
    void assign(int thnskrng, int thnlhr){
        ts=thnskrng;
        tl=thnlhr;
    }
    int umur(){
        return ts-tl;
    }

};

int main(){
    age obj;
    obj.assign(2021, 1990);
    cout<<"Berarti Usia Kalian Sekarang Adalah "<<obj.umur()<<" Tahun"<<endl;
    return 0;
}