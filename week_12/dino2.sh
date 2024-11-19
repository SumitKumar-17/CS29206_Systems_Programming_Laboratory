#!/bin/bash
echo -n "Enter the dino database name: "
read dbfile
cat <<EOP> thero.awk
BEGIN{
    FS=":";
    print "theorpod dinosurs"
}
{
    if(\$2 ~ "theropod") { print \$1 " is a theropod";}
}
END{
    print "End of the database";
}

EOP
gawkop=`gawk -f thero.awk $dbfile`
echo "$gawkop"