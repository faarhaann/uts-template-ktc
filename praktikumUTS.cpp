#include <iostream>
#include <string>

using namespace std;

struct Contact {
    string name;
    string phoneNumber;
    Contact* next;
};

class PhoneBook {
private:
    Contact* head;

public:
    PhoneBook() {
        head = nullptr;
    }

    void addContact(string name, string phoneNumber) {
        Contact* newContact = new Contact;
        newContact->name = name;
        newContact->phoneNumber = phoneNumber;
        newContact->next = nullptr;

        if (head == nullptr) {
            head = newContact;
        } else {
            Contact* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newContact;
        }
        cout << "Kontak berhasil ditambahkan." << endl;
    }

    void searchContact(string name) {
        Contact* temp = head;
        bool found = false;

        while (temp != nullptr) {
            if (temp->name == name) {
                found = true;
                cout << "Nama: " << temp->name << ", Nomor Telepon: " << temp->phoneNumber << endl;
            }
            temp = temp->next;
        }

        if (!found) {
            cout << "Kontak dengan nama tersebut tidak ditemukan." << endl;
        }
    }

    void displayContacts() {
        if (head == nullptr) {
            cout << "Buku telepon kosong." << endl;
            return;
        }

        Contact* temp = head;
        cout << "Daftar Kontak:" << endl;
        while (temp != nullptr) {
            cout << "Nama: " << temp->name << ", Nomor Telepon: " << temp->phoneNumber << endl;
            temp = temp->next;
        }
    }
};

PhoneBook() {
        Contact* temp = head;
        while (temp != nullptr) {
            Contact* next = temp->next;
            delete temp;
            temp = next;
        }
        head = nullptr;
    }
    
int main() {
    PhoneBook phoneBook;
    int choice;
    string name, phoneNumber;

    do {
        cout << "Menu:" << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Cari Kontak" << endl;
        cout << "3. Tampilkan Semua Kontak" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan nama: ";
                cin >> name;
                cout << "Masukkan nomor telepon: ";
                cin >> phoneNumber;
                phoneBook.addContact(name, phoneNumber);
                break;
            case 2:
                cout << "Masukkan nama yang ingin dicari: ";
                cin >> name;
                phoneBook.searchContact(name);
                break;
            case 3:
                phoneBook.displayContacts();
                break;
            case 4:
                cout << "Program berakhir." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
