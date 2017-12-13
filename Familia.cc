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
    BinTree<Individu *> esquerra;
    BinTree<Individu *> dret;

    //Cridem la funció recursiva pels dos fills de l'arbre
    this->llegeix_familia_i(esquerra, registre);
    this->llegeix_familia_i(dret, registre);


    // Construim el node
    this->arbre = BinTree<Individu *>(&i, esquerra, dret);

}

void imprimeix_distribucio(Tret &t) const {
    cout << " ";
}

//Funcions Privades

void Familia::llegeix_familia_i(BinTree<Individu *> &arbre, vector <Individu> &registre) {
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
        BinTree<Individu *> esquerra;
        BinTree<Individu *> dret;
        this->llegeix_familia_i(esquerra, registre);
        this->llegeix_familia_i(dret, registre);
        arbre = BinTree<Individu *>(&i, esquerra, dret);
    }
}

pair<bool, BinTree<int>> construeix_subarbre_distribucio(BinTree<Individu *> &arbre, Tret &t) {
    if(arbre.empty()) {
        return make_pair(false, BinTree<int>());
    }
    
    pair<bool, BinTree<int>> ha_manifestat_esquerra = construeix_subarbre_distribucio(arbre.left(), t);
    pair<bool, BinTree<int>> ha_manifestat_dret = construeix_subarbre_distribucio(arbre.right(), t);
    
    BinTree<int> res;
    
    if(ha_manifestat_esquerra.first || ha_manifestat_dret.first) {
        // Sha manifestat abans en algun dels dos fills, per tant retornarem true al parell.  Ara determinem quins fills posem al nou subarbre.
        int val;
        if(t.es_manifesta(arbre.value)) val = arbre.value();
          else val = -1*arbre.value();
          
        if(ha_manifestat_esquerra.first && ha_manifestat_dret.first) {
            // S'ha manifestat abans en ambdós fills, per tant els conservem als dos en el nou subarbre.
            res = BinTree<int>(val, ha_manifestat_esquerra.second, ha_manifestat_dret.second);
        } else if(ha_manifestat_esquerra.first) {
            // S'ha manifestat abans en el fill esquerra, per tant conservem aquest en el nou subarbre.
            res = BinTree<int>(val, ha_manifestat_esquerra.second, BinTree<int>());
        } else {
            // S'ha manifestat abans en el fill dret, per tant conservem aquest en el nou subarbre.
            res = BinTree<int>(val, ha_manifestat_dret.second, BinTree<int>());
        }
        return make_pair(true, res);
    } else {
        // No s'ha manifestat abans.  COmprovem ara si l'individu del node actual manifesta el tret.
        if(t.es_manifesta(arbre.value)) val = arbre.value();
          else val = -1*arbre.value();
        return make_pair(t.es_manifesta(arbre.value()), BinTree<int>(val));
    }
    
}
