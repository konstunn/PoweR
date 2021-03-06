// Title: Statistique de test de Hosking based on trimmed L-moments T_{Lmom}^{(1)}
// Ref. (book or article): Hosking, J.R.M. (1990). "L-moments: analysis and estimation of distributions using linear combinations of order statistics",
//						   Journal of the Royal Statistical Society, Series B 52: 105-124.

#include <R.h>
#include "Rmath.h"

extern "C" {

  void stat11(double *x, int *xlen, double *level, int *nblevel, char **name, int *getname, double *statistic, int *pvalcomp, double *pvalue, double *critvalL, double *critvalR, int *usecrit, int *alter, int *decision, double *paramstat, int *nbparamstat) {

// If the test statistic can only be in category 3 or 4 (see just below), INDICATE the following line accordingly. Else, leave it commented.
// 0: two.sided=bilateral, 1: less=unilateral, 2: greater=unilateral, 3: bilateral test that rejects H0 only for large values of the test statistic, 
// 4: bilateral test that rejects H0 only for small values of the test statistic
    alter[0] = 3;
    
    int i, j=0, n=xlen[0];
    if (getname[0] == 1) {
// Here, INDICATE the name of your statistic
      const char *nom = "$T_{Lmom}^{(1)}$";
// Here, INDICATE the number of parameters of your statistic
      nbparamstat[0] = 0;
// Here, INDICATE the default values of the parameters:
      if (name[0][0] == '1') { // To prevent writing in a non declared address (because maybe paramstat has not be initialized with a sufficient length since the correct value of nbparamstat[0] may be unkown yet).

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

    if (n>3) {
// Computation of the value of the test statistic
      void R_rsort (double* x, int n);
      double pchisq(double q, double df, int lower_tail, int log_p);
      double pstarmod1(int r, int k, int i);
      double *xtmp;
      xtmp = new double[n];
      double statTLmom1, l21=0.0, l31=0.0, l41=0.0, tau31, tau41;
      double mutau41, vtau31, vtau41;
      

      for (i=0;i<=(n-1);i++) xtmp[i] = x[i];
      
      R_rsort(xtmp,n); // We sort the data

      for (i=2;i<=(n-1);i++) {

	l21 = l21 + xtmp[i-1]*pstarmod1(2,n,i);
	l31 = l31 + xtmp[i-1]*pstarmod1(3,n,i);
	l41 = l41 + xtmp[i-1]*pstarmod1(4,n,i);

      }

      l21 = l21/(2.0*choose((double)n,4.0));
      l31 = l31/(3.0*choose((double)n,5.0));
      l41 = l41/(4.0*choose((double)n,6.0));

      tau31 = l31/l21;
      tau41 = l41/l21;

      if (1<=n && n<=25) {
	mutau41 = 0.067077;
	vtau31 = 0.0081391;
	vtau41 = 0.0042752;
      }

      if (25<n && n<=50) {
	mutau41 = 0.064456;
	vtau31 = 0.0034657;
	vtau41 = 0.0015699;
      }
 
      if (50<n) {
	mutau41 = 0.063424;
	vtau31 = 0.0016064;
	vtau41 = 0.00068100;
      }


      statTLmom1 = R_pow(tau31,2.0)/vtau31 + R_pow(tau41 - mutau41,2.0)/vtau41;
      
      statistic[0] = statTLmom1; // Here is the test statistic value

if (pvalcomp[0] == 1) {
	// If possible, computation of the p-value.
	#include "pvalues/pvalue11.cpp"
}

// We take the decision to reject or not to reject the null hypothesis H0
    for (i=0;i<=(nblevel[0]-1);i++) {
      if (usecrit[0] == 1) { // We use the provided critical values
	if (statistic[0] > critvalR[i]) decision[i] = 1; else decision[i] = 0; // two.sided (but in this case only one possible critical value)
      } else {
	if (pvalue[0] < level[i]) decision[i] = 1; else decision[i] = 0; // We use the p-value
      }
    }

 // If applicable, we free the unused array of pointers
      delete[] xtmp;
    }
    
// We return
    return;
   
    
  }


  double pstarmod1(int r, int n, int i) {

    double choose(double n, double k);
    double res=0.0;
    int k;

    for (k=0;k<=(r-1);k++) {

      res = res + R_pow(-1.0,(double)k) * choose((double)(r-1),(double)k) * choose((double)(i-1),(double)(r+1-1-k)) * choose((double)(n-i),(double)(1+k));

    }

    return(res);

  }

  
}
