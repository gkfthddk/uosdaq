LIBUSB_INC = /usr/include/libusb-1.0
LIBUSB_LIB = /usr/lib64

FILENAME1 = runUOSDAQ3
FILENAME2 = getPedestal
MODULE = NoticeUOSDAQ3

NKUSBO = lib/$(MODULE).o
NKUSBSO = lib/lib$(MODULE).so

EXE1	=	bin/$(FILENAME1).exe
EXE2	=	bin/$(FILENAME2).exe

CC	=	g++

COPTS	=	-fPIC -Wall

FLAGS	=	-shared -Wall,-soname -nostartfiles -s

LDFLAGS =        -O2 -Wall 
SLDFLAGS = -shared -Wall
LDLIBS = -L$(LIBUSB_LIB) -lusb-1.0
OutPutOpt = -o 

LIBS	=  -Llib -L$(LIBUSB_LIB) -lusb-1.0  -lm  -lNoticeUOSDAQ3

INCLUDEDIR =	-Ilib -I$(LIBUSB_INC)

INSTALLDIR     =	bin

OBJS1	=	lib/$(FILENAME1).o
OBJS2	=	lib/$(FILENAME2).o

INSTALL_LIB = lib
INCLUDES =	 


#########################################################################

all	:	$(NKUSBSO) $(EXE1) $(EXE2)
clean	:
		/bin/rm -f $(OBJS1) $(EXE1) $(OBJS2) $(EXE2) $(NKUSBO) $(NKUSBSO)

install	:	$(EXE1) $(EXE2)
		install $(EXE1) $(INSTALLDIR); install $(EXE2) $(INSTALLDIR)
		$(NKUSBSO) $(NKUSBH)
		install $< $(INSTALL_LIB)
		install $(NKUSBH) $(INSTALL_LIB)		


$(NKUSBSO): $(NKUSBO)
		$(CC) $(SLDFLAGS) $^ $(LDLIBS) $(OutPutOpt) $@ $(EXPLLINKLIBS)

$(EXE1):      $(OBJS1)
		$(CC) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
		@echo "$@ done"

$(EXE2):      $(OBJS2)
		$(CC) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@
		@echo "$@ done"


$(OBJS1)	:	$(INCLUDES) 
$(OBJS2)	:	$(INCLUDES) 

lib/%.o	:	src/%.cc
		$(CC) $(COPTS) $(INCLUDEDIR) -c -o $@ $<

