//
// Created by mateja on 24.5.2024.
//
#pragma once
#include "Sadrzaj.h"

class Film : public Sadrzaj {
private:
    int trajanje;
public:
    Film(string naslov, string reditelj, int godina, int sadrzajID, int trajanje)
    : Sadrzaj(naslov, reditelj, godina, sadrzajID), trajanje(trajanje) {}

    //inspektori i mutatori
    int getTrajanje() const;
    void setTrajanje(int trajanje);
    void Ispis() override;



};

