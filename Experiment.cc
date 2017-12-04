/** @file Experiment.cc
 *  @brief Implementació de la classe Experiment
 */

#include "Experiment.hh"

Experiment::Experiment() {
}

Experiment::Experiment(int n, int m) {
    this->n = n;
    this->m = m;
}

int Experiment::consul_m() {
    return this->m;
}

void Experiment::llegeix_experiment() {
    RegistreIndividus aux;

    this->familia = Familia();
    this->familia.llegeix_familia(aux);
    this->individus = aux;
}