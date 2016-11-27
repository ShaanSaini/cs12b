// Dictionary.java
// Shaan Saini
// shksaini
// pa3
// Dictionary class containing the method for the Dictionary ADT

public class Dictionary implements DictionaryInterface{
  
    private class Node{
	String key;
	String value;
	Node next;

	Node(String key, String value){
	    this.key = key;
	    this.value = value;
	    next = null;
	}
    }

    private Node front;
    private int numItems;

    public Dictionary(){
	front = null;
	numItems = 0;
    }
 
    public boolean isEmpty(){
	return (numItems==0);
    }

    public int size(){
	return numItems;
    }

    public String lookup(String key){
	Node N = front;
	while( N != null){
	    if( N.key.equals(key)){
		return N.value;
	    }
	    N = N.next;
	}
	return null;
    }

    public void insert(String key, String value) throws DuplicateKeyException{
	if( lookup(key) != null){
	    throw new DuplicateKeyException("cannot insert duplicate key");
	}
	else{
	    if( front == null){
		Node N = new Node(key,value);
		front = N;
		numItems++;
	    }
	    else{
		Node N = front;
		while( N != null){
		    if(N.next == null){
			break;
		    }
		    N = N.next;
		}
		N.next = new Node(key,value);
		numItems++;
	    }
	}
    }

    public void delete(String key) throws KeyNotFoundException{
	if( lookup(key) == null){
	    throw new KeyNotFoundException("cannot delete non-existent key");
	}
	else{
	    if(numItems <= 1){
		Node N = front;
		front = front.next;
		N.next = null;
		numItems--;
	    }
	    else{
		Node N = front;
		if(N.key.equals(key)){
		    front = N.next;
		    numItems--;
		}
		else{
		    while(!N.next.key.equals(key)){
			N = N.next;
		    }
		    N.next = N.next.next;
		    numItems--;
		}
	    }
	}
    }
    /*makeEmpty
     *Pre:none 
     *Pos:makes the linked list empty 
     */ 
    public void makeEmpty(){
	front = null;
	numItems =0;
    }

    public String toString(){
	String s = "";
	Node N = front;
	while( N != null){
	    s += N.key + " " + N.value + "\n"; 
	    N = N.next;
	}
	return s;
    }

    private Node findKey(String key){
	Node N = front;
	while(N != null){
	    if(N.key.equals(key)){
		return N; 
	    }
	    else{
		N = N.next; 
	    }
	}
	return null;
    }
  
}
