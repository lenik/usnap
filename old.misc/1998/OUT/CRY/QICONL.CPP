Byte	bitr(Byte b) {
  Byte _r;
  _r = ((b & 1) << 7) | ((b & 2) << 5) | ((b & 4) << 3) | ((b & 8) << 1) |
    ((b & 16) >> 1) | ((b & 32) >> 3) | ((b & 64) >> 5) | ((b & 128) >> 7);
  return _r;
}

void	initscr() {
  clrscr();
  TSetCharMap(0x80, 4, fontpixel[0]);
  utils.welcome();
  myicons.refresh();
}

void	copybuf() {
  int i, j;

  iconbuf.maxx = myicons.i->maxx;
  iconbuf.maxy = myicons.i->maxy;
  iconbuf.x = myicons.i->x;
  iconbuf.y = myicons.i->y;

  for (i = 0; i < myicons.i->maxx; i++) {
    for (j = 0; j < myicons.i->maxy; j++) {
      iconbuf.map[iconbuf.ring][i][j] = myicons.i->map[myicons.i->ring][i][j];
    }
  }
}

void	pastebuf() {
  int i, j;

  if (myicons.i->modify() == 0) return;

  myicons.i->x = iconbuf.x;
  myicons.i->y = iconbuf.y;
  myicons.i->maxx = iconbuf.maxx;
  myicons.i->maxy = iconbuf.maxy;

  for (i = 0; i < iconbuf.maxx; i++) {
    for (j = 0; j < iconbuf.maxy; j++) {
      myicons.i->map[myicons.i->ring][i][j] = iconbuf.map[iconbuf.ring][i][j];
    }
  }
}

//class icon
icon::icon(int _maxx, int _maxy) {
  int i, j, k;
  maxx = (_maxx < MAXX) ? _maxx : MAXX;
  maxy = (_maxy < MAXY) ? _maxy : MAXY;
  x = y = 0;
  ringactive = False;
  if (myicons.autoclear == True) {
    for (i = 0; i < MAXRING; i++) {
      ring = i;
      clear();
    }
  }
  ring = rstart = rend = 0;
  ringactive = True;
  pen = View;
  prev = next = NULL;
}

int	icon::valid() {
  return (maxx <= MAXX) && (maxy <= MAXY) && (ring < MAXRING);
}

void	icon::ringleft() {
  int ring2 = (ring + 1) % MAXRING;
  int i, j;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring2][i][j] = map[ring][i][j];
    }
  }
  if (ring == rend) {
    rend = ring2;
  }
  ring = ring2;
  if (ring == rstart) {
    rstart = (rstart + 1) % MAXRING;
  }
}

void	icon::ringright() {
  int ring2 = (ring + MAXRING - 1) % MAXRING;
  int i, j;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring2][i][j] = map[ring][i][j];
    }
  }
  if (ring == rstart) {
    rstart = ring2;
  }
  ring = ring2;
  if (ring == rend) {
    rend = (rend + MAXRING - 1) % MAXRING;
  }
}

int	icon::modify() {
  if (valid() == 0) return 0;
  if (ringactive == True) {
    ringleft();
  }
  return 1;
}

void	icon::xcopy(int x1, int x2) {
  int i;
  Byte xmap[MAXY];

  if (valid() == 0) return;
  for (i = 0; i < maxy; i++) {
    xmap[i] = map[ring][x1][i];
    map[ring][x1][i] = map[ring][x2][i];
    map[ring][x2][i] = xmap[i];
  }
}

void	icon::ycopy(int y1, int y2) {
  int i;
  Byte xmap[MAXX];

  if (valid() == 0) return;
  for (i = 0; i < maxx; i++) {
    xmap[i] = map[ring][i][y1];
    map[ring][i][y1] = map[ring][i][y2];
    map[ring][i][y2] = xmap[i];
  }
}

int	icon::getp(int _x, int _y) {
  return (map[ring][_x / 8][_y] & (0x80 >> (_x % 8))) != 0;
}

int	icon::setp(int _x, int _y, int _b) {
  if (valid() == 0) return 0;
  if (_x / 8 > maxx) return 1;
  if (_b == 1) {
    map[ring][_x / 8][_y] |= 0x80 >> (_x % 8);
  } else {
    map[ring][_x / 8][_y] &= ~(0x80 >> (_x % 8));
  }
  return 0;
}

int	icon::noring() {
  if (rstart == rend) {
    return True;
  }
  return False;
}

void	icon::clear() {
  int i, j;

  if (modify() == 0) return;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] = 0;
    }
  }
}

void	icon::full() {
  int i, j;

  if (modify() == 0) return;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] = ~0;
    }
  }
}

void	icon::noise() {
  int i, j;

  if (modify() == 0) return;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] |= random(0x100) & random(0x100) & random(0x100);
    }
  }
}

