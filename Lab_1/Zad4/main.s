	.file	"main.cpp"
	.intel_syntax noprefix
	.text
	.section	.text$_ZN13PlainOldClass3setEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN13PlainOldClass3setEi
	.def	_ZN13PlainOldClass3setEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN13PlainOldClass3setEi
_ZN13PlainOldClass3setEi: //PlainOldClass::set(int)
.LFB0:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx // prvi arg fje, adresa objekta na stogu
	mov	DWORD PTR 24[rbp], edx //drugi arg fje tj vrijednost koja se upisuje na stogu
	mov	rax, QWORD PTR 16[rbp]  // prvui arg fje u rax sa stoga
	mov	edx, DWORD PTR 24[rbp]  //drugi arg fje u edx sa stoga
	mov	DWORD PTR [rax], edx  //postavlja se vrijednost iz edx u varijablu objekta 
	nop
	pop	rbp
	ret //zavrsi i vrati se
	.seh_endproc
	.section	.text$_ZN9CoolClass3setEi,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9CoolClass3setEi //CoolClass::set(int)
	.def	_ZN9CoolClass3setEi;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9CoolClass3setEi
_ZN9CoolClass3setEi: //CoolClass::set(int)
.LFB2:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	DWORD PTR 24[rbp], edx
	mov	rax, QWORD PTR 16[rbp]
	mov	edx, DWORD PTR 24[rbp]
	mov	DWORD PTR 8[rax], edx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClass3getEv,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9CoolClass3getEv
	.def	_ZN9CoolClass3getEv;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9CoolClass3getEv
_ZN9CoolClass3getEv: //CoolClass::get()
.LFB3:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	mov	rax, QWORD PTR 16[rbp]
	mov	eax, DWORD PTR 8[rax]
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN4BaseC2Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN4BaseC2Ev
	.def	_ZN4BaseC2Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN4BaseC2Ev
_ZN4BaseC2Ev: //Base::Base()
.LFB7:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx
	lea	rdx, _ZTV4Base[rip+16]
	mov	rax, QWORD PTR 16[rbp]
	mov	QWORD PTR [rax], rdx
	nop
	pop	rbp
	ret
	.seh_endproc
	.section	.text$_ZN9CoolClassC1Ev,"x"
	.linkonce discard
	.align 2
	.globl	_ZN9CoolClassC1Ev
	.def	_ZN9CoolClassC1Ev;	.scl	2;	.type	32;	.endef
	.seh_proc	_ZN9CoolClassC1Ev
