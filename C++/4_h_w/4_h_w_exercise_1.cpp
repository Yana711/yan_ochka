#include <iostream>
using namespace std;
# define n 3
struct vector{
  float vec[n];
};

void sum(struct vector a, struct vector b){
  struct vector c{};
  for(int i = 0; i<n; i++){
    c.vec[i] = a.vec[i]+b.vec[i];
  }
  cout<<"Результат сложения двух векторов: "<<"\n";
  for(int i = 0; i<n; i++){
    cout<<c.vec[i]<<" ";
}
cout<<"\n";
}


void the_product_of_a_number(struct vector a, float value){
  struct vector c{};
  for(int i = 0; i<n; i++){
    c.vec[i] = a.vec[i] * value;
  }
  cout<<"Результат произведение вектора на число: "<<"\n";
  for(int i = 0; i<n; i++){
    cout<<c.vec[i]<<" ";
  }
  cout<<"\n";
}

void the_scalar_product(struct vector a, struct vector b){
  float scalar;
  for(int i = 0; i<n; i++){
    scalar += a.vec[i]*b.vec[i];
  }
  cout<<"Результат скалярного произведение: "<< scalar <<"\n";
}

int main() 
{
cout<<"Введите число, на которое мы будем умножать вектор\n";
float number;
cin>>number;

cout<<"Введите координаты вектора в формате x_1, y_1, x_2, y_2 ...\n";
float x, y;
struct vector vec_1{};
struct vector vec_2{};
for(int i = 0; i<n; i++){
  cin>>x>>y;
  vec_1.vec[i] = x;
  vec_2.vec[i] = y;
}

sum(vec_1, vec_2);
the_product_of_a_number(vec_1, number);
the_product_of_a_number(vec_2, number);
the_scalar_product(vec_1, vec_2);
}