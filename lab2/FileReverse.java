// FileReverse.java
// Shaan Saini
// shksaini
// lab2
// 

import java.io.*;
import java.util.Scanner;

public class FileReverse{
    public static void main(String[] args) throws IOException{
	Scanner in = null;
	PrintWriter out = null;
	String line = null;
	String[] token = null;
	int n;
    
	//throws an exception if less then two args are given
	if(args.length < 2){
	    System.out.println("Usage: FileCopy <input file> <output file>");
	    System.exit(1);
	}

	in = new Scanner(new File(args[0]));
	out = new PrintWriter(new FileWriter(args[1]));
    
  
	in.useDelimiter("\n");
	while(in.hasNext()){
	    line = in.next() +" ";
	    token = line.split("\\s+");
	    for(int i=0; i<token.length; i++){
		n = token[i].length();
		out.println(stringReverse(token[i],n));
	    }         
	}
	in.close();
	out.close();
    }

    public static String stringReverse(String s, int n){
	if(n>0){
	    return  s.charAt(n-1) + stringReverse(s,n-1); 
	}  
	return "";   
    }
}
