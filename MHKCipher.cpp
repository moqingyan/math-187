#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> get_pb(vector<int> origin_super, int large_p, int a);
vector<int> decrypt_MHK(int secret_message, int large_p, int a, vector<int> origin_super);
int find_inverse(int to_inv, int prime);

int main(){
	//MHK cipher takes in a super increasing sequence
	//This is to change
	vector<int> origin_super = {1,2,3};
	int large_p = 3;
	int a = 2;

	get_pb(origin_super, large_p, a);
	
}

vector<int> get_pb(vector<int> origin_super, int large_p, int a){
	
	vector<int> encrypted_super;
	int to_push = 0;
	cout << "the public key is: ";
	for(int ct = 0; ct < origin_super.size(); ct++){
		to_push = origin_super[ct] * a % large_p);
		encrypted_super.push_back( to_push );
		cout << to_push << ", ";
	}
	cout<<endl;
}

vector<int> decrypt_MHK(int secret_message, int large_p, int a, vector<int> origin_super){
	
	int inv_a = find_inverse(a, large_p);
	vector<int> decrypted;
	int message = inv_a * secret_message % large_p;

	cout << "the message is: ";
	for(int ct = 0; ct < origin_super.size(); ct++){

		if(message > origin_super[ct]){
			cout << "1 " << endl;
			decrypted.push_back(1);
		}

		else if{
			cout << "0 " << endl;
			decrypted.push_back(0);
		}
	}

	return decrypted;

}

int find_inverse(int to_inv, int prime){
	for(int ct=0; ct < prime; ct++){
		if((to_inv * ct % prime) == 1){
			return ct;
		}
	}
	cout << "chose a bad number" << endl;
}
