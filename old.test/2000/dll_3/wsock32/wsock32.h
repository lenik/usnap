
#pragma once

typedef unsigned int SOCKET;
#define INVALID_SOCKET  (SOCKET)(~0)
#define SOCKET_ERROR            (-1)

#define WSABASEERR              10000
#define WSAEINTR                (WSABASEERR+4)
#define WSAEBADF                (WSABASEERR+9)
#define WSAEACCES               (WSABASEERR+13)
#define WSAEFAULT               (WSABASEERR+14)
#define WSAEINVAL               (WSABASEERR+22)
#define WSAEMFILE               (WSABASEERR+24)
#define WSAEWOULDBLOCK          (WSABASEERR+35)
#define WSAEINPROGRESS          (WSABASEERR+36)
#define WSAEALREADY             (WSABASEERR+37)

typedef struct {
	WORD sa_family;
	BYTE sa_data[14];
} sockaddr;

struct sapair {
	SOCKET	s;
	int	l1, l2, l3, l4, lp;
	int	r1, r2, r3, r4, rp;
};
typedef std::list<sapair>	salist;

extern "C" {
	SOCKET _stdcall accept(		SOCKET s, sockaddr *addr, int *addrlen);
	int _stdcall bind(		SOCKET s, const sockaddr *name, int namelen);
	int _stdcall closesocket(	SOCKET s);
	int _stdcall connect(		SOCKET s, const sockaddr *name, int namelen);
	int _stdcall ioctlsocket(	SOCKET s, long cmd, DWORD *argp);
	int _stdcall listen(		SOCKET s, int backlog);
	int _stdcall recv(		SOCKET s, char *buf, int len, int flags);
	int _stdcall recvfrom(		SOCKET s, char *buf, int len, int flags, sockaddr *from, int *fromlen);
	int _stdcall send(		SOCKET s, const char *buf, int len, int flags);
	int _stdcall sendto(		SOCKET s, const char *buf, int len, int flags, const sockaddr *to, int tolen);
	int _stdcall shutdown(		SOCKET s, int how);

	int _stdcall WSAGetLastError();
}

extern "C" {
	SOCKET _stdcall accept_proxy(	SOCKET s, sockaddr *addr, int *addrlen);
	int _stdcall bind_proxy(	SOCKET s, const sockaddr *name, int namelen);
	int _stdcall closesocket_proxy(	SOCKET s);
	int _stdcall connect_proxy(	SOCKET s, const sockaddr *name, int namelen);
	int _stdcall ioctlsocket_proxy(	SOCKET s, long cmd, DWORD *argp);
	int _stdcall listen_proxy(	SOCKET s, int backlog);
	int _stdcall recv_proxy(	SOCKET s, char *buf, int len, int flags);
	int _stdcall recvfrom_proxy(	SOCKET s, char *buf, int len, int flags, sockaddr *from, int *fromlen);
	int _stdcall send_proxy(	SOCKET s, const char *buf, int len, int flags);
	int _stdcall sendto_proxy(	SOCKET s, const char *buf, int len, int flags, const sockaddr *to, int tolen);
	int _stdcall shutdown_proxy(	SOCKET s, int how);
}
