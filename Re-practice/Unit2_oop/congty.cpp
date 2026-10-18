#include "congty.hpp"

congty::congty(/* args */)
{
}

congty::~congty()
{
}

congty::congty(int maNV, string tenNV, int namSinh, float luongCB)
{
    this->maNV = maNV;
    this->tenNV = tenNV;
    this->namSinh = namSinh;
    this->luongCB = luongCB;
}

void congty::nhap()
{
    cout << "Nhap ma nhan vien: ";
    cin >> this->maNV;
    cout << "Nhap ten nhan vien: ";
    cin.ignore();
    getline(cin, this->tenNV);
    cout << "Nhap nam sinh: ";
    cin >> this->namSinh;
    cout << "Nhap luong co ban: ";
    cin >> this->luongCB;
}

void congty::xuat()
{
    cout << "Ma nhan vien: " << this->maNV << endl;
    cout << "Ten nhan vien: " << this->tenNV << endl;
    cout << "Nam sinh: " << this->namSinh << endl;
    cout << "Luong co ban: " << this->luongCB << endl;
}   