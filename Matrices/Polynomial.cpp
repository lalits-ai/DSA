#include<iostream>
using namespace std;
struct poly
{
  int coeff,expo;
};
int main()
{
  // Reading polynomials

  int len1,len2;
  cout<<"Enter the length of 1st polynomial: ";
  cin>>len1;
  poly p[len1];
  cout<<"Enter the polynomial: "<<endl;
  for(int i=0;i<len1;i++)
  {
    cout<<"Enter the "<<i+1<<" coefficient: ";
    cin>>p[i].coeff;
    cout<<"Enter the "<<i+1<<" exponent: ";
    cin>>p[i].expo;
  }
  cout<<"Enter the length of 2nd polynomial : ";
  cin>>len2;
  poly q[len2];
  cout<<"Enter the polynomial : "<<endl;
  for(int i=0;i<len2;i++)
  {
    cout<<"Enter the coefficient: ";
    cin>>q[i].coeff;
    cout<<"Enter the exponent: ";
    cin>>q[i].expo;
  }

  int addedSize = len1 + len2;

  // Adding the polynomials

  poly add[addedSize];
  int i=0,j=0;
  int addTrack = 0; // For keeping track of added polynomial terms
  while(i < len1 && j < len2)
  {
    if(p[i].expo == q[j].expo)
    {
      add[addTrack].coeff = p[i].coeff + q[j].coeff;
      add[addTrack].expo = p[i].expo;
      i++;
      j++;
      addTrack++;
    }
    else if(p[i].expo > q[j].expo)
    {
      add[addTrack].coeff = p[i].coeff;
      add[addTrack].expo = p[i].expo;
      i++;
      addTrack++;
    }
    else
    {
      add[addTrack].coeff = q[j].coeff;
      add[addTrack].expo = q[j].expo;
      j++;
      addTrack++;
    }
  }
  
  // Appending remaining terms, if any

  while(i < len1)
  {
    add[addTrack].coeff = p[i].coeff;
    add[addTrack].expo = p[i].expo;
    i++;
    addTrack++;
  }

  while(j < len2)
  {
    add[addTrack].coeff = q[j].coeff;
    add[addTrack].expo = q[j].expo;
    j++;
    addTrack++; 
  }

  // Displaying polynomials

    //Polynomial 1

    cout<<"---------------------------------------------------"<<endl;
    cout<<"Polynomial 1: ";
    for(int i=0;i<len1;i++)
    {
      // if(i != len1-1)
        cout<<p[i].coeff<<"x^"<<p[i].expo<<" ";
      // else  
      //   cout<<p[i].coeff<<endl;
    }

    // Polynomial 2

    cout<<"Polynomial 2: ";
    for(int i=0;i<len2;i++)
    {
      // if(i != len1-1)
        cout<<q[i].coeff<<"x^"<<q[i].expo<<" ";
      // else  
      //   cout<<q[i].coeff<<endl;
    }
  
  // Displaying the added polynomial

  cout<<"Added polynomial: ";
  for(int i=0;i<addTrack;i++)
  {
    // if(i != addTrack-1)
      cout<<add[i].coeff<<"x^"<<add[i].expo<<" ";
    // else  
    //   cout<<add[i].coeff<<endl;
  }
  cout<<"---------------------------------------------------"<<endl;
  return 0;
}