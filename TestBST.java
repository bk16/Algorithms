import java.io*;
import java.util.*;

public class TestBST
{
	public static void main(String args[])
	{
		RedBlackBST<Integer,String> rbt = new RedBlackBST<Integer,String>();

		rbt.put(5,"Five");
		rbt.put(6,"Six");
		rbt.put(5,"Seven");
		rbt.put(5,"Eight");
		rbt.put(5,"Nine");
		rbt.put(5,"Ten");

		
		
		
