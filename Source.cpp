#include "GATE.h"

bool CongGiaoThuong::quaCong(int& tien, int triTue, int& sucManh) {
    if (!daQua) {
        int chiPhi = donGia * soHang;
        if (tien >= chiPhi) {
            tien -= chiPhi;
            daQua = true;
            return true;
        }
        return false;
    }
    return true;
}

bool CongHocThuat::quaCong(int& tien, int triTue, int& sucManh) {
    if (!daQua) {
        if (triTue >= chiSoTriTue) {
            daQua = true;
            return true;
        }
        return false;
    }
    return true;
}

bool CongSucManh::quaCong(int& tien, int triTue, int& sucManh) {
    if (!daQua) {
        if (sucManh > chiSoSucManh) {
            daQua = true;
            sucManh -= chiSoSucManh;
            return true;
        }
        return false;
    }
    return true;
}

Castle::~Castle() {
}
