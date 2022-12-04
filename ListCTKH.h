#ifndef ListCTKH_h
#define ListCTKH_h

#include <bits/stdc++.h>
#include "Sach.h"
#include "BaiBao.h"
#include "CircularLinkedList.h"

using namespace std;

class ListCTKH{
private:
    string TenCaNhan;
    CircularLinkedList<BaiBao> B;
    CircularLinkedList<Sach> S;
    int SL;
public:
    ListCTKH(){this->SL=0;};
    ListCTKH(string TenCaNhan,CircularLinkedList<BaiBao> &B,CircularLinkedList<Sach> &S);
    ListCTKH(const ListCTKH &L);
    ~ListCTKH(){};
    ListCTKH operator=(const ListCTKH &L);
    void Display() const;
    ListCTKH InsertFirst();
    ListCTKH InsertLast();
    ListCTKH InsertMid();
    ListCTKH EditInfor();
    ListCTKH DeleteFirst();
    ListCTKH DeleteLast();
    ListCTKH DeleteMid();
    void Search();
    ListCTKH QuickSort(bool CompFunc(string a,string b));
};

#endif // ListCTKH_h
