/*
 *  File Name: PrintCostCalculator.java
	Author: Stephen Longofono
    KUID: 2776831
	Email Address: s580l129@ku.edu 
	Homework Assignment Number: 1
	Description: 
	
	Premise:
	Write a program to calculate the cost of a print job, as defined by the number
	of pages, type of print job, color, and the amount of ink used in each type of job.  The user output
	must be exactly as in the format provided.  There should be a prompt to determine if there is a sale, in which case the 
	cost will be discounted by 50% for color jobs with strictly greater than 100 pages.
	
	Execution:
	After gathering the necessary information, the if/else block identifies the print type and populates the
	number of dots per page and the number of dots for the entire job.
	After this, the color is taken from the user and used with the DPP/DPJ values to calculate cost.  This is 
	separate from the rest of the information gathering because I knew I would have to modify
	it later with a discount prompt and amend the cost.
	Finally, the values are displayed to the user in the specified format.
	 
	Last Changed: 9-21-2014 
 */
import java.util.Scanner; 	
import java.lang.Math;		

public class PrintCostCalculator {

	public static void main (String[] args){
		
		Scanner input = new Scanner(System.in);
		int pageNum = 0;	
		char printType = 'z';
		byte color = 0;
		String userTemp = ""; 					//String to populate char printType and char sale from user input
		char sale = 'n';						
		
		final short TEXT = 4300;				//Static values in dots per page for print types.  As lean as
		final short IMAGE = 15000;				//possible so I can run this on my toaster or phone.
		final short COMPTEXT = 25000;
		final short STATEMENT = 27000;
		
		int dotsPerPage = 0;
		double dotsPerJob = 0; 					//Stored separately for different formatting/use later on
		double costPage = 0;					//Ditto last comment
		double costTotal = 0;
		
		System.out.println("--- Price Estimator Program ---");
		System.out.print("Enter Number of Pages (digits only): ");
		pageNum = input.nextInt();									
		System.out.printf("%n");
		System.out.println("--- Select a Print Type ---");
		System.out.println("Enter T or t for Text");				// ASCII 84 or 116 
		System.out.println("Enter I or i for Image");				// ASCII 73 or 105
		System.out.println("Enter C or c for Compressed Text");		// ASCII 67 or 99
		System.out.println("Enter S or s for statement");			// ASCII 83 or 115
		System.out.println("---------------------------");
		System.out.print("Enter Print Type: ");
		userTemp = input.next();
		printType = userTemp.charAt(0);
		System.out.printf("%n");
		
		if(printType==84||printType==116){		//This block reads the print type and sets dotsPerPage to the appropriate value
			dotsPerPage = TEXT;					//Note that this defaults to the most expensive option to avoid underestimation
			dotsPerJob = dotsPerPage * pageNum;	//if the user makes a mistake
		}										
		else if(printType==73||printType==105){
			printType = userTemp.charAt(0);
			dotsPerPage = IMAGE;
			dotsPerJob = dotsPerPage * pageNum;
		}
		else if(printType==67||printType==99){
			printType = userTemp.charAt(0);
			dotsPerPage = COMPTEXT;
			dotsPerJob = dotsPerPage * pageNum;
		}
		else{
			dotsPerPage = STATEMENT;
			dotsPerJob = dotsPerPage * pageNum;
		}
		
		
		System.out.println("--- Select a Print Color ---");
		System.out.println("Enter 0 for Grayscale");
		System.out.println("Enter 1 for Color");
		System.out.println("-----------------------------");
		System.out.print("Enter Print Color: ");
		color = input.nextByte();
		System.out.println("-----------------------------");
		System.out.print("Is there a sale (y/n): ");
		userTemp = input.next();
		sale = userTemp.charAt(0);
		
		if(color == 0){
			costPage = (dotsPerPage/1000.0)*0.03;
			costTotal = costPage * pageNum;
		}
		else{														//This block calculates cost based on a given
			costPage = (dotsPerPage/1000.0)*0.11;					//price for every 1000 dots.  Used a decimal
			costTotal = costPage * pageNum;							//to ensure an accurate result with int dPP
			
			if(sale==121 && pageNum>100){							//Defaults to the more expensive option to avoid underestimation. 
				costTotal = costTotal*(0.5);						//ASCII 121 means y, again defaulted to "n" 
			}
			
		}
		
		System.out.println("");
		System.out.println("--- Cost Estimate ---");
		System.out.println("Ink Usage Per Page: " + dotsPerPage);
		System.out.printf("Total Ink Usage: %8.2e%n", dotsPerJob);		//See note at declaration, requires a double for scientific notation type
		System.out.println("");											//%8.2 means 8 chars wide, 2 decimal places (included in 8).												
		System.out.printf("Estimated Cost Per Page: $%.4f%n", costPage);//e means scientific notation, f means express as															
																		//a float/double, %n means advance line.
																		// order is %[flags][width][.precison][format type].  All are within "",
		if(sale == 121 && pageNum>100){
			System.out.printf("Total Cost: $%6.2f%n", (costTotal*2));
			System.out.println("");
			System.out.printf("SALE Price: $%6.2f%n", costTotal);
		}
		else{
			System.out.printf("Total Cost: $%6.2f%n", costTotal);
		}
	
	}																	
	
}