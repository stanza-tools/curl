#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

// typedef CurlObject {
//
// }

char *buffer;
char *get_stz_curl_write_buffer() {return buffer;}

static size_t
stz_curl_write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	printf("Size: %i", (int) size);
	printf("NMemB: %i", (int) nmemb);
    size_t full_size = size * nmemb;
    buffer = (char *)malloc(full_size);
    strncpy(buffer, (char *)contents, size);
    return full_size;
}

void
stz_curl_set_callback(CURL *handle)
{
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, stz_curl_write_callback);
}
