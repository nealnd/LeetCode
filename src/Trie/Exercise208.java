package Trie;

public class Exercise208 {

    class Trie {
        private static int R = 26;
        Node root;

        private class Node {
            boolean ifEnd = false;
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
                x.ifEnd = true;
                return x;
            }
            int temp = word.charAt(index) - 'a';
            x.Cha[temp] = insert(x.Cha[temp], word, index + 1);
            return x;
        }

        public boolean search(String word) {
            return search(root, word, 0);
        }

        private boolean search(Node x, String word, int index) {
            if (x == null)
                return false;
            if (index == word.length())
                return x.ifEnd;
            int temp = word.charAt(index) - 'a';
            return search(x.Cha[temp], word, index + 1);
        }

        public boolean startsWith(String prefix) {
            return startsWith(root, prefix, 0);

        }

        private boolean startsWith(Node x, String prefix, int index) {
            if (x == null)
                return false;
            if (index == prefix.length())
                return true;
            int temp = prefix.charAt(index) - 'a';
            return startsWith(x.Cha[temp], prefix, index + 1);
        }

        public void delete(String word) {
            root = delete(root, word, 0);

        }

        private Node delete(Node x, String word, int index) {
            if (x == null)
                return null;
            if (index == word.length())
                x.ifEnd = false;
            else {
                int temp = word.charAt(index) - 'a';
                x.Cha[temp] = delete(x.Cha[temp], word, index + 1);
            }
            if (x.ifEnd)
                return x;
            for (int c = 0; c < R; c++)// this is important
                if (x.Cha[c] != null)
                    return x;
            return null;
        }
    }

    public static void main(String[] args) {
        Exercise208 exercise = new Exercise208();

        Trie trie = exercise.new Trie();
        trie.insert("apple");
        System.out.println(trie.search("apple"));
        System.out.println(trie.search("app"));
        System.out.println(trie.startsWith("app"));
        trie.insert("app");
        System.out.println(trie.search("app"));
        trie.delete("apple");

    }

}
