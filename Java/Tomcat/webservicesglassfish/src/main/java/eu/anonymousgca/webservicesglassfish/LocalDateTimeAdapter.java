package eu.anonymousgca.webservicesglassfish;

import com.google.gson.*;

import java.lang.reflect.Type;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class LocalDateTimeAdapter implements JsonSerializer<LocalDateTime>, JsonDeserializer<LocalDateTime> {

    public JsonElement serialize(LocalDateTime date, Type typeOfSrc, JsonSerializationContext context) {
        return new JsonPrimitive(date.format(DateTimeFormatter.ISO_LOCAL_DATE_TIME)); // "yyyy-mm-ddThh:mm:ss"
    }

    public LocalDateTime deserialize(JsonElement json, Type typeOfT, JsonDeserializationContext context) throws JsonParseException {
        return LocalDateTime.parse(json.getAsJsonPrimitive().getAsString(), DateTimeFormatter.ISO_LOCAL_DATE_TIME);
    }
}
