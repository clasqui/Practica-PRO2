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

    També conté els ids dels progenitors, si els té.

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
      \pre Rep el numero de gens que han de tenir els cromosomes.
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

    /** @brief Consulta els id dels progenitors
      \pre <em>Cert</em>
      \post Retorna un parell d'enters amb els ids dels progenitors
    */
    pair<int, int> consul_progenitors() const;

    /** @brief Imprimeix els trets
     \pre <em>Cert</em>
     \post Mostra els trets d'aquell individu ordenats alfabèticament
   */
    void mostra_trets() const;

    /** @brief Afegeix un tret
     * Enllaça un tret amb el paràmetre implícit
     * \pre Rep un punter a un tret
     * \post El paràmetre implícit ara conté el tret a la llista
     */
    void afegeix_tret(string);

    /** @brief Elimina un Tret t del paràmetre implícit.
     * \pre Rep un punter a un tret
     * \post El paràmetre implícit ara no conté aquest tret al set de Trets.
     */
    void elimina_tret(string);



private:

    /** @brief Cromosomes de l'individu
    */
    Cromosoma cromosomes;


    /** @brief parell amb els ids dels progenitors, si en té
    */
    pair<int, int> progenitors;

    /** @brief set amb els noms dels trets que es manifesten en aquest individu
    */
    set<string> trets;


};

#endif //PRACTICA_INDIVIDU_HH
