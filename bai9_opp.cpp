#include <bits/stdc++.h>
using namespace std;

//Tao class KhachHang
class KhachHang{
	private:
		string HoTen,DiaChi,Sdt,loaiPhong;
		int soPhong,maKH;
		static int maKHt;
	public:
		KhachHang();
		void NhapKH();
		void InKH() const;
		int getmaKH();
		string getDiaChi();
		string getHoTen();
		int getsoPhong();
		void giamsoPhong(int soluong);
};

//Khoi tao ma khach hang
int KhachHang::maKHt = 100;
KhachHang::KhachHang(){
	HoTen = DiaChi = Sdt = loaiPhong = "";
	soPhong = 0;
	maKH = maKHt++;
}

//Ham nhap thong tin khach hang
void KhachHang::NhapKH(){
	cout<<"Ho va ten: ", getline(cin,HoTen);
	cout<<"Dia chi: ", getline(cin,DiaChi);
	cout<<"So dien thoai: ", getline(cin,Sdt);
	cout<<"So phong can thue: ", cin>>soPhong, cin.ignore();
	cout<<"Loai phong: ", getline(cin,loaiPhong);
};

//Ham in thong tin khach hang
void KhachHang::InKH() const{
	cout<<setw(20)<<left<<maKH<<setw(20)<<left<<HoTen;
	cout<<setw(20)<<left<<DiaChi<<setw(20)<<left<<Sdt;
	cout<<setw(20)<<left<<soPhong<<setw(20)<<left<<loaiPhong<<endl;
};

//Ham giam so luong phong can dat cua khach hang
void KhachHang::giamsoPhong(int soluong){
	if(soPhong-soluong>=0) soPhong-=soluong;
}

//Lay ma khach hang, dia chi, ho ten va so phong can dat
int KhachHang::getmaKH(){return maKH;};
string KhachHang::getDiaChi(){return DiaChi;};
string KhachHang::getHoTen(){return HoTen;};
int KhachHang::getsoPhong(){return soPhong;};


//Tao class Phong
class Phong{
	private:
		string kieuPhong;
		int muctienThue,soPhong,makieuPhong;
		static int makieuPhongt;
	public:
		Phong();
		void NhapPhong();
		void InPhong() const;
		void giamsoPhong(int soluong);
		int getmakieuPhong();
		string getkieuPhong();
		int getmuctienThue();
		int getsoPhong();
};

//Ham khoi tao ma kieu phong
int Phong::makieuPhongt = 100;
Phong::Phong(){
	kieuPhong = "";
	soPhong = muctienThue = 0;
	makieuPhong = makieuPhongt++;
}

//Ham nhap thong tin cua phong cho thue
void Phong::NhapPhong(){
	cout<<"Kieu phong(don, doi, vip): ", getline(cin,kieuPhong);
	cout<<"So phong co the cho thue: ", cin>>soPhong;
	cout<<"Tien thue phong: ", cin>>muctienThue, cin.ignore();
	cout<<endl;
};

//Ham in ra thong tin phong
void Phong::InPhong() const{
	cout<<setw(30)<<left<<makieuPhong<<setw(30)<<left<<kieuPhong;
	cout<<setw(30)<<left<<soPhong<<setw(30)<<left<<muctienThue<<endl;
};

//Ham giam so luong phong khi khach hang dat
void Phong::giamsoPhong(int soluong) {
    if(soPhong-soluong>=0) soPhong-=soluong;
}

//Lay ma kieu phong, kieu phong(don, doi, vip), so phong, gia thue moi phong
int Phong::getmakieuPhong(){return makieuPhong;}
string Phong::getkieuPhong(){return kieuPhong;}
int Phong::getsoPhong(){return soPhong;}
int Phong::getmuctienThue(){return muctienThue;}

//Tao class BangSapXep
class BangSapXep{
	private:
		KhachHang khachhang;
		Phong phong;
		int songayThue,soluongThue;
	public:
		void NhapP(KhachHang a, Phong b, int songayThue_, int soluongThue_);
		void InBang();
		int getsongayThue();
		int getsoluongThue();
		KhachHang getDataKhach();
		Phong getDataPhong();
		void XuatHoaDon();
};

