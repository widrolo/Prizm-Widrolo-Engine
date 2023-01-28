
.SUFFIXES:

ifeq ($(strip $(FXCGSDK)),)
export FXCGSDK := $(abspath ../../)
endif

include $(FXCGSDK)/toolchain/prizm_rules

REMOVER=RemoveDrive
CASIODRIVE=E:


TARGET		:=	$(notdir $(CURDIR))
BUILD		:=	build
SOURCES		:=	src
DATA		:=	data  
INCLUDES	:=  "C:\Users\Filip\Desktop\PrizmSDK-win-0.5.2\projects\Widrolo-Engine\src"


APPNAME	   := "!DBG!"
MKG3AFLAGS := -n basic:$(APPNAME) -i uns:../unselected.bmp -i sel:../selected.bmp


CFLAGS	= -Os -Wall $(MACHDEP) $(INCLUDE) -ffunction-sections -fdata-sections
CXXFLAGS	=	$(CFLAGS) -fno-exceptions

LDFLAGS	= $(MACHDEP) -T$(FXCGSDK)/toolchain/prizm.x -Wl,-static -Wl,-gc-sections

LIBS	:=	 -lc -lfxcg -lgcc

LIBDIRS	:=

ifneq ($(BUILD),$(notdir $(CURDIR)))
#---------------------------------------------------------------------------------

export OUTPUT	:=	$(CURDIR)/$(TARGET)

export VPATH	:=	$(foreach dir,$(SOURCES),$(CURDIR)/$(dir)) \
					$(foreach dir,$(DATA),$(CURDIR)/$(dir))

export DEPSDIR	:=	$(CURDIR)/$(BUILD)

# automatically build a list of object files for our project
CFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.c)))
CPPFILES	:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.cpp)))
sFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.s)))
SFILES		:=	$(foreach dir,$(SOURCES),$(notdir $(wildcard $(dir)/*.S)))
BINFILES	:=	$(foreach dir,$(DATA),$(notdir $(wildcard $(dir)/*.*)))

# use CXX for linking C++ projects, CC for standard C
ifeq ($(strip $(CPPFILES)),)
	export LD	:=	$(CC)
else
	export LD	:=	$(CXX)
endif

export OFILES	:=	$(addsuffix .o,$(BINFILES)) \
					$(CPPFILES:.cpp=.o) $(CFILES:.c=.o) \
					$(sFILES:.s=.o) $(SFILES:.S=.o)

# build a list of include paths
export INCLUDE	:=	$(foreach dir,$(INCLUDES), -iquote $(CURDIR)/$(dir)) \
					$(foreach dir,$(LIBDIRS),-I$(dir)/include) \
					-I$(CURDIR)/$(BUILD) -I$(LIBFXCG_INC)

# build a list of library paths
export LIBPATHS	:=	$(foreach dir,$(LIBDIRS),-L$(dir)/lib) \
					-L$(LIBFXCG_LIB)

export OUTPUT	:=	$(CURDIR)/$(TARGET)
.PHONY: all clean

#---------------------------------------------------------------------------------
all: $(BUILD)
	@make --no-print-directory -C $(BUILD) -f $(CURDIR)/Makefile

$(BUILD):
	@mkdir $@

#---------------------------------------------------------------------------------
transfer-clean:
	copy "$(OUTPUT).g3a" "$(CASIODRIVE)/$(TARGET).g3a"
	$(REMOVER) $(CASIODRIVE)
transfer:
	$(call rm,$(CASIODRIVE)/$(TARGET).g3a)
	copy "$(OUTPUT).g3a" "$(CASIODRIVE)/$(TARGET).g3a"
	$(REMOVER) $(CASIODRIVE)
#---------------------------------------------------------------------------------
export CYGWIN := nodosfilewarning
clean:
	$(call rmdir,$(BUILD))
	$(call rm,$(OUTPUT).bin)
	$(call rm,$(OUTPUT).g3a)

#---------------------------------------------------------------------------------
else

DEPENDS	:=	$(OFILES:.o=.d)

# main targets
$(OUTPUT).g3a: $(OUTPUT).bin
$(OUTPUT).bin: $(OFILES)


-include $(DEPENDS)

#---------------------------------------------------------------------------------
endif
#---------------------------------------------------------------------------------
