/*
 * File Name: 	MethodPractice.java
 * Author: 		Stephen Longofono s580l129@ku.edu	
 * Assignment:  EECS-168 Lab 05
 * Description: In this file you will have your main method and three other methods:

    			integer chooseGreater(int a, int b)
        		Take in two integers
        		returns the bigger of the two numbers

    			void printWord(String word, int timesToPrint)
        		Accepts a String and an integer
        		This function returns nothing, but will print the parameter word over and over, timesToPrint times
        		If timesToPrint is less than or equal to zero, then nothing is printed 
        		
        		
    			double circumference(double radius)
        		takes in a radius
        		if the radius is greater than zero, return the circumference, otherwise return 0.0
        	 	3.14159 as an approximation for PI


    			main method
        		In you main method test your methods
        		I highly recommend that you test each method after your write it
        		Don't try to write all the methods then test for the first time

        		
        		
 * Date: 		9-29-2014
 */

import java.util.Scanner;
import java.lang.Math;

public class MethodPractice {

	public static void main(String[]args){
		
		Scanner input = new Scanner(System.in);
		String s1 = new String("");
		int choice = 0;
		
		System.out.println("Input two numbers:");
		System.out.println("The greater number is " + chooseGreater(input.nextInt(), input.nextInt()));
		System.out.println("If you got a zero, your numbers are equal.");
		//calls the chooseGreater method with arguments of the next
		//two inputs from the scanner.  Verbalizes the result.
		
		System.out.print("Input a radius: ");
		System.out.println("The circumference is: " + circumference(input.nextDouble()));
		//calls the circumference method with the argument of the next double input from the scanner.  Verbalizes the result.
		
		System.out.println("Input a string:");
		s1 = input.next();
		System.out.print("How many times do you want to print it?: ");
		input.nextLine();			//Advances the scanner line so that the string goes away and it doesn't throw an error
		choice = input.nextInt();
		printWord(s1, choice);
		//calls the printWord method using the String and # of times gathered from the scanner.  Verbalizes the result.
		
	}
	
	
	public static int chooseGreater(int a, int b){
		
		if(a > b){
			return a;
		}
		else if(a < b){
			return b;
		}
		else{
			return 0;
		}
	}
	
	
	public static void printWord(String word, int timesToPrint){
		
		while (timesToPrint > 0){
			System.out.println(word);
			timesToPrint = (timesToPrint - 1);
		}
	}
	
	public static double circumference(double radius){
		
		final double PI = 3.14159;
		double result = PI * radius * 2.0;
		return result;
		
	}
	
}
