/** @file Cromosoma.hh
    @brief Especificació de la classe Cromosoma
*/

#ifndef PRACTICA_CROMOSOMA_HH
#define PRACTICA_CROMOSOMA_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

using namespace std;

/** @class Cromosoma
    @brief Representa un parell de cromosomes, amb els seus gens

*/
class Cromosoma {
public:

    //Constructores

    /** @brief Constructora per defecte.
        S'executa automàticament en declarar un Cromosoma.

        \pre <em>Cert</em>
        \post El resultat és un Cromosoma nou.
    */
    Cromosoma();

    /** @brief Constructora per defecte.
        Llegeix els gens del parell de cromosomes.
        S'executa automàticament en declarar un Cromosoma.

        \pre Dues sèries de m gens a l'entrada estàndard
        \post El resultat és un Cromosoma nou.
    */
    Cromosoma(const int m);


    /** @brief Consulta els gens amb l'index i
      \pre 0 <= i <= li
      \post Retorna el parell de gens en la posició i del cromosoma
    */
    pair<int, int> consul_gen(int i) const;

    /** @brief Consulta el cromosoma segons el codi
      \pre codi = {0, 1}
      \post Retorna el primer cromosoma si el codi es 0 o el segon cromosoma si el codi es 1
    */
    vector<int> consul_cromosoma(int codi) const;

    /** @brief Imprimeix els gens del cromosoma segons el codi
      \pre codi = {0, 1}
      \post Imprimeix els gens del primer cromosoma si el codi es 0 o del segon cromosoma si el codi es 1
    */
    void imprimeix_cromosoma(int codi) const;



private:
    /** @brief Helper function que converteix els caracters de l'entrada estandard en int 1 o 0
     *
     */
    int convert_char_int(char c);
    /** @brief Vector de gens del primer cromosoma del parell
     *
     */
    vector<int> c1;

    /** @bref Vector de gens del segon cromosoma del parell
     *
     */
    vector<int> c2;
};

#endif //PRACTICA_CROMOSOMA_HH