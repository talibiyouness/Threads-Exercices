#include <iostream>       
#include <thread>         
#include <mutex>
#include <string>
#include <list>
#include "md5.h"


std::mutex mtx;


int main() 
{
	std::list<char> alphabet ={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
	string secret="3ed7dceaf266cafef032b9d5db224717";
	std::thread th[26];
	int test = 0;
	int i = 0;

do{	
	 th[i]=thread([&] { 
	 string hachage=""; 
	 mtx.lock(); 
	 hachage = hachage+alphabet[i]; 
	 mtx.unlock();

int j=0;


do{  if(test==0) break;	 mtx.lock(); hachage = hachage + alphabet[j]; mtx.unlock(); 

	int k = 0;
	  while ( k <= 25 ){if(test == 0) break; mtx.lock(); hachage=hachage + alphabet[k];	mtx.unlock();
	 int L = 0;
	while ( L <= 25){if(test == 0) break; mtx.lock(); hachage = hachage + alphabet[L]; mtx.unlock(); 
	int M = 0;
    while (M <= 25){if(test == 0) break; mtx.lock(); hachage = hachage+ alphabet[M]; if(md5(hachage) == secret) { std::cout << "+++ Resultat Hache +++  "<< hachage<< endl; test = 1; } mtx.unlock(); hachage.pop_back();
	M++;}
	 hachage.pop_back();
	 L++;}
	 hachage.pop_back();
	 k++;}
	 hachage.pop_back();
     ++j;

  }while(j <= 25);

});	++i;

}while(i <= 25);



for (int A = 0; A <= 25; ++A)
{
	th[A].join();
}

	
  return 0;
}