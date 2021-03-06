function trace = FnProcessData2(xout, num_var, num_ud)
    
    ichpoints = {};
    chpoints = [];
    for i = 1:num_var
        chpoints = union(chpoints, changepoint(xout(:,num_var)));
    end
    trace.chpoints = chpoints;
    trace.x = xout(:,1:num_var);
    trace.labels_num = []; 
    trace.labels_trace = []; 
       
end

function [points_num] = changepoint(values)

  valdif1 = [values(1); diff(values)];
  valdif2 =  diff(valdif1);
  indx = find(abs(valdif2) >=0.05);
  points_num = union(1,[indx; length(values)]);
end