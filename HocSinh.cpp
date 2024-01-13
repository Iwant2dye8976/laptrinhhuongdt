#include <bits/stdc++.h>
using namespace std;

class Nguoi{
	protected:
		string HoTen;
		int NamSinh;
	public:
		void NhapNguoi();
		void InNguoi();
		string getHoTen();
		int getNamSinh();
};

void Nguoi::NhapNguoi(){
	cout<<"Nhap ho ten: ", getline(cin,HoTen);
	cout<<"Nhap nam sinh: ", cin>>NamSinh;
	cin.ignore();
}

void Nguoi::InNguoi(){
	cout<<setw(30)<<left<<HoTen;
	cout<<setw(30)<<left<<NamSinh;
}

string Nguoi::getHoTen(){return HoTen;}
int Nguoi::getNamSinh(){return NamSinh;}

class HocSinh : public Nguoi{
	private:
		string MaHS;
		double diemToan,diemVan,diemTA;
	public:
		void NhapHS();
		void InHS();
};

void HocSinh::NhapHS(){
	Nguoi : NhapNguoi();
	cout<<"Nhap ma hoc sinh: ", getline(cin,MaHS);
	cout<<"Nhap diem Toan: ", cin>>diemToan;
	cout<<"Nhap diem Ngu Van: ", cin>>diemVan;
	cout<<"Nhap diem Tieng Anh: ", cin>>diemTA;
}

void HocSinh::InHS(){
	Nguoi : InNguoi();
	cout<<setw(30)<<left<<MaHS;
	cout<<setw(30)<<left<<(diemToan+diemVan+diemTA)/3<<endl;
}

static void InBangHS(){
	cout<<setfill('-')<<setw(120)<<'-'<<endl;
	cout<<setfill(' ')<<setw(120)<<' '<<endl;
	cout<<setw(65)<<right<<"BANG HOC SINH"<<endl;
	cout<<setfill('-')<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(30)<<left<<"Ho Ten"<<setw(30)<<left<<"Nam Sinh";
	cout<<setw(30)<<left<<"Ma Hoc Sinh"<<setw(30)<<left<<"Diem TB"<<endl;
	cout<<setfill('-')<<setw(120)<<'-'<<endl;
	cout<<setfill(' ')<<setw(120)<<' '<<endl;
}

int main(){
	HocSinh a;
	a.NhapHS();
	InBangHS();
	a.InHS();
	return 0;
}
