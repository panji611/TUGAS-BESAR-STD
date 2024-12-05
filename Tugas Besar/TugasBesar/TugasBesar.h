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
};

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

// List transport
struct ListTransport {
    Transport* first;
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
void createListTransport(ListTransport &L);
void createListDaerah(ListDaerah &L);
void createListRelasi(ListRelasi &L);

//insert
adr_transport newElmListTransport(transport x);
adr_daerah newElmListDaerah(daerah x);
adr_relasi newElmListRelasi(adr_Transport a, adr_daerah b);

//delete Transport
void deleteFirstTransport(list_Transport &L, adr_Transport &trs);
void deleteLastTransport(list_Transport &L, adr_Transport &trs);
void deleteAfterTransport(list_Transport &L, adr_Transport &trs, adr_Transport &prec);

//print keseluruhan
void printAll(list_Transport L, list_Relasi LR);

void deleteDaerahFirst(ListDaerah &L);
void deleteDaerahdByName(ListDaerah &L, string regionName);
void displayTransportList(const ListTransport &L);
void createRelasi(Transport* T, Daerah* D);
void insertRelasiFirst(ListRelasi &L, Relasi* R);


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
