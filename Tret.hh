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
    @brief Representa un Tret amb els cromosomes que el representen i els individus als quals es manifesta

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

        S'executa automàticament en declarar un Tret amb un nom.
        \pre Rep un string amb el nom del nou tret i un int amb el numero de gens per cromosoma
        \post El resultat és un Tret nou amb el paràmetre <em>nom</em> inicialitzat.
    */
    Tret(string nom, int m);


    /** @brief Consulta el nom del tret
      \pre <em>Cert</em>
      \post Retorna el nom del tret
    */
    string consul_nom() const;


    /** @brief Afegeix un individu al qual es manifesta el tret
      \pre <em>id de l'individu</em>
      \post Retorna el nom de l'individu
    */
    void afegeix_manifestacio(int id);

    /** @brief Treu un individu al qual es manifesta el tret
      \pre <em>id de l'individu</em>
      \post Retorna el nom de l'individu
    */
    void treu_manifestacio(int id) const;

    /** @brief Imprimeix els gens pels quals es manifesta el tret
      \pre <em>Cert</em>
      \post Imprimeix els gens pels quals es manifesta el tret
    */
    void mostra_interseccio() const;

    /** @brief Retona els individus als quals es manifesta el tret
      \pre <em>Cert</em>
      \post Retorna el vecotr d'enters amb els id dels individus.
      TODO Comprovar si es realment necessària la funció
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

    /** @brief Recalcula la manifestació del tret fent la intersecció entre l'actual i els gens del cromosoma que rep.
     *  \pre Rep per referència un Cromosoma c amb els gens
     *  \post Ara el paràmetre implícit conté la intersecció dels gens entre l'actual i el Cromosoma que rep.
     */
    void recalcular_interseccio(Cromosoma &c);


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



};


#endif //PRACTICA_TRET_HH
