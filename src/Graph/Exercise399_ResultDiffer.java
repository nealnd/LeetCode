package Graph;

import java.util.ArrayList;
import java.util.List;

import java.util.HashMap;
import java.util.HashSet;

public class Exercise399_ResultDiffer {
    class Solution {
        public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {

            HashMap<String, ArrayList<Edge>> adj = new HashMap<>();
            for (int i = 0; i < queries.size(); i++) {
                adj.put(queries.get(i).get(0), new ArrayList<>());
            }
            for (int i = 0; i < equations.size(); i++) {
                ArrayList<Edge> temp = adj.getOrDefault(equations.get(i).get(0), new ArrayList<Edge>());
                Edge edge = new Edge(equations.get(i).get(0), equations.get(i).get(1), values[i]);
                temp.add(edge);
                adj.put(equations.get(i).get(0), temp);
                ArrayList<Edge> temp1 = adj.getOrDefault(equations.get(i).get(1), new ArrayList<Edge>());
                temp1.add(edge);
                adj.put(equations.get(i).get(1), temp1);

            }

            double[] answer = new double[queries.size()];
            for (int i = 0; i < answer.length; i++) {

                String index = queries.get(i).get(0);
                String target = queries.get(i).get(1);
                answer[i] = dfs(target, adj, index,new HashSet<String>());

            }
            return answer;

        }

        private double dfs(String target, HashMap<String, ArrayList<Edge>> adj, String index, HashSet<String> visited) {
            visited.add(index);

            if (adj.get(index).size() == 0||adj.get(index)==null)
                return -1;
            for (Edge item : adj.get(index)) {
                if (visited.contains(target))
                    return 1;
                if (!visited.contains(item.other(index))) {
                    double answer = dfs(target, adj, item.other(index), visited);
                    if(answer!=-1)
                        return answer * item.factor(index);

                }
            }
            
    

            return  -1;
        }

        private class Edge {

            String v;
            String w;
            double ans;

            public Edge(String s, String w, double values) {
                this.v = s;
                this.w = w;
                this.ans = values;
            }
            
            public double factor(String s) {
                if (this.v == s)
                    return ans;
                else
                    return 1 / ans;
            }
            
            public String other(String s) {
                if (this.v == s)
                return this.w;
            else
                return this.v;
            }

        }
    }
    public static void main(String[] args) {
        Exercise399_ResultDiffer exercise = new Exercise399_ResultDiffer();
        Solution solution = exercise.new Solution();
        List<List<String>> equations = new ArrayList<>(List.of(List.of("a", "b"),List.of("b", "c"),List.of("bc", "cd")));// , List.of("b", "c")
        double[] values = new double[] { 1.5,2.5,5.0 };
        List<List<String>> queries=new ArrayList<>(List.of(List.of("a","c"), List.of("c", "b"),List.of("bc","cd"),
                List.of("cd","bc")));

        double[] ans = solution.calcEquation(equations, values, queries);
    }

}
