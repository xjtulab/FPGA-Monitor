#!/bin/bash

proc_name=$1
ps -aux | grep ${proc_name} | grep SN