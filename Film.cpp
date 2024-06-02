//
// Created by mateja on 24.5.2024.
//

#include "Film.h"



int Film::getTrajanje() const {
    return trajanje;
}
void Film::setTrajanje(int trajanje) {
    this->trajanje = trajanje;
}
void Film::Ispis()  {
    cout << "Film: \"" << naslov << "\" (" << godina << "), Reditelj: " << reditelj << ", Trajanje: " << trajanje << "min. " << "ID: " << sadrzajID << endl;
}

