#!/bin/bash
#取文件的某一行

tail -n +$2 $1 | head -n 1
