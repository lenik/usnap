
function out = fff111(inargs)
    in_1 = 100;
    in_2 = 200;

    out = in_F;


function out = in_F(inargs)
    % 函数内部变量不能跨一个以上函数传递！

    Xin_1 = evalin('caller', 'in_1');
    Xin_2 = evalin('caller', 'in_2');

    out = in_F2;

function out = in_F2(inargs)
    % 从调用者处获取变量值。
    % 也就是如何在函数fff111中将变量的有效传递到其它汉书中。

    % 下面这种方法也不能完成级连传输。
    %    lasteval = 'evalin(''caller'', ''in_1'')';
    %    out = evalin('caller', lasteval);

    out = evalin('caller', 'Xin_1') + evalin('caller', 'Xin_2');

