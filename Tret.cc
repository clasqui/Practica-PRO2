/** @file Tret.cc
    @brief Implementació de la classe Tret
*/

#include "Tret.hh"

Tret::Tret() {}

Tret::Tret(string nom, int m) {
    this->nom = nom;
    this->individus = list<int>();
    interseccio = vector<pair<int, int>>(m);
}

string Tret::consul_nom() const {
    return this->nom;
}

bool Tret::es_manifesta(int id) const {
    list<int>::const_iterator result = find(individus.begin(), individus.end(), id);
    return (result != individus.end());
}

void Tret::afegeix_manifestacio(int id) {
    individus.insert(individus.end(), id);
}

void Tret::recalcular_interseccio(Cromosoma &c) {
    if(this->individus.size() == 1) {
        for (int i = 0; i < interseccio.size(); ++i) {
            interseccio[i] = c.consul_gen(i);
        }
    } else {
        for (int i = 0; i < interseccio.size(); ++i) {
            if(interseccio[i].first != c.consul_gen(i).first ||
                    interseccio[i].second != c.consul_gen(i).second) {
                // Si son diferents, no hi ha intersecció i
                // i per tant borrem aquest element
                interseccio.erase(interseccio.begin()+i);
            }
        }
    }
}