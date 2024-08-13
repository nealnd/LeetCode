import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class Exercise199_2 {
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
            if (root == null)
                return new ArrayList();
            Queue<TreeNode> queue = new LinkedList();
            queue.offer(root);
            List<Integer> res = new ArrayList();

            while (!queue.isEmpty()) {
                int size = queue.size();

                while (size-- > 0) {
                    TreeNode cur = queue.poll();
                    if (size == 0)
                        res.add(cur.val);

                    if (cur.left != null)
                        queue.offer(cur.left);
                    if (cur.right != null)
                        queue.offer(cur.right);
                }
            }

            return res;
        }
    }
    public static void main(String[] args) {
        Exercise199_2 exercise = new Exercise199_2();
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
