VERSION=1.1
PROGRAMS    = scoped_ptr-$(VERSION) smart_ptr_test-$(VERSION) \
		shared_ptr-$(VERSION) cmdopt joinstring
		#shared_ptr-$(VERSION) hash_map-$(VERSION)
EXT = cc
CPP=c++
EXTRA_CFLAGS+=-I./boost-library/boost_1_60_0
EXTRA_CFLAGS+=-L./boost-library/boost_1_60_0/stage/lib
#EXTRA_CFLAGS=-I/home/varadhan/boost-1.6/include/ -L/home/varadhan/boost-1.6/lib/ 
CFLAGS=-std=c++0x $(EXTRA_CFLAGS) -DUSE_BOOST

scoped_ptr-$(VERSION)_OBJS = scoped_ptr-$(VERSION).o
shared_ptr-$(VERSION)_OBJS = shared_ptr-$(VERSION).o
smart_ptr_test-$(VERSION)_OBJS = smart_ptr_test-$(VERSION).o
hash_map-$(VERSION)_OBJS = smart_ptr_test-$(VERSION).o
cmdopt_OBJS = cmdopt.o
joinstring_OBJS = joinstring.o


.PHONY: all clean
all: $(PROGRAMS)
	@echo "Compliation Success $(PROGRAMS)"

clean:
	@echo "Cleaning  $(ALL_OBJS)"
	rm -f $(ALL_OBJS) $(PROGRAMS)

define DEFINE_AUTO_TEMPLATES
$1: $$($1_OBJS)
	@echo "Compiling EXE $$< >> $$@ "
	@$(CPP) $(CFLAGS) $$< -o $1 -lboost_program_options -lboost_filesystem -lboost_system

$$($1_OBJS): $1.$(EXT)
	@echo "Compiling OBJ $$< >> $$@ "
	$(CPP) $(CFLAGS) -c $$< -o $$@
	#@$(CPP) $(CFLAGS) -c $$< -o $$@

ALL_OBJS += $$($1_OBJS)
endef

#$(eval $(call DEFINE_AUTO_TEMPLATES,$(PROGRAMS)))

$(foreach prog,$(PROGRAMS),$(eval $(call DEFINE_AUTO_TEMPLATES,$(prog))))



#Run the program by setting LB_LIBRARY_PATH
#export LD_LIBRARY_PATH=$PWD/boost-library/boost_1_60_0/stage/lib/

