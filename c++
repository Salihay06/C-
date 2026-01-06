#include <iostream>

using namespace std;

// 1. KUTUCUK SINIFI (NODE)
class Node {
private:
    int data;       // İçindeki veri (sayı)
    Node *next;     // Bir sonraki kutunun adresi

    // Kurucu Fonksiyon (Constructor)
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }

    friend class LinkedList; // LinkedList sınıfı bu özel verilere erişebilsin
};

// 2. LİSTE YÖNETİCİSİ SINIFI (LINKEDLIST)
class LinkedList {
private:
    Node *head; // Listenin başını tutan işaretçi (Çok önemli!)

public:
    // Başlangıçta liste boştur
    LinkedList() {
        this->head = nullptr;
    }

    // BAŞA EKLEME FONKSİYONU
    void insertAtBeginning(int data) {
        Node *newNode = new Node(data); // Yeni kutuyu yarat
        newNode->next = head;           // Yeni kutu, eski başkanı göstersin
        head = newNode;                 // Artık yeni başkan bu kutu
    }

    // SONA EKLEME FONKSİYONU
    void insertAtEnd(int data) {
        Node *newNode = new Node(data); // Yeni kutuyu yarat

        // Eğer liste boşsa, bu kutu direkt baş olur
        if (head == nullptr) {
            head = newNode;
            return;
        }

        // Değilse, en sona kadar yürümemiz lazım
        Node *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        // En sona geldik, şimdi ekleyelim
        temp->next = newNode;
    }

    // BAŞTAN SİLME FONKSİYONU
    void deleteAtBeginning() {
        if (head == nullptr) { // Liste boşsa işlem yapma
            return;
        }
        Node *temp = head;      // Silinecek olanı (başkanı) bir yere not et
        head = head->next;      // Başkanlığı bir sonrakine devret
        delete temp;            // Eski başkanı hafızadan sil
    }

    // SONDAN SİLME FONKSİYONU
    void deleteAtEnd() {
        if (head == nullptr) { // Liste boşsa işlem yapma
            return;
        }
        // Listede tek eleman varsa, onu sil ve listeyi boşalt
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        // Sondan bir öncekini bulmamız lazım
        Node *temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }
        
        // temp şu an sondan bir önceki eleman
        delete temp->next;      // Sonuncuyu sil
        temp->next = nullptr;   // Artık sonuncu benim de
    }

    // LİSTEYİ YAZDIRMA
    void printList() {
        Node *temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    // Listeyi oluştur
    LinkedList list;

    // Başa eklemeler yapalım: 3, sonra 2, sonra 1 eklenir. Liste: 1 -> 2 -> 3 olur.
    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    // Sona eklemeler yapalım: 4, 5, 6. Liste: 1 -> 2 -> 3 -> 4 -> 5 -> 6 olur.
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.insertAtEnd(6);

    cout << "Orijinal liste: ";
    list.printList();

    // Baştan sil (1 gider)
    list.deleteAtBeginning();
    cout << "Baştan silince: ";
    list.printList();

    // Sondan sil (6 gider)
    list.deleteAtEnd();
    cout << "Sondan silince: ";
    list.printList();

    return 0;
}
