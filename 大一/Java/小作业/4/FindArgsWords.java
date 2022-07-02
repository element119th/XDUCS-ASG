import java.util.*;

public class FindArgsWords {
    public static void main(String[] args) {
        Map<String, Integer> map = new HashMap<>();
        for (int i = 0; i < args.length; i++) {
            if (map.containsKey(args[i]))
            {
                int count = map.get(args[i]);
                map.put(args[i], count + 1);
            }
            else {
                map.put(args[i], 1);
            }
        }
        Set<String> keys = map.keySet();
        TreeSet<String> sortedKeys = new TreeSet<>(keys);
        System.out.print("<");
        for (String key : sortedKeys)
        {
            if (map.get(key)>=1)
            {
            System.out.printf("%s=%s ", key, map.get(key));
            }
        }
        System.out.print(">");
    }
}
