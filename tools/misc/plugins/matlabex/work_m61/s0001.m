
function out = s0001(a, N, use_formula)
% s0001: sum about real, integer
%

if use_formula
    out = 0;
    for i = 0:(N - 1),
        out = out + floor(a * i);
    end
else
    out = ...
        1 / a * (floor(a * (N - 1)) - 1) * floor(a * (N - 1)) / 2 + ...
        (N - 1 / a * floor(a * (N - 1))) * floor(a * (N - 1));
end
