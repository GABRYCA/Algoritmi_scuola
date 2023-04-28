package eu.anonymousgca.webservicesglassfish;

import jakarta.servlet.http.HttpServletRequest;
import jakarta.servlet.http.HttpSession;
import jakarta.ws.rs.*;

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
}