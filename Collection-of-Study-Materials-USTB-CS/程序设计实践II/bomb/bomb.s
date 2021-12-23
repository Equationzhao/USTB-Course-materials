
/home/jovyan/work/bomb:     file format elf32-i386


Disassembly of section .init:

08049000 <_init>:
 8049000:	f3 0f 1e fb          	endbr32 
 8049004:	53                   	push   %ebx
 8049005:	83 ec 08             	sub    $0x8,%esp
 8049008:	e8 83 02 00 00       	call   8049290 <__x86.get_pc_thunk.bx>
 804900d:	81 c3 f3 3f 00 00    	add    $0x3ff3,%ebx
 8049013:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 8049019:	85 c0                	test   %eax,%eax
 804901b:	74 02                	je     804901f <_init+0x1f>
 804901d:	ff d0                	call   *%eax
 804901f:	83 c4 08             	add    $0x8,%esp
 8049022:	5b                   	pop    %ebx
 8049023:	c3                   	ret    

Disassembly of section .plt:

08049030 <.plt>:
 8049030:	ff 35 04 d0 04 08    	pushl  0x804d004
 8049036:	ff 25 08 d0 04 08    	jmp    *0x804d008
 804903c:	0f 1f 40 00          	nopl   0x0(%eax)
 8049040:	f3 0f 1e fb          	endbr32 
 8049044:	68 00 00 00 00       	push   $0x0
 8049049:	e9 e2 ff ff ff       	jmp    8049030 <.plt>
 804904e:	66 90                	xchg   %ax,%ax
 8049050:	f3 0f 1e fb          	endbr32 
 8049054:	68 08 00 00 00       	push   $0x8
 8049059:	e9 d2 ff ff ff       	jmp    8049030 <.plt>
 804905e:	66 90                	xchg   %ax,%ax
 8049060:	f3 0f 1e fb          	endbr32 
 8049064:	68 10 00 00 00       	push   $0x10
 8049069:	e9 c2 ff ff ff       	jmp    8049030 <.plt>
 804906e:	66 90                	xchg   %ax,%ax
 8049070:	f3 0f 1e fb          	endbr32 
 8049074:	68 18 00 00 00       	push   $0x18
 8049079:	e9 b2 ff ff ff       	jmp    8049030 <.plt>
 804907e:	66 90                	xchg   %ax,%ax
 8049080:	f3 0f 1e fb          	endbr32 
 8049084:	68 20 00 00 00       	push   $0x20
 8049089:	e9 a2 ff ff ff       	jmp    8049030 <.plt>
 804908e:	66 90                	xchg   %ax,%ax
 8049090:	f3 0f 1e fb          	endbr32 
 8049094:	68 28 00 00 00       	push   $0x28
 8049099:	e9 92 ff ff ff       	jmp    8049030 <.plt>
 804909e:	66 90                	xchg   %ax,%ax
 80490a0:	f3 0f 1e fb          	endbr32 
 80490a4:	68 30 00 00 00       	push   $0x30
 80490a9:	e9 82 ff ff ff       	jmp    8049030 <.plt>
 80490ae:	66 90                	xchg   %ax,%ax
 80490b0:	f3 0f 1e fb          	endbr32 
 80490b4:	68 38 00 00 00       	push   $0x38
 80490b9:	e9 72 ff ff ff       	jmp    8049030 <.plt>
 80490be:	66 90                	xchg   %ax,%ax
 80490c0:	f3 0f 1e fb          	endbr32 
 80490c4:	68 40 00 00 00       	push   $0x40
 80490c9:	e9 62 ff ff ff       	jmp    8049030 <.plt>
 80490ce:	66 90                	xchg   %ax,%ax
 80490d0:	f3 0f 1e fb          	endbr32 
 80490d4:	68 48 00 00 00       	push   $0x48
 80490d9:	e9 52 ff ff ff       	jmp    8049030 <.plt>
 80490de:	66 90                	xchg   %ax,%ax
 80490e0:	f3 0f 1e fb          	endbr32 
 80490e4:	68 50 00 00 00       	push   $0x50
 80490e9:	e9 42 ff ff ff       	jmp    8049030 <.plt>
 80490ee:	66 90                	xchg   %ax,%ax
 80490f0:	f3 0f 1e fb          	endbr32 
 80490f4:	68 58 00 00 00       	push   $0x58
 80490f9:	e9 32 ff ff ff       	jmp    8049030 <.plt>
 80490fe:	66 90                	xchg   %ax,%ax
 8049100:	f3 0f 1e fb          	endbr32 
 8049104:	68 60 00 00 00       	push   $0x60
 8049109:	e9 22 ff ff ff       	jmp    8049030 <.plt>
 804910e:	66 90                	xchg   %ax,%ax
 8049110:	f3 0f 1e fb          	endbr32 
 8049114:	68 68 00 00 00       	push   $0x68
 8049119:	e9 12 ff ff ff       	jmp    8049030 <.plt>
 804911e:	66 90                	xchg   %ax,%ax
 8049120:	f3 0f 1e fb          	endbr32 
 8049124:	68 70 00 00 00       	push   $0x70
 8049129:	e9 02 ff ff ff       	jmp    8049030 <.plt>
 804912e:	66 90                	xchg   %ax,%ax
 8049130:	f3 0f 1e fb          	endbr32 
 8049134:	68 78 00 00 00       	push   $0x78
 8049139:	e9 f2 fe ff ff       	jmp    8049030 <.plt>
 804913e:	66 90                	xchg   %ax,%ax

Disassembly of section .plt.sec:

08049140 <printf@plt>:
 8049140:	f3 0f 1e fb          	endbr32 
 8049144:	ff 25 0c d0 04 08    	jmp    *0x804d00c
 804914a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049150 <fflush@plt>:
 8049150:	f3 0f 1e fb          	endbr32 
 8049154:	ff 25 10 d0 04 08    	jmp    *0x804d010
 804915a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049160 <fgets@plt>:
 8049160:	f3 0f 1e fb          	endbr32 
 8049164:	ff 25 14 d0 04 08    	jmp    *0x804d014
 804916a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049170 <signal@plt>:
 8049170:	f3 0f 1e fb          	endbr32 
 8049174:	ff 25 18 d0 04 08    	jmp    *0x804d018
 804917a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049180 <sleep@plt>:
 8049180:	f3 0f 1e fb          	endbr32 
 8049184:	ff 25 1c d0 04 08    	jmp    *0x804d01c
 804918a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049190 <__stack_chk_fail@plt>:
 8049190:	f3 0f 1e fb          	endbr32 
 8049194:	ff 25 20 d0 04 08    	jmp    *0x804d020
 804919a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080491a0 <getenv@plt>:
 80491a0:	f3 0f 1e fb          	endbr32 
 80491a4:	ff 25 24 d0 04 08    	jmp    *0x804d024
 80491aa:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080491b0 <puts@plt>:
 80491b0:	f3 0f 1e fb          	endbr32 
 80491b4:	ff 25 28 d0 04 08    	jmp    *0x804d028
 80491ba:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080491c0 <exit@plt>:
 80491c0:	f3 0f 1e fb          	endbr32 
 80491c4:	ff 25 2c d0 04 08    	jmp    *0x804d02c
 80491ca:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080491d0 <strlen@plt>:
 80491d0:	f3 0f 1e fb          	endbr32 
 80491d4:	ff 25 30 d0 04 08    	jmp    *0x804d030
 80491da:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080491e0 <__libc_start_main@plt>:
 80491e0:	f3 0f 1e fb          	endbr32 
 80491e4:	ff 25 34 d0 04 08    	jmp    *0x804d034
 80491ea:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

080491f0 <__isoc99_sscanf@plt>:
 80491f0:	f3 0f 1e fb          	endbr32 
 80491f4:	ff 25 38 d0 04 08    	jmp    *0x804d038
 80491fa:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049200 <fopen@plt>:
 8049200:	f3 0f 1e fb          	endbr32 
 8049204:	ff 25 3c d0 04 08    	jmp    *0x804d03c
 804920a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049210 <strtok@plt>:
 8049210:	f3 0f 1e fb          	endbr32 
 8049214:	ff 25 40 d0 04 08    	jmp    *0x804d040
 804921a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049220 <atoi@plt>:
 8049220:	f3 0f 1e fb          	endbr32 
 8049224:	ff 25 44 d0 04 08    	jmp    *0x804d044
 804922a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

08049230 <__ctype_b_loc@plt>:
 8049230:	f3 0f 1e fb          	endbr32 
 8049234:	ff 25 48 d0 04 08    	jmp    *0x804d048
 804923a:	66 0f 1f 44 00 00    	nopw   0x0(%eax,%eax,1)

Disassembly of section .text:

08049240 <_start>:
 8049240:	f3 0f 1e fb          	endbr32 
 8049244:	31 ed                	xor    %ebp,%ebp
 8049246:	5e                   	pop    %esi
 8049247:	89 e1                	mov    %esp,%ecx
 8049249:	83 e4 f0             	and    $0xfffffff0,%esp
 804924c:	50                   	push   %eax
 804924d:	54                   	push   %esp
 804924e:	52                   	push   %edx
 804924f:	e8 23 00 00 00       	call   8049277 <_start+0x37>
 8049254:	81 c3 ac 3d 00 00    	add    $0x3dac,%ebx
 804925a:	8d 83 60 d1 ff ff    	lea    -0x2ea0(%ebx),%eax
 8049260:	50                   	push   %eax
 8049261:	8d 83 f0 d0 ff ff    	lea    -0x2f10(%ebx),%eax
 8049267:	50                   	push   %eax
 8049268:	51                   	push   %ecx
 8049269:	56                   	push   %esi
 804926a:	c7 c0 56 93 04 08    	mov    $0x8049356,%eax
 8049270:	50                   	push   %eax
 8049271:	e8 6a ff ff ff       	call   80491e0 <__libc_start_main@plt>
 8049276:	f4                   	hlt    
 8049277:	8b 1c 24             	mov    (%esp),%ebx
 804927a:	c3                   	ret    
 804927b:	66 90                	xchg   %ax,%ax
 804927d:	66 90                	xchg   %ax,%ax
 804927f:	90                   	nop

08049280 <_dl_relocate_static_pie>:
 8049280:	f3 0f 1e fb          	endbr32 
 8049284:	c3                   	ret    
 8049285:	66 90                	xchg   %ax,%ax
 8049287:	66 90                	xchg   %ax,%ax
 8049289:	66 90                	xchg   %ax,%ax
 804928b:	66 90                	xchg   %ax,%ax
 804928d:	66 90                	xchg   %ax,%ax
 804928f:	90                   	nop

08049290 <__x86.get_pc_thunk.bx>:
 8049290:	8b 1c 24             	mov    (%esp),%ebx
 8049293:	c3                   	ret    
 8049294:	66 90                	xchg   %ax,%ax
 8049296:	66 90                	xchg   %ax,%ax
 8049298:	66 90                	xchg   %ax,%ax
 804929a:	66 90                	xchg   %ax,%ax
 804929c:	66 90                	xchg   %ax,%ax
 804929e:	66 90                	xchg   %ax,%ax

