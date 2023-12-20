#include <bits/stdc++.h>
using namespace std;

//Tao class Nguoi
class Nguoi{
	protected:
		int tuoi;
		string Hoten,Sdt,Diachi;
	public:
		Nguoi();
		void NhapNguoi();
		void InNguoi();
		string getHoten();
		string getSdt();
		string getDiachi();
		int getTuoi();
};

//Ham khoi tao Nguoi
Nguoi::Nguoi(){
	Hoten = Sdt = Diachi = "";
	tuoi = 0;
}

void Nguoi::NhapNguoi(){
	cout<<"Ho va ten: ", getline(cin,Hoten);
	cout<<"Tuoi: ", cin>>tuoi;
	cin.ignore();
	cout<<"So dien thoai: ", getline(cin,Sdt);
	cout<<"Dia chi: ", getline(cin,Diachi);
}

void Nguoi::InNguoi(){
	cout<<setw(37)<<left<<Hoten<<setw(37)<<left<<tuoi;
	cout<<setw(37)<<left<<Sdt<<setw(37)<<left<<Diachi;
}

string Nguoi::getHoten(){
	return Hoten;
}

string Nguoi::getDiachi(){
	return Diachi;
}

string Nguoi::getSdt(){
	return Sdt;
}

int Nguoi::getTuoi(){
	return tuoi;
}

//Tao class BacSi
class BacSi : public Nguoi{
	private:
		string MaBS;
		int SoNgayLam,TienCong;
		Nguoi a;
	public:
		BacSi(Nguoi a);
		void NhapBS();
		void InBS();
		int TienCongThang();
		int getSoNgayLam();
};


//Khoi tao BacSi

BacSi::BacSi(Nguoi a){
	Hoten = a.getHoten();
	tuoi = a.getTuoi();
	Sdt = a.getSdt();
	Diachi = a.getDiachi();
	SoNgayLam = TienCong = 0;
	MaBS = "";
}

void BacSi::NhapBS(){
	cout<<"Ma bac si: ", getline(cin,MaBS);
	cout<<"So ngay lam viec: ", cin>>SoNgayLam;
	cout<<"Tien cong: ", cin>>TienCong;
	cin.ignore();
}

//In Bac si
void BacSi::InBS(){
	cout<<setw(18)<<left<<Hoten<<setw(18)<<left<<tuoi;
	cout<<setw(18)<<left<<Sdt<<setw(18)<<left<<Diachi;
	cout<<setw(18)<<left<<MaBS<<setw(18)<<left<<SoNgayLam;
	cout<<setw(18)<<left<<TienCong<<setw(18)<<left<<TienCongThang()<<endl;
}

//Tra ve tien cong = son gay lam * tien cong/ngay
int BacSi::TienCongThang(){
	return SoNgayLam * TienCong;
}

//Lay so ngay lam viec
int BacSi::getSoNgayLam(){
	return SoNgayLam;
}

class BenhNhan : public Nguoi{
	private:
		string MaBN;
		Nguoi a;
	public:
		BenhNhan(Nguoi a);
		void NhapBN();
		void InBN();
		int getTuoiBN();
};

BenhNhan::BenhNhan(Nguoi a){
	Hoten = a.getHoten();
	tuoi = a.getTuoi();
	Sdt = a.getSdt();
	Diachi = a.getDiachi();
	MaBN = "";
}

void BenhNhan::NhapBN(){
	cout<<"Ma benh nhan: ", getline(cin,MaBN);
}

void BenhNhan::InBN(){
	cout<<setw(29)<<left<<Hoten<<setw(29)<<left<<tuoi;
	cout<<setw(29)<<left<<Sdt<<setw(29)<<left<<Diachi;
	cout<<setw(29)<<left<<MaBN<<endl;
}

int BenhNhan::getTuoiBN(){
	return tuoi;
}


//Cac ham in bang

