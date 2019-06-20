# HOME      := /Users/rvdg
# Make sure you have BLIS installed in your home directory.
BLAS_LIB  := $(HOME)/blis/lib/libblis.a
BLAS_INC  := $(HOME)/blis/include/blis

# indicate how the object files are to be created
CC         := gcc
LINKER     := $(CC)
CFLAGS     := -O3 -I$(BLAS_INC) -m64 -msse3 -std=c99 -march=native -D_POSIX_C_SOURCE=200112L -fopenmp
FFLAGS     := $(CFLAGS) 

# set the range of experiments to be performed
NREPEATS   := 3#       number of times each experiment is repeated.  The best time is reported.
NFIRST     := 48#     smallest size to be timed.
NLAST_SMALL:= 500#    largest size to be timed for slow implementations.
NLAST_SMALLISH:= 1500#    largest size to be timed for slow implementations.
NLAST      := 2000#   largest size to be timed for fast implementations.
NINC       := 48#     increment between sizes.

LDFLAGS    := -fopenmp -lpthread -m64 -lm 

UTIL_OBJS  := FLA_Clock.o MaxAbsDiff.o RandomMatrix.o

# -------------- Set blocking parameters ----------

MC :=  72
KC :=  256
NC := 2016

# ---------------------

SRC_IJP := Gemm_IJP.c 

IJP: $(OBJS_IJP) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_IJP) driver.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_IJP.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_IJP.x > data/output_IJP.m 
	tail data/output_IJP.m

# ---------------------


SRC_MT_IJP := Gemm_MT_IJP.c 

MT_IJP: $(OBJS_MT_IJP) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_MT_IJP) driver.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_IJP.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_MT_IJP.x > data/output_MT_IJP.m 
	tail data/output_MT_IJP.m

# ---------------------

SRC_JPI := Gemm_JPI.c 

JPI: $(OBJS_JPI) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_JPI) driver.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_JPI.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_JPI.x > data/output_JPI.m 
	tail data/output_JPI.m

# ---------------------


SRC_MT_JPI := Gemm_MT_JPI.c 

MT_JPI: $(OBJS_MT_JPI) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_MT_JPI) driver.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_JPI.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_MT_JPI.x > data/output_MT_JPI.m 
	tail data/output_MT_JPI.m

# ---------------------

