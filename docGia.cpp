#include <stdio.h>

#include "muonTra.cpp"
using namespace std;

// Stuct chứa thông tin của 1 độc giả
struct docGia {
    // Họ
    string lastName;
    // Tên
    string firstName;
    // Giới tính -> 0: nữ || 1: nam
    bool gender;
    // Trạng thái thẻ độc giả -> 0: bị khoá || 1: được mượn
    int cardState;

    // DS các quyển sách đã mượn, trả
    DSmuonTra* borrowList;
};

// Node cho cây tìm kiếm nhị phân
struct nodeDocGia {
    // Thông tin của 1 độc giả
    docGia* data;
    // ID của độc giả
    int ID;

    // Node con bên trái
    nodeDocGia* left = nullptr;
    // Node con bên phải
    nodeDocGia* right = nullptr;
    // Node cha
    nodeDocGia* parent = nullptr;
};

// Cây tìm kiếm nhị phân tự cân bằng (AVL Tree)
struct DStheDocGia {
    // Node gốc
    nodeDocGia* root = nullptr;
    // Số lượng các node -> Số lượng độc giả
    int size = 0;
};

// Tìm kiếm một thẻ độc giả trong danh sách theo ID
nodeDocGia* find(DStheDocGia* MemberTree, int ID) {
    // Lấy ra node gốc
    nodeDocGia* ptr = MemberTree->root;

    // Duyệt cây đến khi hết cây (duyệt đến node lá)
    // Hoặc khi tìm thấy ID cần tìm
    while (ptr != nullptr && ptr->ID != ID) {
        // So sánh ID cần tìm với ID của nút hiện tại
        // Nếu ID cần tìm nhỏ hơn -> Tìm ở cây con bên trái
        if (ptr->ID > ID)
            // Duyệt sang trái
            ptr = ptr->left;
        // Ngược lại thì duyệt sang bên phải
        else
            ptr = ptr->right;
    }

    return ptr;
}

// Chỉnh sửa: thêm/ xoá/ điều chỉnh thông tin một thẻ độc giả trong danh sách

// Thêm một thẻ vào danh sách
void addMember(DStheDocGia* MemberTree, string lastName, string firstName, bool gender) {
    // Cấp phát bộ nhớ động cho 1 node độc giả
    nodeDocGia* newNode = new nodeDocGia();

    // Cấp phát động thông tin của độc giả
    newNode->data = new docGia();

    // Nhập thông tin cho độc giả này
    newNode->data->lastName = lastName;
    newNode->data->firstName = firstName;
    newNode->data->gender = gender;
    newNode->data->cardState = 1;
    newNode -> data -> borrowList = new DSmuonTra();

    // Nhập thông tin cho node độc giả
    newNode->ID = MemberTree->size + 1;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->parent = nullptr;

    int ID = newNode->ID;

    // Nếu cây rỗng thì thêm vào gốc
    if (MemberTree->size == 0) {
        MemberTree->root = newNode;
    }

    // Tìm kiếm vị trí để thêm node mới
    else {
        nodeDocGia* ptr = MemberTree->root;
        bool foundPlace = false;

        // Khi chưa tìm thấy
        while (!foundPlace) {
            if (ptr->ID > ID) {
                if (ptr->left == nullptr)
                    foundPlace = true;
                else
                    ptr = ptr->left;
            } else {
                if (ptr->right == nullptr)
                    foundPlace = true;
                else
                    ptr = ptr->right;
            }
        }

        if (ptr->ID > ID)
            ptr->left = newNode;
        else
            ptr->right = newNode;
        newNode->parent = ptr;
    }
    MemberTree->size++;
}

// Điều chỉnh thông tin thẻ
void HieuChinh(DStheDocGia* MemberTree, int ID, int cardState, string lastName, string firstName) {
    nodeDocGia* mem = find(MemberTree, ID);
    if (mem != nullptr) {
        mem->data->cardState = cardState;
        mem->data->firstName = firstName;
        mem->data->lastName = lastName;
    }
}

// Xoa ma the theo ID
nodeDocGia* successor(DStheDocGia* MemberTree, int ID) {
    nodeDocGia* node = MemberTree->root;

    // Keep track of the lastest left turn when searching for k
    nodeDocGia* last_left = nullptr;

    int turned_left = 0;

    while (node != nullptr && node->ID != ID) {
        if (node->ID > ID) {
            last_left = node;
            turned_left = 1;
            node = node->left;
        } else
            node = node->right;
    }

    if (node == nullptr)
        return nullptr;

    if (node->right != nullptr) {
        nodeDocGia* ptr = node->right;
        while (ptr->left != nullptr)
            ptr = ptr->left;

        return ptr;
    }

    if (turned_left)
        return last_left;

    return nullptr;
}

// Xóa thẻ khỏi cây
void xoaThe(DStheDocGia* MemberTree, int ID) {
    nodeDocGia* discard = find(MemberTree, ID);
    // Neu ID co trong cay, ta xoa node co chua ID
    if (discard != nullptr) {
        nodeDocGia* rNode = discard->right;
        nodeDocGia* lNode = discard->left;
        // Neu node can xoa khong co con
        if (rNode == nullptr && lNode == nullptr) {
            if (discard == MemberTree->root) {
                MemberTree->root = nullptr;
                delete discard;
            } else {
                nodeDocGia* par = discard->parent;
                if (discard->ID > par->ID)
                    par->right = nullptr;
                else
                    par->left = nullptr;
                delete discard;
            }
        }
        // Neu node can xoa co 1 con
        else if (rNode == nullptr || lNode == nullptr) {
            // Tim node thay the
            nodeDocGia* replacement = nullptr;
            if (rNode != nullptr)
                replacement = rNode;
            else
                replacement = lNode;
            // Neu node can xoa la goc thi thay goc
            if (discard == MemberTree->root) {
                replacement->parent = nullptr;
                MemberTree->root = replacement;
            }
            // Neu khong, cap nhat lai ca node cha cua node can xoa
            else {
                nodeDocGia* par = nullptr;
                par = discard->parent;

                replacement->parent = par;

                if (discard->ID > par->ID)
                    par->right = replacement;
                else
                    par->left = replacement;

                delete discard;
            }
        }
        // Neu node can xoa co 2 con
        else {
            nodeDocGia* replacement = successor(MemberTree, discard->ID);
            int ID = replacement->ID;
            discard->data = replacement->data;
            xoaThe(MemberTree, ID);
            discard->ID = ID;
        }
    }
}

// In các độc giả theo thứ tự của mã thẻ -> Duyệt cây
void printMember(DStheDocGia* Tree, nodeDocGia* node) {
    if (node == nullptr) return;
    printMember(Tree, node->left);
    printf("%10s %-6s -%5s || %d\n", node->data->lastName.c_str(), node->data->firstName.c_str(),
           node->data->gender ? "Nam" : "Nu", node->ID);
    printMember(Tree, node->right);
}

void printMember(DStheDocGia* Tree) {
    printMember(Tree, Tree->root);
}
