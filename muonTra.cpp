#include "Sach.cpp"

struct date {
    int day;
    int month;
    int year;
};

struct sachMuon {
    std::string bookID;

    date borrowDate;
    date returnDate;

    int state;
    // 0: chua tra  || 1: da tra || 2: lam mat
};

struct nodeSachMuon {
    sachMuon data;
    nodeSachMuon* prev;
    nodeSachMuon* next;
};

struct DSmuonTra {
    nodeSachMuon* head;

    int bookCount;
};