void	icon::invert() {
  int i, j;

  if (modify() == 0) return;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy; j++) {
      map[ring][i][j] = ~map[ring][i][j];
    }
  }
}

void	icon::left(int n) {
  int i, j, l, lc;
  Byte k1, k2, m;
  Byte xmap[MAXX][MAXY];

  if (modify() == 0) return;
  n %= maxx * 8;
  l = n / 8;
  lc = 8 - n % 8;
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < l; j++) {
      xmap[j][i] = map[ring][j][i];
    }
  }
  for (i = l; i < maxx; i++) {
    xcopy(i, i - l);
  }
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < l; j++) {
      map[ring][maxx - l + j][i] = xmap[j][i];
    }
  }

  m = 0xFF << lc;
  for (i = 0; i < maxy; i++) {
    k2 = (map[ring][0][i] & m) >> lc;
    for (j = maxx - 1; j >= 0; j--) {
      k1 = (map[ring][j][i] & m) >> lc;
      map[ring][j][i] <<= n % 8;
      map[ring][j][i] |= k2;
      k2 = k1;
    }
  }
}

void	icon::right(int n) {
  int i, j, l, lc;
  Byte k1, k2, m;
  Byte xmap[MAXX][MAXY];

  if (modify() == 0) return;
  n %= maxx * 8;
  l = n / 8;
  lc = 8 - n % 8;
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < l; j++) {
      xmap[j][i] = map[ring][maxx - l + j][i];
    }
  }
  for (i = maxx - l - 1; i >= 0; i--) {
    xcopy(i, i + l);
  }
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < l; j++) {
      map[ring][j][i] = xmap[j][i];
    }
  }

  m = 0xFF >> lc;
  for (i = 0; i < maxy; i++) {
    k2 = (map[ring][maxx - 1][i] & m) << lc;
    for (j = 0; j < maxx; j++) {
      k1 = (map[ring][j][i] & m) << lc;
      map[ring][j][i] >>= n % 8;
      map[ring][j][i] |= k2;
      k2 = k1;
    }
  }
}

void	icon::up(int n) {
  int i, j;
  Byte xmap[MAXX][MAXY];

  if (modify() == 0) return;
  n %= maxy;
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      xmap[j][i] = map[ring][j][i];
    }
  }
  for (i = n; i < maxy; i++) {
    ycopy(i, i - n);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      map[ring][j][maxy - n + i] = xmap[j][i];
    }
  }
}

void	icon::down(int n) {
  int i, j;
  Byte xmap[MAXX][MAXY];

  if (modify() == 0) return;
  n %= maxy;
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      xmap[j][i] = map[ring][j][maxy - n + i];
    }
  }
  for (i = maxy - n - 1; i >= 0; i--) {
    ycopy(i, i + n);
  }
  for (i = 0; i < n; i++) {
    for (j = 0; j < maxx; j++) {
      map[ring][j][i] = xmap[j][i];
    }
  }
}

void	icon::cutleft(int n) {
  int i, j, l, lc1;
  Byte k1, k2, m1;
  Byte xmap[MAXX][MAXY];

  if (modify() == 0) return;
  n %= x + 1;
  l = n / 8;		// block override (shift / 8)
  lc1 = 8 - n % 8;	// how many bits shift for mask
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < l; j++) {
      xmap[j][i] = map[ring][j][i];
    }
  }
  for (i = l; i <= x / 8; i++) {
    xcopy(i, i - l);
  }
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < l; j++) {
      map[ring][x / 8 - l + j][i] = xmap[j][i];
    }
  }

  m1 = 0xFF << lc1;
  for (i = 0; i < maxy; i++) {
    k2 = (map[ring][0][i] & m1) >> lc1;
    for (j = x / 8; j >= 0; j--) {
      k1 = (map[ring][j][i] & m1) >> lc1;
      map[ring][j][i] <<= n % 8;
      map[ring][j][i] |= k2;
      k2 = k1;
    }
  }
}

void	icon::cutright(int n) {
}
void	icon::cutup(int n) {
}
void	icon::cutdown(int n) {
}

void	icon::invertx() {
  int i, j, x;

  if (modify() == 0) return;
  for (i = 0; i < maxy; i++) {
    for (j = 0; j < maxx / 2; j++) {
      x = bitr(map[ring][j][i]);
      map[ring][j][i] = bitr(map[ring][maxx - j][i]);
      map[ring][maxx - j][i] = x;
    }
    if (maxx % 2 == 1) {
      map[ring][maxx / 2][i] = bitr(map[ring][maxx / 2][i]);
    }
  }
}

void	icon::inverty() {
  int i, j, x;

  if (modify() == 0) return;
  for (i = 0; i < maxx; i++) {
    for (j = 0; j < maxy / 2; j++) {
      x = map[ring][i][j];
      map[ring][i][j] = map[ring][i][maxy - j - 1];
      map[ring][i][maxy - j - 1] = x;
    }
  }
}

