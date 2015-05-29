#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 INDICE:
    VARIABILI GLOBALI E STRUTTURE:23
    FUNZIONI:
        1) INIZIALIZZA:35
        2) INSERIMENTO:43
        3) STAMPA:64
        4) RICERCA:70
    INTERFACCE ALLE FUNZIONI:
        1) INSERIMENTO:106
        2) RICERCA:126
(per maggiori informazioni leggi la guida inclusa nella cartella docs)

*/

/*---------------------------- VARIABILI E STRUTTURE -------------------------------*/
struct oem
     //questa struct OEM (Open EleMent) memorizza i dati relativi al nome dello studente
    //e al suo voto di verbalizzazione dell'esame.
    {
        int key;
        string nome;
        string cognome;
        int voto;
    };

 /*---------------------------- FUNZIONI -------------------------------*/

 void tabellaaperta_inizializza(oem vettore[], int n) //FUNZIONE CHE INIZIALIZZA LA TABELLA APERTA, SETTANDO A 0 TUTTI I SUOI ELEMENTI.
{
    for (int i=0; i<n; i++){
        vettore[i].key=0;
        vettore[i].nome="";
        vettore[i].voto=0;
    }
}
void tabellaaperta_inserimento(int i, oem vettore[], int ktemp, int numero) //gestisce l'inserimento nella tabella aperta
{
    if (i >= numero){ i=i-numero; } //QUESTO IF CONTROLLA CHE IL NUMERO GENERATO DAL BUCKET NON SIA MAGGIORE DI N.

                                    // SE I>N ALLORA AD I VIENE SOTTRATTO N, IN MODO DA RINIZIARE A SCORRERE IL VETTORE.

        if (vettore[i].key==0){     //SE L'ELEMENTO DEL VETTORE È VUOTO, VENGONO RICHIESTI I CAMPI E VIENE INSERITO NELL'INDICE F(H)
            vettore[i].key=ktemp;
            cout << "inserisci il nome" << endl;
            cin >> vettore[i].nome;
            cout << "inserisci il cognome" << endl;
            cin >> vettore[i].cognome;
            cout << "inserisci il voto di " << vettore[i].nome << " " << vettore[i].cognome << endl;
            cin >> vettore[i].voto;
        }
        else{   //SE L'ELEMENTO è GIA OCCUPATO, INCREMENTA IL CONTATORE E RICHIAMA LA FUNZIONE. PER QUESTO SCOPO, È UTILE IL CONTROLLO AD INIZIO FUNZIONE (I >N )
                i++;
                tabellaaperta_inserimento(i, vettore, ktemp, numero);
        }

}
void tabellaaperta_stampa(oem ta[],int n)
{
            cout << "*) key | nome | cognome | voto" << endl;
            for (int i=0; i<n; i++) //la stampa va da 0 a n, perchè i resti saranno SEMPRE compresi tra 0 e N.
            cout << i << ") " << ta[i].key << " | " << ta[i].nome << " | " << ta[i].cognome << " | " << ta[i].voto << endl;
}
void tabellaaperta_search(int i, int c, oem ta[], int n, int ktemp) //FUNZIONE RICORSIVA DI RICERCA SU TABELLA APERTA
{
    if (i>n) i=i-n; //controlla che il risultato dell'hash sia minore del numero n di elementi. se maggiore, allora ad i sottrae n.

    if (ktemp==0)
        {
        cout << "Valore non trovato" << endl;
        return;
        }
    if (ktemp==ta[i].key)
    {

        //cerca se la chiave si trova nella posizione ottenuta dall'hashing. se la trova, la stampa.
        cout << "*) | Chiave | Nome | Cognome | Voto" << endl;
        cout << i << ") " << ta[i].key << " | " << ta[i].nome << " | " << ta[i].cognome << " | " << ta[i].voto << endl;
    }
    else
    {
        //la chiave non è stata trovata in quella posizione, dunque va a scorrere il vettore
        //c è un contatore che conta il numero di elementi controllati. se è uguale ad n, significa che ha controllato tutti gli elementi ma non ha trovato mai la chiave, e quindi esce.
        if (c==n)
        {
            cout << "Il tuo elemento non esiste"<< endl;
        }
        else
            {
                //incrementa l'indice di 1. (se supera n, allora verrà normalizzato alla nuova esecuzione)
                //incrementa c, il contatore degli scorrimenti
                i++;
                c++;
                tabellaaperta_search(i, c, ta, n, ktemp); //richiama la funzione, con il parametro i e c modificati. Ktemp, ta ed n rimangono sempre uguali in tutte le ricorsioni.
            }
    }
}
/*---------------------------- INTERFACCE  -------------------------------*/

void tabellaaperta_inserisci(oem ta[], int n,int b) //INTERFACCIA, RICEVE COME PARAMETRI LA TABELLA, IL NUMERO DI ELEMENTI E IL NUMERO DI BUCKET
{
for (int i=0; i<n; i++) // inserisce n elementi nella tabella.
        {
        int ktemp; //viene memorizzata la chiave in una variabile temporanea
        int index;
        do
        {
            cout << "inserisci la chiave (deve essere DIVERSA da 0)" << endl;
            cin >> ktemp;

        }
        while(ktemp==0);

        index=fhash(ktemp,b); //genero l'hash della chiave
        tabellaaperta_inserimento(index,ta,ktemp,n); //ESEGUE IL VERO INSERIMENTO NELLA TABELLA
        cout << "Inserimento avvenuto con successo." << endl;

        }
}
void tabellaaperta_ricerca(oem ta[], int n) //INTERFACCIA DELLA RICERCA. RICEVE LA TABELLA E IL NUMERO DI ELEMENTI
{
            int ktemp;
            int i=0;
            int c=0;
            cout << "Inserisci la chiave da ricercare" << endl;
            cin >> ktemp;
            tabellaaperta_search(i, c, ta, n, ktemp); //ESEGUE LA RICERCA
}
