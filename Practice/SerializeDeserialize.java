import java.util.ArrayList;
import java.util.List;

public class SerializeDeserialize {

    private class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }

    private static int height(TreeNode root){
        if(root == null || (root.right == null && root.left == null)) return 0;
        return 1 + Math.max(height(root.left), height(root.right));
    }

    private static void levelOrder(TreeNode root, int level, List<List<Integer>> ans){
        if(root == null) return;
        if(root.left == null && root.right == null){
            ans.get(level).add(root.val);
            return;
        }

        ans.get(level).add(root.val);
        levelOrder(root.left, level + 1, ans);
        levelOrder(root.right, level + 1, ans);
    }

    static TreeNode r = null;

    private static String serialize(TreeNode root) {
        r = root;

        int level = height(root) + 1;
        List<List<Integer>> ans = new ArrayList<>(level + 1);

        for (int i = 0; i <= level; i++) {
            ans.add(new ArrayList<>());
        }

        levelOrder(root, 0, ans);

        String res = "";
        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans.get(i).size(); i++) {
                res += ans.get(i).get(j) + "";
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    private static TreeNode deserialize(String data) {
        return r;
    }

    public static void main(String[] args) {
        
    }
    
}
