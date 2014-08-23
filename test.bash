#!/bin/bash

function clear_all {
  sleep 0.4
  for i in `seq 4`; do
    echo curl http://localhost:9292/$i/0/0/0
    curl http://localhost:9292/$i/0/0/0 > /dev/null 2>&1
    sleep 0.4
  done
}

clear_all
curl http://localhost:9292/1/255/255/0 > /dev/null 2>&1
curl http://localhost:9292/1/255/255/0 > /dev/null 2>&1
sleep 1
curl http://localhost:9292/2/255/0/0 > /dev/null 2>&1
curl http://localhost:9292/2/255/0/0 > /dev/null 2>&1
sleep 1
curl http://localhost:9292/3/0/255/0 > /dev/null 2>&1
curl http://localhost:9292/3/0/255/0 > /dev/null 2>&1
sleep 1
curl http://localhost:9292/4/0/0/255 > /dev/null 2>&1
curl http://localhost:9292/4/0/0/255 > /dev/null 2>&1
clear_all

