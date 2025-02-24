public class MakeBTFromPrePost {
    private static class TreeNode{
        int val;
        TreeNode left;
        TreeNode right;
        public TreeNode(int val){
            this.val = val;
            this.left = null;
            this.right = null;
        }
    }
    private static int ind = 0;
    public static TreeNode makeBinaryTreePrePost(int[] pre, int[] post, int l, int h){
        if (ind >= pre.length || l > h) return null;


        TreeNode root = new TreeNode(pre[ind]);
        ind++;

        if(l == h) return root;

        int devideIndex = h;
        for(int j = h; j >= l; j--){
            if(post[j] == pre[ind]){
                devideIndex = j;
                break;
            }
        }


        root.left = makeBinaryTreePrePost(pre, post, l, devideIndex);
        root.right = makeBinaryTreePrePost(pre, post, devideIndex + 1, h - 1);

        return root;
    }
    public static void main(String[] args){
        int[] preorder = {1,2,4,5,3,6,7};
        int[] postorder = {4,5,2,6,7,3,1};
        TreeNode root = makeBinaryTreePrePost(preorder, postorder, 0,preorder.length - 1);
    }
}
