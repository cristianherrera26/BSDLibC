#ifndef _ARCH_SYSCALL_ARCH
#define _ARCH_SYSCALL_ARCH	1

#define __syscall0(n) ({								\
	unsigned long ret;								\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n) : "rcx", "r11", "memory");	\
	(long)ret;									\
})

#define __syscall1(n, a1) ({								\
	unsigned long ret;								\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1)			\
				: "rcx", "r11", "memory");				\
	(long)ret;									\
})

#define __syscall2(n, a1, a2) ({							\
	unsigned long ret;								\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), 			\
				"S"(a2) : "rcx", "r11", "memory");			\
	(long)ret;									\
})

#define __syscall3(n, a1, a2, a3) ({							\
	unsigned long ret;								\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), 			\
				"S"(a2), "d"(a3) : "rcx", "r11", "memory");		\
	(long)ret;									\
})

#define __syscall4(n, a1, a2, a3, a4) ({						\
	unsigned long ret;								\
	register long r10 __asm__("r10") = a4;						\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), 			\
				"S"(a2), "d"(a3), "r"(r10) :				\
				"rcx", "r11", "memory");				\
	(long)ret;									\
})

#define __syscall5(n, a1, a2, a3, a4, a5) ({						\
	unsigned long ret;								\
	register long r10 __asm__("r10") = a4;						\
	register long r8 __asm__("r8") = a5;						\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), 			\
				"S"(a2), "d"(a3), "r"(r10), "r"(r8) :			\
				"rcx", "r11", "memory");				\
	(long)ret;									\
})

#define __syscall6(n, a1, a2, a3, a4, a5, a6) ({					\
	unsigned long ret;								\
	register long r10 __asm__("r10") = a4;						\
	register long r8 __asm__("r8") = a5;						\
	register long r9 __asm__("r9") = a6;						\
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), 			\
				"S"(a2), "d"(a3), "r"(r10), "r"(r8),			\
				"r"(r9) : "rcx", "r11", "memory");			\
	(long)ret;									\
})

#endif
