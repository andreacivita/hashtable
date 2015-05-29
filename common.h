#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


/* INDICE FUNZIONI
 PRIMO:14
 CALCOLO DEL BUCKET:44
 FUNZIONE BUCKET E PRIMO:57
 FHASH:70
 OPERAZIONE:78
*/
void primo(int primi[], int sup){
    //QUESTA FUNZIONE PRENDE COME PARAMETRI: UN VETTORE VUOTO(CHE OSPITA I NUMERI PRIMI GENERATI) E UN ESTREMO SUPERIORE, CHE VIENE USATO
    //COME LIMITE
    primi[0]=1;
    primi[1]=2;
    primi[2]=3;
    //AGGIUNGE NEL VETTORE I NUMERI PRIMI 1,2,3
    int contatore=3;
    bool cond=true;
    for (int i=5; i<sup; i++){ //I RAPPRESENTA IL NUMERO DA TESTARE, J IL DIVISORE. J PARTE DA DUE ED ARRIVA A I-1.
        cond=true; //la condizione permette di entrare nel ciclo while e di girare fino a quando un numero non è primo.
         int j=2;
        while(j<i && cond==true)
        {
            int r=i%j;
            if ( r == 0) {
                cond=false; //se è stato trovato un divisore tra 2 e n-1, i non è primo. I per essere primo deve essere divisibile solo
                            //per 1 e n.
            }
        j++; //incremento del denominatore
        }
        if (cond==true)
        {
            primi[contatore]=i; //se si è usciti dal ciclo while (j=1), allora il numero è primo e viene aggiunto nel vettore.
            contatore++;
        }
    }
}
/*-----------------------------------------------------------------------------------------------------------------*/
int calcola_bucket(int n, int primi[], int ext){ //FUNZIONE CHE CALCOLA IL NUMERO DI BUCKET DA IMPIEGARE. RESTITUISCE COME RISULTATO IL
                                        // NUMERO STESSO. PRENDE COME PARAMETRI IL NUMERO N DI ELEMENTI, IL VETTORE DEI NUMERI
                                        //PRIMI E UN CAMPO EXT CHE RAPPRESENTA LA DIMENSIONE DEL VETTORE DEI PRIMI
int b=0;
n=n*2; //n viene raddoppiato per mantenere il fattore di carico a max 0.50 (m=f*n => f=n/m)
for (int i=0; i<ext; i++){
        if (primi[i]>n){ //fin quando il numero primo è inferiore ad n, viene ignorato. il primo numero primo successivo ad N viene utilizzato come
            b=primi[i];  //numero di bucket
            return b;
    }
}
return b;
}
/*------------------------------------------------------------------------------------------------------------*/
int bucket(int n){
int b=0;
int ext =n * 3; //moltiplico n*3, in modo da avere un limite superiore =3 * n
int numeriprimi[ext]; //dichiaro un vettore di numeriprimi
primo(numeriprimi, ext); //calcolo i numeri primi fino a 3*n
b=calcola_bucket(n,numeriprimi,ext);
return b;
}
/*--------------------------------------------------------------------------------------------------------------------------*/
int fhash(int key, int b) //funzione di hash. Prende come parametri la chiave primaria (matricola) e il numero di bucket.
{
int hk;
hk= key%b; //calcola il resto della divisione tra chiave e numero di bucket. Tale resto va utilizzato come indice della tabella hash.
return hk;
}
/*---------------------------------------------------------------------------------------------------------------------*/

bool operazione(string param) { //QUESTA FUNZIONE VIENE UTILIZZATA PER GESTIRE LE SCELTE DELL'UTENTE NELL'INSERIMENTO E NELLA RICERCA
if (param=="ricerca") //PARAMETRO CHE PERMETTE DI GESTIRE I CASI, PASSATO DIRETTAMENTE ALLA FUNZIONE
{
    string s;
    cout << "Vuoi effettuare una ricerca sulla tabella? [s/n]" << endl; //DICHIARA UNA VARIABILE CHE CONTIENE LA RISPOSTA.
    cin >> s;
    if (s=="s"){ //SE LA RISPOSTA È POSITIVA, RESTITUISCE TRUE, ALTRIMENTI FALSE
        return true;
    }
    else
    {
        return false;
    }
}

if (param=="inserimento"){
    string s;
    cout << "Vuoi inserire un nuovo elemento? [s/n]" << endl;
    cin >> s;
    if (s=="s"){
        return true;
    }
    else
    {
        return false;
    }
}
if (param=="stampa"){
    string s;
    cout << "Vuoi controllare la tabella? [s/n]" << endl;
    cin >> s;
    if (s=="s"){
        return true;
    }
    else
    {
        return false;
    }
}
return false;
}
