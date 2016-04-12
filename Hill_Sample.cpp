#include <cmath>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int det(vector <vector<int> > b,int m);
int num_to_ascii(int num, int scale);
int ascii_to_num (int ascii, int scale);
 vector< vector<int> > rev_mat(vector <vector<int> > b, int prime);
int find_inverse(int to_inv, int prime);
vector<int> v_mult (vector< vector<int> > key_r, vector<int> cipher
        ,int prime);
int euclidean_algorithm (int a, int b);
string decode_HS(string cipher, vector< vector<int> > key, 
        int prime, int scale);

int main(){

        vector< vector<int> > mat = {
        {4,3},
        {6,5}
    };
    
    string cipher = "6g";
    int prime = 37;
    int scale = 37;

    decode_HS(cipher,mat, prime, scale);

    cout << "This is det of the mat: " << det(mat, 2)<< endl;
}

string decode_HS(string cipher, vector< vector<int> > key, 
        int prime, int scale)
{   
    const char* cip_ptr = cipher.c_str();
    vector<int> v_arr[cipher.size()/2];
    vector< vector<int> > key_i = rev_mat(key, prime);
    vector<int> m_arr[cipher.size()/2];
    string message = "";

    for(int ct =0 ; ct < (cipher.size()/2); ct++){

        

        v_arr[ct].push_back( ascii_to_num(cip_ptr[ct*2], scale));
        v_arr[ct].push_back( ascii_to_num(cip_ptr[ct*2 + 1], scale));

        cout << "varr["<<ct<<"]"<<"( "<<v_arr[ct][0]<<","
            <<v_arr[ct][1] << " )"<< endl;

        m_arr[ct] = v_mult(key_i, v_arr[ct], prime);

        cout << "marr["<<ct<<"]"<<"( "<<m_arr[ct][0]<<","
            <<m_arr[ct][1] << " )"<< endl;

        message += num_to_ascii(m_arr[ct][0], scale);
        message += num_to_ascii(m_arr[ct][1], scale);

    }
    
    cout<<"the massage is: "<<message<<endl;
    return message;
}

vector<int> v_mult (vector< vector<int> > key_r, vector<int> cipher
        ,int prime)
{
    vector<int> ret = {0,0};
    ret[0] = (cipher[0] * key_r[0][0] + cipher[1]* key_r[1][0]) % prime;
    ret[1] = (cipher[0] * key_r[0][1] + cipher[1]* key_r[1][1]) % prime;
    return ret;
}

 vector< vector<int> > rev_mat(vector< vector<int> > b, int prime)
{
    int rev_det_b = find_inverse(det(b, 2), prime);
    vector< vector<int> > rev = {
        {0,0},
        {0,0}
    };

    rev[0][0] = b[1][1] * rev_det_b % prime;
    rev[0][1] = (-1) * b[0][1] * rev_det_b % prime;
    rev[1][0] = (-1) * b[1][0] * rev_det_b % prime;
    rev[1][1] = b[0][0] * rev_det_b % prime;
    
    cout << "the key matrix is: "<<endl;
    for(int i = 0; i<2; i++){
        for(int j = 0; j<2; j++){
            if(rev[i][j] < 0){
                rev[i][j] = prime + rev[i][j];
            }

            cout << rev[i][j] << "  ";
        }
        cout << endl;
    }

    return rev;
}

//https://gist.github.com/suryadharani/4037974
int det(vector< vector<int> > b,int m)
{
    int sum=0,x=0,y=0,i=0,j,aa,bb,c[b.size()][b.size()];
    //if(m==2)
    return(b[0][0]*b[1][1]-b[0][1]*b[1][0]);
    /*
       else
    {
        for(j=0;j<m;j++)
        {
                for(aa=0,y=0;aa<m;aa++)
                {
                                for(bb=0;bb<m;bb++)
                                {
                              
                                }
                               if(y>0)x++;
                               y=0;
                }
             sum=sum+b[i][j]*pow(-1,i+j)*det(c,m-1);
        }
    }
    return sum;
    */
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
            return (num + 'a');
        }
    }
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