void	icon::scalex(int _xp) {
}
void	icon::scaley(int _yp) {
}
void	icon::rotate(int an) {
}
void	icon::slipleft(int s) {
}
void	icon::slipright(int s) {
}
void	icon::slipup(int s) {
}
void	icon::slipdown(int s) {
}
void	icon::outline() {
  int i;

  if (modify() == 0) return;
  for (i = 0; i < maxx; i++) {
    switch (pen) {
      case Draw:
	map[ring][i][0] = map[ring][i][maxy - 1] = ~0;
	break;
      case Erase:
	map[ring][i][0] = map[ring][i][maxy - 1] = 0;
	break;
      case View:
      case Invert:
	map[ring][i][0] = ~map[ring][i][0];
	map[ring][i][maxy - 1] = ~map[ring][i][maxy - 1];
	break;
    }
  }
  for (i = 0; i < maxy; i++) {
    switch (pen) {
      case Draw:
	setp(0, i, 1);
	setp(maxx * 8 - 1, i, 1);
	break;
      case Erase:
	setp(0, i, 0);
	setp(maxx * 8 - 1, i, 0);
	break;
      case View:
      case Invert:
	if ((i != 0) && (i != maxy - 1)) {
	  setp(0, i, 1 - getp(0, i));
	  setp(maxx * 8 - 1, i, 1 - getp(maxx * 8 - 1, i));
	}
	break;
    }
  }
}

void	line(int x1, int y1, int x2, int y2) {
}
void	rect(int x1, int y1, int x2, int y2) {
}
void	box(int x1, int y1, int x2, int y2) {
}
void	circle(int cx, int cy, int r) {
}
void	ellipse(int x1, int y1, int x2, int y2) {
}

void	icon::fill() {
  if (modify() == 0) return;
  iconfill.clear();
  fillxy(x, y, getp(x, y));
}

void	icon::fillxy(int x, int y, int v) {
  if ((x < 0) || (x >= maxx * 8) || (y < 0) || (y >= maxy)) {
    return;
  }
  iconfill.setp(x, y, 1);
  setp(x, y, v);
  if (iconfill.getp(x - 1, y) == 0) {
    if (getp(x - 1, y) != v) {
      fillxy(x - 1, y, v);
    }
  }
  if (iconfill.getp(x + 1, y) == 0) {
    if (getp(x + 1, y) != v) {
      fillxy(x + 1, y, v);
    }
  }
  if (iconfill.getp(x, y - 1) == 0) {
    if (getp(x, y - 1) != v) {
      fillxy(x, y - 1, v);
    }
  }
  if (iconfill.getp(x, y + 1) == 0) {
    if (getp(x, y + 1) != v) {
      fillxy(x, y + 1, v);
    }
  }
}

int	icon::undo() {
  if (ring == rstart) {
    return 1;
  }
  ring = (ring + MAXRING - 1) % MAXRING;
  return 0;
}

int	icon::redo() {
  if (ring == rend) {
    return 1;
  }
  ring = (ring + 1) % MAXRING;
  return 0;
}

// class icons
icons::icons() {
  i = NULL;
  curpage = totalpages = 0;
  defmaxx = DEFMAXX;
  defmaxy = DEFMAXY;
  statusbar = True;
  changed = False;
  autoclear = True;
}

int	icons::count() {
  int c = 1;
  if (i == NULL) return 0;
  _i = i;
  top();
  while (i->next != NULL) {
    i = i->next;
    c++;
  }
  i = _i;
  return c;
}

int	icons::prev() {
  if ((i != NULL) && (i->prev != NULL)) {
    i = i->prev;
    curpage--;
    return 0;
  } else {
    return 1;
  }
}

int	icons::next() {
  if ((i != NULL) && (i->next != NULL)) {
    i = i->next;
    curpage++;
    return 0;
  } else {
    return 1;
  }
}

void	icons::top() {
  if (i == NULL) return;
  while (i->prev != NULL) i = i->prev;
  curpage = 1;
}

void	icons::bottom() {
  if (i == NULL) return;
  while (i->next != NULL) i = i->next;
  curpage = totalpages;
}

int	icons::add(int _maxx = myicons.defmaxx, int _maxy = myicons.defmaxy) {
  icon *ni;
  int opage = curpage;
  if (i == NULL) {
    if ((i = new icon(_maxx, _maxy)) == NULL) {
      return 1;
    } else {
      curpage = totalpages = 1;
      return 0;
    }
  }
  if ((ni = new icon(_maxx, _maxy)) == NULL) {
    return 1;
  }
  totalpages++;
  _i = i;
  bottom();
  i->next = ni;
  ni->prev = i;
  i = _i;
  curpage = opage;
  return 0;
}

