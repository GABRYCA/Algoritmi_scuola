package me.simo;

public class Main {

    private String f;
    private String m;
    private float c, l;
    public static void main(String[] args) {
        //QUI VADO A DICHIARARE LE VARIABILI
        int scelta, scelta2;
        //VADO A CREARE I BICCHIERI
        Bicchiere b;
        Bicchiere pb1;
        pb1=new Bicchiere();
        Bicchiere pb2;
        pb2=new Bicchiere("Cilindro", "Vetro", 20, 5);
        do
            cout << "\tMenu' Bicchieri" << endl;
            cout << "1-Visualizzazione" << endl;
            cout << "2-Modifica" << endl;
            cout << "3-Riempi" << endl;
            cout << "4-Svuota" << endl;
            cout << "0-Fine" << endl;
            cin >> scelta;
            switch(scelta)
            {
                case 1:
                    //HO CREATO UN MENU' PER VISUALIZZARE I BICCHIERI
                    do
                    {
                        cout << "\tMenu' Visualizzazione" << endl;
                        cout << "1-Bicchiere Statico" << endl;
                        cout << "2-Bicchiere Dinamico" << endl;
                        cout << "3-Bicchiere Dinamico con costruttore con parametri" << endl;
                        cout << "4-Tutto" << endl;
                        cout << "0-Menu' Principale" << endl;
                        cin >> scelta2;
                        switch(scelta2)
                        {
                            case 1:
                                cout << "\tBicchiere Statico (1)" << endl;
                                cout << "\nForma: " << b.returnforma() << endl;
                                cout << "Materiale: " << b.returnmateriale() << endl;
                                cout << "Capacita: " << b.returncapacita() << endl;
                                cout << "Livello: " << b.returnlivello() << endl;
                                system("PAUSE");
                                break;

                            case 2:
                                cout << "\tBicchiere Dinamico (2)" << endl;
                                cout << "\nForma: " << pb1->returnforma() << endl;
                                cout << "Materiale: " << pb1->returnmateriale() << endl;
                                cout << "Capacita: " << pb1->returncapacita() << endl;
                                cout << "Livello: " << pb1->returnlivello() << endl;
                                system("PAUSE");
                                break;

                            case 3:
                                cout << "\tBicchiere Dinamico con costruttore con parametri (3)" << endl;
                                cout << "\nForma: " << pb2->returnforma() << endl;
                                cout << "Materiale: " << pb2->returnmateriale() << endl;
                                cout << "Capacita: " << pb2->returncapacita() << endl;
                                cout << "Livello: " << pb2->returnlivello() << endl;
                                system("PAUSE");
                                break;

                            case 4:
                                cout << "\tBicchiere Statico (1)" << endl;
                                cout << "\nForma: " << b.returnforma() << endl;
                                cout << "Materiale: " << b.returnmateriale() << endl;
                                cout << "Capacita: " << b.returncapacita() << endl;
                                cout << "Livello: " << b.returnlivello() << endl;
                                cout << "\n\tBicchiere Dinamico (2)" << endl;
                                cout << "\nForma: " << pb1->returnforma() << endl;
                                cout << "Materiale: " << pb1->returnmateriale() << endl;
                                cout << "Capacita: " << pb1->returncapacita() << endl;
                                cout << "Livello: " << pb1->returnlivello() << endl;
                                cout << "\n\tBicchiere Dinamico con costruttore con parametri (3)" << endl;
                                cout << "\nForma: " << pb2->returnforma() << endl;
                                cout << "Materiale: " << pb2->returnmateriale() << endl;
                                cout << "Capacita: " << pb2->returncapacita() << endl;
                                cout << "Livello: " << pb2->returnlivello() << endl;
                                system("PAUSE");
                                break;

                            case 0:
                                cout << "Stai tornando al menu' principale!!" << endl;
                                system("PAUSE");
                                break;

                            default:
                                cout << "Numero inserito non valido" << endl;
                                system("PAUSE");
                        }
                    }while(scelta2!=0);
                    break;

                case 2:
                    //HO CREATO UN MENU' PER MODIFICARE I BICCHIERI
                    do
                    {
                        system("cls");
                        cout << "\tMenu' Modifica" << endl;
                        cout << "1-Bicchiere Statico" << endl;
                        cout << "2-Bicchiere Dinamico" << endl;
                        cout << "3-Bicchiere Dinamico con costruttore con parametri" << endl;
                        cout << "0-Menu' Principale" << endl;
                        cin >> scelta2;
                        system("cls");
                        switch(scelta2)
                        {
                            case 1:
                                cout << "\tBicchiere Statico (1)" << endl;
                                cout << "Forma: ";
                                cin >> f;
                                b.setforma(f);
                                cout << "Materiale: ";
                                cin >> m;
                                b.setmateriale(m);
                                cout << "Capacita: ";
                                cin >> c;
                                b.setcapacita(c);
                                cout << "Livello: ";
                                cin >> l;
                                b.setlivello(l);
                                system("PAUSE");
                                break;

                            case 2:
                                cout << "\tBicchiere Dinamico (2)" << endl;
                                cout << "Forma: ";
                                cin >> f;
                                pb1->setforma(f);
                                cout << "Materiale: ";
                                cin >> m;
                                pb1->setmateriale(m);
                                cout << "Capacita: ";
                                cin >> c;
                                pb1->setcapacita(c);
                                cout << "Livello: ";
                                cin >> l;
                                pb1->setlivello(l);
                                system("PAUSE");
                                break;

                            case 3:
                                cout << "\tBicchiere Dinamico con costruttore con parametri (3)" << endl;
                                cout << "Forma: ";
                                cin >> f;
                                pb2->setforma(f);
                                cout << "Materiale: ";
                                cin >> m;
                                pb2->setmateriale(m);
                                cout << "Capacita: ";
                                cin >> c;
                                pb2->setcapacita(c);
                                cout << "Livello: ";
                                cin >> l;
                                pb2->setlivello(l);
                                system("PAUSE");
                                break;

                            case 0:
                                cout << "Stai tornando al menu' principale!!" << endl;
                                system("PAUSE");
                                break;

                            default:
                                cout << "Numero inserito non valido" << endl;
                                system("PAUSE");
                        }
                    }while(scelta2!=0);
                    break;

                case 3:
                    //HO CREATO UN MENU' PER RIEMPIRE I BICCHIERI
                    do
                    {
                        system("cls");
                        cout << "\tMenu' Riempimento" << endl;
                        cout << "1-Bicchiere Statico" << endl;
                        cout << "2-Bicchiere Dinamico" << endl;
                        cout << "3-Bicchiere Dinamico con costruttore con parametri" << endl;
                        cout << "4-Tutti" << endl;
                        cout << "0-Menu' Principale" << endl;
                        cin >> scelta2;
                        system("cls");
                        switch(scelta2)
                        {
                            case 1:
                                b.riempi();
                                cout << "Bicchiere riempito" << endl;
                                system("PAUSE");
                                break;

                            case 2:
                                pb1->riempi();
                                cout << "Bicchiere riempito" << endl;
                                system("PAUSE");
                                break;

                            case 3:
                                pb2->riempi();
                                cout << "Bicchiere riempito" << endl;
                                system("PAUSE");
                                break;

                            case 4:
                                b.riempi();
                                pb1->riempi();
                                pb2->riempi();
                                cout << "Bicchieri riempiti" << endl;
                                system("PAUSE");
                                break;

                            case 0:
                                cout << "Stai tornando al menu' principale!!" << endl;
                                system("PAUSE");
                                break;

                            default:
                                cout << "Numero inserito non valido" << endl;
                                system("PAUSE");
                        }
                    }while(scelta2!=0);
                    break;

                case 4:
                    //HO CREATO UN MENU' PER SVUOTARE I BICCHIERI
                    do
                    {
                        system("cls");
                        cout << "\tMenu' Svuotamento" << endl;
                        cout << "1-Bicchiere Statico" << endl;
                        cout << "2-Bicchiere Dinamico" << endl;
                        cout << "3-Bicchiere Dinamico con costruttore con parametri" << endl;
                        cout << "4-Tutti" << endl;
                        cout << "0-Menu' Principale" << endl;
                        cin >> scelta2;
                        system("cls");
                        switch(scelta2)
                        {
                            case 1:
                                b.svuota();
                                cout << "Bicchiere svuotato" << endl;
                                system("PAUSE");
                                break;

                            case 2:
                                pb1->svuota();
                                cout << "Bicchiere svuotato" << endl;
                                system("PAUSE");
                                break;

                            case 3:
                                pb2->svuota();
                                cout << "Bicchiere svuotato" << endl;
                                system("PAUSE");
                                break;

                            case 4:
                                b.svuota();
                                pb1->svuota();
                                pb2->svuota();
                                cout << "Bicchieri svuotati" << endl;
                                system("PAUSE");
                                break;

                            case 0:
                                cout << "Stai tornando al menu' principale!!" << endl;
                                system("PAUSE");
                                break;

                            default:
                                cout << "Numero inserito non valido" << endl;
                                system("PAUSE");
                        }
                    }while(scelta2!=0);
                    break;

                case 0:
                    //IL BICCHIERE STATICO SI ELIMINA DA SOLO QUELLI DINAMICI DEVO ANDARLI AD ELIMINARE MANUALMENTE
                    cout << "PROGRAMMA TERMINATO" << endl;
                    return 0;

                default:
                    cout << "Numero inserito non valido" << endl;
                    system("PAUSE");
            }
        }
        while(scelta!=0);
    }
}
