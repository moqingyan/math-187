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
	vector<int> origin_super = {3,5,12,21,43};
	int large_p = 89;
	int a = 15;
    int secret_message = 10;
	//get_pb(origin_super, large_p, a);
	decrypt_MHK(secret_message, large_p, a, origin_super);
}

vector<int> get_pb(vector<int> origin_super, int large_p, int a){
	
	vector<int> encrypted_super;
	int to_push = 0;
	cout << "the public key is: ";
	for(int ct = 0; ct < origin_super.size(); ct++){
		to_push = origin_super[ct] * a % large_p;
		encrypted_super.push_back( to_push );
		cout << to_push << ", ";
	}
	cout<<endl;
    return encrypted_super;
}

vector<int> decrypt_MHK(int secret_message, int large_p, int a, vector<int> origin_super){
	
	int inv_a = find_inverse(a, large_p);
	
    cout << "This is inv_a: " << inv_a << endl;

    vector<int> decrypted;
	int message = inv_a * secret_message % large_p;

    cout << "This is message: " << message << endl;
	cout << "the reversed eessage is: ";
	for(int ct = origin_super.size()-1; ct >= 0; ct--){

		if(message >= origin_super[ct]){
			cout << "1 ";
			decrypted.push_back(1);
            message = message - origin_super[ct];
        }

		else{
			cout << "0 ";
			decrypted.push_back(0);
		}

	}


     cout << endl;
	return decrypted;

}

int find_inverse(int to_inv, int prime){
	for(int ct=0; ct < prime; ct++){
		if((to_inv * ct % prime) == 1){
			return ct;
		}
	}
	cout << "chose a bad number" << endl;
    return -1;
}
