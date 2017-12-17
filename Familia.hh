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
 *  Els nodes de l'arbre contenen l'id de cada Individu.
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


    /** @brief Arbre del tipus BinTree<int> que representa les relacions paternofilials.
     *   L'arrel de l'arbre es un enter que representa l'id de l'individu.
     */
    BinTree<int> arbre;
    
    /** @brief Construeix un subarbre de l'arbre original que conté els camins a tots els fills als quals es manifesta el Tret t.

        \pre Rep per referència un BinTree arbre i un Tret t
        \post Retorna un parell amb un bool i un BinTree<int>.  El bool ens indica si en el nostre arbre s'ha manifestat el tret t. El BinTree és un subabre amb els id dels individus que manifesten el tret, o amb l'id canviat de signe els que no el manifesten.  Si els fills no manifesten el tret, el subarbre és buit.
    */
    pair<bool, BinTree<int>> construeix_subarbre_distribucio(const BinTree<int> &arbre, Tret &t);

    /** @brief Imprimeix recursivament i en inordre un BinTree per la sortida estàndard

        \pre Rep per referència un arbre.
        \post Si l'arbre és buit, retorna. Si és no buit, imprimeix l'arbre esquerra, imprimeix el valor de l'arrel i imprimeix l'arbre dret.
    */
    void imprimeix_arbre(const BinTree<int> &arbre) const;

};

#endif //PRACTICA_FAMILIA_HH
