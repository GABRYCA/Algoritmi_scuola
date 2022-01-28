public class EsempioStack{
  public static void main(String[] args){
    StackAL s = new StackAL();
    s.push("Ciao ");
    s.push("Bye !");
    System.out.println(s);
    
    String x;
    x = (String)s.pop();
    System.out.println(x);
    x = (String)s.pop();
    System.out.println(x);
    System.out.print(s);   
  }
}

