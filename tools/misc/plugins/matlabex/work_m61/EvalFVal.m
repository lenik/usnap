function out = EvalFVal(f, fx)
% EvalFVal  General Functions evaluation, not limited in built-in or symbolic functions.
%
% out = EvalFVal(function, parameters)

    if isa(f, 'sym')
        out = subs(f, 'x', fx);
    else
        out = feval(f, fx);
    end
