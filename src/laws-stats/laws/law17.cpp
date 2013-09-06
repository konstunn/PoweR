// Title: JSU(mu,sigma,nu,tau)
// Ref. (book or article): N. L. Johnson, "Systems of Frequency Curves Generated by Methods of Translation", Biometrika, Vol. 36, No. 1/2 (Jun., 1949), pp. 149-176
// See also the rJSU() function in package gamlss
// Be carefull that this is not the same parameterization as Mathematica

#include <R.h>
#include "Rmath.h"

extern "C" {

  void law17 (int *xlen, double *x, char **name, int *getname, double *params, int *nbparams, int *setseed) {

    int i, j=0, n=xlen[0];
    if (getname[0] == 1) {
// Here, INDICATE the name of the distribution:
   const char *nom = "$JSU(\\mu,\\sigma,\\nu,\\tau)$";
// Here, INDICATE the number of parameters of the distribution:
      nbparams[0] = 4;
// Here, INDICATE the default values of the parameters:
      if (name[0][0] == '1') { // To prevent writing in a non declared address (because maybe params has not be initialized with a sufficient length since the correct value of nbparams[0] may be unkown yet).
      params[0] = 0.0;
      params[1] = 1.0;
      params[2] = 0.0;
      params[3] = 0.5;
     }
// The following 7 lines should NOT be modified
      const char *space = " ";
      while (nom[j] != '\0') {
	name[j][0] = nom[j];
	j++;
      }
      for (i=j;i<50;i++) name[i][0] = space[0];
      return;
    }
     
// Initialization of the parameters
    double mu, sigma, nu, tau;
    if (nbparams[0] == 0) {
      nbparams[0] = 4;
      mu = 0.0;
      sigma = 1.0;
      nu = 0.0;
      tau = 0.5;
      params[0] = 0.0;
      params[1] = 1.0;
      params[2] = 0.0;
      params[3] = 0.5;
    } else if (nbparams[0] == 1) {
      nbparams[0] = 4;
      mu = params[0];
      sigma = 1.0;
      nu = 0.0;
      tau = 0.5;
      params[1] = 1.0;
      params[2] = 0.0;
      params[3] = 0.5;
    } else if  (nbparams[0] == 2) {
      nbparams[0] = 4;
      mu = params[0];
      sigma = params[1];
      nu = 0.0;
      tau = 0.5;
      params[2] = 0.0;
      params[3] = 0.5;
    } else if  (nbparams[0] == 3) {
      nbparams[0] = 4;
      mu = params[0];
      sigma = params[1];
      nu = params[2];
      tau = 0.5;
      params[3] = 0.5;
    } else if  (nbparams[0] == 4) {
      mu = params[0];
      sigma = params[1];
      nu = params[2];
      tau = params[3];
    } else {
      error("Number of parameters should be at most: 4");
    }

// If necessary, we check if some parameter values are out of parameter space
    if (sigma <= 0 || tau <= 0) {
      warning("sigma and tau should be > 0 in law17!\n");
      for (i=0;i<n;i++) x[i] = R_NaN;
      return;
    }

// Generation of the random values
    if (setseed[0] == 1) GetRNGstate();   
    double runif(double a, double b);
    double qnorm(double p, double mean, double sd, int lower_tail, int log_p);
    double *U, rtau;
    U = new double [n];
    for (i=0;i<n;i++) U[i] = runif(0.0,1.0);
    double w, omega, c;
    rtau = 1.0/tau;
    if (rtau < 0.0000001) w = 1.0; else w = exp(rtau*rtau);
    omega = -nu*rtau;
    c = 1.0/sqrt(0.5*(w-1.0)*(w*cosh(2.0*omega)+1.0));
    for (i=0;i<n;i++) x[i] = (mu+c*sigma*sqrt(w)*sinh(omega)) + c*sigma*sinh(rtau*(qnorm(U[i],0.0,1.0,1,0)+nu));
    if (setseed[0] == 1) PutRNGstate();

// If applicable, we free the unused array of pointers. Then we return.
    delete[] U;
    
    return;
    
  }
  
}