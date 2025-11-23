#include <stdio.h>
#include <string.h>

struct Contact {
    char name[50];
    char phoneNumber[15];
    char email[50];
};

int main() {
    struct Contact ct[100];
    int n = 0, choose;

    do {
        printf("\n========== MENU ==========\n");
        printf("1. Them lien he moi\n");
        printf("2. Hien thi tat ca lien he\n");
        printf("3. Tim kiem theo ten\n");
        printf("4. Xoa lien he theo ten\n");
        printf("5. Thoat\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choose);
        getchar();
        switch (choose) {
        case 1: {
            printf("Nhap ten: ");
            fgets(ct[n].name, sizeof(ct[n].name), stdin);
            ct[n].name[strcspn(ct[n].name, "\n")] = '\0';

            printf("Nhap so dien thoai: ");
            fgets(ct[n].phoneNumber, sizeof(ct[n].phoneNumber), stdin);
            ct[n].phoneNumber[strcspn(ct[n].phoneNumber, "\n")] = '\0';

            printf("Nhap email: ");
            fgets(ct[n].email, sizeof(ct[n].email), stdin);
            ct[n].email[strcspn(ct[n].email, "\n")] = '\0';

            n++;
            printf(">> Them thanh cong!\n");
            break;
        }
        case 2: {
            if (n == 0) {
                printf(">> Khong co lien he nao!\n");
            } else {
                printf("\n--- Danh sach lien he ---\n");
                for (int i = 0; i < n; i++) {
                    printf("%d. %s - %s - %s\n", i + 1, ct[i].name, ct[i].phoneNumber, ct[i].email);
                }
            }
            break;
        }
        case 3: {
            char key[50];
            printf("Nhap ten can tim: ");
            fgets(key, sizeof(key), stdin);
            key[strcspn(key, "\n")] = '\0';

            int found = 0;
            for (int i = 0; i < n; i++) {
                if (strcasecmp(ct[i].name, key) == 0) {
                    printf(">> Tim thay: %s - %s - %s\n",
                           ct[i].name, ct[i].phoneNumber, ct[i].email);
                    found = 1;
                }
            }
            if (!found) printf(">> Khong tim thay!\n");
            break;
        }

        case 4: {
            char delName[50];
            printf("Nhap ten can xoa: ");
            fgets(delName, sizeof(delName), stdin);
            delName[strcspn(delName, "\n")] = '\0';

            int found = -1;
            for (int i = 0; i < n; i++) {
                if (strcasecmp(ct[i].name, delName) == 0) {
                    found = i;
                    break;
                }
            }

            if (found == -1) {
                printf(">> Khong tim thay lien he!\n");
            } else {
                for (int i = found; i < n - 1; i++) {
                    ct[i] = ct[i + 1];  
                }
                n--;
                printf(">> Da xoa thanh cong!\n");
            }
            break;
        }

        case 5:
            printf("Thoat chuong trinh...\n");
            break;

        default:
            printf(">> Lua chon khong hop le!\n");
        }

    } while (choose != 5);

    return 0;
}
