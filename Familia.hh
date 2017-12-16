/** @file Familia.hh
 *  @brief Especificació de la classe Familia
 */

#ifndef PRACTICA_FAMILIA_HH
#define PRACTICA_FAMILIA_HH

#include "Individu.hh"
#include "BinTree.cc"
#include "Tret.hh"

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

        \pre Rep per referència un vector d'individus que anirà omplint.
        \post Familia amb el paràmetre arbre omplert.
    */
    void llegeix_familia(vector<Individu>& registre);
    
    /** @brief Imprimeix l'arbre de parentiu tenint en compte com es distribueix el Tret t
     * \pre Rep un Tret t per referència
     * \post imprimeix l'arbre en inordre amb l'identificador dels individus que manifesten el tret en els nodes, i l'identificador canviat de signe els individus que no el manifesten.
     */
    void imprimeix_distribucio(Tret &t);


private:

    /** @brief LLegeix recursivament els individus d'una familia i els introdueix a l'arbre

        \pre Rep per referència un arbre buit.<br>Per l'entrada estàndard també rep un id 0 <= id <= n
        \post L'arbre ara conté l'id llegit a l'arrel i els fills llegits.
    */
    void llegeix_familia_i(BinTree<int> &arbre, vector<Individu>& registre);


    /** @brief Arbre del tipus BinTree que representa les relacions paternofilials
     */
    BinTree<int> arbre;
    
    /** @brief Imprimeix el subarbre d'arbre que conté els camins a tots els fills als quals es manifesta el Tret t.

        \pre Rep per referència un BinTree arbre i un Tret t
        \post Es mostra a la sortida estàndard el subarbre d'arbre en inordre que conté tots els camins a els fills individus als quals es manifesta el tret t.  Els nodes seran l'id de l'individu si el tret es manifesta, i l'id en signe invers si el tret no es manifesta.
        Retorna un booleà que indica si en els fills del subarbre hi ha algun individu que manifesta el Tret t.
    */
    pair<bool, BinTree<int>> construeix_subarbre_distribucio(const BinTree<int> &arbre, Tret &t);

    /** @brief Imprimeix recursivament un BinTree per la sortida estàndard

        \pre Rep per referència un arbre.
        \post Si l'arbre és buit, retorna. Si és no buit, imprimeix l'arbre esquerra, imprimeix el valor de l'arrel i imprimeix l'arbre dret.
    */
    void imprimeix_arbre(const BinTree<int> &arbre) const;

};

#endif //PRACTICA_FAMILIA_HH
