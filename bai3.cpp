#include <stdio.h>
#include <string.h>

struct NgaySinh {
    int ngay;
    int thang;
    int nam;
};

struct SinhVien {
    char maSV[20];
    char hoTen[50];
    struct NgaySinh ns;
    char diaChi[100];
    char dienThoai[15];
};

void xoaXuongDong(char *str) {
    str[strcspn(str, "\n")] = '\0';
}

int main() {
    struct SinhVien sv[100];
    int n = 0, choose;

    do {
        printf("\n=========== MENU ===========\n");
        printf("1. Nhap thong tin sinh vien\n");
        printf("2. Hien thi thong tin sinh vien\n");
        printf("3. Them sinh vien vao cuoi danh sach\n");
        printf("4. Xoa sinh vien theo ma SV\n");
        printf("5. Cap nhat thong tin sinh vien theo ma SV\n");
        printf("6. Sap xep sinh vien theo ho ten (A-Z)\n");
        printf("7. Tim kiem sinh vien theo ma SV\n");
        printf("8. Thoat\n");
        printf("Chon: ");
        scanf("%d", &choose);
        getchar(); 
        switch (choose) {

        case 1: {
            printf("Nhap so luong sinh vien: ");
            scanf("%d", &n);
            getchar();

            for (int i = 0; i < n; i++) {
                printf("\n--- Sinh vien %d ---\n", i + 1);

                printf("Ma SV: ");
                fgets(sv[i].maSV, sizeof(sv[i].maSV), stdin);
                xoaXuongDong(sv[i].maSV);

                printf("Ho ten: ");
                fgets(sv[i].hoTen, sizeof(sv[i].hoTen), stdin);
                xoaXuongDong(sv[i].hoTen);

                printf("Ngay sinh (ngay thang nam): ");
                scanf("%d %d %d", &sv[i].ns.ngay, &sv[i].ns.thang, &sv[i].ns.nam);
                getchar();

                printf("Dia chi: ");
                fgets(sv[i].diaChi, sizeof(sv[i].diaChi), stdin);
                xoaXuongDong(sv[i].diaChi);

                printf("Dien thoai: ");
                fgets(sv[i].dienThoai, sizeof(sv[i].dienThoai), stdin);
                xoaXuongDong(sv[i].dienThoai);
            }
            break;
        }
        case 2: {
            if (n == 0) {
                printf("Chua co sinh vien nao!\n");
            } else {
                printf("\n===== DANH SACH SINH VIEN =====\n");
                for (int i = 0; i < n; i++) {
                    printf("%d. %s - %s - %02d/%02d/%04d - %s - %s\n",
                           i + 1,
                           sv[i].maSV,
                           sv[i].hoTen,
                           sv[i].ns.ngay, sv[i].ns.thang, sv[i].ns.nam,
                           sv[i].diaChi,
                           sv[i].dienThoai);
                }
            }
            break;
        }
        case 3: {
            printf("\n--- Them sinh vien moi ---\n");

            printf("Ma SV: ");
            fgets(sv[n].maSV, sizeof(sv[n].maSV), stdin);
            xoaXuongDong(sv[n].maSV);

            printf("Ho ten: ");
            fgets(sv[n].hoTen, sizeof(sv[n].hoTen), stdin);
            xoaXuongDong(sv[n].hoTen);

            printf("Ngay sinh (ngay thang nam): ");
            scanf("%d %d %d", &sv[n].ns.ngay, &sv[n].ns.thang, &sv[n].ns.nam);
            getchar();

            printf("Dia chi: ");
            fgets(sv[n].diaChi, sizeof(sv[n].diaChi), stdin);
            xoaXuongDong(sv[n].diaChi);

            printf("Dien thoai: ");
            fgets(sv[n].dienThoai, sizeof(sv[n].dienThoai), stdin);
            xoaXuongDong(sv[n].dienThoai);

            n++;
            printf(">> Them thanh cong!\n");
            break;
        }
        case 4: {
            char maXoa[20];
            printf("Nhap ma SV can xoa: ");
            fgets(maXoa, sizeof(maXoa), stdin);
            xoaXuongDong(maXoa);

            int pos = -1;
            for (int i = 0; i < n; i++) {
                if (strcmp(sv[i].maSV, maXoa) == 0) {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                printf(">> Khong tim thay ma SV!\n");
            } else {
                for (int i = pos; i < n - 1; i++) {
                    sv[i] = sv[i + 1];
                }
                n--;
                printf(">> Xoa thanh cong!\n");
            }
            break;
        }
        case 5: {
            char maUpdate[20];
            printf("Nhap ma SV can cap nhat: ");
            fgets(maUpdate, sizeof(maUpdate), stdin);
            xoaXuongDong(maUpdate);

            int pos = -1;
            for (int i = 0; i < n; i++) {
                if (strcmp(sv[i].maSV, maUpdate) == 0) {
                    pos = i;
                    break;
                }
            }

            if (pos == -1) {
                printf(">> Khong tim thay!\n");
            } else {
                printf("Nhap ten moi: ");
                fgets(sv[pos].hoTen, sizeof(sv[pos].hoTen), stdin);
                xoaXuongDong(sv[pos].hoTen);

                printf("Nhap ngay sinh moi (ngay thang nam): ");
                scanf("%d %d %d", &sv[pos].ns.ngay, &sv[pos].ns.thang, &sv[pos].ns.nam);
                getchar();

                printf("Nhap dia chi moi: ");
                fgets(sv[pos].diaChi, sizeof(sv[pos].diaChi), stdin);
                xoaXuongDong(sv[pos].diaChi);

                printf("Nhap dien thoai moi: ");
                fgets(sv[pos].dienThoai, sizeof(sv[pos].dienThoai), stdin);
                xoaXuongDong(sv[pos].dienThoai);

                printf(">> Cap nhat thanh cong!\n");
            }
            break;
        }
        case 6: {
            for (int i = 0; i < n - 1; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (strcmp(sv[i].hoTen, sv[j].hoTen) > 0) {
                        struct SinhVien temp = sv[i];
                        sv[i] = sv[j];
                        sv[j] = temp;
                    }
                }
            }
            printf(">> Da sap xep xong!\n");
            break;
        }
        case 7: {
            char maTim[20];
            printf("Nhap ma SV can tim: ");
            fgets(maTim, sizeof(maTim), stdin);
            xoaXuongDong(maTim);

            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(sv[i].maSV, maTim) == 0) {
                    printf(">> %s - %s - %02d/%02d/%04d - %s - %s\n",
                           sv[i].maSV, sv[i].hoTen,
                           sv[i].ns.ngay, sv[i].ns.thang, sv[i].ns.nam,
                           sv[i].diaChi, sv[i].dienThoai);
                    found = 1;
                }
            }
            if (!found) printf(">> Khong tim thay!\n");
            break;
        }

        case 8:
            printf("Thoat chuong trinh...\n");
            break;

        default:
            printf("Lua chon khong hop le!\n");
        }

    } while (choose != 8);

    return 0;
}
