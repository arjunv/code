"""
	Pig Latin is a language game, where you move the first letter of the word to the end and add "ay."
	So "Python" becomes "ythonpay."
  
	To write a Pig Latin translator in Python, here are the steps we'll need to take:
		* Ask the user to input a word in English.
		* Make sure the user entered a valid word.
		* Convert the word from English to Pig Latin.
		* Display the translation result.
	
	
"""

word = str(raw_input("Enter a word: ")).lower()
print word
if len(word) == 0:
    print "NO WORD ENTERED"
print("%s%s%say") % (word[1].upper(),word[2:],word[0])
