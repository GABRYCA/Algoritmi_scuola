package eu.anonymousgca.webservicesglassfish;

import jakarta.ws.rs.*;

@Path("/hello-world")
public class Resource {
    @GET
    @Produces("text/plain")
    public String hello() {
        return "Hello, World!";
    }
}