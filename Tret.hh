/** @file Tret.hh
    @brief Especificació de la classe Tret
*/

#ifndef PRACTICA_TRET_HH
#define PRACTICA_TRET_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <string>
#endif

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
        \pre Rep un string amb el nom del nou tret i un int n que serà la mida del vector d'individus
        \post El resultat és un Individu nou amb el paràmetre <em>nom</em> i <em>individus</em> inicialitzats.
    */
    Tret(string nom, int n);


    /** @brief Consulta el nom del tret
      \pre <em>Cert</em>
      \post Retorna el nom del tret
    */
    string consul_nom() const;


    /** @brief Afegeix un individu al qual es manifesta el tret
      \pre <em>id de l'individu</em>
      \post Retorna el nom de l'individu
    */
    void afegeix_manifestacio(int id) const;

    /** @brief Treu un individu al qual es manifesta el tret
      \pre <em>id de l'individu</em>
      \post Retorna el nom de l'individu
    */
    void treu_manifestacio(int id) const;

    /** @brief Imprimeix els gens pels quals es manifesta el tret
      \pre <em>Cert</em>
      \post Imprimeix els gens pels quals es manifesta el tret
    */
    void consulta_tret() const;

    /** @brief Retona els individus als quals es manifesta el tret
      \pre <em>Cert</em>
      \post Retorna el vecotr d'enters amb els id dels individus.
    */
    vector<int> consulta_individus() const;


private:
    /** @brief Nom de l'individu
    */
    string nom;

    /** @brief individus als quals es manifesta el tret
    */
    vector<int> individus;

};


#endif //PRACTICA_TRET_HH
