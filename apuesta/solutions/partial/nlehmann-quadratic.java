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

        int prefix_sum[] = new int[n+1];
        for (int i = 1; i <= n; ++i) {
            prefix_sum[i] = coins[i-1] + prefix_sum[i - 1];
        }

        int total = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int sum = prefix_sum[j] - prefix_sum[i-1];
                if (sum > 0) total += 1;
            }
        }
        System.out.println(total);
    }
}
