executable = main
flags = -ansi -std=gnu99 -pedantic-errors -Wall -fsanitize=undefined -fsanitize=address
file1 = consts
file2 = init
file3 = prints
file4 = xtetris
mainfile = main

$(mainfile): $(mainfile).o $(file1).o $(file2).o $(file3).o $(file4).o
	gcc $(flags) -o $(executable) $(mainfile).c $(file1).o $(file2).o $(file3).o $(file4).o

$(file1).o: $(file1).c
	gcc $(flags) -c $(file1).c 

$(file2).o: $(file2).c
	gcc $(flags) -c $(file2).c

$(file3).o: $(file3).c
	gcc $(flags) -c $(file3).c

$(file4).o: $(file4).c
	gcc $(flags) -c $(file4).c

clean:
	rm *.o $(executable)