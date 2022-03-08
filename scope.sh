#!/bin/bash
var=global
scope() {
    local var=$1
    echo " wihtin function the value of var is $var";
}
#var=outside
echo "before calling function value is $var"
scope local
echo "after function call value of var is $var"
