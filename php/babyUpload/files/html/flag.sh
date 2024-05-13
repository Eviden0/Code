#!/bin/sh    #必需的东西没什么好讲的
sed -i "s/flag{testflag}/$GZCTF_FLAG/" /var/www/html/flag
export GZCTF_FLAG=""
