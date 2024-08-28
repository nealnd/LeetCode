package Trie;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.TreeSet;



public class Exercise1268_1 {
    class Solution {
        public List<List<String>> suggestedProducts(String[] products, String searchWord) {
            TreeSet<String> set = new TreeSet<>();
            for (var item : products)
                set.add(item);
            List<List<String>> ans = new ArrayList<>();
            for (int i = 1; i <= searchWord.length(); i++) {
                List<String> temp = new ArrayList<>();
                int j = 0;
                
                // searchWord.substring(0, i) + "~" is 
                Iterator<String> it = set.subSet(searchWord.substring(0, i), true, searchWord.substring(0, i) + "~", false).iterator();
                while (j++ < 3 && it.hasNext())
                {
                    temp.add(it.next());
                   
                }
                ans.add(temp);
            }
            return ans;
        }
    }

    public static void main(String[] args) {
        Exercise1268_1 exercise = new Exercise1268_1();
        
        Solution solution = exercise.new Solution();
        String[] products = new String[] { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
        String searchWord = "mouse";
        System.out.println(solution.suggestedProducts(products, searchWord));


    } 
}
