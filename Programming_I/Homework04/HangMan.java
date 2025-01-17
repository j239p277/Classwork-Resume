/*
 * 	File Name: HangMan.java
	Author: Stephen Longofono
	KUID: 2776831
	Email Address: s580l129@ku.edu 
	Homework Assignment Number: 4 
	Description:  	This is the "back-end" framework for a hangman game in java.  The constructor and methods below are generalized to allow porting to other environments such as an Android app.
					Note: there are some specific class methods used, namely string.toLowerCase() and string.charAt().  Everything else should be standard fare.
	Last Changed: 12-05-14 
	
 */
public class HangMan {

	public static int gamesPlayed = 0;
	private int MAX_MISSES_ALLOWED;
	private int guessCount;
	private int missesCount;
	private char[] missedMarkers;
	private char[] disguised_word;
	private final String secret_word;
	
	
	public HangMan(String s1){							//constructor initializes variables, populates arrays
		MAX_MISSES_ALLOWED = 7;							//initialized here in case we want to change the program later
		guessCount = 0;
		missesCount = 0;
		missedMarkers = new char[7];
		disguised_word = new char[s1.length()];
		secret_word = s1.toLowerCase();
		gamesPlayed++;
		for(int i = 0; i< missedMarkers.length; i++){	//ie lives left
			missedMarkers[i] = 'O';
		}
		for(int i = 0; i<disguised_word.length; i++){	//show the disguised word, with spaces shown to be nice
			if(s1.charAt(i)==' '){
				disguised_word[i] = ' ';
			}
			else{
				disguised_word[i] = '?';
			}
		}
		
	}
	
	/*
	 * This method makes a guess in the game, by checking for the char c in the secret word. It update counters accordingly
	 * This method assumes secret_word has been initialized to a nonempty string and that guessCount, missesCount have been initialized.
	 * This method returns a boolean value
	 */
	public boolean guessCharacter(char c){
		guessCount++;
		if(hasChar(secret_word, c)){
			for(int i=0; i<secret_word.length(); i++){
				if(secret_word.charAt(i)==c){
					disguised_word[i] = c;
				}
			}
			return true;
		}
		else{
			missesCount++;
			lostLife(missedMarkers);
			return false;
		}
	}
	/*
	 * This method checks if the game should end (maximum wrong guesses or word is found)
	 * This method assumes missesCount and MAX_MISSES_ALLOWED have been initialized
	 * It also assumes proper function of the isFound method below
	 * This method returns a boolean value
	 */
	public boolean isGameOver(){
		if((missesCount == MAX_MISSES_ALLOWED)||(isFound())){
			return true;
		}
		return false;
	}
	/*
	 * This method checks the winning condition (the chars in String secret_word matches the char array disguised_word)
	 * This method assumes proper initialization and nonzero length for both.
	 * This method returns a boolean value
	 */
	
	public boolean isFound(){
		for(int i = 0; i<secret_word.length(); i++){
			if(disguised_word[i]!=secret_word.charAt(i)){
				return false;
			}
		}
		return true;
	}
	/*
	 * This is a public getter for the int value of guessCount, assumes an initialization of the value, and returns that value. 
	 */
	public int getGuessCount(){
		return guessCount;
	}
	/*
	 * This is a public getter for the int value of missesCount, assumes an initialization of the value, and returns that value. 
	 */
	public int getMissesCount(){
		return missesCount;
	}
	/*
	 * This method is a public getter that uses the fetchStringVal method below.  Same pre/post conditions 
	 */
	public String getDisguisedWord(){
		return(fetchStringVal(disguised_word));
	}
	/*
	 * This method is a public getter that uses the fetchStringVal method below.  Same pre/post conditions 
	 */
	public String getMissedMarker(){
		return(fetchStringVal(missedMarkers));
	}
	
	/*
	 * This method searches for the first occurrence of an O and replaces it with an X
	 * It is assuming the array passed in has at least one O in it (predetermined by a counter in the instance)
	 * It returns the array modified as such.
	 */
	private char[] lostLife(char[] missedMarkers){
		boolean notDone = true;
		for(int i = 0; i<missedMarkers.length; i++){
			if(missedMarkers[i]=='O'){
				if(notDone){
					missedMarkers[i] = 'X';
					notDone = false;
				}
			}
		}
		return missedMarkers;
	}
	/*
	 * This method is a helper to run through an array of chars and determine if the char c is in that array.
	 * It expects an initialized array (nonzero length), and returns a boolean value
	 */
	private static boolean hasChar(char[] array, char c){
		for(int i = 0; i<array.length; i++){
			if(array[i]==c){
				return true;
			}
		}
		return false;
	}
	/*
	 * This method is another version of the above to handle a char array instead of a string.
	 */
	private static boolean hasChar(String word, char c){	//method overloading even!
		for(int i = 0; i<word.length(); i++){
			if(word.charAt(i)==c){
				return true;
			}
		}
		return false;
	}
	/*
	 * This method returns the string value of the given char array (with all its glorious method libraries)
	 * This method assumes a nonzero array length
	 * this method returns a String composed of the chars in the array, in order.
	 */
	private String fetchStringVal(char[] arr){
		String x = "";
		for(int i = 0; i<arr.length; i++){
			x = x + arr[i];
		}
		return x;
	}
}
