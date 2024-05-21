#ifndef GATE_H
#define GATE_H

#include <iostream>
#include <vector>

class Cong {
public:
    virtual bool quaCong(int& tien, int triTue, int& sucManh) = 0;
    virtual ~Cong() {}
};

class CongGiaoThuong : public Cong {
private:
    int donGia;
    int soHang;
    bool daQua;
public:
    CongGiaoThuong(int gia, int hang) : donGia(gia), soHang(hang), daQua(false) {}
    bool quaCong(int& tien, int triTue, int& sucManh) override;
};

class CongHocThuat : public Cong {
private:
    int chiSoTriTue;
    bool daQua;
public:
    CongHocThuat(int triTue) : chiSoTriTue(triTue), daQua(false) {}
    bool quaCong(int& tien, int triTue, int& sucManh) override;
};

class CongSucManh : public Cong {
private:
    int chiSoSucManh;
    bool daQua;
public:
    CongSucManh(int sucManh) : chiSoSucManh(sucManh), daQua(false) {}
    bool quaCong(int& tien, int triTue, int& sucManh) override;
};

class Castle {
private:
    bool daKichHoatTuHuy;
public:
    Castle() : daKichHoatTuHuy(false) {}
    ~Castle();
    void kichHoatTuHuy() { daKichHoatTuHuy = true; }
    bool daDuocKichHoat() const { return daKichHoatTuHuy; }
};

#endif
