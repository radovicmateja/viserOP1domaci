//
// Created by mateja on 24.5.2024.
//

#include "Korisnik.h"


//inspektori i mutatori
string Korisnik::getUsername() const {
    return username;
}
int Korisnik::getKorisnikID() const {
    return korisnikID;
}
void Korisnik::setUsername(string username) {
    this->username = username;
}

[[maybe_unused]] void Korisnik::setKorisnikID(int korisnikID) {
    this->korisnikID = korisnikID;
}
void Korisnik::dodajOmiljeniSadrzaj(Sadrzaj* sadrzaj) {
    omiljeniSadrzaji.push_back(sadrzaj);
}
void Korisnik::ukloniOmiljeniSadrzaj(Sadrzaj* sadrzaj) {
    for (int i = 0; i < omiljeniSadrzaji.size(); i++) {
        if (omiljeniSadrzaji[i] == sadrzaj) {
            omiljeniSadrzaji.erase(omiljeniSadrzaji.begin() + i);
            break;
        }
    }
}
void Korisnik::dodajGledaniSadrzaj(Sadrzaj* sadrzaj) {
    gledaniSadrzaji.push(sadrzaj);
}
void Korisnik::ukloniGledaniSadrzaj() {
    gledaniSadrzaji.pop();
}
//geter za omiljene sadrzaje
vector<Sadrzaj*> Korisnik::getOmiljeniSadrzaji() {
    return omiljeniSadrzaji;
}
//Ispis omiljenog sadrzaja
void Korisnik::IspisOmiljenogSadrzaja() {
    cout << "Omiljeni sadrzaji - " << getUsername() << ":" << endl;
    for (int i = 0; i < omiljeniSadrzaji.size(); i++) {
        omiljeniSadrzaji[i]->Ispis();
    }
}

//Ispis gledanog sadrzaja - stampanje steka
void Korisnik::IspisGledanogSadrzaja() {
    cout << "Gledani sadrzaji - " << getUsername() << ":" << endl;
    stack<Sadrzaj*> temp = gledaniSadrzaji;
    while (!temp.empty()) {
        temp.top()->Ispis();
        temp.pop();
    }
}

//geter za gledane sadrzaje
stack<Sadrzaj*> Korisnik::getGledaniSadrzaji() {
    return gledaniSadrzaji;
}

void Korisnik::dodajNaRedZaGledanje(Sadrzaj *sadrzaj) {
    redZaGledanje.push(sadrzaj);

}

void Korisnik::stampajRedZaGledanje() {
    cout << "Red za gledanje - " << getUsername() << ":" << endl;
    queue<Sadrzaj*> temp = redZaGledanje;
    while (!temp.empty()) {
        temp.front()->Ispis();
        temp.pop();
    }

}
