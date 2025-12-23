#include <iostream>
#include "coffeshop_parent.h"
#include "coffeshop_child.h"
#include "coffeshop_relation.h"

using namespace std;

int main() {
    ListMinuman LM;
    ListTopping LT;

    createListMinuman(LM);
    createListTopping(LT);

    int pilih;
    do {
        cout << "=====================================================\n";
        cout << "|              SISTEM COFFEE SHOP                   |\n";
        cout << "|===================================================|\n";
        cout << "|   1. Tambah Minuman                               |\n";
        cout << "|   2. Tambah Topping                               |\n";
        cout << "|   3. Tambah Topping ke Minuman                    |\n";
        cout << "|   4. Hapus Topping dari Minuman                   |\n";
        cout << "|   5. Tampilkan Semua Minuman                      |\n";
        cout << "|   6. Tampilkan Semua Topping                      |\n";
        cout << "|   7. Tampilkan Relasi                             |\n";
        cout << "|   8. Hitung Total Harga Minuman                   |\n";
        cout << "|   0. Keluar                                       |\n";
        cout << "|===================================================|\n";
        cout << "| Pilih menu: ";
        cin >> pilih;

        if (pilih == 1) {
            string idMinuman;
            cout << "ID Minuman   : ";
            cin >> idMinuman;

            if (findMinumanByID(LM, idMinuman) != nullptr) {
                cout << "ID Minuman sudah ada!\n";
                cout << "Data tidak ditambahkan.\n";
            } else {
                infoMinuman data;
                data.idMinuman = idMinuman;
                cout << "Nama         : ";
                cin >> data.nama;
                cout << "Harga        : ";
                cin >> data.harga;
                cout << "Kategori     : ";
                cin >> data.kategori;

                insertLastMinuman(LM, createElmMinuman(data));
                cout << "Minuman berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 2) {
            string idTopping;
            cout << "ID Topping   : ";
            cin >> idTopping;

            if (findToppingByID(LT, idTopping) != nullptr) {
                cout << "ID Topping sudah ada!\n";
                cout << "Data tidak ditambahkan.\n";
            } else {
                infoTopping data;
                data.idTopping = idTopping;
                cout << "Nama         : ";
                cin >> data.nama;
                cout << "Harga Tambah : ";
                cin >> data.hargaTambahan;

                insertLastTopping(LT, createElmTopping(data));
                cout << "Topping berhasil ditambahkan.\n";
            }
        }

        else if (pilih == 3) {
            string idM, idT;
            cout << "ID Minuman : ";
            cin >> idM;

            addressMinuman M = findMinumanByID(LM, idM);
            if (M == nullptr) {
                cout << "Minuman dengan ID '" << idM << "' tidak ditemukan.\n";
            } else {
                cout << "ID Topping : ";
                cin >> idT;

                addressTopping T = findToppingByID(LT, idT);
                if (T == nullptr) {
                    cout << "Topping dengan ID '" << idT << "' tidak ditemukan.\n";
                } else {
                    insertRelation(M, T);
                    cout << "Topping berhasil ditambahkan ke minuman.\n";
                }
            }
        }

        else if (pilih == 4) {
            string idM, idT;
            cout << "ID Minuman : ";
            cin >> idM;

            addressMinuman M = findMinumanByID(LM, idM);
            if (M == nullptr) {
                cout << "Minuman dengan ID '" << idM << "' tidak ditemukan.\n";
            } else {
                cout << "ID Topping : ";
                cin >> idT;

                addressTopping T = findToppingByID(LT, idT);
                if (T == nullptr) {
                    cout << "Topping dengan ID '" << idT << "' tidak ditemukan.\n";
                } else {
                    deleteRelation(M, T);
                    cout << "Relasi dihapus.\n";
                }
            }
        }

        else if (pilih == 5) {
            cout << "\n=== DAFTAR MINUMAN ===\n";
            printDataMinuman(LM);
        }

        else if (pilih == 6) {
            cout << "\n=== DAFTAR TOPPING ===\n";
            printDataTopping(LT);
        }

        else if (pilih == 7) {
            cout << "\n=== RELASI MINUMAN-TOPPING ===\n";
            showAllRelations(LM);
        }

        else if (pilih == 8) {
            cout << "\nTotal Harga Semua Pesanan: "
                 << calculateTotalPrice(LM) << endl;
        }

        else if (pilih == 0) {
            // Keluar program
        }

        else {
            cout << "Pilihan menu tidak valid!\n";
        }

    } while (pilih != 0);

    cout << "\nProgram selesai.\n";
    return 0;
}