//Ham nhap thong tin khach hang thue phong
void BangSapXep::NhapP(KhachHang a, Phong b, int songayThue_, int soluongThue_){
	khachhang = a;
	phong = b;
	songayThue = songayThue_;
	soluongThue = soluongThue_;
}

//In danh sach khach hang thue phong
void BangSapXep::InBang(){
	cout<<setw(20)<<left<<phong.getmakieuPhong()<<setw(20)<<left<<khachhang.getHoTen();
	cout<<setw(20)<<left<<phong.getkieuPhong()<<setw(20)<<left<<songayThue;
	cout<<setw(20)<<left<<soluongThue<<setw(20)<<left<<phong.getmuctienThue()<<endl;
}

//Lay so ngay thue, so luong thue
int BangSapXep::getsongayThue(){return songayThue;};
int BangSapXep::getsoluongThue(){return soluongThue;};

//Lay du lieu cua phong va khach hang
Phong BangSapXep::getDataPhong(){return phong;};
KhachHang BangSapXep::getDataKhach(){return khachhang;};

//In hoa don cho moi khach hang
void BangSapXep::XuatHoaDon(){
	cout<<setw(17)<<left<<khachhang.getmaKH()<<setw(17)<<left<<khachhang.getHoTen();
	cout<<setw(17)<<left<<phong.getkieuPhong()<<setw(17)<<left<<songayThue<<setw(17)<<soluongThue;
	cout<<setw(17)<<left<<phong.getmuctienThue()<<setw(17)<<left<<soluongThue*phong.getmuctienThue()<<endl;
}


