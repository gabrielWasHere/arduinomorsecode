# arduinomorsecode

Arduino project designated to translate Morse Code from a button into alphanumerical digits. 

This project involves the implementation of two buttons on the Arduino platform, one of them intended to receive the Morse Code signal (dits or dahs), and  the other one intended for representing message starts, message endings or breaks.
In this project there are two data structures, one for Morse Code transcription, and the other for it's alphanumerical correspondent (using the same index). The project's logic is applied to identifying and storing the Morse Code in a string, and when the end button is activated, comparing it to the Morse Code transcription list. When the Morse Code character is identified, it's index is captured and used for locating the respective alphanumerical character, returning to the main program the intended character in the transmission.
