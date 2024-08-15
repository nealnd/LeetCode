package BinaryTree;
public class Exercise450_1 {
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

        public TreeNode deleteNode(TreeNode root, int key) {
            TreeNode[] ans = find(root, key, null);
            TreeNode pre_after_ans = null;
            TreeNode after_ans;
            if (ans == null)
                return root;

            if (ans[1].right != null) {
                after_ans = ans[1].right;
                while (after_ans.left != null) {
                    pre_after_ans = after_ans;
                    after_ans = after_ans.left;
                }
            } else
                after_ans = null;

            if (ans[1].left == null && ans[1].right == null) {

                if (root == ans[1])
                    return null;

                if (ans[0].left == ans[1])
                    ans[0].left = null;
                else
                    ans[0].right = null;
            }

            else if (ans[1].right != null) {
                after_ans.left = ans[1].left;
                if (ans[0] == null) {
                    root = after_ans;
                } else if (ans[0].left == ans[1]) {
                    ans[0].left = after_ans;

                } else if (ans[0].right == ans[1]) {
                    ans[0].right = after_ans;
                }
                if (after_ans != ans[1].right) {
                    pre_after_ans.left = after_ans.right;
                    after_ans.right = ans[1].right;

                }

                ans[1] = null;

            } else {
                if (ans[0] == null)
                    root = ans[1].left;
                else if (ans[0].left == ans[1]) {
                    ans[0].left = ans[1].left;

                } else if (ans[0].right == ans[1]) {
                    ans[0].right = ans[1].left;
                }
                ans[1] = null;
            }
            return root;

        }

        private TreeNode[] find(TreeNode node, int key, TreeNode pre) {

            if (node == null)
                return null;
            if (node.val == key)
                return new TreeNode[] { pre, node };

            TreeNode[] temp = find(node.left, key, node);
            if (temp == null)
                temp = find(node.right, key, node);
            return temp;

        }
    }

    public static void main(String[] args) {
        Exercise450_1 exercise = new Exercise450_1();
        Solution solution = exercise.new Solution();

        // TreeNode node8 = exercise.new TreeNode(8);
        // TreeNode node7 = exercise.new TreeNode(7, null, node8);
        /*
         * TreeNode node6 = exercise.new TreeNode(7);
         * TreeNode node5 = exercise.new TreeNode(4);
         * TreeNode node4 = exercise.new TreeNode(2);
         * TreeNode node3 = exercise.new TreeNode(6,null,node6);
         * TreeNode node2 = exercise.new TreeNode(3, node4, node5);
         * TreeNode node1 = exercise.new TreeNode(5, node2, node3);
         */

        TreeNode node6 = exercise.new TreeNode(80);
        TreeNode node5 = exercise.new TreeNode(60);
        TreeNode node4 = exercise.new TreeNode(40);
        TreeNode node3 = exercise.new TreeNode(70, node5, node6);
        TreeNode node2 = exercise.new TreeNode(30, null, node4);
        TreeNode node1 = exercise.new TreeNode(50, node2, node3);

        TreeNode s = solution.deleteNode(node1, 50);

    }
}
