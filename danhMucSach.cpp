#include "Sach.cpp"

struct nodeSach
{
    Sach* data;
    
    nodeSach* next = nullptr;
};

struct danhMucSach
{
    nodeSach* head = nullptr;
    nodeSach* back = nullptr;

    int bookCount = 0;
};

// Thêm ID sách vào danh mục
void addBook(danhMucSach* bookList, int ID){
	Sach* newBookTemplate = new Sach();
	newBookTemplate -> bookID = ID;
	newBookTemplate -> state = 0;
	newBookTemplate -> place = "None";

	nodeSach* newNode = new nodeSach();
	newNode -> data = newBookTemplate;

	if (bookList -> head == nullptr){
		bookList -> head = newNode;
		bookList -> back = newNode;
	}
	else{
		bookList -> back -> next = newNode;
		bookList -> back = newNode;
	}
}


