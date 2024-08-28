package Trie;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.TreeMap;

public class Exercise1268_2 {
    class Solution {
        public List<List<String>> suggestedProducts(String[] products, String searchWord) {
            List<List<String>> res = new ArrayList<>();
            TreeMap<String, Integer> map = new TreeMap<>();
            Arrays.sort(products);
            List<String> productsList = Arrays.asList(products);

            for (int i = 0; i < products.length; i++) {
                map.put(products[i], i);
            }

            String key = "";
            for (char c : searchWord.toCharArray()) {
                key += c;
                String ceiling = map.ceilingKey(key);
                String floor = map.floorKey(key + "~");
                if (ceiling == null || floor == null)
                    break;
                res.add(productsList.subList(map.get(ceiling), Math.min(map.get(ceiling) + 3, map.get(floor) + 1)));
            }

            while (res.size() < searchWord.length())
                res.add(new ArrayList<>());
            return res;

        }
    }

    public static void main(String[] args) {
        Exercise1268_2 exercise = new Exercise1268_2();
        
        Solution solution = exercise.new Solution();
        String[] products = new String[] { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
        String searchWord = "mouse";
        System.out.println(solution.suggestedProducts(products, searchWord));


    } 
}
