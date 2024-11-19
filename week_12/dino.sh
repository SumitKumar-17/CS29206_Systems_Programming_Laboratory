#!/bin/bash

echo -n "En ther the dino database name: "
read dbfile
gawk `
 BEGIN{
    FS=":" ;
    print "Reading the databse";
    {
        if(\$2 ~  "theropod") { print "hi";}
    }
    END{
        print "End of the database";
    }
 }

` $dbfile