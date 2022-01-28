// Autore : De Fabritiis Davide
// Classe 4INF1
//Versione Funzionante del Programmma Di Gestione Casse de Supermercato attraverso Liste

#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct s_cliente{												//Definizione Della Struttura Liste
	int info;
	struct s_cliente *next;
};
typedef struct s_cliente cliente;
typedef cliente *head;

//Funzioni
int ContaClienti(head lis);															 //Ritorna il N di Clienti nella Lista														
void StampaRicors(head lis);											
void StampaSituaz(head pl1,head pl2,head pl3);    			 //Stampa Le tre Liste rappresentani le Casse
void addclient(int state,head *pl1,head *pl2,head *pl3); //Funzione Che Gestisce l'ingresso di un nuovo cliente
void remclient(int state,head *pl1,head *pl2,head *pl3); //Funzione Che Gestisce l'uscita di un cliente
head SpostaPari(head pl1);                               //Sposta i Numeri di Posiz Pari (info>100)
void IncPari(head pl1);																	 //Incrementa di 100 i campi info di posiz pari
void DecAll(head pl2);																	 //Decrementa di 100 i campi info
head AnzianiPLN(head pl,head temp);                      //Individua e pone gli anziani trovati in una nuova lista 
head CombinaListe(head t1,head t2);                      //unisce le 2 liste

int main()
{
	head PL1=NULL;											//dichiaraz e Inizializzazione puntatori
	head PL2=NULL;
	head PL3=NULL;
	head temp=NULL;
	
	int n;														//utilizzatata per contenere il numero di elementi di PL1
	int m;														//utilizzatata per contenere il numero di elementi di PL2
	const int trigger=5;							// Numero di Clienti che fa triggerare gli eventi
	int state;												//contiene lo stato attuale
	int ora;													//Contiene la fascia Oraria
	int event;												//Contiene un numero che determina l'ingresoo o l'uscita di un cliente
	srand(time(NULL));
	state=0;
	
	do
	{
		printf("Selezionare la Fascia Oraria di Lavoro :\n");
		printf("1 - Mattina      : 50 IN - 50 OUT;\n");
		printf("2 - Notte        : 20 IN - 80 OUT;\n");
		printf("3 - Ora di Punta : 80 IN - 20 OUT;\n : ");
		scanf("%d",&ora);
		system("cls");
	}while((ora!=1)&&(ora!=2)&&(ora!=3));
	
	while (1)
	{
		event=evento(ora);
		if (event==1)
		  addclient(state,&PL1,&PL2,&PL3);
		else
		  remclient(state,&PL1,&PL2,&PL3);
		
		StampaSituaz(PL1,PL2,PL3);
	  
		if (state==0)
	  {
	  	n=ContaClienti(PL1);						//EVENTO 1 TRIGGERATO
	  	if (n==trigger)
	  	{
	  		state++;
	  		printf("\nATTENZIONE !!! WARNING !!!\n");
	  		printf("EVENTO 1 TRIGGERED ! APERTURA CASSA 2 !\nSPOSTAMENTO CLIENTI PARI !\n\n");
	  		IncPari(PL1);
	  		//StampaRicors(PL1);
	  		PL2=SpostaPari(PL1);
	  		//StampaRicors(PL2);
	  		DecAll(PL2);
	  		printf("Situazione Aggiornata !\n");
	  		StampaSituaz(PL1,PL2,PL3);
	  	}
	  }
	  
	  if (state==1)								//EVENTO 2 TRIGGERATO
	  {
	  	n=ContaClienti(PL1);
	  	m=ContaClienti(PL2);
	  	
	  	if ((n==trigger)||(m==trigger))
	  	{
	  		state++;
	  		printf("\nATTENZIONE !!! WARNING !!!\n");
	  		printf("EVENTO 2 TRIGGERED ! APERTURA CASSA 3 !\nSPOSTAMENTO ANZIANI 60+ !\n\n");
	  		PL3=AnzianiPLN(PL1,PL3);
	  		StampaRicors(PL3);
	  		printf("  Anziani Prima Fila\n");
	  		system("PAUSE");
	  		temp=AnzianiPLN(PL2,temp);						//NOTA: Se L'anziano si trova nella PRIMA posizione della cassa 1 o 2			
	  		StampaRicors(temp);										//Non verrà Considerato, piochè in ogni caso, non gli conviene cambiare cassa
	  		printf("  Anziani Seconda Fila\n");
	  		system("PAUSE");
	  		PL3=CombinaListe(PL3,temp);
	  		StampaRicors(PL3);
	  		printf("  Anziani Prima e Seconda Fila\n");
	  		printf("\nSituazione Aggiornata !\n");
	  		StampaSituaz(PL1,PL2,PL3);
	  	}
	  }
	  
	  system("PAUSE");
	  system("cls");
	}
	
printf("\n\n");

}

