#include <bits/stdc++.h>
using namespace std;
class HoaQua{
	protected:
		string Mahoaqua, Tenhoaqua, Xuatsu;
		double Gia, Thanhtien = 0;
	public:
		//Ham tao
		HoaQua(){
			Mahoaqua = Tenhoaqua = Xuatsu = "Unknown";
			Gia = Thanhtien = 0;
		}
		//Ham Nhap Xuat
		void NhapHoaQua(){
			cout<<"Ma hoa qua: ", getline(cin,Mahoaqua);
			cout<<"Ten hoa qua: ", getline(cin,Tenhoaqua);
			cout<<"Xuat su: ", getline(cin,Xuatsu);
			cout<<"Gia: ", cin>>Gia;
		}
		void InHoaQua(int width){
			cout<<setw(width)<<left<<Mahoaqua<<setw(width)<<left<<Tenhoaqua;
			cout<<setw(width)<<left<<Xuatsu<<setw(width)<<left<<Gia;
		}
		//Ham truy cap va bien doi
		string getMahoaqua(){return Mahoaqua;};
		string getTenhoaqua(){return Tenhoaqua;};
		string getXuatsu(){return Xuatsu;};
		double getGia(){return Gia;};
		double getThanhtien(){return Thanhtien;};
		void setMahoaqua(string ma){Mahoaqua = ma;};
		void setTenhoaqua(string ten){Mahoaqua = ten;};
		void setXuatsu(string sx){Mahoaqua = sx;};
		double setGia(double gia){Gia = gia;};
		//Nap chong toan tu +
		friend HoaQua operator+(const HoaQua& hq1, const HoaQua& hq2) {
        	HoaQua result;
        	result.Thanhtien = hq1.Thanhtien + hq2.Thanhtien;
        	return result;
    	}
};

class DuaHau : public HoaQua{
	private:
		double Khoiluong;
	public:
		//Ham tao
		DuaHau(){Khoiluong = 0;}
		DuaHau(string mahoaqua, string tenhoaqua, string xuatsu, double gia, double khoiluong)
    	: HoaQua(), Khoiluong(khoiluong) {
    	setMahoaqua(mahoaqua);
    	setTenhoaqua(tenhoaqua);
    	setXuatsu(xuatsu);
    	setGia(gia);
}

		//Ham nhap, xuat
		void NhapDuaHau(){
			HoaQua : NhapHoaQua();
			cout<<"Khoi luong(kg): ", cin>>Khoiluong;
			cin.ignore();
		}
		void InDuaHau(int width){
			HoaQua : InHoaQua(width);
			cout<<setw(width)<<left<<Khoiluong<<endl;
			TongDuaHau();
		}
		void TongDuaHau(){Thanhtien = Gia * Khoiluong;};
		//Ham huy
		~DuaHau(){};
};

class QuaDua : public HoaQua{
	private:
		int Soluong;
	public:
		//Ham tao
		QuaDua(){Soluong = 0;}
		QuaDua(string mahoaqua, string tenhoaqua, string xuatsu, double gia, int Soluong)
    	: HoaQua(), Soluong(Soluong) {
    	setMahoaqua(mahoaqua);
    	setTenhoaqua(tenhoaqua);
    	setXuatsu(xuatsu);
    	setGia(gia);
    	}
		//Ham nhap, xuat
		void NhapQuaDua(){
			HoaQua : NhapHoaQua();
			cout<<"So luong: ", cin>>Soluong;
			cin.ignore();
		}
		void InQuaDua(int width){
			HoaQua : InHoaQua(width);
			cout<<setw(width)<<left<<Soluong<<endl;
			TongQuaDua();
		}
		void TongQuaDua(){Thanhtien = Gia * Soluong;};
		//Ham huy
		~QuaDua(){};
};


static void InDuaHau(int width){
	cout<<setfill('-');
	cout<<setw(120)<<left<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"BANG DON HANG DUA HAU"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<left<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(width)<<left<<"MA HOA QUA"<<setw(width)<<left<<"TEN HOA QUA";
	cout<<setw(width)<<left<<"XUAT SU"<<setw(width)<<left<<"GIA";
	cout<<setw(width)<<left<<"KHOI LUONG"<<endl;
	cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
}

static void InQuaDua(int width){
	cout<<setfill('-');
	cout<<setw(120)<<left<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(65)<<right<<"BANG DON HANG QUA DUA"<<endl;
	cout<<setfill('-');
	cout<<setw(120)<<left<<'-'<<endl;
	cout<<setfill(' ');
	cout<<setw(width)<<left<<"MA HOA QUA"<<setw(width)<<left<<"TEN HOA QUA";
	cout<<setw(width)<<left<<"XUAT SU"<<setw(width)<<left<<"GIA";
	cout<<setw(width)<<left<<"SO LUONG"<<endl;
	cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
}

int main(){
	int soluong;
	cout<<"Nhap so luong hoa qua can mua (Lon hon 0 va nho hon 10): ", cin>>soluong;
	while(soluong>=10||soluong<=0){
		cout<<"\nSo luong hoa qua khong hop le!\n";
		cout<<"Vui long nhap lai: ";
		cin>>soluong;
	}
	vector<HoaQua> HoaQuaList;
	vector<DuaHau> DuaHauList;
	vector<QuaDua> QuaDuaList;
	for(int i=0;i<soluong;i++){
		int chon;
		cout<<"\n===========================================\n";
		cout<<"Nhap lua chon|1.Mua dua hau|2.Mua qua dua: ",cin>>chon;
		while(chon<1||chon>2){
			cout<<"\nLua chon khong hop le!\n";
			cout<<"Vui long nhap lai: ";
			cin>>chon;
		}
		cin.ignore(); 
		if(chon==1){
			DuaHau a;
			cout<<"\n===========================================\n";
			cout<<"Nhap thong tin cho don hang dua hau: "<<endl;
			a.NhapDuaHau();
			a.TongDuaHau();
			DuaHauList.push_back(a);
		}
		else{
			QuaDua b;
			cout<<"\n===========================================\n";
			cout<<"Nhap thong tin cho don hang qua dua: "<<endl;
			b.NhapQuaDua();
			b.TongQuaDua();
			QuaDuaList.push_back(b);
		}
	}
	//In danh sach hoa don mua dua hau
	system("cls");
	if(!DuaHauList.empty()){
		InDuaHau(24);
		for(auto &dh : DuaHauList){
			dh.InDuaHau(24);
		}
	system("pause");
	system("cls");
	}
	
	//In danh sach mua qua dua
	if(!QuaDuaList.empty()){
		InQuaDua(24);
		for(auto &qd : QuaDuaList){
			qd.InQuaDua(24);
		}
	system("pause");
	system("cls");
	}
	
	//Nap chong toan tu
	HoaQua totalOrder;
	//Duyet hoa don dua hau
    for (const DuaHau& duaHau : DuaHauList) {
        totalOrder = totalOrder + duaHau;
    }
	//Duyet hoa don qua dua
    for (const QuaDua& quaDua : QuaDuaList) {
        totalOrder = totalOrder + quaDua;
    }
    cout << "Tong gia tri don hang: " << totalOrder.getThanhtien() << endl;
	return 0;
}
