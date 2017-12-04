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