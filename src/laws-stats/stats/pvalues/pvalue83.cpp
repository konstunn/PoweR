if (alter[0] == 0) {
  pvaltmp = 2.0 * pt(fabs(statT), n-1, 1, 0);
 }
 else if (alter[0] == 1) {
   pvaltmp = pt(statT, n-1, 1, 0);
 }
 else if (alter[0] == 2) {
   pvaltmp = pt(statT, n-1, 0, 0);
 }

pvalue[0] = pvaltmp;
