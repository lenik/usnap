
struct nscodec_t {
    const char *name;
    size_t rest_size;
    void *rest_data;
};

void _stdcall nscodec_bin(nssvc_t *svc, x32_t sel, size_t size, void *data) {
    svc->bin_in(svc, sel, size, data);
}

void _stdcall nscodec_hex(nssvc_t *svc, x32_t sel, size_t size, void *data) {
    /* concat(rest_data, data); */
    /* decode hex -> bin */
    nscodec_bin(svc, sel, bin_size, bin_data);
}

void _stdcall nscodec_base64(nssvc_t *svc, x32_t sel, size_t size, void *data) {
    /* concat(rest_data, data); */
    /* decode hex -> bin */
    nscodec_bin(svc, sel, bin_size, bin_data);
}
