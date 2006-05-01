
/* SIOF (SFFDDA) */
/* Socket I/O Framework for Data-Driven Application */


应用程序自己操作SIOF，最后形成一个IO接口，包括：
nsios_t {
    in(x32_t sel, size_t, void *);
    --> 这个接口将被替换:
        nsio_t *nsnew(nsio_t *),
        void nsaddmod(nsio_t *, mod_t *);
    out(x32_t sel, size_t, void *);
    close();
}
