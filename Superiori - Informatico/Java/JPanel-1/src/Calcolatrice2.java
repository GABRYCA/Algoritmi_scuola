import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowEvent;
import java.awt.event.WindowListener;

public class Calcolatrice2 extends JPanel implements ActionListener, WindowListener {

    JButton n1, n2, n3, n4, n5, n6, n7, n8, n9, n0, piu, meno, per, diviso, uguale, cancella, punto;
    JTextField display;
    public Calcolatrice2() {
        initialize();
    }

    private void initialize() {
        JFrame frame = new JFrame("Calcolatrice");
        frame.setSize(800, 500);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setLocationRelativeTo(null);

        JPanel panel = new JPanel();
        panel.setLayout(new GridBagLayout());
        panel.setBackground(Color.getHSBColor(0.4f, 0.0f, 0.17f));

        GridBagConstraints c = new GridBagConstraints();


        n1 = new JButton("1");
        n1.addActionListener(this);
        n2 = new JButton("2");
        n2.addActionListener(this);
        n3 = new JButton("3");
        n3.addActionListener(this);
        n4 = new JButton("4");
        n4.addActionListener(this);
        n5 = new JButton("5");
        n5.addActionListener(this);
        n6 = new JButton("6");
        n6.addActionListener(this);
        n7 = new JButton("7");
        n7.addActionListener(this);
        n8 = new JButton("8");
        n8.addActionListener(this);
        n9 = new JButton("9");
        n9.addActionListener(this);
        n0 = new JButton("0");
        n0.addActionListener(this);
        piu = new JButton("+");
        piu.addActionListener(this);
        meno = new JButton("-");
        meno.addActionListener(this);
        per = new JButton("*");
        per.addActionListener(this);
        diviso = new JButton("/");
        diviso.addActionListener(this);
        uguale = new JButton("=");
        uguale.addActionListener(this);
        cancella = new JButton("C");
        cancella.addActionListener(this);
        punto = new JButton(".");
        punto.addActionListener(this);

        // Creo display.
        display = new JTextField();
        display.setEditable(false); // Lo rendo non editabile.
        Font font1 = new Font("SansSerif", Font.BOLD, 20); // Cambio il font e le dimensioni, metto anche in grassetto.
        display.setFont(font1); // Imposto il font creato prima.
        display.setHorizontalAlignment(JTextField.LEFT); // Allineo a sinistra.
        display.setMargin(new Insets(0, 30, 0, 0)); // Sposto il testo del display di 30 pixel a destra.

        // Aggiungo i bottoni al pannello.
        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50; // Altezza.
        c.weightx = 0.5; // Peso asse x.
        c.gridx = 0; // Colonna.
        c.gridy = 1; // Riga.
        panel.add(n1, c);  // Aggiungo il primo pulsante/numero.

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.weightx = 0.5;
        c.gridx = 1;
        c.gridy = 1;
        panel.add(n2, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.weightx = 0.5;
        c.gridx = 2;
        c.gridy = 1;
        panel.add(n3, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.weightx = 0.5;
        c.gridx = 3;
        c.gridy = 1;
        panel.add(punto, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 0;
        c.gridy = 2;
        panel.add(n4, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 1;
        c.gridy = 2;
        panel.add(n5, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 2;
        c.gridy = 2;
        panel.add(n6, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 3;
        c.gridy = 2;
        panel.add(piu, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 0;
        c.gridy = 3;
        panel.add(n7, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 1;
        c.gridy = 3;
        panel.add(n8, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 2;
        c.gridy = 3;
        panel.add(n9, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 3;
        c.gridy = 3;
        panel.add(meno, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 0;
        c.gridy = 4;
        panel.add(cancella, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 1;
        c.gridy = 4;
        panel.add(n0, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 2;
        c.gridy = 4;
        panel.add(diviso, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridx = 3;
        c.gridy = 4;
        panel.add(per, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.gridwidth = 4;
        c.gridx = 0;
        c.gridy = 5;
        panel.add(uguale, c);

        c.fill = GridBagConstraints.HORIZONTAL;
        c.ipady = 50;
        c.weightx = 0;
        c.gridwidth = 4;
        c.gridx = 0;
        c.gridy = 0;
        panel.add(display, c);

        // Aggiungo il pannello al frame.
        frame.add(panel);
        frame.setVisible(true);
        frame.getRootPane().setDefaultButton(uguale);
        frame.addWindowListener(this);
    }

    /**
     * Gestore degli eventi (click ai pulsanti).
     * @param e click al pulsante.
     */
    @Override
    public void actionPerformed(ActionEvent e) { // Gestore degli eventi.
        // In base al pulsante cliccato, aggiungo il numero/operatore al display.
        if (e.getSource() == n1) {
            display.setText(display.getText() + "1");
        }
        if (e.getSource() == n2) {
            display.setText(display.getText() + "2");
        }
        if (e.getSource() == n3) {
            display.setText(display.getText() + "3");
        }
        if (e.getSource() == n4) {
            display.setText(display.getText() + "4");
        }
        if (e.getSource() == n5) {
            display.setText(display.getText() + "5");
        }
        if (e.getSource() == n6) {
            display.setText(display.getText() + "6");
        }
        if (e.getSource() == n7) {
            display.setText(display.getText() + "7");
        }
        if (e.getSource() == n8) {
            display.setText(display.getText() + "8");
        }
        if (e.getSource() == n9) {
            display.setText(display.getText() + "9");
        }
        if (e.getSource() == n0) {
            display.setText(display.getText() + "0");
        }
        if (e.getSource() == piu) {
            if (display.getText().isEmpty()){ // Controllo non sia vuota la casella di testo.
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("+")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("-")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("*")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("/")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals(".")) {
                return;
            }
            display.setText(display.getText() + "+");
        }
        if (e.getSource() == meno) {
            if (display.getText().isEmpty()){
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("+")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("-")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("*")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("/")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals(".")) {
                return;
            }
            display.setText(display.getText() + "-");
        }
        if (e.getSource() == per) {
            if (display.getText().isEmpty()){
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("+")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("-")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("*")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("/")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals(".")) {
                return;
            }
            display.setText(display.getText() + "*");
        }
        if (e.getSource() == diviso) {
            if (display.getText().isEmpty()){
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("+")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("-")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("*")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("/")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals(".")) {
                return;
            }
            display.setText(display.getText() + "/");
        }
        if (e.getSource() == punto) {
            if (display.getText().isEmpty()){
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("+")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("-")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("*")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals("/")) {
                return;
            }
            if (display.getText().substring(display.getText().length() - 1).equals(".")) {
                return;
            }
            display.setText(display.getText() + ".");
        }
        if (e.getSource() == cancella) {
            display.setText("");
        }

        // Se premo il pulsante uguale, chiamo il metodo calcolo dandogli la stringa del display che dovrebbe essere un'espressione.
        if (e.getSource() == uguale) {
            if (display.getText().isEmpty()){
                return;
            }
            display.setText(calcola(display.getText()));
        }
    }

    private String calcola(String display) {

        // Inizializzo le variabili.
        String[] array = display.split("\\+|-|\\*|\\/"); // Array di stringhe che contiene tutti i numeri e OPERATORI.
        double[] array2 = new double[array.length]; // Array di double che contiene tutti i numeri.
        for (int i = 0; i < array.length; i++) {
            try {
                array2[i] = Double.parseDouble(array[i]);
            } catch (NumberFormatException e) {
                this.display.setText("");
                JOptionPane.showMessageDialog(null, "Hai inserito troppi punti (.)!");
            }
        }
        double risultato = 0;
        if (display.contains("+")) {
            risultato = array2[0];
        }
        if (display.contains("-")) {
            risultato = array2[0];
        }
        if (display.contains("*")) {
            risultato = array2[0];
        }
        if (display.contains("/")) {
            risultato = array2[0];
        }
        for (int i = 1; i < array2.length; i++) {
            if (display.contains("+")) {
                risultato += array2[i];
            }
            if (display.contains("-")) {
                risultato -= array2[i];
            }
            if (display.contains("*")) {
                risultato *= array2[i];
            }
            if (display.contains("/")) {
                risultato /= array2[i];
            }
        }
        return String.valueOf(risultato);
    }

    @Override
    public void windowOpened(WindowEvent e) {
        System.out.println("windowOpened");
    }

    @Override
    public void windowClosing(WindowEvent e) {
        System.out.println("windowClosing");
    }

    @Override
    public void windowClosed(WindowEvent e) {
        System.out.println("windowClosed");
        Main.finestraAperta = false;
    }

    @Override
    public void windowIconified(WindowEvent e) {
        System.out.println("windowIconified");
    }

    @Override
    public void windowDeiconified(WindowEvent e) {
        System.out.println("windowDeiconified");
    }

    @Override
    public void windowActivated(WindowEvent e) {
        System.out.println("windowActivated");
    }

    @Override
    public void windowDeactivated(WindowEvent e) {
        System.out.println("windowDeactivated");
    }
}
