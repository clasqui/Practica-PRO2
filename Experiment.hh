/** @file Experiment.hh
    @brief Especificació de la classe Experiment
*/

#ifndef PRACTICA_EXPERIMENT_HH
#define PRACTICA_EXPERIMENT_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#include <string>
#include <map>
#endif

#include "Individu.hh"
#include "Tret.hh"
#include "Familia.hh"

using namespace std;


/** @brief Tipus Registre d'individus.<br>
 * El tipus RegistreIndividus és un vector en el qual elements de la classe Individu es troben en la posició <em>id</em> del vector.
    */
typedef vector<Individu> RegistreIndividus;

/** @brief Tipus Registre de Trets.<br>
 * El tipus RegistreTrets és un map en el qual la clau és el nom del tret i el valor es un objecte de la classe Tret
    */
typedef map<string, Tret> RegistreTrets;

/** @class Experiment
    @brief Representa un experiment amb els individus i els trets que estem estudiant.

    Conté, en un vector, tots els individus de l'experiment, i en un altre map els trets de l'experiment

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
      \post Si aquest tret no es manifesta a cap mes individu després d'aquest procediment, s'elimina del RegsitreTrets <em>trets</em>.
    */
    void treu_tret(string nom, int id);

    /** @brief Consulta un tret.
      \pre Rep el nom del tret que es vol consultar
      \post Es mostra la combinacio que fa que es manifesti aquest tret i els ids del individus en els quals es manifesta en ordre creixent per <em>id</em>. Si no existeix escriu "error".
    */
    void consulta_tret(string nom);


    /** @brief Mostra un individu.
      \pre Rep l'id de l'individu que es vol consultar
      \post Es mostren els cromosomes de l'individu i els trets que es manifesten en aquest individu ordenats alfabèticament.
    */
    void consulta_individu(int id);

    /** @brief Mostra la distribució d'un tret
     \pre <em>Rep el nom del tret</em>
     \post Imprimeix el subarbre genealògic en inordre amb els camins a tots els individus que manifesten aques tret. <br>Si pel camí hi ha trets que no manifesten el tret els mostrarem amb l'<em>id</em> canviat de signe.
   */
    void distribucio_tret(string nom);



private:

    /** @brief Nombre d'individus de l'experiment
    */
    int n;

    /** @brief Nombre de gens que tenen els cromosomes dels individus.
    */
    int m;

    /** @brief El Registre dels individus amb els quals treballem en aquest experiment.<br> 
     *  En aquest vector els objectes de la classe Individu estan indexats pel seu identificador <em>1 <= id <= n</em>
     *  Això fa que la posició <em>individus[0]</em> sigui buida sempre.
    */
    RegistreIndividus individus;

    /** @brief El Registre dels trets amb els quals treballem en aquest experiment.<br>
     *  En aquest mapa els objectes de a classe Tret estan indexats pel seu nom.
    */
    RegistreTrets trets;
    
    /** @brief Objecte de tipus arbre que representa la familia d'individus amb la qual treballem en aquest Experiment.
     *
     */
     Familia familia;

    /** @brief Recalcula la intersecció dels gens que fan que es manifesti un Tret t
     * Cridem aquesta funció només quan el càlcul s'ha de fer perquè s'ha afegit un individu, ja que és molt més fàcil i menys costós.
     *
     * @param t Referència al Tret que hem de recalcular
     * @param id ID de l'individu que estem afegint a la intersecció
     * \pre Rep un Tret t per referència i un id d'un individu 1 <= id <= n
     * \post El Tret t ara conté la intersecció de gens que fan que es manifesti correctament
     */
    void recalcular_tret_addicio(Tret &t, int id);

    /** @brief Recalcula la intersecció dels gens que fan que es manifesti un Tret t
     *  Cridem aquesta funció només quan el càlcul s'ha de fer perquè s'ha eliminat el tret en un indvidu.
     *
     * @param t Referència al Tret que hem de recalcular
     * \pre Rep un Tret t per referència
     * \post El Tret t ara conté la intersecció de gens que fan que es manifesti correctament
     */
    void recalcular_tret_supressio(Tret &t);
    

};


#endif //PRACTICA_EXPERIMENT_HH

