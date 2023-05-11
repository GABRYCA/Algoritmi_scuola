package eu.anonymousgca.webservicesglassfish;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import jakarta.ws.rs.*;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

@Path("/")
public class ChiamateAPI {
    @GET
    @Produces("text/plain")
    public String hello() {
        return "Hello, World!";
    }

    @GET
    @Path("/hello/{name}")
    @Produces("text/plain")
    public String helloName(@PathParam("name") String name) {
        return "Hello, " + name + "!";
    }

    /**
     * Autenticazione dati Email e Password
     * @param email Email dell'utente
     * @param password Password dell'utente
     * @return true se l'autenticazione va a buon fine, false altrimenti.
     * */
    @POST
    @Path("/login")
    @Produces("text/plain")
    public String login(@FormParam("email") String email, @FormParam("password") String password) {
        DBConnection dbConnection = new DBConnection();
        if (dbConnection.autenticazione(email, password)) {
            // Autenticazione riuscita.
            return "true";
        } else {
            // Autenticazione fallita.
            return "false";
        }
    }

    /**
     * Usando la funzione in UtenteBean getListaUtentiContattati() ottengo la lista degli utenti con cui l'utente ha avuto un contatto, e invio in formato JSON l'ID dell'utente, il suo nome e l'orario dell'ultimo accesso.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * */
    @POST
    @Path("/post/utenti/contatti")
    @Produces("text/plain")
    public String getUtentiConUltimoMessaggio(@FormParam("id_utente") int id_utente) {
        UtenteBean utenteBean = new UtenteBean();
        utenteBean.setId_utente(id_utente);
        ArrayList<UtenteBean> utenti = utenteBean.getListaUtentiContattati();
        // Uso GSON per immettere i dati richiesti da utenti in un formato JSON.
        Gson gson = new Gson();
        // Creo il JSON con un vettore di id, nome e ultimo accesso.
        String json = gson.toJson(utenti);
        return json;
    }

    /**
     * Usando la funzione in UtenteBean getMessaggiRicevuti() che ritorna una lista di MessaggioBean, invio in formato JSON i dati dei messaggi.
     * Questo metodo API filtrerà in automatico i messaggi che l'utente ha ricevuto da un determinato utente.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * @param id_utente_contatto id_utente dell'utente con cui l'utente che ha effettuato il login ha avuto un contatto.
     * */
    @POST
    @Path("/post/messaggi/ricevuti")
    @Produces("text/plain")
    public String getMessaggiRicevuti(@FormParam("id_utente") int id_utente, @FormParam("id_utente_contatto") int id_utente_contatto) {
        UtenteBean utenteBean = new UtenteBean();
        utenteBean.setId_utente(id_utente);
        ArrayList<MessaggioBean> messaggi = utenteBean.getMessaggiRicevuti();

        ArrayList<MessaggioBean> messaggiFiltrati = new ArrayList<>();
        for (MessaggioBean messaggio : messaggi) {
            if (messaggio.getId_mittente() == id_utente_contatto) {
                messaggiFiltrati.add(messaggio);
            }
        }

        // Uso GSON per immettere i dati richiesti da utenti in un formato JSON.
        Gson gson = new Gson();
        // Creo il JSON con un vettore di id, nome e ultimo accesso.
        String json = gson.toJson(messaggiFiltrati);
        return json;
    }

    /**
     * Usando la funzione in UtenteBean getMessaggiInviati() che ritorna una lista di MessaggioBean, invio in formato JSON i dati dei messaggi.
     * Questo metodo API filtrerà in automatico i messaggi che l'utente ha inviato a un determinato utente.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * @param id_utente_contatto id_utente dell'utente con cui l'utente che ha effettuato il login ha avuto un contatto.
     * */
    @POST
    @Path("/post/messaggi/inviati")
    @Produces("text/plain")
    public String getMessaggiInviati(@FormParam("id_utente") int id_utente, @FormParam("id_utente_contatto") int id_utente_contatto) {
        UtenteBean utenteBean = new UtenteBean();
        utenteBean.setId_utente(id_utente);
        ArrayList<MessaggioBean> messaggi = utenteBean.getMessaggiInviati();

        ArrayList<MessaggioBean> messaggiFiltrati = new ArrayList<>();
        for (MessaggioBean messaggio : messaggi) {
            if (messaggio.getId_destinatario() == id_utente_contatto) {
                messaggiFiltrati.add(messaggio);
            }
        }

        // Uso GSON per immettere i dati richiesti da utenti in un formato JSON.
        Gson gson = new Gson();
        // Creo il JSON con un vettore di id, nome e ultimo accesso.
        String json = gson.toJson(messaggiFiltrati);
        return json;
    }

