import java.util.*;
public class sortStack
{

	public static Stack<Integer> sort(Stack<Integer> s) 
	{
	
		Stack<Integer> r = new Stack<Integer>();
		
		while(!s.isEmpty()) 
		{
		
			int tmp = s.pop();
		
			while(!r.isEmpty() && r.peek() > tmp) 
			{
			
				s.push(r.pop());
				
			}
			
		r.push(tmp);
	
		}
	
		return r;
	}

	public static void main(String args[])
	{
		Stack<Integer> r = new Stack<Integer>();

		r.push(6);
		r.push(3);
		r.push(4);
		r.push(1);
		r.push(8);
		r.push(7);

		for( Integer i : r )
			System.out.println(i + " " );

		System.out.println( sort(r) );
	}
}