080492a0 <deregister_tm_clones>:
 80492a0:	b8 74 d2 04 08       	mov    $0x804d274,%eax
 80492a5:	3d 74 d2 04 08       	cmp    $0x804d274,%eax
 80492aa:	74 24                	je     80492d0 <deregister_tm_clones+0x30>
 80492ac:	b8 00 00 00 00       	mov    $0x0,%eax
 80492b1:	85 c0                	test   %eax,%eax
 80492b3:	74 1b                	je     80492d0 <deregister_tm_clones+0x30>
 80492b5:	55                   	push   %ebp
 80492b6:	89 e5                	mov    %esp,%ebp
 80492b8:	83 ec 14             	sub    $0x14,%esp
 80492bb:	68 74 d2 04 08       	push   $0x804d274
 80492c0:	ff d0                	call   *%eax
 80492c2:	83 c4 10             	add    $0x10,%esp
 80492c5:	c9                   	leave  
 80492c6:	c3                   	ret    
 80492c7:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 80492ce:	66 90                	xchg   %ax,%ax
 80492d0:	c3                   	ret    
 80492d1:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 80492d8:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 80492df:	90                   	nop

080492e0 <register_tm_clones>:
 80492e0:	b8 74 d2 04 08       	mov    $0x804d274,%eax
 80492e5:	2d 74 d2 04 08       	sub    $0x804d274,%eax
 80492ea:	89 c2                	mov    %eax,%edx
 80492ec:	c1 e8 1f             	shr    $0x1f,%eax
 80492ef:	c1 fa 02             	sar    $0x2,%edx
 80492f2:	01 d0                	add    %edx,%eax
 80492f4:	d1 f8                	sar    %eax
 80492f6:	74 20                	je     8049318 <register_tm_clones+0x38>
 80492f8:	ba 00 00 00 00       	mov    $0x0,%edx
 80492fd:	85 d2                	test   %edx,%edx
 80492ff:	74 17                	je     8049318 <register_tm_clones+0x38>
 8049301:	55                   	push   %ebp
 8049302:	89 e5                	mov    %esp,%ebp
 8049304:	83 ec 10             	sub    $0x10,%esp
 8049307:	50                   	push   %eax
 8049308:	68 74 d2 04 08       	push   $0x804d274
 804930d:	ff d2                	call   *%edx
 804930f:	83 c4 10             	add    $0x10,%esp
 8049312:	c9                   	leave  
 8049313:	c3                   	ret    
 8049314:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi
 8049318:	c3                   	ret    
 8049319:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

08049320 <__do_global_dtors_aux>:
 8049320:	f3 0f 1e fb          	endbr32 
 8049324:	80 3d 88 d2 04 08 00 	cmpb   $0x0,0x804d288
 804932b:	75 1b                	jne    8049348 <__do_global_dtors_aux+0x28>
 804932d:	55                   	push   %ebp
 804932e:	89 e5                	mov    %esp,%ebp
 8049330:	83 ec 08             	sub    $0x8,%esp
 8049333:	e8 68 ff ff ff       	call   80492a0 <deregister_tm_clones>
 8049338:	c6 05 88 d2 04 08 01 	movb   $0x1,0x804d288
 804933f:	c9                   	leave  
 8049340:	c3                   	ret    
 8049341:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 8049348:	c3                   	ret    
 8049349:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi

08049350 <frame_dummy>:
 8049350:	f3 0f 1e fb          	endbr32 
 8049354:	eb 8a                	jmp    80492e0 <register_tm_clones>

08049356 <main>:
 8049356:	f3 0f 1e fb          	endbr32 
 804935a:	8d 4c 24 04          	lea    0x4(%esp),%ecx
 804935e:	83 e4 f0             	and    $0xfffffff0,%esp
 8049361:	ff 71 fc             	pushl  -0x4(%ecx)
 8049364:	55                   	push   %ebp
 8049365:	89 e5                	mov    %esp,%ebp
 8049367:	53                   	push   %ebx
 8049368:	51                   	push   %ecx
 8049369:	83 ec 10             	sub    $0x10,%esp
 804936c:	89 cb                	mov    %ecx,%ebx
 804936e:	83 3b 01             	cmpl   $0x1,(%ebx)
 8049371:	75 0c                	jne    804937f <main+0x29>
 8049373:	a1 80 d2 04 08       	mov    0x804d280,%eax
 8049378:	a3 90 d2 04 08       	mov    %eax,0x804d290
 804937d:	eb 75                	jmp    80493f4 <main+0x9e>
 804937f:	83 3b 02             	cmpl   $0x2,(%ebx)
 8049382:	75 50                	jne    80493d4 <main+0x7e>
 8049384:	8b 43 04             	mov    0x4(%ebx),%eax
 8049387:	83 c0 04             	add    $0x4,%eax
 804938a:	8b 00                	mov    (%eax),%eax
 804938c:	83 ec 08             	sub    $0x8,%esp
 804938f:	68 08 b0 04 08       	push   $0x804b008
 8049394:	50                   	push   %eax
 8049395:	e8 66 fe ff ff       	call   8049200 <fopen@plt>
 804939a:	83 c4 10             	add    $0x10,%esp
 804939d:	a3 90 d2 04 08       	mov    %eax,0x804d290
 80493a2:	a1 90 d2 04 08       	mov    0x804d290,%eax
 80493a7:	85 c0                	test   %eax,%eax
 80493a9:	75 49                	jne    80493f4 <main+0x9e>
 80493ab:	8b 43 04             	mov    0x4(%ebx),%eax
 80493ae:	83 c0 04             	add    $0x4,%eax
 80493b1:	8b 10                	mov    (%eax),%edx
 80493b3:	8b 43 04             	mov    0x4(%ebx),%eax
 80493b6:	8b 00                	mov    (%eax),%eax
 80493b8:	83 ec 04             	sub    $0x4,%esp
 80493bb:	52                   	push   %edx
 80493bc:	50                   	push   %eax
 80493bd:	68 0a b0 04 08       	push   $0x804b00a
 80493c2:	e8 79 fd ff ff       	call   8049140 <printf@plt>
 80493c7:	83 c4 10             	add    $0x10,%esp
 80493ca:	83 ec 0c             	sub    $0xc,%esp
 80493cd:	6a 08                	push   $0x8
 80493cf:	e8 ec fd ff ff       	call   80491c0 <exit@plt>
 80493d4:	8b 43 04             	mov    0x4(%ebx),%eax
 80493d7:	8b 00                	mov    (%eax),%eax
 80493d9:	83 ec 08             	sub    $0x8,%esp
 80493dc:	50                   	push   %eax
 80493dd:	68 27 b0 04 08       	push   $0x804b027
 80493e2:	e8 59 fd ff ff       	call   8049140 <printf@plt>
 80493e7:	83 c4 10             	add    $0x10,%esp
 80493ea:	83 ec 0c             	sub    $0xc,%esp
 80493ed:	6a 08                	push   $0x8
 80493ef:	e8 cc fd ff ff       	call   80491c0 <exit@plt>
 80493f4:	e8 0d 0a 00 00       	call   8049e06 <initialize_bomb>
 80493f9:	83 ec 0c             	sub    $0xc,%esp
 80493fc:	68 44 b0 04 08       	push   $0x804b044
 8049401:	e8 aa fd ff ff       	call   80491b0 <puts@plt>
 8049406:	83 c4 10             	add    $0x10,%esp
 8049409:	83 ec 0c             	sub    $0xc,%esp
 804940c:	68 80 b0 04 08       	push   $0x804b080
 8049411:	e8 9a fd ff ff       	call   80491b0 <puts@plt>
 8049416:	83 c4 10             	add    $0x10,%esp
 8049419:	e8 b2 0a 00 00       	call   8049ed0 <read_line>
 804941e:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049421:	83 ec 0c             	sub    $0xc,%esp
 8049424:	ff 75 f4             	pushl  -0xc(%ebp)
 8049427:	e8 5b 01 00 00       	call   8049587 <phase_0>
 804942c:	83 c4 10             	add    $0x10,%esp
 804942f:	85 c0                	test   %eax,%eax
 8049431:	74 15                	je     8049448 <main+0xf2>
 8049433:	e8 0c 0c 00 00       	call   804a044 <phase_defused>
 8049438:	83 ec 0c             	sub    $0xc,%esp
 804943b:	68 ac b0 04 08       	push   $0x804b0ac
 8049440:	e8 6b fd ff ff       	call   80491b0 <puts@plt>
 8049445:	83 c4 10             	add    $0x10,%esp
 8049448:	e8 83 0a 00 00       	call   8049ed0 <read_line>
 804944d:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049450:	83 ec 0c             	sub    $0xc,%esp
 8049453:	ff 75 f4             	pushl  -0xc(%ebp)
 8049456:	e8 60 01 00 00       	call   80495bb <phase_1>
 804945b:	83 c4 10             	add    $0x10,%esp
 804945e:	85 c0                	test   %eax,%eax
 8049460:	74 15                	je     8049477 <main+0x121>
 8049462:	e8 dd 0b 00 00       	call   804a044 <phase_defused>
 8049467:	83 ec 0c             	sub    $0xc,%esp
 804946a:	68 d4 b0 04 08       	push   $0x804b0d4
 804946f:	e8 3c fd ff ff       	call   80491b0 <puts@plt>
 8049474:	83 c4 10             	add    $0x10,%esp
 8049477:	e8 54 0a 00 00       	call   8049ed0 <read_line>
 804947c:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804947f:	83 ec 0c             	sub    $0xc,%esp
 8049482:	ff 75 f4             	pushl  -0xc(%ebp)
 8049485:	e8 c9 01 00 00       	call   8049653 <phase_2>
 804948a:	83 c4 10             	add    $0x10,%esp
 804948d:	85 c0                	test   %eax,%eax
 804948f:	74 15                	je     80494a6 <main+0x150>
 8049491:	e8 ae 0b 00 00       	call   804a044 <phase_defused>
 8049496:	83 ec 0c             	sub    $0xc,%esp
 8049499:	68 fd b0 04 08       	push   $0x804b0fd
 804949e:	e8 0d fd ff ff       	call   80491b0 <puts@plt>
 80494a3:	83 c4 10             	add    $0x10,%esp
 80494a6:	e8 25 0a 00 00       	call   8049ed0 <read_line>
 80494ab:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80494ae:	83 ec 0c             	sub    $0xc,%esp
 80494b1:	ff 75 f4             	pushl  -0xc(%ebp)
 80494b4:	e8 40 02 00 00       	call   80496f9 <phase_3>
 80494b9:	83 c4 10             	add    $0x10,%esp
 80494bc:	85 c0                	test   %eax,%eax
 80494be:	74 15                	je     80494d5 <main+0x17f>
 80494c0:	e8 7f 0b 00 00       	call   804a044 <phase_defused>
 80494c5:	83 ec 0c             	sub    $0xc,%esp
 80494c8:	68 1b b1 04 08       	push   $0x804b11b
 80494cd:	e8 de fc ff ff       	call   80491b0 <puts@plt>
 80494d2:	83 c4 10             	add    $0x10,%esp
 80494d5:	e8 f6 09 00 00       	call   8049ed0 <read_line>
 80494da:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80494dd:	83 ec 0c             	sub    $0xc,%esp
 80494e0:	ff 75 f4             	pushl  -0xc(%ebp)
 80494e3:	e8 3c 03 00 00       	call   8049824 <phase_4>
 80494e8:	83 c4 10             	add    $0x10,%esp
 80494eb:	85 c0                	test   %eax,%eax
 80494ed:	74 15                	je     8049504 <main+0x1ae>
 80494ef:	e8 50 0b 00 00       	call   804a044 <phase_defused>
 80494f4:	83 ec 0c             	sub    $0xc,%esp
 80494f7:	68 2c b1 04 08       	push   $0x804b12c
 80494fc:	e8 af fc ff ff       	call   80491b0 <puts@plt>
 8049501:	83 c4 10             	add    $0x10,%esp
 8049504:	e8 c7 09 00 00       	call   8049ed0 <read_line>
 8049509:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804950c:	83 ec 0c             	sub    $0xc,%esp
 804950f:	ff 75 f4             	pushl  -0xc(%ebp)
 8049512:	e8 9b 03 00 00       	call   80498b2 <phase_5>
 8049517:	83 c4 10             	add    $0x10,%esp
 804951a:	85 c0                	test   %eax,%eax
 804951c:	74 15                	je     8049533 <main+0x1dd>
 804951e:	e8 21 0b 00 00       	call   804a044 <phase_defused>
 8049523:	83 ec 0c             	sub    $0xc,%esp
 8049526:	68 50 b1 04 08       	push   $0x804b150
 804952b:	e8 80 fc ff ff       	call   80491b0 <puts@plt>
 8049530:	83 c4 10             	add    $0x10,%esp
 8049533:	e8 98 09 00 00       	call   8049ed0 <read_line>
 8049538:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804953b:	83 ec 0c             	sub    $0xc,%esp
 804953e:	ff 75 f4             	pushl  -0xc(%ebp)
 8049541:	e8 1f 04 00 00       	call   8049965 <phase_6>
 8049546:	83 c4 10             	add    $0x10,%esp
 8049549:	85 c0                	test   %eax,%eax
 804954b:	74 05                	je     8049552 <main+0x1fc>
 804954d:	e8 f2 0a 00 00       	call   804a044 <phase_defused>
 8049552:	b8 00 00 00 00       	mov    $0x0,%eax
 8049557:	8d 65 f8             	lea    -0x8(%ebp),%esp
 804955a:	59                   	pop    %ecx
 804955b:	5b                   	pop    %ebx
 804955c:	5d                   	pop    %ebp
 804955d:	8d 61 fc             	lea    -0x4(%ecx),%esp
 8049560:	c3                   	ret    