    /**
     * Ritorna la chat con i MessaggiBean inviati e ricevuti tra id_utente e id_utente_contatto in ordine per data_invio.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * @param id_utente_contatto id_utente dell'utente con cui l'utente che ha effettuato il login ha avuto un contatto.
     * */
    @POST
    @Path("/post/chat")
    @Produces("text/plain")
    public String getChat(@FormParam("id_utente") int id_utente, @FormParam("id_utente_contatto") int id_utente_contatto) {
        UtenteBean utenteBean = new UtenteBean();
        utenteBean.setId_utente(id_utente);
        ArrayList<MessaggioBean> messaggi = utenteBean.getMessaggiInviatiERicevuti();

        ArrayList<MessaggioBean> messaggiFiltrati = new ArrayList<>();

        for (MessaggioBean messaggio : messaggi) {
            if (messaggio.getId_mittente() == id_utente_contatto || messaggio.getId_destinatario() == id_utente_contatto) {
                messaggiFiltrati.add(messaggio);
            }
        }

        // I messaggi sono ordinati dal più vecchio al più nuovo.
        Collections.sort(messaggiFiltrati, new Comparator<MessaggioBean>() {
            @Override
            public int compare(MessaggioBean o1, MessaggioBean o2) {
                return o1.getData_invio().compareTo(o2.getData_invio());
            }
        });


        // Uso anche com.fatboyindustrial.gsonjavatime.JavaTimeTypeAdapterFactory per convertire LocalDate in JSON.
        Gson gson = new GsonBuilder()
                .registerTypeAdapter(LocalDateTime.class, new LocalDateTimeAdapter())
                .create();
        // Creo il JSON con un vettore di id, nome e ultimo accesso.
        String json = gson.toJson(messaggiFiltrati);
        return json;
    }

    /**
     * Funzione che ricevuto id_utente, id_utente_contatto e testo inserisce il messaggio nel database.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * @param id_utente_contatto id_utente dell'utente con cui l'utente che ha effettuato il login ha avuto un contatto.
     * */
    @POST
    @Path("/post/inviaMessaggio")
    @Produces("text/plain")
    public String inviaMessaggio(@FormParam("id_utente") int id_utente, @FormParam("id_utente_contatto") int id_utente_contatto, @FormParam("testo") String testo) {
        MessaggioBean messaggioBean = new MessaggioBean();
        messaggioBean.setId_mittente(id_utente);
        messaggioBean.setId_destinatario(id_utente_contatto);
        messaggioBean.setTesto(testo);
        messaggioBean.setTipo_messaggio("testo");
        messaggioBean.setCancellato(false);
        messaggioBean.setUrl_immagine(null);
        messaggioBean.setLetto(false);
        messaggioBean.inserisciMessaggio();
        return "true";
    }

    /**
     * Funzione che ricevuto id_utente, ritorna la lista di utenti a cui non ha mai scritto.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * */
    @POST
    @Path("/post/utentiNonContattati")
    @Produces("text/plain")
    public String getUtentiNonContattati(@FormParam("id_utente") int id_utente) {
        UtenteBean utenteBean = new UtenteBean();
        utenteBean.setId_utente(id_utente);
        ArrayList<UtenteBean> utenti = utenteBean.getListaUtentiDaContattare();

        // Uso GSON per immettere i dati richiesti da utenti in un formato JSON.
        Gson gson = new Gson();
        // Creo il JSON con un vettore di id, nome e ultimo accesso.
        String json = gson.toJson(utenti);
        return json;
    }

    /**
     * Funzione che ritorna il nome dell'utente da id_utente.
     * @param id_utente id_utente dell'utente che ha effettuato il login.
     * */
    @POST
    @Path("/post/nome")
    @Produces("text/plain")
    public String getNomeUtente(@FormParam("id_utente") int id_utente) {
        UtenteBean utenteBean = new UtenteBean();
        System.out.println(id_utente);
        utenteBean.setId_utente(id_utente);
        if (utenteBean.getUtente()) {
            // Ritorna utente in json
            Gson gson = new Gson();
            String json = gson.toJson(utenteBean);
            return json;
        }
        return null;
    }
}