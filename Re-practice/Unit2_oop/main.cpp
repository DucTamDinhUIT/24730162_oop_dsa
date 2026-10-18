#include <iostream>
#include "congty.hpp"
//#include "laptrinhV.hpp"
using namespace std;

int main(){
    congty a;
    a.nhap();
    a.xuat();
}



/*

Trang 2 / 3 – Đề 1
 Hiện tại, Công ty phần mềm Hoàn cầu lưu trữ các thông tin sau:
  - Đối với Lập trình viên: 
  mã nhân viên, họ tên, năm sinh, lương cơ bản, số giờ làm overtime. 
  - Đối với Kiểm chứng viên:
   mã nhân viên, họ tên, năm sinh, lương cơ bản, số lỗi phát hiện được. 
  Do tính chất công việc khác nhau, nên lương hàng tháng của
   Lập trình viên và Kiểm chứng viên cũng khác nhau.
   Cụ thể: - Lương (Lập trình viên) = 
   lương cơ bản + số giờ làm thêm * 200.000 - Lương (kiểm chứng viên) = lương cơ bản + số lỗi * 50.000 
   Bạn hãy đề xuất thiết kế các lớp đối tượng cần thiết để quản lý
    danh sách các nhân viên của Công ty và hỗ trợ tính lương cho nhân viên theo tiêu chí đặt ra như trên. 
   Hãy viết chương trình bằng C++ cho phép thực hiện các yêu cầu sau: 
   1. Nhập vào danh sách nhân viên của công ty gồm Lập trình viên và Kiểm chứng viên (1 điểm). 
   2. Tính tổng lương mà công ty phải trả cho các nhân viên (0.5 điểm).*/