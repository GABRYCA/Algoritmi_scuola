import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class Calcolatrice implements ActionListener {

    JTextArea primoNumero;
    JTextArea secondoNumero;
    JTextArea risultato;
    JComboBox<String> operazione;

    public Calcolatrice(){
        initialize();
    }

    private void initialize(){
        JFrame frame = new JFrame("Calcolatrice");
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        frame.setSize(800, 600);
        frame.setLocationRelativeTo(null);


        JPanel panel = new JPanel();
        panel.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        panel.setBackground(Color.getHSBColor(0.4f, 0.0f, 0.17f));

        primoNumero = new JTextArea(1, 10);
        secondoNumero = new JTextArea(1, 10);

        operazione = new JComboBox<>();
        operazione.addItem("+");
        operazione.addItem("-");
        operazione.addItem("*");
        operazione.addItem("/");

        risultato = new JTextArea(1, 10);
        risultato.setEditable(false);

        JLabel risultatoLabel = new JLabel("Risultato:");
        risultatoLabel.setForeground(Color.WHITE);

        JButton calcola = new JButton("Calcola");
        calcola.addActionListener(this);

        panel.add(primoNumero);
        panel.add(operazione);
        panel.add(secondoNumero);
        panel.add(risultatoLabel);
        panel.add(risultato);
        panel.add(calcola);
        frame.add(panel);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (primoNumero.getText().isEmpty() || secondoNumero.getText().isEmpty() || operazione.getSelectedItem().toString().isEmpty()) {
            JOptionPane.showMessageDialog(null, "Inserire tutti i dati");
        } else {

            if (primoNumero.getLineCount() != 1 || secondoNumero.getLineCount() != 1) {
                JOptionPane.showMessageDialog(null, "Massimo una riga!");
            }

            double primo = Double.parseDouble(primoNumero.getText());
            double secondo = Double.parseDouble(secondoNumero.getText());
            String operazioneSelezionata = operazione.getSelectedItem().toString();
            if (operazioneSelezionata.equals("+")) {
                risultato.setText(String.valueOf(primo + secondo));
            }
            if (operazioneSelezionata.equals("-")) {
                risultato.setText(String.valueOf(primo - secondo));
            }
            if (operazioneSelezionata.equals("*")) {
                risultato.setText(String.valueOf(primo * secondo));
            }
            if (operazioneSelezionata.equals("/")) {
                risultato.setText(String.valueOf(primo / secondo));
            }
        }
    }
}
