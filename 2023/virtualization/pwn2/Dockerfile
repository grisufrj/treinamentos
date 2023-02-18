# docker build -t pwn .
# docker run -p 9999:9999 pwn:latest
FROM ubuntu:18.04

RUN apt-get update -y && apt-get install -y \
    lib32z1 xinetd

RUN useradd -m ctf

WORKDIR /home/ctf

RUN apt-get install -y \
    qemu-user

COPY ./ctf.xinetd /etc/xinetd.d/ctf
COPY ./start.sh /start.sh

RUN echo "Blocked by ctf_xinetd" > /etc/banner_fail

RUN chmod +x /start.sh

COPY ./bin/ /home/ctf/
RUN chown -R root:ctf /home/ctf && \
    chmod -R 750 /home/ctf && \
    chmod 740 /home/ctf/flag.txt

CMD ["/start.sh"]

EXPOSE 9999