08049561 <lwiJZUXo>:
 8049561:	f3 0f 1e fb          	endbr32 
 8049565:	55                   	push   %ebp
 8049566:	89 e5                	mov    %esp,%ebp
 8049568:	8b 55 08             	mov    0x8(%ebp),%edx
 804956b:	8b 45 0c             	mov    0xc(%ebp),%eax
 804956e:	01 c2                	add    %eax,%edx
 8049570:	8b 45 08             	mov    0x8(%ebp),%eax
 8049573:	0f af c0             	imul   %eax,%eax
 8049576:	89 c1                	mov    %eax,%ecx
 8049578:	8b 45 0c             	mov    0xc(%ebp),%eax
 804957b:	0f af c0             	imul   %eax,%eax
 804957e:	01 c1                	add    %eax,%ecx
 8049580:	89 d0                	mov    %edx,%eax
 8049582:	99                   	cltd   
 8049583:	f7 f9                	idiv   %ecx
 8049585:	5d                   	pop    %ebp
 8049586:	c3                   	ret    

08049587 <phase_0>:
 8049587:	f3 0f 1e fb          	endbr32 
 804958b:	55                   	push   %ebp
 804958c:	89 e5                	mov    %esp,%ebp
 804958e:	83 ec 08             	sub    $0x8,%esp
 8049591:	83 ec 08             	sub    $0x8,%esp
 8049594:	68 ec b1 04 08       	push   $0x804b1ec
 8049599:	ff 75 08             	pushl  0x8(%ebp)
 804959c:	e8 f6 07 00 00       	call   8049d97 <strings_not_equal>
 80495a1:	83 c4 10             	add    $0x10,%esp
 80495a4:	85 c0                	test   %eax,%eax
 80495a6:	74 0c                	je     80495b4 <phase_0+0x2d>
 80495a8:	e8 6a 0a 00 00       	call   804a017 <explode_bomb>
 80495ad:	b8 00 00 00 00       	mov    $0x0,%eax
 80495b2:	eb 05                	jmp    80495b9 <phase_0+0x32>
 80495b4:	b8 01 00 00 00       	mov    $0x1,%eax
 80495b9:	c9                   	leave  
 80495ba:	c3                   	ret    

080495bb <phase_1>:
 80495bb:	f3 0f 1e fb          	endbr32 
 80495bf:	55                   	push   %ebp
 80495c0:	89 e5                	mov    %esp,%ebp
 80495c2:	83 ec 38             	sub    $0x38,%esp
 80495c5:	8b 45 08             	mov    0x8(%ebp),%eax
 80495c8:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 80495cb:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 80495d1:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80495d4:	31 c0                	xor    %eax,%eax
 80495d6:	c7 45 f0 66 75 27 0b 	movl   $0xb277566,-0x10(%ebp)
 80495dd:	db 45 f0             	fildl  -0x10(%ebp)
 80495e0:	d9 5d e4             	fstps  -0x1c(%ebp)
 80495e3:	8d 45 ec             	lea    -0x14(%ebp),%eax
 80495e6:	50                   	push   %eax
 80495e7:	8d 45 e8             	lea    -0x18(%ebp),%eax
 80495ea:	50                   	push   %eax
 80495eb:	68 11 b2 04 08       	push   $0x804b211
 80495f0:	ff 75 d4             	pushl  -0x2c(%ebp)
 80495f3:	e8 f8 fb ff ff       	call   80491f0 <__isoc99_sscanf@plt>
 80495f8:	83 c4 10             	add    $0x10,%esp
 80495fb:	83 f8 02             	cmp    $0x2,%eax
 80495fe:	74 0c                	je     804960c <phase_1+0x51>
 8049600:	e8 12 0a 00 00       	call   804a017 <explode_bomb>
 8049605:	b8 00 00 00 00       	mov    $0x0,%eax
 804960a:	eb 34                	jmp    8049640 <phase_1+0x85>
 804960c:	8d 45 e4             	lea    -0x1c(%ebp),%eax
 804960f:	0f b7 00             	movzwl (%eax),%eax
 8049612:	0f bf d0             	movswl %ax,%edx
 8049615:	8b 45 e8             	mov    -0x18(%ebp),%eax
 8049618:	39 c2                	cmp    %eax,%edx
 804961a:	75 13                	jne    804962f <phase_1+0x74>
 804961c:	8d 45 e4             	lea    -0x1c(%ebp),%eax
 804961f:	83 c0 02             	add    $0x2,%eax
 8049622:	0f b7 00             	movzwl (%eax),%eax
 8049625:	0f bf d0             	movswl %ax,%edx
 8049628:	8b 45 ec             	mov    -0x14(%ebp),%eax
 804962b:	39 c2                	cmp    %eax,%edx
 804962d:	74 0c                	je     804963b <phase_1+0x80>
 804962f:	e8 e3 09 00 00       	call   804a017 <explode_bomb>
 8049634:	b8 00 00 00 00       	mov    $0x0,%eax
 8049639:	eb 05                	jmp    8049640 <phase_1+0x85>
 804963b:	b8 01 00 00 00       	mov    $0x1,%eax
 8049640:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049643:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 804964a:	74 05                	je     8049651 <phase_1+0x96>
 804964c:	e8 3f fb ff ff       	call   8049190 <__stack_chk_fail@plt>
 8049651:	c9                   	leave  
 8049652:	c3                   	ret    

08049653 <phase_2>:
 8049653:	f3 0f 1e fb          	endbr32 
 8049657:	55                   	push   %ebp
 8049658:	89 e5                	mov    %esp,%ebp
 804965a:	83 ec 48             	sub    $0x48,%esp
 804965d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049660:	89 45 c4             	mov    %eax,-0x3c(%ebp)
 8049663:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 8049669:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804966c:	31 c0                	xor    %eax,%eax
 804966e:	83 ec 04             	sub    $0x4,%esp
 8049671:	6a 09                	push   $0x9
 8049673:	8d 45 d0             	lea    -0x30(%ebp),%eax
 8049676:	50                   	push   %eax
 8049677:	ff 75 c4             	pushl  -0x3c(%ebp)
 804967a:	e8 56 06 00 00       	call   8049cd5 <read_n_numbers>
 804967f:	83 c4 10             	add    $0x10,%esp
 8049682:	85 c0                	test   %eax,%eax
 8049684:	75 07                	jne    804968d <phase_2+0x3a>
 8049686:	b8 00 00 00 00       	mov    $0x0,%eax
 804968b:	eb 59                	jmp    80496e6 <phase_2+0x93>
 804968d:	8b 45 d0             	mov    -0x30(%ebp),%eax
 8049690:	3d 90 00 00 00       	cmp    $0x90,%eax
 8049695:	74 0c                	je     80496a3 <phase_2+0x50>
 8049697:	e8 7b 09 00 00       	call   804a017 <explode_bomb>
 804969c:	b8 00 00 00 00       	mov    $0x0,%eax
 80496a1:	eb 43                	jmp    80496e6 <phase_2+0x93>
 80496a3:	c7 45 cc 01 00 00 00 	movl   $0x1,-0x34(%ebp)
 80496aa:	eb 2f                	jmp    80496db <phase_2+0x88>
 80496ac:	8b 45 cc             	mov    -0x34(%ebp),%eax
 80496af:	8b 44 85 d0          	mov    -0x30(%ebp,%eax,4),%eax
 80496b3:	8b 55 cc             	mov    -0x34(%ebp),%edx
 80496b6:	83 ea 01             	sub    $0x1,%edx
 80496b9:	8b 54 95 d0          	mov    -0x30(%ebp,%edx,4),%edx
 80496bd:	8b 4d cc             	mov    -0x34(%ebp),%ecx
 80496c0:	01 c9                	add    %ecx,%ecx
 80496c2:	29 ca                	sub    %ecx,%edx
 80496c4:	83 c2 01             	add    $0x1,%edx
 80496c7:	39 d0                	cmp    %edx,%eax
 80496c9:	74 0c                	je     80496d7 <phase_2+0x84>
 80496cb:	e8 47 09 00 00       	call   804a017 <explode_bomb>
 80496d0:	b8 00 00 00 00       	mov    $0x0,%eax
 80496d5:	eb 0f                	jmp    80496e6 <phase_2+0x93>
 80496d7:	83 45 cc 01          	addl   $0x1,-0x34(%ebp)
 80496db:	83 7d cc 08          	cmpl   $0x8,-0x34(%ebp)
 80496df:	7e cb                	jle    80496ac <phase_2+0x59>
 80496e1:	b8 01 00 00 00       	mov    $0x1,%eax
 80496e6:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 80496e9:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 80496f0:	74 05                	je     80496f7 <phase_2+0xa4>
 80496f2:	e8 99 fa ff ff       	call   8049190 <__stack_chk_fail@plt>
 80496f7:	c9                   	leave  
 80496f8:	c3                   	ret    

