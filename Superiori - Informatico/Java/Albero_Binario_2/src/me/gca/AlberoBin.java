package me.gca;

public class AlberoBin {

  // Crea nodo di base.
  protected NodoBin padre;
  static final int conta = 8;

  /**
   * Costruttore, setto il nodo padre iniziale a null.
   */
  public AlberoBin() {
    padre = null;
  }

  /**
   * Stampa da stringa l'albero.
   *
   * @return
   */
  public String toString() {
    if (padre == null) {
      return "NULL";
    }
    return "" + padre + "";
  }

  /**
   * Albero da vettore di interi.
   *
   * @param vettore
   * @param inizio
   * @param tanti
   */
  void creaDaVettore(int[] vettore, int inizio, int tanti) {
    padre = daVettore(vettore, inizio, tanti);
  }

  /**
   * Creo singolo nodo da vettore in modo ricorsivo.
   *
   * @param vettore
   * @param i
   * @param tanti
   * @return
   */
  public NodoBin daVettore(int[] vettore, int i, int tanti) {
    NodoBin temp;
    // Se vera, superato il limite del vettore.
    if (i >= tanti) {
      return null;
    }
    // Nessun valore rimasto da aggiungere.
    if (vettore[i] == 0) {
      return null;
      // Creo il nodo.
    }

    temp = new NodoBin(vettore[i], null, null);

    // Albero sinistro.
    temp.sinistro = daVettore(vettore, 2 * i + 1, tanti);
    // Albero destro.
    temp.destro = daVettore(vettore, 2 * i + 2, tanti);

    // Condizioni per posizione valida.
    if (temp.sinistro != null && temp.destro != null) {
      if (temp.getDato() < temp.sinistro.getDato() || temp.getDato() < temp.destro.getDato()) {
        if (temp.sinistro.getDato() > temp.getDato()) {
          if (temp.sinistro.getDato() > temp.destro.getDato()) {
            temp.setDato(temp.sinistro.getDato());
            temp.sinistro.setDato(vettore[i]);
          } else {
            temp.setDato(temp.destro.getDato());
            temp.destro.setDato(vettore[i]);
          }
        }
        if (temp.destro.getDato() > temp.getDato()) {
          temp.setDato(temp.destro.getDato());
          temp.destro.setDato(vettore[i]);
        }
      }
    }
    return temp;
  }

  /**
   * Ritorna true se l'albero è vuoto.
   *
   * @return
   */
  public boolean alberoVuoto() {
    return (padre == null);
  }

  /**
   * Inserisci nodo da valore.
   *
   * @param val
   */
  public void insNode(int val) {
    if (alberoVuoto()) {
      padre = new NodoBin(val);
    } else {
      padre.insNodoInterno(val);
    }
  }

  /**
   * Legge in modo ricorsivo dal nodo specificato in modalità preorder.
   */
  public void preorder(NodoBin radice) {
    if (radice != null) {
      System.out.print(radice.dato + " ");
      preorder(radice.sinistro);
      preorder(radice.destro);
    }
  }

  /**
   * Legge in modo ricorsivo dal nodo specificato in modalità postorder.
   *
   * @param radice
   */
  public void postorder(NodoBin radice) {
    if (radice != null) {
      postorder(radice.sinistro);
      postorder(radice.destro);
      System.out.print(radice.dato + " ");
    }
  }

  /**
   * Legge in modo ricorsivo dal nodo specificato in modalità inorder.
   *
   * @param radice
   */
  public void inorder(NodoBin radice) {
    if (radice != null) {
      inorder(radice.sinistro);
      System.out.print(radice.dato + " ");
      inorder(radice.destro);
    }
  }

  /**
   * Leggo l'intero albero da questo nodo in modo ricorsivo, in modalità preorder.
   */
  public void preorder1() {
    System.out.print("\n preorder  : ");
    if (padre != null)
      padre.nodoBinPreorder();
  }

  /**
   * Leggo l'intero albero da questo nodo in modo ricorsivo, in modalità postorder.
   */
  public void postorder1() {
    System.out.print("\n postorder : ");
    if (padre != null) {
      padre.nodoBinPostorder();
    }
  }

