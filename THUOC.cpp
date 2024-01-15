#include <bits/stdc++.h>
using namespace std;

class Thuoc{
	protected:
		string Ma_thuoc,Ten_thuoc,Hang_thuoc;
		double Gia;
	public:
		//Cac ham tao
		Thuoc(){
			Ma_thuoc = Ten_thuoc = Hang_thuoc = "unknown";
			Gia = 0;
		}
		Thuoc(string ma,string ten,string hang,double gia){
			Ma_thuoc = ma;
			Ten_thuoc = ten;
			Hang_thuoc = hang;
			Gia = gia;
		}
		//Cac ham truy cap gia tri
		string getMa_thuoc(){return Ma_thuoc;};
		string getTen_thuoc(){return Ten_thuoc;};
		string getHang_thuoc(){return Hang_thuoc;};
		double getGia(){return Gia;};
		//Cac ham bien doi gia tri
		void setMa_thuoc(string ma){Ma_thuoc = ma;};
		void setTen_thuoc(string ten){Ten_thuoc = ten;};
		void setHang_thuoc(string hang){Hang_thuoc = hang;};
		void setGia(double gia){Gia = gia;};
		//Ham nhap xuat gia tri
		void NhapThuoc(){
			cout<<"Nhap ma thuoc: ",getline(cin,Ma_thuoc);
			cout<<"Nhap ten thuoc: ",getline(cin,Ten_thuoc);
			cout<<"Nhap hang thuoc: ",getline(cin,Hang_thuoc);
			cout<<"Gia: ",cin>>Gia;
			cin.ignore();
		}
		void InThuoc(int width){
			cout<<setw(width)<<left<<Ma_thuoc<<setw(width)<<left<<Ten_thuoc;
			cout<<setw(width)<<left<<Hang_thuoc<<setw(width)<<left<<Gia;
		}
		//Nap chong toan tu ==
		bool operator ==(const Thuoc& thuoc){
			return Ma_thuoc == thuoc.Ma_thuoc;
		}
};

class ThuocBo : public Thuoc{
	private:
		string Cong_dung;
	public:
		//Cac ham tao
		ThuocBo(){Cong_dung = "unknown";}
		ThuocBo(string ma_thuoc,string ten_thuoc,string hang_thuoc,double gia,string cong_dung)
		: Thuoc(), Cong_dung("unknown"){
			setMa_thuoc(ma_thuoc);
			setTen_thuoc(ten_thuoc);
			setHang_thuoc(hang_thuoc);
			setGia(gia);
		}
		//Ham nhap xuat gia tri
		void NhapThuocBo(){
			Thuoc : NhapThuoc();
			cout<<"Cong dung: ",getline(cin,Cong_dung);
		}
		void InThuocBo(int width){
			Thuoc : InThuoc(width);
			cout<<setw(width)<<left<<Cong_dung<<endl;
		}
		//Ham truy cap gia tri
		string getCong_dung(){return Cong_dung;};
		//Ham bien doi gia tri
		void setCong_dung(string cd){Cong_dung = cd;};
		//Ham huy
		~ThuocBo(){};
		
};

class KhangSinh : public Thuoc{
	private:
		string Ham_luong_sd;
	public:
		//Cac ham tao
		KhangSinh(){Ham_luong_sd = "unknown";}
		KhangSinh(string ma_thuoc,string ten_thuoc,string hang_thuoc,double gia,string ham_luong_sd)
		: Thuoc(), Ham_luong_sd("unknown"){
			setMa_thuoc(ma_thuoc);
			setTen_thuoc(ten_thuoc);
			setHang_thuoc(hang_thuoc);
			setGia(gia);
		}
		//Ham nhap xuat gia tri
		void NhapKhangSinh(){
			Thuoc : NhapThuoc();
			cout<<"Ham luong su dung: ",getline(cin,Ham_luong_sd);
		}
		void InKhangSinh(int width){
			Thuoc : InThuoc(width);
			cout<<setw(width)<<left<<Ham_luong_sd<<endl;
		}
		//Ham truy cap gia tri
		string getHam_luong_sd(){return Ham_luong_sd;};
		//Ham bien doi gia tri
		void setHam_luong_sd(string sd){Ham_luong_sd = sd;};
		//Ham huy
		~KhangSinh(){};
		
};

