#include <iostream>
#include <vector>
#include <algorithm>

class KhachHang {
public:
    static int nextMaKH; // S? nguyên t? d?ng tang d? làm mã khách hàng
    int maKH;
    std::string hoTen;
    std::string diaChi;
    std::string soDT;
    std::string loaiKH;

    KhachHang() : maKH(nextMaKH++) {}

    void NhapKH() {
        std::cout << "Nhap ho ten: ";
        std::getline(std::cin, hoTen);
        std::cout << "Nhap dia chi: ";
        std::getline(std::cin, diaChi);
        std::cout << "Nhap so dien thoai: ";
        std::getline(std::cin, soDT);
        std::cout << "Nhap loai khach hang: ";
        std::getline(std::cin, loaiKH);
    }
};

int KhachHang::nextMaKH = 10000; // Kh?i t?o mã khách hàng

class LoaiDichVu {
public:
    static int nextMaDV; // S? nguyên t? d?ng tang d? làm mã d?ch v?
    int maDV;
    std::string moTa;
    double mucGiaCuoc; // Gi? s? tính cu?c theo dung lu?ng

    LoaiDichVu() : maDV(nextMaDV++) {}

    void NhapDV() {
        std::cout << "Nhap mo ta dich vu: ";
        std::getline(std::cin, moTa);
        std::cout << "Nhap muc gia cuoc: ";
        std::cin >> mucGiaCuoc;
        std::cin.ignore(); // Ð?c b? d?u new line
    }
};

int LoaiDichVu::nextMaDV = 100; // Kh?i t?o mã d?ch v?

class HoaDon {
public:
    KhachHang* khachHang;
    LoaiDichVu* loaiDichVu;
    double soLuongSuDung;

    HoaDon(KhachHang* kh, LoaiDichVu* dv, double sl) : khachHang(kh), loaiDichVu(dv), soLuongSuDung(sl) {}

    static bool CompareByHoTen(const HoaDon& a, const HoaDon& b) {
        return a.khachHang->hoTen < b.khachHang->hoTen;
    }

    static bool CompareBySoLuongSuDung(const HoaDon& a, const HoaDon& b) {
        return a.soLuongSuDung > b.soLuongSuDung;
    }

    double TinhTien() const {
        return soLuongSuDung * loaiDichVu->mucGiaCuoc;
    }
};

int main() {
    std::vector<KhachHang> danhSachKhachHang;
    std::vector<LoaiDichVu> danhSachDichVu;
    std::vector<HoaDon> danhSachHoaDon;

    int slKH;
    std::cout << "Nhap so luong khach hang: ";
    std::cin >> slKH;
    std::cin.ignore();

    for (int i = 0; i < slKH; ++i) {
        KhachHang kh;
        std::cout << "Nhap thong tin cho khach hang thu " << i + 1 << ":\n";
        kh.NhapKH();
        danhSachKhachHang.push_back(kh);
    }

    int slDV;
    std::cout << "Nhap so luong loai dich vu: ";
    std::cin >> slDV;
    std::cin.ignore();

    for (int i = 0; i < slDV; ++i) {
        LoaiDichVu dv;
        std::cout << "Nhap thong tin cho loai dich vu thu " << i + 1 << ":\n";
        dv.NhapDV();
        danhSachDichVu.push_back(dv);
    }

    for (const auto& khachHang : danhSachKhachHang) {
        for (const auto& loaiDichVu : danhSachDichVu) {
            double soLuong;
            std::cout << "Nhap so luong su dung cho dich vu " << loaiDichVu.moTa << " cua khach hang " << khachHang.hoTen << ": ";
            std::cin >> soLuong;
            danhSachHoaDon.emplace_back(&const_cast<KhachHang&>(khachHang), &const_cast<LoaiDichVu&>(loaiDichVu), soLuong);
        }
    }

    // S?p x?p danh sách hóa don
    std::sort(danhSachHoaDon.begin(), danhSachHoaDon.end(), HoaDon::CompareByHoTen);
    std::sort(danhSachHoaDon.begin(), danhSachHoaDon.end(), HoaDon::CompareBySoLuongSuDung);

    // In danh sách hóa don
    std::cout << "\nDanh sach hoa don:\n";
    for (const auto& hoaDon : danhSachHoaDon) {
        std::cout << "Khach hang: " << hoaDon.khachHang->hoTen << ", Dich vu: " << hoaDon.loaiDichVu->moTa
                  << ", So luong su dung: " << hoaDon.soLuongSuDung << ", Thanh tien: " << hoaDon.TinhTien() << std::endl;
    }

    // L?p b?ng kê s? ti?n ph?i tr? cho m?i khách hàng
    std::cout << "\nBang ke so tien phai tra cho moi khach hang:\n";
    for (const auto& khachHang : danhSachKhachHang) {
        double tongTien = 0.0;
        for (const auto& hoaDon : danhSachHoaDon) {
            if (hoaDon.khachHang == &khachHang) {
                tongTien += hoaDon.TinhTien();
            }
        }
        std::cout << "Khach hang: " << khachHang.hoTen << ", Tong tien phai tra: " << tongTien << std::endl;
    }

    return 0;
}

