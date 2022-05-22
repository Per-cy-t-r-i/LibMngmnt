#include "Sach.cpp"
using namespace std;

struct date {
    int day;
    int month;
    int year;
};

struct sachMuon {
    Sach* book;

    date borrowDate;
    date returnDate;

    int state;
    // 0: chua tra  || 1: da tra || 2: lam mat
};

struct nodeSachMuon {
    sachMuon* data;
    nodeSachMuon* prev = nullptr;
    nodeSachMuon* next = nullptr;
};

struct DSmuonTra {
    nodeSachMuon* head = nullptr;

    int bookCount = 0;
};

int diffDay(date d1, date d2){
    return (d1.day - d2.day) + (d1.month - d2.month)*30 + (d1.year - d2.year)* 365;
}

bool muonSach(DSmuonTra* borrowList, Sach* book, int d, int m, int y){
    if (borrowList -> bookCount == 3)
        return false;

    date today = {d, m, y};
    nodeSachMuon* newNode = new nodeSachMuon();
    sachMuon* newData = new sachMuon();
    newData -> book = book;
    newData -> borrowDate = today;

    newData -> returnDate.day = d + 7;
    newData -> returnDate.month = m;
    newData -> returnDate.year = y;

    newNode -> data = newData;

    if (borrowList -> bookCount == 0){
        borrowList ->  head = newNode;
    }
    else{
        nodeSachMuon* ptr = borrowList -> head;
        while (ptr -> next != nullptr){
            if (diffDay(ptr -> data -> returnDate, today) > 7)
                return false;
            ptr = ptr -> next;
        }
        ptr -> next = newNode;
        newNode -> prev = ptr;
    }
    return true;
}