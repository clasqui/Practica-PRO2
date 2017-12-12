/** @file Tret.cc
    @brief Implementació de la classe Tret
*/

#include "Tret.hh"
#include <cassert>

Tret::Tret() {}


Tret::Tret(string nom, int m) {
    this->nom = nom;
    this->individus = list<int>();
    interseccio = vector<pair<int, int>>(m);
    this->recalcular = true;
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
    if(recalcular) {
        for (int i = 0; i < interseccio.size(); ++i) {
            interseccio[i] = c.consul_gen(i);
        }
        recalcular = false;
    } else {
        for (int i = 0; i < interseccio.size(); ++i) {
            if(interseccio[i].first != c.consul_gen(i).first ||
                    interseccio[i].second != c.consul_gen(i).second) {
                // Si son diferents, no hi ha intersecció i
                // i per tant borrem aquest element
                // interseccio.erase(interseccio.begin()+i);
                // Aquest metode no funciona perque despres no hi ha
                // manera de saber si existeix o no, per tant ho substituim per un -1
                interseccio[i].first = -1;
                interseccio[i].second = -1;
            }
        }
    }
}

void Tret::mostra_interseccio() const {
    cout << "  ";
    for (int i = 0; i < interseccio.size(); ++i) {
        if(interseccio[i].first == 1 || interseccio[i].first == 0) {
            cout << interseccio[i].first;
        } else {
            cout << "-";
        }
    }
    cout << endl;
    cout << "  ";
    for (int i = 0; i < interseccio.size(); ++i) {
        if(interseccio[i].second == 1 || interseccio[i].second == 0) {
            cout << interseccio[i].second;
        } else {
            cout << "-";
        }
    }
    cout << endl;
}

void Tret::mostra_individus() const {
    list<int>::const_iterator it;
    for (it = individus.begin(); it != individus.end(); ++it) {
        cout << "  " << *it << endl;
    }
}

bool Tret::treu_manifestacio(int id) {
    list<int>::iterator it = find(individus.begin(), individus.end(), id);
    individus.erase(it);
    return (individus.size() == 0);
}

int Tret::count_individus() const {
    return individus.size();
}

void Tret::buida() {
    this->recalcular = true;
}

list<int> Tret::consulta_individus() const {
    return individus;
}