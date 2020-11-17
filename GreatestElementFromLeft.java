import java.util.*; 
class GreatestElementFromLeft { 
static void printNGE(int arr[], int n) 
{ 
	Stack<Integer> s = new Stack<Integer>(); 

	int arr1[] = new int[n]; 

	for (int i = 0; i<n; i++) 
	{ 

		while (!s.isEmpty() && s.peek() <= arr[i]) 
               {
		s.pop();
                }
	
		if (s.empty()) 
               {
                arr1[i] = -1;
               }
		 
		else
               {
		arr1[i] =s.peek();
               }
		s.push(arr[i]);

		 

	} 

	for (int i = 0; i < n; i++) 
		System.out.print(arr1[i]+" "); 
} 


public static void main(String[] args) 
{ 
	Scanner sc=new Scanner(System.in);
int n=sc.nextInt();
int[] arr=new int[n];
for(int i=0;i<n;i++)
{
arr[i]=sc.nextInt();
}
	printNGE(arr, n); 
} 
} 
