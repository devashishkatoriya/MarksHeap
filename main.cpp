
/*
 * Read the marks obtained by students of second year
 * in an online examination of particular subject.
 * Find out maximum and minimum marks obtained in that subject.
 * Use heap data structure.
 */


/*
 * Created by Devashish Katoriya on 14-03-2017
 */

#include <iostream>

using namespace std;

#define LIMIT 100

class Heap
{
    int a[LIMIT],n;
    void reHeapUp();
    void reHeapDown();
public:
    Heap()
    {
        n = 0;
        for(int i=0;i<LIMIT;i++)
            a[i] = 0;
    }
    inline bool isFull()
    {
        return n == LIMIT-1;
    }
    inline bool isEmpty()
    {
        return n == 0;
    }
    void clr()
    {
        n = 0;
        for(int i=0;i<LIMIT;i++)
            a[i] = 0;
    }
    void insert();
    void display();
    void max();
    void min();
};

void Heap::max()
{
    if(isEmpty())
    {
        cout<<"\nDatabase is Empty!";
        return;
    }
    else
    {
        cout<<"\nMaximum Marks are "<<a[0];
    }
}

void Heap::min()
{
    if(isEmpty())
    {
        cout<<"\nDatabase is Empty!";
        return;
    }
    else
    {
        reHeapDown();
        cout<<"\nMinimum Marks are "<<a[0];
        reHeapUp();
    }
}

void Heap::reHeapDown()
{
    int i,j,k,root;
    for(i=1;i<n;i++)
    {
        root = a[i];
        j = i;
        k = (j-1)/2;
        while(j>0 && a[k]>root)
        {
            a[j] = a[k];
            j = k;
            k = (j-1)/2;
        }
        a[j] = root;
    }
}

void Heap::reHeapUp()
{
    int i,j,k,root;
    for(i=1;i<n;i++)
    {
        root = a[i];
        j = i;
        k = (j-1)/2;
        while(j>0 && a[k]<root)
        {
            a[j] = a[k];
            j = k;
            k = (j-1)/2;
        }
        a[j] = root;
    }
}

void Heap::insert()
{
    int element;
    cout<<"\nEnter -99 to stop.";
    while(1)
    {
        cout << "\n\nEnter next marks : ";
        cin >> element;
        if(element == -99)
            break;
        if (!isFull())
        {
            a[n++] = element;
            reHeapUp();
            cout << "Marks inserted Successfully!";
        }
        else
            cout << "\nDatabase is Full!";
    }
}

void Heap::display()
{
    if(isEmpty())
    {
        cout<<"\nDatabase is Empty!";
        return;
    }
    cout<<"\nThe contents of Max.Heap are :- \n";
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<"\t";
    }
}

int main()
{
    Heap obj;
    int ch;
    char choice;
    cout<<"\nProgram to find Max and Min marks using Heap.";
    do
    {
        ch = 0;
        choice = 'n';
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 for Insertion";
        cout<<"\n 2 for Display Heap";
        cout<<"\n 3 for Max. marks";
        cout<<"\n 4 for Min. marks";
        cout<<"\n 5 for Is-Full";
        cout<<"\n 6 for Is-Empty";
        cout<<"\n -1 to Clear Heap";
        cout<<"\n  0 to Exit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch)
        {
            case 1 : obj.insert();
                break;
            case 2 : obj.display();
                break;
            case 3 : obj.max();
                break;
            case 4 : obj.min();
                break;
            case 5 : if(obj.isFull())
                    cout<<"\nThe Database is Full!";
                else
                    cout<<"\nThe Database is Not full.";
                break;
            case 6 : if(obj.isEmpty())
                    cout<<"\nThe Database is Empty!";
                else
                    cout<<"\nThe Database is Not empty.";
                break;
            case -1: cout<<"\nAre you sure, you want to clear the Database (y/n) ? ";
                cin>>choice;
                if(choice == 'y' || choice == 'Y')
                {
                    obj.clr();
                    cout<<"\nDatabase cleared Successfully!";
                }
                else
                    cout<<"\nCancelled!";
            case 0 : break;
            default: cout<<"\nInvalid Option!";
        }
        
    }while(ch!=0);
    
    cout<<"\n\nThank you for using this program :)\n\n";
    return 0;
}

/* OUTPUT

*/