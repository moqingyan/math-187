/*
how to use: change plain and cipher to whatever you like, and in cmd input
			g++ ceasar.cpp in the directory it is in. Then input "a.exe".
*/

#include "propotypes.hpp"




/* 
 * codes for ceasar encrytion and decrytion, which takes in the text and 
 * store the code into out put pointers
 */
int ceasar_encryption(const char* plain, char* cipher, int key){
	
	int curr = 0;
	int encryted = 0;

	/*loop though all the characters*/
	while (plain[curr] != '\0'){
		encryted = ((plain[curr] + key - 'A') % 26) + 'A';
		cipher[curr] = encryted ;
		curr++;
	}

	/*end of the cipher message*/
	cipher[curr] = '\0';

	return 0;
}

int ceasar_decryption(char* plain, const char* cipher, int key){

	int curr = 0;
	int decrypted = 0;

	/*loop though all the characters*/
	while (cipher[curr] != '\0'){
		decrypted = cipher[curr] - key;
		if (decrypted < 'A') {
			decrypted = decrypted + 26;
		}
		plain[curr] = decrypted;
		curr++;
	}

	/*end of the cipher message*/
	plain[curr] = '\0';
	return 0;
}
