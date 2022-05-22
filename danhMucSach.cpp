#include "Sach.cpp"
using namespace std;

// Mỗi node trong DSLK chứa thông tin của 1 quyển sách và con trỏ đến quyển sách tiếp theo
struct nodeSach {
    // Thông tin của 1 quyển sách
    Sach* data;
    // Con trỏ đến quyển sách tiếp theo
    nodeSach* next = nullptr;
};

// Danh mục sách là 1 DSLK đơn
struct danhMucSach {
    // DSLK đơn có 1 con trỏ trỏ vào đầu DS
    nodeSach* head = nullptr;
    // Và 1 con trỏ trỏ vào cuối DS
    nodeSach* back = nullptr;
    // Số lượng quyển sách trong DSLK -> Số node trong DSLK
    int bookCount = 0;
};

// Thêm một quyển sách vào danh mục sách
void addBook(danhMucSach* bookList, int state, string place, string ISBN) {
    // Tạo ra 1 quyển sách mới
    Sach* newBook = new Sach();

    newBook -> state = state;
    newBook -> place = place;
    

    nodeSach* newNode = new nodeSach();
    newNode -> data = newBook;

    if (bookList -> bookCount == 0){
        bookList -> head = newNode;
        bookList -> back = newNode;
    }
    else{
        bookList -> back -> next = newNode;
        bookList -> back = newNode;
    }
    newBook -> bookID = ISBN + to_string(bookList -> bookCount);
    bookList -> bookCount ++;
}

// Tìm sách theo ID
Sach* find(danhMucSach* dms, string ID){
    if (dms -> bookCount == 0)
        return nullptr;

    nodeSach* ptr = dms -> head;
    while (ptr != nullptr && ptr -> data -> bookID != ID)
        ptr = ptr -> next;
    return ptr -> data;
}

// In các mã và vị trí sách trong danh mục
void printBooks(danhMucSach* bookList){
    if (bookList -> bookCount == 0){
        printf("Chua co sach nay trong thu vien.\n");
        return;
    }

    nodeSach* ptr = bookList -> head;
    while (ptr){
        printf("%s: %s: %d\n", ptr -> data -> bookID.c_str(), ptr -> data -> place.c_str(), ptr -> data -> state);
        ptr = ptr -> next;
    }
}
