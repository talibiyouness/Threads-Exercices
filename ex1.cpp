#include <iostream>       
#include <thread>        
#include <mutex>
#include <math.h>
#include "ctpl.h"

//source de la fonction Factoriel : https://www.gladir.com/CODER/CPP/factoriel.htm


std::mutex mtx;

 float result=0;

void FormuleFac(float n){

    	mtx.lock();
    	float d=pow(-1,n);
    	float p=Factoriel(n);
    	result+=d/p;
    	mtx.unlock();    	
    	std::cout << result <<endl;
    	
    }


float Factoriel(float n) {
  	 return n > 1?(n * Factoriel(n-1)):1;
	}

  	

int main () {


int NumThread=4;
int n=14;

ctpl::thread_pool p(NumThread);

p.push(FormuleFac, n);


return 0;

}