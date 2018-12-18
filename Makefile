LIBUSB_INC = /usr/include/libusb-1.0
LIBUSB_LIB = /usr/lib64

FILENAME1 = runUOSDAQ3
FILENAME2 = getPedestal
FILENAME3 = testgui
MODULE = NoticeUOSDAQ3

NKUSBO = lib/$(MODULE).o
NKUSBSO = lib/lib$(MODULE).so

EXE1	=	bin/$(FILENAME1).exe
EXE2	=	bin/$(FILENAME2).exe
EXE3	=	bin/$(FILENAME3).exe

CC	=	g++ `root-config --cflags --libs`

COPTS	=	-fPIC -Wall

FLAGS	=	-shared -Wall,-soname -nostartfiles -s

LDFLAGS =        -O2 -Wall #wall 
SLDFLAGS = -shared -Wall
LDLIBS =  -L$(LIBUSB_LIB) -lm -Llib -lNoticeUOSDAQ3 -lusb-1.0 `root-config --cflags --glibs` #lib
#g++ -std=c++0x append.cxx -o append `root-config --cflags --libs`
OutPutOpt = -o 

LIBS	=  -Llib -L$(LIBUSB_LIB) -lusb-1.0  -lm  -lNoticeUOSDAQ3

INCLUDEDIR =	-I/home/daq/root/include -Ilib -I$(LIBUSB_INC) 

INSTALLDIR     =	bin

OBJS1	=	lib/$(FILENAME1).o
OBJS2	=	lib/$(FILENAME2).o
OBJS3	=	lib/$(FILENAME3).o

INSTALL_LIB = lib
INCLUDES =	 


#########################################################################

all	:	$(NKUSBSO) $(EXE1) $(EXE2) $(EXE3)
clean	:
		/bin/rm -f $(OBJS1) $(EXE1) $(OBJS2) $(EXE2) $(EXE3) $(NKUSBO) $(NKUSBSO)

install	:	$(EXE1) $(EXE2) $(EXE3)
		install $(EXE1) $(INSTALLDIR); install $(EXE2) $(INSTALLDIR)
		$(NKUSBSO) $(NKUSBH)
		install $< $(INSTALL_LIB)
		install $(NKUSBH) $(INSTALL_LIB)		


$(NKUSBSO): $(NKUSBO)
		@echo "asdone"
		$(CC) $(SLDFLAGS) $^ $(LDLIBS) $(OutPutOpt) $@ $(EXPLLINKLIBS)

$(EXE1):      $(OBJS1)
		mkdir -p bin
		$(CC) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@ `root-config --cflags --libs`
		@echo "$@ done"

$(EXE2):      $(OBJS2)
		@echo "fdsfdone"
		$(CC) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@ `root-config --cflags --libs`

$(EXE3):      $(OBJS3)
		$(CC) $(LDFLAGS) $^ $(LIBS) $(OutPutOpt)$@ `root-config --cflags --libs`
		@echo "$@ done"

$(OBJS1)	:	$(INCLUDES) 
$(OBJS2)	:	$(INCLUDES) 
$(OBJS3)	:	$(INCLUDES) 

lib/%.o	:	src/%.cc
		mkdir -p lib
		$(CC) $(COPTS) $(INCLUDEDIR) -c -o $@ $<

