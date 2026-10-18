// Basic struct example in C++
#include <iostream>
#include <string>
using namespace std;

 struct hocsinh
 {
	int id;
	float diem;
 };

int main(){
	hocsinh hs1;
	hs1.id = 1;
	hs1.diem = 9.5;
	cout << "ID: " << hs1.id << ", Diem: " << hs1.diem << std::endl;
}
 