_ZN9CoolClassC1Ev: //CoolClass::CoolClass() tj konstruktor cool klse
.LFB10:
	push	rbp
	.seh_pushreg	rbp
	mov	rbp, rsp
	.seh_setframe	rbp, 0
	sub	rsp, 32 //32 bajta za lok. varijable
	.seh_stackalloc	32
	.seh_endprologue
	mov	QWORD PTR 16[rbp], rcx //sprema prvi arg fje na stog, tj. pokazivac na this
	mov	rax, QWORD PTR 16[rbp] //ucitava this u rax
	mov	rcx, rax //argument za konstruktor baze, postavlja adresu this objekta kao argument
	call	_ZN4BaseC2Ev //poziv konstruktora baze
	lea	rdx, _ZTV9CoolClass[rip+16] //vtable for CoolClass, ucitava adresu vtable za coolclass u rdx
	mov	rax, QWORD PTR 16[rbp] // u rax ucitava this sa stoga
	mov	QWORD PTR [rax], rdx // do ovdje je postavljena vir. tablica na početak objekta tj njen pokazivac
	nop
	add	rsp, 32 //oslobadja prostor za lok var.
	pop	rbp 
	ret //izlaz
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
.LFB4:
	push	rbp
	.seh_pushreg	rbp
	push	rbx
	.seh_pushreg	rbx
	sub	rsp, 56
	.seh_stackalloc	56	//alocira se mjesto na stogu za lokalnu varijablu,
	// vjerovatni poc, u velicini 48 (56 je vjerovatno zbog paddinga?)
	lea	rbp, 48[rsp] //stavlja SP na početak alociranih podataka 
	.seh_setframe	rbp, 48
	.seh_endprologue
	call	__main // započinje program
	mov	ecx, 16
	call	_Znwy //operator new(unsigned long long) 
	mov	rbx, rax // adresa alocirane memorije se vraca u rax
	mov	rcx, rbx 
	call	_ZN9CoolClassC1Ev //CoolClass::CoolClass() tj konstruktor cool klase poc se ne poziva konstruktor 
	//jer je definiran kao lok. varijabla
	mov	QWORD PTR -8[rbp], rbx //sadrzi adresu za coolclass
	lea	rax, -12[rbp] // adresa plain old class sa stoga
	mov	edx, 42 // postavlja vrijednost 42
	mov	rcx, rax // postavlja adresu plainoldclass objekta
	call	_ZN13PlainOldClass3setEi //poziv set na objektu p.o.c.
	mov	rax, QWORD PTR -8[rbp] //ucitava pointer na vtable
	mov	rax, QWORD PTR [rax] // ucitava ono sto se nalazi na toj memoriji tj. virtual table
	mov	r8, QWORD PTR [rax] // ucitava sadrzaj prvog pok. u vir. tab.
	mov	rax, QWORD PTR -8[rbp] // ucitaj adresu alocirane memorije za coolclass
	mov	edx, 42 // argument koji se postavlja tj salje u fji
	mov	rcx, rax //adresa coolclass u rcx
	call	r8 //pozivaa fju koja se nalazi na adresi koja je u r8 a to bi bila fja set
	mov	eax, 0 // uspjesan zavrsetak programa
	add	rsp, 56 //oslobadja memoriju alociranu za lok varijable 
	pop	rbx
	pop	rbp
	ret
	.seh_endproc
	.globl	_ZTV9CoolClass
	.section	.rdata$_ZTV9CoolClass,"dr" // read only
	.linkonce same_size
	.align 8
_ZTV9CoolClass: //vtable for CoolClass 
	.quad	0
	.quad	_ZTI9CoolClass // informacije o tipu klase
	.quad	_ZN9CoolClass3setEi //set
	.quad	_ZN9CoolClass3getEv //get
	.globl	_ZTV4Base //ovo se odnosi na vtable od bazne klase
	.section	.rdata$_ZTV4Base,"dr"
	.linkonce same_size
	.align 8
_ZTV4Base: //vtable for Base
	.quad	0
	.quad	_ZTI4Base
	.quad	__cxa_pure_virtual
	.quad	__cxa_pure_virtual
	.globl	_ZTI9CoolClass
	.section	.rdata$_ZTI9CoolClass,"dr"
	.linkonce same_size
	.align 8
_ZTI9CoolClass: //typeinfo for CoolClass
	.quad	_ZTVN10__cxxabiv120__si_class_type_infoE+16 //vtable for __cxxabiv1::__si_class_type_info 16
	.quad	_ZTS9CoolClass
	.quad	_ZTI4Base
	.globl	_ZTS9CoolClass
	.section	.rdata$_ZTS9CoolClass,"dr"
	.linkonce same_size
	.align 8
_ZTS9CoolClass: //typeinfo name for CoolClass
	.ascii "9CoolClass\0"
	.globl	_ZTI4Base
	.section	.rdata$_ZTI4Base,"dr"
	.linkonce same_size
	.align 8
_ZTI4Base: //typeinfo for Base
	.quad	_ZTVN10__cxxabiv117__class_type_infoE+16 //vtable for __cxxabiv1::__class_type_info 16
	.quad	_ZTS4Base //typeinfo name for Base
	.globl	_ZTS4Base
	.section	.rdata$_ZTS4Base,"dr"
	.linkonce same_size
_ZTS4Base: //typeinfo name for Base
	.ascii "4Base\0"
	.weak	__cxa_pure_virtual
	.ident	"GCC: (Rev1, Built by MSYS2 project) 12.2.0"
	.def	_Znwy;	.scl	2;	.type	32;	.endef
	.def	__cxa_pure_virtual;	.scl	2;	.type	32;	.endef
