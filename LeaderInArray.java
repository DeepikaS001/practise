package lecture5;

import java.util.Scanner;

public class LeaderInArray {
	public static Scanner s = new Scanner(System.in);

	public static int[] takeInput() {
		int n= s.nextInt();
		int[] arr = new int[n];
		for(int i=0;i<n;i++)  {
			arr[i]=s.nextInt();
		}
		return arr;
	}

	public static void Leader(int[] arr, int left, int right) {
		while(left<=right) {
			int count=0;
			for(int i=left+1; i<=right; i++) {
				if(arr[left] >= arr[i])
					count=1;
				else
					break;
			}
			if(count==1)
				System.out.print(arr[left]+" ");
			left++;
		}
		System.out.print(arr[right]);
	}

	public static void main(String[] args) {
		int[] arr = takeInput();
		Leader(arr, 0, arr.length-1);
		
	}

}
