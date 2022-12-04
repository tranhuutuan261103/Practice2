#include <bits/stdc++.h>
#include "Sach.h"

using namespace std;

bool Sach::checkMaCT(string maCT) const
{
	if(maCT.size()!=5)
	return false;
	for (int i=0;i<5;i++)
	{
		if(!(maCT[i]>='0' && maCT[i]<='9') ) return false;
	}
	return true;
}

Sach::Sach(const Sach &x)
{
    this->setMaCT(x.getMaCT());
    this->setNXB(x.getNXB());
    this->setKhuVuc(x.getKhuVuc());
    this->LoaiSach=x.LoaiSach;
}

Sach Sach::operator=(const Sach &x)
{
	if (this != &x)
	{
	    this->setMaCT(x.getMaCT());
	    this->setNXB(x.getNXB());
	    this->setKhuVuc(x.getKhuVuc());
	    this->LoaiSach=x.LoaiSach;
	}
	return *this;
}

istream &operator>>(istream &in,Sach &S)
{
    string maCT;
    int nxb;
    int choose;
    bool khuvuc;
    cout << "Nhap ma cong trinh(ma gom 5 so):" << endl;
	do {
        cout << "->Ma cong trinh:";
        getline(in,maCT);
        cout << maCT;
	} while (!S.checkMaCT(maCT));
    S.setMaCT(maCT);
    cout << "Nhap nam xuat ban(>1900):" << endl;
	do {
	    cout << "->Nam xuat ban:";
		in >> nxb;
	} while (nxb<1900);
	S.setNXB(nxb);
    cout << "Khu vuc xuat ban (1.Quoc te/0.Trong nuoc):" ;
	in >> choose;
	if (choose==1) khuvuc=true;
	else khuvuc=false;
	S.setKhuVuc(khuvuc);
	cout << "Nhap loai sach:";
	cin.ignore();
	getline(in,S.LoaiSach);
    return in;
}

void Sach::printfIntro() const
{
    cout << left << setw(10) << "Ma CT" ;
    cout << left << setw(10) << "Nam XB" ;
    cout << left << setw(15) << "Khu vuc";
    cout << left << setw(10) << "Loai sach" << endl;
}
void Sach::printfNode() const
{
    cout << left << setw(10) << this->getMaCT();
    cout << left << setw(10) << this->getNXB();
    if (this->getKhuVuc()==true) cout << left << setw(15) << "Quoc te";
    else cout << left << setw(15) << "Trong nuoc";
    cout << left << setw(10) << this->LoaiSach << endl;
}

