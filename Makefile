INC = -I$(HOME)/include -I/usr/local/dmp/nifti/include
CC = g++
all: libbabak_lib

# because of functions in matrixops, linking the libbabak_lib will possibly require lapack libs.

singular_value_decomposition.o: singular_value_decomposition.c
	$(CC) -O2 -c $(INC) singular_value_decomposition.c

DKI.o: DKI.c
	$(CC) -O2 -c $(INC) DKI.c

artlib.o: artlib.c
	$(CC) -O2 -c $(INC) artlib.c

volume.o: volume.c
	$(CC) -O2 -c $(INC) volume.c

binomial.o: binomial.c
	$(CC) -O2 -c $(INC) binomial.c

smooth.o: smooth.cxx
	$(CC) -O2 -c $(INC) smooth.cxx

niftiimage.o: niftiimage.cxx
	$(CC) -O2 -c $(INC) niftiimage.cxx

utils.o: utils.c
	$(CC) -O2 -c $(INC) utils.c

nifti.o: nifti.cxx
	$(CC) -O2 -c $(INC) nifti.cxx

errorMessage.o: errorMessage.cxx
	$(CC) -O2 -c $(INC) errorMessage.cxx

maskOps.o: maskOps.c
	$(CC) -O2 -c $(INC) maskOps.c

EMFIT.o: EMFIT.c
	$(CC) -O2 -c $(INC) EMFIT.c

max_cc.o: max_cc.c
	$(CC) -O2 -c $(INC) max_cc.c

statistics.o: statistics.c
	$(CC) -O2 -c $(INC) statistics.c

ginverse.o: ginverse.c
	$(CC) -O2 -c $(INC) ginverse.c

permutation.o: permutation.c
	$(CC) -O2 -c $(INC) permutation.c

hpsort.o: hpsort.c
	$(CC) -O2 -c $(INC) hpsort.c

random.o: random.c
	$(CC) -O2 -c $(INC) random.c

dicomIO.o: dicomIO.c
	$(CC) -O2 -c $(INC) dicomIO.c

nkiIO.o: nkiIO.c
	$(CC) -O2 -c $(INC) nkiIO.c

matrixops.o: matrixops.c
	$(CC) -O2 -c $(INC) matrixops.c

subsets.o: subsets.c 
	$(CC) -O2 -c $(INC) subsets.c 

analyzeio.o: analyzeio.c 
	$(CC) -O2 -c $(INC) analyzeio.c 

getoption.o: getoption.c 
	$(CC) -O2 -c $(INC) getoption.c 

swap.o: swap.cxx 
	$(CC) -O2 -c $(INC) swap.cxx 

minmax.o: minmax.cxx
	$(CC) -O2 -c $(INC) minmax.cxx

fileinfo.o: fileinfo.c
	$(CC) -O2 -c $(INC) fileinfo.c

histogram.o: histogram.c
	$(CC) -O2 -c $(INC) histogram.c

resize.o: resize.c
	$(CC) -O2 -c $(INC) resize.c

gaussian_kernel.o: gaussian_kernel.cxx
	$(CC) -O2 -c $(INC) gaussian_kernel.cxx

convolution.o: convolution.c
	$(CC) -O2 -c $(INC) convolution.c

reslice.o: reslice.c
	$(CC) -O2 -c $(INC) reslice.c

matrixCom.o: matrixCom.c
	$(CC) -O2 -c $(INC) matrixCom.c

registration.o: registration.c
	$(CC) -O2 -c $(INC) registration.c

legendre.o: legendre.c
	$(CC) -O2 -c $(INC) legendre.c

cubicspline.o: cubicspline.c
	$(CC) -O2 -c $(INC) cubicspline.c

medianfilter.o: medianfilter.cxx
	$(CC) -O2 -c $(INC) medianfilter.cxx

directionCode.o: directionCode.cxx
	$(CC) -O2 -c $(INC) directionCode.cxx

checkNiftiFileExtension.o: checkNiftiFileExtension.cxx
	$(CC) -O2 -c $(INC) checkNiftiFileExtension.cxx

getNiftiImageOrientation.o: getNiftiImageOrientation.cxx
	$(CC) -O2 -c $(INC) getNiftiImageOrientation.cxx

isOrientationCodeValid.o: isOrientationCodeValid.cxx
	$(CC) -O2 -c $(INC) isOrientationCodeValid.cxx

PILtransform.o: PILtransform.cxx
	$(CC) -O2 -c $(INC) PILtransform.cxx

reorientVolume.o: reorientVolume.cxx
	$(CC) -O2 -c $(INC) reorientVolume.cxx

rotate.o: rotate.cxx
	$(CC) -O2 -c $(INC) rotate.cxx

setLowHigh.o: setLowHigh.cxx
	$(CC) -O2 -c $(INC) setLowHigh.cxx

compute_cm.o: compute_cm.cxx
	$(CC) -O2 -c $(INC) compute_cm.cxx

standardize.o: standardize.cxx
	$(CC) -O2 -c $(INC) standardize.cxx

sph.o: sph.cxx
	$(CC) -O2 -c $(INC) sph.cxx

libbabak_lib: singular_value_decomposition.o DKI.o artlib.o volume.o binomial.o smooth.o niftiimage.o utils.o nifti.o errorMessage.o maskOps.o EMFIT.o max_cc.o statistics.o ginverse.o permutation.o hpsort.o random.o dicomIO.o nkiIO.o matrixops.o subsets.o analyzeio.o getoption.o swap.o minmax.o fileinfo.o histogram.o resize.o gaussian_kernel.o convolution.o reslice.o matrixCom.o registration.o legendre.o cubicspline.o medianfilter.o directionCode.o checkNiftiFileExtension.o getNiftiImageOrientation.o isOrientationCodeValid.o PILtransform.o reorientVolume.o rotate.o setLowHigh.o compute_cm.o standardize.o sph.o
	ar -ru libbabak_lib_linux.a singular_value_decomposition.o DKI.o artlib.o volume.o binomial.o smooth.o niftiimage.o utils.o nifti.o errorMessage.o maskOps.o EMFIT.o max_cc.o statistics.o ginverse.o permutation.o hpsort.o random.o dicomIO.o nkiIO.o matrixops.o subsets.o analyzeio.o getoption.o swap.o minmax.o fileinfo.o histogram.o resize.o gaussian_kernel.o convolution.o reslice.o matrixCom.o registration.o legendre.o cubicspline.o medianfilter.o directionCode.o checkNiftiFileExtension.o getNiftiImageOrientation.o isOrientationCodeValid.o PILtransform.o reorientVolume.o rotate.o setLowHigh.o compute_cm.o standardize.o sph.o

clean: 
	rm -f *.o