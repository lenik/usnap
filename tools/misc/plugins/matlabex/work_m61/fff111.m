
function out = fff111(inargs)
    in_1 = 100;
    in_2 = 200;

    out = in_F;


function out = in_F(inargs)
    % �����ڲ��������ܿ�һ�����Ϻ������ݣ�

    Xin_1 = evalin('caller', 'in_1');
    Xin_2 = evalin('caller', 'in_2');

    out = in_F2;

function out = in_F2(inargs)
    % �ӵ����ߴ���ȡ����ֵ��
    % Ҳ��������ں���fff111�н���������Ч���ݵ����������С�

    % �������ַ���Ҳ������ɼ������䡣
    %    lasteval = 'evalin(''caller'', ''in_1'')';
    %    out = evalin('caller', lasteval);

    out = evalin('caller', 'Xin_1') + evalin('caller', 'Xin_2');

