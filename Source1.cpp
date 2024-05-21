#include <iostream>
#include <fstream>
#include <vector>
#include "GATE.h"

int main() {
    int tien, triTue, sucManh;
    std::cout << "Nhap so tien, chi so tri tue va chi so suc manh cua hoang tu: ";
    std::cin >> tien >> triTue >> sucManh;

    int n;
    std::cout << "Nhap so luong cong: ";
    std::cin >> n;

    std::vector<Cong*> dsCong;
    bool coCongGiaoThuong = false, coCongHocThuat = false, coCongSucManh = false;
    for (int i = 0; i < n; ++i) {
        int loai;
        std::cout << "Nhap loai cong (1: Giao thuong, 2: Hoc thuat, 3: Suc manh): ";
        std::cin >> loai;
        if (loai == 1) {
            int gia, hang;
            std::cout << "Nhap don gia va so hang: ";
            std::cin >> gia >> hang;
            dsCong.push_back(new CongGiaoThuong(gia, hang));
            coCongGiaoThuong = true;
        }
        else if (loai == 2) {
            int triTue;
            std::cout << "Nhap chi so tri tue: ";
            std::cin >> triTue;
            dsCong.push_back(new CongHocThuat(triTue));
            coCongHocThuat = true;
        }
        else if (loai == 3) {
            int sucManh;
            std::cout << "Nhap suc manh dung sy: ";
            std::cin >> sucManh;
            dsCong.push_back(new CongSucManh(sucManh));
            coCongSucManh = true;
        }
    }


    bool giaoThuongQua = false, hocThuatQua = false, sucManhQua = false;

    for (Cong* cong : dsCong) {
        if (dynamic_cast<CongGiaoThuong*>(cong)) {
            if (cong->quaCong(tien, triTue, sucManh)) giaoThuongQua = true;
        }
        else if (dynamic_cast<CongHocThuat*>(cong)) {
            if (cong->quaCong(tien, triTue, sucManh)) hocThuatQua = true;
        }
        else if (dynamic_cast<CongSucManh*>(cong)) {
            if (cong->quaCong(tien, triTue, sucManh)) sucManhQua = true;
        }

        if (giaoThuongQua && hocThuatQua && sucManhQua) break;
    }

    std::ofstream outFile("result.out");
    if (outFile.is_open()) {
        if (giaoThuongQua && hocThuatQua && sucManhQua) {
            outFile << "Hoang tu Phineas co the cuu cong chua Isabella.\n";
            outFile << "Tien con lai: " << tien << "\n";
            outFile << "Tri tue con lai: " << triTue << "\n";
            outFile << "Suc manh con lai: " << sucManh << "\n";
        }
        else {
            outFile << "Hoang tu Phineas khong the cuu cong chua Isabella.\n";
        }
        outFile.close();
        std::cout << "Ket qua da duoc ghi vao tep result.out.\n";
    }
    else {
        std::cerr << "Khong the mo file result.out de ghi.\n";
    }

    for (Cong* cong : dsCong) {
        delete cong;
    }

    return 0;
}
