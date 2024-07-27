
public class Exercise100 {
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
        public boolean isSameTree(TreeNode p, TreeNode q) {
            if (p == null && q == null)
                return true;
            else if ((p != null && q != null) && p.val == q.val)
                return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
            else
                return false;

        }

    }
    
        public static void main(String[] args) {
        Exercise100 exercise = new Exercise100();
        Solution solution = exercise.new Solution();

        TreeNode node1_3 = exercise.new TreeNode(3);
        TreeNode node1_2 = exercise.new TreeNode(2, node1_3, null);
        TreeNode node1_1 = exercise.new TreeNode(1, null, node1_2);
       
        TreeNode node2_3 = exercise.new TreeNode(3);
        TreeNode node2_2 = exercise.new TreeNode(2, node2_3, null);
        TreeNode node2_1 = exercise.new TreeNode(1, null, node2_2);

        System.out.println(solution.isSameTree(node1_1, node2_1));
    }
}
