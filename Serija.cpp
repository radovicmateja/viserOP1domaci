//
// Created by mateja on 24.5.2024.
//

#include "Serija.h"


int Serija::getSezone() const {
    return sezone;
}
void Serija::setSezone(int sezone) {
    this->sezone = sezone;
}
int Serija::getEpizode() const {
    return epizode;
}
void Serija::setEpizode(int epizode) {
    this->epizode = epizode;
}
void Serija::Ispis() {
    cout << "Serija: \"" << naslov << "\" (" << godina << "), Reditelj: " << reditelj << ", Broj sezona: " << sezone << ", Broj epizoda: " << epizode << ", ID: " << sadrzajID << endl;
}
