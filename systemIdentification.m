clear;
set(0,'RecursionLimit',1000);

X=importdata("X.txt");
Y=importdata("Y.txt");

X_OUT=0:0.001:0.498;
Y_OUT=interp1(X,Y,X_OUT,'spline');

INPUT=ones(1, 499);

%systemIdentification