int	icons::ins(int _maxx = myicons.defmaxx, int _maxy = myicons.defmaxy) {
  icon *ni;
  if (i == NULL) {
    if ((i = new icon(_maxx, _maxy)) == NULL) {
      return 1;
    } else {
      curpage = totalpages = 1;
      return 0;
    }
  }
  if ((ni = new icon(_maxx, _maxy)) == NULL) {
    return 1;
  }
  totalpages++;
  curpage++;
  if (i->prev != NULL) {
    i->prev->next = ni;
  }
  ni->prev = i->prev;
  i->prev = ni;
  ni->next = i;
  return 0;
}

int     icons::del() {
  if (i == NULL) {
    return 1;
  }

  if (i->next != NULL) {
    _i = i->next;
  } else {
    _i = i->prev;
    curpage--;
  }
  if (i->prev != NULL) {
    i->prev->next = i->next;
  }
  if (i->next != NULL) {
    i->next->prev = i->prev;
  }
  delete i;
  totalpages--;
  i = _i;
  return 0;
}

int	icons::clear() {
  if (i == NULL) {
    return 1;
  }
  top();
  if (i->next != NULL) {
    i = i->next;
  }
  while (i->prev != NULL) {
    delete i->prev;
    i->prev = NULL;
    if (i->next != NULL) {
      i = i->next;
    }
  }
  delete i;
  i = NULL;
  curpage = totalpages = 0;
  return 0;
}

int	icons::incw(int _w) {
  int j, k;

  if ((i->maxx + _w > MAXX) || (i->maxx + _w <= 0)) {
    return 1;
  }
  i->maxx += _w;
  if (autoclear == True) {
    for (j = 0; j < i->maxy; j++) {
      for (k = i->maxx - _w; k < i->maxx; k++) {
	i->map[i->ring][k][j] = 0;
      }
    }
  }
  if (i->x >= i->maxx) {
    i->x = i->maxx - 1;
  }
  return 0;
}

int	icons::inch(int _h) {
  int j, k;

  if ((i->maxy + _h > MAXY) || (i->maxy + _h <= 0)) {
    return 1;
  }
  i->maxy += _h;
  if (autoclear == True) {
    for (j = 0; j < i->maxx; j++) {
      for (k = i->maxy - _h; k < i->maxy; k++) {
	i->map[i->ring][j][k] = 0;
      }
    }
  }
  if (i->y >= i->maxy) {
    i->y = i->maxy - 1;
  }
  return 0;
}

void	icons::curop() {
  switch (i->pen) {
    case View:
      break;
    case Draw:
      if (i->modify() == 0) return;
      i->setp(i->x, i->y, 1);
      break;
    case Erase:
      if (i->modify() == 0) return;
      i->setp(i->x, i->y, 0);
      break;
    case Invert:
      if (i->modify() == 0) return;
      i->setp(i->x, i->y, 1 - i->getp(i->x, i->y));
      break;
  }
}

void	icons::curinvert() {
  if (i->modify() == 0) return;
  i->setp(i->x, i->y, 1 - i->getp(i->x, i->y));
}

void	icons::curhome() {
  int j;
  switch (i->pen) {
    case View:
      break;
    case Draw:
      if (i->modify() == 0) return;
      for (j = 0; j < i->x; j++) {
	i->setp(j, i->y, 1);
      }
      break;
    case Erase:
      if (i->modify() == 0) return;
      for (j = 0; j < i->x; j++) {
	i->setp(j, i->y, 0);
      }
      break;
    case Invert:
      if (i->modify() == 0) return;
      for (j = 0; j < i->x; j++) {
	i->setp(j, i->y, 1 - i->getp(j, i->y));
      }
      break;
  }
  i->x = 0;
}

void	icons::curend() {
  int j;
  switch (i->pen) {
    case View:
      break;
    case Draw:
      if (i->modify() == 0) return;
      for (j = i->x + 1; j < i->maxx * 8; j++) {
	i->setp(j, i->y, 1);
      }
      break;
    case Erase:
      if (i->modify() == 0) return;
      for (j = i->x + 1; j < i->maxx * 8; j++) {
	i->setp(j, i->y, 0);
      }
      break;
    case Invert:
      if (i->modify() == 0) return;
      for (j = i->x + 1; j < i->maxx * 8; j++) {
	i->setp(j, i->y, 1 - i->getp(j, i->y));
      }
      break;
  }
  i->x = i->maxx * 8 - 1;
}

void	icons::curmostup() {
  int j;
  switch (i->pen) {
    case View:
      break;
    case Draw:
      if (i->modify() == 0) return;
      for (j = 0; j < i->y; j++) {
	i->setp(i->x, j, 1);
      }
      break;
    case Erase:
      if (i->modify() == 0) return;
      for (j = 0; j < i->y; j++) {
	i->setp(i->x, j, 0);
      }
      break;
    case Invert:
      if (i->modify() == 0) return;
      for (j = 0; j < i->y; j++) {
	i->setp(i->x, j, 1 - i->getp(i->x, j));
      }
      break;
  }
  i->y = 0;
}

