VERSION=1.1
PROGRAMS    = singleton-1.1 prototype-1.1 AbstractFactory-1.1 builder_shared
EXT = cc
CPP=c++

EXTRA_CFLAGS+=-I${HOME}/usr/local/include/
EXTRA_CFLAGS+=-L${HOME}/usr/local/lib/

CFLAGS=-std=c++11 $(EXTRA_CFLAGS) -DUSE_BOOST

singleton-$(VERSION)_OBJS = singleton-$(VERSION).o 
prototype-$(VERSION)_OBJS = prototype-$(VERSION).o
AbstractFactory-$(VERSION)_OBJS = AbstractFactory-$(VERSION).o
builder_shared_OBJS = builder_shared.o

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
