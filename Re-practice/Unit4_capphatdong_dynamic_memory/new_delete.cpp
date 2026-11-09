#include <iostream>
#include <string>
using namespace std;

struct Student
{
    int id;
    string name;

    // Constructor được tự động gọi khi dùng new
    Student(int i, string n) : id(i), name(n)
    {
        cout << "Khoi tao sinh vien: " << name << endl;
    }

    ~Student()
    {
        cout << "Huy sinh vien: " << name << endl;
    }
};

int main()
{
    // 1. Cấp phát đơn lẻ và khởi tạo giá trị
    int *pNum = new int(42);
    Student *s1 = new Student(101, "Tam");

    cout << "ID: " << s1->id << ", Name: " << s1->name << endl;

    // Giải phóng phần tử đơn lẻ
    delete pNum;
    delete s1; // Gọi Destructor rồi mới trả lại bộ nhớ

    // 2. Cấp phát mảng
    int size = 3;
    int *arr = new int[size]; // Khởi tạo mảng trực tiếp

    // Gán giá trị sau khi cấp phát
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;

    // Giải phóng mảng BẮT BUỘC dùng delete[]
    delete[] arr;

    return 0;
}