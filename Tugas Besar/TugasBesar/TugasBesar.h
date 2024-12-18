#ifndef TUGASBESAR_H_INCLUDED
#define TUGASBESAR_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmTransport *adr_transport;
typedef struct elmDaerah *adr_daerah;
typedef struct elmRelasi *adr_relasi;


// Struct untuk List Alat Transportasi
struct Transport {
    string jenisTransport;
    string namaTransport;
    transport *next;
};

// Struct untuk List Daerah
struct Daerah {
    string namaDaerah;
    string kodeDaerah;
    daerah *next;

};

// Struct untuk List Relasi
struct Relasi {
    Daerah *daerah;
    Transport *angkutan;
    Relasi *next;
};

// List transport
struct elmTransport {
    transport info;
    adr_transport next;
};

// List daerah
struct elmDaerah {
    daerah info;
    adr_daerah next;
};

// List Relasi
struct elmRelasi {
    adr_transport transport;
    adr_daerah daerah;
    adr_relasi next;
};

struct listTransport {
    adr_transport first;
};

struct listDaerah {
    adr_daerah first;
};

struct listRelasi {
    adr_relasi first;
};


//
void createListTransport(ListTransport &L);
void createListDaerah(ListDaerah &L);
void createListRelasi(ListRelasi &L);

//
adr_transport newElmListTransport(transport x);
adr_daerah newElmListDaerah(daerah x);
adr_relasi newElmListRelasi(adr_Transport a, adr_daerah b);

//insert(penambahan data)
void insertFirstTransport(listTransport &L, adr_transport P);
void insertFirstDaerah(listDaerah &L, adr_daerah P);
void insertFirstRelasi(listRelasi &L, adr_relasi P);

void insertLastTransport(listTransport &L, adr_transport P);
void insertLastDaerah(listDaerah &L, adr_daerah P);
void insertLastRelasi(listRelasi &L, adr_relasi P);

//delete Transport
void deleteTransport(listTransport &L, listRelasi &R, string namaTransport);

//delete Daerah
void deleteDaerah(listDaerah &L, listRelasi &R, string namaDaerah);

//Menampilkan semua Transport dan daerah yang dikunjunginya.
void printAllTransport(listTransport L, listRelasi R);

//daerah tertentu
void printTransportByDaerah(listRelasi R, string namaDaerah); 

//Menampilkan data daerah yang paling mudah dan yang paling sulit
void printDaerahSarana(listDaerah D, listRelasi R);

//daerah yang dilalui oleh alat angkutan tertentu.
void printDaerahByTransport(listRelasi R, string namaTransport); 

//ascending
void sortTransportAsc(listTransport &L); 

//descending
void sortTransportDesc(listTransport &L);

#endif // TUGASBESAR_H_INCLUDED
