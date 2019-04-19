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
NLAST      := 1500#   largest size to be timed for fast implementations.
NINC       := 48#     increment between sizes.

LDFLAGS    := -lpthread -m64 -lm -fopenmp

UTIL_OBJS  := FLA_Clock.o MaxAbsDiff.o RandomMatrix.o

# ---------------------

OBJS_JPI := driver.o Gemm_JPI.o

driver_JPI.x: $(OBJS_JPI) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JPI) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JPI.x $(LDFLAGS) 

JPI: driver_JPI.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JPI.x > data/output_JPI.m 
	tail data/output_JPI.m

# ---------------------

OBJS_JIP_PJI := driver.o Gemm_JIP_PJI.o

driver_JIP_PJI.x: $(OBJS_JIP_PJI) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JIP_PJI) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JIP_PJI.x $(LDFLAGS) 

JIP_PJI: driver_JIP_PJI.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JIP_PJI.x > data/output_JIP_PJI.m 
	tail data/output_JIP_PJI.m

# ---------------------

OBJS_JI_PJI := driver.o Gemm_JI_PJI.o

driver_JI_PJI.x: $(OBJS_JI_PJI) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_PJI) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_PJI.x $(LDFLAGS) 

JI_PJI: driver_JI_PJI.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_PJI.x > data/output_JI_PJI.m 
	tail data/output_JI_PJI.m

# ---------------------

OBJS_JIP_P_Ger := driver.o Gemm_JIP_P_Ger.o Ger_J_Axpy.o Axpy.o

driver_JIP_P_Ger.x: $(OBJS_JIP_P_Ger) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JIP_P_Ger) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JIP_P_Ger.x $(LDFLAGS) 

JIP_P_Ger: driver_JIP_P_Ger.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALL) $(NINC)" | ./driver_JIP_P_Ger.x > data/output_JIP_P_Ger.m 
	tail data/output_JIP_P_Ger.m

# ---------------------

OBJS_JI_P_Ger := driver.o Gemm_JI_P_Ger.o Ger_J_Axpy.o Axpy.o

driver_JI_P_Ger.x: $(OBJS_JI_P_Ger) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_P_Ger) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_P_Ger.x $(LDFLAGS) 

JI_P_Ger: driver_JI_P_Ger.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST_SMALL) $(NINC)" | ./driver_JI_P_Ger.x > data/output_JI_P_Ger.m 
	tail data/output_JI_P_Ger.m

# ---------------------

OBJS_JI_4x4Kernel := driver.o Gemm_JI_4x4Kernel.o 

driver_JI_4x4Kernel.x: $(OBJS_JI_4x4Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_4x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_4x4Kernel.x $(LDFLAGS) 

JI_4x4Kernel: driver_JI_4x4Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_4x4Kernel.x > data/output_JI_4x4Kernel.m 
	tail data/output_JI_4x4Kernel.m

# ---------------------

OBJS_JI_8x4Kernel := driver.o Gemm_JI_8x4Kernel.o 

driver_JI_8x4Kernel.x: $(OBJS_JI_8x4Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_8x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_8x4Kernel.x $(LDFLAGS) 

JI_8x4Kernel: driver_JI_8x4Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_8x4Kernel.x > data/output_JI_8x4Kernel.m 
	tail data/output_JI_8x4Kernel.m

# ---------------------

OBJS_JI_12x4Kernel := driver.o Gemm_JI_12x4Kernel.o 

driver_JI_12x4Kernel.x: $(OBJS_JI_12x4Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_12x4Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_12x4Kernel.x $(LDFLAGS) 

JI_12x4Kernel: driver_JI_12x4Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_12x4Kernel.x > data/output_JI_12x4Kernel.m 
	tail data/output_JI_12x4Kernel.m

# ---------------------

OBJS_JI_4x6Kernel := driver.o Gemm_JI_4x6Kernel.o 

driver_JI_4x6Kernel.x: $(OBJS_JI_4x6Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_4x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_4x6Kernel.x $(LDFLAGS) 

JI_4x6Kernel: driver_JI_4x6Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_4x6Kernel.x > data/output_JI_4x6Kernel.m 
	tail data/output_JI_4x6Kernel.m

# ---------------------

OBJS_JI_8x6Kernel := driver.o Gemm_JI_8x6Kernel.o 

driver_JI_8x6Kernel.x: $(OBJS_JI_8x6Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_8x6Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_8x6Kernel.x $(LDFLAGS) 

JI_8x6Kernel: driver_JI_8x6Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_8x6Kernel.x > data/output_JI_8x6Kernel.m 
	tail data/output_JI_8x6Kernel.m

# ---------------------

OBJS_JI_4x8Kernel := driver.o Gemm_JI_4x8Kernel.o 

driver_JI_4x8Kernel.x: $(OBJS_JI_4x8Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_4x8Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_4x8Kernel.x $(LDFLAGS) 

JI_4x8Kernel: driver_JI_4x8Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_4x8Kernel.x > data/output_JI_4x8Kernel.m 
	tail data/output_JI_8x6Kernel.m

# ---------------------

OBJS_JI_4x10Kernel := driver.o Gemm_JI_4x10Kernel.o 

driver_JI_4x10Kernel.x: $(OBJS_JI_4x10Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_4x10Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_4x10Kernel.x $(LDFLAGS) 

JI_4x10Kernel: driver_JI_4x10Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_4x10Kernel.x > data/output_JI_4x10Kernel.m 
	tail data/output_JI_4x10Kernel.m

# ---------------------

OBJS_JI_4x12Kernel := driver.o Gemm_JI_4x12Kernel.o 

driver_JI_4x12Kernel.x: $(OBJS_JI_4x12Kernel) $(UTIL_OBJS)
	$(LINKER) $(OBJS_JI_4x12Kernel) $(UTIL_OBJS) $(BLAS_LIB) -o driver_JI_4x12Kernel.x $(LDFLAGS) 

JI_4x12Kernel: driver_JI_4x12Kernel.x
	echo "$(NREPEATS) $(NFIRST) $(NLAST) $(NINC)" | ./driver_JI_4x12Kernel.x > data/output_JI_4x12Kernel.m 
	tail data/output_JI_4x12Kernel.m

# ---------------------                                                               
clean:
	rm -f *.o *~ core *.x *.pdf
