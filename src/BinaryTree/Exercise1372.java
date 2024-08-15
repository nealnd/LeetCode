package BinaryTree;
public class Exercise1372 {
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
        int maxStep = 0;

        public int longestZigZag(TreeNode root) {
            longestZigZag(root, true, 0);
            longestZigZag(root, false, 0);
            return maxStep;
        }

        private void longestZigZag(TreeNode node, boolean isLeft, int step) {
            if (node == null)
                return;
            maxStep = Math.max(maxStep, step); // update max step sofar
            if (isLeft) {
                longestZigZag(node.left, false, step + 1); // keep going from root to left
                longestZigZag(node.right, true, 1); // restart going from root to right
            } else {
                longestZigZag(node.right, true, step + 1); 
                longestZigZag(node.left, false, 1); 
            }
        }

    }

    public static void main(String[] args) {
        Exercise1372 exercise = new Exercise1372();
        Solution solution = exercise.new Solution();

        TreeNode node8 = exercise.new TreeNode(8);
        TreeNode node7 = exercise.new TreeNode(7, null, node8);
        TreeNode node6 = exercise.new TreeNode(6);
        TreeNode node5 = exercise.new TreeNode(5, null, node7);
        TreeNode node4 = exercise.new TreeNode(4, node5, node6);
        TreeNode node3 = exercise.new TreeNode(3);
        TreeNode node2 = exercise.new TreeNode(2, node3, node4);
        TreeNode node1 = exercise.new TreeNode(1, null, node2);
        System.out.println(solution.longestZigZag(node1));
    }

}