080496f9 <phase_3>:
 80496f9:	f3 0f 1e fb          	endbr32 
 80496fd:	55                   	push   %ebp
 80496fe:	89 e5                	mov    %esp,%ebp
 8049700:	83 ec 38             	sub    $0x38,%esp
 8049703:	8b 45 08             	mov    0x8(%ebp),%eax
 8049706:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 8049709:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804970f:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049712:	31 c0                	xor    %eax,%eax
 8049714:	8d 45 e8             	lea    -0x18(%ebp),%eax
 8049717:	50                   	push   %eax
 8049718:	8d 45 e4             	lea    -0x1c(%ebp),%eax
 804971b:	50                   	push   %eax
 804971c:	68 11 b2 04 08       	push   $0x804b211
 8049721:	ff 75 d4             	pushl  -0x2c(%ebp)
 8049724:	e8 c7 fa ff ff       	call   80491f0 <__isoc99_sscanf@plt>
 8049729:	83 c4 10             	add    $0x10,%esp
 804972c:	89 45 f0             	mov    %eax,-0x10(%ebp)
 804972f:	83 7d f0 01          	cmpl   $0x1,-0x10(%ebp)
 8049733:	7f 0c                	jg     8049741 <phase_3+0x48>
 8049735:	e8 dd 08 00 00       	call   804a017 <explode_bomb>
 804973a:	b8 00 00 00 00       	mov    $0x0,%eax
 804973f:	eb 7c                	jmp    80497bd <phase_3+0xc4>
 8049741:	c7 45 ec 00 00 00 00 	movl   $0x0,-0x14(%ebp)
 8049748:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 804974b:	83 e8 25             	sub    $0x25,%eax
 804974e:	83 f8 08             	cmp    $0x8,%eax
 8049751:	77 45                	ja     8049798 <phase_3+0x9f>
 8049753:	8b 04 85 18 b2 04 08 	mov    0x804b218(,%eax,4),%eax
 804975a:	3e ff e0             	notrack jmp *%eax
 804975d:	83 45 ec 78          	addl   $0x78,-0x14(%ebp)
 8049761:	81 45 ec 24 03 00 00 	addl   $0x324,-0x14(%ebp)
 8049768:	83 6d ec 78          	subl   $0x78,-0x14(%ebp)
 804976c:	83 45 ec 78          	addl   $0x78,-0x14(%ebp)
 8049770:	81 45 ec 24 03 00 00 	addl   $0x324,-0x14(%ebp)
 8049777:	83 6d ec 78          	subl   $0x78,-0x14(%ebp)
 804977b:	81 45 ec 24 03 00 00 	addl   $0x324,-0x14(%ebp)
 8049782:	81 6d ec 24 03 00 00 	subl   $0x324,-0x14(%ebp)
 8049789:	83 45 ec 78          	addl   $0x78,-0x14(%ebp)
 804978d:	90                   	nop
 804978e:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 8049791:	83 f8 2b             	cmp    $0x2b,%eax
 8049794:	7f 16                	jg     80497ac <phase_3+0xb3>
 8049796:	eb 0c                	jmp    80497a4 <phase_3+0xab>
 8049798:	e8 7a 08 00 00       	call   804a017 <explode_bomb>
 804979d:	b8 00 00 00 00       	mov    $0x0,%eax
 80497a2:	eb 19                	jmp    80497bd <phase_3+0xc4>
 80497a4:	8b 45 e8             	mov    -0x18(%ebp),%eax
 80497a7:	39 45 ec             	cmp    %eax,-0x14(%ebp)
 80497aa:	74 0c                	je     80497b8 <phase_3+0xbf>
 80497ac:	e8 66 08 00 00       	call   804a017 <explode_bomb>
 80497b1:	b8 00 00 00 00       	mov    $0x0,%eax
 80497b6:	eb 05                	jmp    80497bd <phase_3+0xc4>
 80497b8:	b8 01 00 00 00       	mov    $0x1,%eax
 80497bd:	8b 55 f4             	mov    -0xc(%ebp),%edx
 80497c0:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
 80497c7:	74 05                	je     80497ce <phase_3+0xd5>
 80497c9:	e8 c2 f9 ff ff       	call   8049190 <__stack_chk_fail@plt>
 80497ce:	c9                   	leave  
 80497cf:	c3                   	ret    

080497d0 <func4>:
 80497d0:	f3 0f 1e fb          	endbr32 
 80497d4:	55                   	push   %ebp
 80497d5:	89 e5                	mov    %esp,%ebp
 80497d7:	53                   	push   %ebx
 80497d8:	83 ec 04             	sub    $0x4,%esp
 80497db:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 80497df:	7f 07                	jg     80497e8 <func4+0x18>
 80497e1:	b8 0c 00 00 00       	mov    $0xc,%eax
 80497e6:	eb 37                	jmp    804981f <func4+0x4f>
 80497e8:	83 7d 08 01          	cmpl   $0x1,0x8(%ebp)
 80497ec:	75 07                	jne    80497f5 <func4+0x25>
 80497ee:	b8 13 00 00 00       	mov    $0x13,%eax
 80497f3:	eb 2a                	jmp    804981f <func4+0x4f>
 80497f5:	8b 45 08             	mov    0x8(%ebp),%eax
 80497f8:	83 e8 01             	sub    $0x1,%eax
 80497fb:	83 ec 0c             	sub    $0xc,%esp
 80497fe:	50                   	push   %eax
 80497ff:	e8 cc ff ff ff       	call   80497d0 <func4>
 8049804:	83 c4 10             	add    $0x10,%esp
 8049807:	89 c3                	mov    %eax,%ebx
 8049809:	8b 45 08             	mov    0x8(%ebp),%eax
 804980c:	83 e8 02             	sub    $0x2,%eax
 804980f:	83 ec 0c             	sub    $0xc,%esp
 8049812:	50                   	push   %eax
 8049813:	e8 b8 ff ff ff       	call   80497d0 <func4>
 8049818:	83 c4 10             	add    $0x10,%esp
 804981b:	d1 f8                	sar    %eax
 804981d:	01 d8                	add    %ebx,%eax
 804981f:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 8049822:	c9                   	leave  
 8049823:	c3                   	ret    

08049824 <phase_4>:
 8049824:	f3 0f 1e fb          	endbr32 
 8049828:	55                   	push   %ebp
 8049829:	89 e5                	mov    %esp,%ebp
 804982b:	83 ec 38             	sub    $0x38,%esp
 804982e:	8b 45 08             	mov    0x8(%ebp),%eax
 8049831:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 8049834:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804983a:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804983d:	31 c0                	xor    %eax,%eax
 804983f:	8d 45 e8             	lea    -0x18(%ebp),%eax
 8049842:	50                   	push   %eax
 8049843:	8d 45 e4             	lea    -0x1c(%ebp),%eax
 8049846:	50                   	push   %eax
 8049847:	68 11 b2 04 08       	push   $0x804b211
 804984c:	ff 75 d4             	pushl  -0x2c(%ebp)
 804984f:	e8 9c f9 ff ff       	call   80491f0 <__isoc99_sscanf@plt>
 8049854:	83 c4 10             	add    $0x10,%esp
 8049857:	89 45 ec             	mov    %eax,-0x14(%ebp)
 804985a:	83 7d ec 02          	cmpl   $0x2,-0x14(%ebp)
 804985e:	75 08                	jne    8049868 <phase_4+0x44>
 8049860:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 8049863:	83 f8 07             	cmp    $0x7,%eax
 8049866:	7f 0c                	jg     8049874 <phase_4+0x50>
 8049868:	e8 aa 07 00 00       	call   804a017 <explode_bomb>
 804986d:	b8 00 00 00 00       	mov    $0x0,%eax
 8049872:	eb 2b                	jmp    804989f <phase_4+0x7b>
 8049874:	8b 45 e4             	mov    -0x1c(%ebp),%eax
 8049877:	83 ec 0c             	sub    $0xc,%esp
 804987a:	50                   	push   %eax
 804987b:	e8 50 ff ff ff       	call   80497d0 <func4>
 8049880:	83 c4 10             	add    $0x10,%esp
 8049883:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049886:	8b 45 e8             	mov    -0x18(%ebp),%eax
 8049889:	39 45 f0             	cmp    %eax,-0x10(%ebp)
 804988c:	74 0c                	je     804989a <phase_4+0x76>
 804988e:	e8 84 07 00 00       	call   804a017 <explode_bomb>
 8049893:	b8 00 00 00 00       	mov    $0x0,%eax
 8049898:	eb 05                	jmp    804989f <phase_4+0x7b>
 804989a:	b8 01 00 00 00       	mov    $0x1,%eax
 804989f:	8b 55 f4             	mov    -0xc(%ebp),%edx
 80498a2:	65 33 15 14 00 00 00 	xor    %gs:0x14,%edx
 80498a9:	74 05                	je     80498b0 <phase_4+0x8c>
 80498ab:	e8 e0 f8 ff ff       	call   8049190 <__stack_chk_fail@plt>
 80498b0:	c9                   	leave  
 80498b1:	c3                   	ret    

080498b2 <phase_5>:
 80498b2:	f3 0f 1e fb          	endbr32 
 80498b6:	55                   	push   %ebp
 80498b7:	89 e5                	mov    %esp,%ebp
 80498b9:	83 ec 38             	sub    $0x38,%esp
 80498bc:	8b 45 08             	mov    0x8(%ebp),%eax
 80498bf:	89 45 d4             	mov    %eax,-0x2c(%ebp)
 80498c2:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 80498c8:	89 45 f4             	mov    %eax,-0xc(%ebp)
 80498cb:	31 c0                	xor    %eax,%eax
 80498cd:	83 ec 0c             	sub    $0xc,%esp
 80498d0:	ff 75 d4             	pushl  -0x2c(%ebp)
 80498d3:	e8 8f 04 00 00       	call   8049d67 <string_length>
 80498d8:	83 c4 10             	add    $0x10,%esp
 80498db:	89 45 e8             	mov    %eax,-0x18(%ebp)
 80498de:	83 7d e8 06          	cmpl   $0x6,-0x18(%ebp)
 80498e2:	74 0c                	je     80498f0 <phase_5+0x3e>
 80498e4:	e8 2e 07 00 00       	call   804a017 <explode_bomb>
 80498e9:	b8 00 00 00 00       	mov    $0x0,%eax
 80498ee:	eb 62                	jmp    8049952 <phase_5+0xa0>
 80498f0:	c7 45 e4 00 00 00 00 	movl   $0x0,-0x1c(%ebp)
 80498f7:	eb 26                	jmp    804991f <phase_5+0x6d>
 80498f9:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 80498fc:	8b 45 d4             	mov    -0x2c(%ebp),%eax
 80498ff:	01 d0                	add    %edx,%eax
 8049901:	0f b6 00             	movzbl (%eax),%eax
 8049904:	0f be c0             	movsbl %al,%eax
 8049907:	83 e0 0f             	and    $0xf,%eax
 804990a:	0f b6 80 64 d2 04 08 	movzbl 0x804d264(%eax),%eax
 8049911:	8d 4d ed             	lea    -0x13(%ebp),%ecx
 8049914:	8b 55 e4             	mov    -0x1c(%ebp),%edx
 8049917:	01 ca                	add    %ecx,%edx
 8049919:	88 02                	mov    %al,(%edx)
 804991b:	83 45 e4 01          	addl   $0x1,-0x1c(%ebp)
 804991f:	83 7d e4 05          	cmpl   $0x5,-0x1c(%ebp)
 8049923:	7e d4                	jle    80498f9 <phase_5+0x47>
 8049925:	c6 45 f3 00          	movb   $0x0,-0xd(%ebp)
 8049929:	83 ec 08             	sub    $0x8,%esp
 804992c:	68 3c b2 04 08       	push   $0x804b23c
 8049931:	8d 45 ed             	lea    -0x13(%ebp),%eax
 8049934:	50                   	push   %eax
 8049935:	e8 5d 04 00 00       	call   8049d97 <strings_not_equal>
 804993a:	83 c4 10             	add    $0x10,%esp
 804993d:	85 c0                	test   %eax,%eax
 804993f:	74 0c                	je     804994d <phase_5+0x9b>
 8049941:	e8 d1 06 00 00       	call   804a017 <explode_bomb>
 8049946:	b8 00 00 00 00       	mov    $0x0,%eax
 804994b:	eb 05                	jmp    8049952 <phase_5+0xa0>
 804994d:	b8 01 00 00 00       	mov    $0x1,%eax
 8049952:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049955:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 804995c:	74 05                	je     8049963 <phase_5+0xb1>
 804995e:	e8 2d f8 ff ff       	call   8049190 <__stack_chk_fail@plt>
 8049963:	c9                   	leave  
 8049964:	c3                   	ret    

