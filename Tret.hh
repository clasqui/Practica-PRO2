/** @file Tret.hh
    @brief Especificació de la classe Tret
*/

#ifndef PRACTICA_TRET_HH
#define PRACTICA_TRET_HH

#ifndef NO_DIAGRAM
#include <list>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#endif

#include "Cromosoma.hh"


using namespace std;

/** @class Tret
    @brief Representa un Tret amb els la intersecció de gens que el representa i els individus als quals es manifesta.

*/
class Tret {
public:

    //Constructores

    /** @brief Constructora budia.

        S'executa automàticament en declarar un Tret.
        \pre <em>Cert</em>
        \post Tret buit inicialitzat.
    */
    Tret();


    /** @brief Constructora per defecte.

        S'executa automàticament en declarar un Tret amb un nom i el numero de gens de cada Cromosoma.
        \pre Rep un string amb el nom del nou tret i un int amb el numero de gens per Cromosoma.
        \post El resultat és un Tret nou amb el paràmetre <em>nom</em> inicialitzat i amb el vector interseccio incialitzat amb mida <em>m</em>.
    */
    Tret(string nom, int m);


    /** @brief Consulta el nom del paràmetre implícit
      \pre <em>Cert</em>
      \post Retorna el nom del paràmetre implícit.
    */
    string consul_nom() const;


    /** @brief Afegeix un individu al qual es manifesta el paràmetre implícit.
      \pre <em>id</em> de l'individu
      \post Ara el paràmetre implícit conté l'id de l'individu a la llista de individus.
    */
    void afegeix_manifestacio(int id);

    /** @brief Treu un individu en el que el tret es manifesta
        La funció també ens indicacrà a través d'un bool si el tret ja no es manifesta en CAP individu, i per tant s'ha d'eliminar.
      \pre Rep un id, <em>1 <= id <= n</em>,  de l'individu
      \post El resultat és true si després d'eliminar l'individu no queden individus.
    */
    bool treu_manifestacio(int id);

    /** @brief Imprimeix els gens pels quals es manifesta el paràmetre implícit.
      \pre <em>Cert</em>
      \post Imprimeix els gens pels quals es manifesta el paràmetre implícit.
    */
    void mostra_interseccio() const;

    /** @brief Retona els individus als quals es manifesta el tret
      \pre <em>Cert</em>
      \post Retorna el vector d'enters amb els id dels individus.
    */
    list<int> consulta_individus() const;


    /** @brief Mostra els individus als quals es manifesta el tret a la sortida estàndard
      \pre <em>Cert</em>
      \post Mostra els individus que manifesten el tret per ordre creixent d'identificador.
    */
    void mostra_individus() const;

    /** @brief Ens diu si el tret es manifesta a un individu
      \pre un id 1 <= id <= n
      \post Retorna un bool amb el resultat
    */
    bool es_manifesta(int id) const;

    /** @brief Recalcula la manifestació del paràmetre implícit fent la intersecció entre l'actual i els gens del cromosoma que rep.
     *  \pre Rep per referència un Cromosoma c amb els gens
     *  \post Ara el paràmetre implícit conté la intersecció dels gens entre l'actual i el Cromosoma que rep.
     */
    void recalcular_interseccio(Cromosoma &c);

    /** @brief Indica que el tret és buit, i per tant s'ha de recalcular
     * \pre <em>Cert</em>
     * \post El paràmetre implícit ara conté el booleà <em>recalcular</em> igual a <em>true</em>
     */
    void buida();


private:
    /** @brief Nom de l'individu
    */
    string nom;

    /** @brief individus als quals es manifesta el tret
    */
    list<int> individus;

    /** @brief Combinació de parells de cromosomes que fan que es manifesti el tret
     *
     */
     vector<pair<int, int>> interseccio;

    /** @brief Ens indica que la intersecció s'haurà de recalcular des de 0
     * Això fa substancialment diferent la funció recalcular_interseccio(), ja que si recalcular == true,
     * el cromosoma que es calcula es posa directament a la intersecció.
     */
    bool recalcular;



};


#endif //PRACTICA_TRET_HH
