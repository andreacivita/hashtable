#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "common.h"
#include "tabellaaperta.h"
#include "tabellachiusa.h"

using namespace std;

int main()
{

    int n=0; //n= numero di elementi da memorizzare nella tabella
    int b=13; //numero di bucket per tabella hash ad inserimento chiuso
    cem* tc[b];
    tabellachiusa_inizializza(tc,b);
    int scelta;
    do{
    do {
    system("cls");
    cout << "==============================" << endl;
    cout << "Tabelle Hash (chiuse e aperte)" << endl;
    cout << "==============================" << endl;
    cout << "1) Gestione Tabella Hash ad inserimento aperto" << endl;
    cout << "2) Gestione Tabella Hash ad inserimento chiuso" << endl;

    cin >> scelta;
    if (scelta==1){
        cout << "Inserisci il numero di elementi da memorizzare" << endl;
        cin >> n;
        b=bucket(n); //assegno a b il numero di bucket (vedi common.h per maggiori informazioni)
        oem ta[b]; //tabella hash aperta che conterrà elementi OEM (vedi dichiarazione struct OEM per maggiori dettagli)
        tabellaaperta_inizializza(ta,n); //la tabella viene inizializzata
        tabellaaperta_inserisci(ta,n,b);
        bool cond=operazione("stampa"); //possibilità di stampare la tabella di hash
        if (cond==true) //se cond è vera, stampa la tabella
        {
            tabellaaperta_stampa(ta,n);
        }
        bool ricerca;
        do
        {
            ricerca=operazione("ricerca"); //chiede all'utente se vuole effettuare una ricerca
            if (ricerca==true)
            {
            tabellaaperta_ricerca(ta,n); //esegue la ricerca dell'elemento
            }
        }
        while (ricerca==true);
        system("pause"); //mette in pausa il programma (messaggio: premere un tasto per continuare)
        }
        if (scelta == 2) {
        //tabella chiusa
        bool ins;
        do{
         tabellachiusa_inserisci(tc,b); //questa procedura si occupa di gestire l'intero inserimento nella tabella (Input dei dati, hash della chiave, inserimento in coda)
         ins=operazione("inserimento"); //chiede all'utente se vuole inserire un nuovo elemento (operazione() è una funzione booleana)
        //termina il ciclo while, se ins è falsa il ciclo NON verrà rieseguito.
        }
        while (ins==true);
        bool print=operazione("stampa"); //chiedo all'utente se vuole stampare la lista
        if (print==true)
            { //se il risultato è vero, allora stampo, altrimenti non faccio nulla
            stampalista(tc,b);
            }

        bool ricerca=true; //creo una variabile booleana settata a true
        while (ricerca==true)
            {
                ricerca=operazione("ricerca"); //chiede all'utente se vuole effettuare una ricerca
                if (ricerca==true)
                {
                    tabellachiusa_ricerca(tc,b); //esegue la ricerca
                }
            }
        }
        }
    while (scelta !=1 || scelta !=2); //se viene inserito un numero che non corrisponde ad opzione, lo schermo viene cancellato e il menù viene stampato.
    system("cls");
    }
    while (true); //questo ciclo infinito impedisce all'utente di uscire dal programma digitando numeri o caratteri. Per uscire dovrà terminare manualmente il programma.
    return 0;
}
