package Pila;

public class Pila {

    private Object item;
    private Pila next;
    private Pila prev;

    public Pila(){
        this.item = null;
        this.next = null;
        this.prev = null;
    }

    public boolean isEmpty(){
        return item == null && next == null;
    }

    public int size(){
        if (item == null && next == null) return 0;
        int count = 0;
        Pila temp = this;
        while(temp != null){
            if (temp.item != null) count++; // Non contare elementi nulli
            temp = temp.next;
        }
        return count;
    }

    public void push(Object item){
        if (this.item == null){ // Inserisco il valore
            this.item = item;
        } else if (this.next == null){ // Inserisco il valore successivamente alla creazione di un "nodo"
            this.next = new Pila();
            this.next.item = item;
            this.next.prev = this;
        } else { // Inserisco il valore al nodo successivo se this.next non è nullo (ricorsivo)
            this.next.push(item);
        }
    }

    public Object pop(){
        if (this.isEmpty()) return -1;
        if (this.next == null){
            Object temp = this.item; // Leggo elemento
            this.item = null; // Rimuovo elemento
            if (this.prev != null) { // Se esiste un nodo precedente
                this.prev.next = null; // Rimuovo il riferimento a questo nodo
            }
            return temp; // Ritorno elemento
        } else {
            return this.next.pop(); // Vado ricorsivamente fino all'ultimo (LIFO)
        }
    }

    public Object top(){
        if (this.isEmpty()) return null;
        if (this.next == null){
            return this.item;
        } else {
            return this.next.top();
        }
    }

    public void print(){
        if (this.isEmpty()){
            System.out.println("La pila è vuota.");
        } else {
            Pila temp = this;
            while(temp != null){
                if (temp.item != null){
                    System.out.println(temp.item);
                }
                temp = temp.next;
            }
        }
    }

    public boolean contains(Object item){
        if (this.item == null && this.next == null) return false; // Se la lista è vuota, ritorna false.
        if (this.item == item) return true;
        if (this.next == null) return false;
        return this.next.contains(item);
    }

    @Override
    public String toString() {
        return "Pila{" +
                "item=" + item +
                ", next=" + next +
                '}';
    }
}
