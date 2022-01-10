import java.util.*;


public class Solution {
    Map<Integer, Node> cache= new HashMap();
    int size = 0;
    Node head, tail;
    /**
     * lru design
     * @param operators int整型二维数组 the ops
     * @param k int整型 the k
     * @return int整型一维数组
     */
    public int[] LRU (int[][] operators, int k) {
        // write code here
        this.size = k;
        
        int length = 0;
        for (int i = 0; i < operators.length; i++) {
            int[] operator = operators[i];
            if (operator[0] == 2) length++;
        }
        int[] res = new int[length];
        int j = 0;
        for (int i = 0; i < operators.length; i++) {
            int[] operator = operators[i];
            if (operator[0] == 1) {
                set(operator[1], operator[2]);
            } else res[j++] = get(operator[1]);
        }
        
        return res;
    }
    
    void set(int k, int v) {
        if (cache.containsKey(k)) {
            get(k);
            cache.get(k).v = v;
            return;
        }
        
        Node node = new Node(k, v);
        cache.put(k, node);
        node.next = head;
        if (head != null) head.prev = node;
        else tail = node;
        head = node;
        
        if (cache.size() > size) {
            cache.remove(tail.k);
            tail = tail.prev;
            tail.next = null;
        }
    }
    
    int get(int k) {
        if (!cache.containsKey(k))    return -1;
        
        Node node = cache.get(k);
        moveToHead(node);
        return node.v;
    }
    
    void moveToHead(Node node) {
        if (head == node)   return;
        Node prev = node.prev;
        Node next = node.next;
        if (prev != null) prev.next = next;
        if (next != null) next.prev = prev;
        if (node == tail && prev != null) tail = prev;
        node.next = head;
        if (head != null) head.prev = node;
        head = node;
        head.prev = null;
    }
    
    static class Node {
        Node prev, next;
        int k, v;
        Node(int k, int v) {
            this.k = k;
            this.v = v;
        }
    }
}