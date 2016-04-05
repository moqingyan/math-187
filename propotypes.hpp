
#include <string>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

int ceasar_encryption(const char* plain, char* cipher, int key);
int ceasar_decryption(char* plain, const char* cipher, int key);
int count_char(const char* to_count);
int vignere_decryption ( char* plain, const char* cipher, const int length);
int string_to_number (const char* to_trans, int* transed);
int vernam_encryption(const string & plain, string & cipher, 
	const vector<int> & key_U, const vector<int> & key_V);
int vernam_decryption(string & plain, const string & cipher, 
	const vector<int> & key_U, const vector<int> & key_V);
int find_key_W(const vector<int> & key_U, const vector<int> & key_V, vector<int> & key_W);
int LCM(int x,int y);