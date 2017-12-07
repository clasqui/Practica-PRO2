/** @file Familia.hh
 *  @brief Especificació de la classe Familia
 */

#ifndef PRACTICA_FAMILIA_HH
#define PRACTICA_FAMILIA_HH

#include "Individu.hh"
#include "BinTree.cc"

/** @class Familia
 *  @brief Representa els individus d'un experiment i les seves relacions paternofilials.
 *  Els nodes de l'arbre contenen punters als individus, de manera que el seu accés és molt més fàcil i té un cost molt baix
 */
class Familia {
public:
    
    /** @brief Constructora per defecte.

        S'executa automàticament en declarar una Familia.
        \pre <em>Cert</em>
        \post Familia buida inicialitzada.
    */
    Familia();
    
    
    /** @brief Llegeix una familia d'individus

        \pre Rep per paràmetre un vector d'individus que anirà omplint.
        \post Familia amb el paràmetre arbre omplert.
    */
    void llegeix_familia(vector<Individu>& registre);


private:

    /** @brief LLegeix recursivament els individus d'una familia i els introdueix a l'arbre

        \pre Rep per paràmetre un arbre buit.<br>Per l'entrada estàndard també rep un id 0 <= id <= n
        \post L'arbre ara conté l'id llegit a l'arrel i els fills llegits.
    */
    void llegeix_familia_i(BinTree<Individu *> &arbre, vector<Individu>& registre);


    /** @brief Arbre del tipus BinTree que representa les relacions
     */
    BinTree<Individu *> arbre;
};

#endif //PRACTICA_FAMILIA_HH
