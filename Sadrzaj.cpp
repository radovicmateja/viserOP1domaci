//
// Created by mateja on 24.5.2024.
//

#include "Sadrzaj.h"


string Sadrzaj::getNaslov() const {
    return naslov;
}
string Sadrzaj::getReditelj() const {
    return reditelj;
}
int Sadrzaj::getGodina() const {
    return godina;
}
int Sadrzaj::getSadrzajID() const {
    return sadrzajID;
}
void Sadrzaj::setNaslov(string naslov) {
    this->naslov = naslov;
}
void Sadrzaj::setReditelj(string reditelj) {
    this->reditelj = reditelj;
}
void Sadrzaj::setGodina(int godina) {
    this->godina = godina;
}
void Sadrzaj::setSadrzajID(int sadrzajID) {
    this->sadrzajID = sadrzajID;
}
bool Sadrzaj::operator<(Sadrzaj& drugi) const{
    return godina < drugi.getGodina();
}

void Sadrzaj::Ispis() {
    cout << "Sadrzaj: " << naslov << " " << reditelj << " " << godina << " " << sadrzajID << endl;
}
