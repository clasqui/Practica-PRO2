/** @file Individu.cc
    @brief Implementació de la classe Individu
*/

#include "Individu.hh"

Individu::Individu() {}

void Individu::llegeix_individu(int m) {
    Cromosoma c = Cromosoma(m);
    this->cromosomes = c;
}