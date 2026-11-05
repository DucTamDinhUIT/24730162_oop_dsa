// Vi du OOP co su dung con tro trong C++
#include <iostream>
#include <string>

// Lop co so (base class)
class Animal {
protected:
	std::string name;

public:
	Animal(const std::string& n) : name(n) {}

	// Ham ao de the hien tinh da hinh (polymorphism)
	virtual void speak() const {
		std::cout << name << " phat ra am thanh." << std::endl;
	}

	// Destructor ao de giai phong dung khi xoa qua con tro base
	virtual ~Animal() {}
};

// Lop dan xuat (derived class)
class Dog : public Animal {
public:
	Dog(const std::string& n) : Animal(n) {}

	void speak() const override {
		std::cout << name << " sua: Gau gau!" << std::endl;
	}
};

int main() {
	// Tao doi tuong bang con tro (cap phat dong tren heap)
	Animal* pet = new Dog("Milo");

	// Goi ham ao qua con tro base -> chay ham cua lop Dog
	pet->speak();

	// Giai phong bo nho sau khi dung xong
	delete pet;
	pet = nullptr;

	return 0;
}