static void InBangThuocBo(int width){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"BANG THUOC BO"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(width)<<left<<"Ma Thuoc"<<setw(width)<<left<<"Ten Thuoc";
	cout<<setw(width)<<left<<"Hang Thuoc"<<setw(width)<<left<<"Gia";
	cout<<setw(width)<<left<<"Cong Dung"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

static void InBangKhangSinh(int width){
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"BANG KHANG SINH"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(width)<<left<<"Ma Thuoc"<<setw(width)<<left<<"Ten Thuoc";
	cout<<setw(width)<<left<<"Hang Thuoc"<<setw(width)<<left<<"Gia";
	cout<<setw(width)<<left<<"Ham Luong Su Dung"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<'-'<<endl;
	cout<<setfill(' ');
}

//Ham nhap thong tin thuoc
void ChonThuoc(vector<Thuoc> &Thuoc_List, vector<ThuocBo> &ThuocBo_List, vector<KhangSinh> &KhangSinh_List){
		int chon;
		cout<<"\n=========================================\n";
		cout<<"Vui long chon loai thuoc de nhap thong tin!\n";
		cout<<"1.Thuoc Bo||2.Khang Sinh: ";
		cin>>chon;
		while(chon!=1&&chon!=2){
			cout<<"Lua chon khong hop le!\n";
			cout<<"Vui long nhap lai!\n";
			cout<<"1.Thuoc Bo||2.Khang Sinh: ";
			cin>>chon;
		}
		cin.ignore();
		if(chon==1){
			ThuocBo a;
			cout<<"\n==============================\n";
			cout<<"\nNhap thong tin cho thuoc bo.\n";
			a.NhapThuocBo();
			ThuocBo_List.push_back(a);
		}
		else{
			KhangSinh b;
			cout<<"\n==============================\n";
			cout<<"\nNhap thong tin cho khang sinh.\n";
			b.NhapKhangSinh();
			KhangSinh_List.push_back(b);
		}
}

//Ham check thuoc da nhap them co trong danh sach chua
void CheckThuoc(vector<Thuoc> &Thuoc_List, vector<ThuocBo> &ThuocBo_List, vector<KhangSinh> &KhangSinh_List){
		int chon;
		cout<<"\n=========================================\n";
		cout<<"Vui long chon loai thuoc de nhap thong tin!\n";
		cout<<"1.Thuoc Bo||2.Khang Sinh: ";
		cin>>chon;
		while(chon!=1&&chon!=2){
			cout<<"Lua chon khong hop le!\n";
			cout<<"Vui long nhap lai!\n";
			cout<<"1.Thuoc Bo||2.Khang Sinh: ";
			cin>>chon;
		}
		cin.ignore();
		if(chon==1){
			int dem=0;
			ThuocBo a;
			cout<<"\n==============================\n";
			cout<<"\nNhap thong tin cho thuoc bo.\n";
			a.NhapThuocBo();
			for(auto &tb : ThuocBo_List){
				if(a==tb) //Su dung nap chong toan tu ==
					dem++;
			}
			if(dem>0){
				cout<<"Thuoc bo nay da co trong danh sach!";
			}
			else{
				cout<<"Thuoc bo nay chua co trong danh sach!\n";
				ThuocBo_List.push_back(a);
				cout<<"Da them vao danh sach!";
			}
		}
		else{
			int dem=0;
			KhangSinh b;
			cout<<"\n==============================\n";
			cout<<"\nNhap thong tin cho khang sinh.\n";
			b.NhapKhangSinh();
			for(auto &ks : KhangSinh_List){
				if(b==ks) //Su dung nap chong toan tu ==
					dem++;
			}
			if(dem>0){
				cout<<"Khang sinh nay da co trong danh sach!";
			}
			else{
				cout<<"Khang sinh nay chua co trong danh sach!\n";
				KhangSinh_List.push_back(b);
				cout<<"Da them vao danh sach!";
			}
		}
}


int main(){
	int soluong;
	cout<<"Nhap so luong thuoc: ",cin>>soluong;
	while(soluong<=0||soluong>=10){
		cout<<"\nSo luong nhap khong hop le!\n";
		cout<<"Vui long nhap lai: ",cin>>soluong;
	}
	vector<Thuoc> Thuoc_List;
	vector<ThuocBo> ThuocBo_List;
	vector<KhangSinh> KhangSinh_List;
	for(int i=0;i<soluong;i++){ChonThuoc(Thuoc_List,ThuocBo_List,KhangSinh_List);}//Da viet gon thanh ham void ChonThuoc()
	system("cls");
	
	if(!ThuocBo_List.empty()){
		InBangThuocBo(24);
		for(auto tb : ThuocBo_List){
			tb.InThuocBo(24);
		}
		system("pause");
		system("cls");
	}
	
	if(!KhangSinh_List.empty()){
		InBangKhangSinh(24);
		for(auto ks : KhangSinh_List){
			ks.InKhangSinh(20);
		}
		system("pause");
		system("cls");
	}
	
	//Nhap them va check xem da co loai thuoc do trong danh sach chua
	cout<<"===========================\n";
	cout<<"Nhap them thuoc moi.\n";
	CheckThuoc(Thuoc_List,ThuocBo_List,KhangSinh_List);
	return 0;
}
