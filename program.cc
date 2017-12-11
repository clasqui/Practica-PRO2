/**
 * @mainpage Implementació de la pràctica:  Aplicació per a un laboratori de biologia

 Aquesta pràctica és un disseny modular que permet fer experiments en un laboratori per tal de relacionar els trets dels individus amb els gens.

*/

/** @file main.cc
    @brief Programa principal de la pràctica <em>Aplicació per a un laboratori de biologia</em>.
*/
#include "Experiment.hh"

#ifndef NO_DIAGRAM
#include <string>
#endif

using namespace std;

int main() {

    Experiment experiment;

    string comm;
    cin >> comm;

    while(comm != "fi") {
        cout << comm;
        if (comm == "experiment") {
            int n, m;
            cin >> n >> m;
            cout << " " << n << " " << m << endl;
            experiment = Experiment(n, m);
            experiment.llegeix_experiment();

        }
        if (comm == "afegir") {
            string nom;
            int id;
            cin >> nom >> id;
            cout << " " << nom << " " << id << endl;
            experiment.afegeix_tret(nom, id);

        }
        if (comm == "treure") {
            string nom;
            int id;
            cin >> nom >> id;
            // experiment.treu_tret(nom, id);

        }
        if (comm == "consulta_tret") {
            string nom;
            cin >> nom;
            cout << " " << nom << endl;
            experiment.consulta_tret(nom);

        }
        if(comm == "consulta_individu") {
            int id;
            cin >> id;
            cout << " " << id << endl;
            experiment.consulta_individu(id);

        }
        if(comm == "distribucio_tret") {
            string nom;
            cin >> nom;
            // experiment.distribucio_tret(nom);
        }

        cin >> comm;
    }

    cout << "fi" << endl;

}