#pragma once

#include <iostream>
#include <string>
#include "congty.hpp"
using namespace std;

class laptrinhV : public congty
{
private:
    float soGioLamOvertime;
public:
    laptrinhV(/* args */);
    ~laptrinhV();
    laptrinhV(int maNV, string tenNV, int namSinh, float luongCB, float soGioLamOvertime);
    //void nhap();
    //void xuat();
    void nhapSoGioLamOvertime();
    void xuatSoGioLamOvertime();
};


