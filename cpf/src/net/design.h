
/* SIOF (SFFDDA) */
/* Socket I/O Framework for Data-Driven Application */


Ӧ�ó����Լ�����SIOF������γ�һ��IO�ӿڣ�������
nsios_t {
    in(x32_t sel, size_t, void *);
    --> ����ӿڽ����滻:
        nsio_t *nsnew(nsio_t *),
        void nsaddmod(nsio_t *, mod_t *);
    out(x32_t sel, size_t, void *);
    close();
}
