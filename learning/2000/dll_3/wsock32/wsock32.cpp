// wsock32.cpp : Defines the entry point for the DLL application.
//

#include "stdafx.h"

#include <stdio.h>
#include <string.h>

#include "wsock32.h"

BOOL inited = FALSE;

// log funcs
	char logfile[1024] = "c:\\wsock32.log";
	char buf[1000];
	void slog(char *s, LONG length = -1) {
		/*
		HANDLE f;
		f = CreateFile(logfile,
			GENERIC_WRITE,
			FILE_SHARE_WRITE,
			NULL,
			OPEN_ALWAYS,
			FILE_ATTRIBUTE_NORMAL,
			NULL);
		if (f != INVALID_HANDLE_VALUE) {
			WriteFile(f, s, strlen(s), NULL, NULL);
			CloseHandle(f);
		}
		*/
		//return;
		FILE *f;
		f = fopen(logfile, "a");
		if (f != NULL) {
			if (length < 0) {
				fprintf(f, s);
			} else {
				fwrite(s, 1, length, f);
			}
			fclose(f);
		}
	}
	void _stdcall change_logfile(char *newname) {
		strcpy(logfile, newname);
	}

// socket <--> address:port mapping
	salist	sas;
	sapair	nullsa = { 0, };

	void delmap(SOCKET s) {
		salist::iterator i;
		for (i = sas.begin(); i != sas.end(); ++i) {
			if ((*i).s == s) {
				sas.erase(i);
				break;
			}
		}
		return;
	}
	void addmap(SOCKET s, int l1, int l2, int l3, int l4, int lp, int r1, int r2, int r3, int r4, int rp) {
		sapair a;
		delmap(s);
		a.s	= s;
		a.l1	= l1;
		a.l2	= l2;
		a.l3	= l3;
		a.l4	= l4;
		a.lp	= lp;
		a.r1	= r1;
		a.r2	= r2;
		a.r3	= r3;
		a.r4	= r4;
		a.rp	= rp;
		sas.insert(sas.end(), a);
	}
	void addmap(sapair sa) {
		addmap(sa.s, sa.l1, sa.l2, sa.l3, sa.l4, sa.lp, sa.r1, sa.r2, sa.r3, sa.r4, sa.rp);
	}

	sapair getsa(SOCKET s) {
		salist::iterator i;
		for (i = sas.begin(); i != sas.end(); ++i) {
			if ((*i).s == s) {
				return *i;
			}
		}
		return nullsa;
	}

	char *getdescl(sapair sa) {
		static char addrtemp[1000];
		sprintf(addrtemp, "%d.%d.%d.%d:%d", sa.l1, sa.l2, sa.l3, sa.l4, sa.lp);
		return addrtemp;
	}
	char *getdescr(sapair sa) {
		static char addrtemp[1000];
		sprintf(addrtemp, "%d.%d.%d.%d:%d", sa.r1, sa.r2, sa.r3, sa.r4, sa.rp);
		return addrtemp;
	}

//

BOOL APIENTRY DllMain( HANDLE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		if (!inited) {
			sas.clear();
			inited = TRUE;
		}
		break;
	}
	return TRUE;
}


SOCKET _stdcall accept_proxy(SOCKET s, sockaddr *addr, int *addrlen) {
	SOCKET ret = accept(s, addr, addrlen);
	if (ret != INVALID_SOCKET) {
		sapair sa	= getsa(s);
		if (addrlen != NULL && *addrlen > 0) {
			sa.r1	= addr->sa_data[2];
			sa.r2	= addr->sa_data[3];
			sa.r3	= addr->sa_data[4];
			sa.r4	= addr->sa_data[5];
			sa.rp	= addr->sa_data[0] * 256 + addr->sa_data[1],
			addmap(sa);
		}
		sprintf(buf, "%s accepted %s. \n", getdescl(sa), getdescr(sa));
		slog(buf);
	}
	return ret;
}

int _stdcall bind_proxy(SOCKET s, const sockaddr *name, int namelen) {
	int r;
	r = bind(s, name, namelen);
	if (r == 0) {
		sapair sa;
		addmap(s,
			name->sa_data[2],
			name->sa_data[3],
			name->sa_data[4],
			name->sa_data[5],
			name->sa_data[0] * 256 + name->sa_data[1],
			0, 0, 0, 0, 0);
		sa = getsa(s);
	}
	return r;
}

int _stdcall closesocket_proxy(SOCKET s) {
	int r = closesocket(s);
	if (r == 0) {
		sapair sa = getsa(s);
		delmap(s);
		sprintf(buf, "%s to %s was closed. \n", getdescl(sa), getdescr(sa));
		slog(buf);
	}
	return r;
}

