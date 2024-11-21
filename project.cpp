#include<iostream>
using namespace std;

/////////////////////////////////////////
//code of singly linear
/////////////////////////////////////////

template <class T>
struct nodeSL
{
    T data;
    struct nodeSL *next;
};

template <class T>
class SinglyLL
{
    private:
        struct nodeSL<T> * First;
        int iCount;

    public:
        SinglyLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
SinglyLL<T>::SinglyLL()
{
    cout<<"Inside Constructor\n";
    First = NULL;
    iCount = 0;    
}

template <class T>
void SinglyLL<T>::Display()
{
    struct nodeSL<T> * temp = First;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template <class T>
void SinglyLL<T>::InsertFirst(T No)
{
    struct nodeSL<T> * newn = NULL;

    newn = new nodeSL<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertLast(T No)
{
    struct nodeSL<T> * newn = NULL;
    struct nodeSL<T> * temp = First;

    newn = new nodeSL<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    iCount++;
}

template <class T>
void SinglyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeSL<T> * newn = NULL;
    int i = 0;
    struct nodeSL<T> * temp = NULL;

    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;

        newn = new nodeSL<T>;
        newn->data = No;
        newn->next = NULL;

        for(i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }   
}

template <class T>
void SinglyLL<T>::DeleteFirst()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"Linked list empty nodeSL can't be deleted"<<endl;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete temp;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteLast()
{
    struct nodeSL<T> * temp = First;

    if(First == NULL)
    {
        cout<<"Linked list empty nodeSL can't be deleted"<<endl;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeSL<T> * temp1;
    int i = 0;
    struct nodeSL<T> * temp2;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }

        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;

        iCount--;
    }   
}

/////////////////////////////////////////
//code of singly circular
////////////////////////////////////////

template <class T>
struct nodeCL
{
    T data;
    struct nodeCL *next;
};

template <class T>
class CircularLL
{
    private:
        struct nodeCL<T> * First;
        struct nodeCL<T> * Last;
        int iCount;

    public:
        CircularLL();

        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No,int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
CircularLL<T>::CircularLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
void CircularLL<T>::Display()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"CLL is empty\n";
        return;      
    }
    cout<<"<->";
    do
    {
        cout<<"| "<<First->data<<" |<->";
        First = First->next;
    } while (First != Last->next);
     cout<<"\n";
}

template <class T>
int CircularLL<T>::Count()
{
    return iCount;
}

template <class T>
void CircularLL<T>::InsertFirst(T No)
{
    struct nodeCL<T> * newn = NULL;

    newn = new nodeCL<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;       
    }
    else
    {
        newn->next = First;
        First = newn;       
    }
    Last->next = First;
    iCount++;
}

template <class T>
void CircularLL<T>::InsertLast(T No)
{
    struct nodeCL<T> * newn = NULL;

    newn = new nodeCL<T>;
    newn->data = No;
    newn->next = NULL;

    if(First == NULL && Last == NULL)
    {
        First = newn;
        Last = newn;       
    }
    else
    {
        Last->next = newn;
        Last = newn;       
    }
    Last->next = First;
    iCount++;
}

