#!/bin/bash

name=$(whoami)

if [[ $name != 'root' ]] ; then
    su -c "userdel $name"
fi
