#ifndef COFFESHOP_PARENT_H_INCLUDED
#define COFFESHOP_PARENT_H_INCLUDED

#include <string>
using namespace std;

struct Minuman {
    string idMinuman;
    string nama;
    int harga;
    string kategori;
};
typedef Minuman infoMinuman;

struct elmRelation;
typedef elmRelation* addressRelation;

struct elmListMinuman {
    infoMinuman info;
    elmListMinuman *next;
    elmListMinuman *prev;
    addressRelation relasi;
};
typedef elmListMinuman* addressMinuman;

struct ListMinuman {
    addressMinuman first;
    addressMinuman last;
};

void createListMinuman(ListMinuman &LM);
addressMinuman createElmMinuman(infoMinuman data);
bool isEmptyMinuman(ListMinuman LM);

void insertFirstMinuman(ListMinuman &LM, addressMinuman M);
void insertLastMinuman(ListMinuman &LM, addressMinuman M);
void insertAfterMinuman(ListMinuman &LM, addressMinuman prec, addressMinuman M);

addressMinuman findMinumanByID(ListMinuman LM, string id);
void printDataMinuman(ListMinuman LM);
void deleteMinuman(ListMinuman &LM, string id);

#endif
