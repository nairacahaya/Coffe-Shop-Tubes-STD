#include "coffeshop_parent.h"
#include <iostream>
using namespace std;

void createListMinuman(ListMinuman &LM) {
    LM.first = nullptr;
    LM.last = nullptr;
}

addressMinuman createElmMinuman(infoMinuman data) {
    addressMinuman M = new elmListMinuman;
    M->info = data;
    M->next = nullptr;
    M->prev = nullptr;
    M->relasi = nullptr;
    return M;
}

bool isEmptyMinuman(ListMinuman LM) {
    return LM.first == nullptr;
}

void insertFirstMinuman(ListMinuman &LM, addressMinuman M) {
    if (findMinumanByID(LM, M->info.idMinuman) != nullptr) {
        cout << "ID Minuman sudah ada! Data tidak ditambahkan.\n";
        delete M;
        return;
    }

    if (isEmptyMinuman(LM)) {
        LM.first = LM.last = M;
    } else {
        M->next = LM.first;
        LM.first->prev = M;
        LM.first = M;
    }
}

void insertLastMinuman(ListMinuman &LM, addressMinuman M) {
     if (findMinumanByID(LM, M->info.idMinuman) != nullptr) {
        cout << "ID Minuman sudah ada! Data tidak ditambahkan.\n";
        delete M;
        return;
    }

    if (isEmptyMinuman(LM)) {
        LM.first = LM.last = M;
    } else {
        LM.last->next = M;
        M->prev = LM.last;
        LM.last = M;
    }
}

void insertAfterMinuman(ListMinuman &LM, addressMinuman prec, addressMinuman M) {
    if (findMinumanByID(LM, M->info.idMinuman) != nullptr) {
        cout << "ID Minuman sudah ada! Data tidak ditambahkan.\n";
        delete M;
        return;
    }

    M->next = prec->next;
    M->prev = prec;

    if (prec->next != nullptr)
        prec->next->prev = M;
    else
        LM.last = M;

    prec->next = M;
}

addressMinuman findMinumanByID(ListMinuman LM, string id) {
    addressMinuman P = LM.first;
    while (P != nullptr) {
        if (P->info.idMinuman == id)
            return P;
        P = P->next;
    }
    return nullptr;
}

void printDataMinuman(ListMinuman LM) {
    addressMinuman P = LM.first;
    while (P != nullptr) {
        cout << P->info.idMinuman << " | "
             << P->info.nama << " | "
             << P->info.harga << " | "
             << P->info.kategori << endl;
        P = P->next;
    }
}

void deleteMinuman(ListMinuman &LM, string id) {
    addressMinuman P = findMinumanByID(LM, id);

    if (P == nullptr) {
        cout << "Minuman tidak ditemukan.\n";
        return;
    }

    if (P->prev != nullptr) {
        P->prev->next = P->next;
    } else {
        LM.first = P->next;
    }

    if (P->next != nullptr) {
        P->next->prev = P->prev;
    } else {
        LM.last = P->prev;
    }

    delete P;
    cout << "Minuman berhasil dihapus.\n";
}
