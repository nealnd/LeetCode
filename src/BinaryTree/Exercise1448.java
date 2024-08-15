package BinaryTree;
public class Exercise1448 {

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
        public int goodNodes(TreeNode root) {
            if (root == null)
                return 0;
            int count = 0;
            int max = root.val;
            count = goodNodes(root, count, max);
            return count;
        }

        public int goodNodes(TreeNode node, int count, int max) {
            if (node == null)
                return count;
            if (node != null && node.val >= max) {
                count++;
                max = node.val;

            }
            count = goodNodes(node.left, count, max);
            count = goodNodes(node.right, count, max);
            return count;
        }
    }

    public static void main(String[] args) {
        Exercise1448 exercise = new Exercise1448();
        Solution solution = exercise.new Solution();

        TreeNode node6 = exercise.new TreeNode(5);
        TreeNode node5 = exercise.new TreeNode(1);
        TreeNode node4 = exercise.new TreeNode(4, node5, node6);
        TreeNode node3 = exercise.new TreeNode(3);
        TreeNode node2 = exercise.new TreeNode(1, node3, null);
        TreeNode node1 = exercise.new TreeNode(3, node2, node4);
        System.out.println(solution.goodNodes(node1));
    }
}
