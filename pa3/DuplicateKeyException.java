// DuplicateKeyException.java
// Shaan Saini
// shksaini
// pa3
// Throws an exception if duplicate keys are inserted

public class DuplicateKeyException extends RuntimeException{
    public DuplicateKeyException( String s){
	super(s);
    }
}
