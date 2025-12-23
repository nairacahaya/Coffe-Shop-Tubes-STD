#include "coffeshop_child.h"
#include <iostream>
using namespace std;

void createListTopping(ListTopping &LT) {
    LT.first = nullptr;
}

addressTopping createElmTopping(infoTopping data) {
    addressTopping T = new elmTopping;
    T->info = data;
    T->next = nullptr;
    return T;
}

bool isEmptyTopping(ListTopping LT) {
    return LT.first == nullptr;
}

void insertFirstTopping(ListTopping &LT, addressTopping T) {
    T->next = LT.first;
    LT.first = T;
}

void insertLastTopping(ListTopping &LT, addressTopping T) {
    if (isEmptyTopping(LT)) {
        LT.first = T;
    } else {
        addressTopping P = LT.first;
        while (P->next != nullptr)
            P = P->next;
        P->next = T;
    }
}

void insertAfterTopping(ListTopping &LT, addressTopping prec, addressTopping T) {
    T->next = prec->next;
    prec->next = T;
}

addressTopping findToppingByID(ListTopping LT, string idTopping) {
    addressTopping P = LT.first;
    while (P != nullptr) {
        if (P->info.idTopping == idTopping)
            return P;
        P = P->next;
    }
    return nullptr;
}

void deleteFirstTopping(ListTopping &LT, addressTopping &T) {
    T = LT.first;
    LT.first = T->next;
    T->next = nullptr;
}

void deleteLastTopping(ListTopping &LT, addressTopping &T) {
    addressTopping P = LT.first;
    if (P->next == nullptr) {
        T = P;
        LT.first = nullptr;
    } else {
        while (P->next->next != nullptr)
            P = P->next;
        T = P->next;
        P->next = nullptr;
    }
}

void deleteAfterTopping(ListTopping &LT, addressTopping prec, addressTopping &T) {
    T = prec->next;
    prec->next = T->next;
    T->next = nullptr;
}

void printDataTopping(ListTopping LT) {
    addressTopping P = LT.first;
    while (P != nullptr) {
        cout << P->info.idTopping << " | "
             << P->info.nama << " | "
             << P->info.hargaTambahan << endl;
        P = P->next;
    }
}

void deleteTopping(ListTopping &LT, string id) {
    addressTopping P = LT.first, prev = nullptr;

    while (P != nullptr && P->info.idTopping != id) {
        prev = P;
        P = P->next;
    }

    if (P == nullptr) {
        cout << "Topping tidak ditemukan.\n";
        return;
    }

    if (prev == nullptr)
        LT.first = P->next;
    else
        prev->next = P->next;

    delete P;
    cout << "Topping berhasil dihapus.\n";
}
