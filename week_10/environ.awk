#!/usr/bin/gawk -F
BEGIN{
    for (name in ENVIRON){
        print name, ENVIRON[name]
    }
}