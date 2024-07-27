import java.util.ArrayList;
import java.util.List;

public class Exercise94_1 {
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
        public List<Integer> inorderTraversal(TreeNode root) {
            List<Integer> list = new ArrayList<>();
            inorder(root, list);
            return list;

        }

        public void inorder(TreeNode root, List<Integer> list) {
            if (root == null)
                return;

            inorder(root.left, list);
            list.add(root.val);
            inorder(root.right, list);
        }
    }

    public static void main(String[] args) {
        Exercise94_1 exercise = new Exercise94_1();
        Solution solution = exercise.new Solution();

        TreeNode node3 = exercise.new TreeNode(3);
        TreeNode node2 = exercise.new TreeNode(2, node3, null);
        TreeNode node1 = exercise.new TreeNode(1, null, node2);
        List<Integer> list = solution.inorderTraversal(node1);
        for (Integer item : list)
            System.out.println(item);
    }
}