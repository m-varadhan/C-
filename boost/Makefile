PROGRAMS    = scoped_ptr-1.1
EXT = cc
CPP=c++

scoped_ptr-1.1_OBJS = scoped_ptr-1.1.o

define DEFINE_AUTO_TEMPLATES
$1: $$($1_OBJS)
	@echo "Compiling EXE $$< >> $$@ "
	@$(CPP) $(CFLAGS) $$< -o $1

$$($1_OBJS): $1.$(EXT)
	@echo "Compiling OBJ $$< >> $$@ "
	@$(CPP) $(CFLAGS) -c $$< -o $$@

ALL_OBJS += $$($1_OBJS)
endef

#$(eval $(call DEFINE_AUTO_TEMPLATES,$(PROGRAMS)))

$(foreach prog,$(PROGRAMS),$(eval $(call DEFINE_AUTO_TEMPLATES,$(prog))))

.PHONY: all clean
all: $(PROGRAMS)

clean:
	@echo "Cleaning  $(ALL_OBJS)"
	rm -f $(ALL_OBJS) $(PROGRAMS)
