//
// Created by mateja on 24.5.2024.
//
#include <iostream>
#pragma once

using namespace std;

class Sadrzaj {
protected:
    string naslov;
    string reditelj;
    int godina;
    int sadrzajID;
public:
    Sadrzaj(string naslov, string reditelj, int godina, int sadrzajID)
    : naslov(naslov), reditelj(reditelj), godina(godina), sadrzajID(sadrzajID) {}

    //inspektori i mutatori
    string getNaslov() const;

    string getReditelj() const;

    int getGodina() const;

    int getSadrzajID() const;

    void setNaslov(string naslov);

    void setReditelj(string reditelj);

    void setGodina(int godina);

    void setSadrzajID(int sadrzajID);

    bool operator<(Sadrzaj& drugi) const;

    virtual void Ispis();

};
