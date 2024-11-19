BEGIN{
    FS=":"
    print "going through the dinosaur database"
}

{print $1}
{print "\tType:" $2}
{print "\tLength:" $3 "metres "}
$4  == "" { print "\tWeight: Unknown" }
$4 != "" { print "\tWeight: " $4 " kilograms" }
$5 == "H" { print "\tDiet: Herbivorous" }
$5 == "C" { print "\tDiet: Carnivorous" }
$5 == "O" { print "\tDiet: Omnivorous" }
{ print "\tLived " $6 " million years ago" }

{
    print "\tFosiils founf in"
    n=split($7,clist,",")
    for (i=1;i<=n;i++) { print "\t\t" clist[i] 
}
}

END {print "printing gis complete"}