
public class Lab11 {
public static void main(String []args){
	int[] app = {9,4,8,5,7,5,6,4,10};
	int[] inorder = {8,7,6,5,4,3};
	BubbleSort sort = new BubbleSort();
	printArray(app);
	sort.descending(app);
	printArray(app);
	printArray(app);
	sort.ascending(app);
	printArray(app);
	
}
public static void printArray(int[] a){
	for(int i = 0; i<a.length; i++){
		System.out.print(a[i] +" ");
	}
	System.out.println("");
}
}