//Cac ham ve bang
static void InKhachHang(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"DANH SACH KHACH HANG"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(20)<<left<<"Ma Khach Hang"<<setw(20)<<left<<"Ho Va Ten";
	cout<<setw(20)<< left<<"Dia Chi"<<setw(20)<<left<<"So Dien Thoai";
	cout<<setw(20)<<left<<"So Phong Can Thue"<<setw(20)<<left<<"Loai Phong";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InPhong(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"DANH SACH PHONG"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(30)<<left<<"Ma Kieu Phong"<<setw(30)<<left<<"Kieu Phong";
	cout<<setw(30)<< left<<"So Phong Co The Cho Thue"<<setw(30)<<left<<"Gia Thue Phong";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InPhongDaDat(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"DANH SACH DAT PHONG"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(20)<<left<<"Ma Kieu Phong"<<setw(20)<<left<<"Nguoi Thue";
	cout<<setw(20)<< left<<"Kieu Phong"<<setw(20)<<left<<"So Ngay Thue"<<setw(20)<<left<<"So Luong";
	cout<<setw(20)<<left<<"Gia Thue";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InHoaDon(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"HOA DON"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(17)<<left<<"Ma Khach Hang"<<setw(17)<<left<<"Ho Ten";
	cout<<setw(17)<< left<<"Kieu Phong"<<setw(17)<<left<<"So Ngay Thue"<<setw(17)<<left<<"So Luong";
	cout<<setw(17)<<left<<"Gia Mot Phong"<<setw(17)<<left<<"Tong";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

//So sanh theo loai phong
static bool SapXepLoaiPhong(Phong a, Phong b){return a.getkieuPhong() < b.getkieuPhong();}

//So sanh theo so phong con lai co the cho thue
static bool SapXepSoPhong(Phong a, Phong b){return a.getsoPhong() < b.getsoPhong();}



int main(){
	//Nhap va in danh sach phong	
	int slPhong;
	cout<<"Nhap so luong phong cho thue: ", cin>>slPhong;
	vector<Phong> DSP(slPhong);
	cin.ignore();
	for(int i=0;i<slPhong;i++){
		cout<<"Nhap thong tin cho phong thu "<<i+1<<": "<<endl;
		DSP[i].NhapPhong();
	}
		if(!DSP.empty()){
			InPhong();
			for(int i=0;i<DSP.size();i++){
				DSP[i].InPhong();
			}
		}
	
	//Nhap va in danh sach khach hang
	int slKH;
	cout<<"\nNhap so khach hang: ", cin>>slKH;
	vector<KhachHang> DSKH(slKH);
	cin.ignore();
	for(int i=0;i<slKH;i++){
		cout<<"\nNhap thong tin cho khach hang thu "<<i+1<<": "<<endl;
		DSKH[i].NhapKH();
	}
		if(!DSKH.empty()){
			InKhachHang();
			for(int i=0;i<DSKH.size();i++){
				DSKH[i].InKH();
			}
		}
	
	//Nhap va in danh sach cho khach hang thue phong		
	vector<BangSapXep> BSX;
	for(int i=0;i<slKH;i++){
		while(DSKH[i].getsoPhong()>0){
			cout<<"\nChon phong cho khach hang: "<<DSKH[i].getHoTen()<<endl;
			for(int j=0;j<DSP.size();j++){
				cout << "Phong so " << DSP[j].getmakieuPhong() << ", kieu " << DSP[j].getkieuPhong();
				cout << ", so phong con lai: " << DSP[j].getsoPhong() << endl;
			}
			int ma;
			cout<<"Nhap ma kieu phong muon thue: ", cin>>ma;
			for(int k=0;k<DSP.size();k++){
				if(ma==DSP[k].getmakieuPhong()){
					if(DSP[k].getsoPhong()>0){
						cout<<"Con "<<DSP[k].getsoPhong()<<" phong voi ma kieu "<<DSP[k].getmakieuPhong()<<" co the thue!"<<endl;
						BangSapXep NhanPhong;
						int songayThue_,soluongThue_;
						cout<<"Nhap so luong phong can thue: ", cin>>soluongThue_;
						while(DSP[k].getsoPhong()-soluongThue_<0 || DSKH[i].getsoPhong()-soluongThue_<0){
							cout<<"\nSo luong phong can thue khong hop le!"<<endl;
							cout<<"Vui long nhap lai: ", cin>>soluongThue_;
						};
						cout<<"So ngay thue: ", cin>>songayThue_;
						while(songayThue_<=0){
							cout<<"\nSo ngay thue khong hop le!"<<endl;
							cout<<"Vui long nhap lai: ", cin>>songayThue_;
						}
						NhanPhong.NhapP(DSKH[i],DSP[k],songayThue_,soluongThue_);
						DSP[k].giamsoPhong(soluongThue_);
						DSKH[i].giamsoPhong(soluongThue_);
						BSX.push_back(NhanPhong);
						break;
					}
					else if(DSP[k].getsoPhong()==0) cout<<"Da het phong can thue!/n"<<"Vui long chon phong khac!"<<endl;
				}
				else {
					if(k==DSP.size()-1 && ma!=DSP[k].getmakieuPhong()){
					cout<<"Khong tim thay kieu ma phong nay!\n"<<"Vui long nhap lai!"<<endl;
					break;
					}
				}
			}
		}
	}
		if(!BSX.empty()){
			InPhongDaDat();
			for(int i=0;i<BSX.size();i++){
				BSX[i].InBang();
			}
		}
	
	//Sap xep theo loai phong
	cout<<"\nSap xep danh sach sap xep phong theo loai phong:"<<endl;
	sort(DSP.begin(),DSP.end(),SapXepLoaiPhong);
	InPhong();
	for(auto sx : DSP){
		sx.InPhong();
	}
	
	//Sap xep theo so luong phong con lai co the cho thue
	cout<<"\nSap xep danh sach sap xep phong theo so phong con lai:"<<endl;
	sort(DSP.begin(),DSP.end(),SapXepSoPhong);
	InPhong();
	for(auto sx : DSP){
		sx.InPhong();
	}
	
	//In hoa don cho khach hang
	cout<<"\nLap hoa don cho moi khach hang:"<<endl;
	InHoaDon();
	for(auto kh : BSX){
		kh.XuatHoaDon();
	}
	return 0;
}
