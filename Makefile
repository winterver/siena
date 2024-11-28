CC = gcc
LD = ld

CFLAGS = -O2
LDFLAGS =

TARGET = build/siena

# flags that should not be edited
CFLAGS += \
	-Wall \
	-Wextra \
	-std=gnu11 \
	-ffreestanding \
	-fno-stack-protector \
	-fno-stack-check \
	-fno-lto \
	-fno-PIC \
	-m64 \
	-march=x86-64 \
	-mno-80387 \
	-mno-mmx \
	-mno-sse \
	-mno-sse2 \
	-mno-red-zone \
	-mcmodel=kernel

LDFLAGS += \
	-static \
	-nostdlib \
	-T linker.ld

# intentionally left empty
SRCS =
OBJS =

SRCS += $(shell find src -type f -name '*.S')
SRCS += $(shell find src -type f -name '*.c')

OBJS += $(filter %.o,$(patsubst src/%.S,build/%.o,$(SRCS)))
OBJS += $(filter %.o,$(patsubst src/%.c,build/%.o,$(SRCS)))

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o $(TARGET)

build/%.o: src/%.S
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: src/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	mkdir -p vfat/{EFI/BOOT,boot/limine}
	cp -u limine/BOOTX64.EFI vfat/EFI/BOOT/
	cp -u limine.conf vfat/boot/limine/
	cp -u $(TARGET) vfat/boot/
	qemu-system-x86_64 -net none -bios /usr/share/ovmf/x64/OVMF.4m.fd -drive file=fat:rw:vfat,format=raw &
	sleep 1 && gvncviewer localhost

clean:
	rm $(TARGET) $(OBJS) 2> /dev/null || true
