VERSION=1.1
PROGRAMS    = scoped_ptr-$(VERSION) smart_ptr_test-$(VERSION) \
		shared_ptr-$(VERSION) 
		#shared_ptr-$(VERSION) hash_map-$(VERSION)
EXT = cc
CPP=c++
CFLAGS=-std=c++0x

scoped_ptr-$(VERSION)_OBJS = scoped_ptr-$(VERSION).o
shared_ptr-$(VERSION)_OBJS = shared_ptr-$(VERSION).o
smart_ptr_test-$(VERSION)_OBJS = smart_ptr_test-$(VERSION).o
hash_map-$(VERSION)_OBJS = smart_ptr_test-$(VERSION).o


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
