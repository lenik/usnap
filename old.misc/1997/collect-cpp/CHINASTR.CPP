// Chinese String

/* Special Chinese Trans To English: ***********************
 Chinese	English
 Num

 * Special Chinese Trans To English ***********************/

#include "TString.cpp"

char HaveChinese(char *str){
  while (*str++){
    if((Byte)*str>=0xa1) return 1;
  }return 0;
}

char PureChinese(char *str){
  while (str++[0]){
    if((Byte)*str<=0xa0) return 0;
  }return 1;
}

TRetNum StrFindChinese(char *str){
  _TRetNum.r=0;
  _TRetNum.s=1;
  while ((Byte)str[_TRetNum.r]<=0xa0){
    if (!str[_TRetNum.r]){
      _TRetNum.s=0;
      return _TRetNum;
    } _TRetNum.r++;
  }
  return _TRetNum;
}

/*
���������������������������������������¡ơȡɡʡ١ڡۡܡݡߡ������
��������������������������
���������������ۣܣݣ�������

��������������������
�����������������������������������¢â�
�ŢƢǢȢɢʢˢ̢͢΢ϢТѢҢӢԢբ֢ע�
�٢ڢۢܢݢޢߢ���
������������
���������������������

���£ãģţƣǣȣɣʣˣ̣ͣΣϣУѣңӣԣգ֣ףأ٣�
����������������������������������
*/
