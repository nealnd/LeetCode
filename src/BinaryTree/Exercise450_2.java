package BinaryTree;
public class Exercise450_2 {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;

        TreeNode() {
        }

        TreeNode(int val) {
            this.val = val;
        }

        TreeNode(int val, TreeNode left, TreeNode right) {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    class Solution {
        public TreeNode deleteNode(TreeNode root, int key) {
            if (root == null)
                return null;
            if (key < root.val)
                root.left = deleteNode(root.left, key);
            else if (key > root.val)
                root.right = deleteNode(root.right, key);

            else {

                if (root.left == null)
                    return root.right;
                if (root.right == null)
                    return root.left;

                TreeNode temp = root;
                root = findMinNode(temp.right);
               
                root.right = deleteMinNode(temp.right);
                root.left = temp.left;

            }

            return root;

        }

        private TreeNode findMinNode(TreeNode node) {
            if (node.left == null)
                return node;

            else
                return findMinNode(node.left);
        }

        private TreeNode deleteMinNode(TreeNode node) {
            if (node.left == null)
                return node.right;
            node.left = deleteMinNode(node.left);
            return node;
        }
    }

    public static void main(String[] args) {
        Exercise450_2 exercise = new Exercise450_2();
        Solution solution = exercise.new Solution();
        TreeNode node6 = exercise.new TreeNode(7);
        TreeNode node5 = exercise.new TreeNode(4);
        TreeNode node4 = exercise.new TreeNode(2);
        TreeNode node3 = exercise.new TreeNode(6, null, node6);
        TreeNode node2 = exercise.new TreeNode(3, node4, node5);
        TreeNode node1 = exercise.new TreeNode(5, node2, node3);
        TreeNode s = solution.deleteNode(node1, 3);

    }
}
