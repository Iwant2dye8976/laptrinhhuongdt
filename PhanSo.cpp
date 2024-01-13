#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(abs(b)==0) return a;
	return gcd(abs(b),abs(a%b));
}

int lcm(int a, int b){
	return a*b/gcd(a,b);
}

class Ps{
	private:
		int tu, mau;
	public:
		Ps(int tu, int mau);
		friend ostream& operator << (ostream&, Ps);
		friend istream& operator >> (istream&, Ps&);
		friend Ps operator + (Ps,Ps); 
		void rutgon();
};

Ps::Ps(int tu, int mau){
	this->tu=tu;
	this->mau=mau;
}

ostream& operator << (ostream& out, Ps a){
	out<<a.tu<<"/"<<a.mau<<endl;
	return out;
}

istream& operator >> (istream& in, Ps &a){
	in>>a.tu>>a.mau;
	return in;
}

Ps operator + (Ps a, Ps b){
	Ps tong(1,1);
	int mc = lcm(a.mau,b.mau);
	tong.tu = mc/a.mau*a.tu + mc/b.mau*b.tu;
	tong.mau = mc;
	int  m = gcd(tong.tu,tong.mau);
	tong.tu/=m;
	tong.mau/=m;
	return tong;
}

void Ps::rutgon(){
	int m = gcd(this->tu,this->mau);
	if(this->mau<0){
		this->tu/=-m;
		this->mau/=-m;
	}
	this->tu/=m;
	this->mau/=m;
}

int main(){
	Ps p(1,1),q(1,1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}




