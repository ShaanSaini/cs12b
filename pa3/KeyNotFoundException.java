// KeyNotFoundException.java
// Shaan Saini
// shksaini
// pa3
// Throws an exception if you try to delete a key that doesn't exist

public class KeyNotFoundException extends RuntimeException{
    public KeyNotFoundException(String s){
	super(s);
    }
}
