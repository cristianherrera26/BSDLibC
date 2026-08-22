#ifndef _UNISTD_H
#define _UNISTD_H	1

#include <sys/types.h>
#include <stddef.h>

pid_t fork(void);
pid_t getpid(void);
pid_t getppid(void);
ssize_t write(int fd, const void *buf, size_t count);
ssize_t read(int fd, void *buf, size_t count);
void _exit(int exit_code);
int getdomainname(char *name, size_t namelen);
int gethostname(char *name, size_t namelen);

#define F_OK 0
#define R_OK 4
#define W_OK 2
#define X_OK 1

int close(int fd);
void sync(void);
int getpagesize(void);
int brk(void *addr);
void *sbrk(intptr_t increment);
uid_t getuid(void);
uid_t geteuid(void);
gid_t getgid(void);
gid_t getegid(void);
int issetugid(void);
int chroot(const char *path);
int chdir(const char *path);
int fchdir(int fd);
int fchroot(int fd);
int access(const char *path, int mode);
int link(const char *path);
int unlink(const char *path);
int pipe(int fd[2]);

ssize_t readlink(const char *path, char *buf, size_t count);

/* OpenBSD compatibility layer */
int unveil(const char *path, const char *permissions);
int pledge(const char *promises, const char *execpromises);

int sethostid(long hostid);
long gethostid(void);

char *getcwd(char *buf, size_t size);
char *getwd(char *buf);

int revoke(const char *path);
int execve(const char *path, char *const argv[], char *const envp[]);

#define STDIN_FILENO  0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

#endif