void	icons::curmostdown() {
  int j;
  switch (i->pen) {
    case View:
      break;
    case Draw:
      if (i->modify() == 0) return;
      for (j = i->y + 1; j < i->maxy; j++) {
	i->setp(i->x, j, 1);
      }
      break;
    case Erase:
      if (i->modify() == 0) return;
      for (j = i->y + 1; j < i->maxy; j++) {
	i->setp(i->x, j, 0);
      }
      break;
    case Invert:
      if (i->modify() == 0) return;
      for (j = i->y + 1; j < i->maxy; j++) {
	i->setp(i->x, j, 1 - i->getp(i->x, j));
      }
      break;
  }
  i->y = i->maxy - 1;
}

void    icons::curleft() {
  if (i->x > 0) i->x--;
  curop();
}

void	icons::curright() {
  if (i->x < i->maxx * 8 - 1) i->x++;
  curop();
}

void	icons::curup() {
  if (i->y > 0) i->y--;
  curop();
}

void 	icons::curdown() {
  if (i->y < i->maxy - 1) i->y++;
  curop();
}

void	icons::refresh() {
  int j, k, xs, ys;
  char *pens[4] = {"View", "Draw", "Erase", "Invert"};

  i->valid();

  if (statusbar == True) {
    gotoxy(1, 1);
    left = coreleft();
    printf("PAGE[%d/%d] POS[%d:%d] SIZE[%d:%d] MEM[%lu] [%-6s]	Press <F1> For Help",
      curpage, totalpages, i->x, i->y, i->maxx * 8, i->maxy, left, pens[i->pen]);
  }

  xs = (80 - i->maxx * 8) / 2;
  ys = (25 - i->maxy) / 2 + 1;

  for (j = 0; j < i->maxy; j++) {
    for (k = 0; k< i->maxx * 8; k++) {
      gotoxy(xs + k, ys + j);
      putch(0x80 | i->getp(k, j));
    }
  }

  gotoxy(xs + i->x, ys + i->y);
  k = i->getp(i->x, i->y);
  putch(0x82 | k);
}

// struct iconfile
iconfile::iconfile() {
  *filename = '\0';
  brace = True;
  comments = True;
  newline = False;
  dir = Vert;
  nf = Dec;
  strcpy(sep, ", ");
}

long    iconfile::getnum(FILE *file) {
  char c, buf[200];
  enum Boolean ishex;
  int p = 1;

  while ((c = fgetc(file)) != EOF) {
    if (isdigit(c) != 0) {
      break;
    }
  }
  buf[0] = c;
  ishex = False;
  while ((c = fgetc(file)) != EOF) {
    buf[p++] = c;
    if ((p == 2) && ((c | 0x20) == 'x')) {
      ishex = True;
      continue;
    }
    if (ishex == True) {
      if (isxdigit(c) == 0) {
	break;
      }
    } else {
      if (isdigit(c) == 0) {
	break;
      }
    }
    if (p >= 198) {
      break;
    }
  }
  buf[p] = '\x0';
  return strtol(buf, NULL, 0);
}

int	iconfile::save() {
  FILE *file;
  char *f[6] = {"%u", "%x", "%o", "%3u", "0x%02x", "0%03o"};
  icon *ori = myicons.i;
  int oricur = myicons.curpage;

  int i, j, k, c = myicons.totalpages;

  while ((file = fopen(filename, "w")) == NULL) {
    printf("error in opening file: %s\ndo you want to change filename? (y/n)", filename);
    if ((getch() | 0x20) == 'y') {
      printf("\nnew filename: ");
      scanf("%s", filename);
    } else {
      return 1;
    }
  }
  myicons.top();
  for (i = 0; i < c; i++) {
    if (comments == True) {
      fprintf(file, "/* << QICON: %d %d %d %d >> */\n", myicons.i->maxx, myicons.i->maxy, 0, dir);
    }
    if (brace == True) {
      fprintf(file, "{");
    }
    switch (dir) {
      case Horiz:
	for (j = 0; j < myicons.i->maxy; j++) {
	  if (newline == True) {
	    fprintf(file, "\n  ");
	  }
	  for (k = 0; k < myicons.i->maxx; k++) {
	    fprintf(file, f[nf], myicons.i->map[myicons.i->ring][k][j]);
	    if ((j == myicons.i->maxy - 1) && (k == myicons.i->maxx - 1)) {
	      break;
	    }
	    fprintf(file, sep);
	  }
	}
	break;
      case Vert:
	for (j = 0; j < myicons.i->maxx; j++) {
	  if (newline == True) {
	    fprintf(file, "\n");
	  }
	  for (k = 0; k < myicons.i->maxy; k++) {
	    fprintf(file, f[nf], myicons.i->map[myicons.i->ring][j][k]);
	    if ((j == myicons.i->maxx - 1) && (k == myicons.i->maxy - 1)) {
	      break;
	    }
	    fprintf(file, sep);
	  }
	}
	break;
    }
    if (newline == True) {
      fprintf(file, "\n");
    }
    if (brace == True) {
      fprintf(file, "}");
    }
    if (i != c - 1) fprintf(file, ", \n");
    myicons.next();
  }
  fprintf(file, "\n");
  fclose(file);
  myicons.i = ori;
  myicons.curpage = oricur;
  return 0;
}

