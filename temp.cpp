#include <iostream>
using namespace std;

void printMenu() {
    printf("_____\n");
    printf("CHON 1 CHUC NANG:\n");
    printf("1. Them/ Chinh sua the doc gia.\n");
    printf("2. Xoa the doc gia.\n");
    printf("3. In danh sach doc gia.\n");
    printf("4. Them mot dau sach.\n");
    printf("5. Them sach vao dau sach.\n");
    printf("6. In cac dau sach.\n");
    printf("7. Tim thong tin sach.\n");
    printf("8. Muon sach.\n");
    printf("0. Ket thuc chuong trinh.\n");

    printf("_____\n");
    printf("Your option: ");
}

int main() {
    int option;
    do {
        printMenu();
        cin >> option;
        switch (option) {
            // if(option == 1)
            case 1:
                printf("1. Them/ Chinh sua the doc gia.\n");

                break;
            case 2:
                printf("2. Xoa the doc gia.\n");

                break;
            case 3:
                printf("3. In danh sach doc gia.\n");

                break;
            case 4:
                printf("4. Them mot dau sach.\n");

                break;
            case 5:
                printf("5. Them sach vao dau sach.\n");

                break;
            case 6:
                printf("6. In cac dau sach.\n");

                break;
            case 7:
                printf("7. Tim thong tin sach.\n");

                break;
            case 8:
                printf("8. Muon sach.\n");

                break;
            case 0:
                printf("0. Ket thuc chuong trinh.\n");
                break;
        }
    } while (option != 0);
}