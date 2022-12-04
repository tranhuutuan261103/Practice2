#include <bits/stdc++.h>
#include "CircularLinkedList.h"
#include "CTKH.h"
#include "Sach.h"
#include "ListCTKH.h"

using namespace std;

bool Accending(string a,string b);
bool Decending(string a,string b);

int main()
{
    CircularLinkedList<BaiBao> B;
    BaiBao b1("10001",2003,false,"Cac giai phap nen du lieu",2);
    BaiBao b2("10002",2004,false,"Cong nghe so",2);
    BaiBao b3("10003",2003,true,"Co so ha tang",4);
    BaiBao b4("10004",2004,false,"Duong sat Viet Nam",2);
    B.InsertFirst(b1);
    B.InsertFirst(b2);
    B.InsertLast(b3);
    B.InsertFirst(b4);
    CircularLinkedList<Sach> S;
    Sach s1("10005",2021,true,"Sach tham khao Toan");
    Sach s2("10006",2021,false,"Sach tham khao Ly");
    Sach s3("10007",2020,false,"Sach chuyen khao Ly");
    Sach s4("10008",2019,false,"Sach chuyen khao Toan");
    S.InsertFirst(s1);
    S.InsertFirst(s2);
    S.InsertLast(s3);
    S.InsertFirst(s4);
    ListCTKH L("Tran Huu Tuan",B,S);
	int choose;
	do {
        string maCT;
        int c;
        system("cls");
		cout << "1.Hien thi danh sach cac doi tuong" << endl;
		cout << "2.Them doi tuong" << endl;
		cout << "3.Cap nhat thong tin doi tuong" << endl;
		cout << "4.Xoa doi tuong" << endl;
		cout << "5.Tim kiem doi tuong" << endl;
		cout << "6.Sap xep doi tuong" << endl;
		cout << "0.Ket thuc chuong trinh" << endl;
		cout << "Nhap lua chon:";
		cin >> choose;
		switch(choose)
		{
			case 0:
				break;
			case 1:
				system("cls");
				L.Display();
				system("pause");
				break;
			case 2:
				do {
                    system("cls");
					cout << "1.Them vao dau" << endl;
					cout << "2.Them vao cuoi" << endl;
					cout << "3.Them vao vi tri k" << endl;
					cout << "0.Thoat" << endl;
					cout << "Nhap lua chon:";
					cin >> c;
					switch (c)
					{
						case 0:
						    system("cls");
						    break;
						case 1:
						    system("cls");
							L.InsertFirst();
							system("pause");
							break;
						case 2:
						    system("cls");
							L.InsertLast();
                            system("pause");
							break;
						case 3:
						    system("cls");
							L.InsertMid();
							system("pause");
							break;
						default:
							cout << "Vui long nhap lai!" << endl;
							break;
					}
				} while (c);
				break;
			case 3:
			    system("cls");
			    L.Display();
			    L.EditInfor();
			    system("pause");
				break;
            case 4:
				do {
                    system("cls");
					cout << "1.Xoa dau" << endl;
					cout << "2.Xoa cuoi" << endl;
					cout << "3.Xoa tai vi tri k" << endl;
					cout << "0.Thoat" << endl;
					cout << "Nhap lua chon:";
					cin >> c;
					switch (c)
					{
						case 0:
						    system("cls");
						    break;
						case 1:
						    system("cls");
							L.DeleteFirst();
							L.Display();
                            system("pause");
							break;
						case 2:
						    system("cls");
							L.DeleteLast();
							L.Display();
                            system("pause");
							break;
						case 3:
							system("cls");
							L.DeleteMid();
							L.Display();
                            system("pause");
							break;
						default:
							cout << "Vui long nhap lai!" << endl;
							break;
					}
				} while (c);
				break;
            case 5:
                system("cls");
                L.Search();
                system ("pause");
                break;
            case 6:
                do{
                system("cls");
                cout << "1.Sap xep tang dan" << endl;
                cout << "2.Sap xep giam dan" << endl;
                cout << "0.Thoat" << endl;
                cout << "Nhap lua chon:" ;
                cin >> c;
                switch (c)
                {
                    case 1:
                        system("cls");
                        L.QuickSort(Accending);
                        L.Display();
                        system("pause");
                        break;
                    case 2:
                        system("cls");
                        L.QuickSort(Decending);
                        L.Display();
                        system("pause");
                        break;
                    case 0:
                        system("cls");
                        break;
                    default:
                        cout << "Vui long nhap lai!" << endl;
                        break;
                }
		        }while(c);
                break;
			default:
				cout <<"Vui long nhap lai" << endl;
				break;
		}
	} while (choose);
    return 0;
}

bool Accending(string a,string b)
{
    return a>b;
}

bool Decending(string a,string b)
{
    return a<b;
}
