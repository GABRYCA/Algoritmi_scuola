import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        System.out.println("//////////////////////////////////////////////////////");
        System.out.println("            Algoritmi di Ordinamento | GCA            ");
        System.out.println("//////////////////////////////////////////////////////");

        Scanner scanner = new Scanner(System.in);

        int numeroNumeri = 100000;
        int scelta = -1;

        while (scelta != 0){
            System.out.println("\nOpzioni:\n" +
                    "0 -> Esci\n" +
                    "1 -> Selection Sort\n" +
                    "2 -> Insertion Sort\n" +
                    "3 -> BubbleSort\n" +
                    "4 -> Distribution Counting Sort\n" +
                    "5 -> BucketSort\n" +
                    "6 -> MergeSort\n" +
                    "7 -> BucketBuckSort\n" +
                    "8 -> QuickSort\n" +
                    "9 -> HeapSort\n" +
                    "Scelta:");

            scelta = scanner.nextInt();

            switch (scelta){
                case 0 -> System.out.println("Uscita in corso...");

                case 1 -> {
                    System.out.println("Selection Sort con " + numeroNumeri + " numeri...");
                    SelectionSort sort = new SelectionSort(numeroNumeri);
                    sort.sort(); // Avvio sort
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 2 -> {
                    System.out.println("Insertion Sort con " + numeroNumeri + " numeri...");
                    InsertionSort sort = new InsertionSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 3 -> {
                    System.out.println("BubbleSort con " + numeroNumeri + " numeri...");
                    BubbleSort sort = new BubbleSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 4 -> {
                    System.out.println("Distribution Counting Sort con " + numeroNumeri + " numeri...");
                    DistributionCountingSort sort = new DistributionCountingSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 5 -> {
                    System.out.println("BucketSort con " + numeroNumeri + " numeri...");
                    BucketSort sort = new BucketSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 6 -> {
                    System.out.println("MergeSort con " + numeroNumeri + " numeri...");
                    MergeSort sort = new MergeSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 7 -> {
                    int lunghezzaParole = 4;
                    System.out.println("BucketBuckSort con " + numeroNumeri + " parole da " + lunghezzaParole + " caratteri...");
                    BucketBuckSort sort = new BucketBuckSort(numeroNumeri, lunghezzaParole);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 8 -> {
                    System.out.println("QuickSort con " + numeroNumeri + " numeri...");
                    QuickSort sort = new QuickSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                case 9 -> {
                    System.out.println("HeapSort con " + numeroNumeri + " numeri...");
                    HeapSort sort = new HeapSort(numeroNumeri);
                    sort.sort();
                    System.out.println("Riepilogo vettore ordinato: ");
                    sort.print();
                }

                default -> System.out.println("Scelta non valida!");
            }
        }

        System.out.println("Chiuso con successo!");
    }
}