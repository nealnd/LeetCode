import java.util.ArrayList;
import java.util.List;

public class Exercise199_1 {
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
     

        public List<Integer> rightSideView(TreeNode root) {
            List<Integer> list = new ArrayList<>();
            int index = 0;
            helper(root,list, 0);
            return list;
            
        
        }

        public void helper(TreeNode root, List<Integer> list,int count) {

            if (root == null) {
                return;

            }
            if (list.size() <= count)
                list.add(count, root.val);

            count++;

            helper(root.right, list,count);
            helper(root.left, list,count);
          

        }

    }

    public static void main(String[] args) {
        Exercise199_1 exercise = new Exercise199_1();
        Solution solution = exercise.new Solution();

        TreeNode node8 = exercise.new TreeNode(8);
        TreeNode node7 = exercise.new TreeNode(7, null, node8);
        TreeNode node6 = exercise.new TreeNode(6);
        TreeNode node5 = exercise.new TreeNode(5, null, node7);
        TreeNode node4 = exercise.new TreeNode(4, node5, node6);
        TreeNode node3 = exercise.new TreeNode(3);
        TreeNode node2 = exercise.new TreeNode(2, node3, node4);
        TreeNode node1 = exercise.new TreeNode(1, null, node2);
        List<Integer> list = solution.rightSideView(node1);
        for (int item : list)
            System.out.println(item);

    }

}
