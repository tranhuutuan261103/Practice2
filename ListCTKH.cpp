#include <bits/stdc++.h>
#include "ListCTKH.h"

using namespace std;


ListCTKH::ListCTKH(string TenCaNhan,CircularLinkedList<BaiBao> &B,CircularLinkedList<Sach> &S)
{
    this->TenCaNhan=TenCaNhan;
    this->B=B;
    this->S=S;
    this->SL=S.getLength()+B.getLength();
}
ListCTKH::ListCTKH(const ListCTKH &L)
{
    this->TenCaNhan=L.TenCaNhan;
    this->B=L.B;
    this->S=L.S;
    this->SL=L.SL;
}

ListCTKH ListCTKH::operator=(const ListCTKH &L)
{
    if (this!=&L)
    {
        this->TenCaNhan=L.TenCaNhan;
        this->B=L.B;
        this->S=L.S;
        this->SL=L.SL;
    }
    return *this;
}


void ListCTKH::Display() const
{
    cout << "Ten ca nhan:";
    cout << this->TenCaNhan << endl;
    this->B.printfList();
    this->S.printfList();
    cout << "So cong trinh:" << this->SL << endl;
}

ListCTKH ListCTKH::InsertFirst()
{
    int choose;
    BaiBao b;
    Sach s;
    cout << "Nhap (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        cin.ignore();
        cin >> b;
        B.InsertFirst(b);
    }
    else{
        cin.ignore();
        cin >> s;
        S.InsertFirst(s);
    }
    return *this;
}
ListCTKH ListCTKH::InsertLast()
{
    int choose;
    BaiBao b;
    Sach s;
    cout << "Nhap (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        cin.ignore();
        cin >> b;
        B.InsertLast(b);
    }
    else{
        cin.ignore();
        cin >> s;
        S.InsertLast(s);
    }
    return *this;
}
ListCTKH ListCTKH::InsertMid()
{
    int choose,pos;
    BaiBao b;
    Sach s;
    cout << "Nhap (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        cin.ignore();
        cin >> b;
        cout << "Nhap vi tri can chen vao:";
        cin >> pos;
        B.InsertMid(b,pos);
    }
    else{
        cin.ignore();
        cin >> s;
        cout << "Nhap vi tri can chen vao:";
        cin >> pos;
        S.InsertMid(s,pos);
    }
    return *this;
}
////////////////////////////////
ListCTKH ListCTKH::EditInfor()
{
    int choose,pos;
    BaiBao b;
    Sach s;
    cout << "Cap nhat (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        cin.ignore();
        cin >> b;
        cout << "Nhap vi tri can cap nhat:";
        cin >> pos;
        if (pos<0 && pos>=B.getLength())
        {
            cout << "\nInvalid location to enter data\n";
            return *this;
        }
        else{
            B[pos]=b;
        }
    }
    else{
        cin.ignore();
        cin >> s;
        cout << "Nhap vi tri can cap nhat:";
        cin >> pos;
        if (pos<0 && pos>=S.getLength())
        {
            cout << "\nInvalid location to enter data\n";
            return *this;
        }
        else{
            S[pos]=s;
        }
    }
    return *this;
}

ListCTKH ListCTKH::DeleteFirst()
{
    int choose;
    cout << "Xoa (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        B.DeleteFirst();
    }
    else{
        S.DeleteFirst();
    }
    return *this;
}
ListCTKH ListCTKH::DeleteLast()
{
    int choose;
    cout << "Xoa (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        B.DeleteLast();
    }
    else{
        S.DeleteLast();
    }
    return *this;
}
ListCTKH ListCTKH::DeleteMid()
{
    int choose,k;
    cout << "Xoa (1.Bai bao/2.Sach):";
    cin >> choose;
    cout << "Nhap vi tri k can xoa:";
    if (choose==1)
    {
        cin >> k;
        B.DeleteMid(k);
    }
    else{
        cin >> k;
        S.DeleteMid(k);
    }
    return *this;
}

void ListCTKH::Search()
{
    int choose,pos;
    string maCT;
    cout << "Tim kiem (1.Bai bao/2.Sach):";
    cin >> choose;
    if (choose==1)
    {
        B.printfList();
        cout << "Nhap ma cong trinh can tim:";
        cin.ignore();
        getline(cin,maCT);
        pos=B.InterpolationSearch(maCT);
        if(pos==-1)
            cout << "Ma cong trinh khong ton tai!\n";
        else {
            BaiBao b=B[pos];
            b.printfNode();
        }
    }
    else{
        S.printfList();
        cout << "Nhap ma cong trinh can tim:";
        cin.ignore();
        getline(cin,maCT);
        pos= S.InterpolationSearch(maCT);
        if(pos==-1)
            cout << "Ma cong trinh khong ton tai!\n";
        else {
            Sach s=S[pos];
            s.printfNode();
        }
    }
}

ListCTKH ListCTKH::QuickSort(bool CompFunc(string a,string b))
{
    this->B.QuickSort(CompFunc);
    this->S.QuickSort(CompFunc);
    return *this;
}
