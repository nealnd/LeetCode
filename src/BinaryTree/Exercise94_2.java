package BinaryTree;
import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Exercise94_2 {
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
            Stack<TreeNode> stack = new Stack<>();
            if (root == null)
                return list;
            while (!stack.isEmpty()||root!=null) {
                while (root != null) {

                    stack.push(root);
                    root = root.left;

                }
                root=stack.pop();
                list.add(root.val);
                root = root.right;

            }
            return list;

        }
    }

    public static void main(String[] args) {
        Exercise94_2 exercise = new Exercise94_2();
        Solution solution = exercise.new Solution();

        TreeNode node3 = exercise.new TreeNode(3);
        TreeNode node2 = exercise.new TreeNode(2, node3, null);
        TreeNode node1 = exercise.new TreeNode(1, null, node2);
        List<Integer> list = solution.inorderTraversal(node1);
        for (Integer item : list)
            System.out.println(item);
            
    }
}
