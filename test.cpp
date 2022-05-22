#include "dauSach.cpp"
#include "docGia.cpp"

int main() {
    DSdauSach* dauSachs = new DSdauSach();

    addBook(dauSachs, "111", "Holmes", "Conan", "trinh tham", 600, 1950);
    addBook(dauSachs, "121", "Holmes 2", "Conan", "trinh tham", 500, 1950);
    addBook(dauSachs, "311", "Holmes 3", "Conan", "trinh tham", 1000, 1950);

    printf("Cac sach da them:\n");
    for (int i = 0; i < dauSachs->bookCount; i++) {
        printf("%s - %s - %s - %s - %d trang - %d\n",
               dauSachs->list[i]->ISBN.c_str(),
               dauSachs->list[i]->bookName.c_str(),
               dauSachs->list[i]->bookAuth.c_str(),
               dauSachs->list[i]->bookCategory.c_str(),
               dauSachs->list[i]->bookPages,
               dauSachs->list[i]->publishYear);
    }

    DStheDocGia* DSThe = new DStheDocGia();
    addMember(DSThe, "Nguyen", "A", 1);
    addMember(DSThe, "Nguyen", "B", 1);
    addMember(DSThe, "Nguyen", "C", 0);
    addMember(DSThe, "Dang", "P", 1);
    addMember(DSThe, "Le", "O", 0);
    xoaThe(DSThe, 1);
    printf("Cac doc gia trong danh sach\n");
    printMember(DSThe);

dauSach* tmp = timSachTheoTen(dauSachs, "Holmes");
printf("%d\n", tmp -> bookList == nullptr);
addBook(tmp -> bookList, 1, "Ngan 2, Ke 1", tmp -> ISBN);

    // Tim sach co ten Holmes
    printf("Tim sach co ten Holmes\n");
    dauSach* book = timSachTheoTen(dauSachs, "Holmes");
    inTTSach(book);

    // Tim sach co ten Conan
    printf("Tim sach co ten Conan\n");
    book = timSachTheoTen(dauSachs, "Conan");
    inTTSach(book);

    return 0;
}