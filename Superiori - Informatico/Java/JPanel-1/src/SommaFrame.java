import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class SommaFrame implements ActionListener {

    private JFrame frame;
    private JPanel panel;
    private Button button;

    private JLabel eseguiSomma;
    private JLabel simboloPiu;
    private JLabel simboloUguale;

    private JTextArea numero1;
    private JTextArea numero2;
    private JTextArea risultato;
    public SommaFrame(){
        initialize();
    }

    private void initialize() {
        frame = new JFrame("Somma");
        frame.setLayout(new BorderLayout(10, 5));
        frame.setSize(800, 600);
        frame.setLocationRelativeTo(null);
        frame.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);

        panel = new JPanel();
        panel.setLayout(new FlowLayout(FlowLayout.CENTER, 10, 10));
        panel.setBackground(Color.RED);

        button = new Button("Calcola!");
        button.addActionListener(this);


        eseguiSomma = new JLabel("Esegui Somma:");
        simboloPiu = new JLabel("+");
        simboloUguale = new JLabel("=");

        numero1 = new JTextArea(1, 10);

        numero2 = new JTextArea(1, 10);
        numero2.setSize(100, 100);

        risultato = new JTextArea(1, 10);
        risultato.setSize(100, 100);
        risultato.setEditable(false);

        panel.add(eseguiSomma);
        panel.add(numero1);
        panel.add(simboloPiu);
        panel.add(numero2);
        panel.add(simboloUguale);
        panel.add(risultato);
        panel.add(button);

        frame.add(panel, BorderLayout.NORTH);
        frame.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        try {
            risultato.setText("" + (Integer.parseInt(numero1.getText()) + Integer.parseInt(numero2.getText())));
        } catch (NumberFormatException ex) {
            risultato.setText("Errore!");
        }
        // Cambio colore background.
        /*new Thread(() -> {
            int red = 0, green = 0, blue = 0;
            while (true) {
                panel.setBackground(new Color(red, green, blue));
                int random = getRandomNumber(0, 5);
                switch (random) {
                    case 0:
                        if (red < 255) {
                            red++;
                        }
                        break;
                    case 1:
                        if (green < 255) {
                            green++;
                        }
                        break;
                    case 2:
                        if (blue < 255) {
                            blue++;
                        }
                        break;
                    case 3:
                        if (red > 0) {
                            red--;
                        }
                        break;
                    case 4:
                        if (green > 0) {
                            green--;
                        }
                        break;
                    case 5:
                        if (blue > 0) {
                            blue--;
                        }
                        break;
                }

                try {
                    Thread.sleep(1);
                } catch (InterruptedException e1) {
                    e1.printStackTrace();
                }
            }
        } ).start();*/
    }

    public int getRandomNumber(int min, int max) {
        return (int) ((Math.random() * (max - min)) + min);
    }
}
