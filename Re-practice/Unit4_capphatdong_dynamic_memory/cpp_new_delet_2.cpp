#include <iostream>
using namespace std;

struct concho
{
    int id;
    long age;

    concho(int m, long n) : id(m), age(n)
    {
        cout << "khoi tao con cho" << endl;
    };
};
int main()
{
    concho *a = new concho(3, 12.3); 
    cout << a->id << endl;
    cout << a->age;
    
    return 0;
}