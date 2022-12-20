#include<stdio.h>
#include<math.h>

int RicercaDicotomica(int vett[], int dimVett, int valRicerca);

int main(){
    int i, dimV, val;
    
    do{
        printf("quanti spazi vuoi creare dentro il vettore? \n"
        "(verra' rimepito con numeri da 0 a n-1) \n>>");
        scanf("%d",&dimV);
    }while(dimV==0 && printf("\t*non puoi creare un vettore di 0 spazi* \n\n"));

    int vett[dimV];
    
    for(i=0;i<dimV;i++){
        vett[i]=i;
    }
   
    printf("Inserisci il valore da ricercare \n>>");
    scanf("%d",&val);
    
    if(RicercaDicotomica(vett,dimV,val)==-1){
        printf("il valore non e' presente all'interno del vettore \n");
    }else{
        printf("il valore e' presente nella posizione: %d", RicercaDicotomica(vett,dimV,val));
    }

    return 0;
}
 
int RicercaDicotomica(int vett[], int dimVett, int valRicerca){
        //temp tiene conto della dimensione del vettore
        int i,j,temp=dimVett,pos=dimVett-1;
 
        /*se il valore è maggiore dell'ultima posizione o minore 
        non può trovarsi all'interno del vettore, quindi della prima termina la ricerca*/
        if(valRicerca<vett[0]||valRicerca>vett[pos]){ return -1; }
 
        //la posizione da esaminare si posiziona in automatico a metà del vettore
        pos/=2;
 
        //per usare questa funzione necessita della libreria math.h
        //logaritmo in base 2 arrotondato per eccesso di dimVett
        j=(log10(dimVett)/log10(2));
        j++;
 
        //la ricerca dicotomica viene sempre eseguita al massimo j volte
        for(i=0;i<=j;i++){  
            if(dimVett%2!=0){dimVett++;}
            //di quanti spazi si deve spostare pos
            dimVett/=2;

            //verifica se lo spazio esaminato contiene il val cercato
            if(valRicerca==vett[pos]){
                return pos;
            }else if(valRicerca<vett[pos]){
                pos-=dimVett;
                //impedisce al codice di esaminare spazi di memoria non appartenenti al vettore
                if(pos<0){pos=0;}
            }else{
                pos+=dimVett;
                //impedisce al codice di esaminare spazi di memoria non appartenenti al vettore
                if(pos>=temp){pos=temp-1;}
            }
        }
        return -1;
    }
