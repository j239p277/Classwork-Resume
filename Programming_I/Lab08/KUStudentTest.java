/* File Name: KUStudentTest.java
 * Author: Stephen Longofono 2776831
 * Assignment:   EECS-168 lab08
 * Description:  Create a class with a main to interact with the class KUStudent.  Write code to collect student info,
 * 					verify proper input, create and populate a new student object, and a method to print student info
 * 					in the proper format.
 * 					
 * Date: 10-27-2014
 */
import java.util.Scanner;

public class KUStudentTest {

	public static void main(String[] args){
				
		Scanner input = new Scanner(System.in);
		String lastLine = ("");
		String tempFirst = ("");
		String tempLast = ("");
		String tempId = ("");
		String tempDept = ("");
		KUStudent stu = new KUStudent();
		
		System.out.println("Please input the student's name (firstname lastname): ");
		tempFirst = input.next();
		tempLast = input.next();
		
		System.out.println("Please input the student's KUID and department: ");
		tempId = input.next();
		tempDept = input.next();
		
		stu.set_name(tempFirst, tempLast);
		stu.set_kuinfo(tempId, tempDept);
		
		writeOutput(stu);
		
		
	}
	
	public  static void writeOutput(KUStudent stu){
		
		System.out.println("Student: " + stu.get_fname() + " " + stu.get_lname());
		System.out.println("KUID: " + stu.get_id());
		System.out.println("Department: " + stu.get_dept());
		
	}
	
}
