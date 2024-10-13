// @ocimatic should-fail=[st1, st2]
import java.util.*;
import java.io.*;

class tranvia {
    static public void main(String args[]) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(in.readLine());

        int L = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int E = Integer.parseInt(st.nextToken());

        int stations[] = new int[N + 1];
        st = new StringTokenizer(in.readLine());
        for (int i = 1; i <= N; ++i) {
            stations[i] = Integer.parseInt(st.nextToken());
        }

        int trains[] = new int[M + 1];
        Arrays.fill(trains, -1);

        TreeMap<Integer, Integer> sorted_trains = new TreeMap<>();
        for (int e = 0; e < E; ++e) {
            st = new StringTokenizer(in.readLine());

            int t = Integer.parseInt(st.nextToken());

            if (t == 1) {
                int j = Integer.parseInt(st.nextToken());
                int p = Integer.parseInt(st.nextToken());

                if (trains[j] != -1) {
                    int count = sorted_trains.remove(trains[j]);
                    if (count > 1) {
                        // debiese ser sorted_trains.put(trains[j], count - 1);
                        sorted_trains.put(p, count - 1);
                    }
                }

                trains[j] = p;
                if (p != -1) {
                    int count = 0;
                    if (sorted_trains.containsKey(p)) {
                        count = sorted_trains.get(p);
                    }
                    sorted_trains.put(p, count + 1);
                }
            } else {
                int i = Integer.parseInt(st.nextToken());
                Integer p = sorted_trains.floorKey(stations[i]);
                if (p == null) {
                    System.out.println(-1);
                } else {
                    System.out.println(stations[i] - p);
                }
            }
        }
    }
}
