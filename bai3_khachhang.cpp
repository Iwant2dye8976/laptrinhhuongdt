#include <bits/stdc++.h>
using namespace std;

//Tao class KhachHang
class KhachHang{
	private:
		string HoTen,DiaChi,Sdt,loaiKH;
		int maKH,total;
		static int maKHt;
	public:
		KhachHang();
		void NhapKH();
		void InKH() const;
		int getmaKH();
		string getDiaChi();
		string getHoTen();
		void setTotal(int);
		int getTotal();
};

//Khoi tao ma khach hang
int KhachHang::maKHt = 10000;
KhachHang::KhachHang(){
	HoTen = DiaChi = Sdt = loaiKH = "";
	maKH = maKHt++;
}

//Ham nhap thong tin khach hang
void KhachHang::NhapKH(){
	cout<<"Ho va ten: ", getline(cin,HoTen);
	cout<<"Dia chi: ", getline(cin,DiaChi);
	cout<<"So dien thoai: ", getline(cin,Sdt);
	cout<<"Loai khach hang(mua le, mua buon): ", getline(cin,loaiKH);
};

//Ham in thong tin khach hang
void KhachHang::InKH() const{
	cout<<setw(24)<<left<<maKH<<setw(24)<<left<<HoTen;
	cout<<setw(24)<<left<<DiaChi<<setw(24)<<left<<Sdt;
	cout<<setw(24)<<left<<loaiKH<<endl;
};

//Lay ma khach hang, dia chi, ho ten va so phong can dat
int KhachHang::getmaKH(){return maKH;};
string KhachHang::getDiaChi(){return DiaChi;};
string KhachHang::getHoTen(){return HoTen;};
void KhachHang::setTotal(int a){
	total = a;
}
int KhachHang::getTotal(){
	return total;
}

class MatHang{
	private:
		string tenHang,nhomHang;
		int maHang,giaHang;
		static int maHt;
	public:
		MatHang();
		void nhapHang();
		void inHang();
		int getmaHang();
		string gettenHang();
		string getnhomHang();
		int getgiaHang();
};

int MatHang::maHt = 1000;
MatHang::MatHang(){
	tenHang = nhomHang = "";
	maHang = maHt++;
}

void MatHang::nhapHang(){
	cout<<"Nhap ten mat hang: ", getline(cin,tenHang);
	cout<<"Nhom hang(thoi trang, tieu dung, dien may, gia dung): ", getline(cin,nhomHang);
	cout<<"Gia ban: ", cin>>giaHang, cin.ignore();
}

void MatHang::inHang(){
	cout<<setw(30)<<left<<maHang<<setw(30)<<left<<tenHang;
	cout<<setw(30)<<left<<nhomHang<<setw(30)<<left<<giaHang<<endl;
}

int MatHang::getmaHang(){
	return maHang;
};
string MatHang::gettenHang(){
	return tenHang;
};
string MatHang::getnhomHang(){
	return nhomHang;
};
int MatHang::getgiaHang(){
	return giaHang;
};

class BangMuaHang{
	private:
		KhachHang khach;
		MatHang hang;
		int total;
	public:
		void muaHang(KhachHang a, MatHang b);
		void inBangMuaHang();
		KhachHang getDataKH();
		MatHang getDataHang();
		void inDSmua();
		void inHoaDon();
};

void BangMuaHang::muaHang(KhachHang a, MatHang b){
	khach = a;
	hang = b;
}

void BangMuaHang::inBangMuaHang(){
	cout<<setw(30)<<left<<hang.getmaHang()<<setw(30)<<left<<hang.gettenHang();
	cout<<setw(30)<<left<<hang.getnhomHang()<<setw(30)<<left<<hang.getgiaHang()<<endl;
}

void BangMuaHang::inDSmua(){
	cout<<setw(24)<<left<<khach.getHoTen()<<setw(24)<<left<<khach.getmaKH();
	cout<<setw(24)<<left<<hang.gettenHang();
	cout<<setw(24)<<left<<hang.getnhomHang()<<setw(24)<<left<<hang.getgiaHang()<<endl;
}

void BangMuaHang::inHoaDon(){
	cout<<setw(40)<<left<<khach.getHoTen()<<setw(40)<<left<<khach.getmaKH();
	cout<<setw(40)<<left<<khach.getTotal()<<endl;
}



KhachHang BangMuaHang::getDataKH(){
	return khach;
}

MatHang BangMuaHang::getDataHang(){
	return hang;
}


