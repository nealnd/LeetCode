import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Exercise49 {
    class Solution {
        public List<List<String>> groupAnagrams(String[] strs) {

            Map<String, List<String>> map = new HashMap<>();

            for (String word : strs) {
                char[] chars = word.toCharArray();
                Arrays.sort(chars);
                String sortedWord = new String(chars);

                if (!map.containsKey(sortedWord)) {
                    map.put(sortedWord, new ArrayList<>());
                }

                map.get(sortedWord).add(word);
            }

            return new ArrayList<>(map.values());
        }
    }

    public static void main(String[] args) {
        Exercise49 exercise = new Exercise49();
        Solution solution = exercise.new Solution();

        String[] strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
        List<List<String>> result = solution.groupAnagrams(strs);
        for (List<String> triplet : result) {
            System.out.println(triplet);
        }

    }
}