SRC_Five_Loops_Packed_8x6Kernel := driver.c Gemm_Five_Loops_Packed_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_8x6Kernel:  $(SRC_Five_Loops_Packed_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_Five_Loops_Packed_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_8x6Kernel.x > data/output_Five_Loops_Packed_8x6Kernel.m 
	tail data/output_Five_Loops_Packed_8x6Kernel.m

# ---------------------

SRC_Five_Loops_Packed_12x4Kernel := driver.c Gemm_Five_Loops_Packed_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_12x4Kernel:  $(SRC_Five_Loops_Packed_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_Five_Loops_Packed_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_12x4Kernel.x > data/output_Five_Loops_Packed_12x4Kernel.m 
	tail data/output_Five_Loops_Packed_12x4Kernel.m

# ---------------------

SRC_MT_Loop1_8x6Kernel := driver.c Gemm_MT_Loop1_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

MT_Loop1_8x6Kernel:  $(SRC_MT_Loop1_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop1_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop1_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_MT_Loop1_8x6Kernel.x > data/output_MT_Loop1_8x6Kernel.m 
	tail data/output_MT_Loop1_8x6Kernel.m

# ---------------------

SRC_MT_Loop1_12x4Kernel := driver.c Gemm_MT_Loop1_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

MT_Loop1_12x4Kernel:  $(SRC_MT_Loop1_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop1_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop1_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_MT_Loop1_12x4Kernel.x > data/output_MT_Loop1_12x4Kernel.m 
	tail data/output_MT_Loop1_12x4Kernel.m

# ---------------------

SRC_MT_Loop2_8x6Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

MT_Loop2_8x6Kernel:  $(SRC_MT_Loop2_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop2_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_8x6Kernel.x > data/output_MT_Loop2_8x6Kernel.m 
	tail data/output_MT_Loop2_8x6Kernel.m

# ---------------------

SRC_MT_Loop2_12x4Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

MT_Loop2_12x4Kernel:  $(SRC_MT_Loop2_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop2_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_12x4Kernel.x > data/output_MT_Loop2_12x4Kernel.m 
	tail data/output_MT_Loop2_12x4Kernel.m

# ---------------------

SRC_MT_Loop3_8x6Kernel := driver.c Gemm_MT_Loop3_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

MT_Loop3_8x6Kernel:  $(SRC_MT_Loop3_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop3_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop3_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop3_8x6Kernel.x > data/output_MT_Loop3_8x6Kernel.m 
	tail data/output_MT_Loop3_8x6Kernel.m

# ---------------------

SRC_MT_Loop3_12x4Kernel := driver.c Gemm_MT_Loop3_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

MT_Loop3_12x4Kernel:  $(SRC_MT_Loop3_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop3_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop3_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop3_12x4Kernel.x > data/output_MT_Loop3_12x4Kernel.m 
	tail data/output_MT_Loop3_12x4Kernel.m

# ---------------------

SRC_MT_Loop4_8x6Kernel := driver.c Gemm_MT_Loop4_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

MT_Loop4_8x6Kernel:  $(SRC_MT_Loop4_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop4_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop4_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop4_8x6Kernel.x > data/output_MT_Loop4_8x6Kernel.m 
	tail data/output_MT_Loop4_8x6Kernel.m

# ---------------------

SRC_MT_Loop4_12x4Kernel := driver.c Gemm_MT_Loop4_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

MT_Loop4_12x4Kernel:  $(SRC_MT_Loop4_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop4_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop4_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop4_12x4Kernel.x > data/output_MT_Loop4_12x4Kernel.m 
	tail data/output_MT_Loop4_12x4Kernel.m

# ---------------------

SRC_MT_Loop5_8x6Kernel := driver.c Gemm_MT_Loop5_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

MT_Loop5_8x6Kernel:  $(SRC_MT_Loop5_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop5_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop5_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) 2500 $(NINC)" | ./driver_MT_Loop5_8x6Kernel.x > data/output_MT_Loop5_8x6Kernel.m 
	tail data/output_MT_Loop5_8x6Kernel.m

# ---------------------

SRC_MT_Loop5_12x4Kernel := driver.c Gemm_MT_Loop5_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

MT_Loop5_12x4Kernel:  $(SRC_MT_Loop5_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop5_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop5_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop5_12x4Kernel.x > data/output_MT_Loop5_12x4Kernel.m 
	tail data/output_MT_Loop5_12x4Kernel.m

# ---------------------

SRC_MT_Loop2_MT_PackA_8x6Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_8x6Kernel_Packed.c MT_PackA.c PackB.c

MT_Loop2_MT_PackA_8x6Kernel:  $(SRC_MT_Loop2_MT_PackA_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop2_MT_PackA_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_MT_PackA_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_MT_PackA_8x6Kernel.x > data/output_MT_Loop2_MT_PackA_8x6Kernel.m 
	tail data/output_MT_Loop2_MT_PackA_8x6Kernel.m

# ---------------------

SRC_MT_Loop2_MT_PackA_12x4Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_12x4Kernel_Packed.c MT_PackA.c PackB.c

MT_Loop2_MT_PackA_12x4Kernel:  $(SRC_MT_Loop2_MT_PackA_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop2_MT_PackA_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_MT_PackA_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_MT_PackA_12x4Kernel.x > data/output_MT_Loop2_MT_PackA_12x4Kernel.m 
	tail data/output_MT_Loop2_MT_PackA_12x4Kernel.m

# ---------------------

SRC_MT_Loop2_MT_PackB_8x6Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_8x6Kernel_Packed.c MT_PackB.c PackA.c

MT_Loop2_MT_PackB_8x6Kernel:  $(SRC_MT_Loop2_MT_PackB_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop2_MT_PackB_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_MT_PackB_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_MT_PackB_8x6Kernel.x > data/output_MT_Loop2_MT_PackB_8x6Kernel.m 
	tail data/output_MT_Loop2_MT_PackB_8x6Kernel.m

# ---------------------

SRC_MT_Loop2_MT_PackAB_8x6Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_8x6Kernel_Packed.c MT_PackB.c MT_PackA.c

MT_Loop2_MT_PackAB_8x6Kernel:  $(SRC_MT_Loop2_MT_PackAB_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop2_MT_PackAB_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_MT_PackAB_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_MT_PackAB_8x6Kernel.x > data/output_MT_Loop2_MT_PackAB_8x6Kernel.m 
	tail data/output_MT_Loop2_MT_PackAB_8x6Kernel.m

# ---------------------

SRC_MT_Loop2_MT_PackAB_8x6Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_8x6Kernel_Packed.c MT_PackA.c MT_PackB.c

MT_Loop2_MT_PackAB_8x6Kernel:  $(SRC_MT_Loop2_MT_PackAB_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop2_MT_PackAB_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_MT_PackAB_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_MT_PackAB_8x6Kernel.x > data/output_MT_Loop2_MT_PackAB_8x6Kernel.m 
	tail data/output_MT_Loop2_MT_PackAB_8x6Kernel.m

# ---------------------

SRC_MT_Loop2_MT_PackAB_A12x4Kernel := driver.c Gemm_MT_Loop2_MRxNRKernel.c Gemm_12x4Kernel_Packed.c MT_PackA.c MTPackB.c

MT_Loop2_MT_PackAB_12x4Kernel:  $(SRC_MT_Loop2_MT_PackAB_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_MT_Loop2_MT_PackAB_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop2_MT_PackAB_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop2_MT_PackAB_12x4Kernel.x > data/output_MT_Loop2_MT_PackAB_12x4Kernel.m 
	tail data/output_MT_Loop2_MT_PackAB_12x4Kernel.m

# ---------------------

SRC_MT_Loop3_MT_PackB_8x6Kernel := driver.c Gemm_MT_Loop3_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c MT_PackB.c

MT_Loop3_MT_PackB_8x6Kernel:  $(SRC_MT_Loop3_MT_PackB_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_MT_Loop3_MT_PackB_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_MT_Loop3_MT_PackB_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_MT_Loop3_MT_PackB_8x6Kernel.x > data/output_MT_Loop3_MT_PackB_8x6Kernel.m 
	tail data/output_MT_Loop3_MT_PackB_8x6Kernel.m

# ---------------------

clean:
	rm -f *.o *~ core *.x *.pdf
