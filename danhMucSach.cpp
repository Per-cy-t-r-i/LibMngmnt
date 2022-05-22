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

// Thêm ID sách vào danh mục
void addBook(danhMucSach* bookList, int ID) {
    // Tạo ra 1 quyển sách mới
    Sach* newBookTemplate = new Sach();
    newBookTemplate->bookID = ID;
    newBookTemplate->state = 0;
    newBookTemplate->place = "None";

    // Tạo node chứa thông tin quyển sách này
    nodeSach* newNode = new nodeSach();
    newNode->data = newBookTemplate;

    // Thêm quyển sách này vào DMS
    if (bookList->head == nullptr) {
        bookList->head = newNode;
        bookList->back = newNode;
    } else {
        bookList->back->next = newNode;
        bookList->back = newNode;
    }
}
