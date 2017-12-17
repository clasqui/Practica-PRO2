/** @file Individu.hh
    @brief Especificació de la classe Individu
*/

#ifndef PRACTICA_INDIVIDU_HH
#define PRACTICA_INDIVIDU_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <string>
#include <set>
#endif

#include "Cromosoma.hh"
#include "Tret.hh"

using namespace std;

/** @class Individu
    @brief Representa un indvidu amb el seu parell de cromosomes

*/
class Individu {
public:

    //Constructores

    /** @brief Constructora per defecte.

        S'executa automàticament en declarar un Individu.
        \pre <em>Cert</em>
        \post Individu buit inicialitzat.
    */
    Individu();


    /** @brief Llegeix els cromosomes de l'entrada estàndard i el posa al paràmetre implícit
      \pre Rep el numero de gens que han de tenir els cromosomes i per l'entrada estàndard llegeix els dos cromosomes.
      \post El paràmetre implícit ara conté el els cromosomes llegits
    */
    void llegeix_individu(int m);


    /** @brief Consulta els cromosomes
      \pre <em>Cert</em>
      \post Retorna els cromosomes del paràmetre implícit
    */
    Cromosoma consul_cromosomes() const;

    /** @brief Imprimeix els cromosomes a l'entrada estàndard
      \pre <em>Cert</em>
      \post Mostra els cromosomes del paràmetre implícit a l'entrada estàndard
    */
    void mostra_cromosomes() const;

    /** @brief Imprimeix els trets
     \pre <em>Cert</em>
     \post Mostra els trets del paràmetre implícit ordenats alfabèticament.
   */
    void mostra_trets() const;

    /** @brief Afegeix un Tret al paràmetre implícit.
     * \pre Rep una string que representa el nom d'un Tret.
     * \post El paràmetre implícit ara conté el el nom del tret al set de <em>trets</em>
     */
    void afegeix_tret(string);

    /** @brief Elimina un Tret del paràmetre implícit.
     * \pre Rep una string que representa el nom del Tret.
     * \post El paràmetre implícit ara no conté aquest tret al set <em>trets</em>
     */
    void elimina_tret(string);



private:

    /** @brief Cromosomes del paràmetre implícit.
    */
    Cromosoma cromosomes;


    /** @brief set amb els noms dels trets que el paràmetre implícit manifesta.
    */
    set<string> trets;


};

#endif //PRACTICA_INDIVIDU_HH
