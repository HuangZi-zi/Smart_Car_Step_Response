clear;
set(0,'RecursionLimit',1000);

X=importdata("X.txt");
Y=importdata("Y.txt");

X_OUT=0:0.001:0.498;
Y_OUT=interp1(X,Y,X_OUT,'spline');
fileIDO=fopen("OUTPUT.txt",'w');
fprintf(fileIDO,'%f\n',Y_OUT);
fclose(fileIDO);

INPUT=ones(1, 499);
fileIDI=fopen("INPUT.txt",'w');
fprintf(fileIDI,'%f\n',INPUT);
fclose(fileIDI);

clear;
load("INPUT.txt");
load("OUTPUT.txt");

systemIdentification