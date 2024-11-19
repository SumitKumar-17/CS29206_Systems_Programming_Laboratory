function oddsum(n,i,sum){
    # print"oddsum
    sum=0
    term=1
    for(i=1;i<=n;i++){
        sum+=term
        term+=2
    
    }

return sum
}


BEGIN{
    print "Enter the number"
    getline i < "-"
    i=int(i);
    for(j=1;j<=i;j++){sum+=oddsum(j)}
    print sum
}