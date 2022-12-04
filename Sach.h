#ifndef Sach_h
#define Sach_h
#include <bits/stdc++.h>
#include "CTKH.h"

using namespace std;

class Sach:public CTKH{
	private:
		string LoaiSach;
	public:
	    Sach(){};
	    Sach(string MaCT,int NXB,bool KhuVuc,string LoaiSach):CTKH(MaCT,NXB,KhuVuc),LoaiSach(LoaiSach){};
	    Sach(const Sach &B);
	    ~Sach(){};
		Sach operator=(const Sach &x);
		bool checkMaCT(string maCT) const;
		friend istream &operator>>(istream &in,Sach &S);
		void printfIntro() const;
		void printfNode() const;
};

#endif
