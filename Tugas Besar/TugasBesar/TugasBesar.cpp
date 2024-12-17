#include "TugasBesar.h"

void createListTransport(ListTransport &L){
    L.first = NULL;
}
void createListDaerah(ListDaerah &L){
    L.first = NULL;
}
void createListRelasi(ListRelasi &L){
    L.first = NULL;
}
adr_transport newElmListTransport(transport x){
    adr_transport P = new elmTransport;
    p->info = x;
    p->next = NULL;
    return P;
}
adr_daerah newElmListDaerah(daerah x){
    adr_daerah P = new elmDaerah;
    p->info = x;
    p->next = NULL;
    return P;
}
adr_relasi newElmListRelasi(adr_Transport a, adr_daerah b){
    adr_relasi P = new elmRelasi;
    p->Transport = a;
    p->daerah = b;
    p->next = NULL;
    return P;
}
void insertAngkutan(listTransport &L, adr_transport P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_transport Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertDaerah(listDaerah &L, adr_daerah P){
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_daerah Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void insertRelasi(listRelasi &L, adr_relasi R){
    R->next = L.first;
    L.first = R;
}
void deleteTransport(listTransport &L, listRelasi &R, string namaTransport);
void deleteDaerah(listDaerah &L, listRelasi &R, string namaDaerah);
void printAllTransport(listTransport L, listRelasi R);
void printTransportByDaerah(listRelasi R, string namaDaerah); 
void printDaerahSarana(listDaerah D, listRelasi R);
void printDaerahByTransport(listRelasi R, string namaTransport); 
void sortTransportAsc(listTransport &L); 
void sortTransportDesc(listTransport &L);

void createListTransport(ListTransport &L) {
    L.first = NULL;
}
void createListChild(ListChild &L) {
    L.first = NULL;
}
void createListRelation(ListRelation &L) {
    L.first = NULL;
}

Parent* createTransport(string transportName) {
    Transport* P = new Transport;
    P->transportName = transportName;
    P->next = NULL;
    return P;
}

void insertTransportFirst(ListTransport &L, Transport* P) {
    P->next = L.first;
    L.first = P;
}

void insertTransportLast(ListTransport &L, Transport* P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        Transport* temp = L.first;
        while (temp->next != NULL) temp = temp->next;
        temp->next = P;
    }
}

void deleteTransportFirst(ListParent &L) {
    if (L.first != NULL) {
       Transport* temp = L.first;
        L.first = temp->next;
        delete temp;
    }
}

void deleteParentByName(ListParent &L, string transportName) {
    Parent* temp = L.first;
    Parent* prev = NULL;
    while (temp != NULL && temp->transportName != transportName) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            L.first = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

Child* createChild(string regionName) {
    Child* C = new Child;
    C->regionName = regionName;
    C->next = NULL;
    return C;
}

void insertChildFirst(ListChild &L, Child* C) {
    C->next = L.first;
    L.first = C;
}

void insertChildLast(ListChild &L, Child* C) {
    if (L.first == NULL) {
        L.first = C;
    } else {
        Child* temp = L.first;
        while (temp->next != NULL) temp = temp->next;
        temp->next = C;
    }
}

void deleteChildFirst(ListChild &L) {
    if (L.first != NULL) {
        Child* temp = L.first;
        L.first = temp->next;
        delete temp;
    }
}

void deleteChildByName(ListChild &L, string regionName) {
    Child* temp = L.first;
    Child* prev = NULL;
    while (temp != NULL && temp->regionName != regionName) {
        prev = temp;
        temp = temp->next;
    }
    if (temp != NULL) {
        if (prev == NULL) {
            L.first = temp->next;
        } else {
            prev->next = temp->next;
        }
        delete temp;
    }
}

void createRelation(Parent* P, Child* C) {
    Relation* R = new Relation;
    R->transport = P;
    R->region = C;
    R->next = NULL;
    return R;
}

void insertRelationFirst(ListRelation &L, Relation* R) {
    R->next = L.first;
    L.first = R;
}

void deleteRelationByParent(ListRelation &L, Parent* P) {
    Relation* temp = L.first;
    Relation* prev = NULL;
    while (temp != NULL) {
        if (temp->transport == P) {
            if (prev == NULL) {
                L.first = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            temp = (prev == NULL) ? L.first : prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void deleteRelationByChild(ListRelation &L, Child* C) {
    Relation* temp = L.first;
    Relation* prev = NULL;
    while (temp != NULL) {
        if (temp->region == C) {
            if (prev == NULL) {
                L.first = temp->next;
            } else {
                prev->next = temp->next;
            }
            delete temp;
            temp = (prev == NULL) ? L.first : prev->next;
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

// Display Functions
void displayParentList(const ListParent &L) {
    Parent* temp = L.first;
    while (temp != NULL) {
        cout << "Transport: " << temp->transportName << endl;
        temp = temp->next;
    }
}

void displayChildList(const ListChild &L) {
    Child* temp = L.first;
    while (temp != NULL) {
        cout << "Region: " << temp->regionName << endl;
        temp = temp->next;
    }
}

void displayRelations(const ListRelation &L) {
    Relation* temp = L.first;
    while (temp != NULL) {
        cout << "Transport: " << temp->transport->transportName
             << " -> Region: " << temp->region->regionName << endl;
        temp = temp->next;
    }
}
