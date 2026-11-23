#include <iostream>
using namespace std;

int main() {
    int x = 10;      // biến thường
    int* p = &x;     // p lưu địa chỉ của x

    cout << "Gia tri x ban dau: " << x << endl;   // 10
    cout << "Gia tri *p: " << *p << endl;         // 10

    *p = 25; // thay đổi giá trị tại địa chỉ p đang trỏ tới (tức là x)

    cout << "Gia tri x sau khi *p = 25: " << x << endl; // 25
    return 0;
}