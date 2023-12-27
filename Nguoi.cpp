#include <bits/stdc++.h>
using namespace std;

//Tao class Nguoi 
class Nguoi {
protected:
    string HoTen;
    int NamSinh;

public:
    Nguoi(string, int);
    void setHoTen(string);
    void setNamSinh(int);
    string getHoTen();
    int getNamSinh();
    void inNguoi();
};

//Ham khoi tao voi 2 tham so HoTen va NamSinh
Nguoi::Nguoi(string ht, int ns) : HoTen(ht), NamSinh(ns) {}
//Set hoten
void Nguoi::setHoTen(string ten) {
    HoTen = ten;
}
//Set namsinh
void Nguoi::setNamSinh(int nam) {
    NamSinh = nam;
}
//Lay HoTen
string Nguoi::getHoTen() {
    return HoTen;
}
//Lay NamSinh
int Nguoi::getNamSinh() {
    return NamSinh;
}
//In thong tin Nguoi
void Nguoi::inNguoi() {
    cout << setw(40) << left << HoTen << setw(40) << left << NamSinh << endl;
}
//Tao class SinhVien
class SinhVien : public Nguoi {
private:
    string MSV;

public:
    SinhVien(Nguoi);
    void inSV();
    void setMSV(string);
    string getMSV();
    string getHoTenSv();
};
//Khoi tao SinhVien
SinhVien::SinhVien(Nguoi a) : Nguoi(a.getHoTen(), a.getNamSinh()) {}
//Set MSV
void SinhVien::setMSV(string msv) {
    MSV = msv;
}
//In thong tin sinh vien
void SinhVien::inSV() {
    cout << setw(40) << left << MSV << setw(40) << left << HoTen << setw(40) << left << NamSinh << endl;
}
//Lay MSV
string SinhVien::getMSV(){
	return MSV;
}
//Lay HoTen sinh vien
string SinhVien::getHoTenSv(){
	return HoTen;
}
//Cac Ham in bang
static void InBangNguoi() {
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(65) << right << "DANH SACH NGUOI" << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(40) << left << "HO TEN" << setw(40) << left << "NAM SINH";
    cout << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
}

static void InBangSV() {
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(65) << right << "DANH SACH SINH VIEN" << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
    cout << setw(40) << left << "MSV" << setw(40) << left << "HO TEN" << setw(40) << left << "NAM SINH";
    cout << endl;
    cout << setfill('-');
    cout << setw(120) << '-' << endl;
    cout << setfill(' ');
}
//Ham so sanh MSV
bool SapXepMSV(SinhVien a, SinhVien b){
	return a.getMSV() < b.getMSV();
}
//Ham so sanh HoTen Sinh vien
bool SapXepHoTen(SinhVien a, SinhVien b){
	return a.getHoTenSv() < b.getHoTenSv();
}

int main() {
    int slNguoi;
    cout << "Nhap so luong nguoi: "; cin >> slNguoi;
    cin.ignore();
    vector<Nguoi> DSN;
    vector<SinhVien> DSSV;
    for (int i = 0; i < slNguoi; i++) {
        string ht;
        int ns,type;
        cout << "\nNhap thong tin cho nguoi thu " << i + 1 << ": \n";
        cout << "Ho ten: ", getline(cin, ht);
        cout << "Nam sinh: ", cin >> ns, cin.ignore();
        Nguoi a(ht, ns);
        DSN.push_back(a);
        cout<<"Nhap '1' neu la sinh vien: ", cin>>type;
        cin.ignore();
        if(type==1){
        	SinhVien b(a);
        	string msv;
        	cout<<"Nhap ma sinh vien: ";
        	getline(cin, msv);
        	b.setMSV(msv);
        	DSSV.push_back(b);
		}
    }
    system("cls");
	//In danh sach Nguoi
    if (!DSN.empty()) {
        InBangNguoi();
        for (auto &nguoi : DSN) {
            nguoi.inNguoi();
        }
        system("pause");
		system("cls");
    }
    //In danh sach sinh vien sap xep theo MSV
    if (!DSSV.empty()) {
    	cout<<"Danh sach sinh vien sap xep theo MSV\n\n";
    	sort(DSSV.begin(),DSSV.end(),SapXepMSV);
    	InBangSV();
    	for (auto &sv : DSSV){
    		sv.inSV();
		}
		system("pause");
		system("cls");
	}
	//In danh sach sinh vien sap xep theo HoTen
	if (!DSSV.empty()) {
		cout<<"Danh sach sinh vien sap xep theo ho ten\n\n";
    	sort(DSSV.begin(),DSSV.end(),SapXepHoTen);
    	InBangSV();
    	for (auto &sv : DSSV){
    		sv.inSV();
		}
	}
    return 0;
}

