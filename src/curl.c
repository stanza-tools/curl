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
void  stz_curl_write_mem_free() {free(mem->memory);}

static size_t
stz_curl_write_mem_cb(void *contents, size_t size, size_t nmemb, void *userp)
{
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
stz_curl_write_mem_cb_set(CURL *handle)
{
    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, stz_curl_write_mem_cb);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, (void *)&chunk);
}
