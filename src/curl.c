#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

// typedef CurlObject {
//
// }

/* char *buffer; */
/* char *get_stz_curl_write_buffer() {return buffer;} */

struct MemoryStruct {
  char *memory;
  size_t size;
};

struct MemoryStruct *mem;
char *stz_curl_write_mem() {return mem->memory;}

static size_t
WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    printf("Writing to memory...");
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if(mem->memory == NULL) {
    /* out of memory! */
    printf("not enough memory (realloc returned NULL)\n");
    return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;

    return realsize;
}

void
stz_curl_set_callback(CURL *handle)
{
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
}
