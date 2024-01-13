#include <bits/stdc++.h>
using namespace std;

class KhachHang{
	private:
		static int maKHt;
		int maKH;
		string Hoten,Diachi,Sdt,LoaiKH;
	public:
		KhachHang(){
			maKH = maKHt++;
		};
		void NhapKH(){
			cout<<"Nhap ho ten: ",getline(cin,Hoten);
			cout<<"Dia chi: ",getline(cin,Diachi);
			cout<<"So dien thoai: ",getline(cin,Sdt);
			cout<<"Loai khach hang: ",getline(cin,LoaiKH);
		};
		void InKH(int width){
			cout<<setw(width)<<left<<maKH<<setw(width)<<left<<Hoten;
			cout<<setw(width)<<left<<Diachi<<setw(width)<<left<<Sdt;
			cout<<setw(width)<<left<<LoaiKH;
		};
		int getmaKH(){return maKH;};
		string getHoten(){return Hoten;};
		string getDiachi(){return Diachi;};
		string getSdt(){return Sdt;};
		string getLoaiKH(){return LoaiKH;};
};

int KhachHang::maKHt = 10000;

class LoaiDV{
	private:
		static int maDVt;
		int maDV,GiaCuoc;
		string MoTa;
	public:
		LoaiDV(){
			maDV = maDVt++;
		};
		void NhapDV(){
			cout<<"Mo ta: ",getline(cin,MoTa);
			cout<<"Muc gia cuoc: ",cin>>GiaCuoc;
			cin.ignore();
		};
		void InDV(){
			cout<<setw(40)<<left<<maDV<<setw(40)<<left<<MoTa;
			cout<<setw(40)<<left<<GiaCuoc<<endl;
		};
		int getmaDV(){return maDV;};
		string getMoTa(){return MoTa;};
		int getGiaCuoc(){return GiaCuoc;};
};

int LoaiDV::maDVt = 100;

class HoaDon{
	private:
		KhachHang kh;
		LoaiDV dv;
		int SoLuongSD;
	public:
		KhachHang getDataKH(){
			return kh;
		}
		LoaiDV getDataDV(){
			return dv;
		}
		void NhapHD(KhachHang a,LoaiDV b,int soluongsd){
			kh = a;
			dv = b;
			SoLuongSD = soluongsd;
		}
		void InHD(){
			cout<<setw(20)<<left<<kh.getmaKH()<<setw(20)<<left<<kh.getHoten();
			cout<<setw(20)<<left<<dv.getmaDV()<<setw(20)<<left<<dv.getMoTa();
			cout<<setw(20)<<left<<dv.getGiaCuoc()<<setw(20)<<left<<SoLuongSD<<endl;
		}
		int getSoLuongSD(){return SoLuongSD;};
		int Tong(){return SoLuongSD * dv.getGiaCuoc();};
};

static void InBangKH(){
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(65) << right << "DANH SACH KHACH HANG" << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(24) << left << "Ma Khach Hang" << setw(24) << left << "Ho Ten";
	cout << setw(24) << left << "Dia Chi" << setw(24) << left << "SDT";
	cout<<setw(24)<<left<<"Loai KH";
	cout << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
}

static void InBangDV(){
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(65) << right << "DANH SACH DICH VU" << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(40) << left << "Ma Dich Vu" << setw(40) << left << "Mo Ta";
	cout << setw(40) << left << "Gia Cuoc";
	cout << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
}


static void InBangHD(){
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(65) << right << "DANH SACH HOA DON" << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma Khach Hang" << setw(20) << left << "Ho Ten";
	cout << setw(20) << left << "Ma Dich Vu"<<setw(20)<<left<<"Mo Ta";
	cout<<setw(20)<<left<<"Gia Cuoc"<<setw(20)<<left<<"So Luong Su Dung";
	cout << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
}

static void ThanhTien(){
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(65) << right << "DANH SACH KHACH HANG" << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
	cout << setw(20) << left << "Ma Khach Hang" << setw(20) << left << "Ho Ten";
	cout << setw(20) << left << "Dia Chi" << setw(20) << left << "SDT";
	cout<<setw(20)<<left<<"Loai KH"<<setw(20)<<left<<"Tong";
	cout << endl;
	cout << setfill('-');
	cout << setw(120) << '-' << endl;
	cout << setfill(' ');
}

