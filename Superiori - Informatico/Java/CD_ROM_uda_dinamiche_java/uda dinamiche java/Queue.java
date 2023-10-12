public class Queue{
  private Nodo pTesta;
  private Nodo pCoda;
  public Queue(){
	pTesta = null;
	pCoda = null;
  }
   public void enqueue(int dato){
    if (isEmpty()){
      pTesta = new Nodo(dato, pTesta);
      pCoda = pTesta;
    }
    else{
	  pCoda.next = new Nodo(dato, null);
	  pCoda = pCoda.next;
    }
  }
  public int dequeue(){
    if(isEmpty())
		return(-1);
	int top = pTesta.getInfo();
	pTesta = pTesta.getNext();
	return top;
  }
  public String toString(){
    String q = "";
    if (pTesta == null)
      return "[]->NULL";
    else
      return "[]->" + pTesta + "";
  }
  public boolean isEmpty(){
    return pTesta == null;
  }
  public void makeEmpty1(){
    pTesta = null;
	pCoda = null;
  }
}



