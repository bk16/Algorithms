
public class TestMergeSort
{
	public static void main(String args[])
	{
		Integer[] ar = new Integer[10];
	
		ar[0] = 10;
		ar[1] = 43;
		ar[2] = 59;
		ar[3] = 97;
		ar[4] = 21;
		ar[5] = 31;
		ar[6] = 12;
		ar[7] = 9;
		ar[8] = 30;
		ar[9] = 75;

		MergeSort.sort(ar);

		for( int k : ar )
			System.out.println(k);
	}
}
