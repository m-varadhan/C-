VERSION=1.1
PROGRAMS    = singleton-1.1 prototype-1.1
EXT = cc
CPP=c++
CFLAGS=-std=c++0x

singleton-$(VERSION)_OBJS = singleton-$(VERSION).o 
prototype-$(VERSION)_OBJS = prototype-$(VERSION).o

.PHONY: all clean
all: $(PROGRAMS)
	@echo "Compliation Success $(PROGRAMS)"

clean:
	@echo "Cleaning  $(ALL_OBJS)"
	rm -f $(ALL_OBJS) $(PROGRAMS)

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
