#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

// typedef CurlObject {
//
// }

char *buffer;
buffer[0] = '\0';
char *get_stz_curl_write_buffer() {return buffer;}

static size_t
stz_curl_write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
  strncpy((char *)contents, size, buffer);
  return size * nmemb;
}
