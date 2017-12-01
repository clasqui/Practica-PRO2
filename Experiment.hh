/** @file Experiment.hh
    @brief Especificació de la classe Experiment
*/

#ifndef PRACTICA_EXPERIMENT_HH
#define PRACTICA_EXPERIMENT_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <string>
#endif

#include "Individu.hh"
#include "Tret.hh"

using namespace std;


/** @brief Tipus Registre d'individus.<br>
 * El tipus RegistreIndividus és un mapa en el qual la clau és l'<em>id</em> de l'individu i el valor es un objecte de la classe Individu
    */
typedef vector <Individu> RegistreIndividus;

/** @brief Tipus Registre de Trets.<br>
 * El tipus RegistreTrets és un mapa en el qual la clau és el nom del tret i el valor es un objecte de la classe Tret
    */
typedef map <string, Tret> RegistreTrets;

/** @class Experiment
    @brief Representa un experiment amb els individus i els trets que estem estudiant.

    Conté, en un map, tots els individus de l'experiment, i en un altre map els trets de l'experiment

*/
class Experiment {
public:

    //Constructores

    /** @brief Constructora budia.

        S'executa automàticament en declarar un Experiment.
        \pre <em>Cert</em>
        \post Exeriment buit inicialitzat.
    */
    Experiment();

    /** @brief Constructora per defecte.

        S'executa automàticament en declarar un Experiment amb els valors n i m.
        \pre Rep un nombre d'individus n >= 3 i un nombre de gens per cada cromosoma m >= 1
        \post El resultat és un Experiment nou amb els paràmetres <em>n</em> i <em>m</em> inicialitzats.
    */
    Experiment(int n, int m);

    /** @brief Consulta el nombre de gens dels cromosomes de cada individu
      \pre <em>Cert</em>
      \post Retorna el paràmetre m
    */
    int consul_m() const;

    /** @brief Llegeix l'arbre genealògic dels individus i a continuació llegeix els cromosomes dels individus
      \pre <em>Cert</em>
      \post El paràmetre implícit ara conté un mapa amb els individus
    */
    void llegeix_experiment();

    /** @brief Afegeix un tret a un individu.
      \pre Rep el nom del tret i l'id de l'individu al que li afegirà
      \post El paràmetre implícit ara conté el nou tret al registre de trets, si no existia.
    */
    void afegeix_tret(string nom, int id);


    /** @brief Elimina un tret a un individu.
      \pre Rep el nom del tret i l'id de l'individu al qual ja no es manifesta
      \post Si aquest tret no es manifesta a cap mes individu després d'aquest procediment, s'elimina del registre de trets.
    */
    void treu_tret(string nom, int id);

    /** @brief Consulta un tret.
      \pre Rep el nom del tret que es vol consultar
      \post Es mostra la combinacio que fa que es manifesti aquest tret i els ids del individus en els quals es manifesta
    */
    void consulta_tret(string nom);


    /** @brief Consulta un individu.
      \pre Rep l'id de l'individu que es vol consultar
      \post Es mostra els cromosomes de l'individu i els trets que es manifesten en aquest individu
    */
    void consulta_individu(int id);

    /** @brief Consulta la distribució d'un tret
     \pre <em>Rep el nom del tret</em>
     \post Imprimeix l'arbre genealogic en inordre amb els indvidus, dient en cada cas si es manifesta o no.
   */
    void distribucio_tret(string nom);



private:

    /** @brief Nombre d'individus de l'experiment
    */
    int n;

    /** @brief Nombre de gens de cada individu
    */
    int m;

    /** @brief El Registre dels individus amb els quals treballem en aquest experiment.<br> 
     *  En aquest mapa estan indexats pel seu identificador <em>1 <= id <= n</em>
    */
    RegistreIndividus individus;

    /** @brief El Registre dels trets amb els quals treballem en aquest experiment.<br>
     *  En aquest mapa estan indexats pel seu nom
    */
    RegistreTrets trets;
    
    /** @brief Objecte de tipus arbre que representa la familia d'individus amb la qual treballem en aquest experiment
     * 
     */
    

};


#endif //PRACTICA_EXPERIMENT_HH
