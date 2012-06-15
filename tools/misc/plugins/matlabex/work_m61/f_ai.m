function out = f_ai(func, i, T)
% f_ai      get fourier a[i] parameter from func specfied.

    omg = 2 * pi / T;

    if isa(func, 'sym')
        x = sym('x');
        out = int(func * cos(i * omg * x), -T / 2, T / 2) * 2 / T;
    else
        assignin('base', 'f_ai_func', func);
        assignin('base', 'f_ai_i', i);
        assignin('base', 'f_ai_T', T);
        assignin('base', 'f_ai_omg', omg);

        out = d_int('f_ai_function', -T / 2 : precise_step : T / 2) * 2 / T;
    end
