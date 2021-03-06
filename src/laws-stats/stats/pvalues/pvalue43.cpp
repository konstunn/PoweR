void probQsupx(double *x, double *lambda, int *lambdalen, double *h, double *delta2, double *Qx, double *epsabs, double *epsrel, int *limit);
double *statW2, *lambdasW2, *h, *delta2, *Qx, *epsabs, *epsrel;
statW2 = new double[1];
lambdasW2 = new double[200];
h = new double[200];
delta2 = new double[200];
Qx = new double[1];
epsabs = new double[1];
epsrel = new double[1];
int *lambdasW2len, *limit;
lambdasW2len = new int[1];
limit = new int[1];

statW2[0] = statCvM;

// Vector of 200 lambdas for W^2 test

lambdasW2[0]   = 2.533030e-02; lambdasW2[1]   = 1.048856e-02; lambdasW2[2]   = 6.332574e-03; lambdasW2[3]   = 4.257996e-03; 
lambdasW2[4]   = 2.814477e-03; lambdasW2[5]   = 2.031808e-03; lambdasW2[6]   = 1.583143e-03; lambdasW2[7]   = 1.261975e-03; 
lambdasW2[8]   = 1.013212e-03; lambdasW2[9]   = 8.556529e-04; lambdasW2[10]  = 7.036193e-04; lambdasW2[11]  = 5.878033e-04;
lambdasW2[12]  = 5.169448e-04; lambdasW2[13]  = 3.957959e-04; lambdasW2[14]  = 3.957859e-04; lambdasW2[15]  = 3.127297e-04;
lambdasW2[16]  = 3.127197e-04; lambdasW2[17]  = 2.533130e-04; lambdasW2[18]  = 2.533030e-04; lambdasW2[19]  = 2.093513e-04;
lambdasW2[20]  = 2.093413e-04; lambdasW2[21]  = 1.759148e-04; lambdasW2[22]  = 1.759048e-04; lambdasW2[23]  = 1.498934e-04;
lambdasW2[24]  = 1.498834e-04; lambdasW2[25]  = 1.292462e-04; lambdasW2[26]  = 1.292362e-04; lambdasW2[27]  = 1.125891e-04;
lambdasW2[28]  = 1.125791e-04; lambdasW2[29]  = 9.895647e-05; lambdasW2[30]  = 9.894647e-05; lambdasW2[31]  = 8.765808e-05;
lambdasW2[32]  = 8.764808e-05; lambdasW2[33]  = 7.818993e-05; lambdasW2[34]  = 7.817993e-05; lambdasW2[35]  = 7.017702e-05;
lambdasW2[36]  = 7.016702e-05; lambdasW2[37]  = 6.333574e-05; lambdasW2[38]  = 6.332574e-05; lambdasW2[39]  = 5.744831e-05;
lambdasW2[40]  = 5.743831e-05; lambdasW2[41]  = 5.234532e-05; lambdasW2[42]  = 5.233532e-05; lambdasW2[43]  = 4.789336e-05;
lambdasW2[44]  = 4.788336e-05; lambdasW2[45]  = 4.398621e-05; lambdasW2[46]  = 4.397621e-05; lambdasW2[47]  = 4.053847e-05;
lambdasW2[48]  = 4.052847e-05; lambdasW2[49]  = 3.748085e-05; lambdasW2[50]  = 3.747085e-05; lambdasW2[51]  = 3.475663e-05;
lambdasW2[52]  = 3.474663e-05; lambdasW2[53]  = 3.231905e-05; lambdasW2[54]  = 3.230905e-05; lambdasW2[55]  = 3.012926e-05;
lambdasW2[56]  = 3.011926e-05; lambdasW2[57]  = 2.815477e-05; lambdasW2[58]  = 2.814477e-05; lambdasW2[59]  = 2.636827e-05;
lambdasW2[60]  = 2.635827e-05; lambdasW2[61]  = 2.474662e-05; lambdasW2[62]  = 2.473662e-05; lambdasW2[63]  = 2.327014e-05;
lambdasW2[64]  = 2.326014e-05; lambdasW2[65]  = 2.192202e-05; lambdasW2[66]  = 2.191202e-05; lambdasW2[67]  = 2.068779e-05;
lambdasW2[68]  = 2.067779e-05; lambdasW2[69]  = 1.955498e-05; lambdasW2[70]  = 1.954498e-05; lambdasW2[71]  = 1.851277e-05;
lambdasW2[72]  = 1.850277e-05; lambdasW2[73]  = 1.755176e-05; lambdasW2[74]  = 1.754176e-05; lambdasW2[75]  = 1.666371e-05; 
lambdasW2[76]  = 1.665371e-05; lambdasW2[77]  = 1.584143e-05; lambdasW2[78]  = 1.583143e-05; lambdasW2[79]  = 1.507859e-05;
lambdasW2[80]  = 1.506859e-05; lambdasW2[81]  = 1.436958e-05; lambdasW2[82]  = 1.435958e-05; lambdasW2[83]  = 1.370946e-05;
lambdasW2[84]  = 1.369946e-05; lambdasW2[85]  = 1.309383e-05; lambdasW2[86]  = 1.308383e-05; lambdasW2[87]  = 1.251879e-05;
lambdasW2[88]  = 1.250879e-05; lambdasW2[89]  = 1.198084e-05; lambdasW2[90]  = 1.197084e-05; lambdasW2[91]  = 1.147686e-05;
lambdasW2[92]  = 1.146686e-05; lambdasW2[93]  = 1.100405e-05; lambdasW2[94]  = 1.099405e-05; lambdasW2[95]  = 1.055989e-05;
lambdasW2[96]  = 1.054989e-05; lambdasW2[97]  = 1.014212e-05; lambdasW2[98]  = 1.013212e-05; lambdasW2[99]  = 9.748676e-06;
lambdasW2[100] = 9.738676e-06; lambdasW2[101] = 9.377713e-06; lambdasW2[102] = 9.367713e-06; lambdasW2[103] = 9.027549e-06;
lambdasW2[104] = 9.017549e-06; lambdasW2[105] = 8.696658e-06; lambdasW2[106] = 8.686658e-06; lambdasW2[107] = 8.383652e-06;
lambdasW2[108] = 8.373652e-06; lambdasW2[109] = 8.087263e-06; lambdasW2[110] = 8.077263e-06; lambdasW2[111] = 7.806336e-06;
lambdasW2[112] = 7.796336e-06; lambdasW2[113] = 7.539814e-06; lambdasW2[114] = 7.529814e-06; lambdasW2[115] = 7.286730e-06;
lambdasW2[116] = 7.276730e-06; lambdasW2[117] = 7.046193e-06; lambdasW2[118] = 7.036193e-06; lambdasW2[119] = 6.817389e-06;
lambdasW2[120] = 6.807389e-06; lambdasW2[121] = 6.599567e-06; lambdasW2[122] = 6.589567e-06; lambdasW2[123] = 6.392035e-06;
lambdasW2[124] = 6.382035e-06; lambdasW2[125] = 6.194154e-06; lambdasW2[126] = 6.184154e-06; lambdasW2[127] = 6.005336e-06;
lambdasW2[128] = 5.995336e-06; lambdasW2[129] = 5.825036e-06; lambdasW2[130] = 5.815036e-06; lambdasW2[131] = 5.652748e-06;
lambdasW2[132] = 5.642748e-06; lambdasW2[133] = 5.488005e-06; lambdasW2[134] = 5.478005e-06; lambdasW2[135] = 5.330373e-06;
lambdasW2[136] = 5.320373e-06; lambdasW2[137] = 5.179448e-06; lambdasW2[138] = 5.169448e-06; lambdasW2[139] = 5.034855e-06;
lambdasW2[140] = 5.024855e-06; lambdasW2[141] = 4.896245e-06; lambdasW2[142] = 4.886245e-06; lambdasW2[143] = 4.763293e-06;
lambdasW2[144] = 4.753293e-06; lambdasW2[145] = 4.635693e-06; lambdasW2[146] = 4.625693e-06; lambdasW2[147] = 4.513164e-06;
lambdasW2[148] = 4.503164e-06; lambdasW2[149] = 4.395439e-06; lambdasW2[150] = 4.385439e-06; lambdasW2[151] = 4.282271e-06;
lambdasW2[152] = 4.272271e-06; lambdasW2[153] = 4.173428e-06; lambdasW2[154] = 4.163428e-06; lambdasW2[155] = 4.068692e-06;
lambdasW2[156] = 4.058692e-06; lambdasW2[157] = 3.967859e-06; lambdasW2[158] = 3.957859e-06; lambdasW2[159] = 3.870737e-06;
lambdasW2[160] = 3.860737e-06; lambdasW2[161] = 3.777147e-06; lambdasW2[162] = 3.767147e-06; lambdasW2[163] = 3.686919e-06;
lambdasW2[164] = 3.676919e-06; lambdasW2[165] = 3.599895e-06; lambdasW2[166] = 3.589895e-06; lambdasW2[167] = 3.515923e-06;
lambdasW2[168] = 3.505923e-06; lambdasW2[169] = 3.434864e-06; lambdasW2[170] = 3.424864e-06; lambdasW2[171] = 3.356584e-06;
lambdasW2[172] = 3.346584e-06; lambdasW2[173] = 3.280958e-06; lambdasW2[174] = 3.270958e-06; lambdasW2[175] = 3.207866e-06;
lambdasW2[176] = 3.197866e-06; lambdasW2[177] = 3.137197e-06; lambdasW2[178] = 3.127197e-06; lambdasW2[179] = 3.068845e-06;
lambdasW2[180] = 3.058845e-06; lambdasW2[181] = 3.002710e-06; lambdasW2[182] = 2.992710e-06; lambdasW2[183] = 2.938696e-06;
lambdasW2[184] = 2.928696e-06; lambdasW2[185] = 2.876715e-06; lambdasW2[186] = 2.866715e-06; lambdasW2[187] = 2.816681e-06;
lambdasW2[188] = 2.806681e-06; lambdasW2[189] = 2.758513e-06; lambdasW2[190] = 2.748513e-06; lambdasW2[191] = 2.702135e-06;
lambdasW2[192] = 2.692135e-06; lambdasW2[193] = 2.647474e-06; lambdasW2[194] = 2.637474e-06; lambdasW2[195] = 2.594460e-06;
lambdasW2[196] = 2.584460e-06; lambdasW2[197] = 2.543030e-06; lambdasW2[198] = 2.533030e-06; lambdasW2[199] = 2.493119e-06;



