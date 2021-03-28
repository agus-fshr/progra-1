	.file	"10.c"
	.text
	.globl	_hasta_dia
	.bss
	.align 4
_hasta_dia:
	.space 4
	.globl	_hasta_mes
	.align 4
_hasta_mes:
	.space 4
	.globl	_hasta_anno
	.align 4
_hasta_anno:
	.space 4
	.globl	_desde_dia
	.align 4
_desde_dia:
	.space 4
	.globl	_desde_mes
	.align 4
_desde_mes:
	.space 4
	.globl	_desde_anno
	.align 4
_desde_anno:
	.space 4
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "Fecha de inicio: %d\11%d\11%d\12\0"
LC1:
	.ascii "Fecha de fin   : %d\11%d\11%d\12\0"
	.align 4
LC2:
	.ascii "\12La diferencia entre fechas es %d\12\0"
	.text
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB13:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	andl	$-16, %esp
	subl	$48, %esp
	.cfi_offset 7, -12
	.cfi_offset 6, -16
	.cfi_offset 3, -20
	call	___main
	call	_parsear_fechas
	movl	_desde_anno, %ecx
	movl	_desde_mes, %edx
	movl	_desde_dia, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC0, (%esp)
	call	_printf
	movl	_hasta_anno, %ecx
	movl	_hasta_mes, %edx
	movl	_hasta_dia, %eax
	movl	%ecx, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$LC1, (%esp)
	call	_printf
	movl	_hasta_dia, %edi
	movl	_hasta_mes, %esi
	movl	_hasta_anno, %ebx
	movl	_desde_dia, %ecx
	movl	_desde_mes, %edx
	movl	_desde_anno, %eax
	movl	%edi, 20(%esp)
	movl	%esi, 16(%esp)
	movl	%ebx, 12(%esp)
	movl	%ecx, 8(%esp)
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_calcular_diferencia
	movl	%eax, 44(%esp)
	movl	44(%esp), %eax
	movl	%eax, 4(%esp)
	movl	$LC2, (%esp)
	call	_printf
	movl	$0, %eax
	leal	-12(%ebp), %esp
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%edi
	.cfi_restore 7
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE13:
	.globl	_bisiesto
	.def	_bisiesto;	.scl	2;	.type	32;	.endef
