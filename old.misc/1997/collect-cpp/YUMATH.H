/* 选自: 给C增加高位数运算函数及应用一例
	  --- 山西省晋城风台东街19号  元晋豫
	 <<Computer Programming Skills & Maintenance 1998-3>>
*/

#define NUM_LEN		100
#define NUM_MAX_LEN	2 * NUM_LEN
#define PERR		{ printf("\nInvalid number!\n"); exit(0); }

struct dat {
  char cnum[NUM_MAX_LEN];
  int dot, end;
};

struct dat strton(char *str) {
  struct dat n;
  int j = 0, i = 0;
  char *c = str;
  while (*c != '\0') {
    if (*c == '.') j = i;
    n.cnum[i] = *c;
    i++;
    c++;
  }
  n.end = i - 1;
  if (!j) n.dot = i; else n.dot = j;
  n.cnum[i] = '\0';
  return n;
}

char *ntostr(struct dat n) {
  int i = 0;
  char res[NUM_MAX_LEN];
  while (i <= n.end) {
    res[i] = n.cnum[i++];
  }
  res[i] = '\0';
  return res;
}

void dqdot(struct dat *p1, struct dat *p2) {
  int i, j, t;
  j = p2->dot - p1->dot + p1->end;
  t = p1->end;
  i = j;
  while (t >= 0) {
    p1->cnum[i--] = p1->cnum[t--];
  }
  p1->end = j;
  p1->dot = p2->dot;
}

void dqend(struct dat *p1, struct dat *p2) {
  int i, j;
  i = p1->end + 1;
  j = p2->end;
  while (i <= j) {
    p1->cnum[i++] = 0x30;
  }
  p1->end = p2->end;
}

void delfh(struct dat *res) {
  int i, j;
  i = res->end;
  if (res->cnum[0] == '-') {
    for (j = 0; j < i; j++) {
      res->cnum[j] = res->cnum[j+1];
    }
    res->end--; res->dot--;
  }
}

void appfh(struct dat *res) {
  int i, j;
  i = res->end;
  if (i != 0 || res->cnum[0] != 0x30) {
    for (j = i; j >= 0; j--) res->cnum[j + 1] = res->cnum[j];
    res->end++; res->dot++; res->cnum[0] = '-';
  }
}

void zldat(struct dat *res) {
  int i, j, t, s;
  char ch1, ch2;
  i = res->end;
  ch1 = res->cnum[0];
  ch2 = res->cnum[i];
  if (res->cnum[0] == '-') s = 1; else s = 0;
  t = 0; j = 0; i = s;
  while (i <= res->end) {
    ch1 = res->cnum[i];
    if ((ch1 < 0x30 || ch2 > 0x39) && (ch1 != '.')) PERR;
    if (ch1 == '.') t++;
    if (i != res->dot) if (ch1 != 0x30) j = 1;
    i++;
  }
  if (t > 1) PERR;
  if (!j) {
    res->end = 0;
    res->dot = 1;
    res->cnum[0] = 0x30;
  } else {
    i = s;
    while (res->cnum[i] == 0x30) i++;
    if (res->cnum[i] == '.') i--;
    j = s;
    for (t - i; t <= res->end; t++) {
      res->cnum[j] = res->cnum[t];
      j++;
    }
    res->end -= (i - s);
    res->dot -= (i - s);
    res->cnum[res->dot] = '.';
    i = res->end;
    if (res->end > res->dot)
      while (res->cnum[i] == 0x30) i--;
    if (res->cnum[i] == '.') res->end = i - 1;
    else res->end = i;
    res->cnum[res->end + 1] = '\0';
  }
}

int db(struct dat n1, struct dat n2) {
  int i, j, t;
  char str1[NUM_MAX_LEN], str2[NUM_MAX_LEN];
  if (n1.dot > n2.dot) return (1);
  else if (n1.dot < n2.dot) return (-1);
  else {
    for (i = 0; i < n1.dot; i++) str1[i] = n1.cnum[i];
    str1[i] = '\0';
    for (i = 0; i < n2.dot; i++) str2[i] = n2.cnum[i];
    str2[i] = '\0';
    if (strcmp(str1, str2) == 0) {
      j = 0; t = 0;
      for (i = n1.dot + 1; i <= n1.end; i++) {
	str1[j] = n1.cnum[i]; j++;
      } str1[j] = '\0';
      for (i = n2.dot + 1; i <= n2.end; i++) {
	str2[t] = n2.cnum[i]; t++;
      } str2[t] = '\0';
      if (strcmp(str1, str2) == 0) return (0);
      else return (strcmp(str1, str2));
    }
    else return (strcmp(str1, str2));
  }
}

