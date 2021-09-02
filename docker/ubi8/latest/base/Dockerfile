ARG dist=ubi8
ARG tag=latest
FROM ${dist}:${tag}

MAINTAINER Philippe HUET <phuet@dotgee.fr>

RUN dnf -y install \
        python3 \
        gcc \
        gcc-c++ \
        flex \
        bison \
        git \
        libidn \
        procps-ng \
        iptables \
        iputils \
        iproute \
        net-tools

RUN dnf -y install --enablerepo=rhel-8-for-x86_64-baseos-rpms \
       libcurl-devel \
       libyaml-devel \
       cyrus-sasl-devel \
       libgcrypt-devel \
       gnutls-devel \
       openssl-devel \
       libnghttp2 \
       libmicrohttpd \
       lksctp-tools-devel

RUN rpm -ivh https://dl.fedoraproject.org/pub/epel/epel-release-latest-8.noarch.rpm

RUN dnf -y install \
        mongo-c-driver-devel

#        libyaml-devel \
#        mongo-c-driver-devel \
#        libmicrohttpd-devel \
#        libnghttp2-devel \

RUN dnf -y install --enablerepo=codeready-builder-for-rhel-8-x86_64-rpms \
      libidn-devel \
      libnghttp2-devel \
      libmicrohttpd-devel \
      cmake \
      ninja-build \
      meson

# RUN dnf -y install tcpdump

#
# for umf
#
# Not sure that it is still required
#
### USER 0
### RUN mkdir -p /dev/net && \
###     chgrp 0 /dev/net && \
###     mknod /dev/net/tun c 10 200 && \
###     chgrp 0 /dev/net/tun && \
###     chmod 660 /dev/net/tun
USER 1000
