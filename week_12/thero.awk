BEGIN{
    FS=":";
    print "theorpod dinosurs"
}
{
    if($2 ~ "theropod") { print $1 " is a theropod";}
}
END{
    print "End of the database";
}