struct dat cadd(struct dat n1, struct dat n2) {
  int i, j, t, jw, dot, end;
  struct dat result;
  if (n1.dot < n2.dot) {
    dot = n2.dot; dqdot(&n1, &n2);
  } else {
    dot = n1.dot; dqdot(&n2, &n1);
  }
  if (n1.end < n2.end) {
    end = n2.end; dqend(&n1, &n2);
  } else {
    end = n1.end; dqend(&n2, &n1);
  }
  for (i = 0; i < NUM_MAX_LEN; i++) result.cnum[i] = 0x30;
  j = end; end++; i = end; jw = 0;
  while (j >= 0) {
    if (j != dot) {
      n1.cnum[j] -= 0x30;
      n2.cnum[j] -= 0x30;
      t = n1.cnum[j] + n2.cnum[j] + jw;
      if (t > 9) jw = 1; else jw = 0;
      t = t % 10;
      result.cnum[i] = (char)t + 0x30;
      i--; j--;
    } else {
      i--; j--;
    }
  }
  if (jw) {
    result.cnum[i] = 0x31; dot++;
  } else {
    i = 0;
    while (i < end) {
      result.cnum[i] = result.cnum[j + 1];
      i++;
    }
    end--;
  }
  result.dot = dot;
  result.end = end;
  result.cnum[result.dot] = '.';
  zldat(&result);
  return result;
}

struct dat csub(struct dat n1, struct dat n2) {
  struct dat result;
  int i, j, jw, dot, end, t, t1, t2;
  n1.cnum[n1.end + 1] = '\0';
  n2.cnum[n2.end + 1] = '\0';
  if (strcmp(n1.cnum, n2.cnum) == 0) {
    result.end = 0;
    result.dot = 1;
    result.cnum[0] = 0x30;
    return result;
  }
  dot = n1.dot;
  dqdot(&n2, &n1);
  if (n1.end < n2.end) {
    end = n2.end;
    dqend(&n1, &n2);
  } else {
    end = n1.end;
    dqend(&n2, &n1);
  }
  for (i = 0; i < NUM_MAX_LEN; i++) result.cnum[i] = 0x30;
  i = end;
  jw = 0;
  while (i >= 0) {
    if (i != dot) {
      n1.cnum[i] -= 0x30;
      n2.cnum[i] -= 0x30;
      t1 = (int)(n1.cnum[i]); t2 = (int)(n2.cnum[i]);
      if (t1 - jw < t2) {
	result.cnum[i] = (char)(t1 + 10 - jw - t2) + 0x30;
	jw = 1;
      } else {
	result.cnum[i] = (char)(t1 - jw - t2) + 0x30;
	jw = 0;
      }
    }
    i--;
  }
  result.end = end;
  result.dot = dot;
  result.cnum[result.dot] = '.';
  zldat(&result);
  return result;
}

char *sub(char *str1, char *str2) {
  struct dat n1, n2;
  char ch1, ch2;
  struct dat result;
  n1 = strton(str1);
  n2 = strton(str2);
  zldat(&n1);
  zldat(&n2);
  ch1 = n1.cnum[0];
  ch2 = n2.cnum[0];
  if (ch1 == '-') {
    if (ch2 == '-') {
      delfh(&n1);
      delfh(&n2);
      if (db(n1, n2) > 0) {
	result = csub(n1, n2);
	appfh(&result);
      } else result = csub(n2, n1);
    } else {
      delfh(&n1);
      delfh(&n2);
      result = cadd(n1, n2);
      appfh(&result);
    }
  } else if (ch2 == '-') {
    delfh(&n2);
    result = cadd(n1, n2);
  } else if (db(n2, n1) > 0) {
    result = csub(n2, n1);
    appfh(&result);
  } else {
    result = csub(n1, n2);
  }
  return (ntostr(result));
}

char *add(char *str1, char *str2) {
  struct dat n1, n2;
  char ch1, ch2;
  struct dat result;
  n1 = strton(str1);
  n2 = strton(str2);
  zldat(&n1);
  zldat(&n2);
  ch1 = n1.cnum[0];
  ch2 = n2.cnum[0];
  if (ch1 == '-') {
    if (ch2 == '-') {
      delfh(&n1);
      delfh(&n2);
      result = cadd(n1, n2);
      appfh(&result);
    } else {
      delfh(&n1);
      if (db(n1, n2) > 0) {
	result = csub(n1, n2);
	appfh(&result);
      } else result = csub(n2, n1);
    }
  } else if (ch2 != '-') {
    result = cadd(n1, n2);
  } else {
    delfh(&n2);
    if (db(n2, n1) > 0) {
      result = csub(n2, n1);
      appfh(&result);
    } else result = csub(n1, n2);
  }
  return ntostr(result);
}

