#/bin/sh
ifconfig -a link | grep ether | cut -d "r" -f 2 | cut -d " " -f 2
