/** @file Cromosoma.cc
    @brief Especificació de la classe Cromosoma
*/

#include "Cromosoma.hh"

Cromosoma::Cromosoma() {}

Cromosoma::Cromosoma(const int m) {
    c1 = vector<int>(m);
    c2 = vector<int>(m);

    //Omplim el cromosoma 1
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        c1[i] = x;
    }

    //Omplim el cromosoma 2
    for (int i = 0; i < m; ++i) {
        int x;
        cin >> x;
        c2[i] = x;
    }
}

pair<int, int> Cromosoma::consul_gen(int i) const {
    return make_pair(c1[i], c2[i]);
}