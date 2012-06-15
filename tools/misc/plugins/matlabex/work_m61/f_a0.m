function a0 = f_a0(func, T)
% f_a0      get fourier a0 parameter from func specfied.
% a0 = f_a0(func, T)
% get fourier a0 parameter from func specfied.

    if isa(func, 'sym')
        a0 = int(func, -T / 2, T / 2) * 2 / T;
    else
        a0 = d_int(func, -T / 2 : precise_step : T / 2) * 2 / T;
    end
