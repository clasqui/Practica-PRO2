/** @file Familia.cc
 *  @brief Implementació de la classe Familia
 */

#include "Familia.hh"
using namespace std;

Familia::Familia() {
}

void Familia::llegeix_familia(vector<Individu>& registre) {

    // Llegeix l'ID de l'individu
    int x;
    cin >> x;
    //Crea el nou individu
    Individu i = Individu();
    //L'afegeix al vector que ens han passat
    registre[x] = i;

    // Creem arbres esquerra i dret
    BinTree<int> esquerra;
    BinTree<int> dret;

    //Cridem la funció recursiva pels dos fills de l'arbre
    this->llegeix_familia_i(esquerra, registre);
    this->llegeix_familia_i(dret, registre);


    // Construim el node
    this->arbre = BinTree<int>(x, esquerra, dret);

}

void Familia::imprimeix_distribucio(Tret &t) {
     pair<bool, BinTree<int>> result = construeix_subarbre_distribucio(arbre, t);
    if(result.first) {
        cout << " ";
        imprimeix_arbre(result.second);
        cout << endl;
    }
}

//Funcions Privades

void Familia::llegeix_familia_i(BinTree<int> &arbre, vector <Individu> &registre) {
    int id;
    cin >> id;
    // Sabem que els id van de 2 a n, per tant si es diferent de 0
    // el valor és vàlid i seguim la recursivitat
    if(id == 0) {
        return;
    }
    else {
        Individu i = Individu();
        registre[id] = i;
        BinTree<int> esquerra;
        BinTree<int> dret;
        this->llegeix_familia_i(esquerra, registre);
        this->llegeix_familia_i(dret, registre);
        arbre = BinTree<int>(id, esquerra, dret);
    }
}

pair<bool, BinTree<int>> Familia::construeix_subarbre_distribucio(const BinTree<int> &arbre, Tret &t) {
    if(arbre.empty()) {

        return make_pair(false, BinTree<int>());
    }

    pair<bool, BinTree<int>> ha_manifestat_esquerra = construeix_subarbre_distribucio(arbre.left(), t);
    pair<bool, BinTree<int>> ha_manifestat_dret = construeix_subarbre_distribucio(arbre.right(), t);

    BinTree<int> res;
    
    if(ha_manifestat_esquerra.first || ha_manifestat_dret.first) {
        // Sha manifestat abans en algun dels dos fills, per tant retornarem true al parell i retornem els arbres.

        int val;
        if(t.es_manifesta(arbre.value())) val = arbre.value();
          else val = -1*arbre.value();

        res = BinTree<int>(val, ha_manifestat_esquerra.second, ha_manifestat_dret.second);
        return make_pair(true, res);
    } else {
        // No s'ha manifestat abans.  Comprovem ara si l'individu del node actual manifesta el tret.
        if(t.es_manifesta(arbre.value())) {
            return make_pair(true, BinTree<int>(arbre.value()));
        } else {
            return make_pair(false, BinTree<int>());
        }

    }
    
}

void Familia::imprimeix_arbre(const BinTree<int> &arbre) const {
    if(arbre.empty()) return;

    imprimeix_arbre(arbre.left());
    cout << " " << arbre.value();
    imprimeix_arbre(arbre.right());
}