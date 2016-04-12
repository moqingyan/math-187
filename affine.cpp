#include <string>
#include <vector>
#include <iostream>

using namespace std;

int find_inverse(int to_inv, int prime);
int euclidean_algorithm (int a, int b);
int decode_affine(string cipher, int prime, int a, int b);
int num_to_ascii(int num, int scale);
int ascii_to_num (int ascii, int scale);

int main(){
	string cipher = "rpnaonvl";
	int prime = 26;
	int a = 19;
	int b = 13;

	decode_affine(cipher,prime, a,b);

}

int decode_affine(string cipher, int prime, int a, int b)
{
	int inv_a = find_inverse(a, prime);
	const char* cipher_ptr = cipher.c_str();
	string message = "";

	for(int ct = 0; ct<cipher.size();ct++){
		int new_m = inv_a * (ascii_to_num(cipher_ptr[ct], 26) - b) % prime;
			cout<<"This was the new_m: "<<new_m << endl;

		if(new_m < 0){
			//cout<<"This was the new_m: "<<new_m << endl;
			new_m = prime + new_m;
		}
		message += num_to_ascii(new_m, 26);
		cout << "The num is: "<<new_m << endl;
	}

	cout << "This is message: " << message << endl;
	return 0;
}

int ascii_to_num (int ascii, int scale)
{
    if (scale != 26 && scale != 37){
        cout<<"the scale is: " << scale << endl;
        cerr << "Wrong scale!";
        return -1;
    }

    if (scale == 26){
        if(ascii < 91 && ascii > 64){
            return (ascii - 'A');
        }
        else if(ascii < 123 && ascii > 96){
            return (ascii - 'a');
        }
        else{
            cerr<<"Illegal ascii!";
                return -1;
        }
    }

    else{
        if(ascii >= 'A' && ascii <= 'Z'){
            return (ascii - 'A'+ 10);
        }
        else if(ascii >= 'a' && ascii <= 'z'){
            return (ascii - 'a'+ 10);
        }
        else if(ascii >= '0' && ascii <= '9'){
            return (ascii - '0');
        }
        else if(ascii == '.'){
            return 36;
        }
        else{
            cerr<<"Illegal ascii!";
                return -1;
        }
   
    }
}


int num_to_ascii(int num, int scale)
{
    if (scale != 26 && scale != 37){
        cerr << "Wrong scale!";
        return -1;
    }
    
    if(scale == 26){
        if(num > 25 || num < 0){
            cerr<<"wrong num!";
            return -1;
        }
        return (num + 'a');
    }

    if(scale == 37){
        if(num > 37 || num < 0){
            cout<< "the num is: "<<num<<endl;
            cerr<<"wrong num1";
            return -1;
        }
        if(num < 10){
            return (num + '0');
        }
        else if(num == 36){
            return '.';
        }
        else{

            return (num - 10 + 'a');
        }
    }
}

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
