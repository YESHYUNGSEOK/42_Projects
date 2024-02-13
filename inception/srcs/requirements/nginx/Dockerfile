FROM debian:buster

RUN apt -y update && apt install -y nginx && apt install openssl -y

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/hyungnoh.crt \
       -keyout /etc/nginx/ssl/hyungnoh.key \
       -subj "/C=KR/ST=Seoul/L=Seoul/O=42 School/OU=hyungnoh/CN=hyungnoh/"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE	443

CMD ["nginx", "-g", "daemon off;"]