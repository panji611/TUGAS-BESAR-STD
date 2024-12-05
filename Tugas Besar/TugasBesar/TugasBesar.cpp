#include "TugasBesar.h"

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
