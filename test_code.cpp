#include "propotypes.hpp"
#include "ceasar.hpp"
#include "vernam.hpp"

/*this is the main test place to change input value and out put values*/
int main(){
	
	/* Vernam cipher decoding*/
	
	
	
	//because we know the length of cipher and plain should be the same
	//initialize the plain text with the cipher text as well

	string cipher ("MJZWLRXFVIUYX");
	string plain(cipher);
	vector<int> key_U = {3, 5};
	vector<int> key_V = {16,23,18};

	vernam_decryption( plain, cipher, key_U, key_V) ;
	

	/*Verman cipher encoding*/
	/*
	
	string plain ("WHERESTHEBEEF");
	string cipher(plain);
	vector<int> key_U = {3, 5};
	vector<int> key_V = {16,23,18};

	vernam_encryption( plain, cipher, key_U, key_V) ;	
    */

	/*vigenere cipher decoding*/
	
/*	
	string cipher = "YVJFJWXOXSYHQSRSSHYVFHSSJRXMTIWVJZU";
	char plain[cipher.length()+1] = {'\0'};
	vignere_decryption(plain, cipher.c_str(), 2);
	*/


	/*These are the codes for ceasar encryption and decryption*/
	/*
	int key = 1;
	char plain[] = "";
	char cipher[] = "tbnqmg";

	ceasar_encryption(plain, cipher, key);
	cout << "the plain text is:" << plain << endl;
	cout << "the encryted text is:" << cipher << endl;

	ceasar_decryption(plain, cipher, key);
	cout << "the plain text is:" << plain << endl;
	cout << "the encryted text is:" << cipher << endl;
	*/
	
}
