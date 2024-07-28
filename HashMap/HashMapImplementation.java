import java.util.LinkedList;

public class HashMapImplementation {
    static class MyHashMap<k,v>{
        public static final int DEFAULT_CAPACITY = 4;
        public static final float DEFAULT_LOAD_FACTOR = 0.75f;
        private class Node{
            k key;
            v value;
            Node(k key,v value){
                this.key = key;
                this.value = value;
            }
        }

        private int n; // number of entries in map
        private LinkedList<Node>[] buckets; // array of linked list of nodes



        private void inItBuckets(int N){ // N = size of array / no of buckets in array
            buckets = new LinkedList[N];
            for(int i = 0; i < buckets.length; i++){
                buckets[i] = new LinkedList<>();
            }
        }

        private int HashFunc(k key){
            int hc = key.hashCode();  // give hashcode of given key
            return Math.abs(hc) % buckets.length;
        }

        // travese ll and looks for a node with key, if found return its index other return null
        private int searchInBucket(LinkedList<Node> ll,k key){ 
            for(int i = 0; i < ll.size(); i++){
                if(ll.get(i).key == key){
                    return i;
                }
            }
            return -1;         

        }

        private void rehash(){ // rehashing
            LinkedList<Node>[] oldBuckets = buckets; 
            inItBuckets(oldBuckets.length * 2);
            n = 0;
            for(var bucket : oldBuckets){
                for(var node : bucket){
                    put(node.key, node.value);
                }
            }
        }


        public MyHashMap(){
            inItBuckets(DEFAULT_CAPACITY);
        }

        public int size(){ // return the number of entries in map
            return n;
        }

        public void put(k key,v value){ // insert, update
            int bi = HashFunc(key);
            LinkedList<Node> currentBucket = buckets[bi];
            int ei = searchInBucket(currentBucket, key);
            if(ei == -1){ // means key is doesnt exist in ll so we need to add new node in ll
                Node node = new Node(key, value);
                currentBucket.add(node);
                n++;
            } else { // update case
                Node currentNode = currentBucket.get(ei);
                currentNode.value = value;
                // also we replace two statement by currentLinkedList.get(ei).value = value;
            }

            if(n >= buckets.length * DEFAULT_LOAD_FACTOR){
                rehash();
            }
        }

        public v get(k key){
            int bi = HashFunc(key);
            LinkedList<Node> currentLinkedList = buckets[bi];
            int ei = searchInBucket(currentLinkedList, key);
            if(ei == -1){ // means key is doesn't exist return null
                return null;
            } else { // key exist, so we return value of that key of index bi
                return currentLinkedList.get(ei).value;
            }
        }

        public v remove(k key){
            int bi = HashFunc(key);
            LinkedList<Node> currentLinkedList = buckets[bi];
            int ei = searchInBucket(currentLinkedList, key);
            if(ei == -1){ // means key is doesnt exist return null 
                return null;

            } else { // key exist
                Node currentNode = currentLinkedList.get(ei);
                v val = currentNode.value;
                currentLinkedList.remove(ei);
                n--;
                return val;               
            }
        }

        public int capacity(){
            return buckets.length;
        }

        public float load(){
            return (n * 1.0f) / buckets.length;
        }

        public boolean containsKey(k key){
            int bi = HashFunc(key);
            LinkedList<Node> currentLinkedList = buckets[bi];
            for(var node : currentLinkedList){
                if(node.key == key){
                    return true;
                }
            }
            return false;
        }

        public void entrySet(){ // this is only print the hashmap
            System.out.print("[ ");
            for(var bucket : buckets){
                for(var node : bucket){
                    System.out.print(node.key+"="+node.value+ " ");
                }
            }
            System.out.print("]");
            System.out.println();
        }


    }
    public static void main(String[] args) {
        MyHashMap<String,Integer> mp = new MyHashMap<>();
        System.out.println("Testing put");
        mp.put("a", 1);
        mp.put("b", 2);
        mp.put("c", 3);
        System.out.println("capacity is : " + mp.capacity());
        System.out.println("load is : "+mp.load());

       
        System.out.println("Testing size " + mp.size()); // 3
        mp.put("c", 30);
        System.out.println("Testing size after updating " + mp.size()); // 3
        
        // testing get
        System.out.println(mp.get("a")); // 1
        System.out.println(mp.get("b")); // 2
        System.out.println(mp.get("c")); // 30
        System.out.println("output for non existing : "+mp.get("college")); // null

        System.out.println(mp.remove("c")); // 30
        // now c does not exist let remove c 
        System.out.println("Testing remove for non existing : "+mp.remove("c")); // null

        System.out.println(mp.size()); // 2

        mp.put("x", 21);
        mp.put("y", 71);
        System.out.println(mp.get("x"));
        System.out.println(mp.get("y"));
        System.out.println(mp.size());

        System.out.println("capacity is : " + mp.capacity());
        System.out.println("load is : "+mp.load());

        System.out.println("testing contains key for non existing : "+ mp.containsKey("college"));
        System.out.println("testing contains key for existing : "+ mp.containsKey("x"));

        mp.entrySet();

        
    }
}
