#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

/*
 INDICE:
    VARIABILI GLOBALI E STRUTTURE:23
    FUNZIONI
        1) INIZIALIZZA:37
        2) INSERIMENTO:45
        3) STAMPA:64
        4) RICERCA:83
    INTERFACCE ALLE FUNZIONI
        1) INSERIMENTO: 117

(per maggiori informazioni leggi la guida inclusa nella cartella docs)

*/

/*---------------------------- VARIABILI GLOBALI E STRUTTURE ------------------------------------------------------- */
    struct cem
     //questa struct CEM (Closed EleMent) memorizza i dati relativi al nome dello studente
    //e al suo voto di verbalizzazione dell'esame.
    {
        int key;
        string nome;
        string cognome;
        int voto;
        cem* psucc;
    };

    typedef cem* lista; //quando bisogna dichiarare un puntatore al successivo della lista, basta dichiarare lista nomepuntatore;

/* --------------------------------------- FUNZIONI -------------------------------------------------------------------*/
    void tabellachiusa_inizializza(lista vettore[], int b)
    {
        //FUNZIONE CHE INIZIALIZZA LA TABELLA CHIUSA, SETTANDO A NULL TUTTI I SUOI ELEMENTI.
        for (int i=0; i<b; i++)
            {
            vettore[i]=NULL;
            }
    }
     lista tabellachiusa_inserimento(lista& inizio, int key,string nome,string cognome,int voto){
    //FUNZIONE CHE INSERISCE L'ELEMENTO IN CODA. RICEVE LA TESTA DELLA LISTA E I DATI DA INSERIRE.
    lista p,q; //dichiara due puntatori
    if (inizio!=0) //inizio è il puntatore di testa, contenuto nella tabella hash
        {
        for(q=inizio;q!=0;q=q->psucc)p=q; //se inizio è diverso da 0, allora scorro tutta la lista. Alla fine avrò che il puntatore
                                         // p punta all'ultimo elemento, mentre q a NULL
        }
        q=new cem; //a q assegna un nuovo elemento di tipo cem
        q->nome=nome; //inserisce i dati.
        q->cognome=cognome;
        q->voto=voto;
        q->key=key;
        q->psucc=0;
        if(inizio==0) inizio=q; //se inizio era 0, allora q viene assegnato ad inizio (q ed inizio sono due puntatori)
        else p->psucc=q; //altrimenti, al puntatore contenuto nell'ultimo elemento viene assegnato l'indirizzo di q.
    return inizio;
    }

    void stampalista(lista p[],int b) //stampa tutta la tabella hash
{
    for (int i=0; i<b; i++){ //primo ciclo for che effettua n operazioni per ogni numero di bucket
        if (p[i]!=0){ //se esiste una lista nell'elemento i-esimo, allora stampa tutta la lista.
        cout << "================" << endl;
        cout << "   Indice:  " << i << endl;
        cout << "================" << endl;
        }
        cem* n=p[i];
        //se l'elemento i-esimo è 0, salta automaticamente il ciclo while, perchè 0 e NULL sono interpretati nella stessa maniera.
        while (n!=NULL){ //scorre tutta la lista, fino a quando non trova l'ultimo elemento che ha puntatore null
            cout << "----------------------" << endl;
            cout << "| chiave  : " << n->key << endl <<  "| nome    : " << n->nome  << endl << "| cognome : " << n->cognome  << endl << "| voto    : " << n->voto  << endl;
            cout << "----------------------" << endl;
            n=n->psucc;
        }
    }
}

void tabellachiusa_ricerca(lista p[],int b) //esegue la ricerca dell'elemento su lista
{
    int ksrc; //dichiaro la variabile che conterrà la chiave da cercare
    int i; //dichiaro un indice che ospiterà la funzione di hash

    cout <<"Inserisci la chiave da cercare" << endl;
    cin >> ksrc;
    i= fhash(ksrc, b); //ad i inserisco il risultato della funzione di hash
    cem* n=p[i]; //dichiaro un puntatore a cui assegno la testa della lista
        do
        {
            if (n==0)
                {
                cout << " ---------------------------" << endl;
                cout << "|   La chiave non esiste!   |" << endl; //se n=0 allora il valore non esiste (o la testa della tabella è 0, oppure è arrivato alla fine della lista senza trovare nulla)
                cout << " ---------------------------" << endl;
                }
        	if (n != 0)
                {
                if (n->key == ksrc) //se la chiave corrisponde a quella inserita
                {
                    //stampo l'elemento
                      cout << "----------------------" << endl;
                      cout << "| chiave  : " << n->key << endl <<  "| nome    : " << n->nome  << endl << "| cognome : " << n->cognome  << endl << "| voto    : " << n->voto  << endl;
                      cout << "----------------------" << endl;
                    return;
                }
                n=n->psucc; //scorro la lista
        	}
        }
	    while (n!=NULL); //eseguo il while fin quando il puntatore non è null
}

/* --------------------------------------- INTERFACCE -------------------------------------------------------------------*/
void tabellachiusa_inserisci(lista tabella[],int b){

    int ktemp; //dichiaro chiave temporanea
    int index;
    cout << "inserisci una chiave" << endl;
    cin>> ktemp;
    index=fhash(ktemp,b); //applico la funzione di hash sulla chiave
    string nome;
    string cognome;
    int voto;
    cout << "inserisci un nome" << endl;
    cin >> nome;
    cout << "inserisci un cognome" << endl;
    cin >> cognome;
    cout << "Inserisci il voto dello studente " << nome << " " <<cognome << endl;
    cin >>voto;
    lista inizio=tabella[index];
    tabella[index]=tabellachiusa_inserimento(inizio,ktemp,nome,cognome,voto); //all'interno della tabella inserisco sempre il puntatore di testa della tabella
    return;

}


