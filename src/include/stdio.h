#ifndef _STDIO_H
#define _STDIO_H	1

typedef struct __sFILE {
        unsigned char *_p;      /* current position in (some) buffer */
        int     _r;             /* read space left for getc() */
        int     _w;             /* write space left for putc() */
        unsigned short _flags;  /* flags, below; this FILE is free if 0 */
        short   _file;          /* fileno, if Unix descriptor, else -1 */
        struct  __sbuf _bf;     /* the buffer (at least 1 byte, if !NULL) */
        int     _lbfsize;       /* 0 or -_bf._size, for inline putc */

        /* operations */
        void    *_cookie;       /* cookie passed to io functions */
        int     (*_close)(void *);
        ssize_t (*_read) (void *, void *, size_t);
        __off_t (*_seek) (void *, __off_t, int);
        ssize_t (*_write)(void *, const void *, size_t);

        /* file extension */
        struct  __sbuf _ext;

        /* separate buffer for long sequences of ungetc() */
        unsigned char *_up;     /* saved _p when _p is doing ungetc data */
        int     _ur;            /* saved _r when _r is counting ungetc data */

        /* tricks to meet minimum requirements even when malloc() fails */
        unsigned char _ubuf[3]; /* guarantee an ungetc() buffer */
        unsigned char _nbuf[1]; /* guarantee a getc() buffer */

        int     (*_flush)(void *);
        /* Formerly used by fgetln/fgetwln; kept for binary compatibility */
        char    _lb_unused[sizeof(struct __sbuf) - sizeof(int (*)(void *))];

        /* Unix stdio files get aligned to block boundaries on fseek() */
        int     _blksize;       /* stat.st_blksize (may be != _bf._size) */
        __off_t _offset;        /* current lseek offset */
} FILE;

#endif
