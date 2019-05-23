package test;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;


public  class BinTree{
	private BinTree left, root, right;
	private Object data;
	private List<BinTree> datas;
	
	public BinTree(BinTree left, BinTree root, BinTree right, Object data) {
		this.left  = left;
		this.root  = root;
		this.right = right;
		this.data  = data;
	}
	
	public BinTree(Object obj) {
		this(null, null, null, obj);
	}
	
	public BinTree() {
		
	}
	
	public void create(Object[] objs) {
		datas = new ArrayList<>();
		for (Object object : objs) {
			datas.add(new BinTree(object));
		}
		for (int i = datas.size()/2 -1; i >= 0; i--) {
			datas.get(i).root = datas.get(i);
			datas.get(i).left = datas.get(2*i+1);
			if (i*2 +2 < datas.size()) {
				datas.get(i).right = datas.get(2*i+2);
			}
		}
		root = datas.get(0);
	}
	
	public void preOrder(BinTree root) {
		if (root != null) {
			System.out.print(root.data + ",");
			preOrder(root.left);
			preOrder(root.right);
		}
	}
	
	public void midOrder(BinTree root) {
		if (root != null) {
			midOrder(root.left);
			System.out.print(root.data + ",");
			midOrder(root.right);
		}
	}
	
	public void afterOrder(BinTree root) {
		if (root != null) {
			afterOrder(root.left);
			afterOrder(root.right);
			System.out.print(root.data + ",");
		}
	}
	
	public int depth(BinTree tree) {
		if (tree == null) {
			return 0;
		} else {
			int leftH  = depth(tree.left);
			int rightH = depth(tree.right);
			return (leftH > rightH ? leftH : rightH) + 1;
		}
	}
	
	public int getOneChildNodes(BinTree tree) {
		if (tree == null) {
			return 0;
		} else {
			int num = 0;
			if (tree.right != null && tree.left == null ||
					tree.left != null && tree.right == null) {
				num = 1;
			}
			return getOneChildNodes(tree.left)
					+ getOneChildNodes(tree.right) + num;
		}
	}
	
	public int getTwoChildNodes(BinTree tree) {
		if (tree == null) {
			return 0;
		} else {
			int num = 0;
			if (tree.right != null && tree.left != null) {
				num = 1;
			}
			return getOneChildNodes(tree.left)
					+ getOneChildNodes(tree.right) + num;
		}
	}
	
	public int getLeafNodes(BinTree tree) {
		if (tree == null) {
			return 0;
		} else {
			int num = 0;
			if (tree.right == null && tree.left == null) {
				num = 1;
			}
			return getLeafNodes(tree.left)
					+ getLeafNodes(tree.right) + num;
		}
	}
	
	public void swapLRNode(BinTree tree) {
		if (tree == null) {
			return;
		} else {
			swapLRNode(tree.left);
			swapLRNode(tree.right);
			BinTree temp = tree.left;
			tree.left    = tree.right;
			tree.right   = temp;
		}
	}
	
	public void levelTraverse(BinTree root) {  
        if (root == null) {  
            return;  
        }  
        LinkedList<BinTree> queue = new LinkedList<>();  
        // 将root添加双向链表末尾
        queue.offer(root);  
        while (!queue.isEmpty()) {  
        	// 删除并返回第一个节点
        	// 若queue的大小为0,则返回null
        	BinTree node = queue.poll();  
            System.out.print(node.data+",");  
            if (node.left != null) {  
                queue.offer(node.left);  
            }  
            if (node.right != null) {  
                queue.offer(node.right);  
            }  
        }  
    }  
}
