# It is a confession: mohali copied this makefile from redsocks 

# 
SOURCES = $(wildcard *.cpp)
-include make.conf
OBJS = $(SOURCES:.cpp=.o)
ifeq ($(DBG_BUILD),1)
OBJS += debug.o
endif
SRCS := $(OBJS:.o=.cpp)
CONF := config.h
DEPS := .depend
OUT := game
VERSION := 0.5

CC := clang
CXX := clang++
CXXFLAGS :=  -std=c++20 -fdiagnostics-color=always
CFLAGS :=  -std=c++20 -fdiagnostics-color=always

INSTALL_DIR := /opt/redshoes
DIST_FILES := $(OUT) bin
BIN_DIR := /usr/bin

# mohali created this section himself with help of chatgpt :)

ifeq ($(MAKECMDGOALS),debug)
CXXFLAGS += -g
endif



ifeq ($(DBG_BUILD),1)
# -levent_extra is required only for `http` and `debug`
#LIBS += -levent_extra
endif
# _GNU_SOURCE is used to get splice(2), it also implies _BSD_SOURCE
#override CFLAGS +=  -D_DEFAULT_SOURCE -D_GNU_SOURCE -Wall

all: $(OUT)


debug: all


.PHONY: all clean distclean test

tags: *.c *.h
	ctags -R

$(CONF):
	@case `uname` in \
	Linux*) \
		echo "#define USE_IPTABLES" >$(CONF) \
		;; \
	OpenBSD) \
		echo "#define USE_PF" >$(CONF) \
		;; \
	*) \
		echo "Unknown system, only generic firewall code is compiled" 1>&2; \
		echo "/* Unknown system, only generic firewall code is compiled */" >$(CONF) \
		;; \
	esac
ifeq ($(DBG_BUILD),1)
	echo "#define DBG_BUILD 1" >>$(CONF)
endif

# Dependency on .git is useful to rebuild `version.c' after commit, but it breaks non-git builds.
gen/version.c: *.c *.h gen/.build
	rm -f $@.tmp
	echo '/* this file is auto-generated during build */' > $@.tmp
	echo '#include "../version.h"' >> $@.tmp
	echo 'const char* redsocks_version = ' >> $@.tmp
	if [ -d .git ]; then \
		echo '"redsocks.git/'`git describe --tags`'"'; \
		if [ `git status --porcelain | grep -v -c '^??'` != 0 ]; then \
			echo '"'"-unclean-$$(date --rfc-3339=seconds | tr ' ' 'T')-$${USER}@$$(uname -n)"'"'; \
		fi \
	else \
		echo '"redsocks/$(VERSION)"'; \
	fi >> $@.tmp
	echo ';' >> $@.tmp
	mv -f $@.tmp $@

gen/.build:
	mkdir -p gen
	touch $@

base.c: $(CONF)

$(DEPS): $(SRCS)
	gcc -MM $(SRCS) 2>/dev/null >$(DEPS) || \
	( \
		for I in $(wildcard *.h); do \
			export $${I//[-.]/_}_DEPS="`sed '/^\#[ \t]*include \?"\(.*\)".*/!d;s//\1/' $$I`"; \
		done; \
		echo -n >$(DEPS); \
		for SRC in $(SRCS); do \
			echo -n "$${SRC%.c}.o: " >>$(DEPS); \
			export SRC_DEPS="`sed '/\#[ \t]*include \?"\(.*\)".*/!d;s//\1/' $$SRC | sort`"; \
			while true; do \
				export SRC_DEPS_OLD="$$SRC_DEPS"; \
				export SRC_DEEP_DEPS=""; \
				for HDR in $$SRC_DEPS; do \
					eval export SRC_DEEP_DEPS="\"$$SRC_DEEP_DEPS \$$$${HDR//[-.]/_}_DEPS\""; \
				done; \
				export SRC_DEPS="`echo $$SRC_DEPS $$SRC_DEEP_DEPS | sed 's/  */\n/g' | sort -u`"; \
				test "$$SRC_DEPS" = "$$SRC_DEPS_OLD" && break; \
			done; \
			echo $$SRC $$SRC_DEPS >>$(DEPS); \
		done; \
	)

-include $(DEPS)

$(OUT): $(OBJS)
	$(CXX) $(CXXFLAGS)   -o $@ $^ $(LDFLAGS) $(LIBS)

clean:
	$(RM) $(OUT) $(CONF) $(OBJS)

distclean: clean
	$(RM) tags $(DEPS)
	$(RM) -r gen

tests/__build-tstamp__: $(OUT) tests/[a-z]* tests/[a-z]*/*
	cd tests && ./build
	touch $@

tests/prlimit-nofile: tests/prlimit-nofile.c
	$(CC)   $(CFLAGS) -o $@ $^

test: tests/__build-tstamp__ tests/prlimit-nofile
	cd tests && env $(TEST_ENV) ./run

install: all
	@if [ -d "$(INSTALL_DIR)" ]; then \
		echo "Removing $(INSTALL_DIR)"; \
		rm -rf "$(INSTALL_DIR)"; \
	fi
	@mkdir -p "$(INSTALL_DIR)"
	@echo "Coping $(DIST_FILES) to $(INSTALL_DIR)"
	@cp -r $(DIST_FILES) $(INSTALL_DIR)
	@echo "Creating symlink from $(INSTALL_DIR)/$(OUT) to $(BIN_DIR)/$(OUT)"
	@ln -sf $(INSTALL_DIR)/$(OUT)  $(BIN_DIR)/$(OUT)

uninstall:
	@if [ -d "$(INSTALL_DIR)" ]; then \
		echo "Removing $(INSTALL_DIR)"; \
		rm -rf "$(INSTALL_DIR)"; \
	fi
	if [ -L "$(BIN_DIR)/$(OUT)"]; then\
		echo "Unlinking $(BIN_DIR)/$(OUT)"; \
		rm -f "$(BIN_DIR)/$(OUT)"; \
	fi