static void InKhachHang(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"DANH SACH KHACH HANG"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(24)<<left<<"Ma Khach Hang"<<setw(24)<<left<<"Ho Va Ten";
	cout<<setw(24)<< left<<"Dia Chi"<<setw(24)<<left<<"So Dien Thoai";
	cout<<setw(24)<<left<<"Loai Khach Hang";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InMatHang(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"DANH SACH MAT HANG"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(30)<<left<<"Ma San Pham"<<setw(30)<<left<<"Ten San Pham";
	cout<<setw(30)<< left<<"Nhom San Pham"<<setw(30)<<left<<"Gia Ban";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InDSmuaH(){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"DANH SACH MUA HANG"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(24)<<left<<"Ho ten"<<setw(24)<<left<<"Ma KH";
	cout<<setw(24)<< left<<"Ten Hang"<<setw(24)<<left<<"Nhom Hang";
	cout<<setw(24)<<left<<"Gia";
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
	cout<<setw(40)<<left<<"Ho ten"<<setw(40)<<left<<"Ma KH";
	cout<<setw(40)<<left<<"Thanh Tien";
	cout<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

bool SapxepHoten(BangMuaHang a, BangMuaHang b){
	return a.getDataKH().getHoTen()<b.getDataKH().getHoTen();
}

bool SapxepHang(BangMuaHang a, BangMuaHang b){
	return a.getDataHang().gettenHang()<b.getDataHang().gettenHang();
}

int tong(vector<KhachHang> a, vector<BangMuaHang> b, int slKH){
	for(int i=0;i<slKH;i++){
		int sum=0;
		for(auto &kh : BMH){
			if(kh.getDataKH().getmaKH()==DSKH[i].getmaKH()){
				sum+=kh.getDataHang().getgiaHang();
			}
		}
		return sum;
	}
}

int main(){
	int slSP;
	cout<<"Nhap so luong hang: ", cin>>slSP;
	vector<MatHang> DSH(slSP);
	cin.ignore();
	for(int i=0;i<slSP;i++){
		cout<<"\nNhap thong tin cho san pham thu "<<i+1<<": "<<endl;
		DSH[i].nhapHang();
	}
		if(!DSH.empty()){
			InMatHang();
			for(int i=0;i<DSH.size();i++){
				DSH[i].inHang();
			}
		}
	
	int slKH;
	cout<<"\nNhap so luong khach hang: ", cin>>slKH;
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
	
	vector<BangMuaHang> BMH;
	for(int i=0;i<slKH;i++){
		cout<<"\nMua hang cho khach hang '"<<DSKH[i].getHoTen()<<"'"<<endl;
		string loaisp;
		cout<<"Nhap loai san pham can mua(thoi trang, tieu dung, dien may, gia dung): ";
		getline(cin, loaisp);
		cout<<"Danh sach san pham "<<loaisp<<": "<<endl;
		vector<MatHang> DSmh;
		int stt = 1;
		for(int k=0;k<slSP;k++){
			if(DSH[k].getnhomHang()==loaisp){
				cout<<stt<<". Ma sp: "<<DSH[k].getmaHang()<<", ";
				cout<<DSH[k].gettenHang()<<", nhom hang: "<<DSH[k].getnhomHang();
				cout<<", gia: "<<DSH[k].getgiaHang()<<endl;
				DSmh.push_back(DSH[k]);
				stt++;
			}
		}
		int slcanmua;
		cout<<"Nhap so luong mat hang can mua(khong qua 10): ", cin>>slcanmua;
		while(slcanmua<=0 || slcanmua>10){
			cout<<"\nSo luong khong hop le!\n";
			cout<<"Vui long nhap lai: ";
			cin>>slcanmua;
		}
		while(slcanmua>0 && slcanmua<=10){
			int mahangt;
			cout<<"Nhap ma san pham can mua: ", cin>>mahangt;
			cin.ignore();
			for(int j=0;j<DSmh.size();j++){
				if(DSmh[j].getmaHang()==mahangt){
					BangMuaHang hangdamua;
					hangdamua.muaHang(DSKH[i],DSmh[j]);
					BMH.push_back(hangdamua);
				}
			}
			slcanmua--;
		}
		DSmh.clear();
	}
	system("cls");
	//In DS mua hang
	if(!BMH.empty()){
		cout<<"Danh sach mua hang\n";
		InDSmuaH();
		for(auto &kh : BMH){
				kh.inDSmua();
			}
		system("pause");
		system("cls");
	}
	//Sap xep theo ten khach hang
	if(!BMH.empty()){
		cout<<"DS mua hang sap xep theo ten khach hang\n\n";
		sort(BMH.begin(), BMH.end(), SapxepHoten);
		InDSmuaH();
		for(auto &kh : BMH){
				kh.inDSmua();
			}
		system("pause");
		system("cls");
	}
	//Sap xep theo ten hang
	if(!BMH.empty()){
		cout<<"DS mua hang sap xep theo ten hang\n\n";
		sort(BMH.begin(), BMH.end(), SapxepHang);
		InDSmuaH();
		for(auto &kh : BMH){
				kh.inDSmua();
			}
		system("pause");
		system("cls");
	}
	
	//In hoa don
	cout<<"DS Hoa Don\n";
	
	InHoaDon();
	for(auto &kh : BMH){
		kh.inHoaDon();
	}
	system("pause");
	system("cls");
		
	return 0;
}
