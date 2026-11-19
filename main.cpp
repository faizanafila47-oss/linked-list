#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = NULL; }

    void sisipAwal(int x) {
        Node* baru = new Node();
        baru->data = x;
        baru->next = head;
        head = baru;
        cout << "Sisip Awal: " << x << endl;
    }
    void sisipAkhir(int x) {
        Node* baru = new Node();
        baru->data = x; baru->next = NULL;
        if (head == NULL) { head = baru; return; }
        Node* cur = head;
        while (cur->next != NULL) cur = cur->next;
        cur->next = baru;
        cout << "Sisip Akhir: " << x << endl;
    }
    void hapus(int x) {
        if (head == NULL) { cout << "List kosong\n"; return; }
        if (head->data == x) { Node* tmp = head; head = head->next; delete tmp; cout << "Terhapus: " << x << endl; return; }
        Node* cur = head;
        while (cur->next != NULL && cur->next->data != x) cur = cur->next;
        if (cur->next == NULL) { cout << "Tidak ketemu: " << x << endl; return; }
        Node* tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        cout << "Terhapus: " << x << endl;
    }
    void traversal() {
        cout << "List: ";
        Node* cur = head;
        if (cur == NULL) cout << "(kosong)";
        while (cur != NULL) { cout << cur->data << " -> "; cur = cur->next; }
        cout << "NULL" << endl;
        cout << "\nAnalisis Kompleksitas:\n";
        cout << "Sisip Awal: O(1)\nSisip Akhir: O(n)\nHapus: O(n)\nTraversal: O(n)\n";
    }
};

int main() {
    LinkedList list;
    int pilih, nilai;
    do {
        cout << "\n--- LINKED LIST ---\n";
        cout << "1. Sisip Awal\n2. Sisip Akhir\n3. Hapus\n4. Traversal\n5. Keluar\nPilih: ";
        cin >> pilih;
        if (pilih == 1) { cout << "Nilai: "; cin >> nilai; list.sisipAwal(nilai); }
        else if (pilih == 2) { cout << "Nilai: "; cin >> nilai; list.sisipAkhir(nilai); }
        else if (pilih == 3) { cout << "Nilai yg dihapus: "; cin >> nilai; list.hapus(nilai); }
        else if (pilih == 4) list.traversal();
    } while (pilih != 5);
    return 0;
}
