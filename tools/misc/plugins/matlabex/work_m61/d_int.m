function out = d_int(f, int_region)
% Discrete Integration
%
% out = d_int(Function_desc, Integration_region)
%   Function_desc: specify function name, for EVAL use.
%   Integration_region: for linear discrete array integration,
%       this parameter can be as syntax as [LBOUND:UBOUND]
%       for other type, it may be LBOUND:step:UBOUND

RegionSize = size(int_region);
Rows = RegionSize(1);
Columns = RegionSize(2);

for R_i = 1:Rows,
    Last_F = EvalFVal(f, int_region(R_i, 1));
    out(R_i) = 0;
    Delta_C = diff(int_region(R_i, :));
    for C_i = 2:Columns,
        out(R_i) = out(R_i) + Last_F * Delta_C(C_i - 1);
        Last_F = EvalFVal(f, int_region(R_i, C_i));
    end
end