struct dat m(char ch, struct dat n) {
  struct dat res;
  int i, j, jw;
  char cp;
  j = n.end;
  i = 0;
  ch -= 0x30;
  jw = 0;
  while (j >= 0) {
    if (j != n.dot) {
      cp = n.cnum[j] - 0x30;
      cp = cp * ch + jw;
      jw = cp / 10;
      res.cnum[i++] = cp % 10 + 0x30;
    }
    j--;
  }
  if (jw) res.cnum[i++] = jw + 0x30;
  res.end = i - 1;
  return res;
}

void mad(struct dat * b1, struct dat b2, int w) {
  int end, i, jw;
  char c1, c2;
  end = b2.end; jw = 0;
  for (i = 0; i <= end; i++) {
    c1 = b1->cnum[w] - 0x30; c2 = b2.cnum[i] - 0x30;
    c1 = c1 + c2 + jw;
    jw = c1 / 10;
    b1->cnum[w] = c1 % 10 + 0x30;
    w++;
  }
  if (jw) b1->cnum[w] = 0x30 + (char)jw;
  b1->end = w;
}

struct dat cmul(struct dat n1, struct dat n2) {
  struct dat b1, b2;
  int i, j, dot, w;
  if ((i = n1.end - n1.dot) < 0) i = 0;
  if ((j = n2.end - n2.dot) < 0) j = 0;
  dot = i + j;
  i = n2.end;
  for (j = 0; j < NUM_MAX_LEN; j++) b1.cnum[j] = 0x30;
  for (j = 0; j < NUM_MAX_LEN; j++) b2.cnum[j] =  0x30;
  w = 0;
  while (i >= 0) {
    if (i != n2.dot) {
      b2 = m(n2.cnum[i], n1);
      mad(&b1, b2, w);
      for (j = 0; j < NUM_MAX_LEN; j++) {
	b2.cnum[j] = 0x30;
      }
      w++;
    }
    i--;
  }
  i = b1.end; j = 0;
  while (i >= 0) {
    b2.cnum[j] = b1.cnum[i]; j++; i--;
  }
  b2.dot = b1.end - dot + 1;
  j = b1.end;
  if (dot) j = b1.end + 1;
  b2.end = j;
  while (dot > 0) {
    b2.cnum[j] = b2.cnum[j - 1];
    j--; dot--;
  }
  b2.cnum[b2.dot] = '.';
  zldat(&b2);
  return(b2);
}

char *mul(char *str1, char *str2) {
  struct dat n1, n2;
  int i, j;
  struct dat result;
  n1 = strton(str1);
  n2 = strton(str2);
  zldat(&n1);
  zldat(&n2);
  if (n1.cnum[0] == '-')
    i = -1;
  else
    i = 1;
  if (n2.cnum[0] == '-')
    j = -1;
  else
    j = 1;
  i = i * j;
  delfh(&n1);
  delfh(&n2);
  result = cmul(n1, n2);
  if (i == -1)
    appfh(&result);
  return ntostr(result);
}

void adjust(struct dat *n, int ds) {
  int i, t;
  if (ds > 0) {
    t = 0; i = n->dot;
    if (n->end > n->dot) {
      while(i < n->end) {
	n->cnum[i] = n->cnum[i + 1];
	i++;
	t++;
      }
    }
    while ( t < ds) {
      n->cnum[i] = 0x30;
      i++;
      t++;
    }
    n->end = i - 1;
  }
  n->cnum[n->end + 1] = '\0';
  n->dot = n->end + 1;
}

int cmp(char *s1, char *s2) {
  char *p;
  int i = 0;
  p = s1;
  while (*p != '\0') {
    if (*p != 0x30) i = 1;
    p++;
  }
  if (!i) return -1;
  else {
    if (strlen(s1) > strlen(s2)) return 1;
    else if (strlen(s1) < strlen(s2)) return -1;
    else return strcmp(s1, s2);
  }
}

