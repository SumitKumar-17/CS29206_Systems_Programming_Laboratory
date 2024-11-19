BEGIN{
    FS=":"
    nIndian=0
    nlarge=0
    nsmall=0
}

{
    if($7 ~ /India/){ nIndian++ ;Indian[nIndian]=$1}
    if($2 ~ /theropod/){
        if($2 ~ /large/){nlarge++ ;large[nlarge]=$1}
        else {
            nsmall++ ;  small[nsmall]=$1
        }
    }
}

END{
    print "dinosaurs found in India"

    for(i=1;i<=nIndian;i++) print "\t" Indian[i]

    print "large theropods"
    for(i=1;i<=nlarge;i++) print "\t" large[i]

    print "small theropods"
    for(i=1;i<=nsmall;i++) print "\t" small[i]


}