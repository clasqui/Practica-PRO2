/** @file Experiment.cc
 *  @brief Implementació de la classe Experiment
 */

#include "Experiment.hh"
#include <cassert>

Experiment::Experiment() {
}

Experiment::Experiment(int n, int m) {
    this->n = n;
    this->m = m;
}

int Experiment::consul_m() const {
    return this->m;
}

void Experiment::llegeix_experiment() {
    vector<Individu> aux = vector<Individu>(n+1);

    // Llegim primer la familia i la posem a l'arbre
    this->familia = Familia();
    this->familia.llegeix_familia(aux);

    // cout << "DEBUG::EXPERIMENT::llegeix_experiment(): num individus: " << aux.size() << endl;


    // Ara llegim la informació genètica de cada individu
    for (int i = 1; i <= n; ++i) {
        // cout << "DEBUG::EXPERIMENT::llegeix_experiment(): llegim individu " << i << endl;
        aux[i].llegeix_individu(m);
    }

    // El vector, tot ple, el posem al registre d'individus
    this->individus = aux;
}

void Experiment::consulta_individu(int id) {
    Individu i = this->individus[id];
    i.mostra_cromosomes();
    // Ara imprimim els trets
    i.mostra_trets();

}

void Experiment::afegeix_tret(string nom, int id) {
    Tret t;
    // Primer comprovem si existeix
    map<string, Tret>::iterator result = this->trets.find(nom);
    if(result != this->trets.end()) {
        // Existeix
        t = this->trets[nom];

        // Comprovem si ja es manifesta en aquell individu
        if(t.es_manifesta(id)) {
            cout << "  error" << endl;
            return;
        }
    } else {
        t = Tret(nom, this->m);
    }
    // Enllacem un amb l'altre (posem el id del individu al tret, i una referencia del tret al individu)
    t.afegeix_manifestacio(id);
    this->individus[id].afegeix_tret(&t);

    // Recalculem la intersecció
    recalcular_tret_addició(t, id);


    //Quan hem acabat, posem el tret al registre un altre cop
    this->trets[nom] = t;
}

void Experiment::consulta_tret(string nom) {
    Tret t;
    map<string, Tret>::iterator result = this->trets.find(nom);
    if(result == this->trets.end()) {
        cout << "  error" << endl;
    } else {
        cout << "  " << nom << endl;
        t = (*result).second;
        t.mostra_interseccio();
        t.mostra_individus();
    }
}

void Experiment::treu_tret(string nom, int id) {
    // TODO No comprovem primer si el tret no existeix en general?
    // Comprovem si el tret existeix en l'individu donat
    if (!trets[nom].es_manifesta(id)) {
        cout << "  error" << endl;
    } else {
        // Eliminem l'enllaç entre el tret i l'individu
        bool eliminar = trets[nom].treu_manifestacio(id);
        individus[id].elimina_tret(&trets[nom]);

        // Ara comprovem si hem d'eliminar tot rastre d'aquest tret
        if (eliminar) {
            trets.erase(nom);
        } else {
            recalcular_tret_supressio(trets[nom]);
        }
    }
}

void Experiment::distribucio_tret(string nom) {
    Tret t;
    map<string, Tret>::iterator result = this->trets.find(nom);
    if(result == this->trets.end()) {
        cout << "  error" << endl;
    } else {
        t = (*result).second;
        
    }
    
}

//Funcions Privades
void Experiment::recalcular_tret_addició(Tret &t, int id) {
    Cromosoma c = individus[id].consul_cromosomes();
    t.recalcular_interseccio(c);
}



void Experiment::recalcular_tret_supressio(Tret &t) {
    // Reinicialitzem la intersecció del tret
    t.buida();

    // Iterem amb els cromosomes de tots els individus del tret
    list<int> li = t.consulta_individus();
    list<int>::iterator it;
    for (it = li.begin(); it != li.end(); ++it) {
        Cromosoma c = individus[*it].consul_cromosomes();
        t.recalcular_interseccio(c);
    }
}
