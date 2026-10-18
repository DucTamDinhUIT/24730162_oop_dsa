#include "laptrinhV.hpp"

laptrinhV::laptrinhV(/* args */)
{
}

laptrinhV::~laptrinhV()
{
}
laptrinhV::laptrinhV(int maNV, string tenNV, int namSinh, float luongCB, float soGioLamOvertime)
{
    this->soGioLamOvertime = soGioLamOvertime;
}



void laptrinhV::nhapSoGioLamOvertime()
{
    cout << "Nhap so gio lam overtime: ";
    cin >> this->soGioLamOvertime;
}

void laptrinhV::xuatSoGioLamOvertime()
{
    cout << "So gio lam overtime: " << this->soGioLamOvertime << endl;
}
