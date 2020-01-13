#############QQ网络项目Makefile
SUBDIRS = common \
          0.game \
          1.qq_server \
          2.qq_client

MAKEFLAGS = --no-print-directory

.PHONY:all
all:
	@list='$(SUBDIRS)';for subdir in $$list; do \
        echo "----->> make $$subdir";\
        make -C $$subdir;\
    done

.PHONY:clean
clean:
	@list='$(SUBDIRS)';for subdir in $$list; do \
        echo "----->> clean $$subdir";\
        make -C $$subdir clean;\
    done


#################0.game
CC=gcc
CFLAGS=-Wall -g -O0
SRC1=1-morra.c
SRC2=2-nine.c

OBJS1=${patsubst %.c,%.o,$(SRC1)}
OBJS2=${patsubst %.c,%.o,$(SRC2)}

all:../bin/game/1-morra ../bin/game/2-nine
.PHONY:all
../bin/game/1-morra:$(OBJS1)
	$(CC) $(CFLAGS) -o $@ $^

../bin/game/2-nine:$(OBJS2)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(OBJS1) $(OBJS2) .*.SW?
	$(RM) ../bin/game/1-morra ../bin/game/2-nine

###############1.qq_server
CC=gcc
CFLAGS=-Wall -g -O0
SRC1=10-qq_srv_start.c
SRC2=20-qq_srv_exc.c 21-qq_srv_func.c opera_database_qq.c
OBJS1=${patsubst %.c,%.o,$(SRC1)}
OBJS2=${patsubst %.c,%.o,$(SRC2)}
OBJS3=${wildcard ../common/*.o}

all:../bin/1-qq_srv_start ../bin/qq_srv_exc
.PHONY:all
../bin/1-qq_srv_start:$(OBJS1)
	$(CC) $(CFLAGS) -o $@ $^

../bin/qq_srv_exc:$(OBJS2) $(OBJS3)
	$(CC) $(CFLAGS) -o $@ $^ -lsqlite3 -ljson

clean:
	$(RM) $(OBJS1) $(OBJS2) .*.SW?
	$(RM) ../bin/1-qq_srv_start ../bin/qq_srv_exc

################3.qq_client
CC=gcc
CFLAGS=-Wall -g -O0
SRC1=10-qq_start.c
SRC2=20-qq_exc.c 21-qq_func.c
SRC3=30-qq_login.c

OBJS1=${patsubst %.c,%.o,$(SRC1)}
OBJS2=${patsubst %.c,%.o,$(SRC2)}
OBJS3=${patsubst %.c,%.o,$(SRC3)}
OBJSC=${wildcard ../common/func_common.o}

all:../bin/2-qq_start ../bin/qq_exc ../bin/qq_login
.PHONY:all
../bin/2-qq_start:$(OBJS1)
	$(CC) $(CFLAGS) -o $@ $^

../bin/qq_exc:$(OBJS2) $(OBJSC)
	$(CC) $(CFLAGS) -o $@ $^ -lsqlite3 -ljson

../bin/qq_login:$(OBJS3) $(OBJSC)
	$(CC) $(CFLAGS) -o $@ $^ -lsqlite3 -ljson

clean:
	$(RM) $(OBJS1) $(OBJS2) $(OBJS3) .*.SW?
	$(RM) ../bin/2-qq_start ../bin/qq_exc ../bin/qq_login

##########common
CC=gcc
CFLAGS=-Wall -g -O0
SRC=${wildcard *.c}
TARGET=${patsubst %.c,%.o,$(SRC)}

$(TARGET):$(SRC)
	$(CC) $(CFLAGS) -c $^ -o $@ -ljson

clean:
	$(RM) $(TARGET) .*.sw?

######同一文件夹，每个c程序编译为相应文件名的执行文件
CC=gcc
CFLAGS= -Wall -g -O0
SRC=${wildcard *.c}
OBJS=${patsubst %.c, %, $(SRC)}

all:$(OBJS)

%:%.c
	$(CC) $(CFLAGS) -o $@ $^ -lpthread

clean:
	$(RM) $(OBJS) .*.SW?

#####同一文件夹，均要把内核链表C文件或json联合编译进去
CC = gcc
CFLAGS = -Wall -g -O0
#SRC = ${wildcard *.c}
#OBJS = ${patsubst %.c,%,$(SRC)}

SRV = srv_tcp
CLI = cli_tcp

all:$ $(SRV) $(CLI)

%:%.c
	$(CC) $(CFLAGS) -o $@ $^ (linklist.c) (json.c -ljson)

clean:
	$(RM) $(SRV) $(CLI) .*.sw?


##同以文件夹，不同编译条件
CC = arm-none-linux-gnueabi-gcc
#CC = gcc
CFLAGS = -Wall -g -O0

SRV = server
CLI = client

all:$ $(SRV) $(CLI)

#%:%.c
#    $(CC) $(CFLAGS) -o $@ $^ common.c -ljson -lsqlite3 -lpthread

$(SRV):$(SRV).c
	gcc $(CFLAGS) -o $@ $^ common.c -ljson -lsqlite3 

$(CLI):$(CLI).c
	$(CC) $(CFLAGS) -o $@ $^ common.c -ljson -lpthread

clean:
	$(RM) $(SRV) $(CLI) .*.sw?


#####驱动编程中的Makefile
KERNEL_DIR = /home/tom/s5pv210/kernel/linux-3.0.8
CUR_DIR = ${shell pwd}
MYAPP = test

all:
	make -C $(KERNEL_DIR) M=$(CUR_DIR) modules
	arm-none-linux-gnueabi-gcc -o $(MYAPP) $(MYAPP).c
clean:
	make -C $(KERNEL_DIR) M=$(CUR_DIR) clean
	$(RM) $(MYAPP) .*.sw?

install:
	cp *.ko $(MYAPP) /opt/rootfs/drv_module/

obj-m := dev_drv.o


######官网，驱动Makefile
ROOTFS_DIR = /opt/4412/rootfs
ifeq ($(KERNELRELEASE), )
KERNEL_DIR = /home/george/Linux_4412/kernel/linux-3.14
CUR_DIR = $(shell pwd)
all :
	make -C  $(KERNEL_DIR) M=$(CUR_DIR) modules
clean :
	make -C  $(KERNEL_DIR) M=$(CUR_DIR) clean
 
install:
	cp -raf *.ko   $(ROOTFS_DIR)/drv_module

else
obj-m += hello.o
obj-m += math.o

endif

##############多层目录中的源文件一起编译
PARAM_FILE := ./Makefile.param
include Makefile.param

CC := g++

#SRC_PATH = .
#DIRS = $(shell find $(SRC_PATH) -maxdepth 4 -type d)
#SRC = $(foreach dir, $(DIRS), $(wildcard $(dir)/*.cpp))
##SRC = $(wildcard *.cpp)

SRC += ./main.cpp
#SRC += ./object.cpp
#SRC += ./exception/exception.cpp

#OBJ = $(patsubst %.cpp, %.o, $(SRC))
OBJ = $(SRC:%.cpp=%.o)

TARGET = a.out

$(TARGET):$(SRC)
    $(CC) $(CFLAGS) -o $@ $^

#$(CC) $(CFLAGS) -o $@ $^ -g

.PHONY:clean
clean:
	$(RM) $(OBJ) $(TARGET)

