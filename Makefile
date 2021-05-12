# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.19

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /var/lib/snapd/snap/clion/151/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/151/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/djarin/CLionProjects/dilith

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/djarin/CLionProjects/dilith

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/var/lib/snapd/snap/clion/151/bin/cmake/linux/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/var/lib/snapd/snap/clion/151/bin/cmake/linux/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/djarin/CLionProjects/dilith/CMakeFiles /home/djarin/CLionProjects/dilith//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/djarin/CLionProjects/dilith/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named dilith

# Build rule for target.
dilith: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 dilith
.PHONY : dilith

# fast build rule for target.
dilith/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/build
.PHONY : dilith/fast

fips202.o: fips202.c.o

.PHONY : fips202.o

# target to build an object file
fips202.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/fips202.c.o
.PHONY : fips202.c.o

fips202.i: fips202.c.i

.PHONY : fips202.i

# target to preprocess a source file
fips202.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/fips202.c.i
.PHONY : fips202.c.i

fips202.s: fips202.c.s

.PHONY : fips202.s

# target to generate assembly for a file
fips202.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/fips202.c.s
.PHONY : fips202.c.s

ntt.o: ntt.c.o

.PHONY : ntt.o

# target to build an object file
ntt.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/ntt.c.o
.PHONY : ntt.c.o

ntt.i: ntt.c.i

.PHONY : ntt.i

# target to preprocess a source file
ntt.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/ntt.c.i
.PHONY : ntt.c.i

ntt.s: ntt.c.s

.PHONY : ntt.s

# target to generate assembly for a file
ntt.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/ntt.c.s
.PHONY : ntt.c.s

packing.o: packing.c.o

.PHONY : packing.o

# target to build an object file
packing.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/packing.c.o
.PHONY : packing.c.o

packing.i: packing.c.i

.PHONY : packing.i

# target to preprocess a source file
packing.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/packing.c.i
.PHONY : packing.c.i

packing.s: packing.c.s

.PHONY : packing.s

# target to generate assembly for a file
packing.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/packing.c.s
.PHONY : packing.c.s

poly.o: poly.c.o

.PHONY : poly.o

# target to build an object file
poly.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/poly.c.o
.PHONY : poly.c.o

poly.i: poly.c.i

.PHONY : poly.i

# target to preprocess a source file
poly.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/poly.c.i
.PHONY : poly.c.i

poly.s: poly.c.s

.PHONY : poly.s

# target to generate assembly for a file
poly.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/poly.c.s
.PHONY : poly.c.s

polyvec.o: polyvec.c.o

.PHONY : polyvec.o

# target to build an object file
polyvec.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/polyvec.c.o
.PHONY : polyvec.c.o

polyvec.i: polyvec.c.i

.PHONY : polyvec.i

# target to preprocess a source file
polyvec.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/polyvec.c.i
.PHONY : polyvec.c.i

polyvec.s: polyvec.c.s

.PHONY : polyvec.s

# target to generate assembly for a file
polyvec.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/polyvec.c.s
.PHONY : polyvec.c.s

randombytes.o: randombytes.c.o

.PHONY : randombytes.o

# target to build an object file
randombytes.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/randombytes.c.o
.PHONY : randombytes.c.o

randombytes.i: randombytes.c.i

.PHONY : randombytes.i

# target to preprocess a source file
randombytes.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/randombytes.c.i
.PHONY : randombytes.c.i

randombytes.s: randombytes.c.s

.PHONY : randombytes.s

# target to generate assembly for a file
randombytes.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/randombytes.c.s
.PHONY : randombytes.c.s

reduce.o: reduce.c.o

.PHONY : reduce.o

# target to build an object file
reduce.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/reduce.c.o
.PHONY : reduce.c.o

reduce.i: reduce.c.i

.PHONY : reduce.i

# target to preprocess a source file
reduce.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/reduce.c.i
.PHONY : reduce.c.i

reduce.s: reduce.c.s

.PHONY : reduce.s

# target to generate assembly for a file
reduce.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/reduce.c.s
.PHONY : reduce.c.s

rounding.o: rounding.c.o

.PHONY : rounding.o

# target to build an object file
rounding.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/rounding.c.o
.PHONY : rounding.c.o

rounding.i: rounding.c.i

.PHONY : rounding.i

# target to preprocess a source file
rounding.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/rounding.c.i
.PHONY : rounding.c.i

rounding.s: rounding.c.s

.PHONY : rounding.s

# target to generate assembly for a file
rounding.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/rounding.c.s
.PHONY : rounding.c.s

sign.o: sign.c.o

.PHONY : sign.o

# target to build an object file
sign.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/sign.c.o
.PHONY : sign.c.o

sign.i: sign.c.i

.PHONY : sign.i

# target to preprocess a source file
sign.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/sign.c.i
.PHONY : sign.c.i

sign.s: sign.c.s

.PHONY : sign.s

# target to generate assembly for a file
sign.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/sign.c.s
.PHONY : sign.c.s

symmetric-shake.o: symmetric-shake.c.o

.PHONY : symmetric-shake.o

# target to build an object file
symmetric-shake.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/symmetric-shake.c.o
.PHONY : symmetric-shake.c.o

symmetric-shake.i: symmetric-shake.c.i

.PHONY : symmetric-shake.i

# target to preprocess a source file
symmetric-shake.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/symmetric-shake.c.i
.PHONY : symmetric-shake.c.i

symmetric-shake.s: symmetric-shake.c.s

.PHONY : symmetric-shake.s

# target to generate assembly for a file
symmetric-shake.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/symmetric-shake.c.s
.PHONY : symmetric-shake.c.s

testvectors.o: testvectors.c.o

.PHONY : testvectors.o

# target to build an object file
testvectors.c.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/testvectors.c.o
.PHONY : testvectors.c.o

testvectors.i: testvectors.c.i

.PHONY : testvectors.i

# target to preprocess a source file
testvectors.c.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/testvectors.c.i
.PHONY : testvectors.c.i

testvectors.s: testvectors.c.s

.PHONY : testvectors.s

# target to generate assembly for a file
testvectors.c.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/dilith.dir/build.make CMakeFiles/dilith.dir/testvectors.c.s
.PHONY : testvectors.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... rebuild_cache"
	@echo "... dilith"
	@echo "... fips202.o"
	@echo "... fips202.i"
	@echo "... fips202.s"
	@echo "... ntt.o"
	@echo "... ntt.i"
	@echo "... ntt.s"
	@echo "... packing.o"
	@echo "... packing.i"
	@echo "... packing.s"
	@echo "... poly.o"
	@echo "... poly.i"
	@echo "... poly.s"
	@echo "... polyvec.o"
	@echo "... polyvec.i"
	@echo "... polyvec.s"
	@echo "... randombytes.o"
	@echo "... randombytes.i"
	@echo "... randombytes.s"
	@echo "... reduce.o"
	@echo "... reduce.i"
	@echo "... reduce.s"
	@echo "... rounding.o"
	@echo "... rounding.i"
	@echo "... rounding.s"
	@echo "... sign.o"
	@echo "... sign.i"
	@echo "... sign.s"
	@echo "... symmetric-shake.o"
	@echo "... symmetric-shake.i"
	@echo "... symmetric-shake.s"
	@echo "... testvectors.o"
	@echo "... testvectors.i"
	@echo "... testvectors.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

