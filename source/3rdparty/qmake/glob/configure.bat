@echo off
echo Configuring glob for DJGPP
rem This batch file assumes a unix-type "sed" program

echo # Makefile generated by "configure.bat"> Makefile

if exist config.sed del config.sed

echo "s/@srcdir@/./					">> config.sed
echo "s/@CC@/gcc/					">> config.sed
echo "s/@CFLAGS@/-O2 -g/				">> config.sed
echo "s/@CPPFLAGS@/-DHAVE_CONFIG_H -I../		">> config.sed
echo "s/@AR@/ar/					">> config.sed
echo "s/@RANLIB@/ranlib/				">> config.sed
echo "s/@LDFLAGS@//					">> config.sed
echo "s/@DEFS@//					">> config.sed
echo "s/@ALLOCA@//					">> config.sed
echo "s/@LIBS@//					">> config.sed
echo "s/@LIBOBJS@//					">> config.sed
echo "s/^Makefile *:/_Makefile:/			">> config.sed
echo "s/^config.h *:/_config.h:/			">> config.sed

sed -e "s/^\"//" -e "s/\"$//" -e "s/[ 	]*$//" config.sed > config2.sed
sed -f config2.sed Makefile.in >> Makefile
del config.sed
del config2.sed
