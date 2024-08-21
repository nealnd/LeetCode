package Graph;

import java.util.List;
import java.util.HashMap;
import java.util.HashSet;
import java.util.ArrayList;

public class Exercise399 {
    class Solution {
        public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
            HashMap<String, HashMap<String, Double>> graph = new HashMap<>();
            for (int i = 0; i < equations.size(); i++) {
                String u = equations.get(i).get(0);
                String v = equations.get(i).get(1);
                graph.putIfAbsent(u, new HashMap<>());
                graph.putIfAbsent(v, new HashMap<>());
                graph.get(u).put(v, values[i]);
                graph.get(v).put(u, 1 / values[i]);

            }

            double[] answer = new double[queries.size()];
            for (int i = 0; i < queries.size(); i++) {
                String index = queries.get(i).get(0);
                String target = queries.get(i).get(1);
                answer[i] = dfs(graph, index, target, new HashSet<>());
            }

            return answer;
        }

        private double dfs(HashMap<String, HashMap<String, Double>> graph, String index, String target,
                HashSet<String> visited) {

            if (graph.get(index) == null)
                return -1;
            if (graph.get(index).containsKey(target))
                return graph.get(index).get(target);
            visited.add(index);
            for (var item : graph.get(index).keySet()) {

                if (!visited.contains(item)) {
                    double ans = dfs(graph, item, target, visited);
                    if (ans != -1)
                        return graph.get(index).get(item) * ans;
                }
            }

            return -1;
        }

    }

    public static void main(String[] args) {
        Exercise399 exercise = new Exercise399();
        Solution solution = exercise.new Solution();
        List<List<String>> equations = new ArrayList<>(
                List.of(List.of("x1", "x2"), List.of("x2", "x3"), List.of("x3", "x4"), List.of("x4", "x5")));// ,
                                                                                                             // List.of("b",
                                                                                                             // "c")
        double[] values = new double[] { 3.0, 4.0, 5.0, 6.0 };
        List<List<String>> queries = new ArrayList<>(
                List.of(List.of("x1", "x5"), List.of("x5", "x2"), List.of("x2", "x4"),
                        List.of("x2", "x2"), List.of("x2", "x9"), List.of("x9", "x9")));

        double[] ans = solution.calcEquation(equations, values, queries);
    }
}
