//
// Created by mateja on 24.5.2024.
//
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include "Sadrzaj.h"

#pragma once

using namespace std;
class Korisnik {
private:
    string username;
    int korisnikID;
    vector<Sadrzaj*> omiljeniSadrzaji; //korisnik moze da ima vise omiljenih sadrzaja
    std::queue<Sadrzaj*> redZaGledanje; // watch later fazon
    stack<Sadrzaj*> gledaniSadrzaji; //korisnik moze da gleda vise sadrzaja (istorija gledanja)
public:
    Korisnik(string username, int korisnikID)
    : username(username), korisnikID(korisnikID) {}

    //inspektori i mutatori
    string getUsername() const;

    int getKorisnikID() const;

    void setUsername(string username);

    void setKorisnikID(int korisnikID);

    void dodajOmiljeniSadrzaj(Sadrzaj* sadrzaj);

    void ukloniOmiljeniSadrzaj(Sadrzaj* sadrzaj);

    void dodajGledaniSadrzaj(Sadrzaj* sadrzaj);

    void ukloniGledaniSadrzaj();

    void dodajNaRedZaGledanje(Sadrzaj* sadrzaj);

    void stampajRedZaGledanje();




    //geter za omiljene sadrzaje
    vector<Sadrzaj*> getOmiljeniSadrzaji();

    //Ispis omiljenog sadrzaja
    void IspisOmiljenogSadrzaja();

    //geter za gledane sadrzaje
    stack<Sadrzaj*> getGledaniSadrzaji();

    //Ispis gledanog sadrzaja
    void IspisGledanogSadrzaja();




};

