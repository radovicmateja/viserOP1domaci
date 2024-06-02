//
// Created by mateja on 24.5.2024.
//
#include "Sadrzaj.h"
#pragma once

class Serija : public Sadrzaj{
private:
    int sezone;
    int epizode;
public:
    Serija(string naslov, string reditelj, int godina, int sadrzajID, int sezone, int epizode)
    : Sadrzaj(naslov, reditelj, godina, sadrzajID), sezone(sezone), epizode(epizode) {}

    //inspektori i mutatori
    int getSezone() const;

    void setSezone(int sezone);

    int getEpizode() const;

    void setEpizode(int epizode);

    void Ispis() override;
};
