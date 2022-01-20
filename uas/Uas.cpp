#include <iostream>
#include <mysql/mysql.h>
#include <sstream>

using namespace std;

int pilih;
char kembali;
const char* hostname = "127.0.0.1";
const char* user = "root";
const char* pass = "";
const char* dbname = "uasahoy";
unsigned int port = 3306;
const char* unixsocket = NULL;
unsigned long clientflag = 0;

MYSQL* connectdb(){
    MYSQL * conn;
    conn = mysql_init(0);
    conn = mysql_real_connect(conn, hostname, user, pass, dbname, port, unixsocket, clientflag);
    if (conn) {
        cout<< "berhasil"<<endl;
        return conn;
    } else {
        cout<< "gagal"<<endl;
        return conn;
    }
}

class CRUD{
    public : 
    void insertDataMahasiswa(MYSQL* conn){ //tablemahasiswa
    int qstate =0;
    stringstream inserttodb;
    string nim, nama, id;
    cout << "insert Id : "<<endl;
    cin>>id;
    cout << "insert NIM : "<<endl;
    cin>>nim;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO table_mahasiswa (id, nim, nama) VALUES ('"+id+"','"+nim+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;
    }
}

    void insertDataMatkul(MYSQL* conn){ //tablematkul
    int qstate =0;
    stringstream inserttodb;
    string id, nama, kd_matkul;
    cout << "insert Id : "<<endl;
    cin>>id;
    cout << "insert Kode Matkul : "<<endl;
    cin>>kd_matkul;
    cout << "insert Nama : "<<endl;
    cin>>nama;
    inserttodb << "INSERT INTO table_matkul (id, kd_matkul, nama) VALUES ('"+id+"','"+kd_matkul+"','"+nama+"')";
    string query = inserttodb.str();
    const char* q = query.c_str();
    qstate = mysql_query(conn, q);
    if (qstate == 0){
        cout <<"berhasil insert"<<endl;
    } else {
        cout <<"gagal"<<endl;
    }
}

    void updateDataMahasiswa(MYSQL* conn){ //tablemahasiswa
    MYSQL_ROW row; 
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM table_mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);
    string nim, nama;
    if(x>0){
        cout << "insert NIM : "<<endl;
        cin>>nim;
        cout << "insert Nama : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE table_mahasiswa SET nim = '"+nim+"', nama= '"+nama+"' WHERE id = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

    void updateDataMatkul(MYSQL* conn){ //tablematkul
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, updatedb;
    selectdb << "SELECT * FROM table_matkul WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);
    string kd_matkul, nama;
    if(x>0){
        cout << "insert Kode Matkul : "<<endl;
        cin>>kd_matkul;
        cout << "insert Nama : "<<endl;
        cin>>nama;
        updatedb <<"UPDATE table_matkul SET kd_matkul = '"+kd_matkul+"', nama= '"+nama+"' WHERE id = '"+id+"' ";
        string query = updatedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

    void deleteDataMahasiswa(MYSQL* conn){ //tablemahasiswa
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM table_mahasiswa WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);

    if(x>0){
        deletedb <<"DELETE FROM table_mahasiswa WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

    void deleteDataMatkul(MYSQL* conn){ //tablematkul
    MYSQL_ROW row;
    MYSQL_RES* res;
    string id;
    cout << "enter id : "<<endl;
    cin >> id;
    stringstream selectdb, deletedb;
    selectdb << "SELECT * FROM table_matkul WHERE id = '"+id+"' ";
    string query = selectdb.str();
    const char* q = query.c_str();
    mysql_query(conn, q);
    res = mysql_store_result(conn);
    int count = mysql_num_fields(res);
    my_ulonglong x = mysql_num_rows(res);

    if(x>0){
        deletedb <<"DELETE FROM table_matkul WHERE id = '"+id+"' ";
        string query = deletedb.str();
        const char* q = query.c_str();
        mysql_query(conn, q);
    }else{
        cout<<"error\n";
    }

}

    void displayData(MYSQL* conn){
    MYSQL_ROW row;
    MYSQL_RES* res;

    if (conn){
        int qstate = mysql_query(conn, "SELECT * FROM table_mahasiswa JOIN table_matkul ON table_mahasiswa.id = table_matkul.id");
        if(!qstate){
            res = mysql_store_result(conn);
            int count = mysql_num_fields(res);
            cout << "=========================================LIST DATA==========================================\n";
            cout <<"\tID\tNIM\t\tNAMA\tCREATE AT\t\tUPDATE AT\t\tID\tKD MKUL\t\tNAMA MKUL\tCREATE AT\t\tUPDATE AT\n";
            while(row = mysql_fetch_row(res)){
                for(int i=0; i<count;i++){
                    cout <<"\t"<<row[i];
                }
                cout<<endl;
            }

        }
    } else {
        cout << "Data Kosong" <<endl;
    }
}
};

int main(){
    MYSQL* conn = connectdb();
    CRUD C;
    do{
        cout<<"MENU";
        cout<<"\n 0. Exit";
        cout<<"\n 1. Insert Data Mahasiswa";
        cout<<"\n 2. Insert Data Mata Kuliah";
        cout<<"\n 3. Read ";
        cout<<"\n 4. Update Data Mahasiswa";
        cout<<"\n 5. Update Data Mata Kuliah";
        cout<<"\n 6. Delete Data Mahasiswa";
        cout<<"\n 7. Delete Data Mata Kuliah";
        
        
        cout<<"\nPilih : "; cin>>pilih;

        switch(pilih){
            case 0:
                cout<<"\nThanks"<<endl;
                return 0;
            case 1:
				C.insertDataMahasiswa(conn);
                break;
            case 2:
				C.insertDataMatkul(conn);
                break;
            case 3:
				C.displayData(conn);
                break;
            case 4:
                C.updateDataMahasiswa(conn);
                C.displayData(conn);
                break;
            case 5:
                C.updateDataMatkul(conn);
                C.displayData(conn);
                break;
            case 6:
                C.deleteDataMahasiswa(conn);
                break;
            case 7:
                C.deleteDataMatkul(conn);
                break;
            default:
                cout<<"Pilihan Salah"<<endl;
                break;
            }
            cout<<"Ingin memilih menu lain (y/t)? ";
            cin>>kembali;
            cout<<endl;
        }
        while (kembali!= 't');
        cout<<"Thanks"<<endl;
    return 0;

}
