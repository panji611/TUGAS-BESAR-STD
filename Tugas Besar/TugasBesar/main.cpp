#include <iostream>

using namespace std;

int main(){
    listTransport LTransport;
    listDaerah LDaerah;
    listRelasi LRelasi;

    createListTransport(LTransport);
    createListDaerah(LDaerah);
    createListRelasi(LRelasi);

    int pilihan = 0;

    while (true) {
        tampilkanMenu();
        cin >> pilihan;

        if (pilihan == 1) {
            tambahDataTransport(LTransport);
        } else if (pilihan == 2) {
            tambahDataDaerah(LDaerah);
        } else if (pilihan == 3) {
            tambahRelasi(LTransport, LDaerah, LRelasi);
        } else if (pilihan == 4) {
            hapusTransport(LTransport, LRelasi);
        } else if (pilihan == 5) {
            hapusDaerah(LDaerah, LRelasi);
        } else if (pilihan == 6) {
            printAllTransport(LTransport, LRelasi);
        } else if (pilihan == 7) {
            tampilkanTransportByDaerah(LRelasi);
        } else if (pilihan == 8) {
            tampilkanDaerahByTransport(LRelasi);
        } else if (pilihan == 9) {
            tampilkanDaerahPalingSedikitDanBanyak(LDaerah, LRelasi);
        } else if (pilihan == 10) {
            tampilkanTransportAscending(LTransport, LRelasi);
        } else if (pilihan == 11) {
            tampilkanTransportDescending(LTransport, LRelasi);
        } else if (pilihan == 12) {
            cout << "Terima kasih! Program selesai." << endl;
            break;
        } else {
            cout << "Pilihan tidak valid, silakan coba lagi." << endl;
        }

        cout << "\nTekan Enter untuk melanjutkan...";
        cin // Tunggu input Enter
        cin// Tunggu Enter untuk melanjutkan
    }

    return 0;
}