  /**
   * Leggo l'intero albero da questo nodo in modo ricorsivo, in modalità inorder.
   */
  public void inorder1() {
    System.out.print("\n inorder   : ");
    if (padre != null) {
      padre.nodoBinInorder();
    }
  }

  void perLivello() {
    int h = altezzaNodo(padre);
    for (int i = 1; i <= h; i++) {
      stampaLivelloAttuale(padre, i);
    }
  }

  void stampaLivelloAttuale(NodoBin nodo, int level) {
    if (nodo == null) {
      return;
    }
    if (level == 1) {
      System.out.print(nodo.dato + " ");
    } else if (level > 1) {
      stampaLivelloAttuale(nodo.sinistro, level - 1);
      stampaLivelloAttuale(nodo.destro, level - 1);
    }
  }

  int altezzaNodo(NodoBin nodo) {
    if (nodo == null) {
      return 0;
    } else {
      // Altezza albero.
      int altezzaSinistra = altezzaNodo(nodo.sinistro);
      int altezzaDestra = altezzaNodo(nodo.destro);

      // Inizia dall'altezza maggiore.
      if (altezzaSinistra > altezzaDestra) {
        return altezzaSinistra + 1;
      } else {
        return altezzaDestra + 1;
      }
    }
  }

  public void daSinistra(){
    if (padre != null) {
      padre.nodoBinInorder();
    }
  }

  /**
   * Ritorna true se il valore specificato è presente nell'albero.
   *
   * @param val
   * @return
   */
  public boolean inAlbero(int val) {
    if (alberoVuoto()) {
      return false;
    }
    return padre.nodoBinInAlbero(val);
  }


  /**
   * Stampo albero 2D partendo dal nodo dato e con lo spazio che richiamo in modo ricorsivo e si incrementa.
   * Il metodo e' utilizzabile a partire da un nodo a scelta ma con spazio 0 altrimenti parte con un offset.
   *
   * @param radice
   * @param spazio
   */
  public void stampa2D(NodoBin radice, int spazio) {
    if (radice == null) {
      return;
    }

    // Incrementa distanza tra i livelli.
    spazio += conta;

    // Figlio destro.
    stampa2D(radice.destro, spazio);

    // Aggiungo spazi.
    for (int i = conta; i < spazio; i++) {
      Util.printf(" ");
    }
    // Stampo il valore.
    Util.printfn("" + radice.getDato());

    // Ora fai lo stesso per il figlio sinistro.
    stampa2D(radice.sinistro, spazio);
  }

  /**
   * Richiama stampa 2D Con parametri di default partendo dal padre dell'albero stesso.
   * */
  public void stampaAlbero2D() {
    // Spazio iniziale pari a 0 e inizio dal nodo padre dello stesso albero.
    stampa2D(padre, 0);
  }

  /**
   * Ritorna l'altezza dell'albero.
   *
   * @param val
   * @return
   */
  public int altezza(int val) {
    if (alberoVuoto()) {
      return -1;
    }
    return padre.altezzaNodo(val, 0);
  }

  /**
   * Cerca a partire dal nodo specificato il valore richiesto, ritorna true se trovato.
   *
   * @param nodo
   * @param val
   * @return
   */
  public boolean cerca(NodoBin nodo, int val) {
    if (val == nodo.dato) {
      return true;
    } else {
      if (val < nodo.dato) {
        if (nodo.sinistro != null) {
          return cerca(nodo.sinistro, val);
        } else {
          return false;
        }
      } else {
        if (nodo.destro != null) {
          return cerca(nodo.destro, val);
        } else {
          return false;
        }
      }
    }
  }

  /**
   * Cerca nel nodo specificato il valore.
   *
   * @param nodo
   * @param val
   * @return
   */
  public boolean ABR_cercaRic(NodoBin nodo, int val) {
    if (nodo == null) {
      return false;
    }
    if (val == nodo.dato) {
      return true;
    }
    if (val < nodo.dato) {
      if (nodo.sinistro != null) {
        return ABR_cercaRic(nodo.sinistro, val);
      }
      return false;
    }
    if (nodo.destro != null) {
      return ABR_cercaRic(nodo.destro, val);
    }
    return false;
  }
}