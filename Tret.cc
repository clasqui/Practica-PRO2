/** @file Tret.cc
    @brief Implementació de la classe Tret
*/

#include "Tret.hh"

Tret::Tret() {}

Tret::Tret(string nom, int n) {
    this->nom = nom;
    this->individus = vector<int>(n);
}

string Tret::consul_nom() const {
    return this->nom;
}