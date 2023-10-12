import java.util.*;
public class StackAL{
  private ArrayList<Object> st;
  public StackAL(){
    st = new ArrayList<Object>();
  }
  public void push(Object item){
    st.add(item);
  }
  public Object pop(){
   if (!st.isEmpty())
     return st.remove(st.size()-1);
   else 
     return null;
  }
  public int getCount(){
    return st.size(); 
  }
  public String toString(){
    // da completare  
    String stringa =""; 
    for (int x = 0; x < st.size(); x ++){
      stringa =stringa + "\n|"+st.get(x)+ "\t|";
    }   
    return stringa +"\n|_______|\n";   
  }
}
