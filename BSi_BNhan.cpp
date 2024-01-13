#include <bits/stdc++.h>
using namespace std;

class Nguoi{
	protected:
		string Ten;
		int Namsinh;
	public:
		Nguoi();
		Nguoi(string,int);
		string getTen();
		int getNamsinh();
		int tinhTuoi(int);
		void NhapNguoi();
};

Nguoi::Nguoi(){};

Nguoi::Nguoi(string ten, int namsinh):Ten(ten),Namsinh(namsinh){};


void Nguoi::NhapNguoi(){
	cout<<"Nhap ho ten: ", getline(cin,Ten);
	cout<<"Nam sinh: ", cin>>Namsinh;
	cin.ignore();
}

string Nguoi::getTen(){
	return Ten;
}

int Nguoi::getNamsinh(){
	return Namsinh;
}

int Nguoi::tinhTuoi(int ns){
	return 2024-ns;
}

class BenhNhan:public Nguoi{
	private:
		string tenBA;
		int soNgaynam,VienPhi;
	public:
		BenhNhan();
		BenhNhan(string,int,string,int,int);
		void NhapBenhNhan();
		void XuatBenhNhan();
		int tinhVienPhi(int,int);
};

BenhNhan::BenhNhan(){}

BenhNhan::BenhNhan(string ten,int namsinh,string tenba,int songay,int vp)
:Nguoi(Ten,Namsinh), tenBA(tenba), soNgaynam(songay), VienPhi(vp){};

void BenhNhan::NhapBenhNhan(){
	Nguoi : NhapNguoi();
	cout<<"Ten benh an: ", getline(cin,tenBA);
	cout<<"So ngay dieu tri: ", cin>>soNgaynam;
	cout<<"Nhap vien phi/ngay: ", cin>>VienPhi;
}

void BenhNhan::XuatBenhNhan(){
	cout<<setw(24)<<left<<Ten<<setw(24)<<left<<tinhTuoi(Namsinh);
	cout<<setw(24)<<left<<tenBA<<setw(24)<<soNgaynam;
	cout<<setw(24)<<tinhVienPhi(soNgaynam,VienPhi)<<endl;
}

int BenhNhan::tinhVienPhi(int songay,int vp){
	return songay*vp;
}

class BacSi:public Nguoi{
	private:
		string MaBS;
		double Songaylamviec;
		int TienCong;
	public:
		BacSi();
		BacSi(string,int,string,double,int);
		void NhapBacSi();
		void XuatBacSi();
		double tinhTienCong(double,int);
};

BacSi::BacSi(){}

BacSi::BacSi(string ten,int namsinh,string mabs,double songaylmvc,int tiencong)
:Nguoi(Ten,Namsinh), MaBS(mabs), Songaylamviec(songaylmvc), TienCong(tiencong){};

void BacSi::NhapBacSi(){
	Nguoi : NhapNguoi();
	cout<<"Ma bac si: ", getline(cin,MaBS);
	cout<<"So ngay lam viec: ", cin>>Songaylamviec;
	cout<<"Nhap tien cong/ngay: ", cin>>TienCong;
}

void BacSi::XuatBacSi(){
	cout<<setw(20)<<left<<Ten<<setw(20)<<left<<tinhTuoi(Namsinh);
	cout<<setw(20)<<left<<MaBS<<setw(20)<<Songaylamviec;
	cout<<setw(20)<<left<<TienCong;
	cout<<setw(20)<<tinhTienCong(Songaylamviec,TienCong)<<endl;
}

double BacSi::tinhTienCong(double songay,int tienc){
	return songay*tienc;
}


static void InBangBN() {
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(65) << right << "DANH SACH BENH NHAN" << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(24) << left << "TEN" << setw(24) << left << "TUOI" << setw(24) << left << "TEN BENH AN";
    cout << setw(24) << left << "SO NGAY DIEU TRI" << setw(24) << left << "VIEN PHI" ;
    cout << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
}

static void InBangBS() {
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(65) << right << "DANH SACH BAC SI" << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(20) << left << "TEN" << setw(20) << left << "TUOI" << setw(20) << left << "MA BS";
    cout << setw(20) << left << "SO NGAY LAM VIEC" << setw(20) << left << "TIEN CONG/NGAY";
    cout << setw(20) << left << "LUONG";
    cout << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
}

int main(){
	int slNguoi;
	cout<<"Nhap so luong Nguoi: ", cin>>slNguoi;
	cin.ignore();
	vector<BenhNhan> BN;
	vector<BacSi> BS;
	for(int i=0;i<slNguoi;i++){
		int loai;
		cout<<"\nChon loai nguoi|1:Bac Si|2:Benh Nhan|: ";
		cin>>loai;
		cin.ignore();
		while(loai<1||loai>2){
			cout<<"Vui nhap lai!\n";
			cout<<"Chon loai nguoi|1:Bac Si|2:Benh Nhan|: ";
		cin>>loai;
		cin.ignore();
		}
			if(loai==1){
				static int thutuBS = 1;
				BacSi bs;
				cout<<"\nNhap thong tin cho bac si thu "<<thutuBS<<"!\n";
				bs.NhapBacSi();
				BS.push_back(bs);
				thutuBS++;
			}
			else{
				static int thutuBN = 1;
				BenhNhan bn;
				cout<<"\nNhap thong tin cho benh nhan thu "<<thutuBN<<"!\n";
				bn.NhapBenhNhan();
				BN.push_back(bn);
				thutuBN++;
			}
	}
	
	system("pause");
	system("cls");
	
	if(!BS.empty()){
	InBangBS();
	for(auto &bs : BS){
		bs.XuatBacSi();
		}
		system("pause");
		system("cls");
	}
	
	if(!BN.empty()){
		InBangBN();
		for(auto &bn : BN){
			bn.XuatBenhNhan();
		}
		system("pause");
		system("cls");
	}
	
	return 0;
} 
