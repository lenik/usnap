function out = f_ai_function(x)
    func = evalin('base', 'f_ai_func');
    i = evalin('base', 'f_ai_i');
    T = evalin('base', 'f_ai_T');
    omg = evalin('base', 'f_ai_omg');

    out = feval(func, x) * cos(i * omg * x);
