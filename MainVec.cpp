#include<iostream>
#include<math.h>
#include<string>
#include<sstream>
#include"classVect.h"

 std::string leerVect();
 vector x = vector();

int main(){ 
	 std::cout<<std::endl;
	  int unsigned dim;
	  std::cout<<"ingrese la dimension : ";
		std::cin>>dim;
		x.setDimension(dim);
	  double ele;

   for(int i = 0;i<x.getDimension();i++){
		std::cout<<"vector[ "<<i<<" ] = ";
     std::cin>>ele;
     x.modElemen(i,ele);
   }
  std::cout<<std::endl;
  std::cout<<leerVect();
  std::cout<<std::endl;
	std::cout<<x.busqLineal(2);
	std::cout<<std::endl;
  return 0;
}

 std::string leerVect(){
	 std::string v = "";
	  for(int i=0;i<x.getDimension();i++){
      v = v +"| "+std::to_string(x.getElemen(i));
		}
		v = v + " |"+"\n";
	return v;	
 }