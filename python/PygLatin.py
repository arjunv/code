"""
	Pig Latin is a language game, where you move the first letter of the word to the end and add "ay."
	So "Python" becomes "ythonpay."
  
	To write a Pig Latin translator in Python, here are the steps we'll need to take:
		* Ask the user to input a word in English.
		* Make sure the user entered a valid word.
		* Convert the word from English to Pig Latin.
		* Display the translation result.
	
	
"""

print('Welcome to the Pig Latin Translator!\n')
word = str(raw_input("Enter a word, Yah Pig! : ")).lower()
while len(word) < 2 or not word.isalpha():
	word = str(raw_input("No can do. Another one : ")).lower()

print("\nThats \'%s%s%say\' in Pig Latin!") % (word[1].upper(),word[2:],word[0])