char locate(struct dat *buf, struct dat n) {
  char min, max;
  struct dat tmp, mc, tmp1;
  int finish, i;
  mc.end = 0;
  mc.dot = 1;
  buf->cnum[buf->end + 1] = '\0';
  min = 0x10;
  max = 0x0A;
  finish = 0;
  while (!finish) {
    mc.cnum[0] = (min + max) / 2 + 0x30;
    tmp = cmul(mc, n);
    tmp.cnum[tmp.end + 1] = '\0';
    if (cmp(buf->cnum, tmp.cnum) < 0) max = mc.cnum[0] - 0x30;
    if (cmp(buf->cnum, tmp.cnum) == 0) {
      buf->cnum[0] = 0x30;
      buf->end = 0;
      buf->dot = 1;
      buf->cnum[1] = '\0';
      finish = 1;
    }
    if (cmp(buf->cnum, tmp.cnum) > 0) {
      tmp1 = csub(*buf, tmp);
      tmp1.cnum[tmp1.end + 1] = '\0';
      if (cmp(tmp1.cnum, n.cnum) >= 0) min = mc.cnum[0] - 0x30;
      else {
	finish = 1;
	for (i = 0; i <= tmp1.end; i++) buf->cnum[i] = tmp1.cnum[i];
	buf->end = tmp1.end;
	buf->cnum[i] = '\0';
	buf->dot = tmp1.dot;
      }
    }
  }
  return mc.cnum[0];
}

struct dat cdiv(struct dat n1, struct dat n2) {
  struct dat result, buf;
  int i, j, ds1, ds2, ws, st, t,dt;
  char ch;
  j = 0;
  for (i = 0; i <= n2.end; i++)
    if (n2.cnum[i] != 0x30) j = 1;
  if (!j) {
    printf("\nDivide error!\n"); exit(0);
  }
  j = 0;
  for (i = 0; i<= n1.end; i++) if (n1.cnum[i] != 0x30) j = 1;
  if (!j) {
    result.cnum[0] = 0x30;
    result.end = 0;
    result.dot = 1;
    return result;
  }
  ds1 = n1.end - n1.dot;
  ds2 = n2.end - n2.dot;
  st = (n1.end + n2.end) / 2 + 1;
  dt = n1.end - n2.end;
  dt = (dt > 0) ? dt : (-dt);
  ws = (st > dt) ? st : dt;
  if (ds1 > ds2) {
    adjust(&n1, ds1);
    adjust(&n2, ds1);
  } else {
    adjust(&n1, ds2);
    adjust(&n2, ds2);
  }
  n1.cnum[n1.end + 1] = '\0';
  n2.cnum[n2.end + 1] = '\0';
  ds1 = i = t = 0;
  if (n1.end < n2.end) {
    result.cnum[i] = 0x30;
    i++;
    result.cnum[i] = '.';
    i++; dt = 1; t = 1;
    for (j = n1.end + 1; j <= n2.end; j++) {
      result.cnum[i] = 0x30; i++;
      n1.cnum[j] = 0x30;
      ds1++;
    }
    i--;
    ds1--;
  }
  if (ds1 > ws) {
    result.end = 0;
    result.dot = 1;
    zldat(&result);
    return(result);
  }
  for (j = 0; j <= n2.end; j++) buf.cnum[j] = n1.cnum[j];
  buf.end = n2.end; buf.dot = j;
  buf.cnum[j] = '\0';
  st = j;
  j--;
  ds2 = 1;
  while (ds1 < ws) {
    while (cmp(buf.cnum, n2.cnum) < 0) {
      if (ds2) {
	result.cnum[i] = 0x30;
	i++;
	if (t) ds1++;
	if (ds1 > ws) {
	  result.end = i - 1;
	  result.dot = dt;
	  result.cnum[dt] = '.';
	  zldat(&result);
	  return result;
	}
	ds2 = 0;
      }
      if (j == n1.end) {
	dt = i;
	t = 1;
	j++;
	i++;
      }
      if (j > n1.end) {
	ds2 = 1;
	j++;
	buf.end++;
	buf.dot++;
	buf.cnum[st] = 0x30;
	st++;
	buf.cnum[st] = '\0';
      } else {
	j++;
	ds2 = 1;
	if (buf.cnum[0] == 0x30) st--;
	else {
	  buf.end++;
	  buf.dot++;
	}
	buf.cnum[st] = n1.cnum[j];
	st++;
	buf.cnum[st] = '\0';
      }
    }
    ch = locate(&buf, n2);
    st = buf.end;
    st++;
    result.cnum[i] = ch;
    i++;
    if (t) ds1++;
    ds2 = 0;
  }
  result.end = i - 1;
  result.dot = dt;
  result.cnum[dt] = '.';
  zldat(&result);
  return result;
}

char *div(char *str1, char *str2) {
  struct dat n1, n2;
  int i, j;
  struct dat result;
  n1 = strton(str1);
  n2 = strton(str2);
  zldat(&n1);
  zldat(&n2);
  if (n1.cnum[0] == '-') i = -1; else i = 1;
  if (n2.cnum[0] == '-') j = -1; else j = 1;
  i *= j;
  delfh(&n1);
  delfh(&n2);
  result = cdiv(n1, n2);
  if (i == -1) appfh(&result);
  return ntostr(result);
}
