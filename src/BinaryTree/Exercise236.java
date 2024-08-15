package BinaryTree;
public class Exercise236 {
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
        public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
            TreeNode left, right;

            if (root == null)
                return null;
            if (root == p || root == q)
                return root;

            left = lowestCommonAncestor(root.left, p, q);
            right = lowestCommonAncestor(root.right, p, q);

            if (left == null)
                return right;
            else if (right == null)
                return left;
            else
                return root;

        }
    }

    public static void main(String[] args) {
        Exercise236 exercise = new Exercise236();
        Solution solution = exercise.new Solution();
        TreeNode node6 = exercise.new TreeNode(7);
        TreeNode node5 = exercise.new TreeNode(4);
        TreeNode node4 = exercise.new TreeNode(2);
        TreeNode node3 = exercise.new TreeNode(6, null, node6);
        TreeNode node2 = exercise.new TreeNode(3, node4, node5);
        TreeNode node1 = exercise.new TreeNode(5, node2, node3);
        TreeNode test = solution.lowestCommonAncestor(node1, node2, node5);

    }
}