_bisiesto:
LFB14:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	movl	8(%ebp), %eax
	andl	$3, %eax
	testl	%eax, %eax
	jne	L4
	movl	8(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$5, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$100, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	jne	L5
	movl	8(%ebp), %ecx
	movl	$1374389535, %edx
	movl	%ecx, %eax
	imull	%edx
	sarl	$7, %edx
	movl	%ecx, %eax
	sarl	$31, %eax
	subl	%eax, %edx
	movl	%edx, %eax
	imull	$400, %eax, %eax
	subl	%eax, %ecx
	movl	%ecx, %eax
	testl	%eax, %eax
	je	L5
	movl	$0, %eax
	jmp	L6
L5:
	movl	$1, %eax
	jmp	L6
L4:
	movl	$0, %eax
L6:
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE14:
	.section .rdata,"dr"
	.align 4
LC3:
	.ascii "Ingrese una fecha de inicio valida (dd/mm/aaaa): \0"
	.align 4
LC4:
	.ascii "Ingrese una fecha de fin valida (dd/mm/aaaa): \0"
	.text
	.globl	_parsear_fechas
	.def	_parsear_fechas;	.scl	2;	.type	32;	.endef
_parsear_fechas:
LFB15:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$1, -12(%ebp)
	jmp	L8
L11:
	movl	$LC3, (%esp)
	call	_printf
	call	_leer_nro
	movl	%eax, _desde_dia
	call	_leer_nro
	movl	%eax, _desde_mes
	call	_leer_nro
	movl	%eax, _desde_anno
	movl	_desde_dia, %eax
	testl	%eax, %eax
	je	L9
	movl	_desde_anno, %edx
	movl	_desde_mes, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_dias_del_mes
	movl	_desde_dia, %edx
	cmpl	%edx, %eax
	jl	L9
	movl	_desde_mes, %eax
	testl	%eax, %eax
	je	L9
	movl	_desde_mes, %eax
	cmpl	$12, %eax
	jle	L10
L9:
	movl	$1, -12(%ebp)
	jmp	L8
L10:
	movl	$0, -12(%ebp)
L8:
	cmpl	$1, -12(%ebp)
	je	L11
	movl	$1, -12(%ebp)
	jmp	L12
L15:
	movl	$LC4, (%esp)
	call	_printf
	call	_leer_nro
	movl	%eax, _hasta_dia
	call	_leer_nro
	movl	%eax, _hasta_mes
	call	_leer_nro
	movl	%eax, _hasta_anno
	movl	_hasta_dia, %eax
	testl	%eax, %eax
	je	L13
	movl	_hasta_anno, %edx
	movl	_hasta_mes, %eax
	movl	%edx, 4(%esp)
	movl	%eax, (%esp)
	call	_dias_del_mes
	movl	_hasta_dia, %edx
	cmpl	%edx, %eax
	jl	L13
	movl	_hasta_mes, %eax
	testl	%eax, %eax
	je	L13
	movl	_hasta_mes, %eax
	cmpl	$12, %eax
	jle	L14
L13:
	movl	$1, -12(%ebp)
	jmp	L12
L14:
	movl	$0, -12(%ebp)
L12:
	cmpl	$1, -12(%ebp)
	je	L15
	nop
	nop
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE15:
	.globl	_calcular_diferencia
	.def	_calcular_diferencia;	.scl	2;	.type	32;	.endef
_calcular_diferencia:
LFB16:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$56, %esp
	movl	$0, -12(%ebp)
	movl	8(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -16(%ebp)
	jmp	L17
L20:
	movl	$1, -20(%ebp)
	jmp	L18
L19:
	movl	-16(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-20(%ebp), %eax
	movl	%eax, (%esp)
	call	_dias_del_mes
	addl	%eax, -12(%ebp)
	addl	$1, -20(%ebp)
L18:
	cmpl	$12, -20(%ebp)
	jle	L19
	addl	$1, -16(%ebp)
L17:
	movl	-16(%ebp), %eax
	cmpl	20(%ebp), %eax
	jl	L20
	movl	20(%ebp), %eax
	cmpl	8(%ebp), %eax
	je	L21
	movl	$1, -24(%ebp)
	jmp	L22
L23:
	movl	20(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-24(%ebp), %eax
	movl	%eax, (%esp)
	call	_dias_del_mes
	addl	%eax, -12(%ebp)
	addl	$1, -24(%ebp)
L22:
	movl	-24(%ebp), %eax
	cmpl	24(%ebp), %eax
	jl	L23
	movl	28(%ebp), %eax
	addl	%eax, -12(%ebp)
	movl	$12, -28(%ebp)
	jmp	L24
L25:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-28(%ebp), %eax
	movl	%eax, (%esp)
	call	_dias_del_mes
	addl	%eax, -12(%ebp)
	subl	$1, -28(%ebp)
L24:
	movl	-28(%ebp), %eax
	cmpl	12(%ebp), %eax
	jg	L25
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_dias_del_mes
	subl	16(%ebp), %eax
	addl	%eax, -12(%ebp)
	jmp	L26
L21:
	movl	12(%ebp), %eax
	cmpl	24(%ebp), %eax
	je	L27
	movl	12(%ebp), %eax
	addl	$1, %eax
	movl	%eax, -32(%ebp)
	jmp	L28
L29:
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	-32(%ebp), %eax
	movl	%eax, (%esp)
	call	_dias_del_mes
	addl	%eax, -12(%ebp)
	addl	$1, -32(%ebp)
L28:
	movl	-32(%ebp), %eax
	cmpl	24(%ebp), %eax
	jl	L29
	movl	28(%ebp), %eax
	addl	%eax, -12(%ebp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_dias_del_mes
	subl	16(%ebp), %eax
	addl	%eax, -12(%ebp)
	jmp	L26
L27:
	movl	28(%ebp), %eax
	subl	16(%ebp), %eax
	movl	%eax, -12(%ebp)
L26:
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE16:
	.globl	_dias_del_mes
	.def	_dias_del_mes;	.scl	2;	.type	32;	.endef
_dias_del_mes:
LFB17:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$4, %esp
	cmpl	$2, 8(%ebp)
	jne	L32
	movl	12(%ebp), %eax
	movl	%eax, (%esp)
	call	_bisiesto
	testl	%eax, %eax
	je	L33
	movl	$29, %eax
	jmp	L35
L33:
	movl	$28, %eax
	jmp	L35
L32:
	cmpl	$7, 8(%ebp)
	jg	L36
	movl	8(%ebp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	cmpl	$1, %eax
	jne	L37
	movl	$31, %eax
	jmp	L35
L37:
	movl	$30, %eax
	jmp	L35
L36:
	movl	8(%ebp), %eax
	cltd
	shrl	$31, %edx
	addl	%edx, %eax
	andl	$1, %eax
	subl	%edx, %eax
	cmpl	$1, %eax
	jne	L39
	movl	$30, %eax
	jmp	L35
L39:
	movl	$31, %eax
L35:
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE17:
	.globl	_leer_fecha
	.def	_leer_fecha;	.scl	2;	.type	32;	.endef
_leer_fecha:
LFB18:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	nop
	popl	%ebp
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE18:
	.globl	_leer_nro
	.def	_leer_nro;	.scl	2;	.type	32;	.endef
_leer_nro:
LFB19:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$0, -12(%ebp)
	jmp	L43
L45:
	fildl	-12(%ebp)
	fldl	LC5
	fmulp	%st, %st(1)
	fnstcw	-26(%ebp)
	movzwl	-26(%ebp), %eax
	orb	$12, %ah
	movw	%ax, -28(%ebp)
	fldcw	-28(%ebp)
	fistpl	-12(%ebp)
	fldcw	-26(%ebp)
	movsbl	-13(%ebp), %eax
	subl	$48, %eax
	addl	%eax, -12(%ebp)
L43:
	call	_getchar
	movb	%al, -13(%ebp)
	cmpb	$47, -13(%ebp)
	jle	L44
	cmpb	$57, -13(%ebp)
	jle	L45
L44:
	movl	-12(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
LFE19:
	.section .rdata,"dr"
	.align 8
LC5:
	.long	0
	.long	1076101120
	.ident	"GCC: (MinGW.org GCC Build-20200227-1) 9.2.0"
	.def	_printf;	.scl	2;	.type	32;	.endef
	.def	_getchar;	.scl	2;	.type	32;	.endef
