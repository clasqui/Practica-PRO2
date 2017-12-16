/** @file Individu.cc
    @brief Implementació de la classe Individu
*/

#include "Individu.hh"
#include <cassert>

Individu::Individu() {
    this->trets = set<string>();
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
    for(auto tret:trets) {
        cout << "  ";
        cout << tret << endl;
    }
}

void Individu::afegeix_tret(string t) {
    this->trets.insert(t);
}

Cromosoma Individu::consul_cromosomes() const {
    return this->cromosomes;
}

void Individu::elimina_tret(string t) {
    trets.erase(t);
}