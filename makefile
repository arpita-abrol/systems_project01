shell:	shell.c
	gcc shell.c -o shell

run:	shell
	./shell

clean:
	rm *~
	rm .out
	rm .exe
