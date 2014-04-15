
KERNEL_VER=$(uname -r)

all:
	make -C /lib/modules/${KERNEL_VER}/build M=${PWD}

install:
	make -C /lib/modules/${KERNEL_VER}/build M=${PWD} modules_install

clean:
	make -C /lib/modules/${KERNEL_VER}/build M=${PWD} clean
	rm -rf *.o *.ko
