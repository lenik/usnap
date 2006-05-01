
#include "types.h"

static list_t g_ctxlist;

static int addrlen(const sockaddr *addr) {
    switch (addr->sin_family) {
    case AF_INET:
        return sizeof(sockaddr_in);
    case AF_INET6:
        return sizeof(sockaddr_in6);
    }
    return sizeof(sockaddr);
}

sioctx_t *siolisten(const sockaddr *addr, int passive, siopktf_t pkt_in) {
    SOCKET sd;
    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sd == INVALID_SOCKET)
        return NULL;
    if (bind(sd, addr, addrlen(addr)) == SOCKET_ERROR) {
        closesocket(sd);
        return NULL;
    }
    if (listen(sd, SOMAXCONN) == SOCKETERROR) {
        closesocket(sd);
        return NULL;
    }
    return sioupon(sd, 1, passive, pkt_in);
}

sioctx_t *siolistenport(u16_t port, int passive, siopktf_t pkt_in) {
    sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    addr.sin_port = htons(port);
    return siolistenport(&addr, passive, pkt_in);
}

sioctx_t *sioconnect(const sockaddr *addr, int passive, siopktf_t pkt_in) {
    SOCKET sd;
    sd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sd == INVALID_SOCKET)
        return NULL;
    if (connect(sd, addr, addrlen(addr)) == SOCKET_ERROR) {
        closesocket(sd);
        return NULL;
    }
    return sioupon(sd, 0, passive, pkt_in);
}

sioctx_t *sioupon(SOCKET sd, int server, int passive, siopktf_t pkt_in) {
    sioctx_t *ctx;
    ctx = (sioctx_t *)malloc(sizeof(sioctx_t));
    if (ctx == NULL)
        return NULL;                    /* see errno */
    ctx->sd = sd;
    ctx->flags = SIOCTXF_SERVER;
    if (passive)
        ctx->flags |= SIOCTXF_PASSIVE;
    ctx->pkt_in = pkt_in;

    list_add(g_ctxlist, ctx);
    return ctx;
}

void siofree(sioctx_t *ctx) {
    _assert_(ctx);
    if (ctx->flags & SIOCTXF_SERVER) {
        closesocket(ctx->sd);
    }
    free(ctx);
}
