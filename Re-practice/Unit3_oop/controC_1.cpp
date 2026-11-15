// Vi du OOP co su dung con tro trong C++
#include <iostream>
#include <string>
#include <typeinfo>

// Lop co so (base class)
class Animal {
protected:
	std::string name;

public:
	Animal(const std::string& n) : name(n) {}

	const std::string& getName() const {
		return name;
	}

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

	// Xem địa chỉ con trỏ
	std::cout << "pet = " << pet << std::endl;

	// Xem kiểu đối tượng thực sự mà con trỏ đang trỏ tới
	std::cout << "typeid(*pet) = " << typeid(*pet).name() << std::endl;

	// Ép về kiểu Dog để xem con trỏ cụ thể
	Dog* dog = dynamic_cast<Dog*>(pet);
	std::cout << "dog = " << dog << std::endl;

	if (dog != nullptr) {
		std::cout << "dog->getName() = " << dog->getName() << std::endl;
	}

	// Goi ham ao qua con tro base -> chay ham cua lop Dog
	pet->speak();

	// Giai phong bo nho sau khi dung xong
	delete pet;
	pet = nullptr;

	std::cout << "Sau khi delete: pet = " << pet << std::endl;

	return 0;
}

