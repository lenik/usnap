function out = precise_step(inargs)
% precise_step  defines precise level for my own bussniss.
%
% out = precise_step
%   out always return .001 for current.

    if exist('FORCE_PRECISE_STEP') == 1
        out = eval('FORCE_PRECISE_STEP');
    else
        out = .0009;
    end
