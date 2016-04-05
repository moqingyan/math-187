#include "propotypes.hpp"


/*codes for vernam cipher*/

int vernam_decryption(string & plain, const string & cipher, 
	const vector<int> & key_U, const vector<int> & key_V){

	int length = cipher.length();
	int length_W = 0;

	vector<int> key_W;

	/*find out key_W from the two keys provided*/
	find_key_W(key_U, key_V, key_W);
	length_W = key_W.size();
	
	/*find out the matching number for plain text*/
	int transed[length] = {0};
	string_to_number (cipher.c_str(), transed);

	int to_store = 0;
	/*encode them into cipher text*/
	for(int ct = 0; ct < length ; ct++){

		to_store = (transed[ct] - key_W[ct % length_W]);

		if(to_store < 0) {
			to_store = to_store + 26;
		}
		plain[ct] = to_store % 26 + 'A';
	}

	cout<<"this is plain text: " << plain ;

	return 0;
}


int vernam_encryption(const string & plain, string & cipher, 
	const vector<int> & key_U, const vector<int> & key_V){

	int length = cipher.length();
	int length_W = 0;

	vector<int> key_W;

	/*find out key_W from the two keys provided*/
	find_key_W(key_U, key_V, key_W);
	length_W = key_W.size();

	/*find out the matching number for plain text*/
	int transed[length] = {0};
	string_to_number (plain.c_str(), transed);

	/*encode them into cipher text*/
	for(int ct = 0; ct < length ; ct++){
		cipher[ct] = (transed[ct] + key_W[ct % length_W]) % 26 + 'A';
	}

	cout<<"this is ciphered text: " << cipher ;

	return 0;
}

/*this is the algorithm to find out the real key W*/
int find_key_W(const vector<int> & key_U, const vector<int> & key_V, vector<int> & key_W){

	int length_V = key_V.size();
	int length_U = key_U.size();
	int length = LCM( length_U, length_V);

	cout<<"this is key_W: ";

	for(int ct = 0; ct < length; ct++){
		key_W.push_back( (key_U[ct % length_U] + key_V[ct % length_V]) % 26 );
		cout << key_W[ct] << " ";
	}

	cout<<endl;
	return 0;
}

/*Least common multiple, refer to http://www.devx.com/tips/Tip/33554*/
int LCM(int x,int y)
   {
      int prod;
      if(y%x==0)
         return y;
      else
      {
         prod=x*y;
         while(x!=y) // get the GCD of 2 given integers
         {
            if(x>y)
               x=x-y;
            else
               y=y-x;   //x now is the GCD
         }
         return LCM(y,prod/x);  //recurse, changing x to y and vice versa
      }   //LCM = (x*y)/(GCD)
   }

int string_to_number (const char* to_trans, int* transed){
	
	int count = 0;
	int offset = -1;

	while ( *to_trans != '\0' ){
		
		/*lower case letters*/
		if( *to_trans >= 'a' ) {
			offset = *to_trans - 'a';
		}
		/*upper case letters*/
		else{
			offset = *to_trans - 'A';
		}

		if (offset < 0 || offset > 25){
			cerr << "offset is not in the range!!" << offset << endl;
			return -1;
		}

		transed[count] = offset;
		to_trans++;
		count++;

	}

	return 0; 

}