template <class T>
void CircularLL<T>::InsertAtPos(T No,int iPos)
{
    struct nodeCL<T> * temp = NULL;
    struct nodeCL<T> * newn = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;
        newn = new nodeCL<T>;
        newn->data = No;
        newn->next = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void CircularLL<T>::DeleteFirst()
{
    if(First == NULL && Last == NULL)
    {
        cout<<"Empty Cll element  can't be deleted\n";       
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete Last->next;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void CircularLL<T>::DeleteLast()
{
    struct nodeCL<T> * temp = NULL;

    if(First == NULL && Last == NULL)
    {
        cout<<"Empty Cll element  can't be deleted\n";       
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        temp = First;
        while(temp->next != Last)
        {
            temp = temp->next;
        }
        delete temp->next;
        Last = temp;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void CircularLL<T>::DeleteAtPos(int iPos)
{
    struct nodeCL<T> * temp1 = NULL;
    struct nodeCL<T> * temp2 = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp1 = First;

        for(int i = 1; i < iPos-1; i++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp2->next;
        free(temp2);
        iCount--;
    }
}

/////////////////////////////////////////
//code of doubly linear list
/////////////////////////////////////////

template <class T>
struct nodeDL
{
    T data;
    struct nodeDL *next;
    struct nodeDL *prev;
};

template <class T> 
class DoublyLL
{
    private:
        struct nodeDL<T> * First;
        int iCount;

    public:
        DoublyLL();
        
        void Display();
        int Count();

        void InsertFirst(T No);
        void InsertLast(T No);
        void InsertAtPos(T No, int iPos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int iPos);
};

template <class T>
DoublyLL<T>::DoublyLL()
{
    First = NULL;
    iCount = 0;
}

template <class T>       
void DoublyLL<T>::Display()
{
    struct nodeDL<T> * temp = First;
    if(First == NULL)
    {
        printf("DoublyLL is empty\n");
        return;
    }
    printf("NULL<=>");
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |<=>";
        temp = temp->next;
    }
    cout<<"NULL\n";
}

template <class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyLL<T>::InsertFirst(T No)
{
    struct nodeDL<T> * newn = NULL;

    newn = new nodeDL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
        First->next->prev = newn;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertLast(T No)
{
    struct nodeDL<T> * newn = NULL;
    struct nodeDL<T> * temp = NULL;

    newn = new nodeDL<T>;
    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

template <class T>
void DoublyLL<T>::InsertAtPos(T No, int iPos)
{
    struct nodeDL<T> * temp = NULL;
    struct nodeDL<T> * newn = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        temp = First;
        newn = new nodeDL<T>;
        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        newn->prev = temp;
        temp->next = newn;
        iCount++;
    }
}

template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if(First == NULL)
    {
        cout<<"Empty DoublyLL element can't be deleted\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteLast()
{
    struct nodeDL<T> * temp = NULL;

    if(First == NULL)
    {
        cout<<"Empty DoublyLL element can't be deleted\n";
        return;
    }
    else if(First->next == NULL)
    {
        delete First;
        First = NULL;
    }
    else
    {
        temp = First;
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDL<T> * temp = NULL;

    if(iPos < 1 || iPos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount+1)
    {
        DeleteLast();
    }
    else
    {
        temp = First;

        for(int i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}


/////////////////////////////////////////
//code of doubly circular linked list
////////////////////////////////////////

template <class T>
struct nodeDC
{
    T data;
    struct nodeDC *next;
    struct nodeDC *prev;    
};

template <class T>
class DoublyCLL
{
    private:
    struct nodeDC<T> * First;
    struct nodeDC<T> * Last;
    int iCount;

    public:
    DoublyCLL();

    void Display();
    int Count();

    void InsertFirst(T No);
    void InsertLast(T No);
    void InsertAtPos(T No,int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);

};

template <class T>
DoublyCLL<T>::DoublyCLL()
{
    First = NULL;
    Last = NULL;
    iCount = 0;
}

template <class T>
int DoublyCLL<T>::Count()
{
    return iCount;
}

template <class T>
void DoublyCLL<T>::Display()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Linked list empty\n";
        return;
    }

    cout<<"<=>";
    do
    {
        cout<<"| "<<First->data<<" |<=>";
        First = First->next;

    } while (First != Last->next);

    cout<<"\n";   
}

template <class T>
void DoublyCLL<T>::InsertFirst(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->next = First;
        First->prev = newn;
        First = newn;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertLast(T No)
{
    struct nodeDC<T> * newn = NULL;

    newn = new nodeDC<T>;

    newn->data = No;
    newn->next = NULL;
    newn->prev = NULL;

    if((First == NULL) && (Last == NULL))
    {
        First = newn;
        Last = newn;
    }
    else
    {
        newn->prev = Last;
        Last->next = newn;
        Last = newn;
    }
    Last->next = First;
    First->prev = Last;
    iCount++;
}

template <class T>
void DoublyCLL<T>::InsertAtPos(T No,int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalid Positions\n";
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(No);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(No);
    }
    else
    {
        struct nodeDC<T> * newn = NULL;
        struct nodeDC<T> * temp = First;
        int i = 0;

        newn = new nodeDC<T>;

        newn->data = No;
        newn->next = NULL;
        newn->prev = NULL;

        for( i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }        
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;               
        iCount++;
    }
}

template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Empty DCLL\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        First = First->next;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if((First == NULL) && (Last == NULL))
    {
        cout<<"Empty DCLL\n";
        return;
    }
    else if(First == Last)
    {
        delete First;
        First = NULL;
        Last = NULL;
    }
    else
    {
        Last = Last->prev;
        delete First->prev;
        First->prev = Last;
        Last->next = First;
    }
    iCount--;
}

template <class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{
    struct nodeDC<T> * temp = First;
    int i = 0;

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid Positions\n";
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        for( i = 1; i < iPos-1; i++)
        {
            temp = temp->next;
        }        
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        iCount--;
    }
}

/////////////////////////////////////////
//code of queue
////////////////////////////////////////

template<class T>
struct nodeQ
{
    T data;
    struct nodeQ *next;
};

template<class T>
class Queue
{
    private:
        struct nodeQ<T> * First;
        int iCount;

    public:
        Queue();

        void Display();
        int Count();

        void enqueue(T No);
       
        char dequeue();

};

template<class T>
Queue<T>::Queue()
{
    First = NULL;
    iCount = 0;    
}

template<class T>
void Queue<T>::Display()
{
    struct nodeQ<T> *  temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<"\t";
        temp = temp->next;
    }
    cout<<"\n";
}

template<class T>
int Queue<T>::Count()
{
    return iCount;
}

template<class T>
void Queue<T>::enqueue(T No)
{
    struct nodeQ<T> *  newn = NULL;

    newn = new nodeQ<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template<class T>
char Queue<T>::dequeue()
{
    struct nodeQ<T> *  temp = First;
    char value = '\0';

    if(First == NULL)
    {
        cout<<"Linked list empty node can't be deleted"<<endl;
    }
    else if(First->next == NULL)
    {
        value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
    return value;
}

/////////////////////////////////////////////////
//CODE OF STACK
////////////////////////////////////////////////

template <class T>
struct nodeS
{
    T data;
    struct nodeS *next;
};

template <class T>
class Stack
{
    private:
        struct nodeS<T> * First;
        int iCount;

    public:
        Stack();

        void Display();
        int Count();

        void push(T No);
       
        int pop();

};

template <class T>
Stack<T>::Stack()
{
    First = NULL;
    iCount = 0;    
}

template <class T>
void Stack<T>::Display()
{
    struct nodeS<T> * temp = First;
    while(temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
    }
}

template <class T>
int Stack<T>::Count()
{
    return iCount;
}

template <class T>
void Stack<T>::push(T No)
{
    struct nodeS<T> * newn = NULL;

    newn = new nodeS<T>;

    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    }
    else
    {
        newn->next = First;
        First = newn;
    }
    iCount++;
}

template <class T>
int Stack<T>::pop()
{
    struct nodeS<T> * temp = First;
    int value = 0;

    if(First == NULL)
    {
        cout<<"Linked list empty node can't be deleted"<<endl;
    }
    else if(First->next == NULL)
    {
        value = First->data;
        delete First;
        First = NULL;
    }
    else
    {
        First = First->next;
        value = temp->data;
        delete temp;
    }
    iCount--;
    return value;
}

int main()
{
    //LL OF INTEGER
    cout<<"\n-----------Linked list of integer-----------\n";
    SinglyLL<int> *iobj = new SinglyLL<int>();
    int iRet = 0;

    iobj->InsertFirst(51);
    iobj->InsertFirst(21);
    iobj->InsertFirst(11);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    iobj->InsertLast(101);
    iobj->InsertLast(111);
    iobj->InsertLast(121);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;    

    iobj->InsertAtPos(105,5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    iobj->DeleteAtPos(5);

    iobj->Display();
    iRet = iobj->Count();
    cout<<"Number of elements are : "<<iRet<<endl;

    //LL OF CHARACTER
    cout<<"\n-----------Linked list of character-----------\n";
    SinglyLL<char> *csobj = new SinglyLL<char>();
    int cRet = 0;

    csobj->InsertFirst('C');
    csobj->InsertFirst('B');
    csobj->InsertFirst('A');

    csobj->Display();
    cRet = csobj->Count();
    cout<<"Number of elements are : "<<cRet<<endl;

    csobj->InsertLast('D');
    csobj->InsertLast('E');
    csobj->InsertLast('F');

    csobj->Display();
    cRet = csobj->Count();
    cout<<"Number of elements are : "<<cRet<<endl;    

    csobj->InsertAtPos('G',5);

    csobj->Display();
    cRet = csobj->Count();
    cout<<"Number of elements are : "<<cRet<<endl;

    csobj->DeleteAtPos(5);

    csobj->Display();
    cRet = csobj->Count();
    cout<<"Number of elements are : "<<cRet<<endl;

    //LL OF FLOAT
    cout<<"\n-----------Linked list of float-----------\n";
    SinglyLL<float> *fobj = new SinglyLL<float>();
    int fRet = 0;

    fobj->InsertFirst(51.90f);
    fobj->InsertFirst(21.89f);
    fobj->InsertFirst(11.88f);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elements are : "<<fRet<<endl;

    fobj->InsertLast(101.89f);
    fobj->InsertLast(111.45f);
    fobj->InsertLast(121.77f);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elements are : "<<fRet<<endl;    

    fobj->InsertAtPos(105.90f,5);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elements are : "<<fRet<<endl;

    fobj->DeleteAtPos(5);

    fobj->Display();
    fRet = fobj->Count();
    cout<<"Number of elements are : "<<fRet<<endl;

    //LL OF DOUBLE
    cout<<"\n-----------Linked list of double-----------\n";
    SinglyLL<double> *deobj = new SinglyLL<double>();
    int dRet = 0;

    deobj->InsertFirst(51.9089);
    deobj->InsertFirst(21.8989);
    deobj->InsertFirst(11.8889);

    deobj->Display();
    dRet = deobj->Count();
    cout<<"Number of elements are : "<<dRet<<endl;

    deobj->InsertLast(101.8989);
    deobj->InsertLast(111.4598);
    deobj->InsertLast(121.7798);

    deobj->Display();
    dRet = deobj->Count();
    cout<<"Number of elements are : "<<dRet<<endl;    

    deobj->InsertAtPos(105.9098,5);

    deobj->Display();
    dRet = deobj->Count();
    cout<<"Number of elements are : "<<dRet<<endl;

    deobj->DeleteAtPos(5);

    deobj->Display();
    dRet = deobj->Count();
    cout<<"Number of elements are : "<<dRet<<endl;

    //SINGLY CIRCULAR INT TYPE
    cout<<"\n-----------Circular Linked list of integer-----------\n";
    CircularLL<int> *cobj = new CircularLL<int>();

    cobj->InsertFirst(51);
    cobj->InsertFirst(21);
    cobj->InsertFirst(11);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    cobj->InsertLast(101);
    cobj->InsertLast(111);
    cobj->InsertLast(121);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    cobj->DeleteFirst();
    cobj->Display();
    iRet = cobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    cobj->DeleteLast();
    cobj->Display();
    iRet = cobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    cobj->InsertAtPos(55,3);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    cobj->DeleteAtPos(3);
    cobj->Display();
    iRet = cobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    //Singly CIRCULAR LINKED LIST FLOAT
    cout<<"\n-----------Circular Linked list of float-----------\n";
    CircularLL<float> *fcobj = new CircularLL<float>();

    fcobj->InsertFirst(51.12f);
    fcobj->InsertFirst(21.98f);
    fcobj->InsertFirst(11.98f);
    fcobj->Display();
    iRet = fcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fcobj->InsertLast(101.98f);
    fcobj->InsertLast(111.98f);
    fcobj->InsertLast(121.98f);
    fcobj->Display();
    iRet = fcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fcobj->DeleteFirst();
    fcobj->Display();
    iRet = fcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fcobj->DeleteLast();
    fcobj->Display();
    iRet = fcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fcobj->InsertAtPos(55.98f,3);
    fcobj->Display();
    iRet = fcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fcobj->DeleteAtPos(3);
    fcobj->Display();
    iRet = fcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    //Singly CIRCULAR LINKED LIST char
    cout<<"\n-----------Circular Linked list of character-----------\n";
    CircularLL<char> *ccobj = new CircularLL<char>();

    ccobj->InsertFirst('C');
    ccobj->InsertFirst('B');
    ccobj->InsertFirst('A');
    ccobj->Display();
    iRet = ccobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    ccobj->InsertLast('D');
    ccobj->InsertLast('E');
    ccobj->InsertLast('F');
    ccobj->Display();
    iRet = ccobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    ccobj->DeleteFirst();
    ccobj->Display();
    iRet = ccobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    ccobj->DeleteLast();
    ccobj->Display();
    iRet = ccobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    ccobj->InsertAtPos('G',3);
    ccobj->Display();
    iRet = ccobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    ccobj->DeleteAtPos(3);
    ccobj->Display();
    iRet = ccobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    //Singly CIRCULAR LINKED LIST double
    cout<<"\n-----------Circular Linked list of double-----------\n";
    CircularLL<double> *dcobj = new CircularLL<double>();

    dcobj->InsertFirst(51.2048);
    dcobj->InsertFirst(21.2048);
    dcobj->InsertFirst(11.2048);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    dcobj->InsertLast(101.2048);
    dcobj->InsertLast(111.2048);
    dcobj->InsertLast(121.2048);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    dcobj->DeleteFirst();
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    dcobj->DeleteLast();
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    dcobj->InsertAtPos(55.2048,3);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    dcobj->DeleteAtPos(3);
    dcobj->Display();
    iRet = dcobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    //DOUBLY LINEAR LIST INT TYPE
    cout<<"\n-----------Doubly Linked list of integer-----------\n";
    DoublyLL<int> *dobj = new DoublyLL<int>();

    dobj->InsertFirst(51);
    dobj->InsertFirst(21);
    dobj->InsertFirst(11);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Count of elements is : "<<iRet<<"\n";

    dobj->InsertLast(101);
    dobj->InsertLast(111);
    dobj->InsertLast(121);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Count of elements is : "<<iRet<<"\n";

    dobj->DeleteFirst();
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Count of elements is : "<<iRet<<"\n";

    dobj->DeleteLast();
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Count of elements is : "<<iRet<<"\n";

    dobj->InsertAtPos(55,3);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Count of elements is : "<<iRet<<"\n";

    dobj->DeleteAtPos(3);
    dobj->Display();
    iRet = dobj->Count();
    cout<<"Count of elements is : "<<iRet<<"\n";


    //DOUBLY CIRCULAR LL OF INTEGER
    cout<<"\n-----------Doubly Circular Linked list of integer-----------\n";
    DoublyCLL<int> *idobj = new DoublyCLL<int>();

    idobj->Display();
    
    idobj->InsertFirst(51);
    idobj->InsertFirst(21);
    idobj->InsertFirst(11);

    idobj->InsertLast(101);
    idobj->InsertLast(111);
    idobj->InsertLast(121);

    idobj->Display();
    iRet = idobj->Count();
    cout<<"The no-> of elements : "<<iRet<<endl;

    idobj->DeleteFirst();
    idobj->DeleteLast();

    idobj->Display();
    iRet = idobj->Count();
    cout<<"The no-> of elements : "<<iRet<<endl;

    idobj->InsertAtPos(55,3);
    idobj->Display();
    iRet = idobj->Count();
    cout<<"The no-> of elements : "<<iRet<<endl;

    idobj->DeleteAtPos(3);
    idobj->Display();
    iRet = idobj->Count();
    cout<<"The no-> of elements : "<<iRet<<endl;

   //DOUBLY LL OF CHARACTER
   cout<<"\n-----------Doubly Circular Linked list of character-----------\n";
   DoublyCLL<char> *cdobj = new DoublyCLL<char>();

    cdobj->Display();
    
    cdobj->InsertFirst('C');
    cdobj->InsertFirst('B');
    cdobj->InsertFirst('A');

    cdobj->InsertLast('D');
    cdobj->InsertLast('E');
    cdobj->InsertLast('F');

    cdobj->Display();
    cRet = cdobj->Count();
    cout<<"The no-> of elements : "<<cRet<<endl;

    cdobj->DeleteFirst();
    cdobj->DeleteLast();

    cdobj->Display();
    cRet = cdobj->Count();
    cout<<"The no-> of elements : "<<cRet<<endl;

    cdobj->InsertAtPos('G',3);
    cdobj->Display();
    cRet = cdobj->Count();
    cout<<"The no-> of elements : "<<cRet<<endl;

    cdobj->DeleteAtPos(3);
    cdobj->Display();
    cRet = cdobj->Count();
    cout<<"The no-> of elements : "<<cRet<<endl;

    //DOUBLY LL OF FLOAT
    cout<<"\n-----------Doubly Circular Linked list of float-----------\n";
    DoublyCLL<float> *fdobj = new DoublyCLL<float>();
      
    fdobj->InsertFirst(51);
    fdobj->InsertFirst(21);
    fdobj->InsertFirst(11);

    fdobj->Display();
    iRet = fdobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fdobj->InsertLast(101);
    fdobj->InsertLast(111);
    fdobj->InsertLast(121);

    fdobj->Display();
    iRet = fdobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fdobj->DeleteFirst();
    iRet = fdobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fdobj->DeleteLast();
    fdobj->Display();
    iRet = fdobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fdobj->InsertAtPos(55,3);
    fdobj->Display();
    iRet = fdobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    fdobj->DeleteAtPos(3);
    fdobj->Display();
    iRet = fdobj->Count();
    cout<<"The count of elements is : "<<iRet<<endl;

    //QUEUE
    cout<<"\n-----------Queue of characters-----------\n"; 
    Queue<char> *qobj = new Queue<char>();
    
    char idequeue = '\0';

    qobj->enqueue('F');
    qobj->enqueue('E');
    qobj->enqueue('D');
    qobj->enqueue('C');
    qobj->enqueue('B');
    qobj->enqueue('A');

    qobj->Display();
    iRet = qobj->Count();
    cout<<"Count of elements : "<<iRet<<endl<<endl;
    
    idequeue = qobj->dequeue();
    cout<<"Removed element is : "<<idequeue<<endl;
    qobj->Display();
    iRet = qobj->Count();
    cout<<"Count of elements : "<<iRet<<endl<<endl;

    idequeue = qobj->dequeue();
    cout<<"Removed element is : "<<idequeue<<endl;
    qobj->Display();
    iRet = qobj->Count();
    cout<<"Count of elements : "<<iRet<<endl<<endl;

    //STACK
    cout<<"\n-----------Stack of integers-----------\n";
    Stack<int> *ssobj = new Stack<int>();
    int ipop = 0;

    ssobj->push(60);
    ssobj->push(50);
    ssobj->push(40);
    ssobj->push(30);
    ssobj->push(20);
    ssobj->push(10);

    ssobj->Display();
    iRet = ssobj->Count();
    cout<<"Count of elements : "<<iRet<<endl<<endl;
    
    ipop = ssobj->pop();
    cout<<"Popped element is : "<<ipop<<endl;
    ssobj->Display();
    iRet = ssobj->Count();
    cout<<"Count of elements : "<<iRet<<endl<<endl;

    ipop = ssobj->pop();
    cout<<"Popped element is : "<<ipop<<endl;
    ssobj->Display();
    iRet = ssobj->Count();
    cout<<"Count of elements : "<<iRet<<endl<<endl;

    return 0;
}