#include "dauSach.cpp"
#include "docGia.cpp"
#include <iostream>

using std::cin;
using std::cout;
DSdauSach DSDS;
DStheDocGia DSDG;

void printMenu(){
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
	printf("0 . Ket thuc chuong trinh.\n");

	printf("_____\n");
	printf("Your option: ");
}

void hieuChinhThe(){
	cout << "De them doc gia, chon 0.\n";
	cout << "De hieu chinh the doc gia, chon 1.\n";
	int opt;
	cin >> opt;
	if (opt == 0){
		string lastName, firstName;
		bool gender;
		cout << "Them doc gia: \n";
		cout << "Nhap ho: "; cin >> lastName;
		cout << "Nhap ten: "; cin >> firstName;
		cout << "Nhap gioi tinh (0: nu, 1: nam): "; cin >> gender;
		addMember(&DSDG, lastName, firstName, gender);
	}
	else{
		string lastName, firstName;
		int ID, state;
		cout << "Nhap cac thong tin moi cua the: \n";
		cout << "Nhap ID: "; cin >> ID;
		cout << "Nhap ho: "; cin >> lastName;
		cout << "Nhap ten: "; cin >> firstName;
		cout << "Nhap tinh trang the: "; cin >> state;

		HieuChinh(&DSDG, ID, state, lastName, firstName);
	}
}

void xoaThe(){
	int ID;
	cout << "Nhap ID cua the can xoa: "; cin >> ID;
	xoaThe(&DSDG, ID);
	cout << "The da duoc xoa! \n";
}

void printDSDG(){
	cout << "__DANH SACH DOC GIA__ \n";
	printMember(&DSDG);
}

void themDauSach(){
	cout << "Nhap thong tin dau sach can them \n";
	string ISBN;
	string bookName;
	string bookAuth;
	string bookCategory;
	int bookPages;
	int publishYear;

	string tmp; getline(cin, tmp);

	cout << "Nhap ma ISBN: "; getline(cin, ISBN);
	cout << "Nhap ten sach: "; getline(cin, bookName);
	cout << "Nhap tac gia: "; getline(cin, bookAuth);
	cout << "Nhap the loai: "; getline(cin, bookCategory);
	cout << "Nhap so trang: "; cin >> bookPages;
	cout << "Nhap nam xb: "; cin >> publishYear;

	addBook(&DSDS, ISBN, bookName, bookAuth, bookCategory, bookPages, publishYear);
}

void themSach(){
	string bookName;

	string tmp; getline(cin, tmp);

	cout << "Nhap ten dau sach muon them: "; getline(cin, bookName);

	dauSach* book = timSachTheoTen(&DSDS, bookName);
	if (book == nullptr){
		cout << "Sach chua ton tai! \n";
		return;
	}
	else{
		string place;
		cout << "Nhap vi tri cua sach: "; getline(cin, place);
		addBook(book -> bookList, 0, place, book -> ISBN);
	}
}

void timSach(){
	string bookName;
	string tmp; getline(cin, tmp);

	cout << "Nhap ten dau sach muon tim: "; getline(cin, bookName);

	inTTSach(timSachTheoTen(&DSDS ,bookName));
}

void printDSDS(){
	for (int i = 0; i < DSDS.bookCount; i++){
		cout << DSDS.list[i] -> bookName << "\n";
	}
}

void MuonSach(){
	int ID;
	cout << "Nhap ID cua nguoi muon: "; cin >> ID;
	nodeDocGia* borrowerNode = find(&DSDG, ID);
	if (borrowerNode == nullptr){
		cout << "Nguoi dung khong ton tai! \n";
		return;
	}

	docGia* borrower = borrowerNode -> data;
	string bookID;
	cout << "Nhap vao ma sach muon: "; cin >> bookID;
	Sach* book = timSachTheoID(&DSDS, bookID);
	if (book == nullptr){
		cout << "Ma sach khong ton tai! \n";
		return;
	}
	book -> state = 1;
	int d, m, y;
	cout << "Nhap ngay thang nam: "; cin >> d >> m >> y;
	if (!muonSach(borrower -> borrowList, book, d, m , y)){
		cout << "Khong the muon!\n";
		return;
	}
	cout << "Muon sach thanh cong!";
	return;
}

int main(int argc, char const *argv[])
{
	bool running = true;
	int option;
	while (running){
		printMenu();
		scanf("%d", &option);
		switch (option){
			case 1:
				hieuChinhThe();
				break;
			case 2:
				xoaThe();
				break;
			case 3:
				printDSDG();
				break;
			case 4:
				themDauSach();
				break;
			case 5:
				themSach();
				break;
			case 6:
				printDSDS();
				break;
			case 7:
				timSach();
				break;
			case 8:
				MuonSach();
				break;
			case 0:
				printf("Ket thuc chuong trinh\n");
				running = false;
				break;
			default:
				printf("Invalid option! \n");
				running = false;
				break;
		}
	}
	
	return 0;
}