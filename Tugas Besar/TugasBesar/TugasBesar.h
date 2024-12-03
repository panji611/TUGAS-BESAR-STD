#ifndef TUGASBESAR_H_INCLUDED
#define TUGASBESAR_H_INCLUDED
#include <iostream>
#include <string>
using namespace std;

typedef struct elmListDaerah *adr_daerah;
typedef struct elmListAlatPenumpang *adr_alatPenumpang;
typedef struct elmListRelasi *adr_relasi;


// Struct untuk List Alat Transportasi
struct Transport {
    string jenisTransport;
    string platNomor;
    transport *next;

// Struct untuk List Daerah
struct Daerah {
    string daerah;
    string kodePos;
    daerah *next;

};

// Struct untuk List Relasi
struct Relasi {
    Daerah *daerah;
    Transport *angkutan;
    Relasi *next;
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
