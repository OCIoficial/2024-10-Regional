// @ocimatic should-fail=[st3, st4]

import java.util.*;
import java.io.*;

class apuesta {
    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());

        StringTokenizer st = new StringTokenizer(in.readLine());

        int coins[] = new int[n];
        for (int i = 0; i < n; ++i) {
            coins[i] = Integer.parseInt(st.nextToken());
        }

        int total = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += coins[k];
                }
                if (sum > 0) total += 1;
            }
        }
        System.out.println(total);
    }
}
