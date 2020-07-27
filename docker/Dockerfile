#use ubuntu enviroment docker image
FROM ubuntu:18.04
LABEL maintainer="upccfeng@gmail.com"


##update apt-get
RUN apt-get update -y
RUN apt-get upgrade -y
##------------------------------------


##install usefull tool
RUN apt-get install -y vim
RUN apt-get install -y net-tools
RUN apt-get install -y iputils-ping
RUN apt-get install -y git
##-------------------------------------

##install dependency for porject
#https://packages.ubuntu.com/zh-tw/trusty/software-properties-common python package 
RUN apt-get install -y software-properties-common
RUN apt-get install -y autoconf libtool libpam0g-dev
RUN apt-get install -y ssh
RUN apt-get install -y sshfs
RUN apt-get install -y gcc g++ cmake gdb make gdbserver
##----------------------------------------

RUN echo "PermitRootLogin yes" >> /etc/ssh/sshd_config

#set entryfolder
WORKDIR "/workspace"

#set up the root password by "root". For client ssh login (can change any passwd if you want)
RUN echo root:root | chpasswd
RUN mkdir ~/.ssh
RUN mkdir /var/run/sshd
CMD ["/usr/sbin/sshd", "-D"]