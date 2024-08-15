package BinaryTree;
import java.lang.runtime.TemplateRuntime;
import java.util.LinkedList;
import java.util.Queue;

public class Exercise1161 {
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
        public int maxLevelSum(TreeNode root) {
            Queue<TreeNode> queue = new LinkedList<>();
            int max = Integer.MIN_VALUE;
            int count = 0;
            int ans = 0;
            queue.offer(root);
            while (!queue.isEmpty()) {
                int size = queue.size();
                int sum = 0;
                count++;
                while (size > 0) {
                    TreeNode temp = queue.poll();
                    size--;
                    sum += temp.val;

                    if (temp.left != null)
                        queue.offer(temp.left);
                    if (temp.right != null)
                        queue.offer(temp.right);

                }
                if (sum > max) {
                    max = sum;
                    ans = count;
                }
            }
            return ans;

        }
    }
    public static void main(String[] args) {
        Exercise1161 exercise = new Exercise1161();
        Solution solution = exercise.new Solution();

       // TreeNode node8 = exercise.new TreeNode(8);
        //TreeNode node7 = exercise.new TreeNode(7, null, node8);
        //TreeNode node6 = exercise.new TreeNode(6);
        TreeNode node5 = exercise.new TreeNode(-32127);
        TreeNode node4 = exercise.new TreeNode(-89388, null, node5);
        TreeNode node3 = exercise.new TreeNode(98693);
        TreeNode node2 = exercise.new TreeNode(10250, node3, node4);
        TreeNode node1 = exercise.new TreeNode(987, null, node2);
        System.out.println(solution.maxLevelSum(node1));
    }

}