bool SapXepHoTen(HoaDon a, HoaDon b){
	return a.getDataKH().getHoten() < b.getDataKH().getHoten();
}

bool SapXepSLSuDung(HoaDon a, HoaDon b){
	return a.getSoLuongSD() > b.getSoLuongSD();
}

int main(){
	//Khach Hang
	int slKH;
	cout<<"Nhap so luong khach hang: ";
	cin>>slKH, cin.ignore();
	vector<KhachHang>DSKH(slKH);
	for(int i=0;i<slKH;i++){
		cout<<"\n====================================";
		cout<<"\nNhap thong tin cho khach hang thu "<<i+1<<": \n";
		DSKH[i].NhapKH();
	}
	system("cls");
	if(!DSKH.empty()){
		InBangKH();
		for(auto &kh : DSKH){
			kh.InKH(24);
				cout<<"\n";
		}
	}
	system("pause");
	system("cls");
	
	//Dich Vu
	int slDV;
	cout<<"Nhap so luong dich vu: ", cin>>slDV;
	cin.ignore();
	vector<LoaiDV> DSDV(slDV);
	for(int i=0;i<slDV;i++){
		cout<<"\n====================================";
		cout<<"\nNhap thong tin cho dich vu "<<i+1<<": \n";
		DSDV[i].NhapDV();
	}
	system("cls");
	if(!DSDV.empty()){
		InBangDV();
		for(auto &dv : DSDV){
			dv.InDV();
		}
	}
	
	vector<HoaDon> DSHD;
	for(int j=0;j<slKH;j++){
		cout<<"\n============================\n";
		cout<<"Chon dich vu cho khach hang "<<DSKH[j].getHoten()<<": \n";
		int chon;
		cout<<"Nhap 1.Thue dich vu||0.KH ke tiep: ", cin>>chon;
		while(chon<0||chon>1){
			cout<<"Lua chon khong hop le!\n";
			cout<<"Vui long nhap lai!\n";
			cout<<"Nhap 1.Thue dich vu||0.KH ke tiep: ", cin>>chon;
		}
		if(chon==1){
			HoaDon hd;
			int soluong = 3,ma;
			while(soluong!=0){
				for(int k=0;k<DSDV.size();k++){
					int n;
					do{
						cout<<"Moi khach hang khong su dung qua 3 dich vu!\n";
						cout<<"Nhap so luong su dung dich vu "<<DSDV[k].getMoTa()<<": ";
						cin>>n;
					}while(soluong-n<0);
					hd.NhapHD(DSKH[j],DSDV[k],n);
					DSHD.push_back(hd);
					soluong-=n;
					if(soluong==0) break;
				}	
			}	
		}
		else continue;
	}
	//Danh Sach Hoa Don
	system("cls");
	if(!DSHD.empty()){
		InBangHD();
		for(auto &hd : DSHD){
			if(hd.getSoLuongSD()!=0)
				hd.InHD();
		}
	}
	system("pause");
	system("cls");
	//DSHD theo ho ten
	system("cls");
	sort(DSHD.begin(),DSHD.end(),SapXepHoTen);
	if(!DSHD.empty()){
		cout<<"Danh sach hoa don sap xep theo ho ten\n";
		InBangHD();
		for(auto &hd : DSHD){
			if(hd.getSoLuongSD()!=0)
				hd.InHD();
		}
	}
	system("pause");
	system("cls");
	//DSHD theo so luong su dung
	system("cls");
	sort(DSHD.begin(),DSHD.end(),SapXepSLSuDung);
	if(!DSHD.empty()){
		cout<<"Danh sach hoa don sap xep theo so luong su dung giam dan\n";
		InBangHD();
		for(auto &hd : DSHD){
			if(hd.getSoLuongSD()!=0)
				hd.InHD();
		}
	}
	system("pause");
	system("cls");
	//Tinh Tien
	if(!DSKH.empty()){
		ThanhTien();
		for(auto &kh : DSKH){
			int Tongtien=0;
			for(auto &hd : DSHD){
				if(hd.getDataKH().getmaKH() == kh.getmaKH()){
					Tongtien += hd.Tong();
				}
			}
			kh.InKH(20);
			cout<<setw(100)<<left<<Tongtien<<endl;
		}
	}		
	return 0;
}
