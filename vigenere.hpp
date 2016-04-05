#include "propotypes.hpp"

/* codes for vignere cipher */
int vignere_decryption ( char* plain, const char* cipher, const int length){
	
	string plain_in_parts[length] = {""};
	string cipher_in_parts[length] = {""};
	int shift[length] = {0};
	int rem = 0;
	int index = 0;

	//split the string into several strings according to the key length
	while( *cipher != '\0'){

		rem = index % length;
		cipher_in_parts[rem] += *cipher;
		cipher++;
		index++;
	}

	//count the appearance of each chars to figure out what is the most probable
	//'e' in the code
	for (int ct = 0; ct<length; ct++){
		cout << "the " << ct << " th string is " << cipher_in_parts[ct] << endl;
		const char* to_count = cipher_in_parts[ct].c_str();
		shift[ct] = count_char(to_count);
		cout << "the " << ct << " th string's 'e' is probably " << (char) shift[ct] << endl;
		cout << endl;
	}

	//make any fix to the shift frequency here!!!

    //desend into ceasar dexryption code
	for (int ct = 0; ct<length; ct++){

		//decrypt the ceasar cyphers
		int key = (int) ((shift[ct] - 'e') % 26 );


		if(key < 0){
			key = key+26;
		}
		
		ceasar_decryption( (char*) plain_in_parts[ct].c_str(),
		 cipher_in_parts[ct].c_str(),  key);
		
		int count = 0;
		index = 0;
		const char* iter = plain_in_parts[ct].c_str();

		//put the plain text back together
		while( *iter != '\0'){
			index = length * count + ct;
			plain[index] = *iter;
			iter ++;
			count++;
		}

		//cout<< "in the turn "<< ct << " this is plain text: " << plain << endl; 
	}

	cout<< "this is plain text: " << plain << endl; 
	return 0;
}


/*
 * takes in the string to count the variables, and return the ascii of the 
 * largest number of existance
 */
int count_char(const char* to_count){
	int ascii[26] = {0};
	int offset = -1;
	
	/* loop through all the chars in the string*/
	while ( *to_count != '\0' ){
	
		/*lower case letters*/
		if( *to_count >= 'a' ) {
			offset = *to_count - 'a';
		}
		/*upper case letters*/
		else{
			offset = *to_count - 'A';
		}

		if (offset < 0 || offset > 25){
			cerr << "offset is not in the range!!" << offset << endl;
			return -1;
		}

		/*update the chars*/
		ascii[offset] ++;
		to_count++;
	}

	int max = ascii[0];
	bool repeat = false;

	for (int index = 1; index < 26; index ++) {

		/*print all the non-zero char's appearing times*/
		if(ascii[index] != 0){
			cout << "the character " << (char) (index + 'a') << " appears " 
			<< ascii[index] << " times " << endl;
		}

		/*find out the max appeared letter of the string*/
		if(ascii[index] > ascii[max]){
			max = index;
		}
	}

	return (max + 'a');
}