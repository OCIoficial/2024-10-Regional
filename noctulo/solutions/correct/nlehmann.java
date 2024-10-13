import java.util.*;
import java.io.*;

class noctulo {
    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        String ricardo = in.readLine();
        String noctulo = in.readLine();

        for (int i = 0; i < 35; ++i) {
            if (ricardo.charAt(i % 7) == noctulo.charAt(i%5)) {
                System.out.println(i);
                return;
            }
        }

        System.out.println("No nos vemos nunca");
    }
}
