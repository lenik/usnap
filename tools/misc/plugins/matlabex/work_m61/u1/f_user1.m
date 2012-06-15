function out = f_user1(x)
    % user custom function 1: rectangle wave.
    %
    % out = f_user1(x)
    %

    T = 1;
    Offset = -0.2;

    fx = x + Offset;
    fx = fx - floor(fx ./ T) .* T;

    out = ...
        0.00 .* (fx < (T / 3)) + ...
        0.50 .* (fx >= (T / 3) & fx < (T * 2 / 3)) + ...
        1.00 .* (fx >= (T * 2 / 3));
