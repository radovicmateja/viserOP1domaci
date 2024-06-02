#include "Server.h"

int main() {
    Server s;
    s.citanjePodataka();

    Korisnik k1{"Mateja", 3522};
    s.dodajKorisnika(&k1);

    //Staticki clanovi
    s.statusServera();

    //Watch later - queue
    s.dodajRedZaGledanje(3522, 16);
    s.dodajRedZaGledanje(3522, 11);
    k1.stampajRedZaGledanje();


    //Overload operatora
    Sadrzaj s1("Film1", "Reditelj1", 2000, 1);
    Sadrzaj s2("Film2", "Reditelj2", 2001, 2);

    if (s1 < s2) {
        cout << endl << "Film1 je stariji od Film2" << endl;
    }
    else {
        cout << endl << "Film2 je stariji od Film1" << endl;
    }


    cout << endl << "Pretraga (Sablon): " << endl;
    s.pretraga("Joker")->Ispis(); //std::variant sablon, moze da pretrazuje i preko id
    cout << endl;


    s.dodajGledano(3522, 5);
    s.dodajGledano(3522, 12);
    s.dodajOmiljeno(3522, 1);


    //Omiljeni sadrzaji (vektor):
    k1.IspisOmiljenogSadrzaja();
    cout << endl;

    //Korisnik je gledao sadrzaj u sledecem redosledu (stack):
    k1.IspisGledanogSadrzaja();
    cout << endl;

    cout << "Najnoviji sadrzaj (sort): " << endl;
    s.sortiranjePoGodini();




    return 0;
}