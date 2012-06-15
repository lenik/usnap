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
¡¢¡£¡©¡ª¡«¡­¡®¡¯¡°¡±¡²¡³¡´¡µ¡¸¡¹¡º¡»¡Á¡Â¡Æ¡È¡É¡Ê¡Ù¡Ú¡Û¡Ü¡İ¡ß¡à¡ã¡ä¡å¡ç¡ë
£¡£¤£¥£¦£§£¢£¨£©£ª£«£¬£®£¯
£º£»£¼£½£¾£¿£À£Û£Ü£İ£û£ü£ı£ş

£°£±£²£³£´£µ£¶£·£¸£¹
¢±¢²¢³¢´¢µ¢¶¢·¢¸¢¹¢º¢»¢¼¢½¢¾¢¿¢À¢Á¢Â¢Ã¢Ä
¢Å¢Æ¢Ç¢È¢É¢Ê¢Ë¢Ì¢Í¢Î¢Ï¢Ğ¢Ñ¢Ò¢Ó¢Ô¢Õ¢Ö¢×¢Ø
¢Ù¢Ú¢Û¢Ü¢İ¢Ş¢ß¢à¢á¢â
¢å¢æ¢ç¢è¢é¢ê¢ë¢ì¢í¢î
¢ñ¢ò¢ó¢ô¢õ¢ö¢÷¢ø¢ù¢ú¢û¢ü

£Á£Â£Ã£Ä£Å£Æ£Ç£È£É£Ê£Ë£Ì£Í£Î£Ï£Ğ£Ñ£Ò£Ó£Ô£Õ£Ö£×£Ø£Ù£Ú
£á£â£ã£ä£å£æ£ç£è£é£ê£ë£ì£í£î£ï£ğ£ñ£ò£ó£ô£õ£ö£÷£ø£ù£ú
*/
