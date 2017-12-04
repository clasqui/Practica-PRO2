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

int Experiment::consul_m() const {
    return this->m;
}

void Experiment::llegeix_experiment() {
    vector<Individu> aux;

    // Llegim primer la familia i la posem a l'arbre
    this->familia = Familia();
    this->familia.llegeix_familia(aux);


    // Ara llegim la informació genètica de cada individu
    for (int i = 1; i <= n; ++i) {
        aux[i].llegeix_individu(m);
    }

    // El vector, tot ple, el posem al registre d'individus
    this->individus = aux;
}