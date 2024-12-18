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

void insertFirstTransport(listTransport &L, adr_transport P) {
    if(first(L)==NULL){
        first(L)=P;
    }else {
        next(P)=first(L);
        first(L)=P;
    }
}

void insertFirstDaerah(listDaerah &L, adr_daerah P) {
    if(first(L)==NULL){
        first(L)=P;
    }else {
        next(P)=first(L);
        first(L)=P;
    }
}

void insertFirstRelasi(listRelasi &L, adr_relasi P) {
    if(first(L)==NULL){
        first(L)=P;
    }else {
        next(P)=first(L);
        first(L)=P;
    }
}

void insertLastTransport(listTransport &L, adr_transport P) {
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

void insertLastDaerah(listDaerah &L, adr_daerah P) {
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

void insertLastRelasi(listRelasi &L, adr_relasi P) {
    if (L.first == NULL) {
        L.first = P; 
    } else {
        adr_relasi Q = L.first;
        while (Q->next != NULL) {
            Q = Q->next; 
        }
        Q->next = P; 
    }
}

void deleteTransport(listTransport &L, listRelasi &R, string namaTransport) {
    adr_transport P = L.first, Q = NULL;
    while (P != NULL && P->info.namaTransport != namaTransport) {
        Q = P;
        P = P->next;
    }
    if (P != NULL) {
        if (Q == NULL) {
            L.first = P->next;
        } else {
            Q->next = P->next;
        }
        delete P;

        // Hapus hubungan terkait
        adr_relasi r = R.first, prevR = NULL;
        while (r != NULL) {
            if (r->transport->info.namaTransport == namaTransport) {
                if (prevR == NULL) {
                    R.first = r->next;
                } else {
                    prevR->next = r->next;
                }
                delete r;
                // Menggunakan if-else untuk mengganti ternary
                if (prevR == NULL) {
                    r = R.first;
                } else {
                    r = prevR->next;
                }
            } else {
                prevR = r;
                r = r->next;
            }
        }
    }
}

void deleteDaerah(listDaerah &L, listRelasi &R, string namaDaerah) {
    adr_daerah P = L.first, Q = NULL;
    while (P != NULL && P->info.namaDaerah != namaDaerah) {
        Q = P;
        P = P->next;
    }
    if (P != NULL) {
        if (Q == NULL) {
            L.first = P->next;
        } else {
            Q->next = P->next;
        }
        delete P;

        // Hapus hubungan terkait
        adr_relasi r = R.first, prevR = NULL;
        while (r != NULL) {
            if (r->daerah->info.namaDaerah == namaDaerah) {
                if (prevR == NULL) {
                    R.first = r->next;
                } else {
                    prevR->next = r->next;
                }
                delete r;

                if (prevR == NULL) {
                    r = R.first;
                } else {
                    r = prevR->next;
                }
            } else {
                prevR = r;
                r = r->next;
            }
        }
    }
}

void printAllTransport(listTransport L, listRelasi R) {
    adr_transport P = L.first;
    while (P != NULL) {
        cout << "Transport: " << P->info.namaTransport << endl;
        adr_relasi r = R.first;
        while (r != NULL) {
            if (r->transport == P) {
                cout << "  -> Daerah: " << r->daerah->info.namaDaerah << endl;
            }
            r = r->next;
        }
        P = P->next;
    }
}

void printTransportByDaerah(listRelasi R, string namaDaerah) {
    adr_relasi r = R.first;
    bool ketemu = false;
    while (r != NULL) {
        if (r->daerah->info.namaDaerah == namaDaerah) {
            cout << "Transport: " << r->transport->info.namaTransport << endl;
            ketemu = true;
        }
        r = r->next;
    }
    if (!ketemu) {
        cout << "Tidak ada transport yang mengunjungi daerah ini." << endl;
    }
}

void printDaerahSarana(listDaerah D, listRelasi R) {
    int minTransport = 999999, maxTransport = 0;
    string minDaerah, maxDaerah;

    adr_daerah P = D.first;
    while (P != NULL) {
        int transportCount = 0;
        adr_relasi r = R.first;
        while (r != NULL) {
            if (r->daerah == P) {
                transportCount++;
            }
            r = r->next;
        }

        if (transportCount < minTransport) {
            minTransport = transportCount;
            minDaerah = P->info.namaDaerah;
        }
        if (transportCount > maxTransport) {
            maxTransport = transportCount;
            maxDaerah = P->info.namaDaerah;
        }
        P = P->next;
    }

    cout << "Daerah dengan sarana transportasi paling sedikit: " << minDaerah << endl;
    cout << "Daerah dengan sarana transportasi paling banyak: " << maxDaerah << endl;
}

void printDaerahByTransport(listRelasi R, string namaTransport) {
    adr_relasi r = R.first;
    int ketemu = false;
    while (r != NULL) {
        if (r->transport->info.namaTransport == namaTransport) {
            cout << "Daerah: " << pRel->daerah->info.namaDaerah << endl;
            ketemu = true;
        }
        r = r->next;
    }
    if (!ketemu) {
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
            transport temp = P->info;
                P->info = q->info;
                q->info = temp;
            }
        }
    }
}

void sortTransportDesc(listTransport &L) {
    if (L.first == NULL || L.first->next == NULL) return;

    adr_transport p = L.first;
    while (p != NULL) {
        adr_transport q = p->next;
        while (q != NULL) {
            if (p->info.namaTransport < q->info.namaTransport) {
                transport temp = P->info;
                P->info = q->info;
                q->info = temp;
            }
        }
    }
}
