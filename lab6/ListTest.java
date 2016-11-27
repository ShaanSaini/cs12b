/* ListTest.java
 * Shaan Saini
 * shksaini
 * lab6
 * Test class for the list being tested
 */

public class ListTest{
    public static void main(String[] args){
	List<String> A = new List<String>();
	List<Integer> B = new List<Integer>();
	//adds items to list
	A.add(1, "one");
	A.add(2, "two");
	A.add(3, "three");
	A.add(4, "ten");
	A.add(5, "twenty");
	A.add(6, "thirty");
	A.add(7,"one");
    
    
	B.add(1, 1);
	B.add(2, 2);
	B.add(3, 3);
	B.add(4, 4);
	B.add(5, 5);
	B.add(6, 6);
    
	A.remove(2);
	A.remove(1);
    
	System.out.println(A.size());
	System.out.println(B.size());
    
	System.out.println(A.equals(B));
	System.out.println("A:" + A);
	System.out.println("B:"+ B);
    
    }
}
