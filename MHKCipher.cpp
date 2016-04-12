#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> get_pb(vector<int> origin_super, int large_p, int a);
vector<int> decrypt_MHK(int secret_message, int large_p, int a, vector<int> origin_super);
int find_inverse(int to_inv, int prime);
int euclidean_algorithm (int a, int b);

int main(){
    //MHK cipher takes in a super increasing sequence
    //This is to change
    vector<int> origin_super = {2, 5, 9,22,47,99,203,409};
    int large_p = 997;
    int a = 60;
    int secret_message = 1255;

    //find_inverse(a, large_p);
    //int retV = euclidean_algorithm(a, large_p);

    //cout << "Therefore the inverse is " << retV << endl;
    //get_pb(origin_super, large_p, a);
    decrypt_MHK(secret_message, large_p, a, origin_super);
}

/* to get the public key*/
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

/*to decrypt MHK*/
vector<int> decrypt_MHK(int secret_message, int large_p, int a, vector<int> origin_super){

    int inv_a = find_inverse(a, large_p);

    cout << "This is inv_a: " << inv_a << endl;

    vector<int> decrypted;
    int message = inv_a * secret_message % large_p;

    cout << "This is message: " << inv_a << " * "
       << secret_message << " % " << large_p << " = "
       << message << endl;
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

/*find out the inverse of a number */
int find_inverse(int to_inv, int prime){

    /*using eudlidean algorithm*/
    return euclidean_algorithm(prime, to_inv); 

    /*
    for(int ct=0; ct < prime; ct++){
        if((to_inv * ct % prime) == 1){
            cout << "The inverse is " << ct << endl;
            return ct;
        }
    }
    */

}

int euclidean_algorithm (int a, int b){
    vector<int> p;
    vector<int> q;
    vector<int> mult;
    vector<int> rem;

    if(a<b){
        int temp = a;
        a = b;
        b = temp;
    }
    
    rem.push_back(a);
    rem.push_back(b);
    p.push_back(0);
    p.push_back(1);
    q.push_back(1);
    q.push_back(0);
   /* 
    cout<<"p -2 =  0, p -1  = 1" << endl;
    cout<<"q -2 =  1, q -1  = 0" << endl;
    */

    int ct = 0;
    
    printf("%5s %5s %5s %5s %5s\n",
            "step", "rem", "p", "q", "a" );

    printf("%5d %5d %5d %5d \n",
            -2, rem[ct], p[ct], q[ct] );

    printf("%5d %5d %5d %5d \n",
            -1, rem[ct+1], p[ct+1], q[ct+1] );


    while(b != 0){
        mult.push_back(a/b);
        rem.push_back(a % b);
        p.push_back(p[ct] + p[ct+1] * mult[ct]);
        q.push_back(q[ct] + q[ct+1] * mult[ct]);

        printf("%5d %5d %5d %5d %5d\n",
            ct, rem[ct+2], p[ct+2], q[ct+2], mult[ct] );
/*
        cout<<"remainder " << ct <<  " = " << rem[ct+2] << endl ;
        cout<< "mult " << ct  << " = " << a/b << endl;
        cout<<" p " << ct <<  " = " << p[ct+2] << endl ;
        cout<<" q " << ct <<  " = " << q[ct+2] << endl ;
*/
        a = b;
        b = rem[ct+2];
        ct++;

    }
   
    /* 
       cout << "This is ct" << ct << endl;
       */

    int size = mult.size();

    if ( a != 1){
        cout << "b is a factor of a" << endl;
        cout << a << " * 1 - " << b << " * "<<(a/b)<< "= 0" << endl;
    }

    else{
      cout << p[ct] << " * " << rem[1] << " + " << q[ct] << " * " 
          << rem[0] << " = (-1)^" << ct << " (mod " << rem[0] <<")"
          << endl;

      if(ct % 2 != 0){
        cout << "Therefore the inverse is " << p[ct] << endl;
        return p[ct];
      }
      else{
        cout << "Therefore the inverse is " << (rem[0] - p[ct]) << endl;
        return (rem[0] - p[ct]); 
      }
    } 
}
