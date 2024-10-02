//https://github.com/RoberAgro/primer_adolc
#include <iostream>
#include <iomanip>
#include <cmath>
#include "adolc/adolc.h"

//define the function to be differentiated: f(x) = e^x
adouble foo(adouble x){
    adouble f = exp(x);
    return f;
}

int main() {
    //init problem variables 

    int m = 1, n=1;
    //independent vector 
    auto xp = new double[n];
    xp[0] = 1;

    //dependet vector 
    auto yp = new double[m];
    yp[0] = 0; 

    //init active variables 
    auto x = new adouble[n];
    auto y = new adouble[m];

    //active section for auto diff

    //set the tag for the auto diff trace 
    int tag = 0;
    
    //start tracing floating point operations 
    trace_on(tag); //start of the active section 

    //assign independet variables 
    x[0] <<=xp[0];

    //eval the body of the differentiated code 
    y[0] = foo(x[0]);

    //assign dependent variables 
    y[0] >>= yp[0];

    trace_off(); //end of active section 

    //compute the first derivative 

    //declare the tangent vector 
    auto x1 = new double[n]; 
    x1[0] = 1;

    //declare the vector of the first derivative 
    auto y1 = new double[m];

    //define a flag to prepare for reverse auto diff 

    int keep = 0;

    //compute the derivatives of f(x)
    fos_forward(tag, m, n, keep, xp, x1, yp, y1);

    std::cout<<"Derivatives computation in forward mode\n";
    std::cout<< std::setw(20) << "AD derivative"<< std::setw(25)<< "Analytic derivative\n";
    std::cout.precision(8);
    std::cout.setf(std::ios::fixed);
    std::cout<< std::setw(20)<< y1[0] << std::setw(25) << foo(xp[0]).value() << "\n";

    
    return 0;
}