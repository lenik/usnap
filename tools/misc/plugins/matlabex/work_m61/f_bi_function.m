function out = f_bi_function(x)
    func = evalin('base', 'f_bi_func');
    i = evalin('base', 'f_bi_i');
    T = evalin('base', 'f_bi_T');
    omg = evalin('base', 'f_bi_omg');

    out = feval(func, x) * sin(i * omg * x);
