clc
clear

addpath('.\trainingdata');
addpath('..\..\src')
x = []; ud = []; 
num =1;
global lambda num_var num_ud
lambda = 0.000001;  
num_var = 2; num_ud = 0;
for i = 1:10
    load(['training', int2str(i),'.mat']);
    
    trace_temp = FnProcessData(xout, num_var, num_ud);
    chpoints = trace_temp.chpoints;
  
    trace(num) = trace_temp;
    x = [x; trace(num).x];
    ud = [ud; trace(num).ud];
    num = num+1; 
end

trace = FnClusterSegs(trace, x, ud);
%%
ode = FnEstODE(trace);

iter = 1000; % number of iterations 
threshDist = 0.01; % tolerance 
inNum = 5; %the least number of inlayers
[trace,label_guard] = FnLI(trace, iter, threshDist, inNum);
pta_trace = FnPTA(trace);