int 	iconfile::load() {
  FILE *file;
  int p, a[4], i, j, k;
  char *sign = "/* << QICON", c;
  enum Boolean Found;
  long pos;

  while ((file = fopen(filename, "r")) == NULL) {
    printf("error in opening file: %s\ndo you want to change filename? (y/n)", filename);
    if ((getch() | 0x20) == 'y') {
      printf("\nnew filename: ");
      scanf("%s", filename);
    } else {
      return 1;
    }
  }

  while ((c = fgetc(file)) != EOF) {
    if (c == *sign) {
      pos = ftell(file);
      Found = True;
      for (p = 1; p < strlen(sign); p++) {
	if ((c = fgetc(file)) != EOF) {
	  if (c != sign[p]) {
	    Found = False;
	    break;
	  }
	}
      }
      if (Found != True) {
	if (fseek(file, pos + 1, SEEK_SET) != 0) {
	  break;
	}
	continue;
      }
    } else {
      continue;
    }
    for (p = 0; p < 4; p++) {
      a[p] = (int)getnum(file);
    }
    a[0] %= MAXX;
    a[1] %= MAXY;
    if (myicons.add(a[0], a[1]) == 0) {
      myicons.bottom();
      printf("\nAdd icon: %dx%d\n", a[0], a[1]);
      switch (a[3]) {
	case Horiz:
	  for (i = 0; i < a[1]; i++) {
	    for (j = 0; j < a[0]; j++) {
	      k = getnum(file);
	      myicons.i->map[0][j][i] = k;
	    }
	  }
	  break;
	case Vert:
	  for (i = 0; i < a[0]; i++) {
	    for (j = 0; j < a[1]; j++) {
	      k = getnum(file);
	      myicons.i->map[0][i][j] = k;
	    }
	  }
	  break;
      }
    } else {
      printf("\nMemory out!\n");
    }
  }
  fclose(file);
  printf("\nAll data processed!\n");
  return 0;
}

// class misc
void	misc::welcome() {
  printf("\n\
										\
										\
       ²°° ²°°    ²²²²²°°   ²°°    ²²²²²°°     ²²²²°°   ²²²°° ²°°    ²²²²²°°    \
      ²Û²°²Û²°°  ²ÛÛÛÛÛ²°° ²Û²°°  ²ÛÛÛÛÛ²°°   ²ÛÛÛÛ²°° ²ÛÛÛ²°²Û²°°  ²ÛÛÛÛÛ²°°   \
     ²Û²°²°²Û²°°²Û²²²²²Û²°°²Û²°° ²Û²²²²²Û²°° ²Û²²²²Û²°° ²Û²Û²Û²Û²°°²Û²²²²²Û²°°  \
    ²Û²°²Û²°²Û²°²ÛÛÛÛÛÛ²°° ²Û²°°²Û²°°       ²Û²°°  ²Û²°°²Û²²Û²²Û²°°²ÛÛÛÛÛÛ²°°   \
     ²Û²Û²Û²Û²°°²Û²²²²²°°  ²Û²°° ²Û²²²²²Û²°° ²Û²²²²Û²°° ²Û²°²°²Û²°°²Û²²²²²°°    \
      ²Û²°²Û²°°  ²ÛÛÛÛÛ²°° ²Û²°°  ²ÛÛÛÛÛ²°°   ²ÛÛÛÛ²°°  ²Û²°° ²Û²°° ²ÛÛÛÛÛ²°°   \
       ²°° ²°°    ²²²²²°°   ²°°    ²²²²²°°     ²²²²°°    ²°°   ²°°   ²²²²²°°    \
										\
										\
	    Q U	I C K	I C O N	  S O U	R C E  	G E N E	R A T O	R		\
										\
			  V E R S I O N   1 . 0 0				\
										\
		   ÛÛÛÛÛ²°ÛÛÛÛÛ²°ÛÛÛÛÛ²°ÛÛÛÛÛ²°ÛÛÛÛÛ²°ÛÛÛÛÛ²°ÛÛÛÛÛ²°Û²°°Û²°°    \
		     Û²°° Û²°°Û²°Û²°°Û²°Û²°°   Û²°°Û²°Û²°°Û²°Û²°°Û²°Û²°Û²°°     \
		     Û²°° Û²°°Û²°ÛÛÛÛÛ²°Û²°°   ÛÛÛÛÛ²°Û²°°Û²°ÛÛÛÛÛ²°ÛÛÛ²°°      \
		     Û²°° Û²°°Û²°Û²°°   Û²°°   Û²Û²°° Û²°°Û²°Û²°°Û²°Û²°Û²°°     \
		     Û²°° ÛÛÛÛÛ²°Û²°°   ÛÛÛÛÛ²°Û²ÛÛÛ²°ÛÛÛÛÛ²°Û²°°Û²°Û²°°Û²°°    \
										\
										");
  if (getch() == 0) {
    getch();
  }
}

