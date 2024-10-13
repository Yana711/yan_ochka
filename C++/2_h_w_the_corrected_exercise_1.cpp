#include <iostream>
#include <math.h>
using namespace std;

int main() 
{   double the_square_root;
    int value, remains, divider, counter = 0, the_largest_divisor = 0, the_smallest_divisor = 0;
    cin >> value;
    divider = 0;
    remains = 0;
    if (value==1)
    {cout <<"1";}
    
    if (value==2)
    {cout <<"Простое число";}
    
    if (value>2)
    {the_square_root = sqrt(value);
      
      for (int i = 2; i <= the_square_root; i++)
    {remains = value % i;
    if (remains==0)
    {divider = i;
      counter = counter + 1;
    }
    if(counter == 1){
      the_smallest_divisor = divider;
    }
    }
    
    if(divider==0)
    {cout <<"Простое число\n";}
    
    else{
    the_largest_divisor = value/the_smallest_divisor;
    cout<<"Наибольший делитель, не являющися исходным числом: " << the_largest_divisor;
    }
    } 
      
}