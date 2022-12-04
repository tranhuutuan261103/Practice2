#ifndef CircularLinkedList_h
#define CircularLinkedList_h

using namespace std;

template<class T>
class Node{
    T data;
    Node *next;
public:
    Node(T data,Node *next):data(data),next(next){};
    T getNode() const
    {
        return data;
    };
    Node* getNext() const
    {
        return next;
    }
    void setNode(const T &data)
    {
        this->data=data;
    }
    template <class U>
    friend class CircularLinkedList;
};

template<class T>
class CircularLinkedList{
    Node<T> *head;
public:
    CircularLinkedList(){this->head=NULL;};
    ~CircularLinkedList(){this->head=NULL;};
    Node<T>* getHead() const
    {
        return this->head;
    };
    T &operator[](int i) const;
    int getLength() const;
    CircularLinkedList operator=(const CircularLinkedList<T> &p);
    CircularLinkedList InsertFirst(const T &a);
    CircularLinkedList InsertMid(const T &a,int k);
    CircularLinkedList InsertLast(const T &a);
    CircularLinkedList EditInfor(int i);
    CircularLinkedList DeleteFirst();
    CircularLinkedList DeleteMid(int k);
    CircularLinkedList DeleteLast();
    void printfList() const;
    void QuickSort(bool CompFunc(string a,string b));
    int InterpolationSearch(string maCT);
    int StringToNumber(string a);
};

template <class T>
T &CircularLinkedList<T>::operator[](int i) const
{
    Node<T> *p=this->head;
    while(i--)
    {
        p=p->next;
    }
    return p->data;
}

template <class T>
int CircularLinkedList<T>::getLength() const
{
    Node<T> * current = this->head;
    int i = 1;
    if (this->head == NULL) {
        return 0;
    } else {
        current = current -> next;
        while (current != this->head) {
            i++;
            current = current -> next;
        }
    }
    return i;
}

template <class T>
CircularLinkedList<T> CircularLinkedList<T>::operator=(const CircularLinkedList<T> &p)
{
    this->head=p.getHead();
    return *this;
}

template<class T>
CircularLinkedList<T> CircularLinkedList<T>::InsertMid(const T &a,int location)
{
    int len = this->getLength(), i;
    if (location < 1 || location > len + 1) {
        printf("\nInvalid location to enter data\n");
    } else {
        if (this->head == NULL) return this->InsertFirst(a);
        Node<T> *temp=new Node<T>(a,NULL), * current = this->head;
        for (i = 1; i != location; i++) current = current -> next;
        temp -> next = current -> next;
        current -> next = temp;
        if (location == len + 1) this->head = temp;
    }
    return *this;
}

template<class T>
CircularLinkedList<T> CircularLinkedList<T>::InsertFirst(const T &a)
{
	Node<T> *temp=new Node<T>(a,NULL);
	Node<T> *p=this->head;
    if (this->head == NULL) {
        this->head = temp;
        temp -> next = temp;
    } else {
        temp -> next = p ;
        while (p->next!=this->head)
            p=p->next;
        p->next=temp;
    }
    this->head=temp;
    return *this;
}

template<class T>
CircularLinkedList<T> CircularLinkedList<T>::InsertLast(const T &a)
{
    this->InsertFirst(a);
    this->head=this->head->next;
	return *this;
}

template <class T>
CircularLinkedList<T> CircularLinkedList<T>::EditInfor(int pos)
{
    int n=this->getLength();
    if (pos<0 || pos>=n)
    {
        cout << "\nInvalid location to enter data\n";
        return *this;
    }
    T temp;
    cin >>temp;
    this->operator[](pos)=temp;
    return *this;
}

template <class T>
CircularLinkedList<T> CircularLinkedList<T>::DeleteFirst()
{
    if (this->head==NULL)
    {
        cout << "\nInvalid location to enter data\n";
        return *this;
    }
    if(this->head->next == this->head){
        this->head = NULL;
        return *this;
    }
    Node<T> *p=this->head;
    while (p->next!=this->head)
        p=p->next;
    p->next=this->head->next;
    this->head = this->head->next;
    return *this;
}

template <class T>
CircularLinkedList<T> CircularLinkedList<T>::DeleteLast()
{
    if (this->head==NULL)
    {
        cout << "\nInvalid location to enter data\n";
        return *this;
    }
    if(this->head->next == this->head){
        this->head = NULL;
        return *this;
    }
    Node<T> *before = NULL, *after = this->head;
    while (after->next != this->head)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
    {
        this->head = NULL;
    }
    else
    {
        before->next = this->head;
    }
    return *this;
}

template <class T>
CircularLinkedList<T> CircularLinkedList<T>::DeleteMid(int pos)
{
    int n = this->getLength();
    if (pos <= 0 || pos > n)
    {
        printf("\nInvalid location to enter data\n");
        return *this;
    }
    Node<T> *before = NULL, *after = this->head;
    for (int i = 1; i < pos; i++)
    {
        before = after;
        after = after->next;
    }
    if (before == NULL)
    {
        this->DeleteFirst();
    }
    else
    {
        before->next = after->next;
    }
    return *this;
}

template <class T>
void CircularLinkedList<T>::printfList() const
{
    Node<T> * p = this->head;
    T node_cur;
    node_cur.printfIntro();
    if (this->head != NULL) {
        do {
            node_cur=p->data;
            node_cur.printfNode();
            p = p -> next;
        } while (p != this->head);
    }
}

template <class T>
void tQuickSort(CircularLinkedList<T> &a,int left,int right,bool CompFunc(string a,string b))
{
    if(left >=right) return;
    if (left + 1 == right && CompFunc(a[left].getMaCT(), a[right].getMaCT()))
    {
        T temp=a[left];
        a[left]=a[right];
        a[right]=temp;
    }
    else
    {
        string chot = a[right].getMaCT();
        int L = left - 1;
        for (int j = left; j < right; j++)
            if (CompFunc(chot, a[j].getMaCT()))
            {
                L++;
                T temp=a[L];
                a[L]=a[j];
                a[j]=temp;
            }
        T temp=a[L+1];
        a[L+1]=a[right];
        a[right]=temp;
        tQuickSort(a, left, L, CompFunc);
        tQuickSort(a, L + 2, right, CompFunc);
    }
}

template <class T>
void CircularLinkedList<T>::QuickSort(bool CompFunc(string a,string b))
{
    int n=this->getLength();
    tQuickSort(*this,0,n-1,CompFunc);
}

template <class T>
int CircularLinkedList<T>::StringToNumber(string a)
{
    int sum=0;
    int t=a.size();
    for (int i=0;i<t;i++)
        sum=sum*10+(a[i]-'0');
    return sum;
}

template <class T>
int CircularLinkedList<T>::InterpolationSearch(string maCT)
{
    int n=this->getLength();
    if(n==0) return -1;
    int x=this->StringToNumber(maCT);
    int l=0,r=n-1;
    while (l<r && this->operator[](l).getMaCT() != this->operator[](r).getMaCT())
    {
        int a=x-this->StringToNumber(this->operator[](l).getMaCT());
        int b=this->StringToNumber(this->operator[](r).getMaCT()) - this->StringToNumber(this->operator[](l).getMaCT());
        int mid = l + (r-l)*a/b;
        int val_mid=this->StringToNumber(this->operator[](mid).getMaCT());
        if(val_mid < x)
            l=mid+1;
        else if (val_mid > x)
            r=mid-1;
        else return mid;
    }
    if (this->operator[](l).getMaCT()==maCT)
        return l;
    return -1;
}

#endif // CircularLinkedList_h
