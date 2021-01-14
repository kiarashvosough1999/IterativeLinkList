#include "LinkedLinearList.h"
#include <iostream>

using namespace std;

class X
{
public:
    void printStar(){
        cout << "* works" << endl;
    }

    void printArrow(){
        cout << "-> works" << endl;
    }

};


void testIteration()
{
    LinkedLinearList<double> lll;
    LinkedLinearList<double>::Iterator itr;

    itr = lll.begin();
    for (int i =0 ; i < 4; i++){
        itr = lll.insert(itr, i);} // returned itr refers to the inserted item

    cout << "List should be: 0	1	2	3\n";
    cout << lll << "\n";

    cout << "\nForward Iteration should be: 0	1	2	3\n";
    for (itr = lll.begin(); itr != lll.end(); itr++)
        cout << *itr << "\t";
    cout << "\n";

    cout << "\nBackward Iteration should be: 3	2	1	0\n";
    for (itr = lll.rbegin(); itr != lll.rend(); itr--)
        cout << *itr << "\t";
    cout << "\n";

    cout<<"\nresult of finding 6 in list:\n";
    if (lll.search(6)){
        cout<<"found\n";
    }else {
        cout<<"not found\n";
    }

    cout<<"\nrevered the list should be 3    2    1    0\n";
    lll.reversed();
    cout << lll << "\n";

}

void testDereferencing()
{
    LinkedLinearList<X> lll;
    LinkedLinearList<X>::Iterator itr;

    X x;
    itr = lll.begin();
    lll.insert(itr, x);

    itr = lll.begin();
    itr->printArrow();
    (*itr).printStar();
}

void testInsertRemove()
{
    LinkedLinearList<double> lll;
    LinkedLinearList<double>::Iterator itr;

    int N = 10;
    itr = lll.begin();
    for (int i = 0; i<N; ++i)
        itr = lll.insert(itr, i);

    itr = lll.begin();
    for (int i = 0; i < N; i+=2)
    {
        itr = lll.remove(itr);
        itr++;
    }

    cout << "List should be after remove: 1 3 5 7 9\n";
    cout << lll << "\n";
}

int main()
{
    testIteration();
    testDereferencing();
    testInsertRemove();
    int tmp;
    cin >> tmp;
    return 0;
}