08049965 <phase_6>:
 8049965:	f3 0f 1e fb          	endbr32 
 8049969:	55                   	push   %ebp
 804996a:	89 e5                	mov    %esp,%ebp
 804996c:	83 ec 68             	sub    $0x68,%esp
 804996f:	8b 45 08             	mov    0x8(%ebp),%eax
 8049972:	89 45 a4             	mov    %eax,-0x5c(%ebp)
 8049975:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804997b:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804997e:	31 c0                	xor    %eax,%eax
 8049980:	c7 45 b8 a4 d1 04 08 	movl   $1,-0x48(%ebp)
 8049987:	83 ec 04             	sub    $0x4,%esp
 804998a:	6a 07                	push   $0x7
 804998c:	8d 45 bc             	lea    -0x44(%ebp),%eax
 804998f:	50                   	push   %eax
 8049990:	ff 75 a4             	pushl  -0x5c(%ebp)
 8049993:	e8 3d 03 00 00       	call   8049cd5 <read_n_numbers>
 8049998:	83 c4 10             	add    $0x10,%esp
 804999b:	85 c0                	test   %eax,%eax
 804999d:	75 0a                	jne    80499a9 <phase_6+0x44>
 804999f:	b8 00 00 00 00       	mov    $0x0,%eax
 80499a4:	e9 37 01 00 00       	jmp    8049ae0 <phase_6+0x17b>
 80499a9:	c7 45 b0 00 00 00 00 	movl   $0x0,-0x50(%ebp)
 80499b0:	eb 60                	jmp    8049a12 <phase_6+0xad>
 80499b2:	8b 45 b0             	mov    -0x50(%ebp),%eax
 80499b5:	8b 44 85 bc          	mov    -0x44(%ebp,%eax,4),%eax
 80499b9:	85 c0                	test   %eax,%eax
 80499bb:	7e 0c                	jle    80499c9 <phase_6+0x64>
 80499bd:	8b 45 b0             	mov    -0x50(%ebp),%eax
 80499c0:	8b 44 85 bc          	mov    -0x44(%ebp,%eax,4),%eax
 80499c4:	83 f8 07             	cmp    $0x7,%eax
 80499c7:	7e 0f                	jle    80499d8 <phase_6+0x73>
 80499c9:	e8 49 06 00 00       	call   804a017 <explode_bomb>
 80499ce:	b8 00 00 00 00       	mov    $0x0,%eax
 80499d3:	e9 08 01 00 00       	jmp    8049ae0 <phase_6+0x17b>
 80499d8:	8b 45 b0             	mov    -0x50(%ebp),%eax
 80499db:	83 c0 01             	add    $0x1,%eax
 80499de:	89 45 b4             	mov    %eax,-0x4c(%ebp)
 80499e1:	eb 25                	jmp    8049a08 <phase_6+0xa3>
 80499e3:	8b 45 b0             	mov    -0x50(%ebp),%eax
 80499e6:	8b 54 85 bc          	mov    -0x44(%ebp,%eax,4),%edx
 80499ea:	8b 45 b4             	mov    -0x4c(%ebp),%eax
 80499ed:	8b 44 85 bc          	mov    -0x44(%ebp,%eax,4),%eax
 80499f1:	39 c2                	cmp    %eax,%edx
 80499f3:	75 0f                	jne    8049a04 <phase_6+0x9f>
 80499f5:	e8 1d 06 00 00       	call   804a017 <explode_bomb>
 80499fa:	b8 00 00 00 00       	mov    $0x0,%eax
 80499ff:	e9 dc 00 00 00       	jmp    8049ae0 <phase_6+0x17b>
 8049a04:	83 45 b4 01          	addl   $0x1,-0x4c(%ebp)
 8049a08:	83 7d b4 06          	cmpl   $0x6,-0x4c(%ebp)
 8049a0c:	7e d5                	jle    80499e3 <phase_6+0x7e>
 8049a0e:	83 45 b0 01          	addl   $0x1,-0x50(%ebp)
 8049a12:	83 7d b0 06          	cmpl   $0x6,-0x50(%ebp)
 8049a16:	7e 9a                	jle    80499b2 <phase_6+0x4d>
 8049a18:	c7 45 b0 00 00 00 00 	movl   $0x0,-0x50(%ebp)
 8049a1f:	eb 36                	jmp    8049a57 <phase_6+0xf2>
 8049a21:	8b 45 b8             	mov    -0x48(%ebp),%eax
 8049a24:	89 45 ac             	mov    %eax,-0x54(%ebp)
 8049a27:	c7 45 b4 01 00 00 00 	movl   $0x1,-0x4c(%ebp)
 8049a2e:	eb 0d                	jmp    8049a3d <phase_6+0xd8>
 8049a30:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049a33:	8b 40 08             	mov    0x8(%eax),%eax
 8049a36:	89 45 ac             	mov    %eax,-0x54(%ebp)
 8049a39:	83 45 b4 01          	addl   $0x1,-0x4c(%ebp)
 8049a3d:	8b 45 b0             	mov    -0x50(%ebp),%eax
 8049a40:	8b 44 85 bc          	mov    -0x44(%ebp,%eax,4),%eax
 8049a44:	39 45 b4             	cmp    %eax,-0x4c(%ebp)
 8049a47:	7c e7                	jl     8049a30 <phase_6+0xcb>
 8049a49:	8b 45 b0             	mov    -0x50(%ebp),%eax
 8049a4c:	8b 55 ac             	mov    -0x54(%ebp),%edx
 8049a4f:	89 54 85 d8          	mov    %edx,-0x28(%ebp,%eax,4)
 8049a53:	83 45 b0 01          	addl   $0x1,-0x50(%ebp)
 8049a57:	83 7d b0 06          	cmpl   $0x6,-0x50(%ebp)
 8049a5b:	7e c4                	jle    8049a21 <phase_6+0xbc>
 8049a5d:	8b 45 d8             	mov    -0x28(%ebp),%eax
 8049a60:	89 45 b8             	mov    %eax,-0x48(%ebp)
 8049a63:	8b 45 b8             	mov    -0x48(%ebp),%eax
 8049a66:	89 45 ac             	mov    %eax,-0x54(%ebp)
 8049a69:	c7 45 b0 01 00 00 00 	movl   $0x1,-0x50(%ebp)
 8049a70:	eb 1a                	jmp    8049a8c <phase_6+0x127>
 8049a72:	8b 45 b0             	mov    -0x50(%ebp),%eax
 8049a75:	8b 54 85 d8          	mov    -0x28(%ebp,%eax,4),%edx
 8049a79:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049a7c:	89 50 08             	mov    %edx,0x8(%eax)
 8049a7f:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049a82:	8b 40 08             	mov    0x8(%eax),%eax
 8049a85:	89 45 ac             	mov    %eax,-0x54(%ebp)
 8049a88:	83 45 b0 01          	addl   $0x1,-0x50(%ebp)
 8049a8c:	83 7d b0 06          	cmpl   $0x6,-0x50(%ebp)
 8049a90:	7e e0                	jle    8049a72 <phase_6+0x10d>
 8049a92:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049a95:	c7 40 08 00 00 00 00 	movl   $0x0,0x8(%eax)
 8049a9c:	8b 45 b8             	mov    -0x48(%ebp),%eax
 8049a9f:	89 45 ac             	mov    %eax,-0x54(%ebp)
 8049aa2:	c7 45 b0 00 00 00 00 	movl   $0x0,-0x50(%ebp)
 8049aa9:	eb 2a                	jmp    8049ad5 <phase_6+0x170>
 8049aab:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049aae:	8b 10                	mov    (%eax),%edx
 8049ab0:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049ab3:	8b 40 08             	mov    0x8(%eax),%eax
 8049ab6:	8b 00                	mov    (%eax),%eax
 8049ab8:	39 c2                	cmp    %eax,%edx
 8049aba:	7e 0c                	jle    8049ac8 <phase_6+0x163>
 8049abc:	e8 56 05 00 00       	call   804a017 <explode_bomb>
 8049ac1:	b8 00 00 00 00       	mov    $0x0,%eax
 8049ac6:	eb 18                	jmp    8049ae0 <phase_6+0x17b>
 8049ac8:	8b 45 ac             	mov    -0x54(%ebp),%eax
 8049acb:	8b 40 08             	mov    0x8(%eax),%eax
 8049ace:	89 45 ac             	mov    %eax,-0x54(%ebp)
 8049ad1:	83 45 b0 01          	addl   $0x1,-0x50(%ebp)
 8049ad5:	83 7d b0 05          	cmpl   $0x5,-0x50(%ebp)
 8049ad9:	7e d0                	jle    8049aab <phase_6+0x146>
 8049adb:	b8 01 00 00 00       	mov    $0x1,%eax
 8049ae0:	8b 4d f4             	mov    -0xc(%ebp),%ecx
 8049ae3:	65 33 0d 14 00 00 00 	xor    %gs:0x14,%ecx
 8049aea:	74 05                	je     8049af1 <phase_6+0x18c>
 8049aec:	e8 9f f6 ff ff       	call   8049190 <__stack_chk_fail@plt>
 8049af1:	c9                   	leave  
 8049af2:	c3                   	ret    

08049af3 <fun7>:
 8049af3:	f3 0f 1e fb          	endbr32 
 8049af7:	55                   	push   %ebp
 8049af8:	89 e5                	mov    %esp,%ebp
 8049afa:	83 ec 08             	sub    $0x8,%esp
 8049afd:	83 7d 08 00          	cmpl   $0x0,0x8(%ebp)
 8049b01:	75 07                	jne    8049b0a <fun7+0x17>
 8049b03:	b8 ff ff ff ff       	mov    $0xffffffff,%eax
 8049b08:	eb 4e                	jmp    8049b58 <fun7+0x65>
 8049b0a:	8b 45 08             	mov    0x8(%ebp),%eax
 8049b0d:	8b 00                	mov    (%eax),%eax
 8049b0f:	39 45 0c             	cmp    %eax,0xc(%ebp)
 8049b12:	7d 19                	jge    8049b2d <fun7+0x3a>
 8049b14:	8b 45 08             	mov    0x8(%ebp),%eax
 8049b17:	8b 40 04             	mov    0x4(%eax),%eax
 8049b1a:	83 ec 08             	sub    $0x8,%esp
 8049b1d:	ff 75 0c             	pushl  0xc(%ebp)
 8049b20:	50                   	push   %eax
 8049b21:	e8 cd ff ff ff       	call   8049af3 <fun7>
 8049b26:	83 c4 10             	add    $0x10,%esp
 8049b29:	01 c0                	add    %eax,%eax
 8049b2b:	eb 2b                	jmp    8049b58 <fun7+0x65>
 8049b2d:	8b 45 08             	mov    0x8(%ebp),%eax
 8049b30:	8b 00                	mov    (%eax),%eax
 8049b32:	39 45 0c             	cmp    %eax,0xc(%ebp)
 8049b35:	75 07                	jne    8049b3e <fun7+0x4b>
 8049b37:	b8 00 00 00 00       	mov    $0x0,%eax
 8049b3c:	eb 1a                	jmp    8049b58 <fun7+0x65>
 8049b3e:	8b 45 08             	mov    0x8(%ebp),%eax
 8049b41:	8b 40 08             	mov    0x8(%eax),%eax
 8049b44:	83 ec 08             	sub    $0x8,%esp
 8049b47:	ff 75 0c             	pushl  0xc(%ebp)
 8049b4a:	50                   	push   %eax
 8049b4b:	e8 a3 ff ff ff       	call   8049af3 <fun7>
 8049b50:	83 c4 10             	add    $0x10,%esp
 8049b53:	01 c0                	add    %eax,%eax
 8049b55:	83 c0 01             	add    $0x1,%eax
 8049b58:	c9                   	leave  
 8049b59:	c3                   	ret    