static void InBangNguoi(){
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(85)<<right<<"DANH SACH NGUOI"<<endl;
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(37)<<left<<"Ho ten"<<setw(37)<<left<<"Tuoi";
	cout<<setw(37)<< left<<"So dien thoai"<<setw(37)<<left<<"Dia chi";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InBangBacSi(){
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(85)<<right<<"DANH SACH BAC SI"<<endl;
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(18)<<left<<"Ho ten"<<setw(18)<<left<<"Tuoi";
	cout<<setw(18)<< left<<"So dien thoai"<<setw(18)<<left<<"Dia chi";
	cout<<setw(18)<<left<<"Ma Bac Si"<<setw(18)<<left<<"So ngay lam viec";
	cout<<setw(18)<<left<<"Tien cong/ngay"<<setw(18)<<left<<"Tien cong thang";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InBangBenhNhan(){
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(82)<<right<<"DANH SACH BENH NHAN"<<endl;
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(29)<<left<<"Ho ten"<<setw(29)<<left<<"Tuoi";
	cout<<setw(29)<< left<<"So dien thoai"<<setw(29)<<left<<"Dia chi";
	cout<<setw(29)<<left<<"Ma Benh Nhan";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(148)<<'-'<<endl;
	cout<<setfill(' ');
}

int sosanhNgayLamViec(vector<BacSi> &dsBS){
	int maxngay = dsBS[0].getSoNgayLam();
	for(auto &bs : dsBS){
		if(bs.getSoNgayLam()>maxngay){
			maxngay = bs.getSoNgayLam();
		}
	}
	return maxngay;
}

int main(){
	int slNguoi;
	cout<<"Nhap so luong nguoi: ", cin>>slNguoi;

	//Kiem tra dieu kien 0 < slNguoi <= 100
	while(slNguoi<=0 || slNguoi>100){
		cout<<"\nSo luong khong hop le!"<<endl;
		cout<<"Vui long nhap lai: ", cin>>slNguoi;
	}; cin.ignore();
	vector<BacSi> dsBacSi;
	vector<BenhNhan> dsBenhNhan;
	vector<Nguoi> dsNguoi;
	int thutubacsi = 1;
	int thutubenhnhan = 1;
	for(int i=0;i<slNguoi;i++){
		int loai;
		cout<<"\nHay chon vai tro. Nhap 1-Bac Si||2-Benh Nhan: ";
		cin>>loai, cin.ignore();
		while(loai<=0 || loai >=3){
			cout<<"\nVai tro khong hop le!\n";
			cout<<"Vui long nhap lai! Nhap 1-Bac Si||2-Benh Nhan: ";
			cin>>loai;
			cin.ignore();
		}
			if(loai>0 && loai<3){
				Nguoi a;
				if(loai == 1){
					cout<<"Nhap thong tin cho bac si thu "<<thutubacsi<<": \n";
					a.NhapNguoi();
					BacSi bs(a); //Khoi tao bac si voi thong tin tu Nguoi
					bs.NhapBS();
					dsBacSi.push_back(bs);
					dsNguoi.push_back(a);
					thutubacsi++;
				}
				else{
					cout<<"Nhap thong tin cho benh nhan thu "<<thutubenhnhan<<": \n";
					a.NhapNguoi();
					BenhNhan bn(a);
					bn.NhapBN();
					dsBenhNhan.push_back(bn);
					dsNguoi.push_back(a);
					thutubenhnhan++;
				}
			}
	}
	system("cls");
	if(!dsNguoi.empty()){
		cout<<"Danh sach Nguoi da nhap thong tin.\n\n";
		InBangNguoi();
		for(auto &nguoi : dsNguoi){
			nguoi.InNguoi();
		}
		system("pause");
		system("cls");
	}

	if(!dsBacSi.empty()){
		int max = sosanhNgayLamViec(dsBacSi);
		cout<<"Danh sach nhung bac si co so ngay lam viec nhieu nhat.\n\n";
		InBangBacSi();
		for(auto &bs : dsBacSi){
			if(bs.getSoNgayLam()==max){
				bs.InBS();
			}
		}
		system("pause");
		system("cls");
	}
	
	if(!dsBenhNhan.empty()){
		int dem=0;
		for(auto &check : dsBenhNhan){
			if(check.getTuoiBN()<=10){
				dem++;
				break;
			}
		}
		if(dem>0){
			cout<<"Danh sach benh nhan <= 10 tuoi.\n\n";
			InBangBenhNhan();
			for(auto &bn : dsBenhNhan){
				if(bn.getTuoiBN()<=10){
					bn.InBN();
				}
			}
		system("pause");
		system("cls");
		}
		else{
			cout<<"Khong co benh nhan nao <= 10 tuoi!";
		}
	}
	
	return 0;
}
