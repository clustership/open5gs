ARG dist=ubi8
ARG tag=latest
ARG username=acetcom
FROM ${username}/${dist}-${tag}-open5gs-base

MAINTAINER Philippe HUET <phuet@dotgee.fr>

USER 0
RUN dnf -y install \
        findutils \
        cscope \
        vim \
        sudo \
        iputils \
        net-tools

COPY setup.sh /root

ARG username=acetcom
RUN useradd -m --uid=1000 ${username} && \
    echo "${username} ALL=(root) NOPASSWD:ALL" > /etc/sudoers.d/${username} && \
    chmod 0440 /etc/sudoers.d/${username}

USER 1000
WORKDIR /home/${username}
