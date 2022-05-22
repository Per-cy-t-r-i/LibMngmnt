#include <stdio.h>

#include <string>

#include "danhMucSach.cpp"

using std::string;

struct dauSach {
    std::string ISBN;
    std::string bookName;
    std::string bookAuth;
    std::string bookCategory;

    int bookPages;
    int publishYear;

    int ID;

    // chua danh sach cac sach cung danh muc
    danhMucSach* bookList;
};

struct DSdauSach {
    int bookCount = 0;
    dauSach* list[100000];
};

// Nhập thông tin đầu sách
void addBook(DSdauSach* headList, string ISBN,
             string bookName,
             string bookAuth,
             string bookCategory,
             int bookPages, int publishYear,
             danhMucSach* bookList) {
    dauSach* newBook = new dauSach();
    newBook->ISBN = ISBN;
    newBook->bookName = bookName;
    newBook->bookAuth = bookAuth;
    newBook->bookCategory = bookCategory;
    newBook->bookPages = bookPages;
    newBook->publishYear = publishYear;

    newBook->bookList = bookList;
    int ID = headList->bookCount;

    newBook->ID = headList->bookCount;

    addBook(bookList, newBook->ID);

    headList->list[headList->bookCount] = newBook;
    headList->bookCount++;
}

dauSach* timSachTheoTen(DSdauSach* DSDS, string bookName) {
    for (int i = 0; i < DSDS->bookCount; i++) {
        if (DSDS->list[i]->bookName == bookName)
            return DSDS->list[i];
    }
    return nullptr;
}

void inTTSach(dauSach* book) {
    if (book != nullptr)
        printf("%-5s | %-15s | %-15s | %-10s | %d |\n", book->ISBN.c_str(), book->bookName.c_str(),
               book->bookAuth.c_str(), book->bookCategory.c_str(), book->publishYear);
    else
        printf("Sach khong ton tai!\n");
}