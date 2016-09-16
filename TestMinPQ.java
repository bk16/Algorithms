import java.util.Comparator;
public class TestMinPQ
{
	public static void main(String args[])
	{
		MinPQ<Integer> pq = new MinPQ<Integer>(200,new IntComparator());
	
		pq.insert(new Integer(4));
		pq.insert(new Integer(8));
		pq.insert(new Integer(7));
		pq.insert(new Integer(5));
		pq.insert(new Integer(1));
		pq.insert(new Integer(6));
		pq.insert(new Integer(3));

		for( Integer i : pq)
			System.out.print(i + " ");

		System.out.println();
	}
}

class IntComparator implements Comparator<Integer>
{
	public int compare(Integer i1,Integer i2)
	{
		return i1.compareTo(i2);
	}
}
