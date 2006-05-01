
/* e.g. */
static nsiodrv_t g_drv;
static nssvc_t *g_svc;

void main() {
    g_svc = nssvc_new();
    nssvc_setdriver(g_svc, g_drv);
    g_drv->in != NULL */
    g_drv->close = &my_close;

    siof_xxx = { 8080,
                 my_pkt_in,           /* when socket recv data, callback this */
                 my_pkt_out };          /* filled by siof_install? */
    siof_install(siof_xxx);
}

my_pkt_in() {
    g_drv->in(0, size_t, void *);
}

my_close() {
    siof_close();
}
