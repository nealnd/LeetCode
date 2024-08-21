package BinaryTree;

import java.util.HashMap;

import BinaryTree.Exercise100.TreeNode;

public class Exercise105_2 {
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
            HashMap<Integer, Integer> inMap = new HashMap<>();
            for (int i = 0; i < inorder.length; i++)
                inMap.put(inorder[i], i);
            TreeNode root = buildTree(preorder, 0, preorder.length - 1, inorder, 0, inorder.length - 1, inMap);
            return root;
        }

        public TreeNode buildTree(int[] preorder, int preStart, int preEnd, int[] inorder, int inStart, int inEnd,
                HashMap<Integer, Integer> inMap) {
            if (preStart > preEnd || inStart > inEnd)
                return null;

            TreeNode root = new TreeNode(preorder[preStart]);
            int inRoot = inMap.get(root.val);
            int numsLeft = inRoot - inStart;

            root.left = buildTree(preorder, preStart + 1, preStart + numsLeft, inorder, inStart, inRoot - 1, inMap);
            root.right = buildTree(preorder, preStart + numsLeft + 1, preEnd, inorder, inRoot + 1, inEnd, inMap);
            return root;
        }

    }

    public static void main(String[] args) {
        Exercise105_2 exercise = new Exercise105_2();
        Solution solution = exercise.new Solution();
        /*
         * TreeNode node8 = exercise.new TreeNode(8);
         * TreeNode node7 = exercise.new TreeNode(7, null, node8);
         * TreeNode node6 = exercise.new TreeNode(6);
         * TreeNode node5 = exercise.new TreeNode(5, null, node7);
         * TreeNode node4 = exercise.new TreeNode(4, node5, node6);
         * TreeNode node3 = exercise.new TreeNode(20,node4,node5);
         * TreeNode node2 = exercise.new TreeNode(9);
         * TreeNode node1 = exercise.new TreeNode(3,node2, node3);
         */
        int[] preorder = new int[] { 3, 9, 20, 15, 7 };
        int[] inorder = new int[] { 9, 3, 15, 20, 7 };
        TreeNode root = solution.buildTree(preorder, inorder);
    }
}
