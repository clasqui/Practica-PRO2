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
        char c;
        cin >> c;
        c1[i] = convert_char_int(c);
    }

    //Omplim el cromosoma 2
    for (int i = 0; i < m; ++i) {
        char c;
        cin >> c;
        c2[i] = convert_char_int(c);
    }
}

pair<int, int> Cromosoma::consul_gen(int i) const {
    return make_pair(c1[i], c2[i]);
}

void Cromosoma::imprimeix_cromosoma(int codi) const {
    vector<int> c;
    if(codi==0) c = c1;
    else if(codi==1) c = c2;
    else return;
    cout << "  ";
    for (int i = 0; i < c.size(); ++i) {
        cout << c[i];
    }
}

int Cromosoma::convert_char_int(char c) {
    int i = c - '0';
    return i;
}