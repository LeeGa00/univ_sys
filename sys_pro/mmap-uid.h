/* mmap-uid.h */
#include <fcntl.h> 
#include <string.h> 
#include <sys/mman.h> 
#include <sys/stat.h> 
#include <time.h> 
#include <unistd.h> 

#define DB_FILE "counter.data" // mapped file
#define MAGIC "42" // magic number used as a key
#define MAGIC_SIZ sizeof(MAGIC)

struct glob_id {
	char magic[3]; // magic string "42\0" 
	time_t ts; // last modification timestamp
	long val; // global counter value 
};

int glob_id_verify_magic(int fd, struct glob_id *id) {
	int rc;

	// we here check the magic number
	// if the two values are same, then 0 is return
	// man 3 strncmp
	rc = strncmp(id->magic, MAGIC, 3); 
	return rc;
}

void glob_id_write(struct glob_id *id, long val) {
	// we here our magic number (42) into id.magic
	// man 3 memcpy
	memcpy(id->magic, MAGIC, MAGIC_SIZ);

	id->ts = time(NULL);  // store the current time in sec into id.ts
	id->val = val; // copy the counter value into id.val
}