void StampaSituaz(head pl1,head pl2,head pl3){
	
	printf("Cassa 1 : ");
		StampaRicors(pl1);
		printf("\n");
		
		printf("Cassa 2 : ");
		StampaRicors(pl2);
		printf("\n");
		
		printf("Cassa 3 : ");
		StampaRicors(pl3);
		printf("\n");
}

void StampaRicors(head lis){
	if (lis!=NULL){
		printf("[%1d]->",lis->info);
		StampaRicors(lis->next);
	}
}

int evento(int ora){
																	
	int event;
	event=rand()%10+1;								//Viene generato un numero da 1 a 10 e a seconda della fascia oraria
		if(ora==1)											//E Viene determinato se entrerà o uscirà un cliente
		{
			if (event<=5)
			  event=1;
			else
			  event=2;
		} 
		if (ora==2)
		{
			if (event<=2)
			  event=1;
			else
			  event=2;
	  }
	  if (ora==3)
		{
			if (event<=8)
			  event=1;
			else
			  event=2;
	  }
	  if (event==1)
	    printf("EVENTO : Entra Un Cliente\n");
	  else
	    printf("EVENTO : Esce un Cliente\n");
	  return event;
	
}

void addclient(int state,head *pl1,head *pl2,head *pl3){
	
	head temp;																//Generazione nuovo Cliente 
	head PN;
	PN=(head)malloc(sizeof(cliente));
	PN->info=rand()%65+15;
	PN->next=NULL;
	
	if (state==0)										//Se lo stato è zero (Una sola cassa aperta) viene aggiunto un cliente
	{
		if (*pl1==NULL)
		  *pl1=PN;
		else
		{
			temp=*pl1;
			while(temp->next!=NULL)
			  temp=temp->next;
			temp->next=PN;
		}
	}
	
	if (state==1)							//Se lo stato è uno (due casse aperte) viene aggiunto un cliente alla fila più corta
	{
		temp=NULL;
		int n;
		int m;
		temp=*pl1;
		n=ContaClienti(temp);
		temp=*pl2;
		m=ContaClienti(temp);
		
		if (n<=m)
		{
			if (*pl1==NULL)
		 	 *pl1=PN;
			else
			{
				temp=*pl1;
				while(temp->next!=NULL)
				  temp=temp->next;
				temp->next=PN;
			}
		}
		else
		{
			if (*pl2==NULL)
		  	*pl2=PN;
			else
			{
				temp=*pl2;
				while(temp->next!=NULL)
				  temp=temp->next;
				temp->next=PN;
			}
		}
	}
	
	if (state==2)							//Se lo stato è 2 (tre casse aperte) se il cliente è 60+ va alla cassa 3
	{													//Altrimenti il cliente si aggiunge alla fila pù corta (3 esclusa)
		temp=NULL;
		if (PN->info>60)
		{
			if (*pl3==NULL)
		  	*pl3=PN;
			else
			{
				temp=*pl3;
				while(temp->next!=NULL)
				  temp=temp->next;
				temp->next=PN;
			}
		}
		else
		{
			temp=NULL;
			int n;
			int m;
			temp=*pl1;
			n=ContaClienti(temp);
			temp=*pl2;
			m=ContaClienti(temp);
		
			if (n<=m)
			{
				if (*pl1==NULL)
		 		 *pl1=PN;
				else
				{
					temp=*pl1;
					while(temp->next!=NULL)
				 	 temp=temp->next;
					temp->next=PN;
				}
			}
			else
			{
				if (*pl2==NULL)
		  		*pl2=PN;
				else
				{
					temp=*pl2;
					while(temp->next!=NULL)
						temp=temp->next;
					temp->next=PN;
				}
			}
		}
		
	} 
}

