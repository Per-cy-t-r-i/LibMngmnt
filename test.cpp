#include "dauSach.cpp"
#include "docGia.cpp"


int main(int argc, char const *argv[])
{


	DSdauSach* dauSachs = new DSdauSach();
	danhMucSach* trinhTham = new danhMucSach();


	addBook(dauSachs, "111", "Holmes", "Conan", "trinh tham", 600, 1950, trinhTham);
	addBook(dauSachs, "121", "Holmes 2", "Conan", "trinh tham", 500, 1950, trinhTham);

	addBook(dauSachs, "311", "Holmes 3", "Conan", "trinh tham", 1000, 1950, trinhTham);

	printf("Cac sach da them:\n");
	for (int i = 0; i < dauSachs -> bookCount; i++){
		printf("%s - %s - %s - %s - %d trang - %d\n",
			dauSachs -> list[i] -> ISBN.c_str(),
			dauSachs -> list[i] -> bookName.c_str(),
			dauSachs -> list[i] -> bookAuth.c_str(),
			dauSachs -> list[i] -> bookCategory.c_str(),
			dauSachs -> list[i] -> bookPages,
			dauSachs -> list[i] -> publishYear
		 );
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