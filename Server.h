//
// Created by mateja on 24.5.2024.
//

#pragma once

#include <map>
#include <variant>
#include <queue>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "Sadrzaj.h"
#include "Korisnik.h"
#include "Film.h"
#include "Serija.h"

class Server {
private:
    map<int, Sadrzaj*> sadrzaj;
    map<int, Korisnik*> korisnici;


public:
    static int ukupnoSadrzaja;
    static int ukupnoKorisnika;

    //dodavanje sadrzaja
    void dodajSadrzaj(Sadrzaj* s);

    //dodavanje korisnika
    void dodajKorisnika(Korisnik* k);

    //pretraga sadrzaja po id-u ili po naslovu u jednoj metodi koriscenjem sablona
    Sadrzaj* pretraga(std::variant<int, string> id);

    //sortiranje sadrzaja po godini - najnovije prvo
    void sortiranjePoGodini();

    //dodavanje sadrzaja u omiljeno kod korisnika
    void dodajOmiljeno(int korisnikID, int sadrzajID);
    //uklanjanje sadrzaja iz omiljenog kod korisnika
    void ukloniOmiljeno(int korisnikID, int sadrzajID);

    //dodavanje sadrzaja u gledano kod korisnika
    void dodajGledano(int korisnikID, int sadrzajID);
    //uklanjanje sadrzaja iz gledanog kod korisnika
    void ukloniGledano(int korisnikID, int sadrzajID);

    //dodaj u red za gledanje
    void dodajRedZaGledanje(int korisnikID, int sadrzajID);


    //citanje podataka iz datoteke i konstuktovanje sadrzaja (svaka linija u datoteci predstavlja jedan sadrzaj, filmovi imaju 5 atributa, serije 6), datoteka je hardkodovana.
    void citanjePodataka();

    //status servera, ispis
    void statusServera();

    static bool poredjenjePoGodini(Sadrzaj* s1, Sadrzaj* s2);

    //ispis svih sadrzaja
    void IspisSadrzaja();

};
