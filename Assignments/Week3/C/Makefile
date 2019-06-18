#HOME      := /Users/rvdg
# Make sure you have BLIS installed in your home directory (or some other BLAS library)
BLAS_LIB  := $(HOME)/blis/lib/libblis.a
BLAS_INC  := $(HOME)/blis/include/blis

# indicate how the object files are to be created
CC         := gcc
LINKER     := $(CC)
CFLAGS     := -O3 -I$(BLAS_INC) -m64 -mavx2 -std=c99 -march=native -fopenmp -D_POSIX_C_SOURCE=200809L
FFLAGS     := $(CFLAGS) 

# set the range of experiments to be performed
NREPEATS   := 3#       number of times each experiment is repeated.  The best time is reported.
NFIRST     := 48#     smallest size to be timed.
NLAST_SMALL:= 500#    largest size to be timed for slow implementations.
NLAST_SMALLISH:= 1000#    largest size to be timed for slowish implementations.
NLAST      := 1500#   largest size to be timed for fast implementations.
NINC       := 48#     increment between sizes.

LDFLAGS    := -lpthread -m64 -lm -fopenmp

UTIL_OBJS  := FLA_Clock.o MaxAbsDiff.o RandomMatrix.o

# -------------- Set blocking parameters ----------

MC :=  264
KC :=  48
NC := 2016

# ---------------------


SRC_IJP_JI_4x4Kernel := driver.c Gemm_IJP_JI_MRxNRKernel.c Gemm_4x4Kernel.c 

