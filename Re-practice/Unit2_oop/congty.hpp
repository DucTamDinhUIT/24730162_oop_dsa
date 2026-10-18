#pragma once
#include <iostream>
#include <string>
using namespace std;
class congty
{
private:
    /* data */
    int maNV;
    string tenNV;
    int namSinh;
    float luongCB;
public:
    congty(/* args */);
    congty(int maNV, string tenNV, int namSinh, float luongCB);
    ~congty();
    void nhap();
    void xuat();
};
