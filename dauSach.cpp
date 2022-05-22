#include <stdio.h>

#include <string>

#include "danhMucSach.cpp"
using namespace std;

struct dauSach {
    // Thông tin của đầu sách gồm ISBN, tên, tác giả, thể loại, số trang, năm phát hành
    string ISBN;
    string bookName;
    string bookAuth;
    string bookCategory;

    int bookPages;
    int publishYear;

    int ID;

    // Một đầu sách có nhiều quyển sách
    danhMucSach* bookList;
};

// Một thư viện có nhiều đầu sách
struct DSdauSach {
    // Khởi tạo thư viện với 0 quyển sách
    int bookCount = 0;
    // Và 1 danh sách đầu sách với sức chứa 100000 đầu sách
    dauSach* list[100000];
};

// Nhập thông tin đầu sách
void addBook(DSdauSach* headList,
             string ISBN,
             string bookName,
             string bookAuth,
             string bookCategory,
             int bookPages,
             int publishYear,
             danhMucSach* bookList) {
    //  Cấp phát bộ nhớ động cho 1 đầu sách
    dauSach* newBook = new dauSach();

    // Nhập từng thông tin cho đầu sách này
    newBook->ISBN = ISBN;
    newBook->bookName = bookName;
    newBook->bookAuth = bookAuth;
    newBook->bookCategory = bookCategory;
    newBook->bookPages = bookPages;
    newBook->publishYear = publishYear;

    newBook->bookList = bookList;
    int ID = headList->bookCount;

    newBook->ID = headList->bookCount;

    // Nhập xong thì thêm sách vào danh sách đầu sách
    addBook(bookList, newBook->ID);

    headList->list[headList->bookCount] = newBook;
    // Tăng số lượng sách lên 1
    headList->bookCount++;
}

// Duyệt qua danh danh sách đầu sách để tìm quyển sách có tên cần tìm
dauSach* timSachTheoTen(DSdauSach* DSDS, string bookName) {
    for (int i = 0; i < DSDS->bookCount; i++) {
        // Nếu tìm thấy thì trả về con trỏ trỏ đến quyển sách đó
        if (DSDS->list[i]->bookName == bookName)
            return DSDS->list[i];
    }
    // Duyệt hết mà ko tìm thấy thì trả về con trỏ null
    return nullptr;
}

// In thông tin của 1 đầu sách
void inTTSach(dauSach* book) {
    if (book != nullptr)
        printf("%-5s | %-15s | %-15s | %-10s | %d |\n", book->ISBN.c_str(), book->bookName.c_str(),
               book->bookAuth.c_str(), book->bookCategory.c_str(), book->publishYear);
    else
        printf("Sach khong ton tai!\n");
}