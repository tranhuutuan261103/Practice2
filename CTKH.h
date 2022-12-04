#ifndef CTKH_h
#define CTKH_h
#include <bits/stdc++.h>

using namespace std;

class CTKH{
	private:
		string MaCT;
		int NXB;
		bool KhuVuc;
	public:
	    CTKH(){};
	    CTKH(string MaCT,int NXB,bool KhuVuc):MaCT(MaCT),NXB(NXB),KhuVuc(KhuVuc){};
	    CTKH(const CTKH &C);
	    ~CTKH(){};
		string getMaCT() const{
			return this->MaCT;
		}
		int getNXB() const{
		    return this->NXB;
		}
		bool getKhuVuc() const{
		    return this->KhuVuc;
		}
		void setMaCT(string s);
		void setNXB(int nxb);
		void setKhuVuc(bool khuvuc);
		CTKH operator=(const CTKH &x);
};

#endif

