BUILD_APP_TINYPLAY=1
BUILD_APP_TINYMIX=1
BUILD_APP_TINYPCMINFO=1
BUILD_APP_TINYCAP=1

CFLAGS = -g -c -Wall -Os -fdata-sections -ffunction-sections

ifdef BUILD_APP_TINYPLAY
CFLAGS += -DAPP_TINYPLAY
endif
ifdef BUILD_APP_TINYMIX
CFLAGS += -DAPP_TINYMIX
endif
ifdef BUILD_APP_TINYPCMINFO
CFLAGS += -DAPP_TINYPCMINFO
endif
ifdef BUILD_APP_TINYCAP
CFLAGS += -DAPP_TINYCAP
endif

INC = include
OBJECTS = mixer.o pcm.o tinymix.o tinyplay.o tinycap.o tinypcminfo.o
CROSS_COMPILE =
LDFLAGS = -Os -static -Wl,--gc-sections

all: tinytool

tinytool: $(OBJECTS) tinytool.o
	$(CROSS_COMPILE)gcc $(OBJECTS) tinytool.o $(LDFLAGS) -o tinytool
ifdef BUILD_APP_TINYPLAY
	ln -s tinytool tinyplay
endif
ifdef BUILD_APP_TINYMIX
	ln -s tinytool tinymix
endif
ifdef BUILD_APP_TINYPCMINFO
	ln -s tinytool tinypcminfo
endif
ifdef BUILD_APP_TINYCAP
	ln -s tinytool tinycap
endif

.c.o:
	$(CROSS_COMPILE)gcc $(CFLAGS) $< -I$(INC)

clean:
	-rm -f $(OBJECTS) tinytool tinytool.o tinyplay tinymix tinypcminfo tinycap
