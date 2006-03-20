
#pragma once

int base64_encode(const char *data, int cb, char *buffer, int cc);
int base64_decode(const char *base64, int cc, char *buffer, int cb);
