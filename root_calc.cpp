#include<iostream>
#include<cmath>
using namespace std;

double derivative(double bi_cnstnt[],int n,double x) //x mane seed
{
    if(n==0) return 0;
    else return bi_cnstnt[n]*n*pow(x,n-1) + derivative(bi_cnstnt, n-1, x);
}

double function_value(double bi_cnstnt[],int n,double x) //x mane seed
{
    if(n==0) return bi_cnstnt[n];
    else return bi_cnstnt[n]*pow(x,n) + function_value(bi_cnstnt, n-1,x); 
}

double newton_method(double bi_cnstnt[], int n, double x, int a) 
{
    double xInitial = x;
    double fx = function_value(bi_cnstnt, n, x);
    double dfx = derivative(bi_cnstnt, n, x);

    if (fabs(dfx) < 1e-12) {
        cerr << "Error: Derivative too small. Newton's method may fail." << endl;
        exit(1);
    }

    double xFinal = x - fx / dfx;

    if (fabs(xFinal - xInitial) < pow(10, -a)) return xFinal;

    return newton_method(bi_cnstnt, n, xFinal, a);
}

int main()
{    int n;//order of polynomial
    cout<<"Enter the order of polynomial: ";
    cin>>n;
    
    //polynomial show korar jonne habijabi print
    char alphabet[26], initial='a';
    for(int i=0; i<26; i++)
    {
        alphabet[i]=initial;
        initial++;
    }
    cout<<endl;
    for(int i=0,j=n; i<=n; i++,j--)
    {
        if(i==n) cout<<alphabet[i];
        else cout<<alphabet[i]<<"x^"<<j<<"+";
    }
    cout<<endl<<endl;
   //actual code start
    //input binomial constants like a,b,c,d
    double bi_cnstnt[n+1];
    for(int i=0; i<n+1; i++)
    {
        cout<<alphabet[i]<<" = ";
        cin>>bi_cnstnt[i];
    }
   //binomial constant swapping for easier recursion action
    for(int i=0; i<(n+1)/2; i++)
    {
        double temp = bi_cnstnt[n-i];
        bi_cnstnt[n-i] = bi_cnstnt[i];
        bi_cnstnt[i] = temp;
    }
    //input seed value
    cout<<"Enter seed value: ";
    double seed;
    cin>>seed; 

    //input accuracy point
    cout<<"Enter number of digit after decimal point : ";
    int acc;
    cin>>acc;


    double result= newton_method(bi_cnstnt,n,seed,acc);
    cout << endl << "Root: " << result << endl;

return 0;
}