08049b5a <secret_phase>:
 8049b5a:	f3 0f 1e fb          	endbr32 
 8049b5e:	55                   	push   %ebp
 8049b5f:	89 e5                	mov    %esp,%ebp
 8049b61:	83 ec 18             	sub    $0x18,%esp
 8049b64:	e8 67 03 00 00       	call   8049ed0 <read_line>
 8049b69:	89 45 ec             	mov    %eax,-0x14(%ebp)
 8049b6c:	83 ec 0c             	sub    $0xc,%esp
 8049b6f:	ff 75 ec             	pushl  -0x14(%ebp)
 8049b72:	e8 a9 f6 ff ff       	call   8049220 <atoi@plt>
 8049b77:	83 c4 10             	add    $0x10,%esp
 8049b7a:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049b7d:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 8049b81:	7e 09                	jle    8049b8c <secret_phase+0x32>
 8049b83:	81 7d f0 e9 03 00 00 	cmpl   $0x3e9,-0x10(%ebp)
 8049b8a:	7e 0c                	jle    8049b98 <secret_phase+0x3e>
 8049b8c:	e8 86 04 00 00       	call   804a017 <explode_bomb>
 8049b91:	b8 00 00 00 00       	mov    $0x0,%eax
 8049b96:	eb 42                	jmp    8049bda <secret_phase+0x80>
 8049b98:	83 ec 08             	sub    $0x8,%esp
 8049b9b:	ff 75 f0             	pushl  -0x10(%ebp)
 8049b9e:	68 58 d2 04 08       	push   $0x804d258
 8049ba3:	e8 4b ff ff ff       	call   8049af3 <fun7>
 8049ba8:	83 c4 10             	add    $0x10,%esp
 8049bab:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049bae:	83 7d f4 01          	cmpl   $0x1,-0xc(%ebp)
 8049bb2:	74 0c                	je     8049bc0 <secret_phase+0x66>
 8049bb4:	e8 5e 04 00 00       	call   804a017 <explode_bomb>
 8049bb9:	b8 00 00 00 00       	mov    $0x0,%eax
 8049bbe:	eb 1a                	jmp    8049bda <secret_phase+0x80>
 8049bc0:	83 ec 0c             	sub    $0xc,%esp
 8049bc3:	68 44 b2 04 08       	push   $0x804b244
 8049bc8:	e8 e3 f5 ff ff       	call   80491b0 <puts@plt>
 8049bcd:	83 c4 10             	add    $0x10,%esp
 8049bd0:	e8 6f 04 00 00       	call   804a044 <phase_defused>
 8049bd5:	b8 01 00 00 00       	mov    $0x1,%eax
 8049bda:	c9                   	leave  
 8049bdb:	c3                   	ret    

08049bdc <sig_handler>:
 8049bdc:	f3 0f 1e fb          	endbr32 
 8049be0:	55                   	push   %ebp
 8049be1:	89 e5                	mov    %esp,%ebp
 8049be3:	83 ec 08             	sub    $0x8,%esp
 8049be6:	83 ec 0c             	sub    $0xc,%esp
 8049be9:	68 6c b2 04 08       	push   $0x804b26c
 8049bee:	e8 bd f5 ff ff       	call   80491b0 <puts@plt>
 8049bf3:	83 c4 10             	add    $0x10,%esp
 8049bf6:	83 ec 0c             	sub    $0xc,%esp
 8049bf9:	6a 03                	push   $0x3
 8049bfb:	e8 80 f5 ff ff       	call   8049180 <sleep@plt>
 8049c00:	83 c4 10             	add    $0x10,%esp
 8049c03:	83 ec 0c             	sub    $0xc,%esp
 8049c06:	68 a4 b2 04 08       	push   $0x804b2a4
 8049c0b:	e8 30 f5 ff ff       	call   8049140 <printf@plt>
 8049c10:	83 c4 10             	add    $0x10,%esp
 8049c13:	a1 84 d2 04 08       	mov    0x804d284,%eax
 8049c18:	83 ec 0c             	sub    $0xc,%esp
 8049c1b:	50                   	push   %eax
 8049c1c:	e8 2f f5 ff ff       	call   8049150 <fflush@plt>
 8049c21:	83 c4 10             	add    $0x10,%esp
 8049c24:	83 ec 0c             	sub    $0xc,%esp
 8049c27:	6a 01                	push   $0x1
 8049c29:	e8 52 f5 ff ff       	call   8049180 <sleep@plt>
 8049c2e:	83 c4 10             	add    $0x10,%esp
 8049c31:	83 ec 0c             	sub    $0xc,%esp
 8049c34:	68 ac b2 04 08       	push   $0x804b2ac
 8049c39:	e8 72 f5 ff ff       	call   80491b0 <puts@plt>
 8049c3e:	83 c4 10             	add    $0x10,%esp
 8049c41:	83 ec 0c             	sub    $0xc,%esp
 8049c44:	6a 10                	push   $0x10
 8049c46:	e8 75 f5 ff ff       	call   80491c0 <exit@plt>

08049c4b <invalid_phase>:
 8049c4b:	f3 0f 1e fb          	endbr32 
 8049c4f:	55                   	push   %ebp
 8049c50:	89 e5                	mov    %esp,%ebp
 8049c52:	83 ec 08             	sub    $0x8,%esp
 8049c55:	83 ec 08             	sub    $0x8,%esp
 8049c58:	ff 75 08             	pushl  0x8(%ebp)
 8049c5b:	68 b4 b2 04 08       	push   $0x804b2b4
 8049c60:	e8 db f4 ff ff       	call   8049140 <printf@plt>
 8049c65:	83 c4 10             	add    $0x10,%esp
 8049c68:	83 ec 0c             	sub    $0xc,%esp
 8049c6b:	6a 08                	push   $0x8
 8049c6d:	e8 4e f5 ff ff       	call   80491c0 <exit@plt>

08049c72 <read_six_numbers>:
 8049c72:	f3 0f 1e fb          	endbr32 
 8049c76:	55                   	push   %ebp
 8049c77:	89 e5                	mov    %esp,%ebp
 8049c79:	56                   	push   %esi
 8049c7a:	53                   	push   %ebx
 8049c7b:	83 ec 10             	sub    $0x10,%esp
 8049c7e:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049c81:	8d 70 14             	lea    0x14(%eax),%esi
 8049c84:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049c87:	8d 58 10             	lea    0x10(%eax),%ebx
 8049c8a:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049c8d:	8d 48 0c             	lea    0xc(%eax),%ecx
 8049c90:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049c93:	8d 50 08             	lea    0x8(%eax),%edx
 8049c96:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049c99:	83 c0 04             	add    $0x4,%eax
 8049c9c:	56                   	push   %esi
 8049c9d:	53                   	push   %ebx
 8049c9e:	51                   	push   %ecx
 8049c9f:	52                   	push   %edx
 8049ca0:	50                   	push   %eax
 8049ca1:	ff 75 0c             	pushl  0xc(%ebp)
 8049ca4:	68 c5 b2 04 08       	push   $0x804b2c5
 8049ca9:	ff 75 08             	pushl  0x8(%ebp)
 8049cac:	e8 3f f5 ff ff       	call   80491f0 <__isoc99_sscanf@plt>
 8049cb1:	83 c4 20             	add    $0x20,%esp
 8049cb4:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049cb7:	83 7d f4 05          	cmpl   $0x5,-0xc(%ebp)
 8049cbb:	7f 0c                	jg     8049cc9 <read_six_numbers+0x57>
 8049cbd:	e8 55 03 00 00       	call   804a017 <explode_bomb>
 8049cc2:	b8 00 00 00 00       	mov    $0x0,%eax
 8049cc7:	eb 05                	jmp    8049cce <read_six_numbers+0x5c>
 8049cc9:	b8 01 00 00 00       	mov    $0x1,%eax
 8049cce:	8d 65 f8             	lea    -0x8(%ebp),%esp
 8049cd1:	5b                   	pop    %ebx
 8049cd2:	5e                   	pop    %esi
 8049cd3:	5d                   	pop    %ebp
 8049cd4:	c3                   	ret    

08049cd5 <read_n_numbers>:
 8049cd5:	f3 0f 1e fb          	endbr32 
 8049cd9:	55                   	push   %ebp
 8049cda:	89 e5                	mov    %esp,%ebp
 8049cdc:	83 ec 18             	sub    $0x18,%esp
 8049cdf:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 8049ce6:	eb 70                	jmp    8049d58 <read_n_numbers+0x83>
 8049ce8:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8049cec:	75 18                	jne    8049d06 <read_n_numbers+0x31>
 8049cee:	83 ec 08             	sub    $0x8,%esp
 8049cf1:	68 d7 b2 04 08       	push   $0x804b2d7
 8049cf6:	ff 75 08             	pushl  0x8(%ebp)
 8049cf9:	e8 12 f5 ff ff       	call   8049210 <strtok@plt>
 8049cfe:	83 c4 10             	add    $0x10,%esp
 8049d01:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049d04:	eb 15                	jmp    8049d1b <read_n_numbers+0x46>
 8049d06:	83 ec 08             	sub    $0x8,%esp
 8049d09:	68 d7 b2 04 08       	push   $0x804b2d7
 8049d0e:	6a 00                	push   $0x0
 8049d10:	e8 fb f4 ff ff       	call   8049210 <strtok@plt>
 8049d15:	83 c4 10             	add    $0x10,%esp
 8049d18:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049d1b:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 8049d1f:	74 27                	je     8049d48 <read_n_numbers+0x73>
 8049d21:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049d24:	8d 14 85 00 00 00 00 	lea    0x0(,%eax,4),%edx
 8049d2b:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049d2e:	01 d0                	add    %edx,%eax
 8049d30:	83 ec 04             	sub    $0x4,%esp
 8049d33:	50                   	push   %eax
 8049d34:	68 db b2 04 08       	push   $0x804b2db
 8049d39:	ff 75 f0             	pushl  -0x10(%ebp)
 8049d3c:	e8 af f4 ff ff       	call   80491f0 <__isoc99_sscanf@plt>
 8049d41:	83 c4 10             	add    $0x10,%esp
 8049d44:	85 c0                	test   %eax,%eax
 8049d46:	7f 0c                	jg     8049d54 <read_n_numbers+0x7f>
 8049d48:	e8 ca 02 00 00       	call   804a017 <explode_bomb>
 8049d4d:	b8 00 00 00 00       	mov    $0x0,%eax
 8049d52:	eb 11                	jmp    8049d65 <read_n_numbers+0x90>
 8049d54:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8049d58:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049d5b:	3b 45 10             	cmp    0x10(%ebp),%eax
 8049d5e:	7c 88                	jl     8049ce8 <read_n_numbers+0x13>
 8049d60:	b8 01 00 00 00       	mov    $0x1,%eax
 8049d65:	c9                   	leave  
 8049d66:	c3                   	ret    

