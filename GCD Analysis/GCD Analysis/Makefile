source = hw1_5 hw1_6
all: $(source)
$(source):
%: %.c
	gcc $< -o $@
%: %.cpp
	g++ $< -o $@
clean:
	rm -rf $(source)
run5:
	./hw1_5 < input
run6:
	./hw1_6 < input
