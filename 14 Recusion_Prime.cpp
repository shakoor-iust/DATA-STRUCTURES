#include<iostream> 
 using namespace std; 
  
  
bool isprime(int n, int k) 
{ 
  if( k <= 1 ) 
  { 
    return true; 
  } 
 
  else if(n % k == 0 ) 
  { 
    return false; 
  } 
  else 
    return isprime(n,k-1);  
} 
  
 int main() 
 { 
   int n,k; 
   cout<<"Enter the number to check for Prime or Not: "; 
   cin>>n; 
   k=n-1; 
   cout<<isprime(n,k); 
  
 }
