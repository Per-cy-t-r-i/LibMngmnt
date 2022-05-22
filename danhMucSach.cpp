#include "Sach.cpp"

// Mỗi node trong DSLK chứa thông tin của 1 quyển sách và con trỏ đến quyển sách tiếp theo
struct nodeSach {
    // Thông tin của 1 quyển sách
    Sach* data;
    // Con trỏ đến quyển sách tiếp theo
    nodeSach* next = nullptr;
};

// Danh mục sách là 1 DSLK đơn
struct danhMucSach {
    nodeSach* head = nullptr;
    nodeSach* back = nullptr;

    int bookCount = 0;
};

// Thêm ID sách vào danh mục
void addBook(danhMucSach* bookList, int ID) {
    Sach* newBookTemplate = new Sach();
    newBookTemplate->bookID = ID;
    newBookTemplate->state = 0;
    newBookTemplate->place = "None";

    nodeSach* newNode = new nodeSach();
    newNode->data = newBookTemplate;

    if (bookList->head == nullptr) {
        bookList->head = newNode;
        bookList->back = newNode;
    } else {
        bookList->back->next = newNode;
        bookList->back = newNode;
    }
}
