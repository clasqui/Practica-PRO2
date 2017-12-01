/** @file Familia.hh
 *  @brief Especificació de la classe Familia
 */

#ifndef PRACTICA_FAMILIA_HH
#define PRACTICA_FAMILIA_HH

#include "Individu.hh"
#include "BinTree.hh"

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

        Rep un vector d'individus per referència que anirà omplint amb els individus que crea, de manera que la funció que crida llegeix_familia el pot utilitzar després.
        \pre <em>Cert</em>
        \post Familia amb el paràmetre arbre omplert.
    */
    llegeix_familia(vector<Individu> &registre);
    
    
private:
    
    /** @brief Arbre del tipus BinTree que representa les relacions
     */
    BinTree<Individu *> arbre;
}

#endif //PRACTICA_FAMILIA_HH
