src = cat.c
out = cat

flags_1 = -std=c90 -Wpedantic
flags_2 = -Wall -Wextra -Werror
flags_3 = -O2

flags_all = $(flags_1) $(flags_2) $(flags_3)

$(out): $(src)
	gcc $(flags_all) $^ -o $@

clean:
	rm -f $(out)
