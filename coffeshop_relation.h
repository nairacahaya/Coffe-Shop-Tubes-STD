#ifndef COFFEESHOP_RELATION_H
#define COFFEESHOP_RELATION_H

#include "coffeshop_parent.h"
#include "coffeshop_child.h"

struct elmRelation {
    addressTopping topping;
    elmRelation* next;
};

typedef elmRelation* addressRelation;

addressRelation createElmRelation(addressTopping topping);
void insertRelation(addressMinuman minuman, addressTopping topping);
void deleteRelation(addressMinuman minuman, addressTopping topping);
bool isRelationExist(addressMinuman minuman, addressTopping topping);

void showAllRelations(ListMinuman LM);
void showToppingsByMinuman(addressMinuman minuman);
void showMinumansByTopping(addressTopping topping, ListMinuman LM);
void showAllToppingsWithMinumans(ListMinuman LM, ListTopping LT);

int countToppingsByMinuman(addressMinuman minuman);
int countMinumansByTopping(addressTopping topping, ListMinuman LM);
int countToppingsWithoutRelation(ListMinuman LM, ListTopping LT);

void editRelation(addressMinuman minuman, addressTopping oldTopping, addressTopping newTopping);
int calculateTotalPrice(ListMinuman LM);

#endif
