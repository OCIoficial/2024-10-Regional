import java.util.*;
import java.io.*;

class apuesta {
    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());

        StringTokenizer st = new StringTokenizer(in.readLine());
        long v[] = new long[n];
        for (int i = 0; i < n; ++i) {
            v[i] = Integer.parseInt(st.nextToken());
        }

        Stack<Long> sl = new Stack<>();
        Stack<Long> sr = new Stack<>();

        long l = 0;
        long r = 0;
        long actual = 1;
        long exitosos = 0;
        long totales = 0;

        for (int i = 0; i < n; ++i) {
            if (v[i] == -1) {
                sr.push(actual);
                r += actual;
                if (!sl.isEmpty()) {
                    actual = sl.pop();
                    l -= actual;
                    actual++;
                } else {
                    actual = 1;
                }
            } else {
                sl.push(actual);
                l += actual;
                if (!sr.empty()) {
                    actual = sr.pop();
                    r -= actual;
                    actual++;
                } else {
                    actual = 1;
                }
            }
            exitosos += l;
            totales += i+1;
        }
        System.out.println(exitosos);
    }
}
