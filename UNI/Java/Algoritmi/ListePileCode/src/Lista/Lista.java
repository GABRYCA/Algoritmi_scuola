package Lista;

public class Lista {

    private Object item;
    private Lista next;

    public Lista(){
        this.item = null;
        this.next = null;
    }

    public boolean isEmpty(){
        return item == null && next == null;
    }

    public int size(){
        if (item == null && next == null) return 0;
        int count = 0;
        Lista temp = this;
        while(temp != null){
            if (temp.item != null) count++; // Non contare elementi nulli
            temp = temp.next;
        }
        return count;
    }

    public void insert(Object item){
        if (this.item == null){ // Inserisco il valore
            this.item = item;
        } else if (this.next == null){ // Inserisco il valore successivamente alla creazione di un "nodo" lista
            this.next = new Lista();
            this.next.item = item;
        } else { // Inserisco il valore alla lista successiva se this.next non è nullo (ricorsivo)
            this.next.insert(item);
        }
    }

    public boolean remove(Object item){
        if (!this.contains(item)) return false;
        if (this.item == item){
            this.item = null; // Setto il valore a null.
            return true;
        } else {
            return this.next.remove(item); // Rimozione ricorsiva.
        }
    }

    public boolean removePos(int index) {
        if (this.size() <= index) {
            return false;
        }
        if (index <= 0 && this.item != null) {
            this.item = null;
            return true;
        } else {
            if (item != null) { // Decremento solo se l'elemento non è nullo (altrimenti decremento anche negli spazi vuoti e non raggiungo la destinazione voluta)
                index--; // Decremento, fino a quando non arrivo alla posizione richiesta
            }
            return this.next.removePos(index);
        }
    }

    public boolean contains(Object item){
        if (this.item == null && this.next == null) return false; // Se la lista è vuota, ritorna false.
        if (this.item != null && this.item.equals(item)) return true; // Controlla se l'elemento corrente è quello ricercato.
        if (this.next != null) return this.next.contains(item); // Controlla gli elementi successivi.
        return false;
    }

    public void print(){
        if (this.item != null){
            System.out.println(this.item);
        }
        if (this.next != null){
            this.next.print();
        }
    }

    @Override
    public String toString() {
        return "Lista{" +
                "item=" + item +
                ", next=" + next +
                '}';
    }

}
