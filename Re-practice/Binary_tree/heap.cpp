#include <iostream>
using namespace std;

int main()
{
    int data[] = {9, 5, 2, 8, 7, 3, 4, 1, 10};

    int n = sizeof(data) / sizeof(data[0]); // = 9
    cout << "n = " << n << endl;

    for (int i = n; i > 0; --i)
    {
        cout << i << endl;
    }
    return 0;
}