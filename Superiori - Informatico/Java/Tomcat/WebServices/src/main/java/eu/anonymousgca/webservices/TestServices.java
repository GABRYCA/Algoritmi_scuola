package eu.anonymousgca.webservices;

import jakarta.ws.rs.*;

@Path("/hello-world")
public class TestServices {
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
}