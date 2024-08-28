package Trie;

import java.util.ArrayList;
import java.util.List;

public class Exercise1268_4 {
    class Trie {
        static int R = 26;
        Node root;

        private class Node {

            boolean end = false;
            Node[] Cha = new Node[R];
        }

        public Trie() {

        }

        public void insert(String word) {
            root = insert(root, word, 0);
        }

        private Node insert(Node x, String word, int index) {
            if (x == null)
                x = new Node();
            if (index == word.length()) {
                x.end = true;
                return x;
            }
            int temp = word.charAt(index) - 'a';
            x.Cha[temp] = insert(x.Cha[temp], word, index + 1);
            return x;
        }

        public ArrayList<String> keysWithPrefix(String prefix) {
            ArrayList<String> results = new ArrayList<>();
            Node x = get(root, prefix, 0);
            collect(x, new StringBuilder(prefix), results);
            return results;

        }

        private Node get(Node x, String prefix, int index) {
            if (x == null)
                return null;
            if (index == prefix.length())
                return x;
            int temp = prefix.charAt(index) - 'a';
            return get(x.Cha[temp], prefix, index + 1);
        }

        private void collect(Node x, StringBuilder prefix, ArrayList<String> results) {
            if (x == null)
                return;
            if (x.end)
                results.add(prefix.toString());
            for (int i = 0; i < R; i++) {
                prefix.append((char) ('a' + i));
                collect(x.Cha[i], prefix, results);
                prefix.deleteCharAt(prefix.length() - 1);// don't forget this
            }
        }

    }

    class Solution {
        public List<List<String>> suggestedProducts(String[] products, String searchWord) {
            Trie trie = new Trie();
            for (var item : products) {
                trie.insert(item);
            }

            ArrayList<List<String>> ans = new ArrayList<>();
            for (int i = 0; i < searchWord.length(); i++) {
                ArrayList<String> temp = trie.keysWithPrefix(searchWord.substring(0, i + 1));
                ans.add(temp.subList(0, Math.min(3, temp.size())));

            }
            return ans;

        }

    }

    public static void main(String[] args) {
        Exercise1268_4 exercise = new Exercise1268_4();

        Solution solution = exercise.new Solution();
        String[] products = new String[] { "mobile", "mouse", "moneypot", "monitor", "mousepad" };
        String searchWord = "mouse";
        System.out.println(solution.suggestedProducts(products, searchWord));

    }

}