void    misc::help() {
  printf("\n\
ÖÄÄÄÒ H E L P ÄÒÄÄÄ Q u i c k   I c o n - * - A u t h o r   D a n S e i ÄÄÄÄÄÄÄ¿\
º F ÓÄÄÄÄÄÄÄÄÄÄ½  ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ     ³\
º I ³ F1:    Help     ED Ctrl-Z: Undo      M O D -  c: Copy                    ³\
º L ³ F2:    Save     IT Ctrl-A: Redo     - I F Y   p: Paste                   ³\
º E ³ F3:    Reload   Ú¿                                                       ³\
º ÄÄÙ F4:    New      ÀÙ File Settings:    Ctrl-F5                             ³\
º ÄÄ¿ Alt-X: Quit     Ú¿ System Settings:  Ctrl-F6                             ³\
º P ³ F5:    Add      ÀÙ Font Settings:    Ftrl-F7                             ³\
º A ³ <Insert>        Ú¿                                                       ³\
º G ³ <Delete>        ÀÙ Inc/Dec Width:    =-                                  ³\
º E ³ Prev:  PgUp     Ú¿ Inc/Dec Height:   +_                                  ³\
º S ³ Next:  PgDn     ÀÙ                                                       ³\
º ÄÄÙ                 Ú¿ Redraw:           r    Ú X ¿                          ³\
º ÄÄ D Ä R Ä A Ä W ÄÄÄÙÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ³ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ ³\
º Move Cursor: Arrow keys    Action on cursor moved:                           ³\
º Scroll on:   Scroll Icon     Nothing: v  Erase:  e                           ³\
º Scroll Part: Shift-Arrow*    Draw:    d  Invert: i                           ³\
º Clear: Alt-C    o: Outline                                                   ³\
º Full:  Alt-F    x: Invert X                                                  ³\
º Noise: Alt-N    y: Invert Y                                                  ³\
º Fill:  <BS>*                                                                 ³\
º                                                                              ³\
ÓÄpÄrÄeÄsÄsÄÄÄaÄnÄyÄÄÄkÄeÄyÄÄÄtÄoÄÄÄcÄoÄnÄtÄiÄnÄuÄeÄ.Ä.Ä.Ä.Ä.Ä.ÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
  if (getch() == 0) getch();
}

void	misc::fileset() {
  int i;
  char *yesno[2] = {"No", "Yes"};
  char *nfn[3] = {"Dec", "Hex", "Oct"};

  while (1) {
    printf("\n\
ÖÄÄÄÒ F I L E ÄÒÄÄÄ Q u i c k   I c o n - * - A u t h o r   D a n S e i ÄÄÄÄÄÄÄ¿\
º   ÓÄÄÄÄÄÄÄÄÄÄ½                                                               ³\
º f    Filename:        %-40s               ³\
º Bb   Generate brace:  %-3s        Rr   Comments for reloadable:     %-3s       ³\
º xy   Pixel direction: %-5s      Nn   Newline for scanner returns: %-3s       ³\
ºÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ³\
º dho  Numeric format:  %-3s                                                    ³\
º DHO  Equal width:     %-3s                                                    ³\
ÓÄÂÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ\
Ö½À s  Separate string: \"%s\"\n\
ÓÄpÄrÄeÄsÄsÄÄ E S C ÄÄkÄeÄyÄÄÄtÄoÄÄÄrÄeÄtÄuÄrÄnÄÄÄÄÄÄÄÄÄÄ\n",
      myfile.filename,
      yesno[myfile.brace == True], yesno[myfile.comments == True],
      (myfile.dir == Horiz) ? "Horiz" : "Vert", yesno[myfile.newline],
      nfn[myfile.nf % 3],
      yesno[myfile.nf > Oct],
      myfile.sep);
    if ((i = getch()) == 0x1B) {
      break;
    }
    switch (i) {
      case 0:
	getch(); break;
      case 'f':
	printf("\nInput filename: ");
	scanf("%s", myfile.filename);
	break;
      case 'b':
	myfile.brace = True; break;
      case 'B':
	myfile.brace = False; break;
      case 'r':
	myfile.comments = True; break;
      case 'R':
	myfile.comments = False; break;
      case 'x':
	myfile.dir = Horiz; break;
      case 'y':
	myfile.dir = Vert; break;
      case 'n':
	myfile.newline = True; break;
      case 'N':
	myfile.newline = False; break;
      case 'd':
	myfile.nf = Dec; break;
      case 'D':
	myfile.nf = WDec; break;
      case 'h':
	myfile.nf = Hex; break;
      case 'H':
	myfile.nf = WHex; break;
      case 'o':
	myfile.nf = Oct; break;
      case 'O':
	myfile.nf = WOct; break;
      case 's':
	printf("input separate string: ");
	gets(myfile.sep);
	break;
    }
  }
}

void	misc::sysset() {
  int i;
  char *yesno[2] = {"No", "Yes"};

  while (1) {
    printf("\n\
ÖÄÄÄÒ D R A W ÄÒÄÄÄ Q u i c k   I c o n - * - A u t h o r   D a n S e i ÄÄÄÄÄÄÄ¿\
º   ÓÄÄÄÄÄÄÄÄÄÄ½                                                               ³\
º Cc   Auto clear:      %-3s                                                    ³\
º Ss   Status bar:      %-3s                                                    ³\
º w    Default width:   %3d * 8                                                ³\
º h    Default height:  %3d                                                    ³\
ÓÄpÄrÄeÄsÄsÄÄ E S C ÄÄkÄeÄyÄÄÄtÄoÄÄÄrÄeÄtÄuÄrÄnÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ",
      yesno[myicons.autoclear == True],
      yesno[myicons.statusbar == True],
      myicons.defmaxx, myicons.defmaxy);
    if ((i = getch()) == 0x1B) {
      break;
    }
    switch (i) {
      case 0:
	getch(); break;
      case 'c':
	myicons.autoclear = True; break;
      case 'C':
	myicons.autoclear = False; break;
      case 's':
	myicons.statusbar = True; break;
      case 'S':
	myicons.statusbar = False; break;
      case 'w':
	do {
	  printf("Please input default width (0 .. %d): ", MAXX);
	  scanf("%d", &myicons.defmaxx);
	} while (myicons.defmaxx > MAXX);
	break;
      case 'h':
	do {
	  printf("Please input default height (0 .. %d): ", MAXY);
	  scanf("%d", &myicons.defmaxy);
	} while (myicons.defmaxy > MAXY);
	break;
    }
  }
}
void	misc::fontset() {
  int i;
  while (1) {
    printf("\n\
ÖÄÄÄÒ F O N T ÄÒÄÄÄ Q u i c k   I c o n - * - A u t h o r   D a n S e i ÄÄÄÄÄÄÄ¿\
º   ÓÄÄÄÄÄÄÄÄÄÄ½                                                               ³\
º 012  Characters set:  ABCDEFGHIJKLMNOPQRSTUVWXYZ                             ³\
º 345  Characters set:  abcdefghijklmnopqrstuvwxyz                             ³\
º 6789 Characters set:  0123456789                                             ³\
º a-h  Pixel set:       €‚ƒ                                                   ³\
º r    Restore                                                                 ³\
ÓÄpÄrÄeÄsÄsÄÄ E S C ÄÄkÄeÄyÄÄÄtÄoÄÄÄrÄeÄtÄuÄrÄnÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
    if ((i = getch()) == 0x1B) {
      break;
    }
    switch (i) {
      case '0':
      case '1':
      case '2':
	TSetCharMap('A', 26, fontu[i - '0']); break;
      case '3':
      case '4':
      case '5':
	TSetCharMap('a', 26, fontl[i - '3']); break;
      case '6':
      case '7':
      case '8':
      case '9':
	TSetCharMap('0', 10, fontn[i - '6']); break;
      case 'a':
      case 'b':
      case 'c':
      case 'd':
      case 'e':
      case 'f':
      case 'g':
      case 'h':
	TSetCharMap(0x80, 4, fontpixel[i - 'a']); break;
      case 'r':
	TResetCharMap();
	TSetCharMap(0x80, 4, fontpixel[0]);
	break;
    }
  }
}

int	misc::askexit() {
  int i;
  if (myicons.changed == True) {
    printf("\nfile has changed, and has not been written, yet. \n<Q>uit   <W>rite and quit   <C>ancel\n");
    if ((i = getche()) == 0) getch();
    switch (i) {
      case 'q':
      case 'Q':
	return 0;
      case 'w':
      case 'W':
	myfile.save();
	return 0;
      default:
	return 1;
    }
  }
  return 0;
}

void	misc::exit() {
  if (askexit() == 1) {
    return;
  }
  ::exit(0);
}
