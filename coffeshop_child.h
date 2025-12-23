#ifndef COFFEESHOP_CHILD_H
#define COFFEESHOP_CHILD_H

#include <iostream>
using namespace std;

struct infoTopping {
    string idTopping;
    string nama;
    int hargaTambahan;
};

struct elmTopping {
    infoTopping info;
    elmTopping* next;
};

struct ListTopping {
    elmTopping* first;
};

typedef elmTopping* addressTopping;

void createListTopping(ListTopping &LT);
addressTopping createElmTopping(infoTopping data);
bool isEmptyTopping(ListTopping LT);

void insertFirstTopping(ListTopping &LT, addressTopping T);
void insertLastTopping(ListTopping &LT, addressTopping T);
void insertAfterTopping(ListTopping &LT, addressTopping prec, addressTopping T);

void deleteTopping(ListTopping &LT, string id);
void deleteFirstTopping(ListTopping &LT, addressTopping &T);
void deleteLastTopping(ListTopping &LT, addressTopping &T);
void deleteAfterTopping(ListTopping &LT, addressTopping prec, addressTopping &T);

void printDataTopping(ListTopping LT);
addressTopping findToppingByID(ListTopping LT, string idTopping);

#endif
