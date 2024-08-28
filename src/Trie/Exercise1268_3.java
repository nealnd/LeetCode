package Trie;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Exercise1268_3 {
    class Solution {
        public List<List<String>> suggestedProducts(String[] products, String searchWord) {
            List<List<String>> ans = new ArrayList<>();
            Arrays.sort(products); // sort products.
            for (int i = 1; i <= searchWord.length(); ++i) {
                String cur = searchWord.substring(0, i);
                int k = Arrays.binarySearch(products, cur);
                while (k > 0 && cur.equals(products[k - 1])) // in case there are more than 1 cur in products.
                    --k; // find the first one. 
                if (k < 0) // no cur in products. 
                    k = ~k; // find the first one larger than cur.
                List<String> suggestion = new ArrayList<>();
                for (int j = k + 3; k < products.length && k < j && products[k].startsWith(cur); ++k)
                    suggestion.add(products[k]);
                ans.add(suggestion);
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise1268_3 exercise = new Exercise1268_3();
        
        Solution solution = exercise.new Solution();
        String[] products = new String[] { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
        String searchWord = "mouse";
        System.out.println(solution.suggestedProducts(products, searchWord));


    } 
}
