#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void *xmalloc(size_t sz)
{
	void *p;
	
	p = malloc(sz);
	if ((p))
		memset(p, 0x00, sz);
	
	return p;
}

void xfree(void *p, size_t sz)
{
	if ((p) && sz > 0)
		memset(p, 0x00, sz);
	
	free(p);
}