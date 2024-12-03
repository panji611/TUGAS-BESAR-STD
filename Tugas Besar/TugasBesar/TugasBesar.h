#ifndef TUGASBESAR_H_INCLUDED
#define TUGASBESAR_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

// Struct untuk List Parent (Alat Transportasi)
struct Parent {
    string transportName;
    Parent* next;
};

// Struct untuk List Child (Daerah)
struct Child {
    string regionName;
    Child* next;
};

// Struct untuk List Relasi
struct Relation {
    Parent* transport;
    Child* region;
    Relation* next;
};

// List Parent
struct ListParent {
    Parent* first;
};

// List Child
struct ListChild {
    Child* first;
};

// List Relasi
struct ListRelation {
    Relation* first;
};

//punya saya
void createListParent(ListParent &L);
void createListChild(ListChild &L);
void createListRelation(ListRelation &L);
void deleteChildFirst(ListChild &L);
void deleteChildByName(ListChild &L, string regionName);
void displayParentList(const ListParent &L);
void createRelation(Parent* P, Child* C);
void insertRelationFirst(ListRelation &L, Relation* R);


Parent* createParent(string transportName);
void insertParentFirst(ListParent &L, Parent* P);
void insertParentLast(ListParent &L, Parent* P);
void deleteParentFirst(ListParent &L);
void deleteParentByName(ListParent &L, string transportName);

void insertChildLast(ListChild &L, Child* C);
Child* createChild(string regionName);
void insertChildFirst(ListChild &L, Child* C);

void displayRelations(const ListRelation &L);
void deleteRelationByParent(ListRelation &L, Parent* P);
void deleteRelationByChild(ListRelation &L, Child* C);

void displayChildList(const ListChild &L);

#endif // TUGASBESAR_H_INCLUDED
