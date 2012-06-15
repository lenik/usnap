function out = f_bi(func, i, T)
% f_bi      get fourier b[i] parameter from func specfied.

    omg = 2 * pi / T;

    if isa(func, 'sym')
        x = sym('x');
        out = int(func * sin(i * omg * x), -T / 2, T / 2) * 2 / T;
    else
        assignin('base', 'f_bi_func', func);
        assignin('base', 'f_bi_i', i);
        assignin('base', 'f_bi_T', T);
        assignin('base', 'f_bi_omg', omg);

        out = d_int('f_bi_function', -T / 2 : precise_step : T / 2) * 2 / T;
    end
