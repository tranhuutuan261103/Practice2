#ifndef BaiBao_h
#define BaiBao_h
#include <bits/stdc++.h>
#include "CTKH.h"

using namespace std;

class BaiBao:public CTKH{
private:
    string TenCT;
    int SoTacGia;
public:
    BaiBao(){};
    BaiBao(string MaCT,int NXB,bool KhuVuc,string TenCT,int SoTacGia):CTKH(MaCT,NXB,KhuVuc),TenCT(TenCT),SoTacGia(SoTacGia){};
    BaiBao(const BaiBao &B);
    ~BaiBao(){};
    bool checkMaCT(string maCT) const;
    BaiBao operator=(const BaiBao &x);
    friend istream &operator>>(istream &in,BaiBao &B);
    void printfIntro() const;
    void printfNode() const;
};

#endif