08049d67 <string_length>:
 8049d67:	f3 0f 1e fb          	endbr32 
 8049d6b:	55                   	push   %ebp
 8049d6c:	89 e5                	mov    %esp,%ebp
 8049d6e:	83 ec 10             	sub    $0x10,%esp
 8049d71:	8b 45 08             	mov    0x8(%ebp),%eax
 8049d74:	89 45 fc             	mov    %eax,-0x4(%ebp)
 8049d77:	c7 45 f8 00 00 00 00 	movl   $0x0,-0x8(%ebp)
 8049d7e:	eb 08                	jmp    8049d88 <string_length+0x21>
 8049d80:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
 8049d84:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
 8049d88:	8b 45 fc             	mov    -0x4(%ebp),%eax
 8049d8b:	0f b6 00             	movzbl (%eax),%eax
 8049d8e:	84 c0                	test   %al,%al
 8049d90:	75 ee                	jne    8049d80 <string_length+0x19>
 8049d92:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049d95:	c9                   	leave  
 8049d96:	c3                   	ret    

08049d97 <strings_not_equal>:
 8049d97:	f3 0f 1e fb          	endbr32 
 8049d9b:	55                   	push   %ebp
 8049d9c:	89 e5                	mov    %esp,%ebp
 8049d9e:	53                   	push   %ebx
 8049d9f:	83 ec 10             	sub    $0x10,%esp
 8049da2:	ff 75 08             	pushl  0x8(%ebp)
 8049da5:	e8 bd ff ff ff       	call   8049d67 <string_length>
 8049daa:	83 c4 04             	add    $0x4,%esp
 8049dad:	89 c3                	mov    %eax,%ebx
 8049daf:	ff 75 0c             	pushl  0xc(%ebp)
 8049db2:	e8 b0 ff ff ff       	call   8049d67 <string_length>
 8049db7:	83 c4 04             	add    $0x4,%esp
 8049dba:	39 c3                	cmp    %eax,%ebx
 8049dbc:	74 07                	je     8049dc5 <strings_not_equal+0x2e>
 8049dbe:	b8 01 00 00 00       	mov    $0x1,%eax
 8049dc3:	eb 3c                	jmp    8049e01 <strings_not_equal+0x6a>
 8049dc5:	8b 45 08             	mov    0x8(%ebp),%eax
 8049dc8:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049dcb:	8b 45 0c             	mov    0xc(%ebp),%eax
 8049dce:	89 45 f8             	mov    %eax,-0x8(%ebp)
 8049dd1:	eb 1f                	jmp    8049df2 <strings_not_equal+0x5b>
 8049dd3:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049dd6:	0f b6 10             	movzbl (%eax),%edx
 8049dd9:	8b 45 f8             	mov    -0x8(%ebp),%eax
 8049ddc:	0f b6 00             	movzbl (%eax),%eax
 8049ddf:	38 c2                	cmp    %al,%dl
 8049de1:	74 07                	je     8049dea <strings_not_equal+0x53>
 8049de3:	b8 01 00 00 00       	mov    $0x1,%eax
 8049de8:	eb 17                	jmp    8049e01 <strings_not_equal+0x6a>
 8049dea:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 8049dee:	83 45 f8 01          	addl   $0x1,-0x8(%ebp)
 8049df2:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049df5:	0f b6 00             	movzbl (%eax),%eax
 8049df8:	84 c0                	test   %al,%al
 8049dfa:	75 d7                	jne    8049dd3 <strings_not_equal+0x3c>
 8049dfc:	b8 00 00 00 00       	mov    $0x0,%eax
 8049e01:	8b 5d fc             	mov    -0x4(%ebp),%ebx
 8049e04:	c9                   	leave  
 8049e05:	c3                   	ret    

08049e06 <initialize_bomb>:
 8049e06:	f3 0f 1e fb          	endbr32 
 8049e0a:	55                   	push   %ebp
 8049e0b:	89 e5                	mov    %esp,%ebp
 8049e0d:	83 ec 08             	sub    $0x8,%esp
 8049e10:	83 ec 08             	sub    $0x8,%esp
 8049e13:	68 dc 9b 04 08       	push   $0x8049bdc
 8049e18:	6a 02                	push   $0x2
 8049e1a:	e8 51 f3 ff ff       	call   8049170 <signal@plt>
 8049e1f:	83 c4 10             	add    $0x10,%esp
 8049e22:	90                   	nop
 8049e23:	c9                   	leave  
 8049e24:	c3                   	ret    

08049e25 <initialize_bomb_solve>:
 8049e25:	f3 0f 1e fb          	endbr32 
 8049e29:	55                   	push   %ebp
 8049e2a:	89 e5                	mov    %esp,%ebp
 8049e2c:	90                   	nop
 8049e2d:	5d                   	pop    %ebp
 8049e2e:	c3                   	ret    

08049e2f <blank_line>:
 8049e2f:	f3 0f 1e fb          	endbr32 
 8049e33:	55                   	push   %ebp
 8049e34:	89 e5                	mov    %esp,%ebp
 8049e36:	83 ec 08             	sub    $0x8,%esp
 8049e39:	eb 30                	jmp    8049e6b <blank_line+0x3c>
 8049e3b:	e8 f0 f3 ff ff       	call   8049230 <__ctype_b_loc@plt>
 8049e40:	8b 08                	mov    (%eax),%ecx
 8049e42:	8b 45 08             	mov    0x8(%ebp),%eax
 8049e45:	8d 50 01             	lea    0x1(%eax),%edx
 8049e48:	89 55 08             	mov    %edx,0x8(%ebp)
 8049e4b:	0f b6 00             	movzbl (%eax),%eax
 8049e4e:	0f be c0             	movsbl %al,%eax
 8049e51:	01 c0                	add    %eax,%eax
 8049e53:	01 c8                	add    %ecx,%eax
 8049e55:	0f b7 00             	movzwl (%eax),%eax
 8049e58:	0f b7 c0             	movzwl %ax,%eax
 8049e5b:	25 00 20 00 00       	and    $0x2000,%eax
 8049e60:	85 c0                	test   %eax,%eax
 8049e62:	75 07                	jne    8049e6b <blank_line+0x3c>
 8049e64:	b8 00 00 00 00       	mov    $0x0,%eax
 8049e69:	eb 0f                	jmp    8049e7a <blank_line+0x4b>
 8049e6b:	8b 45 08             	mov    0x8(%ebp),%eax
 8049e6e:	0f b6 00             	movzbl (%eax),%eax
 8049e71:	84 c0                	test   %al,%al
 8049e73:	75 c6                	jne    8049e3b <blank_line+0xc>
 8049e75:	b8 01 00 00 00       	mov    $0x1,%eax
 8049e7a:	c9                   	leave  
 8049e7b:	c3                   	ret    

08049e7c <skip>:
 8049e7c:	f3 0f 1e fb          	endbr32 
 8049e80:	55                   	push   %ebp
 8049e81:	89 e5                	mov    %esp,%ebp
 8049e83:	83 ec 18             	sub    $0x18,%esp
 8049e86:	8b 0d 90 d2 04 08    	mov    0x804d290,%ecx
 8049e8c:	8b 15 8c d2 04 08    	mov    0x804d28c,%edx
 8049e92:	89 d0                	mov    %edx,%eax
 8049e94:	c1 e0 02             	shl    $0x2,%eax
 8049e97:	01 d0                	add    %edx,%eax
 8049e99:	c1 e0 04             	shl    $0x4,%eax
 8049e9c:	05 a0 d2 04 08       	add    $0x804d2a0,%eax
 8049ea1:	83 ec 04             	sub    $0x4,%esp
 8049ea4:	51                   	push   %ecx
 8049ea5:	6a 50                	push   $0x50
 8049ea7:	50                   	push   %eax
 8049ea8:	e8 b3 f2 ff ff       	call   8049160 <fgets@plt>
 8049ead:	83 c4 10             	add    $0x10,%esp
 8049eb0:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049eb3:	83 7d f4 00          	cmpl   $0x0,-0xc(%ebp)
 8049eb7:	74 12                	je     8049ecb <skip+0x4f>
 8049eb9:	83 ec 0c             	sub    $0xc,%esp
 8049ebc:	ff 75 f4             	pushl  -0xc(%ebp)
 8049ebf:	e8 6b ff ff ff       	call   8049e2f <blank_line>
 8049ec4:	83 c4 10             	add    $0x10,%esp
 8049ec7:	85 c0                	test   %eax,%eax
 8049ec9:	75 bb                	jne    8049e86 <skip+0xa>
 8049ecb:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049ece:	c9                   	leave  
 8049ecf:	c3                   	ret    