int _stdcall connect_proxy(SOCKET s, const sockaddr *name, int namelen) {
	int r, block = TRUE;
	r = connect(s, name, namelen);
	sapair sa = getsa(s);
	sa.r1	= name->sa_data[2];
	sa.r2	= name->sa_data[3];
	sa.r3	= name->sa_data[4];
	sa.r4	= name->sa_data[5];
	sa.rp	= name->sa_data[0] * 256 + name->sa_data[1];
	if (r == SOCKET_ERROR && WSAGetLastError() == WSAEWOULDBLOCK) block = FALSE;
	sprintf(buf, "%s tries to connect %s, and %s. \n", getdescl(sa), getdescr(sa),
		r == 0 ? "succeed" : (
			block ? "block" : "failed"
			));
	slog(buf);
	if ((r == 0) || !block) {
		addmap(sa);
	}
	return r;
}

int _stdcall ioctlsocket_proxy(SOCKET s, long cmd, unsigned long *argp) {
	int r = ioctlsocket(s, cmd, argp);
	sprintf(buf, "ioctlsocket(%d, %d, %x) returns %d. \n", s, cmd, argp, r);
	slog(buf);
	return r;
}

int _stdcall listen_proxy(SOCKET s, int backlog) {
	int r = listen(s, backlog);
	if (r == 0) {
		sprintf(buf, "%s listen, backlog = %d\n", getdescl(getsa(s)), backlog);
		slog(buf);
	}
	return r;
}

int _stdcall recv_proxy(SOCKET s, char *ret, int len, int flags) {
	int bytes = recv(s, ret, len, flags);
	if (bytes != SOCKET_ERROR) {
		sprintf(buf, "%s `recv` from %s with %d bytes:\n\"", getdescl(getsa(s)), getdescr(getsa(s)), bytes);
		slog(buf);
		slog(ret, bytes);
		slog("\"\n");
	}
	return bytes;
}

int _stdcall recvfrom_proxy(SOCKET s, char *ret, int len, int flags, sockaddr *from, int *fromlen) {
	int bytes = recvfrom(s, ret, len, flags, from, fromlen);
	if (bytes != SOCKET_ERROR) {
		sapair sat;
		sat.r1	= from->sa_data[2];
		sat.r2	= from->sa_data[3];
		sat.r3	= from->sa_data[4];
		sat.r4	= from->sa_data[5];
		sat.rp	= from->sa_data[0] * 256 + from->sa_data[1],
		sprintf(buf, "%s `recvfrom` from %s with %d bytes:\n\"", getdescl(getsa(s)), getdescr(sat), bytes);
		slog(buf);
		slog(ret, bytes);
		slog("\"\n");
	}
	return bytes;
}

int _stdcall send_proxy(SOCKET s, char *dat, int len, int flags) {
	int bytes = send(s, dat, len, flags);
	sprintf(buf, "%s try `send` to %s with %d bytes:\n\"", getdescl(getsa(s)), getdescr(getsa(s)), len);
	slog(buf);
	slog(dat, len);
	sprintf(buf, "\", sent %s (%d bytes). \n",
		bytes == SOCKET_ERROR ? "failed" : "succeed",
		bytes);
	slog(buf);
	return bytes;
}

int _stdcall sendto_proxy(SOCKET s, char *dat, int len, int flags, const sockaddr *to, int tolen) {
	int bytes = sendto(s, dat, len, flags, to, tolen);
	sapair sat;
	sat.r1	= to->sa_data[2];
	sat.r2	= to->sa_data[3];
	sat.r3	= to->sa_data[4];
	sat.r4	= to->sa_data[5];
	sat.rp	= to->sa_data[0] * 256 + to->sa_data[1],
	sprintf(buf, "%s try `sendto` to %s with %d bytes:\n\"", getdescl(getsa(s)), getdescr(getsa(s)), len);
	slog(buf);
	slog(dat, len);
	sprintf(buf, "\", sent %s (%d bytes). \n",
		bytes == SOCKET_ERROR ? "failed" : "succeed",
		bytes);
	slog(buf);
	return bytes;
}

int _stdcall shutdown_proxy(SOCKET s, int how) {
	int r = shutdown(s, how);
	if (r == 0) {
		sprintf(buf, "%s connected to %s shutdowned. (how = %d)\n", getdescl(getsa(s)), getdescr(getsa(s)), how);
		delmap(s);
		slog(buf);
	}
	return r;
}
