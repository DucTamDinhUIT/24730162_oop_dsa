#include <iostream>

using namespace std;

int main()
{
    // int a = 10;
    // cout << a << endl;
    // cout << &a << endl;
    // int *adr = &a;
    // cout << adr << endl;
    // *adr = 12;
    // cout << *adr << endl;
    // cout << &adr << endl;
    // cout << a;
    int a = 10;
    int * poa = &a;
    int b;
    int * pob  = &b;
        *pob = 12;
    int c = *pob;

    cout << c;
}