08049ed0 <read_line>:
 8049ed0:	f3 0f 1e fb          	endbr32 
 8049ed4:	55                   	push   %ebp
 8049ed5:	89 e5                	mov    %esp,%ebp
 8049ed7:	83 ec 18             	sub    $0x18,%esp
 8049eda:	e8 9d ff ff ff       	call   8049e7c <skip>
 8049edf:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049ee2:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 8049ee6:	75 79                	jne    8049f61 <read_line+0x91>
 8049ee8:	8b 15 90 d2 04 08    	mov    0x804d290,%edx
 8049eee:	a1 80 d2 04 08       	mov    0x804d280,%eax
 8049ef3:	39 c2                	cmp    %eax,%edx
 8049ef5:	75 1a                	jne    8049f11 <read_line+0x41>
 8049ef7:	83 ec 0c             	sub    $0xc,%esp
 8049efa:	68 de b2 04 08       	push   $0x804b2de
 8049eff:	e8 ac f2 ff ff       	call   80491b0 <puts@plt>
 8049f04:	83 c4 10             	add    $0x10,%esp
 8049f07:	83 ec 0c             	sub    $0xc,%esp
 8049f0a:	6a 08                	push   $0x8
 8049f0c:	e8 af f2 ff ff       	call   80491c0 <exit@plt>
 8049f11:	83 ec 0c             	sub    $0xc,%esp
 8049f14:	68 fc b2 04 08       	push   $0x804b2fc
 8049f19:	e8 82 f2 ff ff       	call   80491a0 <getenv@plt>
 8049f1e:	83 c4 10             	add    $0x10,%esp
 8049f21:	85 c0                	test   %eax,%eax
 8049f23:	74 0a                	je     8049f2f <read_line+0x5f>
 8049f25:	83 ec 0c             	sub    $0xc,%esp
 8049f28:	6a 00                	push   $0x0
 8049f2a:	e8 91 f2 ff ff       	call   80491c0 <exit@plt>
 8049f2f:	a1 80 d2 04 08       	mov    0x804d280,%eax
 8049f34:	a3 90 d2 04 08       	mov    %eax,0x804d290
 8049f39:	e8 3e ff ff ff       	call   8049e7c <skip>
 8049f3e:	89 45 f0             	mov    %eax,-0x10(%ebp)
 8049f41:	83 7d f0 00          	cmpl   $0x0,-0x10(%ebp)
 8049f45:	75 1a                	jne    8049f61 <read_line+0x91>
 8049f47:	83 ec 0c             	sub    $0xc,%esp
 8049f4a:	68 de b2 04 08       	push   $0x804b2de
 8049f4f:	e8 5c f2 ff ff       	call   80491b0 <puts@plt>
 8049f54:	83 c4 10             	add    $0x10,%esp
 8049f57:	83 ec 0c             	sub    $0xc,%esp
 8049f5a:	6a 00                	push   $0x0
 8049f5c:	e8 5f f2 ff ff       	call   80491c0 <exit@plt>
 8049f61:	8b 15 8c d2 04 08    	mov    0x804d28c,%edx
 8049f67:	89 d0                	mov    %edx,%eax
 8049f69:	c1 e0 02             	shl    $0x2,%eax
 8049f6c:	01 d0                	add    %edx,%eax
 8049f6e:	c1 e0 04             	shl    $0x4,%eax
 8049f71:	05 a0 d2 04 08       	add    $0x804d2a0,%eax
 8049f76:	83 ec 0c             	sub    $0xc,%esp
 8049f79:	50                   	push   %eax
 8049f7a:	e8 51 f2 ff ff       	call   80491d0 <strlen@plt>
 8049f7f:	83 c4 10             	add    $0x10,%esp
 8049f82:	89 45 f4             	mov    %eax,-0xc(%ebp)
 8049f85:	83 7d f4 4e          	cmpl   $0x4e,-0xc(%ebp)
 8049f89:	7e 4d                	jle    8049fd8 <read_line+0x108>
 8049f8b:	83 ec 0c             	sub    $0xc,%esp
 8049f8e:	68 07 b3 04 08       	push   $0x804b307
 8049f93:	e8 18 f2 ff ff       	call   80491b0 <puts@plt>
 8049f98:	83 c4 10             	add    $0x10,%esp
 8049f9b:	8b 15 8c d2 04 08    	mov    0x804d28c,%edx
 8049fa1:	8d 42 01             	lea    0x1(%edx),%eax
 8049fa4:	a3 8c d2 04 08       	mov    %eax,0x804d28c
 8049fa9:	89 d0                	mov    %edx,%eax
 8049fab:	c1 e0 02             	shl    $0x2,%eax
 8049fae:	01 d0                	add    %edx,%eax
 8049fb0:	c1 e0 04             	shl    $0x4,%eax
 8049fb3:	05 a0 d2 04 08       	add    $0x804d2a0,%eax
 8049fb8:	c7 00 2a 2a 2a 74    	movl   $0x742a2a2a,(%eax)
 8049fbe:	c7 40 04 72 75 6e 63 	movl   $0x636e7572,0x4(%eax)
 8049fc5:	c7 40 08 61 74 65 64 	movl   $0x64657461,0x8(%eax)
 8049fcc:	c7 40 0c 2a 2a 2a 00 	movl   $0x2a2a2a,0xc(%eax)
 8049fd3:	e8 3f 00 00 00       	call   804a017 <explode_bomb>
 8049fd8:	8b 15 8c d2 04 08    	mov    0x804d28c,%edx
 8049fde:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8049fe1:	8d 48 ff             	lea    -0x1(%eax),%ecx
 8049fe4:	89 d0                	mov    %edx,%eax
 8049fe6:	c1 e0 02             	shl    $0x2,%eax
 8049fe9:	01 d0                	add    %edx,%eax
 8049feb:	c1 e0 04             	shl    $0x4,%eax
 8049fee:	01 c8                	add    %ecx,%eax
 8049ff0:	05 a0 d2 04 08       	add    $0x804d2a0,%eax
 8049ff5:	c6 00 00             	movb   $0x0,(%eax)
 8049ff8:	8b 15 8c d2 04 08    	mov    0x804d28c,%edx
 8049ffe:	8d 42 01             	lea    0x1(%edx),%eax
 804a001:	a3 8c d2 04 08       	mov    %eax,0x804d28c
 804a006:	89 d0                	mov    %edx,%eax
 804a008:	c1 e0 02             	shl    $0x2,%eax
 804a00b:	01 d0                	add    %edx,%eax
 804a00d:	c1 e0 04             	shl    $0x4,%eax
 804a010:	05 a0 d2 04 08       	add    $0x804d2a0,%eax
 804a015:	c9                   	leave  
 804a016:	c3                   	ret    

0804a017 <explode_bomb>:
 804a017:	f3 0f 1e fb          	endbr32 
 804a01b:	55                   	push   %ebp
 804a01c:	89 e5                	mov    %esp,%ebp
 804a01e:	83 ec 08             	sub    $0x8,%esp
 804a021:	83 ec 0c             	sub    $0xc,%esp
 804a024:	68 22 b3 04 08       	push   $0x804b322
 804a029:	e8 82 f1 ff ff       	call   80491b0 <puts@plt>
 804a02e:	83 c4 10             	add    $0x10,%esp
 804a031:	83 ec 0c             	sub    $0xc,%esp
 804a034:	68 2b b3 04 08       	push   $0x804b32b
 804a039:	e8 72 f1 ff ff       	call   80491b0 <puts@plt>
 804a03e:	83 c4 10             	add    $0x10,%esp
 804a041:	90                   	nop
 804a042:	c9                   	leave  
 804a043:	c3                   	ret    

0804a044 <phase_defused>:
 804a044:	f3 0f 1e fb          	endbr32 
 804a048:	55                   	push   %ebp
 804a049:	89 e5                	mov    %esp,%ebp
 804a04b:	83 ec 68             	sub    $0x68,%esp
 804a04e:	65 a1 14 00 00 00    	mov    %gs:0x14,%eax
 804a054:	89 45 f4             	mov    %eax,-0xc(%ebp)
 804a057:	31 c0                	xor    %eax,%eax
 804a059:	a1 8c d2 04 08       	mov    0x804d28c,%eax
 804a05e:	83 f8 07             	cmp    $0x7,%eax
 804a061:	75 77                	jne    804a0da <phase_defused+0x96>
 804a063:	83 ec 0c             	sub    $0xc,%esp
 804a066:	8d 45 a4             	lea    -0x5c(%ebp),%eax
 804a069:	50                   	push   %eax
 804a06a:	8d 45 9c             	lea    -0x64(%ebp),%eax
 804a06d:	50                   	push   %eax
 804a06e:	8d 45 98             	lea    -0x68(%ebp),%eax
 804a071:	50                   	push   %eax
 804a072:	68 42 b3 04 08       	push   $0x804b342
 804a077:	68 e0 d3 04 08       	push   $0x804d3e0
 804a07c:	e8 6f f1 ff ff       	call   80491f0 <__isoc99_sscanf@plt>
 804a081:	83 c4 20             	add    $0x20,%esp
 804a084:	89 45 a0             	mov    %eax,-0x60(%ebp)
 804a087:	83 7d a0 03          	cmpl   $0x3,-0x60(%ebp)
 804a08b:	75 3d                	jne    804a0ca <phase_defused+0x86>
 804a08d:	83 ec 08             	sub    $0x8,%esp
 804a090:	68 4b b3 04 08       	push   $0x804b34b
 804a095:	8d 45 a4             	lea    -0x5c(%ebp),%eax
 804a098:	50                   	push   %eax
 804a099:	e8 f9 fc ff ff       	call   8049d97 <strings_not_equal>
 804a09e:	83 c4 10             	add    $0x10,%esp
 804a0a1:	85 c0                	test   %eax,%eax
 804a0a3:	75 25                	jne    804a0ca <phase_defused+0x86>
 804a0a5:	83 ec 0c             	sub    $0xc,%esp
 804a0a8:	68 54 b3 04 08       	push   $0x804b354
 804a0ad:	e8 fe f0 ff ff       	call   80491b0 <puts@plt>
 804a0b2:	83 c4 10             	add    $0x10,%esp
 804a0b5:	83 ec 0c             	sub    $0xc,%esp
 804a0b8:	68 7c b3 04 08       	push   $0x804b37c
 804a0bd:	e8 ee f0 ff ff       	call   80491b0 <puts@plt>
 804a0c2:	83 c4 10             	add    $0x10,%esp
 804a0c5:	e8 90 fa ff ff       	call   8049b5a <secret_phase>
 804a0ca:	83 ec 0c             	sub    $0xc,%esp
 804a0cd:	68 b4 b3 04 08       	push   $0x804b3b4
 804a0d2:	e8 d9 f0 ff ff       	call   80491b0 <puts@plt>
 804a0d7:	83 c4 10             	add    $0x10,%esp
 804a0da:	90                   	nop
 804a0db:	8b 45 f4             	mov    -0xc(%ebp),%eax
 804a0de:	65 33 05 14 00 00 00 	xor    %gs:0x14,%eax
 804a0e5:	74 05                	je     804a0ec <phase_defused+0xa8>
 804a0e7:	e8 a4 f0 ff ff       	call   8049190 <__stack_chk_fail@plt>
 804a0ec:	c9                   	leave  
 804a0ed:	c3                   	ret    
 804a0ee:	66 90                	xchg   %ax,%ax

0804a0f0 <__libc_csu_init>:
 804a0f0:	f3 0f 1e fb          	endbr32 
 804a0f4:	55                   	push   %ebp
 804a0f5:	e8 6b 00 00 00       	call   804a165 <__x86.get_pc_thunk.bp>
 804a0fa:	81 c5 06 2f 00 00    	add    $0x2f06,%ebp
 804a100:	57                   	push   %edi
 804a101:	56                   	push   %esi
 804a102:	53                   	push   %ebx
 804a103:	83 ec 0c             	sub    $0xc,%esp
 804a106:	89 eb                	mov    %ebp,%ebx
 804a108:	8b 7c 24 28          	mov    0x28(%esp),%edi
 804a10c:	e8 ef ee ff ff       	call   8049000 <_init>
 804a111:	8d 9d 10 ff ff ff    	lea    -0xf0(%ebp),%ebx
 804a117:	8d 85 0c ff ff ff    	lea    -0xf4(%ebp),%eax
 804a11d:	29 c3                	sub    %eax,%ebx
 804a11f:	c1 fb 02             	sar    $0x2,%ebx
 804a122:	74 29                	je     804a14d <__libc_csu_init+0x5d>
 804a124:	31 f6                	xor    %esi,%esi
 804a126:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 804a12d:	8d 76 00             	lea    0x0(%esi),%esi
 804a130:	83 ec 04             	sub    $0x4,%esp
 804a133:	57                   	push   %edi
 804a134:	ff 74 24 2c          	pushl  0x2c(%esp)
 804a138:	ff 74 24 2c          	pushl  0x2c(%esp)
 804a13c:	ff 94 b5 0c ff ff ff 	call   *-0xf4(%ebp,%esi,4)
 804a143:	83 c6 01             	add    $0x1,%esi
 804a146:	83 c4 10             	add    $0x10,%esp
 804a149:	39 f3                	cmp    %esi,%ebx
 804a14b:	75 e3                	jne    804a130 <__libc_csu_init+0x40>
 804a14d:	83 c4 0c             	add    $0xc,%esp
 804a150:	5b                   	pop    %ebx
 804a151:	5e                   	pop    %esi
 804a152:	5f                   	pop    %edi
 804a153:	5d                   	pop    %ebp
 804a154:	c3                   	ret    
 804a155:	8d b4 26 00 00 00 00 	lea    0x0(%esi,%eiz,1),%esi
 804a15c:	8d 74 26 00          	lea    0x0(%esi,%eiz,1),%esi

0804a160 <__libc_csu_fini>:
 804a160:	f3 0f 1e fb          	endbr32 
 804a164:	c3                   	ret    

0804a165 <__x86.get_pc_thunk.bp>:
 804a165:	8b 2c 24             	mov    (%esp),%ebp
 804a168:	c3                   	ret    

Disassembly of section .fini:

0804a16c <_fini>:
 804a16c:	f3 0f 1e fb          	endbr32 
 804a170:	53                   	push   %ebx
 804a171:	83 ec 08             	sub    $0x8,%esp
 804a174:	e8 17 f1 ff ff       	call   8049290 <__x86.get_pc_thunk.bx>
 804a179:	81 c3 87 2e 00 00    	add    $0x2e87,%ebx
 804a17f:	83 c4 08             	add    $0x8,%esp
 804a182:	5b                   	pop    %ebx
 804a183:	c3                   	ret    
