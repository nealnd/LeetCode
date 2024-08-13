import java.util.HashMap;
public class Exercise437 {
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
        public int pathSum(TreeNode root, int targetSum) {

            HashMap<Integer, Integer> map = new HashMap<>();
            map.put(0, 1);
            return pathSum(root, targetSum, map, 0);

        }

        private int pathSum(TreeNode node, int targetSum, HashMap<Integer, Integer> map, int curSum) {
            if (node == null)
                return 0;
            curSum += node.val;

             // get the number of valid path, ended by the current node
             int ans = map.getOrDefault(curSum - targetSum, 0);
            
             // update the map with the current sum, so the map is good to be passed to the next recursion
            map.put(curSum, map.getOrDefault(curSum, 0) + 1);
            ans = ans + pathSum(node.left, targetSum, map, curSum) + pathSum(node.right, targetSum, map, curSum);
            
            // restore the map, as the recursion goes from the bottom to the top
            map.put(curSum, map.get(curSum) - 1);
            return ans;
        }
    }
    
    public static void main(String[] args) {
        Exercise437 exercise = new Exercise437();
        Solution solution = exercise.new Solution();

        TreeNode node8 = exercise.new TreeNode(1);
        TreeNode node7 = exercise.new TreeNode(2, null, node8);
        TreeNode node6 = exercise.new TreeNode(1);
        TreeNode node5 = exercise.new TreeNode(1, null, node7);
        TreeNode node4 = exercise.new TreeNode(2, node5, node6);
        TreeNode node3 = exercise.new TreeNode(2);
        TreeNode node2 = exercise.new TreeNode(1, node3, node4);
        TreeNode node1 = exercise.new TreeNode(2, null, node2);
        System.out.println(solution.pathSum(node1, 3));
    }
}
