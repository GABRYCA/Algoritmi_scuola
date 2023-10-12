#include "bicchiere.h"


char f[20],m[20];
float l, c;

int main()
{
    printf("creo il primo bicchiere (statico)...\n");
    Bicchiere b;  /* oggetto statico della classe bicchiere: viene invocato
                     il metodo costruttore vuoto */

    /* e visualizziamo i suoi dati */
    printf("dati del primo bicchiere:\n");
    printf("forma: %s\n", b.GetForma());
    printf("materiale: %s\n", b.GetMateriale());
    printf("capacita: %.2f\n", b.GetCapacita());
    printf("livello: %.2f\n", b.GetLivello());
    system("pause");


    /* assegnamo nuovi dati all'oggetto statico */
    printf("\n\nmodifichiamo i dati del primo bicchiere:\n");
    printf("forma: ");
    scanf("%s", f); 
    printf("materiale: ");
    scanf("%s", m); 
    printf("capacita: ");
    scanf("%f", &c); 
    printf("nuovo livello: "); 
    scanf("%f", &l); 

    printf("modifico l'attributo forma...\n");
    b.SetForma(f);
    printf("modifico l'attributo materiale...\n");
    b.SetMateriale(m);
    printf("modifico l'attributo capacita...\n");
    b.SetCapacita(c);
    printf("modifico l'attributo livello...\n");
    b.SetLivello(l);  
    printf("dati modificati!\n");
    system("pause");
    
    /* e visualizziamo i suoi dati */
    printf("\n\ndati del primo bicchiere:\n");
    printf("forma: %s\n", b.GetForma());
    printf("materiale: %s\n", b.GetMateriale());
    printf("capacita: %.2f\n", b.GetCapacita());
    printf("livello: %.2f\n", b.GetLivello());
    system("pause");
    
    /* costruiamo il primo oggetto dinamico  */
    Bicchiere *pb1;  /* dichiaro un puntatore a un oggetto della classe bicchiere
                        non viene ancora creato l'oggetto */
    printf("\n\ncreo il secondo bicchiere (dinamico):\n");
    printf("costruisco il bicchiere con il costruttore vuoto...\n");
    pb1 = new Bicchiere();
    system("pause");
    
    /* e visualizziamo i suoi dati inizializzati col costruttore */
    printf("\n\ndati del secondo bicchiere:\n");
    printf("forma: %s\n", pb1->GetForma());
    printf("materiale: %s\n", pb1->GetMateriale());
    printf("capacita: %.2f\n", pb1->GetCapacita());
    printf("livello: %.2f\n", pb1->GetLivello());
    system("pause");
    
    /* modifichiamo i suoi dati con i metodi set */
    printf("\n\nandiamo a modificare i dati del secondo bicchiere:\n");
    printf("nuova forma: "); 
    scanf("%s", f); 
    printf("nuovo materiale: "); 
    scanf("%s", m); 
    printf("nuova capacita: "); 
    scanf("%f", &c); 
    printf("nuovo livello: "); 
    scanf("%f", &l); 
    printf("modifico l'attributo forma...\n");
    pb1->SetForma(f);
    printf("modifico l'attributo materiale...\n");
    pb1->SetMateriale(m);
    printf("modifico l'attributo capacita...\n");
    pb1->SetCapacita(c);
    printf("modifico l'attributo livello...\n");
    pb1->SetLivello(l);  
    printf("dati modificati!\n");
    system("pause");

    /* e visualizziamo di nuovo i suoi dati*/
    printf("\n\nnuovi dati del secondo bicchiere:\n");
    printf("forma: %s\n", pb1->GetForma());
    printf("materiale: %s\n", pb1->GetMateriale());
    printf("capacita: %.2f\n", pb1->GetCapacita());
    printf("livello: %.2f\n", pb1->GetLivello());
    system("pause");
    
    /* costruiamo il secondo oggetto dinamico, ma stavolta usando il costruttore con parametri */

    Bicchiere *pb2;  /* dichiaro un puntatore a un oggetto della classe bicchiere
                        non viene ancora creato l'oggetto */
    printf("\n\ncreo il terzo bicchiere (dinamico)...\n");
    printf("inseriamo i dati del terzo bicchiere...\n");
    printf("forma: "); 
    scanf("%s", f); 
    printf("materiale: "); 
    scanf("%s", m); 
    printf("capacita: "); 
    scanf("%f", &c); 
    printf("costruisco il bicchiere inizializzandolo con i dati inseriti...\n");
    pb2 = new Bicchiere(f, m, c, 0); /* all'inizio il bicchiere è vuoto */
    system("pause");
    
    /* visualizziamo i suoi dati inizializzati col costruttore */
    printf("\n\ndati del terzo bicchiere:\n");
    printf("forma: %s\n", pb2->GetForma());
    printf("materiale: %s\n", pb2->GetMateriale());
    printf("capacita: %.2f\n", pb2->GetCapacita());
    printf("livello: %.2f\n", pb2->GetLivello());
    system("pause");
    
    /* riempiamo i tre bicchieri */
    printf("\n\nriempiamo i tre bicchieri:\n");
    printf("riempio il primo bicchiere...\n");
    b.Riempi();
    printf("riempio il secondo bicchiere...\n");
    pb1->Riempi();
    printf("riempio il terzo bicchiere...\n");
    pb2->Riempi();
    system("pause"); 
    
    /* visualizziamo il livello dei tre bicchiere */
    printf("\n\nlivello primo bicchiere: %.2f\n", b.GetLivello());
    printf("livello secondo bicchiere: %.2f\n", pb1->GetLivello());
    printf("livello terzo bicchiere: %.2f\n", pb2->GetLivello());
    system("pause"); 
    
    /* svuotiamo i bicchieri */
    printf("\n\nsvuotiamo i tre bicchieri:\n");
    printf("svuoto il primo bicchiere...glu glu glu...\n");
    b.Svuota();
    printf("svuoto il secondo bicchiere...glu glu glu...\n");
    pb1->Svuota();
    printf("svuoto il terzo bicchiere...glu glu glu...\n");
    pb2->Svuota();
    printf("bicchieri svuotati\n");
    system("pause"); 
    
    /* visualizziamo il livello dei tre bicchiere */
    printf("\n\nlivello primo bicchiere: %.2f\n", b.GetLivello());
    printf("livello secondo bicchiere: %.2f\n", pb1->GetLivello());
    printf("livello terzo bicchiere: %.2f\n", pb2->GetLivello());
    system("pause"); 
    
    /* cancelliamo il secondo bicchiere */
    printf("\n\ncancello il secondo bicchiere...crash...\n");
    delete pb2;
    printf("secondo bicchiere cancellato!\n");
    system("pause");    

    printf("\n\nche bella compagnia di ubriaconi!!!!\n");
    system("pause");    
}
