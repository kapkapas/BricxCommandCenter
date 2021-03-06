PROGRAMS = nbc.exe
VER = 1.2.1.r5
DOBJECTS=uNXTClasses.dcu uPreprocess.dcu Parser10.dcu P10Build.dcu uNXCComp.dcu uRPGComp.dcu uRIC.dcu uRICComp.dcu uNBCCommon.dcu uNXTConstants.dcu uNBCInterface.dcu nbc.dpr
DEFAULT_INCLUDE_DIR=.

all:: $(DOBJECTS) $(PROGRAMS)

clean::
	rm -f *.o *.ppu *.rst *.compiled *.dcu ../*.dcu ../bricktools/*.dcu ../pbr/*.dcu nbc_preproc.inc
	rm -f ../*.o ../*.ppu ../*.rst ../bricktools/*.o ../bricktools/*.ppu ../pbr/*.o ../pbr/*.ppu
	rm -f ../*.o ../*.ppu ../*.rst ../bricktools/*.o ../bricktools/*.ppu

realclean:: clean
	rm -f $(PROGRAMS) mkdata.exe NBCCommonData.pas NXTDefsData.pas NXCDefsData.pas SPCDefsData.pas SPMemData.pas

# Delphi
#TOOLPREFIX=C:/win32apps/Borland/Delphi7/Bin/
DELPHI=$(TOOLPREFIX)dcc32.exe

# how to link executable
%.exe: %.dpr nbc_preproc.inc
	$(DELPHI) $< -U.. -U../bricktools -U../png -U../pbr -DCAN_DOWNLOAD -DFAST_MM

# how to compile pas source
%.dcu: %.pas mkdata.exe NBCCommonData.pas NXTDefsData.pas NXCDefsData.pas SPCDefsData.pas SPMemData.pas
	$(DELPHI) $< -U.. -U../bricktools -U../png -U../pbr -DCAN_DOWNLOAD -DFAST_MM

# how to create the include file
nbc_preproc.inc:
	echo '// '$@ > $@
	echo 'const' >> $@
	echo '  DEFAULT_INCLUDE_DIR = '\'$(DEFAULT_INCLUDE_DIR)\'';' >> $@
	echo '  COMPILATION_TIMESTAMP = '\'`date`\'';' >> $@

# how to create the mkdata utility
mkdata.exe: mkdata.dpr
	$(DELPHI) $< -U..

# how to create NBCCommonData.pas
NBCCommonData.pas: NBCCommon.h
	./mkdata.exe $< $@ nbc_common_data

# how to create NXTDefsData.pas
NXTDefsData.pas: NXTDefs.h
	./mkdata.exe $< $@ nxt_defs_data

# how to create NXCDefsData.pas
NXCDefsData.pas: NXCDefs.h
	./mkdata.exe $< $@ nxc_defs_data

# how to create SPCDefsData.pas
SPCDefsData.pas: SPCDefs.h
	./mkdata.exe $< $@ spc_defs_data

# how to create SPMemData.pas
SPMemData.pas: spmem.h
	./mkdata.exe $< $@ spmem_data

