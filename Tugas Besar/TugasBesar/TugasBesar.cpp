#include "tugasbesar.h"

void createListTransport(listTransport &L) {
    L.first = NULL;
}

void createListDaerah(listDaerah &L) {
    L.first = NULL;
}

void createListRelasi(listRelasi &L) {
    L.first = NULL;
}

adr_transport newElmListTransport(transport x) {
    adr_transport P = new elmTransport;
    P->info = x;
    P->next = NULL;
    return P;
}

adr_daerah newElmListDaerah(daerah x) {
    adr_daerah P = new elmDaerah;
    P->info = x;
    P->next = NULL;
    return P;
}

adr_relasi newElmListRelasi(adr_transport a, adr_daerah b) {
    adr_relasi R = new elmRelasi;
    R->transport = a;
    R->daerah = b;
    R->next = NULL;
    return R;
}

void insertAngkutan(listTransport &L, adr_transport P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_transport temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

void insertDaerah(listDaerah &L, adr_daerah P) {
    if (L.first == NULL) {
        L.first = P;
    } else {
        adr_daerah temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = P;
    }
}

void insertRelasi(listRelasi &L, adr_relasi R) {
    if (L.first == NULL) {
        L.first = R;
    } else {
        adr_relasi temp = L.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = R;
    }
}

void deleteTransport(listTransport &L, listRelasi &R, string namaTransport) {
    // Menghapus relasi terkait
    adr_relasi pRel = R.first;
    adr_relasi prevRel = NULL;
    while (pRel != NULL) {
        if (pRel->transport->info.namaTransport == namaTransport) {
            if (prevRel == NULL) {
                R.first = pRel->next;
            } else {
                prevRel->next = pRel->next;
            }
            delete pRel;
            pRel = (prevRel == NULL) ? R.first : prevRel->next;
        } else {
            prevRel = pRel;
            pRel = pRel->next;
        }
    }

    adr_transport p = L.first;
    adr_transport prev = NULL;
    while (p != NULL && p->info.namaTransport != namaTransport) {
        prev = p;
        p = p->next;
    }
    if (p != NULL) {
        if (prev == NULL) {
            L.first = p->next;
        } else {
            prev->next = p->next;
        }
        delete p;
    }
}

void deleteDaerah(listDaerah &L, listRelasi &R, string namaDaerah) {
    adr_relasi pRel = R.first;
    adr_relasi prevRel = NULL;
    while (pRel != NULL) {
        if (pRel->daerah->info.namaDaerah == namaDaerah) {
            if (prevRel == NULL) {
                R.first = pRel->next;
            } else {
                prevRel->next = pRel->next;
            }
            delete pRel;
            pRel = (prevRel == NULL) ? R.first : prevRel->next;
        } else {
            prevRel = pRel;
            pRel = pRel->next;
        }
    }

    adr_daerah p = L.first;
    adr_daerah prev = NULL;
    while (p != NULL && p->info.namaDaerah != namaDaerah) {
        prev = p;
        p = p->next;
    }
    if (p != NULL) {
        if (prev == NULL) {
            L.first = p->next;
        } else {
            prev->next = p->next;
        }
        delete p;
    }
}

void printAllTransport(listTransport L, listRelasi R) {
    adr_relasi pRel = R.first;
    while (pRel != NULL) {
        cout << "Transport: " << pRel->transport->info.namaTransport
             << " -> Daerah: " << pRel->daerah->info.namaDaerah << endl;
        pRel = pRel->next;
    }
}

void printTransportByDaerah(listRelasi R, string namaDaerah) {
    adr_relasi pRel = R.first;
    bool found = false;
    while (pRel != NULL) {
        if (pRel->daerah->info.namaDaerah == namaDaerah) {
            cout << "Transportasi: " << pRel->transport->info.namaTransport << endl;
            found = true;
        }
        pRel = pRel->next;
    }
    if (!found) {
        cout << "Tidak ada transportasi yang mengunjungi daerah ini." << endl;
    }
}

void printDaerahSarana(listDaerah D, listRelasi R) {
    int minTransport = INT_MAX, maxTransport = 0;
    string minDaerah, maxDaerah;

    adr_daerah pDaerah = D.first;
    while (pDaerah != NULL) {
        int transportCount = 0;
        adr_relasi pRel = R.first;
        while (pRel != NULL) {
            if (pRel->daerah->info.namaDaerah == pDaerah->info.namaDaerah) {
                transportCount++;
            }
            pRel = pRel->next;
        }

        if (transportCount < minTransport) {
            minTransport = transportCount;
            minDaerah = pDaerah->info.namaDaerah;
        }
        if (transportCount > maxTransport) {
            maxTransport = transportCount;
            maxDaerah = pDaerah->info.namaDaerah;
        }
        pDaerah = pDaerah->next;
    }

    cout << "Daerah dengan sarana transportasi paling sedikit: " << minDaerah << endl;
    cout << "Daerah dengan sarana transportasi paling banyak: " << maxDaerah << endl;
}

void printDaerahByTransport(listRelasi R, string namaTransport) {
    adr_relasi pRel = R.first;
    bool found = false;
    while (pRel != NULL) {
        if (pRel->transport->info.namaTransport == namaTransport) {
            cout << "Daerah: " << pRel->daerah->info.namaDaerah << endl;
            found = true;
        }
        pRel = pRel->next;
    }
    if (!found) {
        cout << "Tidak ada daerah yang dilalui oleh transportasi ini." << endl;
    }
}

void sortTransportAsc(listTransport &L) {
    if (L.first == NULL || L.first->next == NULL) return;

    adr_transport p = L.first;
    while (p != NULL) {
        adr_transport q = p->next;
        while (q != NULL) {
            if (p->info.namaTransport > q->info.namaTransport) {
                swap(p->info.namaTransport, q->info.namaTransport);
            }
            q = q->next;
        }
        p = p->next;
    }
}

void sortTransportDesc(listTransport &L) {
    if (L.first == NULL || L.first->next == NULL) return;

    adr_transport p = L.first;
    while (p != NULL) {
        adr_transport q = p->next;
        while (q != NULL) {
            if (p->info.namaTransport < q->info.namaTransport) {
                swap(p->info.namaTransport, q->info.namaTransport);
            }
            q = q->next;
        }
        p = p->next;
    }
}
