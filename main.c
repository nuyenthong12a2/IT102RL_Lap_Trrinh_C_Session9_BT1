#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay ds[50];
    int n;

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");

    // Bat nhap n trong khoang 1 den 50
    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        while (getchar() != '\n'); // xoa bo dem tranh troi lenh
    } while (n < 1 || n > 50);

    // Vong lap nhap tung ve
    for (int i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(ds[i].maPNR, sizeof(ds[i].maPNR), stdin);
        ds[i].maPNR[strcspn(ds[i].maPNR, "\n")] = '\0'; // xoa \n o cuoi

        printf("Nhap ho ten hanh khach: ");
        fgets(ds[i].tenHanhKhach, sizeof(ds[i].tenHanhKhach), stdin);
        ds[i].tenHanhKhach[strcspn(ds[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(ds[i].hangVe, sizeof(ds[i].hangVe), stdin);
        ds[i].hangVe[strcspn(ds[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ds[i].trongLuongHanhLy);
        while (getchar() != '\n');

        // Tinh phu thu hanh ly qua 7kg
        if (ds[i].trongLuongHanhLy > 7.0) {
            ds[i].phiPhuThu = (long)((ds[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ds[i].phiPhuThu = 0;
        }
    }

    // In bang danh sach ban dau
    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");
    printf("-----------------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-15s %-15s\n", 
           "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
    printf("-----------------------------------------------------------------------------------------\n");

    for (int i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-15.1f %-15ld\n", 
               i + 1, ds[i].maPNR, ds[i].tenHanhKhach, ds[i].hangVe, ds[i].trongLuongHanhLy, ds[i].phiPhuThu);
    }
    printf("-----------------------------------------------------------------------------------------\n");

    // Tim kiem va cap nhat lai hanh ly
    char pnrTimKiem[10];
    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(pnrTimKiem, sizeof(pnrTimKiem), stdin);
    pnrTimKiem[strcspn(pnrTimKiem, "\n")] = '\0';

    int viTriTimThay = -1; // -1 la chua tim thay
    for (int i = 0; i < n; i++) {
        if (strcmp(ds[i].maPNR, pnrTimKiem) == 0) {
            viTriTimThay = i;
            break;
        }
    }

    if (viTriTimThay != -1) {
        printf("Tim thay ve cua hanh khach: %s\n", ds[viTriTimThay].tenHanhKhach);
        printf("Nhap trong luong hanh ly moi (kg): ");
        scanf("%f", &ds[viTriTimThay].trongLuongHanhLy);
        while (getchar() != '\n');

        // Tinh lai phu thu
        if (ds[viTriTimThay].trongLuongHanhLy > 7.0) {
            ds[viTriTimThay].phiPhuThu = (long)((ds[viTriTimThay].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ds[viTriTimThay].phiPhuThu = 0;
        }

        printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n", ds[viTriTimThay].phiPhuThu);

        // In lai bang sau khi sua
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");
        printf("-----------------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-15s %-15s\n", 
               "STT", "MA PNR", "HO TEN HANH KHACH", "HANG VE", "HANH LY(KG)", "PHI PHU THU(VND)");
        printf("-----------------------------------------------------------------------------------------\n");

        for (int i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-15.1f %-15ld\n", 
                   i + 1, ds[i].maPNR, ds[i].tenHanhKhach, ds[i].hangVe, ds[i].trongLuongHanhLy, ds[i].phiPhuThu);
        }
        printf("-----------------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le trong he thong!\n");
    }

    return 0;
}
