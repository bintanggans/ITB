#include <IOSTREAM>
#include <windows.h>
#include <math.h>
/*  Nama : Bintang Ramdhani.
    NIM  : 16420088
    terdapat terdapat 2 fungsi termasuk main, dan 6 prosedur pada kalkulator ini, fungsi perhitungan sebagai kalkulator untuk kasus penjumlahan sampai perpangkatan sedangkan untuk kalkulator integral formula nya digabung dengan formatnya.
    tujuan dibuat format adalah agar user tidak melakukan kesalahan pada penginputan.   */
using namespace std;

float perhitungan(string var){//fungsi kalkulator untuk penjumlahan sampai perpangkatan
    float a,b,nilai;
    cout<<"masukkan a : ";
    cin>>a;
    cout<<"masukkan b : ";
    cin>>b;
    if(var=="+"){
        cout<<"         "<<a<<" + "<<b<<endl;
        nilai=a+b;
    }
    else if(var=="-"){
        cout<<"         "<<a<<" - "<<b<<endl;
        nilai=a-b;
    }
    else if(var=="x"){
        cout<<"         "<<a<<" x "<<b<<endl;
        nilai=a*b;
    }
    else if(var==":"){
        cout<<"         "<<a<<" : "<<b<<endl;
        nilai=a/b;
    }
    else if(var=="^"){
        cout<<"         "<<a<<"^"<<b<<endl;
        nilai=pow(a,b);
    }
    return (nilai);
}
void format(string var){//format penjumlahan
    cout<<"Format yang digunakan adalah a"<<var<<"b = hasil (hanya memasukkan angka dari a dan b)\n";
}
void format_integral(){//format dan kalkulator integral
    int x,a,b,c;
    cout<<"-----SPECIAL CASE-----"<<endl;
    cout<<"format integral adalah Integral f(x)dx untuk (a,b)\n";
    cout<<"masukkan banyak variabel X : ";
    cin>>x;
    int k[x],pangkat[x];
    cout<<"Integral = ";
	for(int i=0; i<x; i++){
		cout<<"k.X^n ";
		if(x-i!=1){
            cout<<"+ ";
        }
		else{
		    cout<<" + c dx "<<endl<<endl;
        }
	}
	for(int j=0;j<x;j++){
        cout<<"=>masukkan nilai k("<<j+1<<") = ";
        cin>>k[j];
        cout<<"=>masukkan nilai n("<<j+1<<") = ";
        cin>>pangkat[j];
	}
	cout<<"=>masukkan nilai c : ";
	cin>>c;
	cout<<"=>masukkan nilai a : ";
	cin>>a;
	cout<<"=>masukkan nilai b : ";
	cin>>b;
    cout<<"\n=>maka formatnya nya menjadi = f(x) = ";
    for(int i=0;i<x;i++){
        cout<<k[i]<<".X^"<<pangkat[i];
        if(x-i!=1){
            cout<<" + ";
        }
		else{
            cout<<" + "<<c<<" dx"<<"   untuk ("<<a<<","<<b<< ")"<<endl<<endl;
        }
    }
    cout<<"-------------------------------------------------\n";
    cout<<"=>berdasarkan format integral f(x) dx = F(x)+c.\n";
    cout<<"=>lalu kita masukkan batas integralnya\n";
    cout<<"=>maka hasilnya adalah = ";
    float hasil_b[x];
    for(int i=0;i<x;i++){
        int bagi = pangkat[i]+1;
        float konstanta=k[i]/bagi;
        int vrbl=pow(b,bagi);
        hasil_b[i]=konstanta*vrbl;
    }
    float hasil_a[x];
    for(int i=0;i<x;i++){
        int bagi = pangkat[i]+1;
        float konstanta=k[i]/bagi;
        int vrbl=pow(a,bagi);
        hasil_a[i]=konstanta*vrbl;
    }
    float hasil_dari_a=0;
    float hasil_dari_b=0;
    for(int i=0;i<x;i++){
        hasil_dari_b=hasil_dari_b+hasil_b[i];
        hasil_dari_a=hasil_dari_a+hasil_a[i];
    }
    float nilai_c=c*b-c*a;
    float hasil=hasil_dari_b-hasil_dari_a+nilai_c;
    cout<<hasil<<endl;
}
void error(){//bug error text
    cout<<"----------------------------------ERROR-----------------------------------\n";
    cout<<"anda salah memassukkan variabel, kalkulator ini akan ditutup dalam 3 detik.\n\n";
    Sleep(3000);
}
void pembuka(){//prosedur pembuka
    cout<<"----------------------------------------------------\n";
    cout<<"======>Tugas 2 programming - Sekolah URO 2021<======\n\n";
    cout<<"terdapat 6 opsi pada kalkulator ini:\n 1.Penjumlahan.\n 2.Pengurangan.\n 3.Perkalian.\n 4.Pembagian.\n 5.Perpangkatan.\n 6.Integral.\n\n";
}
void pilih_operasi(){//prosedur inti operasi
    int operasi;
    cout<<"silahkan pilih opsi (ex. 3) :";
    cin>>operasi;
    if(operasi==1){
        system("color 2");
        string var = "+";
        cout<<"Anda memilih Penjumlahan\n\n";
        format(var);
        float hitung = perhitungan(var);
        cout<<"hasilnya adalah = "<<hitung<<endl;
    }
    else if(operasi==2){
            system("color 3");
            string var = "-";
            cout<<"anda memilih pengurangan\n\n";
            format(var);
            float hitung = perhitungan(var);
            cout<<"hasilnya adalah = "<<hitung<<endl;
    }
    else if(operasi==3){
            system("color 4");
            string var = "x";
            cout<<"anda memilih perkalian\n\n";
            format(var);
            float hitung = perhitungan(var);
            cout<<"hasilnya adalah = "<<hitung<<endl;
    }
    else if(operasi==4){
            system("color 5");
            string var = ":";
            cout<<"anda memilih pengurangan\n\n";
            format(var);
            float hitung = perhitungan(var);
            cout<<"hasilnya adalah = "<<hitung<<endl;
    }
    else if(operasi==5){
            system("color 6");
            string var = "^";
            cout<<"anda memilih perpangkatan (pangkat>1)\n\n";
            format(var);
            float hitung = perhitungan(var);
            cout<<"hasilnya adalah = "<<hitung<<endl;
    }
    else if(operasi==6){
            system("color 1");
            format_integral();
    }
    else {
        error();
    }
}
void penutup(){//prosedur penutup
    cout<<"\n--------------------------------------------------\n";
    cout<<"Terimakasih, Program akan ditutup dalam 3 detik.\n";
    cout<<"--------------------------------------------------\n\n";
    Sleep(3000);
}
main(){
    //terdapat 3 subprogram yaitu:
    pembuka();//kalimat pembuka dalam prosedur
    pilih_operasi();//prosedur untuk operasi
    penutup();//kalimat penutup dengan prosedur
}
