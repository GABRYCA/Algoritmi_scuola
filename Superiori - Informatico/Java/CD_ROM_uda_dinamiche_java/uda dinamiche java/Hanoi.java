public class Hanoi {
 int disks;
 int pegs[][];
 public Hanoi(int disks) {
  this.disks = disks; 
  pegs = new int[3][disks];
  for(int i=0;i<disks;i++) { pegs[0][i] = i+1; pegs[1][i] = 0; pegs[2][i] = 0; }
   System.out.println("Start!");
  display();
  moveDisks(disks, 0, 2, 1);
 }
 public void moveDisks(int disks, int from, int to, int empty) {
   if(disks <= 1) {
   System.out.println("moving from "+from+" to "+to);
   move(from, to);
  } else {
   moveDisks(disks-1, from, empty, to); 
   System.out.println("moving from "+from+" to "+to);
   move(from, to);
   moveDisks(disks-1, empty, to, from);
  }
 }
 public void move(int from, int to) {
  int i=0;
  while( (pegs[from][i] == 0) && (i<disks) ) i++;
  int tmpFrom = (i==disks) ? disks-1 : i;
  i=disks-1;
  while( (pegs[to][i] != 0) && (i>0) ) i--;
  pegs[to][i] = pegs[from][tmpFrom];
  pegs[from][tmpFrom] = 0;
  display();
 }
 public void display() {
  for(int j=0;j<disks;j++) {
   for(int i=0;i<3;i++) System.out.print(" "+pegs[i][j]+" ");
    System.out.println("");
   }
  System.out.println("");
 }

 public static void main(String args[]) {
   Hanoi h = new Hanoi(3);
  }
}