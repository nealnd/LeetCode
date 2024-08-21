package BinaryTree;

import java.util.HashMap;
import java.util.Queue;
import java.util.LinkedList;

public class Exercise105_1 {
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
        public TreeNode buildTree(int[] preorder, int[] inorder) {
            HashMap<Integer, Integer> left = new HashMap<>();
            HashMap<Integer, Integer> right = new HashMap<>();
            int i = 0, j = 0;
            while (i < preorder.length-1 && j < preorder.length-1) {
                while (i < preorder.length-1&& preorder[i] != inorder[j]) {
                    left.put(preorder[i], preorder[i + 1]);
                    i++;
                }
                while (  j < preorder.length-1&&left.containsKey(inorder[j + 1]))
                    j++;
                if (i < preorder.length - 1)
                    right.put(inorder[j++], preorder[++i]);

            }

            TreeNode root = new TreeNode(preorder[0]);
            Queue<TreeNode> queue = new LinkedList<>();
            queue.offer(root);
            while (!queue.isEmpty()) {
                TreeNode temp = queue.poll();
                if (left.containsKey(temp.val)) {
                    temp.left = new TreeNode(left.get(temp.val));
                    queue.offer(temp.left);
                }
                if (right.containsKey(temp.val)) {
                    temp.right = new TreeNode(right.get(temp.val));
                    queue.offer(temp.right);
                }
            }
            return root;
        }
    }
    
    public static void main(String[] args) {
        Exercise105_1 exercise = new Exercise105_1();
        Solution solution = exercise.new Solution();
/* 
TreeNode node8 = exercise.new TreeNode(8);
TreeNode node7 = exercise.new TreeNode(7, null, node8);
TreeNode node6 = exercise.new TreeNode(6);
TreeNode node5 = exercise.new TreeNode(5, null, node7);
TreeNode node4 = exercise.new TreeNode(4, node5, node6);
TreeNode node3 = exercise.new TreeNode(20,node4,node5);
TreeNode node2 = exercise.new TreeNode(9);
TreeNode node1 = exercise.new TreeNode(3,node2, node3);
*/
int[] preorder = new int[] { 3, 9, 20, 15, 7 };
int[] inorder = new int[] { 9, 3, 15, 20, 7 };
TreeNode root = solution.buildTree(preorder, inorder);
    }
}
