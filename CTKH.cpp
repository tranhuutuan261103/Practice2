#include <bits/stdc++.h>
#include "CTKH.h"

using namespace std;

CTKH::CTKH(const CTKH &C)
{
    this->MaCT=C.MaCT;
    this->NXB=C.NXB;
    this->KhuVuc=C.KhuVuc;
}

void CTKH::setMaCT(string s)
{
    this->MaCT=s;
}
void CTKH::setNXB(int nxb)
{
    this->NXB=nxb;
}
void CTKH::setKhuVuc(bool khuvuc)
{
    this->KhuVuc=khuvuc;
}

CTKH CTKH::operator=(const CTKH &x)
{
	if (this != &x)
	{
	    this->MaCT=x.MaCT;
		this->NXB=x.NXB;
		this->KhuVuc=x.KhuVuc;
	}
	return *this;
}