// double lambdastmp[200] = {2.533030e-02, 1.048856e-02, 6.332574e-03, 4.257996e-03, 2.814477e-03,
 		                  // 2.031808e-03, 1.583143e-03, 1.261975e-03, 1.013212e-03, 8.556529e-04,
                          // 7.036193e-04, 5.878033e-04, 5.169448e-04, 3.957959e-04, 3.957859e-04,
                          // 3.127297e-04, 3.127197e-04, 2.533130e-04, 2.533030e-04, 2.093513e-04,
                          // 2.093413e-04, 1.759148e-04, 1.759048e-04, 1.498934e-04, 1.498834e-04,
                          // 1.292462e-04, 1.292362e-04, 1.125891e-04, 1.125791e-04, 9.895647e-05,
                          // 9.894647e-05, 8.765808e-05, 8.764808e-05, 7.818993e-05, 7.817993e-05,
                          // 7.017702e-05, 7.016702e-05, 6.333574e-05, 6.332574e-05, 5.744831e-05,
                          // 5.743831e-05, 5.234532e-05, 5.233532e-05, 4.789336e-05, 4.788336e-05,
                          // 4.398621e-05, 4.397621e-05, 4.053847e-05, 4.052847e-05, 3.748085e-05,
                          // 3.747085e-05, 3.475663e-05, 3.474663e-05, 3.231905e-05, 3.230905e-05,
                          // 3.012926e-05, 3.011926e-05, 2.815477e-05, 2.814477e-05, 2.636827e-05,
                          // 2.635827e-05, 2.474662e-05, 2.473662e-05, 2.327014e-05, 2.326014e-05,
                          // 2.192202e-05, 2.191202e-05, 2.068779e-05, 2.067779e-05, 1.955498e-05,
                          // 1.954498e-05, 1.851277e-05, 1.850277e-05, 1.755176e-05, 1.754176e-05,
                          // 1.666371e-05, 1.665371e-05, 1.584143e-05, 1.583143e-05, 1.507859e-05,
                          // 1.506859e-05, 1.436958e-05, 1.435958e-05, 1.370946e-05, 1.369946e-05,
                          // 1.309383e-05, 1.308383e-05, 1.251879e-05, 1.250879e-05, 1.198084e-05,
                          // 1.197084e-05, 1.147686e-05, 1.146686e-05, 1.100405e-05, 1.099405e-05,
                          // 1.055989e-05, 1.054989e-05, 1.014212e-05, 1.013212e-05, 9.748676e-06,
                          // 9.738676e-06, 9.377713e-06, 9.367713e-06, 9.027549e-06, 9.017549e-06,
						  // 8.696658e-06, 8.686658e-06, 8.383652e-06, 8.373652e-06, 8.087263e-06,
						  // 8.077263e-06, 7.806336e-06, 7.796336e-06, 7.539814e-06, 7.529814e-06,
						  // 7.286730e-06, 7.276730e-06, 7.046193e-06, 7.036193e-06, 6.817389e-06,
						  // 6.807389e-06, 6.599567e-06, 6.589567e-06, 6.392035e-06, 6.382035e-06,
						  // 6.194154e-06, 6.184154e-06, 6.005336e-06, 5.995336e-06, 5.825036e-06,
						  // 5.815036e-06, 5.652748e-06, 5.642748e-06, 5.488005e-06, 5.478005e-06,
						  // 5.330373e-06, 5.320373e-06, 5.179448e-06, 5.169448e-06, 5.034855e-06,
						  // 5.024855e-06, 4.896245e-06, 4.886245e-06, 4.763293e-06, 4.753293e-06,
						  // 4.635693e-06, 4.625693e-06, 4.513164e-06, 4.503164e-06, 4.395439e-06,
						  // 4.385439e-06, 4.282271e-06, 4.272271e-06, 4.173428e-06, 4.163428e-06,
						  // 4.068692e-06, 4.058692e-06, 3.967859e-06, 3.957859e-06, 3.870737e-06,
						  // 3.860737e-06, 3.777147e-06, 3.767147e-06, 3.686919e-06, 3.676919e-06,
						  // 3.599895e-06, 3.589895e-06, 3.515923e-06, 3.505923e-06, 3.434864e-06,
						  // 3.424864e-06, 3.356584e-06, 3.346584e-06, 3.280958e-06, 3.270958e-06,
						  // 3.207866e-06, 3.197866e-06, 3.137197e-06, 3.127197e-06, 3.068845e-06,
						  // 3.058845e-06, 3.002710e-06, 2.992710e-06, 2.938696e-06, 2.928696e-06,
						  // 2.876715e-06, 2.866715e-06, 2.816681e-06, 2.806681e-06, 2.758513e-06,
						  // 2.748513e-06, 2.702135e-06, 2.692135e-06, 2.647474e-06, 2.637474e-06,
						  // 2.594460e-06, 2.584460e-06, 2.543030e-06, 2.533030e-06, 2.493119e-06 };


for (i=0; i<200; i++) {
	// lambdasW2[i] = lambdastmp[i];
	h[i] = 1.0;
	delta2[i] = 0.0;
}

Qx[0] = 0.0;
epsabs[0] = 0.000001;
epsrel[0] = 0.000001;
lambdasW2len[0] = 200;
limit[0] = 10000;

probQsupx(statW2,lambdasW2,lambdasW2len,h,delta2,Qx,epsabs,epsrel,limit);		

pvalue[0] = Qx[0];


delete[] statW2;
delete[] lambdasW2;
delete[] h;
delete[] delta2;
delete[] Qx;
delete[] epsabs;
delete[] epsrel;
delete[] lambdasW2len;
delete[] limit;
