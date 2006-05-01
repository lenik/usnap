
struct nspkt_t {
    u32_t cat;
    size_t size;
    char *data;
    /* --- raw source info --- */
    sockaddr_t addr;
};

struct nssvc_t {
    void *addrs;
    list_t sendbuf;
    list_t recvbuf;
    void pkt_in(nspkt_t *pkt);
    nssx_cmd_t *cmdsx;                  /* svc ext */
};

struct nssx_cmd_t {
    u32_t nssx_4cc;                     /* = 'CMD ' */
    void pkt2_in(nspkt2_t *pkt2);
    void cmdline_in(char *cmdline, size_t size);
    void cmd_in(nscmd_t *cmd, void **args, int nopts);
};

/* address -> nssvc
   nssvc::pkt2_in() */
void pkt_in(nspkt_t *pkt);

nsbind(nssvc_t *, sockaddr_t);
nsunbind(nssvc_t *, sockaddr_t);

void nsstart();
void nsstop();

static DWORD _nsloop(LPVOID param) {
    /* for each svc:

         recv(sock[i], buf); -- nonblock
         dispatch(i, buf);
         send(sock[i], sendbuf[i]); -- nonblock
     */
}
