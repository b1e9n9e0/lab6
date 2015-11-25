/*
*
Author: b1e9n9e0
Date: 25.11.15

Task:
implement euler metod forward and backward for yd = lambda*y
*
tn+1 = tn + dt
yn+1 = yn + h * f(y)

y[i] = y[i-1]+dt*lambda*y[i-1]
*/

#include <fstream>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>

using namespace std;


int main(){

const int N = 100; //Number of steps
const double lambda = -0.5;
const double dt = 0.1; //size of timestep

double fn;
double yn0 = 1;
double yn1 = 1;
double yn2 = 1;
double yn3 = 1;
double tn = 0;


ofstream out1("out1.txt");

for(int i = 0; i < N; i++){	
	out1 << tn << "\t" << yn0 << "\t" << yn1 << "\t" << yn2 << "\t" << yn3 << endl;
	tn += dt;
	yn0 = exp(lambda * tn);
	yn1 += dt * lambda * yn1; //forward euler
	yn2 /= (1-(dt*lambda)); //backward euler yn-dtlambda yn = yn-1 => yn(1-dt lambda) = yn-1  => yn = yn-1/(1-dt*lambda)
	yn3 = ((yn3 + dt*lambda*yn3)+(yn3/(1-(dt*lambda))))/2;
	

}
out1.close();


return 0;

}