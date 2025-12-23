#include "coffeshop_relation.h"
#include <iostream>
using namespace std;

addressRelation createElmRelation(addressTopping topping) {
    addressRelation R = new elmRelation;
    R->topping = topping;
    R->next = nullptr;
    return R;
}

void insertRelation(addressMinuman minuman, addressTopping topping) {
    addressRelation newRelation = createElmRelation(topping);
    newRelation->next = minuman->relasi;
    minuman->relasi = newRelation;
}

void deleteRelation(addressMinuman minuman, addressTopping topping) {
    if (minuman == nullptr || topping == nullptr) return;

    addressRelation current = minuman->relasi;
    addressRelation previous = nullptr;

    while (current != nullptr && current->topping != topping) {
        previous = current;
        current = current->next;
    }

    if (current != nullptr) {
        if (previous == nullptr) {
            minuman->relasi = current->next;
        } else {
            previous->next = current->next;
        }
        delete current;
    }
}

bool isRelationExist(addressMinuman minuman, addressTopping topping) {
    if (minuman == nullptr || topping == nullptr) return false;

    addressRelation current = minuman->relasi;
    while (current != nullptr) {
        if (current->topping == topping) return true;
        current = current->next;
    }
    return false;
}

void showAllRelations(ListMinuman LM) {
    addressMinuman currentMinuman = LM.first;

    if (currentMinuman == nullptr) {
        cout << "Belum ada data minuman.\n";
        return;
    }

    cout << "\n=== RELASI MINUMAN-TOPPING ===\n";

    while (currentMinuman != nullptr) {
        cout << "Minuman: " << currentMinuman->info.nama << endl;

        addressRelation currentRelation = currentMinuman->relasi;
        if (currentRelation == nullptr) {
            cout << "  - Belum ada topping\n";
        } else {
            while (currentRelation != nullptr) {
                cout << "  - " << currentRelation->topping->info.nama
                     << " (+" << currentRelation->topping->info.hargaTambahan << ")\n";
                currentRelation = currentRelation->next;
            }
        }
        cout << endl;
        currentMinuman = currentMinuman->next;
    }
}

void showToppingsByMinuman(addressMinuman minuman) {
    if (minuman == nullptr) {
        cout << "Minuman tidak ditemukan.\n";
        return;
    }

    cout << "\nTopping untuk " << minuman->info.nama << ":\n";
    addressRelation current = minuman->relasi;

    if (current == nullptr) {
        cout << "  - Belum ada topping\n";
    } else {
        while (current != nullptr) {
            cout << "  - " << current->topping->info.nama
                 << " (+" << current->topping->info.hargaTambahan << ")\n";
            current = current->next;
        }
    }
}

void showMinumansByTopping(addressTopping topping, ListMinuman LM) {
    if (topping == nullptr) {
        cout << "Topping tidak ditemukan.\n";
        return;
    }

    cout << "\nMinuman yang menggunakan " << topping->info.nama << ":\n";

    bool found = false;
    addressMinuman currentMinuman = LM.first;

    while (currentMinuman != nullptr) {
        if (isRelationExist(currentMinuman, topping)) {
            cout << "  - " << currentMinuman->info.nama << endl;
            found = true;
        }
        currentMinuman = currentMinuman->next;
    }

    if (!found) {
        cout << "  - Belum ada minuman yang menggunakan topping ini\n";
    }
}

void showAllToppingsWithMinumans(ListMinuman LM, ListTopping LT) {
    addressTopping currentTopping = LT.first;

    if (currentTopping == nullptr) {
        cout << "Belum ada data topping.\n";
        return;
    }

    cout << "\n=== TOPPING DAN MINUMAN YANG MENGGUNAKANNYA ===\n";

    while (currentTopping != nullptr) {
        cout << "\nTopping: " << currentTopping->info.nama << endl;

        bool hasMinuman = false;
        addressMinuman currentMinuman = LM.first;

        while (currentMinuman != nullptr) {
            if (isRelationExist(currentMinuman, currentTopping)) {
                cout << "  - Digunakan oleh: " << currentMinuman->info.nama << endl;
                hasMinuman = true;
            }
            currentMinuman = currentMinuman->next;
        }

        if (!hasMinuman) {
            cout << "  - Belum digunakan oleh minuman apapun\n";
        }

        currentTopping = currentTopping->next;
    }
}

int countToppingsByMinuman(addressMinuman minuman) {
    int count = 0;
    addressRelation current = minuman->relasi;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}

int countMinumansByTopping(addressTopping topping, ListMinuman LM) {
    int count = 0;
    addressMinuman currentMinuman = LM.first;

    while (currentMinuman != nullptr) {
        if (isRelationExist(currentMinuman, topping)) {
            count++;
        }
        currentMinuman = currentMinuman->next;
    }

    return count;
}

int countToppingsWithoutRelation(ListMinuman LM, ListTopping LT) {
    int count = 0;
    addressTopping currentTopping = LT.first;

    while (currentTopping != nullptr) {
        if (countMinumansByTopping(currentTopping, LM) == 0) {
            count++;
        }
        currentTopping = currentTopping->next;
    }

    return count;
}

void editRelation(addressMinuman minuman, addressTopping oldTopping, addressTopping newTopping) {
    if (minuman == nullptr || oldTopping == nullptr || newTopping == nullptr) {
        cout << "Data tidak valid.\n";
        return;
    }

    if (!isRelationExist(minuman, oldTopping)) {
        cout << "Topping " << oldTopping->info.nama
             << " tidak ditemukan pada minuman " << minuman->info.nama << endl;
        return;
    }

    deleteRelation(minuman, oldTopping);
    insertRelation(minuman, newTopping);

    cout << "Topping " << oldTopping->info.nama
         << " diganti dengan " << newTopping->info.nama
         << " pada minuman " << minuman->info.nama << endl;
}

int calculateTotalPrice(ListMinuman LM) {
    int total = 0;
    addressMinuman currentMinuman = LM.first;

    while (currentMinuman != nullptr) {
        total += currentMinuman->info.harga;

        addressRelation currentRelation = currentMinuman->relasi;
        while (currentRelation != nullptr) {
            total += currentRelation->topping->info.hargaTambahan;
            currentRelation = currentRelation->next;
        }

        currentMinuman = currentMinuman->next;
    }
    return total;
}
