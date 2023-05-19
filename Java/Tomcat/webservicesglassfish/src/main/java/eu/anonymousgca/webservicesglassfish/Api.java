package eu.anonymousgca.webservicesglassfish;

import jakarta.ws.rs.ApplicationPath;
import jakarta.ws.rs.core.Application;

import java.util.HashSet;
import java.util.Set;

@ApplicationPath("/api")
public class Api extends Application {
    /**
     * Collezione di risorse da "SERVIRE".
     * */
    @Override
    public Set<Class<?>> getClasses() {
        HashSet hashSet = new HashSet<Class<?>>();
        hashSet.add(ChiamateAPI.class);
        return hashSet;
    }
}
