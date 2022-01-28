public class Lista{
  private Nodo testa;    // puntatore iniziale alla lista
  private int quanti;    // contatore elementi  - solo per comodità
  public Lista(){
    testa = null;
    quanti  = 0;
  }

  private Lista(Nodo h){
    this.testa = h;
  }

  public Lista(int info){
    testa = new Nodo(info, null);
  }

  public boolean is_Empty(){
    return testa == null;
  }

  public int car(){             // primo elemento
    if(testa == null)
      throw new RuntimeException("car: lista vuota");
    else
      return testa.info;
  }

  public Lista cdr(){           // lista dopo aver tolto  il primo elemento
    if (testa == null)
      throw new RuntimeException("cdr: lista vuota");
    else
      return new Lista(testa.next);
  }

  public Lista cons(int info){
    return new Lista(cons(info, testa));
  }

  private static Nodo cons(int info, Nodo testa){
    return new Nodo(info, testa);
  }


  public String toString(){
    String q = "";
    if (testa == null)
      return "[]->NULL";
    else
      return "[]->" + testa + "";
  }

  public void add(int n){
    Nodo nuovo = new Nodo();
    nuovo.info = n;
    if (testa==null)            //1' caso: lista vuota
    {
      testa = nuovo;
      testa.next = null;
    }
    else
      if (testa.next==null)     //2' caso lista con un solo nodo
        testa.next = nuovo;
      else
      {                         //3' caso: lista > 1 nodo
        Nodo tmp = null;
        for(tmp=testa.next; tmp.next != null; tmp = tmp.next);
        tmp.next = nuovo;
      }
    quanti++;
   }

   public void addCoda(int n){
     Nodo nuovo = new Nodo(n);
     if (testa==null){             //1' caso: lista vuota
       testa = nuovo;
     }
     else {                        //2' caso: lista piena
       Nodo tmp = null;            //   trovo l'ultimo
       for(tmp=testa; tmp.next != null; tmp = tmp.next);
       tmp.next = nuovo;
     }
     quanti++;
   }

   public void addTesta(int n){
     Nodo nuovo = new Nodo(n);
     if (testa==null){            //1' caso: lista vuota
       testa = nuovo;
     }
     else{                        //2' caso: lista piena
       nuovo.next = testa;
       testa = nuovo;
     }
     quanti++;
   }


   public void inserisci(int n){
     if (testa==null || testa.info > n)   //1' caso: lista vuota o primo
       this.addTesta(n);
     else                                 //2' caso: altre situazioni
     {
       Nodo nuovo = new Nodo(n);
       Nodo succ = testa;
       Nodo prec = testa;
       while(succ!=null && succ.info < n){
         prec = succ;
         succ = succ.next;
       }
       prec.next = nuovo;
       nuovo.next = succ;
     }
     quanti++;
   }

   public void togliCoda(){
     if (testa!=null){       //caso: lista piena
       Nodo succ = testa;
       Nodo prec = testa;
       while(succ.next!=null){
         prec = succ;
         succ = succ.next;
       }
       prec.next = null;
       quanti--;
     }
   }

   public void togliMezzo(int voluto){
     if (testa!=null){            //lista piena
       Nodo prec = testa;
       Nodo succ = testa.next;
       if (testa.info == voluto){ //è il primo
         testa = testa.next;
         quanti--;
       }
       else{                      //cerco all'interno
         while(succ != null && succ.info != voluto){
           prec = succ;
           succ = succ.next;
         }
         if(succ.info == voluto){
           prec.next = succ.next;
           quanti--;
         }
       }
     }
   }

   public void togliTesta(){
     if (testa!=null){      //caso: lista piena
       testa = testa.next;
       quanti--;
     }
   }


   public void removeAll(int n, boolean all){
     while(testa!=null && testa.info==n) // e' il primo
     {
       testa = testa.next;
       quanti--;
        if (!all || testa==null)  // fine lista o uno solo da togliere
     	return;
     }
      Nodo succ = testa.next;
      Nodo prec = testa;
      for(; succ != null; succ = succ.next){  // proseguo a togliere gli altri
        if(succ.info == n){
         prec.next = succ.next;
         succ= prec;
         quanti--;
         if(!all)
           return;
      }
      else
        prec = prec.next;
      }
    }

  public boolean inLista(int num){
   Nodo succ = testa;
   while(succ!=null ) // e' il primo
   {
     if(succ.info == num)
       return true;
     else
      succ = succ.next;
    }
    return false;
  }
/*
  public Nodo creaListaCasuale(int Nnodi){
    int n = Nnodi;
    int cont=0;
    cont++;
    Nodo ptesta;
    Nodo succ;
    cont=(int)Math.floor(Math.random()*100);
    Nodo ele = new Nodo(cont);
    ptesta=ele;
    n--;
    while(n>0){
      n--;
      cont = (int)Math.floor(Math.random()*100);
      succ = new Nodo(cont);
      ele  = succ;
      ele = ele.next;
      if(n==0)
       succ.next=null;
    }
    return ptesta;
  }

  */




}
/*
	public Lista removeFirst(){
	}

	public Lista addLast(int info){
	}

	public Lista removeLast(){
	}

	public Lista copia(){
	}

	public Lista insertBeforeElement(int x, int info){
	}

	public Lista insertAfterElement(int x, int info){
	}

	public Lista removeElement(int info){
	}

	public int position(int info){
	}

	public Lista modify(int info, int x){
	}

	public int get(int k){
	}

	public Lista insertK(int info, int k){
	}

	public Lista  removeK(int k){
	}

	public int last(){
	}

	public Lista reverse(){
	}
   */
   /*--------------------------------------------------------------------*/