IJP_JI_4x4Kernel:  $(SRC_IJP_JI_4x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=4' -D'NR=4' $(SRC_IJP_JI_4x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IJP_JI_4x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IJP_JI_4x4Kernel.x > data/output_IJP_JI_4x4Kernel.m 
	tail data/output_IJP_JI_4x4Kernel.m

# ---------------------

SRC_IJP_JI_12x4Kernel := driver.c Gemm_IJP_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

IJP_JI_12x4Kernel:  $(SRC_IJP_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_IJP_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IJP_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IJP_JI_12x4Kernel.x > data/output_IJP_JI_12x4Kernel.m 
	tail data/output_IJP_JI_12x4Kernel.m

# ---------------------

SRC_IJP_JI_8x6Kernel := driver.c Gemm_IJP_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

IJP_JI_8x6Kernel:  $(SRC_IJP_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_IJP_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IJP_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IJP_JI_8x6Kernel.x > data/output_IJP_JI_8x6Kernel.m 
	tail data/output_IJP_JI_8x6Kernel.m

# ---------------------

SRC_IJP_JI_8x4Kernel := driver.c Gemm_IJP_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

IJP_JI_8x4Kernel:  $(SRC_IJP_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_IJP_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IJP_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IJP_JI_8x4Kernel.x > data/output_IJP_JI_8x4Kernel.m 
	tail data/output_IJP_JI_8x4Kernel.m

# ---------------------

SRC_IPJ_JI_12x4Kernel := driver.c Gemm_IPJ_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

IPJ_JI_12x4Kernel:  $(SRC_IPJ_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_IPJ_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IPJ_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IPJ_JI_12x4Kernel.x > data/output_IPJ_JI_12x4Kernel.m 
	tail data/output_IPJ_JI_12x4Kernel.m

# ---------------------

SRC_IPJ_JI_8x6Kernel := driver.c Gemm_IPJ_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

IPJ_JI_8x6Kernel:  $(SRC_IPJ_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_IPJ_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IPJ_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IPJ_JI_8x6Kernel.x > data/output_IPJ_JI_8x6Kernel.m 
	tail data/output_IPJ_JI_8x6Kernel.m

# ---------------------

SRC_IPJ_JI_8x4Kernel := driver.c Gemm_IPJ_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

IPJ_JI_8x4Kernel:  $(SRC_IPJ_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_IPJ_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_IPJ_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_IPJ_JI_8x4Kernel.x > data/output_IPJ_JI_8x4Kernel.m 
	tail data/output_IPJ_JI_8x4Kernel.m

# ---------------------

SRC_JIP_JI_12x4Kernel := driver.c Gemm_JIP_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

JIP_JI_12x4Kernel:  $(SRC_JIP_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_JIP_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JIP_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JIP_JI_12x4Kernel.x > data/output_JIP_JI_12x4Kernel.m 
	tail data/output_JIP_JI_12x4Kernel.m

# ---------------------

SRC_JIP_JI_8x6Kernel := driver.c Gemm_JIP_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

JIP_JI_8x6Kernel:  $(SRC_JIP_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_JIP_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JIP_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JIP_JI_8x6Kernel.x > data/output_JIP_JI_8x6Kernel.m 
	tail data/output_JIP_JI_8x6Kernel.m

# ---------------------

SRC_JIP_JI_8x4Kernel := driver.c Gemm_JIP_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

JIP_JI_8x4Kernel:  $(SRC_JIP_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_JIP_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JIP_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JIP_JI_8x4Kernel.x > data/output_JIP_JI_8x4Kernel.m 
	tail data/output_JIP_JI_8x4Kernel.m

# ---------------------

SRC_JPI_JI_12x4Kernel := driver.c Gemm_JPI_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

JPI_JI_12x4Kernel:  $(SRC_JPI_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_JPI_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JPI_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JPI_JI_12x4Kernel.x > data/output_JPI_JI_12x4Kernel.m 
	tail data/output_JPI_JI_12x4Kernel.m

# ---------------------

SRC_JPI_JI_8x6Kernel := driver.c Gemm_JPI_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

JPI_JI_8x6Kernel:  $(SRC_JPI_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_JPI_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JPI_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JPI_JI_8x6Kernel.x > data/output_JPI_JI_8x6Kernel.m 
	tail data/output_JPI_JI_8x6Kernel.m

# ---------------------

SRC_JPI_JI_8x4Kernel := driver.c Gemm_JPI_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

JPI_JI_8x4Kernel:  $(SRC_JPI_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_JPI_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JPI_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JPI_JI_8x4Kernel.x > data/output_JPI_JI_8x4Kernel.m 
	tail data/output_JPI_JI_8x4Kernel.m

# ---------------------

SRC_PIJ_JI_12x4Kernel := driver.c Gemm_PIJ_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

PIJ_JI_12x4Kernel:  $(SRC_PIJ_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_PIJ_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PIJ_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PIJ_JI_12x4Kernel.x > data/output_PIJ_JI_12x4Kernel.m 
	tail data/output_PIJ_JI_12x4Kernel.m

# ---------------------

SRC_PIJ_JI_8x6Kernel := driver.c Gemm_PIJ_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

PIJ_JI_8x6Kernel:  $(SRC_PIJ_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_PIJ_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PIJ_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PIJ_JI_8x6Kernel.x > data/output_PIJ_JI_8x6Kernel.m 
	tail data/output_PIJ_JI_8x6Kernel.m

# ---------------------

SRC_PIJ_JI_8x4Kernel := driver.c Gemm_PIJ_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

PIJ_JI_8x4Kernel:  $(SRC_PIJ_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_PIJ_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PIJ_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PIJ_JI_8x4Kernel.x > data/output_PIJ_JI_8x4Kernel.m 
	tail data/output_PIJ_JI_8x4Kernel.m

# ---------------------

SRC_PJI_JI_12x4Kernel := driver.c Gemm_PJI_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

PJI_JI_12x4Kernel:  $(SRC_PJI_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_PJI_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PJI_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PJI_JI_12x4Kernel.x > data/output_PJI_JI_12x4Kernel.m 
	tail data/output_PJI_JI_12x4Kernel.m

# ---------------------

SRC_PJI_JI_8x6Kernel := driver.c Gemm_PJI_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

PJI_JI_8x6Kernel:  $(SRC_PJI_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_PJI_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PJI_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PJI_JI_8x6Kernel.x > data/output_PJI_JI_8x6Kernel.m 
	tail data/output_PJI_JI_8x6Kernel.m

# ---------------------

SRC_PJI_JI_8x4Kernel := driver.c Gemm_PJI_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

PJI_JI_8x4Kernel:  $(SRC_PJI_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_PJI_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PJI_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PJI_JI_8x4Kernel.x > data/output_PJI_JI_8x4Kernel.m 
	tail data/output_PJI_JI_8x4Kernel.m

# ---------------------

SRC_PI_JI_12x4Kernel := driver.c Gemm_PI_JI_MRxNRKernel.c Gemm_12x4Kernel.c 

PI_JI_12x4Kernel:  $(SRC_PI_JI_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=12' -D'NR=4' $(SRC_PI_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PI_JI_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PI_JI_12x4Kernel.x > data/output_PI_JI_12x4Kernel.m 
	tail data/output_PI_JI_12x4Kernel.m

# ---------------------

SRC_PI_JI_8x6Kernel := driver.c Gemm_PI_JI_MRxNRKernel.c Gemm_8x6Kernel.c 

PI_JI_8x6Kernel:  $(SRC_PI_JI_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=6' $(SRC_PI_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PI_JI_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PI_JI_8x6Kernel.x > data/output_PI_JI_8x6Kernel.m 
	tail data/output_PI_JI_8x6Kernel.m

# ---------------------

SRC_PI_JI_8x4Kernel := driver.c Gemm_PI_JI_MRxNRKernel.c Gemm_8x4Kernel.c 

PI_JI_8x4Kernel:  $(SRC_PI_JI_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MR=8' -D'NR=4' $(SRC_PI_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_PI_JI_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_PI_JI_8x4Kernel.x > data/output_PI_JI_8x4Kernel.m 
	tail data/output_PI_JI_8x4Kernel.m

# ---------------------

SRC_PI_JI_12x4_MCxKC := Gemm_PI_JI_MCxKC.c Gemm_12x4Kernel.c

PI_JI_12x4_MCxKC: $(OBJS_PI_JI_12x4_MCxKC) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_PI_JI_12x4_MCxKC) -D'MR=12' -D'NR=4' driver_MCxKC.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_PI_JI_12x4_MCxKC.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_PI_JI_12x4_MCxKC.x > data/output_PI_JI_12x4_MCxKC.m 
	tail data/output_PI_JI_12x4_MCxKC.m

# ---------------------

SRC_PI_JI_8x6_MCxKC := Gemm_PI_JI_MCxKC.c Gemm_8x6Kernel.c

PI_JI_8x6_MCxKC: $(OBJS_PI_JI_8x6_MCxKC) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_PI_JI_8x6_MCxKC) -D'MR=8' -D'NR=6' driver_MCxKC.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_PI_JI_8x6_MCxKC.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_PI_JI_8x6_MCxKC.x > data/output_PI_JI_8x6_MCxKC.m 
	tail data/output_PI_JI_8x6_MCxKC.m

# ---------------------

SRC_PI_JI_8x4_MCxKC := Gemm_PI_JI_MCxKC.c Gemm_8x4Kernel.c

PI_JI_8x4_MCxKC: $(OBJS_PI_JI_8x4_MCxKC) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) $(SRC_PI_JI_8x4_MCxKC) -D'MR=8' -D'NR=4' driver_MCxKC.c $(UTIL_OBJS) $(BLAS_LIB) -o driver_PI_JI_8x4_MCxKC.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALLISH) $(NINC)" | ./driver_PI_JI_8x4_MCxKC.x > data/output_PI_JI_8x4_MCxKC.m 
	tail data/output_PI_JI_8x4_MCxKC.m

# ---------------------

SRC_Five_Loops_4x4Kernel := driver.c Gemm_Five_Loops_MRxNRKernel.c Gemm_4x4Kernel.c 

Five_Loops_4x4Kernel:  $(SRC_Five_Loops_4x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=4' -D'NR=4' $(SRC_Five_Loops_4x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_4x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_4x4Kernel.x > data/output_Five_Loops_4x4Kernel.m 
	tail data/output_Five_Loops_4x4Kernel.m

# ---------------------

SRC_Five_Loops_12x4Kernel := driver.c Gemm_Five_Loops_MRxNRKernel.c Gemm_12x4Kernel.c 

Five_Loops_12x4Kernel:  $(SRC_Five_Loops_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_Five_Loops_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_12x4Kernel.x > data/output_Five_Loops_12x4Kernel.m 
	tail data/output_Five_Loops_12x4Kernel.m

# ---------------------

SRC_Five_Loops_12x4Kernel_ldim := driver_ldim.c Gemm_Five_Loops_MRxNRKernel.c Gemm_12x4Kernel.c 

Five_Loops_12x4Kernel_ldim:  $(SRC_Five_Loops_12x4Kernel_ldim) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_Five_Loops_12x4Kernel_ldim) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_12x4Kernel_ldim.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_12x4Kernel_ldim.x > data/output_Five_Loops_12x4Kernel_ldim.m 
	tail data/output_Five_Loops_12x4Kernel_ldim.m

# ---------------------

SRC_Five_Loops_Packed_4x4Kernel := driver.c Gemm_Five_Loops_Packed_MRxNRKernel.c Gemm_4x4Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_4x4Kernel:  $(SRC_Five_Loops_Packed_4x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=4' -D'NR=4' $(SRC_Five_Loops_Packed_4x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_4x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_4x4Kernel.x > data/output_Five_Loops_Packed_4x4Kernel.m 
	tail data/output_Five_Loops_Packed_4x4Kernel.m

# ---------------------

SRC_Five_Loops_Packed_12x4Kernel := driver.c Gemm_Five_Loops_Packed_MRxNRKernel.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_12x4Kernel:  $(SRC_Five_Loops_Packed_12x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=12' -D'NR=4' $(SRC_Five_Loops_Packed_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_12x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_12x4Kernel.x > data/output_Five_Loops_Packed_12x4Kernel.m 
	tail data/output_Five_Loops_Packed_12x4Kernel.m

# ---------------------

SRC_Five_Loops_Packed_8x6Kernel := driver.c Gemm_Five_Loops_Packed_MRxNRKernel.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_8x6Kernel:  $(SRC_Five_Loops_Packed_8x6Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=6' $(SRC_Five_Loops_Packed_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_8x6Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_8x6Kernel.x > data/output_Five_Loops_Packed_8x6Kernel.m 
	tail data/output_Five_Loops_Packed_8x6Kernel.m


# ---------------------

SRC_Five_Loops_Packed_8x4Kernel := driver.c Gemm_Five_Loops_Packed_MRxNRKernel.c Gemm_8x4Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_8x4Kernel:  $(SRC_Five_Loops_Packed_8x4Kernel) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'MC=$(MC)' -D'NC=$(NC)' -D'KC=$(KC)' -D'MR=8' -D'NR=4' $(SRC_Five_Loops_Packed_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_8x4Kernel.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_8x4Kernel.x > data/output_Five_Loops_Packed_8x4Kernel.m 
	tail data/output_Five_Loops_Packed_8x4Kernel.m


# ---------------------

SRC_Five_Loops_Packed_12x4Kernel_MCxKC := driver_MCxKC.c Gemm_Five_Loops_Packed_MRxNRKernel_MCxKC.c Gemm_12x4Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_12x4Kernel_MCxKC:  $(SRC_Five_Loops_Packed_12x4Kernel_MCxKC) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'NC=$(NC)' -D'MR=12' -D'NR=4' $(SRC_Five_Loops_Packed_12x4Kernel_MCxKC) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_12x4Kernel_MCxKC.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_12x4Kernel_MCxKC.x > data/output_Five_Loops_Packed_12x4Kernel_MCxKC.m 
	tail data/output_Five_Loops_Packed_12x4Kernel_MCxKC.m

# ---------------------

SRC_Five_Loops_Packed_8x6Kernel_MCxKC := driver_MCxKC.c Gemm_Five_Loops_Packed_MRxNRKernel_MCxKC.c Gemm_8x6Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_8x6Kernel_MCxKC:  $(SRC_Five_Loops_Packed_8x6Kernel_MCxKC) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'NC=$(NC)' -D'MR=8' -D'NR=6' $(SRC_Five_Loops_Packed_8x6Kernel_MCxKC) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_8x6Kernel_MCxKC.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_8x6Kernel_MCxKC.x > data/output_Five_Loops_Packed_8x6Kernel_MCxKC.m 
	tail data/output_Five_Loops_Packed_8x6Kernel_MCxKC.m

# ---------------------

SRC_Five_Loops_Packed_8x4Kernel_MCxKC := driver_MCxKC.c Gemm_Five_Loops_Packed_MRxNRKernel_MCxKC.c Gemm_8x4Kernel_Packed.c PackA.c PackB.c

Five_Loops_Packed_8x4Kernel_MCxKC:  $(SRC_Five_Loops_Packed_8x4Kernel_MCxKC) $(UTIL_OBJS) Makefile
	$(LINKER) $(CFLAGS) -D'NC=$(NC)' -D'MR=8' -D'NR=4' $(SRC_Five_Loops_Packed_8x4Kernel_MCxKC) $(UTIL_OBJS) $(BLAS_LIB) -o driver_Five_Loops_Packed_8x4Kernel_MCxKC.x $(LDFLAGS) 
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_Five_Loops_Packed_8x4Kernel_MCxKC.x > data/output_Five_Loops_Packed_8x4Kernel_MCxKC.m 
	tail data/output_Five_Loops_Packed_8x4Kernel_MCxKC.m

# ---------------------                                                               
clean:
	rm -f *.o *~ core *.x *.pdf