void remclient(int state,head *pl1,head *pl2,head *pl3){
	head temp=NULL;
															//Rimozione FIFO
	if (state==0)								// SE state=0 viene rimosso un cliente dalla cassa 1 
	{
		if (*pl1!=NULL)
		{
			temp=*pl1;
			*pl1=temp->next;
		}
	}
	
	if (state==1)           // SE state=1 viene rimosso un cliente dalla cassa 1 o dalla cassa 2 (RANDOM)
	{
		temp=NULL;
		int r;
		r=rand()%2+1;
		
		if (r==1)
		{
			if (*pl1!=NULL)
			{
				temp=*pl1;
				*pl1=temp->next;
			}	
		}
		else
		{
			if (*pl2!=NULL)
			{
				temp=*pl2;
				*pl2=temp->next;
			}
		}
	}
	
	if (state==2)				// SE state=2 viene rimosso un cliente dalla cassa 1 o dalla cassa 2 o dalla 3 (RANDOM)
	{
		temp=NULL;
		int r;
		r=rand()%3+1;
		
		if (r==1)
		{
			if (*pl1!=NULL)
			{
				temp=*pl1;
				*pl1=temp->next;
			}	
		}
		
		if (r==2)
		{
			if (*pl2!=NULL)
			{
				temp=*pl2;
				*pl2=temp->next;
			}	
		}
		
		if (r==3)
		{
			if (*pl3!=NULL)
			{
				temp=*pl3;
				*pl3=temp->next;
			}	
		}	
	}
}

head SpostaPari(head pl1)
{
	head pl2=NULL;
	head lis=NULL;
	lis=pl1;
	head temp=NULL;
	while (lis->next!=NULL)
	{
		if (lis->next->info>100)
		{
			if (temp==NULL)
			{
				temp=lis->next;
				lis->next=temp->next;
				temp->next=NULL;
				pl2=temp;
			}
			else
			{
				temp->next=lis->next;
				temp=temp->next;
				lis->next=temp->next;
				temp->next=NULL;
			}
		}
		else
		  lis=lis->next;
	}
	return pl2;
	
}

int ContaClienti(head lis)
{
	int n=0;
	while (lis!=NULL)
	{
		lis=lis->next;
		n++;
	}
	return n;
}

void IncPari(head pl1){
	head lis;
	lis=pl1;
	int conta=1;
	while(lis!=NULL)
	{
		if (conta%2==0)
		{
			lis->info=lis->info+100;
		}
		lis=lis->next;
		conta++;
	}
}

void DecAll(head pl2){
	head lis;
	lis=pl2;
	
	while(lis!=NULL)
	{
		if (lis->info>100)
		{
			lis->info=lis->info-100;
		}
		lis=lis->next;
	}
}

head AnzianiPLN(head pl,head temp){
	
	head lis=NULL;
	lis=pl;
	head testa=NULL;													//NOTA: Se L'anziano si trova nella PRIMA posizione della cassa 1 o 2
																						//Non verrà Considerato, piochè in ogni caso, non gli conviene cambiare cassa
	while (lis->next!=NULL)
	{
		if (lis->next->info>60)
		{
			if (temp==NULL)
			{
				temp=lis->next;
				lis->next=temp->next;
				temp->next=NULL;
				testa=temp;
			}
			else
			{
				temp->next=lis->next;
				temp=temp->next;
				lis->next=temp->next;
				temp->next=NULL;
			}
		}
		else
		  lis=lis->next;
	}
	return testa;
		
}

head CombinaListe(head t1,head t2){
	head temp;
	temp=t1;
	
	if (temp==NULL)
	{
		temp=t2;
		return temp;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=t2;
		return t1;
	}
	
}








