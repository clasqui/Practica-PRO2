/** @file Individu.cc
    @brief Implementació de la classe Individu
*/

#include "Individu.hh"

Individu::Individu() {
    this->trets = set<Tret *>();
}

void Individu::llegeix_individu(int m) {
    Cromosoma c = Cromosoma(m);
    this->cromosomes = c;
}

void Individu::mostra_cromosomes() const {
    this->cromosomes.imprimeix_cromosoma(0);
    cout << endl;
    this->cromosomes.imprimeix_cromosoma(1);
    cout << endl;
}

void Individu::mostra_trets() const {
    set<Tret*>::iterator it;
    for (it = trets.begin(); it != trets.end(); ++it) {
        cout << "  ";
        Tret *p = *it;
        cout << p->consul_nom() << endl;
    }
}

void Individu::afegeix_tret(Tret *t) {
    this->trets.insert(t);
}

Cromosoma Individu::consul_cromosomes() const {
    return this->cromosomes;
}