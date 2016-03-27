VERSION=1.1
PROGRAMS    = implict_conversion-1.1 static_cast-1.1 virtual_function-1.1 \
		virtual_destructor-1.1 dynamic_cast-1.1 noexpect-1.1
EXT = cc
CPP=c++
CFLAGS=-std=c++0x

implict_conversion-$(VERSION)_OBJS = implict_conversion-$(VERSION).o
static_cast-$(VERSION)_OBJS = static_cast-$(VERSION).o
virtual_function-$(VERSION)_OBJS = virtual_function-$(VERSION).o
virtual_destructor-$(VERSION)_OBJS = virtual_destructor-$(VERSION).o
dynamic_cast-$(VERSION)_OBJS = dynamic_cast-$(VERSION).o
noexpect-$(VERSION)_OBJS = noexpect-$(VERSION).o

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
