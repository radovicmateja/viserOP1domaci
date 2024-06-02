//
// Created by mateja on 24.5.2024.
//

#include "Server.h"
#include "Film.h"
#include "Serija.h"

int Server::ukupnoSadrzaja = 0;
int Server::ukupnoKorisnika = 0;


void Server::dodajSadrzaj(Sadrzaj* s) {
    sadrzaj[ukupnoSadrzaja++] = s;
}


void Server::dodajKorisnika(Korisnik* k) {
    korisnici[ukupnoKorisnika++] = k;
}

Sadrzaj* Server::pretraga(std::variant<int, string> id){
    for (int i = 0; i < ukupnoSadrzaja; i++) {
        if (std::holds_alternative<int>(id) && sadrzaj[i]->getSadrzajID() == std::get<int>(id))
            return sadrzaj[i];
        if (std::holds_alternative<string>(id) && sadrzaj[i]->getNaslov() == std::get<string>(id))
            return sadrzaj[i];
    }
    cerr << "Nema sadrzaja sa tim naslovom ili ID..." << endl;
    return nullptr;
}


void Server::sortiranjePoGodini() { //komparator je na dnu cpp fajla
    std::vector<Sadrzaj*> pom;
    for (auto& instanca : sadrzaj) {
        pom.push_back(instanca.second);
    }
    std::sort(pom.begin(), pom.end(), Server::poredjenjePoGodini);

    for (auto& instanca : pom) {
        instanca->Ispis();
    }
}

void Server::dodajOmiljeno(int korisnikID, int sadrzajID) {
    for (int i = 0; i < ukupnoKorisnika; i++) {
        if (korisnici[i]->getKorisnikID() == korisnikID) {
            for (int j = 0; j < ukupnoSadrzaja; j++) {
                if (sadrzaj[j]->getSadrzajID() == sadrzajID) {
                    korisnici[i]->dodajOmiljeniSadrzaj(sadrzaj[j]);
                    break;
                }
            }
            break;
        }
    }
}

void Server::ukloniOmiljeno(int korisnikID, int sadrzajID) {
    for (int i = 0; i < ukupnoKorisnika; i++) {
        if (korisnici[i]->getKorisnikID() == korisnikID) {
            for (auto j = 0; j < ukupnoSadrzaja; j++) {
                if (sadrzaj[j]->getSadrzajID() == sadrzajID) {
                    korisnici[i]->ukloniOmiljeniSadrzaj(sadrzaj[j]);
                    break;
                }
            }
            break;
        }
    }
}

void Server::dodajGledano(int korisnikID, int sadrzajID) {
    for (auto i = 0; i < ukupnoKorisnika; i++) {
        if (korisnici[i]->getKorisnikID() == korisnikID) {
            for (auto j = 0; j < ukupnoSadrzaja; j++) {
                if (sadrzaj[j]->getSadrzajID() == sadrzajID) {
                    korisnici[i]->dodajGledaniSadrzaj(sadrzaj[j]);
                    break;
                }
            }
            break;
        }
    }
}

void Server::ukloniGledano(int korisnikID, int sadrzajID) {
    for (auto i = 0; i < ukupnoKorisnika; i++) {
        if (korisnici[i]->getKorisnikID() == korisnikID) {
            for (auto j = 0; j < ukupnoSadrzaja; j++) {
                if (sadrzaj[j]->getSadrzajID() == sadrzajID) {
                    korisnici[i]->ukloniGledaniSadrzaj();
                    break;
                }
            }
            break;
        }
    }
}

void Server::dodajRedZaGledanje(int korisnikID, int sadrzajID) {
    for (auto i = 0; i < ukupnoKorisnika; i++) {
        if (korisnici[i]->getKorisnikID() == korisnikID) {
            for (auto j = 0; j < ukupnoSadrzaja; j++) {
                if (sadrzaj[j]->getSadrzajID() == sadrzajID) {
                    korisnici[i]->dodajNaRedZaGledanje(sadrzaj[j]);
                    break;
                }
            }
            break;
        }
    }
}

void Server::citanjePodataka() {
    ifstream file("sadrzaj.tsv",ifstream::in);
    if (!file.is_open()) {
        cerr << "Greska pri otvaranju datoteke..." << endl;
        exit(1);
    }
    string linija;
    //popraviti parsiranje na /t
    while (getline(file, linija)) {
        stringstream ss(linija);
        string tip, naslov, reditelj, godinastr, sadrzajIDstr;
        int godina, sadrzajID;

        getline(ss, tip, '\t');
        getline(ss, naslov, '\t');
        getline(ss, reditelj, '\t');
        getline(ss, godinastr, '\t');
        getline(ss, sadrzajIDstr, '\t');

        godina = stoi(godinastr);
        sadrzajID = stoi(sadrzajIDstr);

        if (tip == "Film") {
            int trajanje;
            string trajanjestr;

            getline(ss, trajanjestr, '\t');
            trajanje = stoi(trajanjestr);
            dodajSadrzaj(new Film(naslov, reditelj, godina, sadrzajID, trajanje));
        }
        else if (tip == "Serija") {
            int sezone, brojEpizoda;
            string sezonestr, epizodestr;
            getline(ss, sezonestr, '\t');
            getline(ss, epizodestr, '\t');

            sezone = stoi(sezonestr);
            brojEpizoda = stoi(epizodestr);
            dodajSadrzaj(new Serija(naslov, reditelj, godina, sadrzajID, sezone, brojEpizoda));
        }
    }
    file.close();
}

void Server::statusServera() {
    cout << "Ukupno sadrzaja: " << ukupnoSadrzaja << ", Ukupno registrovanih korisnika: " << ukupnoKorisnika << endl;
}

void Server::IspisSadrzaja() {
    for (int i = 0; i < ukupnoSadrzaja; i++) {
        sadrzaj[i]->Ispis();
    }
}

bool Server::poredjenjePoGodini(Sadrzaj *s1, Sadrzaj *s2) {
    return (s1->getGodina() > s2->getGodina());
}
